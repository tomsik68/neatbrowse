#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "filesystem.h"



int main(int argc, char** argv){

    char* currentDir = "";
    if(argc > 1){
        currentDir = argv[1];
    } else {
        currentDir = getenv("HOME");
    }
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
        printw("Current Directory: %s\n", currentDir);
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
