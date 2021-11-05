#include <stdio.h>

int main(int argc, char **argv) {
    float ancho;
    printf("Digite el valor del ancho del bus: ");
    scanf("%f", &ancho);
    
    float bpc;
    printf("Digite el numero de bits por ciclo: ");
    scanf("%f", &bpc);
    
    float frec;
    printf("Digite la frecuencia en MHz: ");
    scanf("%f", &frec);
    
    float velocidad = (ancho * bpc * frec)/8; 
    
    printf("La velocidad de transferencia es %.1f", velocidad);
    printf(" MB/s");
    
    return 0;
}
