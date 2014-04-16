
/*
            *******************************
				*	EL JUEGO DE LA SERPIENTE	*
            *******************************

	Desarrollar el juego de la serpiente conforme a las
   especificaciones siguientes:

   	1. Un diagrama completo de las funciones que se van a presentar.
      2. Código fuente necesario para que el juego funcione (.cpp + .ide).
      3. Fichero ejecutable, libre de virus del juego.

   Tiempo mínimo estimado para su realización:	3 horas 30 minutos.
   Tiempo máximo estimado para su realización:  12 a 20 horas.
	Fecha última de entrega: 30 de Marzo a las 12:00 h
*/

/*		DATOS

		Estructura cuerpo. -> 	Coordenada x
      								Coordenada y
                              Puntero al anillo anterior del cuerpo.

      La primera parte del cuerpo tendrá el puntero con valor NULL. La
      última se pintará con un espacio en blanco.

      Estructura de una serpiente -> 	Avance X.
                                       Avance Y.
                                       posiciones por crecer.
                                       Numero de frutas comidas.
                                       puntos del jugador.
      											Puntero a la cola.

      El avance es una variable de tipo enum que puede valer -1,0,1

      Estructura Fruta -> 	Caracter con el que va a ser pintada la fruta.
      							Número de posiciones que se tiene que incrementar
                           la cola.
                           Número de puntos que da comerse esa fruta.

		TSerpiente 	serpiente;
      TFruta      fruta[]  = {	{0x57, 6, 2},
      									{'b', ..., ...},
                                 .
                                 .
      										};

		ENTERO SIN SIGNO tiempoHastaLaSiguienteFruta = 0;

      CARÁCTER Volante[2] -> {Carácter para girar la serpiente a su izquierda,
      							  Carácter para girar a la derecha}

		FINDATOS
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 25

enum TOpcion{inicio, puntuacion, salir};

void pintadoPresentacion(){

    system("clear");
    system("cat ./presentacion.txt");

}


void pintadoTablero(){

   // system("cat ./pantalla.txt"); 

    char s[MAX][MAX];
    FILE *fp;

    if ((fp = fopen ("pantalla.txt", "r")) == NULL) {
	fprintf (stderr, "Error al abrir el archivo %s\n", "pantalla.txt");
	exit(EXIT_FAILURE);
    }
    for(int fila = 0; fila < MAX; fila++)
	for(int columna = 0; columna < MAX; columna++){
	    fscanf(fp, " %c[^\n]", &s[fila][columna]); 
	    s[10][10] = 'T';

	}
       //fgets(s[fila], MAX, fp);
    

    
  fclose(fp); 

     for(int fila = 0; fila < MAX; fila++){
	for(int columna = 0; columna < MAX; columna++)
	    printf("%c", s[fila][columna]);

	printf("\n");
     }

     printf("\n");

	    
	    
	/*    for (int i = 0; fgets (s, MAX, fp) != NULL; i++)
	if (i > 31) {
	    printf ("Error!!! mas de 9 lineas\n");
	    break;
	}*/


}

int main(){

    enum TOpcion opcion;

    pintadoPresentacion();
    sleep(3);


 //   do{
	pintadoTablero();
	// Poner a 0 todas las variables, para comenzar una nueva partida.
	// Mover
	// Felicitar al jugador y enseñarles los puntos conseguidos.
   // }while(opcion != salir);

    // Poner los créditos del juego.
    return EXIT_SUCCESS;
}
