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
    TIM4_PSC = 7; // Prescaler, frecuencia de Clk 1 MHz

    TIM4_ARR = 40000; // Con esto se genera onda de 100 Hz
    TIM4_CCR4 = 0; // Duty cycle a 0%
    TIM4_CCR3 = 0; // Duty cycle a 0%

    TIM4_CR1 |= (1<<7)|(1<<0); // Se habilita el temporizador
}

void avanzar(uint8_t vel)
{
     GPIOA->ODR |= (0x6 << 5); // PA5 y PA6 en ALTA
     GPIOA->ODR &= ~(0x9 << 4); // PA4 y PA7 en BAJA
     if (vel == 1) // Velocidad 1
     {
        TIM4_CCR4 = 20000; // duty cycle a 50%
        TIM4_CCR3 = 20000; // duty cycle a 50%
        delay(1000); // 
     }
     if (vel == 2) // Velocidad 2
     {
        TIM4_CCR4 = 40000; // duty cycle a 100%
        TIM4_CCR3 = 40000; // duty cycle a 100%
        delay(1000);
     }
    TIM4_CCR4 = 0; // Se pone el duty cycle a 0% de nuevo
    TIM4_CCR3 = 0; // Se pone el duty cycle a 0% de nuevo
}
void retroceder(uint8_t vel)
{
     GPIOA->ODR &= ~(0x6 << 5); // PA5 y PA6 en BAJA
     GPIOA->ODR |= (0x9 << 4); // PA4 y PA7 en ALTA
     if (vel == 1) // Velocidad 1
     {
        TIM4_CCR4 = 20000; // duty cycle a 50%
        TIM4_CCR3 = 20000; // duty cycle a 50%
        delay(1000); // 
     }
     if (vel == 2) // Velocidad 2
     {
        TIM4_CCR4 = 40000; // duty cycle a 100%
        TIM4_CCR3 = 40000; // duty cycle a 100%
        delay(1000);
     }
    TIM4_CCR4 = 0; // Se pone el duty cycle a 0% de nuevo
    TIM4_CCR3 = 0; // Se pone el duty cycle a 0% de nuevo
}

void girarIzquierda()
{
    GPIOA->ODR |= (0x5 << 5); // PA5 y PA7 en ALTA
    GPIOA->ODR &= ~(0x5 << 4); // PA4 y PA6 en BAJA
    
    TIM4_CCR4 = 20000; // duty cycle a 50%
    TIM4_CCR3 = 20000; // duty cycle a 50%
    delay(1000); // Delay de 1 segundo
    TIM4_CCR4 = 0; // Se pone el duty cycle a 0% de nuevo
    TIM4_CCR3 = 0; // Se pone el duty cycle a 0% de nuevo
}

void girarDerecha()
{
    GPIOA->ODR &= ~(0x5 << 5); // PA5 y PA7 en BAJA
    GPIOA->ODR |= (0x5 << 4); // PA4 y PA6 en ALTA
    
    TIM4_CCR4 = 20000; // duty cycle a 50%
    TIM4_CCR3 = 20000; // duty cycle a 50%
    delay(1000); // Delay de 1 segundo
    TIM4_CCR4 = 0; // Se pone el duty cycle a 0% de nuevo
    TIM4_CCR3 = 0; // Se pone el duty cycle a 0% de nuevo
}