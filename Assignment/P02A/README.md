Example Assignment README
## P02A - ncurses installation
### Binay Devkota
### Description:This is a proof that I have installed ncurses and ran "Hello World" program

### This is the Hello World Program that generated the following output

#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    printw("Hello, World!"); // Print message on the screen
    refresh();            // Refresh to show the message
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}







<img width="1440" alt="Screenshot 2024-10-10 at 6 24 17 PM" src="https://github.com/user-attachments/assets/bdf37bb5-367d-4bb8-8316-c4244c226e1f">

<img width="1440" alt="Screenshot 2024-10-10 at 6 24 26 PM" src="https://github.com/user-attachments/assets/86be3d81-4267-4ed4-80a1-16b498e49d31">



- Example Command:
    - g++ hello_ncurses.cpp -o hello_ncurses -lncurses
    - ./hello_ncurses


