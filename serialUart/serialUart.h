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

void existeCaracter(uint8_t existeDato);
void leerCaracter(uint8_t caracter);
