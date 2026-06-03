#ifndef ADC_H
#define ADC_H
#include <stdint.h>

#define APB2ENR (*(volatile uint32_t *)(0x40021000 + 0x18))
#define ADC1 (*(volatile uint32_t *)(0x40012400))
#define GPIOA_CRL (*(volatile uint32_t *)(0x40010800 + 0x00)
#define RCC_CFGR (*(volatile uint32_t *)(0x40021000 + 0x04))
#define ADC_CR1 (*(volatile uint32_t *)(0x40012400 + 0x04))
#define ADC_SMPR2 (*(volatile uint32_t *)(0x40012400 + 0x10))
#define ADC_SQR3 (*(volatile uint32_t *)(0x40012400 + 0x34))
#define ADC_CR2 (*(volatile uint32_t *)(0x40012400 + 0x08))
#define ADC_SR (*(volatile uint32_t *)(0x40012400 + 0x00))
#define ADC_DR (*(volatile uint32_t *)(0x40012400 + 0x4C))

void ADC_init();
void ADC_data();

#endif