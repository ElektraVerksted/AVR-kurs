/*
 * Fil:         ssd1306.c
 * Kursdag:     3, Oppgave 1
 * Beskrivelse: Implementasjon av driver for SSD1306 OLED-skjerm over I2C.
 */

#include "mcc_generated_files/system/system.h"
#define F_CPU 4000000UL

#include "font.h"
#include "ssd1306.h"
#include <util/delay.h>

// I2C Function Implementations

// Function to initialize the SSD1306 display
void SSD1306_Init()
{
    _delay_ms(200);
    SSD1306_SendCommand(SSD1306_DISPLAY_OFF);
    SSD1306_SendCommand(SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
    SSD1306_SendCommand(0x80);
    SSD1306_SendCommand(SSD1306_SET_MULTIPLEX_RATIO);
    SSD1306_SendCommand(SSD1306_LCDHEIGHT - 1);
    SSD1306_SendCommand(SSD1306_SET_DISPLAY_OFFSET);
    SSD1306_SendCommand(0x00);
    SSD1306_SendCommand(SSD1306_SET_START_LINE | 0x00); // Line: 0
    SSD1306_SendCommand(SSD1306_CHARGE_PUMP);
    SSD1306_SendCommand(0x14);
    SSD1306_SendCommand(SSD1306_MEMORY_ADDR_MODE);
    SSD1306_SendCommand(0x00); // Hor Addressing Mode is Used (02 is Ver)
    SSD1306_SendCommand(SSD1306_SET_SEGMENT_REMAP | 0x01);
    SSD1306_SendCommand(SSD1306_COM_SCAN_DIR_DEC);
    SSD1306_SendCommand(SSD1306_SET_COM_PINS);
    SSD1306_SendCommand(0x02);
    SSD1306_SendCommand(SSD1306_SET_CONTRAST_CONTROL);
    SSD1306_SendCommand(0x8F);
    SSD1306_SendCommand(SSD1306_SET_PRECHARGE_PERIOD);
    SSD1306_SendCommand(0xF1);
    SSD1306_SendCommand(SSD1306_SET_VCOM_DESELECT);
    SSD1306_SendCommand(0x40);
    SSD1306_SendCommand(SSD1306_DISPLAY_ALL_ON_RESUME);
    SSD1306_SendCommand(SSD1306_NORMAL_DISPLAY);
    SSD1306_SendCommand(SSD1306_DEACTIVATE_SCROLL);
    SSD1306_SendCommand(SSD1306_DISPLAY_ON);
}

// Send I2C Commands
void SSD1306_SendCommand(uint8_t command)
{
    uint8_t cmd[] = { SSD1306_COMMAND, command };
    I2C_Host.Write(SSD1306_I2C_ADDRESS, cmd, sizeof(cmd));
    while (I2C_Host.IsBusy())
    {
    }
}

// Send I2C Data
void SSD1306_SendData(uint8_t data)
{
    uint8_t d[] = { SSD1306_DATA_CONTINUE, data };
    I2C_Host.Write(SSD1306_I2C_ADDRESS, d, sizeof(d));
    while (I2C_Host.IsBusy())
    {
    }
}

// Function to write a string to OLED, passed string
void SSD1306_WriteString(char *characters)
{
    while (*characters)
    {
        SSD1306_WriteCharacter(*characters++);
    }
}

// Function to write a character, passed character
void SSD1306_WriteCharacter(char character)
{
    for (int i = 0; i < 5; i++)
    {
        SSD1306_SendData((ASCII[character - 0x20][i]));
    }
    SSD1306_SendData(0x00);
}

// Function to clear OLED screen.
void SSD1306_Clear()
{
    SSD1306_SelectPage(0);
    // SSD1306_CLEAR_SIZE  = 1024  for 128*64
    for (int i = 0; i < SSD1306_CLEAR_SIZE; i++)
    {
        SSD1306_SendData(0x00); // Clear oled screen
    }
}

// Function to clear OLED  line passed page number
void SSD1306_ClearLine(uint8_t page_num)
{
    SSD1306_SelectPage(page_num);
    // Clear line of 128 pixels of current page
    for (int i = 0; i < 128; i++)
    {
        SSD1306_SendData(0x00); // Clear oled screen
    }
}

// Function to select [page] i.e. row or line number
// 128* 64 has page 0-7
// Passed page num / byte
// page 0   8
// page 1   16
// page 2   24
// page 3   32
// page 4   40
// page 5   48
// page 6   56
// page 7   64

void SSD1306_SelectPage(uint8_t page_num)
{
    uint8_t Result = 0xB0 | page_num; // Mask or with zero lets everything thru
    SSD1306_SendCommand(Result);
    SSD1306_SendCommand(SSD1306_SET_LOWER_COLUMN);
    SSD1306_SendCommand(SSD1306_SET_HIGHER_COLUMN);
}

// Draw bitmap
void SSD1306_DrawBitmap(const uint8_t *bitmap)
{
    uint16_t byteIndex = 0;

    // Loop through each row of 8 vertical pixels (8 rows for a 128x64 display)
    for (uint8_t row = 0; row < 4; row++)
    {
        // Loop through each column (128 columns) per row
        for (uint8_t col = 0; col < 128; col++)
        {
            // Get the corresponding byte in the bitmap (each byte represents 8
            // vertical pixels?)
            SSD1306_SendData(bitmap[byteIndex]);

            byteIndex++; // Move to the next byte
        }
    }

    SSD1306_SendData(0x00);
    _delay_ms(50);
}
