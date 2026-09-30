/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    CLCD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelrahman yasser
 *  Layer  : HAL
 *  SWC    : CLCD
 *
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "CLCD_config.h" // to khow the mode



/*

###########  8 Bits Mode
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PA7|---------------->|D7        |
 |        PA6|---------------->|D6        |
 |        PA5|---------------->|D5        |
 |        PA4|---------------->|D4        |
 |        PA3|---------------->|D3        |
 |        PA2|---------------->|D2        |
 |        PA1|---------------->|D1        |
 |        PA0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */




#if   CLCD_MODE == 4
#define FOUR_BITS                     0x28          //4 bits mode initialization
#elif CLCD_MODE == 8
#define EIGHT_BITS                    0x38          //8 bits mode initialization (8-bit data, 2-line display, 5 x 7 font )
#endif
/********/

#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character 
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character 
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'  
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line 
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD

#define CLCD_ROW_1  1
#define CLCD_ROW_2  2

#define CLCD_COLUMN_1  1
#define CLCD_COLUMN_2  2
#define CLCD_COLUMN_3  3
#define CLCD_COLUMN_4  4
#define CLCD_COLUMN_5  5
#define CLCD_COLUMN_6  6
#define CLCD_COLUMN_7  7
#define CLCD_COLUMN_8  8
#define CLCD_COLUMN_9  9
#define CLCD_COLUMN_10 10
#define CLCD_COLUMN_11 11
#define CLCD_COLUMN_12 12
#define CLCD_COLUMN_13 13
#define CLCD_COLUMN_14 14
#define CLCD_COLUMN_15 15
#define CLCD_COLUMN_16 16

void CLCD_voidInit(void);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidClearScreen(void);
void CLCD_voidSendString(const u8 *Copy_prtString);
void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Column);
void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Column);
