/* TP5
En este caso se implementa por medio de corrimientos de ebp, las variables las manejamos como parametros.
Codigo que crea un vector con un tamaño el cual se indica y con valores que igualmente se indican. 
Al final del codigo se encuentra documentado lo que se uso como guia, este fue el codigo de Ana Sofía Padilla Daza - 202021748, integrante de nuestro grupo
Alejandro Salgado Manrique - 201923134
a.salgadom@uniandes.edu.co
Ana Sofía Padilla Daza - 202021748
a.padillad@uniandes.edu.co
Eduardo José Herrera Alba - 201912865
ej.herreraa@uniandes.edu.co
*/


#include <stdio.h>

void empaquetamiento (int, int*, char*, char*, char*, int, int, int, char*);

char hexnum[8];
    
int main(){    

    int tamanio, i;
    int *a;
    
    printf("Indique el tamanio del vector: ");
    scanf("%d", &tamanio);

    a = (int*) calloc (tamanio, sizeof(int));

    if (tamanio > 0) {
         for (i=0; i<tamanio; ++i) {
             printf("Indique el elemento: ");
             scanf("%d", &a[i]);
         }

    }
    else {
        printf("Escribio un valor no válido");
    }

    //Formatos de salida para el print. Estos son preestablecidos 
    char *saltoLinea = "\n";
    char *formVector = "v[%i] = ";
    char *hexa = "0x%c%c ";
    
    //Usamos estas variables para guardar los valores de algunos registros cuando los usamos y se modifican a lo largo del proceso
    int posVector;
    int j;
    int j2;

    //Vector que guarda los valores en hexa de los numeros (En el codigo dentro de un for, sin embargo toco crear el vector por afuera y se modifica por adentro)
    char *pHexnum = &hexnum;



    //empaquetamiento(size, a); LLamado a la funcion empaquetamiento
    __asm{

        //Push del apuntador de hexnum
        push pHexnum
        //Push de j2
        push j2
        //Push de j
        push j
        //Push de la posicion del vector 
        push posVector
        //Push del formato del numero en hexa
        push hexa
        //Push del formato del vector
        push formVector
        //Push del formato de salto de linea
        push saltoLinea
        //Push del parametro a
        push a
        //Push del parametro size
        push tamanio
        //Llamado de la funcion empaquetamiento
        call empaquetamiento

    }



    return 0;

}


void empaquetamiento (int tamanio, int *a, char *saltoLinea, char *formVector, char *hexa, int posVector, int j, int j2, char *pHexnum) {

    /*
    Tamanio es ebp+8
    a es ebp+12
    saltoLinea es ebp+16
    formVector es ebp+20
    hexa es ebp+24
    posVector es ebp+28
    j es ebp+32
    j2 es ebp+36
    pHexnum es ebp+40
    */


    __asm{

        //Variable que guarda la posicion de valores ingresados al vector int i=0
        mov ebx, 0 
        
        //Recorrido for(int i=0; i<size; i++)
        forVector:
        
        //Comparacion i<size. 
        cmp ebx, [ebp+8]
        jge finForVector    
                
            //char hexnum[8]; Se inicializa por afuera
                
            //Variable que guarda el numero de valores hexa que vamos obtener del numero guardado j=0
            mov ecx, 0 
                
            //Recorrido for(int j=0; j<8; j++)
            forNumero: 
            
            //Comparacion j<8. 
            cmp ecx, 8
            jge finForNumero
            
                //Guarda variable por si se modifica ecx
                //mov j2, ecx
                mov [ebp+36], ecx

                /*int hexunit = ((a[i] >> (j*4)) & 15)*/

                //a[i]
                //Aca ponemos el vector dentro de edi y luego accedemos a cada uno de los enteros al llamar al contenido del registro sumandole el valor de ebx*4,
                //esto con el fin de obtener el entero en cada posicion (cada 4 posiciones)
                mov edi, [ebp+12]
                mov esi, [edi+ebx*4]

                //Inicializacion para el recorrido del corrimiento
                mov edi, 0

                //(a[i] >> (j*4)). Toca hacer un recorrido ya que no se puede hacer un corrimiento con 2 registros, sino que el segundo operando debe ser un numero
                //Como funciona es que dependiendo de la posicion hexa se desea encontrar se va a hacer el corrimiento hasta llegar a esta. 
                forCorrimiento:
                
                //Comparacion valor recorrido con la posicion j
                cmp edi, ecx
                jge finForCorrimiento

                    //Hace el corrimiento logico a la derecha
                    SHR esi, 4

                
                    inc edi
                    jmp forCorrimiento

                finForCorrimiento: 

                //Hace un and logico & 15
                AND esi, 15

            
                //hexnum[7-j] = hexaConversor(hexunit);
                
                //hexaConversor(hexunit)
                //Comparador if(numb>=10)
                //En este paso hacemos el hexaconversor. En el codigo original estaba en una funcion aparte. Sin embargo, por temas de agilidad y organizacion 
                //prefirimos hacerlo directamente en empaquetamiento. En esta parte se compara el valor guardado en esi (hexunit) con los numeros de 0 al 16, y 
                //devuelve el valor ASCII correspondiente
                cmp esi, 10
                jge cambioLetra

                    cmp esi, 0
                    jne uno
                    
                        mov al, '0'
                        jmp fin
                        
                    uno:

                    cmp esi, 1
                    jne dos
                    
                        mov al, '1'
                        jmp fin
                        
                    dos:

                    cmp esi, 2
                    jne tres
                    
                        mov al, '2'
                        jmp fin
                        
                    tres:

                    cmp esi, 3 
                    jne cuatro
                    
                        mov al, '3'
                        jmp fin
                        
                    cuatro:

                    cmp esi, 4
                    jne cinco
                    
                        mov al, '4'
                        jmp fin
                        
                    cinco:

                    cmp esi, 5
                    jne seis
                    
                        mov al, '5'
                        jmp fin
                        
                    seis:

                    cmp esi, 6
                    jne siete
                    
                        mov al, '6'
                        jmp fin
                        
                    siete:

                    cmp esi, 7
                    jne ocho
                    
                        mov al, '7'
                        jmp fin
                        
                    ocho:

                    cmp esi, 8
                    jne nueve
                    
                        mov al, '8'
                        jmp fin
                        
                    nueve:

                    cmp esi, 9
                    jne fin
                    
                        mov al, '9'
                        jmp fin
                
                cambioLetra:
                
                    cmp esi, 10 
                    jne once
                    
                        mov al, 'A'
                        jmp fin
                        
                    once:
                    
                    cmp esi, 11 
                    jne doce
                    
                        mov al, 'B'
                        jmp fin
                        
                    doce:
                    
                    cmp esi, 12 
                    jne trece
                    
                        mov al, 'C'
                        jmp fin
                        
                    trece:
                    
                    cmp esi, 13 
                    jne catorce
                    
                        mov al, 'D'
                        jmp fin
                        
                    catorce:
                    
                    cmp esi, 14 
                    jne quince
                    
                        mov al, 'E'
                        jmp fin

                    quince:
                    
                    cmp esi, 15 
                    jne dieciseis 
                    
                        mov al, 'F'
                        jmp fin
                        
                    dieciseis:
                    
                    cmp esi, 16
                    jne fin  
                    
                        mov al, 'G'
                        jmp fin
                    
                    fin:
                    
                    //Esto lo hacemos para hacer el hexnum[7-j], donde ecx es 7-j
                    //mov j, ecx
                    mov [ebp+32], ecx 
                    mov ecx, 7
                    //sub ecx, j
                    sub ecx, [ebp+32]

                    //hexnum[7-j] = hexaConversor(hexunit)
                    //mov hexnum[ecx], al 
                    mov edx, [ebp+40]
                    mov [edx+ecx], al 
                
                //Aca devuelve el valor del for original a ecx, leugo suma su valor y repite el proceso del for
                mov ecx, [ebp+36]
                inc ecx
                jmp forNumero

            finForNumero:
                
            
            mov edi, edx

            
            
            
            //printf("v[%d] = ", i);
            mov [ebp+28], ebx
            push ebx
            push [ebp+20]
            call printf
            add esp, 8
            mov ebx, [ebp+28]

                
            
            //Variable que guarda la posicion de valores en caracter del numero j=0
            mov ecx, 0 
        
            //for(int j=0; j<8; j+=2)
            forPrint: 
        
            //Comparacion j<8. 
            cmp ecx, 8
            jge finForPrint
        
                mov [ebp+36], ecx

                /*printf("0x%c%c", hexnum[j], hexnum[j+1]);*/
                mov al, 0 

                //movzx edi, hexnum[ecx]
                //movzx esi, hexnum[ecx+1]
                //En esta parte del codigo hacemos el push de los valores 
                //de hexnum
                push [edi+ecx+1]
                push [edi+ecx]
                push [ebp+24]
                call printf
                add esp, 12


                //j+=2
                mov ecx, [ebp+36]
                add ecx, 2
                jmp forPrint 


            finForPrint:
          

            //Salto de linea 
            push [ebp+16]
            call printf 
            add esp, 4

            inc ebx
            jmp forVector


        finForVector: 
        
    }



}