#include <stdint.h>
#include "ADC.h"

void ADC_data(){
    uint16_t adc = ADC_DR;
}
void ADC_init(){
    APB2ENR |= (1<<9) | (1<<2);
    GPIOA_CRL &= ~(0xf<<0);
    RCC_CFGR &= ~(0x00 << 0);
    ADC_CR2 |= (1<<0);
    for(int i = 0; i<100; i++);
    ADC_SMPR2 |= (0x2<<0);
    ADC_SQR3 &= ~(0x1f << 0);
    ADC_SQR3 |= (0<<0);
    ADC_CR2 |= (1<<22);
    while(!(ADC_SR & (1<<1)));
    ADC_data();
}

int main(){
    ADC_init();
}
