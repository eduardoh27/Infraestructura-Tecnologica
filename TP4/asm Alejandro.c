/* Codigo que crea un vector con un tamaño el cual se indica y con valores que igualmente se indican. 
Alejandro Salgado
201923134
a.salgadom@un*/


#include <stdio.h>

void procedimientoCalculo (int, int*);

int main () {

    //Aca se inicializan las variables de tamaño y el apuntador del vector
    unsigned int tamanioVector, n;
    unsigned int *vector;

    //Pide el tamaño del vector
    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &tamanioVector);

    //Verifica que tenga un tamaño valido, en el caso de que no se sale del programa
    if (tamanioVector<=0)
    {
        printf("Tamanio no valido");
        exit (1);
    } 

    //Inicializacion del vector con el tamaño asignado
    vector = (unsigned int*)calloc(tamanioVector, sizeof(int));

    //Pide los valores a ingresar, esto de acuerdo al tamaño asignado
    for (n=0;n<tamanioVector;n++)
    {
        printf ("Ingrese el entero #%d: ", n + 1);
        scanf ("%d",&vector[n]);
    }

    printf("\n");

    //Invoca el metodo que devuelve los valores en hexa, ingresa como parametro el tamaño y el apuntador
    procedimientoCalculo(tamanioVector, vector);

    return 0;

}


void procedimientoCalculo (int tamanioVector, int *vector) {

    //Formatos de salida para el print. Estos son preestablecidos 
    char *saltoLinea = "\n";
    char *formVector = "v[%i] = ";
    char *hexa = "0x%c%c ";
    char *hola = "hola \n";
    char *entero = "%i \n";
    
    int posVector;
    int j;
    char hexnum[8];
    int j2;
    
    __asm{
        
        //Variable que guarda la posicion de valores ingresados al vector int i=0
        mov ebx, 0 
        
        //Recorrido for(int i=0; i<size; i++)
        forVector:
        
        //Comparacion i<size. 
        cmp ebx, tamanioVector 
        jge finForVector    
                
            //char hexnum[8]; Se inicializa por afuera
                
            //Variable que guarda el numero de bits del numero guardado j=0
            mov ecx, 0 
                
            //Recorrido for(int j=0; j<8; j++)
            forNumero: 
            
            //Comparacion j<8. 
            cmp ecx, 8
            jge finForNumero
            
                mov j2, ecx
                /int hexunit = ((a[i] >> (j*4)) & 15)/
                //a[i]
                mov esi, vector[ebx]

                mov edi, 0


                
                forCorrimiento:
                
                cmp edi, ecx
                jge finForCorrimiento

                    SHR esi, 4
                    inc edi
                    jmp forCorrimiento

                finForCorrimiento: 

                mov edx, 15
                AND esi, edx 
            
                //hexnum[7-j] = hexaConversor(hexunit);
                
                //hexaConversor(hexunit)
                //Comparador if(numb>=10)
                cmp esi, 10
                jge cambioLetra
                
                    cmp esi, 1
                    je dos
                    
                        mov ax, '1'
                        jmp fin
                        
                    dos:

                    cmp esi, 2
                    je tres
                    
                        mov ax, '2'
                        jmp fin
                        
                    tres:

                    cmp esi, 3 
                    je cuatro
                    
                        mov ax, '3'
                        jmp fin
                        
                    cuatro:

                    cmp esi, 4
                    je cinco
                    
                        mov ax, '4'
                        jmp fin
                        
                    cinco:

                    cmp esi, 5
                    je seis
                    
                        mov ax, '5'
                        jmp fin
                        
                    seis:

                    cmp esi, 6
                    je siete
                    
                        mov ax, '6'
                        jmp fin
                        
                    siete:

                    cmp esi, 7
                    je ocho
                    
                        mov ax, '7'
                        jmp fin
                        
                    ocho:

                    cmp esi, 8
                    je nueve
                    
                        mov ax, '8'
                        jmp fin
                        
                    nueve:

                    cmp esi, 9
                    je fin
                    
                        mov ax, '9'
                        jmp fin
                
                cambioLetra:
                
                    cmp esi, 10 
                    je once
                    
                        mov ax, 'A'
                        jmp fin
                        
                    once:
                    
                    cmp esi, 11 
                    je doce
                    
                        mov ax, 'B'
                        jmp fin
                        
                    doce:
                    
                    cmp esi, 12 
                    je trece
                    
                        mov ax, 'C'
                        jmp fin
                        
                    trece:
                    
                    cmp esi, 13 
                    je catorce
                    
                        mov ax, 'D'
                        jmp fin
                        
                    catorce:
                    
                    cmp esi, 14 
                    je quince
                    
                        mov ax, 'E'
                        jmp fin

                    quince:
                    
                    cmp esi, 15 
                    je dieciseis 
                    
                        mov ax, 'F'
                        jmp fin
                        
                    dieciseis:
                    
                    cmp esi, 16
                    je fin  
                    
                        mov ax, 'G'
                        jmp fin
                    
                    fin:
                    
                    mov j, ecx 
                    mov ecx, 7
                    sub ecx, j 
                    mov hexnum[ecx], al
                    mov ecx, j
                

                mov ecx, j2
                inc ecx
                jmp forNumero

            finForNumero:
                
            
            //printf("v[%d] = ", i);
            mov posVector, ebx
            push ebx
            push formVector
            call printf
            add esp, 8
            mov ebx, posVector


            //Variable que guarda la posicion de valores en caracter del numero j=0
            mov ecx, 0 
        
            //for(int j=0; j<8; j+=2)
            forPrint: 
        
            //Comparacion j<8. 
            cmp ecx, 8
            jge finForPrint
        
                mov j2, ecx

                /printf("0x%c%c", hexnum[j], hexnum[j+1]);/
                mov al, 0 
                mov edi, 'A'
                mov esi, 'B'
                push edi
                push esi
                push hexa
                call printf
                add esp, 12

                //j+=2
                mov ecx, j2
                add ecx, 2
                jmp forPrint 


            finForPrint:
          

            inc ebx
            jmp forVector


        finForVector: 
        
        
        
    }



}