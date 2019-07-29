/*
 * File:   Teclado.c
 * Author: josue
 *
 * Created on 23 de julio de 2018, 11:01 PM
 */

#include <xc.h>
#define _XTAL_FREQ 4000000 

int Lee_Tecl()
{
    PORTB=0XFE;
    __delay_ms(10);
    int a=0;
    
    for (int i=0; i<4 ;i++ ) 
    {
        
        if (PORTBbits.RB4==0)   
        {
            switch (i)
            {
            case 0:
                a=1;    
                break;
            
            case 1:
                a=2;
                break;
            
            case 2:
                a=3;
                break;
            
            case 3:
                a=4;
                break;  
            }
            __delay_ms(250);
            return(a);
        }
        
        if (PORTBbits.RB5==0)
        {
            switch (i)
            {
            case 0:
                a=5;    
                break;
            
            case 1:
                a=6;
                break;
            
            case 2:
                a=7;
                break;
            
            case 3:
                a=8;
                break;  
            }
            __delay_ms(250);
            return(a);
        }
        
        if (PORTBbits.RB6==0)
        {
            switch (i)
            {
            case 0:
                a=9;    
                break;
            
            case 1:
                a=10;
                break;
            
            case 2:
                a=11;
                break;
            
            case 3:
                a=12;
                break;  
            }
            __delay_ms(250);
            return(a);
        }
        
        if (PORTBbits.RB7==0)
        {
            switch (i)
            {
            case 0:
                a=13;    
                break;
            
            case 1:
                a=14;
                break;
            
            case 2:
                a=15;
                break;
            
            case 3:
                a=16;
                break;  
            }
            __delay_ms(250);
            return(a);           
        }
        PORTB=PORTB << 1;       //desplaza bits
        PORTBbits.RB0=1;
        __delay_ms(100);
        
    }
    return(a=0);  
}