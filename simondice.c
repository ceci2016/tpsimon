//
//  simondice.c
//  Simon
//
//  Created by Santiago Bualo on 1/12/16.
//  Copyright © 2016 Santiago Bualo. All rights reserved.
//

#include "simondice.h"
#include "nonblock.h"
#include <time.h>


extern int tiempo_agotado;
extern int game_over,efectivamente;
extern int mi_tablero[RONDAS];
extern int tablero[RONDAS];





void leer_tablero (ronda_actual){
    nonblock (NB_ENABLE);
    while (!kbhit()) {
        kbhit();
    }
    int w=0;
    for (;w!= ronda_actual;++w){
        unsigned int valor_recibido=FALSE;
        char caracter_recibido= getchar();
        if (caracter_recibido== ' '){
            w=0;
            continue;
        }
        
        
        valor_recibido= caracter_recibido - '0';
        
        if (valor_recibido==0 |valor_recibido==1|valor_recibido==2|valor_recibido==3|valor_recibido==4){
            mi_tablero[w]=valor_recibido;
            
            int acierto=simon_dice(w);
            
            if (acierto==FALSE){            //Si los colores no son iguales
                efectivamente=TRUE;
                break;
            }
            
        }
        else {
            printf("Error caracter no válido\n Vuelva a ingresar el dato o pulse espacio para volver a colocar todos los datos\n");
            w--;
        }
    }
    nonblock(NB_DISABLE);
}



int simon_dice (color_actual){
    //Variable que va a contar si se efectua la comparacion correcta
    int correcto=TRUE;
    
    if (tablero[color_actual]==mi_tablero[color_actual]){
        correcto=TRUE;
    }
    else{
        correcto=FALSE;
    }
    
    
    return correcto;
}




int interaccion_con_teclado (char a){               //Ojo en donde se usa pq bloquea el programa
    int control=FALSE;          //Le pasas la tecla que estas esperando y espera hasta que la obtiene
    while (1){
        
        nonblock(NB_ENABLE);
        while (!kbhit()) {
            kbhit();
        }
        char caracter_levantado=getchar();
        if (caracter_levantado==a){
            control=TRUE;
            break;
        }
    }
    nonblock(NB_DISABLE);
    return control;
}



void cronometro (void){
    while (1){
        time_t current_time_init = time(NULL);
        time_t current_time = time(NULL);
        if (current_time <= (current_time_init + TIEMPO_MAX_DE_JUGADA))
        {
            tiempo_agotado=1;
            break;
        }
        else
        {
            current_time = time(NULL);
        }
    }
    exit (1); //test
    
    
}
