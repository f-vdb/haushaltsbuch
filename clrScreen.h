
#ifndef CLR_SCREEN_H
#define CLR_SCREEN_H

#ifdef __unix__
#include "stdio.h"
#define clrScreen() printf("\x1B[2J")
#elif WIN32 || _MSC_VER
#include <cstdlib>
#define clrScreen() system("cls")
#elif __APPLE__
#include "stdio.h"
#define clrScreen() printf("\x1B[2J")
#endif

#endif // CLR_SCREEN_H
