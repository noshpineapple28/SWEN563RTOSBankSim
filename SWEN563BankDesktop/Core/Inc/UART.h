/*
 * UART.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Noah
 */

#ifndef INC_UART_H_
#define INC_UART_H_

/**
 * prints a specific number of characters
 *
 * @param str	a pointer to a string to print
 * @param size	the number of characters from str to print
 *
 * @return		the number of characters printed
 */
int putns (const char* str, int size);

/**
 * prints a string out, and allows insertion of data values into formatted
 * 		string
 *
 * @param format	a pointer to a string to print, along with format chars
 * @param ...		data values to insert into format char positions
 *
 * @return		the number of characters printed
 */
int printf (const char* format, ...);

/**
 * prints a string out, and adds a new line
 *
 * @param str	a pointer to a string to print
 *
 * @return		the number of characters printed
 */
int puts (const char* str);

/**
 * prints a given character to the console
 *
 * @param c	the value of a character to print out
 *
 * @return	the number of characters printed
 */
int putchar (int c);

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART2_UART_Init(void);

#endif /* INC_UART_H_ */
