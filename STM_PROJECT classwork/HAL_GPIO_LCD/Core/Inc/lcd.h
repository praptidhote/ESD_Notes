/*
 * lcd.h
 *
 *  Created on: 21-Mar-2026
 *      Author: sunbeam
 */

#ifndef LCD_H_
#define LCD_H_

#include "main.h"

#define BV(n)	(1 << (n))

#define GPIO_LCD_CLK_EN		3

#define LCD_GPIO		GPIOD
#define LCD_DB4			GPIO_PIN_0
#define LCD_DB5			GPIO_PIN_1
#define LCD_DB6			GPIO_PIN_2
#define LCD_DB7			GPIO_PIN_3

#define LCD_RS			GPIO_PIN_5
#define LCD_RW			GPIO_PIN_6
#define LCD_EN			GPIO_PIN_7

#define LCD_CLEAR				0x01
#define ENTRY_MODE_SET			0x06
#define DISPLAY_ON_OFF_CONTROL	0x0C
#define FUNCTION_SET			0x28
#define LCD_LINE1				0x80
#define LCD_LINE2				0xC0

#define LCD_CMD		0
#define LCD_DATA	1

void lcd_init(void);
void lcd_write_nibble(uint8_t rs, uint8_t val);
void lcd_busy_wait(void);
void lcd_write_byte(uint8_t rs, uint8_t val);
void lcd_puts(uint8_t line, char str[]);

#endif /* LCD_H_ */















