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
#include <time.h>

#define MAXLINES 25
#define MAXCOLS  50
#define L0 4  /*  Longitud inicial */
#define ESC 27   
#define ESP 32
                 
struct TCoordenada{
    double x;    
    double y;    
};               
                 
struct TAnillo{  
    double x;    
    double y;    
                 
};                
                 
typedef struct TSerpiente{ 
    struct TAnillo anillo[L0];
    int longitud ;
                 
} Serpiente;                      // Typedef struct TSerpiente Serpiente -> sirve para darle un alias(Serpiente) a la struct TSerpiente. 
                 
void rellenar_serpiente(Serpiente *serpiente){

    for(int i=0; i<serpiente->longitud; i++){
	serpiente->anillo[i].x = 10 + i;
	serpiente->anillo[i].y = 10;
    }

}

void pintadoPresentacion(){

   // system("clear");
   // system("cat ./presentacion.txt");

    FILE *fp;

    if ((fp = fopen ("presentacion.txt", "r")) == NULL) {
	fprintf (stderr, "Error al abrir el archivo %s\n", "presentacion.txt");
	exit(EXIT_FAILURE);
    }

    //attron(COLOR_PAIR(5));
    char pixel;
    int line = 0;
    while( (pixel = fgetc(fp)) != EOF) {
	printw("%c", pixel);
	line++;
	if(line >= 97 && line <= 143 || line >= 168 && line <= 225 || line >= 250 && line <= 305 || line >= 333 && line <= 389
		|| line >= 408 && line <= 466 || line >= 499 && line <= 540 || line >= 572 && line <= 629 || line >= 651 && line <= 710)
	    attron(COLOR_PAIR(2));
	else
	    attron(COLOR_PAIR(5));
    }
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(5));
    fclose(fp);
} 

void pintadoTablero(){

    // system("cat ./pantalla.txt"); 
    system("clear");

    char tablero[MAXLINES];
    FILE *fp;

    if ((fp = fopen ("pantalla.txt", "r")) == NULL) {
	fprintf (stderr, "Error al abrir el archivo %s\n", "pantalla.txt");
	exit(EXIT_FAILURE);
    }

    char pixel;
    while( (pixel = fgetc(fp)) != EOF) {
	printw("%c", pixel);
    }

    refresh();
    fclose(fp); 

    /*for(int fila = 0; fila < MAX; fila++)
      printf("%s", tablero);

      printf("\n");
     */
}  

void muestra(Serpiente *serpiente, int color){
    clear();
    pintadoTablero();

    attron(COLOR_PAIR(color));
    for(int i=0; i<L0; i++)
	mvprintw(serpiente->anillo[i].y, serpiente->anillo[i].x, "*");

    attroff(COLOR_PAIR(color));
    refresh();

}

void mover(struct TCoordenada incremento, Serpiente *serpiente){

    for(int i=L0-1; i>0; i--){
	serpiente->anillo[i].x = serpiente->anillo[i-1].x;
	serpiente->anillo[i].y = serpiente->anillo[i-1].y;
    }
    serpiente->anillo[0].x += incremento.x;
    serpiente->anillo[0].y += incremento.y;

} 

int main(int argc, char *argv[]){

    char opcion;
    Serpiente serpiente;                       //Se pone Serpiente por el alias creado antes.
    serpiente.longitud = L0;
    struct TCoordenada movimiento = {0, 1};
    int user_input,
	color = 0;

    rellenar_serpiente(&serpiente);

    initscr();   //Crear una matriz para pintar.
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

    srand(time(NULL));

    halfdelay(3);  //Hace que getch espere 3 decimas de segundo (para mover sola la serpiente).
    keypad(stdscr, TRUE); //Para poder leer las flechas.
    noecho();  // Para que no se vea el caracter pulsado.
    curs_set(0); //No se ve el cursor.

    color = (rand() % 5) + 1;

    pintadoPresentacion();
    while((user_input = getch()) != ESP){
    }

    do{
	while((user_input = getch()) != ESC){
	    switch(tolower(user_input)){   //Tolower = indiferencia sobre mayusculas y minusculas.
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
	    mover(movimiento, &serpiente);
	    muestra(&serpiente, color);

	}
	clear();
	mvprintw(LINES/4, COLS/2.5, "¿ Quieres salir ? s/n ");
	__fpurge(stdin);
	scanf(" %c", &opcion);
    }while(tolower(opcion != 's'));

    endwin();   //Libera la matriz.
    return EXIT_SUCCESS;
}
