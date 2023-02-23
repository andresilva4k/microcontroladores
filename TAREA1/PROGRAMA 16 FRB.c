#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP, HS

//Directiva para utilizar puerto USART
#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)

#use STANDARD_IO(B)

// Se define el array con todas las combinaciones del display
int8 numeros[] = {
   //-gfedcba
   0b00111111, // 0
   0b00000110, // 1
   0b01011011, // 2
   0b01001111
};


void main()
{
   setup_uart(9600); //Configurar baudios
   // Inicializar pines
   output_b(0);
   
   while (1)
    {
      // Recorrer vector numeros
      for(int8 i = 0; i < sizeof(numeros); i++)
      {
         output_b(numeros[i]); // Colocar el número en el puerto B
         delay_ms(500); // Esperar
      }
    }
}

