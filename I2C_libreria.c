/*
 * File:   I2C_libreria.c
 * Author: josue
 *
 * Created on 16 de abril de 2019, 10:28 AM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000 

#define SCL TRISCbits.TRISC3 
#define SDA TRISCbits.TRISC4

void Inicializacion_I2C()
{
    SCL=1;
    SDA=1;
    SSPSTAT=0b10000000;
    SSPCON=0b00101000;
    SSPCON2=0b00000000;
    SSPADD=9;
}

void verifica_I2C(){
    while((SSPCON2 & 0b00011111) || (SSPSTAT & 0b00000100));
}

void i2c_inicia_com() {
    verifica_I2C();        
    SSPCON2bits.SEN = 1; 
}

void i2c_reinicia_com(){
    verifica_I2C();        
    SSPCON2bits.RSEN = 1; 
}

void i2c_detener() {
    verifica_I2C();   
    SSPCON2bits.PEN = 1; 
}

unsigned char i2c_envia_dato(unsigned char dato) {
    verifica_I2C(); 
    SSPBUF = dato;  
    return  ACKSTAT;
}

unsigned char i2c_recibe_dato(){
 
    unsigned char datoleido; //variable para guardar el dato que se reciba o lea
                             //del esclavo
 
    verifica_I2C(); 
    SSPCON2bits.RCEN = 1; //reinicia la comunicaci�n i2c, ya que la comunicaci�n
                          //se ha tenido que iniciar antes, para enviar la
                          //direcci�n del esclavo y del registro a leer
    
    verifica_I2C(); 
    datoleido = SSPBUF;   //el dato recibido en el registro SSPBUF
                          //se guarda en la variable datoleido
 
    verifica_I2C(); 
 
    SSPCON2bits.ACKDT = 1;  //el maestro lo pone a 1 despu�s de leer o recibir el dato, 
                            //luego el maestro habilitar� ACKAEN y enviar� al esclavo
                            //el ACKDT para indicarle al esclavo que ya no se leer�n
                            //mas datos
 
    SSPCON2bits.ACKEN = 1;//inicia secuencia final de reconocimiento de SDA y SCL por 
                          //parte del maestro para enviarle al esclavo el valor de ACKDT
                          //en este caso le enviar� un 1 para decirle que ya no se 
                          //recibir�n mas datos 
    return datoleido;
}