#include <stdint.h>
#include "motorDriver/motorDriver.h"
#include "serialUart/serialUart.h"
#include "incFiles/stm32f103x6.h"

int main(void)
{
	/*
	Desarrollar el flujo principal del programa utilizando las librerias motorDriver y serialUart
	*/
	inicializarUart();
	inicializarModulo();

		while(1)
		{
			if (existeCaracter()) 
			{
				uint8_t caracter = leerCaracter();

				switch (caracter)
					{
						case 'a':
							avanzar(1);
							break;
			
						case 'w':
							avanzar(2);
							break;

						case 'b':
							retroceder(1);
							break;
		
						case 's':
							retroceder(2);
							break;

						case 'q':
							girarDerecha();
							break;
			
						case 'e':
							girarIzquierda();
							break;

						default:
							break;
					}
			}
		}
	return 0;
}