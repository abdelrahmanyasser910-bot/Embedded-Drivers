#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*
 * Breif : This Function set the direction of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */

DIO_ErrorState DIO_enumSetPinDirection    (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction)
{
    DIO_ErrorState LOC_enumState = DIO_OK;
    if((copy_u8Port <= DIO_PORTD) && (copy_u8Pin <= DIO_PIN7))
    {
        if(copy_u8Direction == DIO_PIN_OUTPUT)
        {
            switch(copy_u8Port)
        {
            case DIO_PORTA: SET_BIT(DDRA,copy_u8Pin); break;
            case DIO_PORTB: SET_BIT(DDRB,copy_u8Pin); break;
            case DIO_PORTC: SET_BIT(DDRC,copy_u8Pin); break;
            case DIO_PORTD: SET_BIT(DDRD,copy_u8Pin); break;
        }
    else if(copy_u8Direction == DIO_PIN_INPUT)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: CLR_BIT(DDRA,copy_u8Pin); break;
            case DIO_PORTB: CLR_BIT(DDRB,copy_u8Pin); break;
            case DIO_PORTC: CLR_BIT(DDRC,copy_u8Pin); break;
            case DIO_PORTD: CLR_BIT(DDRD,copy_u8Pin); break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
     return LOC_enumState;
}
}

/*
 * Breif : This Function set the Value of the Pin  (HIGH || LOW)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Value --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */

DIO_ErrorState DIO_enumSetPinValue        (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value    )
if((copy_u8Port <= DIO_PORTD) && (copy_u8Pin <= DIO_PIN7))

{
    DIO_ErrorState LOC_enumState = DIO_OK;
    if(copy_u8Value == DIO_PIN_HIGH)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: SET_BIT(PORTA,copy_u8Pin); break;
            case DIO_PORTB: SET_BIT(PORTB,copy_u8Pin); break;
            case DIO_PORTC: SET_BIT(PORTC,copy_u8Pin); break;
            case DIO_PORTD: SET_BIT(PORTD,copy_u8Pin); break;
        }
    }
    else if(copy_u8Value == DIO_PIN_LOW)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: CLR_BIT(PORTA,copy_u8Pin); break;
            case DIO_PORTB: CLR_BIT(PORTB,copy_u8Pin); break;
            case DIO_PORTC: CLR_BIT(PORTC,copy_u8Pin); break;
            case DIO_PORTD: CLR_BIT(PORTD,copy_u8Pin); break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
     return LOC_enumState;
}

/*
 * Breif : This Function Get the Value of the Pin
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => *Copy_PtrData  --> pointer to recieve the pin value
 * return : its status and recieve Pin Value in pointer
 */

 DIO_ErrorState DIO_enumGetPinValue        (u8 copy_u8Port , u8 copy_u8Pin   , u8_*copy_ptrdata                   )
 DIO_ErrorState LOC_enumState = DIO_OK;

 if((copy_u8Port <= DIO_PORTD) && (copy_u8Pin <= DIO_PIN7))
{
    u8 Local_u8Status = 0;
     switch(copy_u8Port)
        {
            case DIO_PORTA: *copy_ptrdata = GET_BIT(PINA,copy_u8Pin); break;
            case DIO_PORTB: *copy_ptrdata = GET_BIT(PINB,copy_u8Pin); break;
            case DIO_PORTC: *copy_ptrdata = GET_BIT(PINC,copy_u8Pin); break;
            case DIO_PORTD: *copy_ptrdata = GET_BIT(PIND,copy_u8Pin); break;
        }
    
    
}
else
{
    LOC_enumState = DIO_NOK;
}
return LOC_enumState;


void DIO_voidTogglePinValue     (u8 copy_u8Port , u8 copy_u8Pin                      )
{
    switch(copy_u8Port)
        {
            case DIO_PORTA: TOG_BIT(PORTA,copy_u8Pin); break;
            case DIO_PORTB: TOG_BIT(PORTB,copy_u8Pin); break;
            case DIO_PORTC: TOG_BIT(PORTC,copy_u8Pin); break;
            case DIO_PORTD: TOG_BIT(PORTD,copy_u8Pin); break;
        }
}

/*
 * Breif : This Function Toggle the Value of the Pin
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status
 */

DIO_ErrorState DIO_enumSetPortDirection   (u8 copy_u8Port , u8 copy_u8Direction               )
{
    DIO_ErrorState LOC_enumState = DIO_OK;

    if (copy_u8Port <= DIO_PORTD)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: DDRA_Register = copy_u8Direction; break;
            case DIO_PORTB: DDRB = copy_u8Direction; break;
            case DIO_PORTC: DDRC = copy_u8Direction; break;
            case DIO_PORTD: DDRD = copy_u8Direction; break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    
}


/*
 * Breif : This Function Set value on Port
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Value  --> The Value  [DIO_PORT_HIGH , DIO_PORT_LOW , Another Value]
 * return : its status
 */

DIO_ErrorState DIO_enumSetPortValue       (u8 copy_u8Port , u8 copy_u8Value                           )
{
    DIO_ErrorState LOC_enumState = DIO_OK;
    if (copy_u8Port <= DIO_PORTD)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: PORTA = copy_u8Value; break;
            case DIO_PORTB: PORTB = copy_u8Value; break;
            case DIO_PORTC: PORTC = copy_u8Value; break;
            case DIO_PORTD: PORTD = copy_u8Value; break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

/*
 * Breif : This Function Toggle value on Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status
 */

DIO_ErrorState DIO_enumTogglePortValue     (u8 copy_u8Port)

{
    DIO_ErrorState LOC_enumState = DIO_OK;
    if (copy_u8Port <= DIO_PORTD)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: PORTA = ~ PORTA; break;
            case DIO_PORTB: PORTB = ~ PORTB; break;
            case DIO_PORTC: PORTC = ~ PORTC; break;
            case DIO_PORTD: PORTD = ~ PORTD; break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}

DIO_ErrorState DIO_enumGetPortValue       (u8 copy_u8Port , u8 * copy_PtrData);
{
    DIO_ErrorState LOC_enumState = DIO_OK;
    if (copy_u8Port <= DIO_PORTD)
    {
        switch(copy_u8Port)
        {
            case DIO_PORTA: *copy_PtrData = PINA; break;
            case DIO_PORTB: *copy_PtrData = PINB; break;
            case DIO_PORTC: *copy_PtrData = PINC; break;
            case DIO_PORTD: *copy_PtrData = PIND; break;
        }
    }
    else
    {
        LOC_enumState = DIO_NOK;
    }
    return LOC_enumState;
}