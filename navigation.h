#ifndef NAVIGATION_H_INCLUDED
#define NAVIGATION_H_INCLUDED
#include "struct.h"
#include <unistd.h>
#include <poll.h>

void onPause();
void onGoto(int *generation);
void onStep();
void onRunning(int *generation);
void next(int *generation);


#endif // NAVIGATION_H_INCLUDED
