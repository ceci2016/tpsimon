//
//  simondice.h
//  Simon
//
//  Created by Santiago Bualo on 1/12/16.
//  Copyright © 2016 Santiago Bualo. All rights reserved.
//

#ifndef simondice_h
#define simondice_h

#include <stdio.h>
#define TRUE 1
#define FALSE 0


#define RONDAS 7            //Numero de tandas de juego
#define TIEMPO_MAX_DE_JUGADA 10             //Diez seg max por jugada
#define BIENVENIDA "Bienvenido al juego Simon. Pulse la tecla enter para continuar\n"
int interaccion_con_teclado (char);        //Funcion que espera la tecla que se le pasa
void leer_tablero (int);
int simon_dice (int);
void cronometro (void);



#endif /* simondice_h */
