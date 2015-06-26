#include "core.h"


void init_blank(univers *gridx, int cellNumber){
    int i = 0;
    for (i = 0; i < cellNumber; i++){
        gridx[i].x = X(i);
        gridx[i].y = Y(i);
        killCell(&gridx[i]);
    }
}

int computeNeighboor(univers *cell){
    int i, j;
    short neighboor = 0;
    univers *ncell;
    for(i = -1; i < 2; i++){
        for(j = -1; j < 2; j++){
            if (j != 0 || i != 0){
                ncell = getXYcell(i  + cell->x, j  + cell->y, griddist);
                if (ncell != NULL)
                    neighboor+= (isAlive(ncell))? 1 : 0;

            }
        }
    }
    return neighboor;
}


int computeNext(){
    int col = 0, row = 0;
    int change = 0;
    univers *ptr_cell = NULL;
    univers *ptr_cell_next = NULL;
    int aliveCellNumber = 0;
    for(row = 0;row < rows; row++){
        for(col = 0;col < cols; col++){
            ptr_cell = getXYcell(col, row, griddist);
            ptr_cell_next = getXYcell(col, row, gridnext);

            if (isAlive(ptr_cell)
            && (computeNeighboor(ptr_cell) == 3 || computeNeighboor(ptr_cell) == 2)){
                // no change

                breedCell(ptr_cell_next);
                aliveCellNumber++;
            }
            else if (isAlive(ptr_cell)
            && (computeNeighboor(ptr_cell) != 3 && computeNeighboor(ptr_cell) != 2) ){
                killCell(ptr_cell_next);
                change = 1;

            }
            else if (!isAlive(ptr_cell) && computeNeighboor(ptr_cell) != 3 ){
                //no change
                killCell(ptr_cell_next);

            }
            else if (!isAlive(ptr_cell) && computeNeighboor(ptr_cell) == 3 ){
                breedCell(ptr_cell_next);
                change = 1;
                aliveCellNumber++;
            }
        }
    }
    if (change == 0) {
        running_status = FINISHED;

    }
    return aliveCellNumber;
}


int  read_pattern(int rows, int cols, univers *gridx){

char format[10] ="%";
char strsize[4]="";
int col=0,row=0;
int aliveCellNumber=0;

char *pattern;
univers *cell;

sprintf(strsize, "%d", cols);
strcat(format, strsize);
strcat(format, "s");

pattern = (char*) malloc((cols+1)*sizeof(char));

for (row=0; row< rows;row++){
    printf("   row [%d] : ", row);
    scanf(format, pattern);
    col = 0;
    while (col < cols && (pattern[col] == 's' || pattern[col] == '-')){
        cell = getXYcell(col,row,gridx);
            if (pattern[col] == 's'){
                breedCell(cell);
                aliveCellNumber++;
                }
    col++;
    }
}

free(pattern);
return aliveCellNumber;
}


int random_univers(univers *gridx, int cols,int rows){
int aliveCellNumber = 0;
int col,row;
univers *cell;

for(row = 0; row< rows; row++){
        for(col = 0; col < cols; col++){
            cell = getXYcell(col, row, gridx);
            if (rand() % 2 == 1){
                breedCell(cell);
                aliveCellNumber++;
            }
        }
    }
return aliveCellNumber;
}
int fill_univers(int idPattern, univers *gridx, int cols,int rows){

switch (idPattern) {
case ID_RANDOM: return random_univers(gridx, cols, rows ); break;
case ID_MANUAL: return read_pattern(rows, cols, gridx); break;
case ID_GLIDER_GUN: return glider_univers(gridx, cols, rows); break;

}

return 0;
}

int glider_univers(univers *gridx, int cols,int rows){

int col,row;
int aliveCellNumber=0;
univers *cell;
char config[9][36] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                     {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                     {1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                     };

for(row = 0; row< rows; row++){
        for(col = 0; col < cols; col++){
            cell = getXYcell(col, row, gridx);
            if (config[row][col] == 1){
                breedCell(cell);
                aliveCellNumber++;
            }

        }
    }

return aliveCellNumber;
}
