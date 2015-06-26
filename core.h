#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <stdio.h>
#include "struct.h"
#include "consts.h"

void init_blank(univers *gridx, int cellNumber);
int computeNeighboor(univers *cell);

int computeNext();
int fill_univers(int idPattern, univers *gridx, int cols,int rows);
int random_univers(univers *gridx, int cols,int rows);
int glider_univers(univers *gridx, int cols,int rows);
#endif // CORE_H_INCLUDED
