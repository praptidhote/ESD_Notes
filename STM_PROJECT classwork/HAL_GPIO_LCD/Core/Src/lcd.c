/*
 * lcd.c
 *
 *  Created on: 21-Mar-2026
 *      Author: sunbeam
 */

#include "lcd.h"

void lcd_init(void)
{
	// clear all pins
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB4 | LCD_DB5 | LCD_DB6 | LCD_DB7 | LCD_RS | LCD_RW | LCD_EN, GPIO_PIN_RESET);

	// LCD init
	HAL_Delay(200);
	lcd_write_byte(LCD_CMD, FUNCTION_SET);
	lcd_write_byte(LCD_CMD, DISPLAY_ON_OFF_CONTROL);
	lcd_write_byte(LCD_CMD, ENTRY_MODE_SET);
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	HAL_Delay(200);
}

void lcd_write_nibble(uint8_t rs, uint8_t val)
{
	// change RS to 0 for instruction or RS to 1 for data
	if(rs == LCD_CMD)
		HAL_GPIO_WritePin(LCD_GPIO, LCD_RS, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(LCD_GPIO, LCD_RS, GPIO_PIN_SET);
	// RW = 0
	HAL_GPIO_WritePin(LCD_GPIO, LCD_RW, GPIO_PIN_RESET);
	// clear all data pins
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB4 | LCD_DB5 | LCD_DB6 | LCD_DB7, GPIO_PIN_RESET);
	// write data into 4 data pins (shift is not required of DB7-DB4 mapped with 3-0)
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB4, val & 0x01);
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB5, val & 0x02);
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB6, val & 0x04);
	HAL_GPIO_WritePin(LCD_GPIO, LCD_DB7, val & 0x08);
	// generate high to low pulse on EN
	HAL_GPIO_WritePin(LCD_GPIO, LCD_EN, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_GPIO, LCD_EN, GPIO_PIN_RESET);
}

void lcd_busy_wait(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {
			.Pin = LCD_DB7,
			.Pull = GPIO_NOPULL,
			.Mode = 0
	};
	// RS = 0
	HAL_GPIO_WritePin(LCD_GPIO, LCD_RS, GPIO_PIN_RESET);
	// RW = 1 , EN = 1
	HAL_GPIO_WritePin(LCD_GPIO, LCD_EN | LCD_RW, GPIO_PIN_SET);
	// set mode of DB7 pin  as input
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(LCD_GPIO, &GPIO_InitStruct);
	// wait till DB7 is 1
	while(HAL_GPIO_ReadPin(LCD_GPIO, LCD_DB7) != GPIO_PIN_RESET)
		;
	// RW = 0, EN = 0
	HAL_GPIO_WritePin(LCD_GPIO, LCD_EN | LCD_RW, GPIO_PIN_RESET);
	// set mode of DB7 pin as output
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(LCD_GPIO, &GPIO_InitStruct);
}

void lcd_write_byte(uint8_t rs, uint8_t val)
{
	uint8_t high = val >> 4, low = val & 0x0F;
	lcd_write_nibble(rs, high);
	lcd_write_nibble(rs, low);
	lcd_busy_wait();
	HAL_Delay(3);
}

void lcd_puts(uint8_t line, char str[])
{
	//set line address
	lcd_write_byte(LCD_CMD, line);
	// send characters to lcd one by one
	for(int i = 0 ; str[i] != '\0' ; i++)
		lcd_write_byte(LCD_DATA, str[i]);
}
