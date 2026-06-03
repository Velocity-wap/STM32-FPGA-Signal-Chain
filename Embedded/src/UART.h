#ifndef UART_H
#define UART_H
#include <stdint.h>

#define USART1 (*(volatile uint32_t *)(0x40013800))
#define APB2ENR (*(volatile uint32_t *)(0x40021000 + 0x18))
#define USART_CRH (*(volatile uint32_t *)(0x40010800 + 0x04))
#define USART_SR (*(volatile uint32_t *)(0x40013800 + 0x00))
#define USART_DR (*(volatile uint32_t *)(0x40013800 + 0x04))
#define USART_BRR (*(volatile uint32_t *)(0x40013800 + 0x08))
#define USART_CR1 (*(volatile uint32_t *)(0x40013800 +0x0C))
#define USART_ODR (*(volatile uint32_t *)(0x40011000 + 0x0C))
#define GPIOC_CRH (*(volatile uint32_t *)(0x40011000 + 0x04))

#define STR_HELLO  "Hello World"

void UART_INFO(void);
void UART_INIT(void);
#endif