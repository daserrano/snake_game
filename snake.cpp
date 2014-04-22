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
#include <ncurses.h>
#include <ctype.h>

#define MAX 25
#define N 10

struct TCoordenada{
    double x; 
    double y;
};

struct TAnillo{
    double x;
    double y;

};

void rellenar_serpiente(struct TAnillo coordenada[N]){

    for(int i=0; i<N; i++){
	coordenada[i].x = 10 + i;
	coordenada[i].y = 10;
    }

}

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

void muestra(struct TAnillo coordenada[N]){
    clear();
    for(int i=0; i<N; i++)
	mvprintw(coordenada[i].y, coordenada[i].x, "*");
    refresh();

}

void mover(struct TCoordenada incremento, struct TAnillo coordenada[N]){
    
    for(int i=N-1; i>0; i--){
	coordenada[i].x = coordenada[i-1].x;
	coordenada[i].y = coordenada[i-1].y;
    }
    coordenada[0].x += incremento.x;
    coordenada[0].y += incremento.y;

}

int main(int argc, char *argv[]){

    char opcion;
    struct TAnillo serpiente[N];
    struct TCoordenada movimiento = {0, -1};
    int user_input;

    pintadoPresentacion();
    sleep(1);
    getchar();

    rellenar_serpiente(serpiente);

    initscr();   //Crear una matriz para pintar.
    halfdelay(3);  //Hace que getch espere 3 decimas de segundo (para mover sola la serpiente).
    keypad(stdscr, TRUE); //Para poder leer las flechas.
    noecho();  // Para que no se vea el caracter pulsado.
    curs_set(0); //No se ve el cursor.
    
    do{
	while(1){
//	pintadoTablero();
	    user_input = getch();
	    switch(tolower(user_input)){
		case 'w':
		case KEY_UP:
		    movimiento.x = 0;
		    movimiento.y = -1;
		    break;
		case 's':
		case KEY_DOWN:
		    movimiento.x = 0;
		    movimiento.y = 1;
		    break;
		case 'a':
		case KEY_LEFT:
		    movimiento.x = -1;
		    movimiento.y = 0;
		    break;
		case 'd':
		case KEY_RIGHT:
		    movimiento.x = 1;
		    movimiento.y = 0;
		    break;
	    }
	    mover(movimiento, serpiente);
	    muestra(serpiente);

	}
	printf("¿Jugar otra partida? s/n ");
	__fpurge(stdin);
	scanf(" %c", &opcion);
    }while(opcion != 'n');

    // Poner los créditos del juego.
    getchar();
    endwin();   //Libera la matriz.
    return EXIT_SUCCESS;
}
