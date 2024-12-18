/*
 * Display.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Noah
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

/**
 * 0 = on, 1 = off
 *
 * 		 ---a
 * 		|f  |b
 * 		 ---g
 * 		|e  |c
 * 		 ---d .dp
 *
 * a b c d e f g dp
 */

#define DISPLAY_0 0b00000011
#define DISPLAY_1 0b10011111
#define DISPLAY_2 0b00100101
#define DISPLAY_3 0b00001101
#define DISPLAY_4 0b10011001
#define DISPLAY_5 0b01001001
#define DISPLAY_6 0b01000001
#define DISPLAY_7 0b00011111
#define DISPLAY_8 0b00000001
#define DISPLAY_9 0b00011001

/**
 *    1234
 * 0b 0000 1111
 */
#define SEGMENT_4 0b00011111
#define SEGMENT_3 0b00101111
#define SEGMENT_2 0b01001111
#define SEGMENT_1 0b10001111

#endif /* INC_DISPLAY_H_ */
