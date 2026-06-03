#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

#define TIM_SR (*(volatile uint32_t *)(0x40000000 + 0x10))
#define APB1ENR (*(volatile uint32_t *)(0x40021000 + 0x1C))
#define TIM_CR1 (*(volatile uint32_t *)(0x40000000 + 0x00))
#define TIM_PSC (*(volatile uint32_t *)(0x40000000 + 0x28))
#define TIM_ARR (*(volatile uint32_t *)(0x40000000 + 0x2C))
#define TIM_DIER (*(volatile uint32_t *)(0x40000000 + 0x0C))
#define NVIC_ISER0 (*(volatile uint32_t *)(0xE000E100))

void TIM_init();
void TIM2_IRQHandler(void);
#endif