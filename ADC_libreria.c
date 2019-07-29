/*
 * File:   ADC_libreria.c
 * Author: josue
 *
 * Created on 10 de diciembre de 2018, 12:06 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000

#define AN0 TRISAbits.TRISA0
#define AN1 TRISAbits.TRISA1
#define AN2 TRISAbits.TRISA2

 int inicia_ADC()
{
     AN0=1;       //canal 0
     AN1=1;       //canal 1
     AN2=1;       //canal 2
     
     //ANSELbits.ANS0=1;      //entrada analogica activada
     //ANSELbits.ANS1=1;
     
     ADCON1=0b10001011;
     ADCON0=0b00000001;
}
 
 int convercion_ADC(int canal)
 {
     int resultado=0;
     switch(canal)
     {
         case 0:
             ADCON0=0B00000001;         //canal 0 ADC
             __delay_us(30);
             ADCON0bits.GO=1;
             while(ADCON0bits.GO==1);
             
             resultado =ADRESH;
             resultado=resultado<<8;
             resultado=resultado+ADRESL;
             return (resultado);
         break;
         
         case 1:
             ADCON0=0B00000101;         //canal 1 ADC
             __delay_us(30);
             ADCON0bits.GO=1;
             while(ADCON0bits.GO==1);
             
             resultado =ADRESH;
             resultado=resultado<<8;
             resultado=resultado+ADRESL;
             return (resultado);
         break;
         
         case 2:
             ADCON0=0B00001001;         //canal 2 ADC
             __delay_us(30);
             ADCON0bits.GO=1;
             while(ADCON0bits.GO==1);
             
             resultado =ADRESH;
             resultado=resultado<<8;
             resultado=resultado+ADRESL;
             return (resultado);
         break;
         
         case 3:
             ADCON0=0B00001101;         //canal 3 ADC
             __delay_us(30);
             ADCON0bits.GO=1;
             while(ADCON0bits.GO==1);
             
             resultado =ADRESH;
             resultado=resultado<<8;
             resultado=resultado+ADRESL;
             return (resultado);
         break;
     }
 }
