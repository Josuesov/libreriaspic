/*
 * File:   USART_libreria.c
 * Author: josue
 *
 * Created on 10 de diciembre de 2018, 12:19 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000 

#define RX TRISCbits.TRISC7 
#define TX TRISCbits.TRISC6

int Inicializacion_usart()
{
    RX=1;     //Rx
    TX=0;     //Tx
    
    TXSTA=0b00100110;
    RCSTA=0b10010000;
    SPBRG=25;
}

char Envia_usart(char dato)
{
    while (TRMT==0);
    TXREG=dato;
}

char Cadena_usart(char cadena[])
{
    int i=0;
        while (cadena[i]!=0)
        {
            Envia_usart(cadena[i]);
            i++;
        }
}
