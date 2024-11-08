/*
 * UART.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Noah
 */
#include "main.h"
#include "stdarg.h"
#include "stdio.h"

UART_HandleTypeDef huart2;

static char BUFFER[100];

/**
 * prints a string out, and adds a new line
 *
 * @param str	a pointer to a string to print
 *
 * @return		the number of characters printed
 */
int puts (const char* str) {
	int ret = sprintf (BUFFER, "%s\r\n", str);
	HAL_UART_Transmit(&huart2, (unsigned char *) BUFFER, ret, 100);
	return ret;
}

/**
 * prints a specific number of characters
 *
 * @param str	a pointer to a string to print
 * @param size	the number of characters from str to print
 *
 * @return		the number of characters printed
 */
int putns (const char* str, int size) {
	int ret = snprintf (BUFFER, size + 1, "%s", str); // len of string plus \0
	HAL_UART_Transmit(&huart2, (unsigned char *) BUFFER, ret, 100);
	return ret + 2;
}

/**
 * prints a given character to the console
 *
 * @param c	the value of a character to print out
 *
 * @return	the number of characters printed
 */
int putchar (int c) {
	HAL_UART_Transmit(&huart2, (unsigned char *) c, 1, 100);
	return 1;
}

/**
 * prints a string out, and allows insertion of data values into formatted
 * 		string
 *
 * @param format	a pointer to a string to print, along with format chars
 * @param ...		data values to insert into format char positions
 *
 * @return		the number of characters printed
 */
int printf (const char* format, ...) {
	// formats the string
	va_list aptr;
	va_start(aptr, format);
	int ret = vsprintf(BUFFER, format, aptr);
	va_end(aptr);

	// writes to output
	HAL_UART_Transmit(&huart2, (unsigned char *) BUFFER, ret, 100);

	// return string length
	return(ret);
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}
