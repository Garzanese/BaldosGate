#include <conio.h>

// define arrow key
#define ARROW_UP    72
#define ARROW_DOWN  80
#define ARROW_LEFT  75
#define ARROW_RIGHT 77

// define actions array
enum action
{
    DX,
    DY,
    ATK,
    DEF,
    ACTION_NUMEL
};

void readCommand(int [ACTION_NUMEL]);
