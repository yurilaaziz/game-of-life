#include "navigation.h"


void onPause(){
    char tmp;
    printf("-- Game paused -- | Press [r] to resume. ");

    while (tmp != 'r'){
        scanf("%c", &tmp);
    }
    resumeGame();
}
void onGoto(int *generation){
    int tmp,i;
    printf("-- Jump from Gen:%d to Gen:", *generation);
    scanf("%d", &tmp);

    if (tmp < *generation)
        printf("Impossible to return back !\n");
    else
    {
        tmp -= *generation + 1 ; // the last compute is handled in the main
        for (i = 0; i< tmp; i++){
              computeNext();
              swap_mat();
              *generation = *generation + 1;
        }
    }
    resumeGame();
}

void onStep(){
    char tmp;
    printf("-- [enter] next step  -- | [r] to return to normal mode. ");
    scanf("%c", &tmp);
    if (tmp == 'r')
        resumeGame();
    //else
        //nothing
}
void onRunning(int *generation){

    char tmp;
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
    printf("-- [s] Step by Step | [g] go to Generation | [p] Pause --  \n");

    if( poll(&mypoll, 1, 1000) )
        {
            scanf("%c", &tmp);
        }

    switch (tmp){
        case 'p': pauseGame(); onPause();break;
        case 'g': genMode(); onGoto(generation);break;
        case 's': stepMode(); onStep();break;
        default:break;
    }
}

void next(int *generation) {

    switch (game_status){
        case PAUSE: onPause(); break;
        case GOTO: onGoto(generation); break;
        case STEPBYSTEP : onStep(); break;
        case RUNNING: onRunning(generation);break;
    }

}
