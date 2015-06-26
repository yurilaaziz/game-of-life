#ifndef STRUCT_C_INCLUDED
#define STRUCT_C_INCLUDED

#include "struct.h"


int isAlive(univers *cell){
    return (cell->status == ALIVE);
}
void killCell(univers *cell){
    cell->status = DEAD;
}
void breedCell(univers *cell){
    cell->status = ALIVE;
}
void intHandler(int dummy) {
    running_status = 0;
}
// navigation
univers* getXYcell( int x, int y, univers *gridx){
    return ( x >= 0 && x < cols && y >= 0 && y< rows) ? &gridx[y * cols + x ] : NULL ;
}

void swap_mat(){
    gridswap = griddist;
    griddist = gridnext;
    gridnext = gridswap;
}

int isRunning(){
    return (running_status == RUN);
}
void stopGame(){
    game_status = STOP_STATUS;
}
void pauseGame(){
    game_status = PAUSE;
}
void resumeGame(){
    game_status = RUNNING;
}
void genMode(){
    game_status = GOTO;
}
void stepMode(){
    game_status = STEPBYSTEP;
}


#endif // STRUCT_C_INCLUDED
