#include <stdint.h>
#include "../incFiles/stm32f103x6.h"

#define TIM4_BASE 0x40000800
#define TIM4_PSC (*((unsigned int*) (TIM4_BASE + 0x28)))
#define TIM4_ARR (*((unsigned int*) (TIM4_BASE + 0x2C)))
#define TIM4_CCR4 (*((unsigned int*) (TIM4_BASE + 0x40)))
#define TIM4_CCR3 (*((unsigned int*) (TIM4_BASE + 0x3C)))
#define TIM4_CCMR2 (*((unsigned int*) (TIM4_BASE + 0x1C)))
#define TIM4_BDTR (*((unsigned int*) (TIM4_BASE + 0x44)))
#define TIM4_CCER (*((unsigned int*) (TIM4_BASE + 0x20)))
#define TIM4_CR1 (*((unsigned int*) (TIM4_BASE + 0x00)))

/*
Desarrollar los prototipos de
iniciarModulo(),
avanzar(),
retroceder(),
girarDerecha(),
girarIzquierda()
*/
void inicializarModulo (void);