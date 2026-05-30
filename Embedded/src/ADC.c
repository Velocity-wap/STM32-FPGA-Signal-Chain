#include <stdint.h>

uint32_t *APB2ENR = (uint32_t *)(0x40021000 + 0x18);
uint32_t *ADC1 = (uint32_t *)(0x40012400);
uint32_t *GPIOA_CRL = (uint32_t *)(0x40010800 + 0x00);
uint32_t *RCC_CFGR = (uint32_t *)(0x40021000 + 0x04);
uint32_t *ADC_CR1 = (uint32_t *)(0x40012400 + 0x04);
uint32_t *ADC_SMPR2 = (uint32_t *)(0x40012400 + 0x10);
uint32_t *ADC_SQR3 = (uint32_t *)(0x40012400 + 0x34);
uint32_t *ADC_CR2 = (uint32_t *)(0x40012400 + 0x08);
uint32_t *ADC_SR = (uint32_t *)(0x40012400 + 0x00);
uint32_t *ADC_DR = (uint32_t *)(0x40012400 + 0x4C);

void ADC_init(){
    *APB2ENR |= (1<<9) | (1<<2);
    *GPIOA_CRL &= ~(0xf<<0);
    *RCC_CFGR &= ~(0x00 << 0);
    *ADC_CR2 |= (1<<0);
    for(int i = 0; i<100; i++);
    *ADC_SMPR2 |= (0x2<<0);
    *ADC_SQR3 &= ~(0x1f << 0);
    *ADC_SQR3 |= (0<<0);
    *ADC_CR2 |= (1<<22);
    while(!(*ADC_SR & (1<<1)));
    uint16_t adc = *ADC_DR;
}

int main(){
    ADC_init();
}
