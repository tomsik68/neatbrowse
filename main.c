#include <stdio.h>
#include <ncurses.h>
#include "filesystem.h"



int main(char** argv, int argc){
    char* currPath = "$HOME";
    initscr();
    clear();
    cbreak();
    noecho();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    int inKey = 0;
    int choice = 0;
    int num_choices = 2;
    while(inKey != KEY_ENTER){
        inKey = getch();
        switch(inKey){
            case KEY_UP:
                --choice;
            break;

            case KEY_DOWN:
                ++choice;
            break;
        }
        clear();
        if(choice >= num_choices) { choice = 0; }
        if(choice < 0) { choice = num_choices - 1; }
        printw("%d", choice);
        refresh();
    }
    endwin();
    putchar('\n');
    return 0;
}
