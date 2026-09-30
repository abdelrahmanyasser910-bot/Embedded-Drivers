#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


/*
* Breif : This Function Apply initialization sequence for LCD module
* Parameters : nothing
* return : nothing
*/


void CLCD_voidInit(void)
{
    #if CLCD_MODE == 8

    ddelay_ms(50);

    void DIO_enumSetPortDirection(CLCD_DATA_PORT, DIO_PORT_OUTPUT);
    void DIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_OUTPUT);
    void DIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_OUTPUT);
    void DIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_OUTPUT);
     
    /* Return cursor to the first position on the first line  */
    CLCD_voidSendCommand(lcd_home);
    delay_ms(1);
     
    /*FUNCTION SET Command : 2 lines , 5*8 font size */
    CLCD_voidSendCommand(EIGHT_BITS); // 8 Bit Mode ==> 0x38
    delay_ms(1);
     
    /* DISPLAY & Cursor (ON / OFF) Control */
    CLCD_voidSendCommand(lcd_DisplayOn_CursorOff);
    delay_ms(1);
    
    /* DISPLAY CLEAR */
    CLCD_voidClearScreen();

    /* ENTRY MODE  SET*/
    CLCD_voidSendCommand(lcd_EntryMode);
    delay_ms(1);

}

/*
* Breif : This Function send data to the port which is defined in config.h
* Parameters :
            => Copy_u8Data --> Data that you want to display (for every pixel )
* return : nothing
*/


void CLCD_voidSendData(u8 Copy_u8Data)
{
    #if CLCD_MODE ==  8

    DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Data);
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_HIGH);      
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
    CLCD_voidSendfallingEdge();

    #elif CLCD_MODE == 4

    #endif

    delay_ms(1);
       
}

/*
* Breif : This Function Interface to send the configuration commands to the LCD Driver
* Parameters :
            => Copy_u8Command --> Command number
* return : nothing
*Hint : RS pin Mode is the difference between this function and the previous (CLCD_voidSendData)
*/


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
    #if CLCD_MODE ==  8

    DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Command);
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_PIN_LOW);
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_PIN_LOW);
    CLCD_voidSendfallingEdge();
    #elif CLCD_MODE == 4

    #endif

    delay_ms(1);
       
}

/*
* Breif : This Function send string to the port which is defined in config.h
* Parameters :
            => * Copy_u8ptrString  --> Pointer to the string
* return : nothing
*/

void CLCD_voidSendString(const u8 *Copy_prtString)
{
    u8 Local_u8Iterator = 0;
    while(Copy_prtString[Local_u8Iterator] != '\0')
    {
        CLCD_voidSendData(Copy_prtString[Local_u8Iterator]);
        Local_u8Iterator++;
    }       

}

/*
* Breif : This Function set the curser position
* Parameters :
            => Copy_u8Row --> row number (CLCD_ROW_1 or CLCD_ROW_2)
			=> Copy_u8Col --> column number (CLCD_COL_1 ... CLCD_COL_16)
* return : nothing
*Hint :-
   In This function we send a command which =0b1xxxxxxx
   MSB = 1  ===> refers that it is command to set cursor
   xxxxxxx  ===> refers to AC ( Address Counter 7Bits / DDRAM Locations 128Location )
*/

void_CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Column)
{
    u8 Local_u8Adata ;
    if(Copy_u8Row >2||copy_u8Row<1||Copy_u8Column>16||Copy_u8Column<1)
    {
        u8 Local_u8Adata = lcd_SetCursor ;
    }
    else if(Copy_u8Row == 1)
    {
        Local_u8Adata = ( lcd_SetCursor + (Copy_u8Column - 1));
    }
    else if(Copy_u8Row == 2)
    {
        Local_u8Adata = ( lcd_SetCursor + (64) + (Copy_u8Column - 1));
    }
    
       
    

}

/*
* Breif : This Function send extra char
* Parameters :
            => Copy_u8Row --> row number (CLCD_ROW_1 or CLCD_ROW_2)
			=> Copy_u8Col --> column number (CLCD_COL_1 ... CLCD_COL_16)
* return : nothing
* Hint :-
	Address Counter can refer to CGRAM and DDRAM
*/

void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Column)
{
    u8 Local_u8Iterator = 0;

    /* 1- Go To CGRAM            */
    CLCD_voidSendCommand(lcd_CGRAM);

    /* 2- Draw Character in CGRAM        */
	/* Hint : it will be copied to DDRAM automatically */
    for(local_u8Iterator = 0; Local_u8Iterator < sizeof(CLCD_u8ExtraChar)/sizeof(CLCD_u8ExtraChar[0]); Local_u8Iterator++)
    {
        CLCD_voidSendData(CLCD_u8ExtraChar[Local_u8Iterator]);
    }
       
      /* 3- Back (AC) To DDRAM          */
    void CLCD_voidSetPosition(Copy_u8Row, Copy_u8Column);

    /* 4- Send Character Address */
    for(local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
    {
        CLCD_voidSendData(local_u8Iterator);
    }
}

static void CLCD_voidSendFallingEdge(void)
{
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_HIGH);
    delay_ms(1);
    DIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, DIO_PIN_LOW);
    delay_ms(1);
}



CLCD_voidClearScreen()
{
    CLCD_voidSendCommand(lcd_Clear);
    delay_ms(5);
}