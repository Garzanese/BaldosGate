#include "keyboard.h"
#include <windows.h>

void readCommand(int todo[ACTION_NUMEL])
{

    // Detect arrow key presses and set movement direction accordingly
    if (GetAsyncKeyState('W')) 
    {
        todo[DY] = -1;
    }
    if (GetAsyncKeyState('S')) 
    {            
        todo[DY] = 1;
    }
    if (GetAsyncKeyState('A')) 
    {
        todo[DX] = -1;
    }
    if (GetAsyncKeyState('D')) 
    {
        todo[DX] = 1;
    }
    if (GetAsyncKeyState(VK_SPACE)) 
    {
        todo[ATK] = 1;
    }
}