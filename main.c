#include "graphic.h"
#include "keyboard.h"
#include "gameplay.h"
#include <string.h>
#include <windows.h>

int main()
{

    int PlayGround [fieldHeight][fieldLength];
    int isContinue  = 1;
    int refreshRate = 1;
    int todo[ACTION_NUMEL];

    character PG;

    initPlayGround (PlayGround);
    initPlayerCharacter(&PG);

    setFullScreen();
    hideCursor();
    
    /* code */
    while (isContinue)
    {
        memset(todo, 0, sizeof(todo));
        initPlayGround (PlayGround);

        resetCursor();
         
        readCommand(todo);
        PG.posx=PG.posx+todo[DX];
        PG.posy=PG.posy+todo[DY];

        PlayGround[PG.posy][PG.posx]=PG.face;

        if(todo[ATK])
        {
            PlayGround[PG.posy+1][PG.posx+1]=92;
        }
        printPlayGround (PlayGround, refreshRate);

        Sleep(10);
    }

    return 0;
}
