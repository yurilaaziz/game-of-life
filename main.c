/*
	GAME OF LIFE 
		Written by @asker_amine
		
	
	@info : The Game of Life is not a typical computer game. It is a 'cellular automaton',
			 and was invented by Cambridge mathematician John Conway
			The Rules

			[+] For a space that is 'populated':
			    	Each cell with one or no neighbors dies, as if by loneliness. 
			    	Each cell with four or more neighbors dies, as if by overpopulation. 
			    	Each cell with two or three neighbors survives. 
			[+]	For a space that is 'empty' or 'unpopulated'
			    Each cell with three neighbors becomes populated. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include "consts.h"
#include "display.h"
#include "struct.h"
#include "core.h"
#include "navigation.h"


int main(int argc,char **argv){

    int aliveCellNumber = 0;
    int generation      = 0;
    int idPattern;

    signal(SIGINT, intHandler);

    running_status= RUN;
    game_status= RUNNING;
    header();
    srand(time(NULL));

    idPattern = menu();
    cellNumber = cols*rows;

    griddist = (struct t_grid*)malloc( cellNumber *sizeof(struct t_grid) );
    if (griddist == NULL)
        exit(-1);

    gridnext = (struct t_grid*)malloc( cellNumber *sizeof(struct t_grid) );
    if (gridnext == NULL)
        exit(-2);

    init_blank(griddist, cellNumber);
    init_blank(gridnext, cellNumber);
    aliveCellNumber = fill_univers(idPattern, griddist,cols,rows);


    while (isRunning()){
        monitorclear();
        displayGrid(griddist,cols,rows);
        printf("\n Generation %d | %d living cell(s) | ctrl-c pour terminer \n", generation, aliveCellNumber);
        next(&generation);
        generation++;
        aliveCellNumber = computeNext();
        swap_mat();
    }

       printf("\n Generation %d | %d living cell(s) | Finished! \n", generation, aliveCellNumber);


    if (griddist != NULL)   
   		 free(griddist);
   	if (gridnext != NULL)
    	free(gridnext);

    return 0;
}
