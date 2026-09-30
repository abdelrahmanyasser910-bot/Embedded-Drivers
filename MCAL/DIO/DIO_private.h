#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*GROUP A*/

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)

/*GROUP B*/

#define DDRB *((volatile u8*)0x3B)
#define PORTB *((volatile u8*)0x38)
#define PINB *((volatile u8*)0x37)

/*GROUP C*/

#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC *((volatile u8*)0x33)

/*GROUP D*/
#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND *((volatile u8*)0x30)



#endif /* DIO_PRIVATE_H_ */