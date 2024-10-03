#include "graphic.h"
#include "gameplay.h"


void initPlayerCharacter(character *PG)
{

    PG->face    = PGface;
    PG->hp      = PGhp;
    PG->armor   = PGarmor;
    PG->atk     = PGatk;
    PG->posx    = PGposx;
    PG->posy    = PGposy;
}

void moveCharacters(int PlayGround[fieldLength][fieldHeight],  character *dummy, int movement[2])
{

    dummy->posx = dummy->posx + movement[0];
    dummy->posx = dummy->posx + movement[1];  
}