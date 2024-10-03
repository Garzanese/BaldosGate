/* Generic definitions*/
#define PGhp    10
#define PGarmor 00
#define PGatk   01
#define PGposx  00
#define PGposy  00

typedef struct _character
{
    int face;
    int hp;
    int armor;
    int atk;
    int posx;
    int posy;
} character;

/* Functions declaration*/

void initPlayerCharacter(character *);
void moveCharacters(int [fieldLength][fieldHeight],  character *, int[2]);
