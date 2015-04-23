#include <stdio.h>
#include <ncurses.h>

int main(char** argv, int argc){
    char* currPath = "$HOME";
    initscr();
    clear();
    cbreak();
    noecho();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    int ch = 0;
    while(ch != KEY_ENTER){
        ch = getch();
        switch(ch){
            case KEY_UP:
            break;

            case KEY_DOWN:
            break;
        }
        refresh();
    }
    endwin();
    putchar('\n');
    return 0;
}
