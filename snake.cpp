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
#include <stdio_ext.h>
#include <unistd.h>

#define MAX 25
#define N 10

struct TAnillo{
    int x;
    int y;

};

void pintadoPresentacion(){

    system("clear");
    system("cat ./presentacion.txt");

}

void pintadoTablero(){

    // system("cat ./pantalla.txt"); 
    system("clear");

    char tablero[MAX][MAX];
    FILE *fp;
    int i = 0;

    if ((fp = fopen ("pantalla.txt", "r")) == NULL) {
	fprintf (stderr, "Error al abrir el archivo %s\n", "pantalla.txt");
	exit(EXIT_FAILURE);
    }

/*	while (!feof(fp)) {
	    fscanf(fp, "%s", tablero[i]);
	    i++;
	}
 */
    for(int fila = 0; fila < MAX ; fila++){
	fgets(tablero[fila], MAX+1, fp);
	//	fflush(stdin);
    }
    /*  for(int fila=0; fila<MAX; fila++)
	for(int col=0; col<MAX; col++){
	fscanf(fp, "%c", &tablero[fila][col]);
	}
     */
    fclose(fp); 

    for(int fila = 0; fila < MAX; fila++)
	printf("%s", tablero[fila]);

    printf("\n");

} 

void mover(){

    /*
Entrada: -
Salida : -

Descipción: Lazo (bucle de control) se encarga de avanzar el juego
paso a paso.

PROCEDIMIENTO
VARIABLES
     */

    bool serpienteViva = true;

    /*
       FIN VARIABLES

ALGORITMO:
     */
    do{
	/*
	 */
	/*
	   1. Cambiar la dirección de avance de la serpiente según la tecla pulsada.
	   2. Borrar el exceso de pulsaciones leyendo caracteres hasta que se
	   vacíe el buffer.

	   Si la siguiente posición de la serpiente es distinto de la ' ' (gettext):
	   Si la siguiente posición es una fruta:
	   1. Incrementar la variable de la serpiente crecerCola en tantas
	   posiciones como indique la fruta (incrementando las posiciones
	   que le quedan por crecer).
	   2. Incremetar los puntos del usuario tanto como indique la fruta.
	   3. Poner a 0 el tiempo hasta la siguiente fruta (opcional).
	   4. Incrementar la velocidad por cada decena de frutas comidas.
	   Si no:
	   1. El usuario se ha chocado y debe morir (cambiando su variable de
	   estado);

	   Fin Si
	   Fin Si.

	   Si las posiciones que le quedan por crecer > 0 :
	   1. Incrementar la cola en 1 anillo.
	   2. decrementar en 1 las posiciones que le quedan por crecer.

	   Decrementar en 1 el tiempo hasta la siguiente fruta.
	   Si el tiempo hasta la siguiente Fruta <= 0 :
	   1. Generar un tipo de fruta aleatoriamente.
	   2. Generar aleatoriamente el tiempo hasta la siguiente fruta.

	   avanzar la serpiente.
	   Incrementar en 1 los puntos del usuario (1 definido como constante PUNTOS).
	   pintar la serpiente.
	 */
    }while(serpienteViva = true);
    /*
       FIN ALGORITMO.
       FIN PROCEDIMIENTO.
     */



}


int main(void){

    char opcion;
    struct TAnillo serpiente[N];

    pintadoPresentacion();
    sleep(1);
    getchar();

    do{
	pintadoTablero();
	// Poner a 0 todas las variables, para comenzar una nueva partida.
	mover();
	// Felicitar al jugador y enseñarles los puntos conseguidos.
	printf("¿Jugar otra partida? s/n ");
	__fpurge(stdin);
	scanf(" %c", &opcion);
    }while(opcion != 'n');

    // Poner los créditos del juego.
    return EXIT_SUCCESS;
}
