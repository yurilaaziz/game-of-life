
#include "display.h"
void header(){
printf("Hello all this is a game \n");

}
void monitorclear(){
    system("clear");

}


void displayGrid(univers *gridx,int cols, int rows){
    int col,row;
    univers *cell;

    for (row = 0; row < rows; row++){
        for (col = 0; col < cols; col++){
            if (col % cols == 0)
                printf("\n");
            cell = getXYcell(col, row, gridx);
            printf("%c|", isAlive( cell ) ? 's' : ' ');
        }
    }
    printf("\n");
}

short menu()
{
short choice = -1;

while (choice < 0 || choice > 7) {
//system("clear");
printf("    Choose a pattern : \n");
printf("        1 - Random  \n");
printf("        2 - Mannual \n");
printf("        %d - %s \n", ID_GLIDER_GUN, NAME_GLIDER_GUN);

printf("    Choice [1..7] : ");
scanf("%d",&choice);

}
if (choice == 1 || choice == 2) {
  while (rows<=0 || rows >MAX_ROWS){
    printf("   rows [0..%d] : ",MAX_ROWS);
    scanf("%d",&rows);
   }
  while (cols<=0 || cols >MAX_COLS){
   printf("   cols [0..%d] : ",MAX_COLS);
   scanf("%d",&cols);
   }
} else
{
    switch (choice){
    case ID_GLIDER_GUN:
        rows = ROWS_GLIDER_GUN;
        cols = COLS_GLIDER_GUN;
        break;
    default : break;

    }
}

return choice;
}
