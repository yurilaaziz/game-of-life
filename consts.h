#ifndef CONSTS_H_INCLUDED
#define CONSTS_H_INCLUDED


#define X(i) i % cols
#define Y(i) i / cols

//      ______CONST_____|__VALUE___
#define RUN_STATUS           1
#define PAUSE_STATUS         2
#define STOP_STATUS          3

//      ______CONST_____|__VALUE___
#define DEAD                0
#define ALIVE               1


//      ______CONST_____|__VALUE___
#define MAX_ROWS            20
#define MAX_COLS            80

//running status
#define RUN                 1
#define FINISHED            2
#define EXITED              3

// game status
#define RUNNING             23
#define PAUSE               20
#define STEPBYSTEP          21
#define GOTO                22

// Pattern ID

#define ID_RANDOM           1
#define ID_MANUAL           2
#define ID_GLIDER_GUN       3

#define NAME_GLIDER_GUN     "Gosper glider gun"
#define COLS_GLIDER_GUN     37
#define ROWS_GLIDER_GUN     9

#endif // CONSTS_H_INCLUDED
