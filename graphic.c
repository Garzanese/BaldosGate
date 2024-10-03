#include "graphic.h"


#ifdef __linux__ 
    
    // Function to reset the console
    void resetCursor(void)
    {
        // ANSI escape sequence to reset the cursor to the top-left corner of the terminal
        printf("\033[H");
    }

    // Function to hide the cursor
    void hideCursor(void)
    {
        // ANSI escape sequence to hide the cursor
        printf("\033[?25l");
    }

    void ToggleFullScreen()
    {
        // Print the escape sequence that might toggle fullscreen in some terminals
       printf("\033[9;1t"); // May work in some terminal emulators to request fullscreen
    }

#elif _WIN32
    #include <windows.h>
    
    // Function to reset the console
    void resetCursor(void)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordScreen = {0, 0};

        // If the console window handle is valid
        if (hConsole != NULL)
        {
            // Set the cursor position to the top-left corner (first line)
            SetConsoleCursorPosition(hConsole, coordScreen);
        }
    }

    // Function to hide the cursor
    void hideCursor()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // If the console window handle is valid
        if (hConsole != NULL)
        {
            CONSOLE_CURSOR_INFO info;
            info.dwSize = 100;
            info.bVisible = FALSE;
            SetConsoleCursorInfo(hConsole, &info);
        }
    }

     // Function to make the console fullscreeen
    void setFullScreen()
    {
        // Get the console window handle
        HWND hConsole = GetConsoleWindow();

        // If the console window handle is valid
        if (hConsole != NULL)
        {
            // Use ShowWindow to maximize the console window (> windows 10)
            ShowWindow(hConsole, SW_MAXIMIZE);
        }
    }

#else

#endif

void initPlayGround (int PlayGround[fieldHeight][fieldLength])
{   // Function to initialize the PlayGround

    for (int irow=0; irow<fieldHeight; irow++)
    {   // Initialize all element to SPACE
        for (int icol=0; icol< fieldLength ; icol++)
        {
            PlayGround[irow][icol]=feeWalk;
        }
    }
}

void printPlayGround (int PlayGround[fieldHeight][fieldLength], int GameRefresh)
{ // Print
    for (int irow = 0; irow < fieldHeight; irow++) 
    {
        fwrite(PlayGround[irow], sizeof(int), fieldLength, stdout);
        putchar('\n'); // Print a newline character to move to the next row
    }
    
    putchar('\n');
    putchar('\n');
    printf("Refresh Rate: %d \n" , GameRefresh);
}