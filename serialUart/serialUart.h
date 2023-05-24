#include <stdint.h>
#include "../incFiles/stm32f103x6.h"

void inicializarUart(void);
void enviarCaracter(uint8_t caracter);
void nuevaLinea(void);
void enviarPalabra(uint8_t cadena[]);

/*
Desarrollar el prototipo de las funciones: 
existeCaracter()
leerCaracter()
*/

uint_8t existeCaracter(void);
uint_8t leerCaracter(void);
