#include <stdio.h>
#include <stdlib.h>

//NOMBRE: Eduardo José Herrera Alba
//CODIGO: 201912865
//CORREO: ej.herreraa@uniandes.edu.co

#define FILE_SIZE ( sizeof( datos.nombres ) + sizeof( datos.apellidos ) + sizeof( datos.cedula ) \
                    + sizeof( datos.codigo ) + sizeof( datos.nota ) + sizeof( datos.tresMilANacimiento ) )

//TO DO: Declare el tipo y tama�o adecuados para que las variables puedan contener 
//el correspondiente valor del archivo de entrada
// NO MODIFIQUE NINGUNA OTRA COSA EN EL PROGRAMA
// Estructura para manejar los datos de entrada.
struct Datos {
   char nombres[43];
   char apellidos[43];
   char cedula[13];
   int codigo;
   char nota;
   short tresMilANacimiento;
} datos;

unsigned int getFileSize ( FILE * );
unsigned int loadData ( struct Datos *, char * );
unsigned int getNumber ( FILE *, char *, unsigned int );
void printChrs ( char *, unsigned int );

int main( int argc, char *argv[] )
{

   if ( argc != 2 ){
      printf( "*** ATENCION! Uso del comando:\n\tbinario archivo-de-datos\n" );
      return 1;
   }

   if ( loadData( &datos, argv[1] ) != FILE_SIZE ) return 1;

   printf( "Nombres:" );
   printChrs( datos.nombres, sizeof( datos.nombres ) );
   printf( "\n" );
   printf( "Apellidos:" );
   printChrs( datos.apellidos, sizeof( datos.apellidos ) );
   printf( "\n" );
   printf( "Cedula:" );
   printChrs( datos.cedula, sizeof( datos.cedula ) );
   printf( "\n" );
   printf( "Codigo:%u\n", datos.codigo );
   printf( "Nota:%u\n", datos.nota );
   printf( "Diferencia a 3000:%d\n", datos.tresMilANacimiento);

   return 0;
} // main

/**
 * Calcula la longitud en bytes de un archivo.
 * Pre   El archivo esta abierto.
 * Parametros  f Apuntador al descriptor del archivo.
 * Retorna  la longitud en bytes del archivo apuntado por f.
 */
unsigned int getFileSize ( FILE * f ){

   unsigned int longArchivo;

   if ( fseek( f, 0, SEEK_END ) || ( longArchivo = ftell( f ) ) < 0 || fseek( f, 0, SEEK_SET ) ) {
      longArchivo = 0;
   }

  return longArchivo;
} // getFileSize

/**
 * Lee del archivo un n�mero binario de l bytes en la variable apuntada por p.
 * El n�mero se supone en formato big endian y lo convierte a little endian.
 */
unsigned int getNumber ( FILE * f, char * p, unsigned int l ){

   int i;

   p = p + l - 1;
   for ( i = 0; i < l && ( fread( p-i, sizeof( char ), 1, f ) == sizeof( char ) ); i++ );

   return i;
} // getNumber

/**
 * Inicializa una estructura con los datos del archivo.
 * Abre el archivo de datos, lo carga en memoria y los guarda en una estructura de datos.
 */
unsigned int loadData ( struct Datos * datosP, char * nombreArchivo ){

   FILE * f = NULL;
   unsigned int longFisica = 0;
   unsigned int nBytes;

   if ( !( f = fopen( nombreArchivo, "rb" ) ) ) {
      printf( "*** ATENCION! No se logro abrir el archivo %s\n", nombreArchivo );
   }
   else if ( getFileSize( f ) != FILE_SIZE ){
         printf( "*** ATENCION! Tamanio del archivo %s no concuerda\n", nombreArchivo );
   }
   else {
      nBytes = sizeof( datosP->nombres );
      if ( fread( datosP->nombres, sizeof( char ), nBytes, f ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer los nombres del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      longFisica += sizeof( datosP->nombres );
      nBytes = sizeof( datosP->apellidos );
      if ( fread( datosP->apellidos, sizeof( char ), nBytes, f ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer los apellidos del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      nBytes = sizeof( datosP->cedula );
      longFisica += sizeof( datosP->apellidos );
      if ( fread( datosP->cedula, sizeof( char ), nBytes, f ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer la cedula del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      nBytes = sizeof( datosP->codigo );
      longFisica += sizeof( datosP->cedula );
      if ( getNumber( f, (char *)(&datosP->codigo), nBytes ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer el codigo del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      nBytes = sizeof( datosP->nota );
      longFisica += sizeof( datosP->codigo );
      if ( fread( &datosP->nota, sizeof( char ), nBytes, f ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer la nota del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      nBytes = sizeof( datosP->tresMilANacimiento );
      longFisica += sizeof( datosP->nota );
      if ( getNumber( f, (char *)(&datosP->tresMilANacimiento), nBytes ) != nBytes ) {
         printf( "*** ATENCION! No se pudo leer la diferencia al 3000 del archivo %s\n", nombreArchivo );
         return longFisica;
      }
      longFisica += sizeof( datosP->tresMilANacimiento );
   }

   fclose( f );

   return longFisica;
} // loadData

/**
 * Imprime l caracteres a partir del caracter apuntado por p.
 */
void printChrs ( char * p, unsigned int l ){

   int i;

   for ( i = 0; i < l; i++ ){
      printf( "%c", p[i] );
   }

} // printChrs

