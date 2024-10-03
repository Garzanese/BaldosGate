#include <stdio.h>

/* Definitions of graphic setting*/

#define fieldLength     50
#define fieldLxHscaling 2
#define fieldHeight     60

#define noWalk          35
#define feeWalk         46
#define roomSizeMin     3
#define PGface          38

/* Definitions of functions*/
void hideCursor(void);
void setFullScreen(void);
void resetCursor(void);
void initPlayGround  (int [fieldHeight][fieldLength]);
void printPlayGround (int [fieldHeight][fieldLength], int);