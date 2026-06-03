#include <stdint.h>
#include <Timer.h>
int main(){
    TIM_init();
}

void TIM_init(){

    APB1ENR |= (1<<0);
    TIM_PSC = 7999;
    TIM_ARR = 999;
    TIM_DIER |= (1<<0);
    NVIC_ISER0 |= (1<<28);
    TIM_CR1 |= (1<<0);
    while(1){
    }
}

void  TIM2_IRQHandler(void){
    TIM_SR &= ~(1<<0);
}
