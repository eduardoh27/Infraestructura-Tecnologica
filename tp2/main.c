#include <stdio.h>

int main() {
    float ancho;
    printf("Digite el valor del ancho: ");
    scanf("%f", &ancho);
    
    float dpc;
    printf("Digite el número de datos por ciclo: ");
    scanf("%f", &dpc);
    
    float frec;
    printf("Digite la frecuencia vibracional: ");
    scanf("%f", &frec);
    
    float v = ancho * dpc * frec ;
    
    printf("La velocidad de transferencia es %.1f",v);
    
    return 0;
}