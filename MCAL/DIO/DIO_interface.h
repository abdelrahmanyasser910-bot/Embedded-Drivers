#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00

#define DIO_PORT_LOW  0x00
#define DIO_PORT_HIGH 0xff

typedef enum
{
    DIO_OK,
    DIO_NOK

} DIO_ErrorState;

DIO_ErrorStatus DIO_enumSetPinDirection      (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction     );
DIO_ErrorStatus DIO_enumSetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value         );
DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData       );
DIO_ErrorStatus DIO_enumTogglePinValue       (u8 Copy_u8PORT, u8 Copy_u8PIN                          );
DIO_ErrorState DIO_enumSetPortDirection   (u8 copy_u8Port , u8 copy_u8Direction               );
DIO_ErrorState DIO_enumSetPortValue       (u8 copy_u8Port , u8 copy_u8Value                           );
DIO_ErrorState DIO_enumTogglePortValue     (u8 copy_u8Port);
DIO_ErrorState DIO_enumGetPortValue       (u8 copy_u8Port , u8 * copy_PtrData);

#endif 