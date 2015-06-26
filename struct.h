#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <stdio.h>

#include "consts.h"
struct t_grid {
    int x;
    int y;
    int status;
};

typedef struct t_grid univers;
 int running_status;// = RUN;
int game_status; //= RUNNING;
int                     cellNumber ;

int rows,cols;

univers *griddist;
univers *gridnext;
univers *gridswap;


int isAlive(univers *cell);
void killCell(univers *cell);
void breedCell(univers *cell);

void intHandler(int dummy);

univers* getXYcell( int x, int y, univers *gridx);
// navigation
void swap_mat();

int isRunning();
void stopGame();
void pauseGame();
void resumeGame();
void genMode();
void stepMode();


#endif // STRUCT_H_INCLUDED
