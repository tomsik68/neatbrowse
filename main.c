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
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    int inKey = 0;
    int choice = 0;
    char** files;
    int entryCount = listDirectory(currentDir, &files);
    bool chosen = FALSE;
    char* chosenFile = NULL;
    char* destPath = NULL;
    while(!chosen){
        inKey = getch();
        switch(inKey){
            case KEY_UP:
                --choice;
            break;

            case KEY_DOWN:
                ++choice;
            break;

            case KEY_RIGHT:
                destPath = pathConcat(currentDir, files[choice]);
                if(canEnter(destPath)){
                    currentDir = destPath;
                } else {
                    chosen = TRUE;
                    chosenFile = destPath;
                }
            
            break;
        }
        clear();
        refresh();
        printw("Current Directory: %s\n", currentDir);
        if(choice >= entryCount) { choice = 0; }
        if(choice < 0) { choice = entryCount - 1; }
        for(int i = 0; i < entryCount; i++){
            if(choice == i)
                attron(COLOR_PAIR(2));
            printw("%s\n", files[i]);
            if(choice == i)
                attroff(COLOR_PAIR(2));
        }
    }
    puts(chosenFile);
    endwin();
    putchar('\n');
    return 0;
}
