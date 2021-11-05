#include <stdio.h>

/*
Trabajo practico 3 - Infraestructura Tecnologica
Nombre: Eduardo Jose Herrera Alba
Codigo: 201912865
Correo: ej.herreraa@uniandes.edu.co
*/

char getHexa(char nibble);

int empaquetamiento(int * vector, int n) {
    /*
    Recorre el vector de numeros e imprime en consola los valores en hexa de cada entero
    */

    signed int cadaNumero;
    for (int i = 0; i < n; i++){
        /*
        Obtiene cada entero del vector de números
        */

        printf("v[%i] = ",i);
        printf("\t");

        cadaNumero = vector[i];

        for (int j = 3; j >= 0; j--){
            /*
            Descompone el int en sus cuatro bytes
            */

            char cadaByte = cadaNumero >> (8*j);

            // Se descompone el byte en los primeros cuatro y los últimos cuatro bits 
            char firstNibble = cadaByte >> 4; 
            char lastNibble = cadaByte & 0x0F;

            // Se obtiene los dos valores Hexa para el entero
            char leftHexa = getHexa(firstNibble);
            char rightHexa = getHexa(lastNibble);

            // Se imprimen los valores en el formato requerido
            printf("0x");
            printf("%c",leftHexa);
            printf("%c",rightHexa);
            printf("\t");
        }

        printf("\n");
    }

    return 0;
}

char getHexa(char nibble){
    /*
    Recibe un caracter que almacena un nibble y traduce su valor a hexadecimal
    */
   
    signed int valorDecimal = (int) nibble; 
    char valorHexa;
    if (valorDecimal == 0 || valorDecimal == -16)
        valorHexa = '0';
    else if (valorDecimal == 1 || valorDecimal == -15)
        valorHexa = '1';
    else if (valorDecimal == 2 || valorDecimal == -14)
        valorHexa = '2';
    else if (valorDecimal == 3 || valorDecimal == -13)
        valorHexa = '3'; 
    else if (valorDecimal == 4 || valorDecimal == -12)
        valorHexa = '4'; 
    else if (valorDecimal == 5 || valorDecimal == -11)
        valorHexa = '5'; 
    else if (valorDecimal == 6 || valorDecimal == -10)
        valorHexa = '6'; 
    else if (valorDecimal == 7 || valorDecimal == -9)
        valorHexa = '7'; 
    else if (valorDecimal == 8 || valorDecimal == -8)
        valorHexa = '8'; 
    else if (valorDecimal == 9 || valorDecimal == -7)
        valorHexa = '9'; 
    else if (valorDecimal == 10 || valorDecimal == -6)
        valorHexa = 'A'; 
    else if (valorDecimal == 11 || valorDecimal == -5)
        valorHexa = 'B'; 
    else if (valorDecimal == 12 || valorDecimal == -4)
        valorHexa = 'C';
    else if (valorDecimal == 13 || valorDecimal == -3) 
        valorHexa = 'D';
    else if (valorDecimal == 14 || valorDecimal == -2) 
        valorHexa = 'E';
    else if (valorDecimal == 15 || valorDecimal == -1)
        valorHexa = 'F';

    return valorHexa;
}

int main(int argc, char **argv) {

    // Input tamanio de vector
    unsigned int n = 0;
    do {
        printf("Ingrese el tamanio del vector: ");
        scanf("%i", &n);
    } while (n <= 0);

    // Declara apuntador 
    signed int * vector_dinamico;
    vector_dinamico = (int *)calloc(n,sizeof(int));

    // Input elementos del vector
    unsigned int posicion = 0;
    for (int i = 0; i < n; i++){
        printf("Ingrese el elemento %i del vector: ",i);
        scanf("%i", &posicion);
        vector_dinamico[i] = posicion;
    }

    // Llamado a funcion de impresion
    empaquetamiento(vector_dinamico, n);

    return 0;
}