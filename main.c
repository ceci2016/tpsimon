
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nonblock.h"
#include <pthread.h>
#include "simondice.h"
#define TRUE 1
#define FALSE 0


#define RONDAS 7            //Numero de tandas de juego
#define TIEMPO_MAX_DE_JUGADA 10             //Diez seg max por jugada
#define BIENVENIDA "Bienvenido al juego Simon. Pulse la tecla enter para continuar\n"
#define INSTRUCCIONES   "Toque los numeros que se le van indicando por ronda. Si presiona de manera incorrecta, pierde"
#define YA "LISTOS...YA\n"
int tiempo_agotado=0;
int game_over=0,efectivamente;
int mi_tablero[RONDAS];
int tablero[RONDAS]={0,0,0,0,0,0,0};                //arreglo en donde se guarda la secuencia
void muestra_colores (int);
void hacer_tiempo (int seconds);


int main(int argc, const char * argv[]) {
    time_t t;
        srand((unsigned) time(&t));
    for(int contador=0;contador<(RONDAS-1);contador++){
        tablero[contador]= rand() % 3 ;
    }
        //pthread_t crono;                        //Para inizializar el thread como cronometro
    
    printf(BIENVENIDA);
                           //Loop para tocar enter
    int control_de_teclado= 0;
    while (control_de_teclado==0){
        control_de_teclado=interaccion_con_teclado('\n');
    }
    
    printf(INSTRUCCIONES);
    
    
    
    
    int ronda_actual = 1;
    
    
    
    
    
  
    
    while (ronda_actual <=RONDAS) {
        printf("\nRonda %d\n",ronda_actual);    //Imprime el patron en pantalla
        
        hacer_tiempo(1);
        muestra_colores (ronda_actual);
        
        
          leer_tablero (ronda_actual);
        
        
    
                if (efectivamente==TRUE){
                    printf("\nPerdiste.\n");
                    game_over=TRUE;
                    break;
                    
                }
       
        
        if (!efectivamente)
            ++ronda_actual;
        else{
            ronda_actual=1;
            game_over=TRUE;
            break;
        }
        


    }
    if (game_over==FALSE)
        printf("\n ganaste!!!!!!!!\n");
    return 0;
}
    
    

void muestra_colores (ronda_actual){
for (int selector=0 ;selector != ronda_actual;++selector){
    printf("%d\n",tablero[selector]);
    hacer_tiempo(1);
    
}
    printf(YA);
}

void hacer_tiempo (int seconds)
{
    time_t current_time_init = time(NULL); //genera un delay en segundos
    time_t current_time = time(NULL);
    while (current_time <= (current_time_init + seconds))
    {
        current_time = time(NULL);
    }
}










