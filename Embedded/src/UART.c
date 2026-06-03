#include <stdint.h>
#include <UART.h>

int UART_INFO(void){
    for(int i=0; STR_HELLO[i] != '\0'; i++){
    while(!(USART_SR & (1<<7)));
    USART_DR = STR_HELLO[i];
    };
}

void UART_INIT(){
 
    APB2ENR |= (1<<14) | (1<<2);
    USART_CRH &= ~(0xf<<4);
    USART_CRH |= (0x9<<4);
    USART_CRH &= ~(0xf<<8);
    USART_CRH |= (0x4<<8);
    USART_BRR = 833;
    USART_CR1 |= (1<<13) | (1<<3);
    UART_INFO();
    while(!(USART_SR & (1<<6)));
    while(1);
}