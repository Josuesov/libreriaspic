/*
 * File:   LCD_libreria.c
 * Author: josue
 *
 * Created on 7 de diciembre de 2018, 12:02 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000 

#define RS PORTCbits.RC0
#define E PORTCbits.RC1

char Envia_instr(char dat)
{
    //PORTAbits.RA6=0;        //RW RA6
    RS=0;        //RS RA7
    
    PORTB=dat;           //manda nible superior
    E=1;        //E RA5
    __delay_ms(1);
    E=0;
    
    PORTB=dat<<4;              //manda nible inferior
    E=1;
    __delay_ms(1);
    E=0;
}

char Envia_dat(char dat)
{
    //PORTAbits.RA6=0;        //RW
    RS=1;        //RS
    
    PORTB=dat;           //manda nible superior
    E=1;
    __delay_ms(1);
    E=0;
    
    PORTB=dat<<4;              //manda nible inferior
    E=1;
    __delay_ms(1);
    E=0;
}


int Inicia_LCD()
{
    
    PORTB=0;
    PORTC=0;
    TRISB=0X01;     //PARA USAR BUS DE 4 BITS
    TRISC=0X00;     //PARA RS,RW, E 
    
    //ANSELbits.ANS4=0;       //ENTRADA ANALOGICA DESACTIVADA
    E=0;        //eneable off
    
    char aux;
    
    aux=0x33;
    Envia_instr(aux);
    __delay_ms(5);
    
    aux=0x32;
    Envia_instr(aux);
    __delay_ms(5);
    
    aux=0x29;
    Envia_instr(aux);
    __delay_ms(5);
    
    aux=0x0C;
    Envia_instr(aux);
    __delay_ms(5);
    
}

char Envia_cadena(char cadena [])
{
    int i=0;
    while (cadena[i]!=0)
    {
        Envia_dat(cadena[i]);
        i++;
    }
}

int Posicion_xy(int x, int y)
{
    int dato=0;
    if (x==1)
    {
        dato=128+y;
        Envia_instr(dato);
//        return;
    }
    
    if (x==2)
    {
        dato=192+y;
        Envia_instr(dato);
//        return;
    }
}


int limpia_LCD()
{
    int dato=0x01;
    Envia_instr(dato);
}

int home()
{
    int dato=0x02;
    Envia_instr(dato);
}