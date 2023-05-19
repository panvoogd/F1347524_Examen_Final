# examenFinalArm
Curso PROGRAMACIÓN DE MICROCONTROLADORES ARM 
EXAMEN FINAL 
F1347524_Examen_Final

Francisco Voogd

---------------------------------------------------------------------------------------------------
Compilar sin incluir librerias con : 
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb --specs=nosys.specs -T stm32f103c8tx_flash.ld startup_stm32f103c8tx.s main.c  -o main.elf

Compilar al incluir las librerias con :
rm-none-eabi-gcc -mcpu=cortex-m3 -mthumb --specs=nosys.specs -T stm32f103c8tx_flash.ld startup_stm32f103c8tx.s main.c ./serialUart/serialUart.c ./motorDriver/motorDriver.c  -o main.elf
