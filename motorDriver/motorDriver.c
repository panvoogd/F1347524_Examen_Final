#include "motorDriver.h"

/*
Implementar el codigo fuente de las fuciones
iniciarModulo(),
avanzar(),
retroceder(),
girarDerecha(),
girarIzquierda()

*/
void inicializarModulo()
{
    RCC->APB1ENR |= (1<<19);
    RCC->APB2ENR |= (1<<4) | (1<<3) | (1<<2) ;// Se habilita el clock PA, PA6

    GPIOA->CRL  &= ~(0xFFFF << 16); // Se hace reset de GPIOA PA4, PA5, PA6, PA7
    GPIOA->CRL  |= ~(0x3333 << 16); // Se los pone como salidas digitales
    GPIOA->ODR &= ~(0xF << 4);  // Se le pone valor 0
    
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |= (0x3 << 20);
    GPIOC->ODR &= ~(1<<13);

    GPIOB->CRH &= ~(0xFF << 0);  // Se hace reset GPIOB PB8 y PB9
    GPIOB->CRH |=(0x99 << 0);  // Se los pone como salidas digitales alternas

    TIM4_CCMR2 |= ((0x68 << 8) | (0x68 << 0)); 
    TIM4_BDTR |= (1 << 15);
    TIM4_CCER |= (1 << 12) | (1 << 8);
    TIM4_PSC = 7;

    TIM4_ARR = 40000;
    TIM4_CCR4 = 0;
    TIM4_CCR3 = 0;

    TIM4_CR1 |= (1<<7)|(1<<0);
}