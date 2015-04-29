#include <stdio.h>
#include <stdlib.h>
#include "filesystem.h"
#include <unistd.h>
#include "terminal.h"

int main(int argc, char** argv){
    char* currentDir = "";
    if(argc > 1){
        currentDir = argv[1];
    } else {
        currentDir = getenv("HOME");
    }

    terminalInit();

    char inKey = ' ';
    int choice = 0;
    char*** files = malloc(sizeof(char**));
    int entryCount = listDirectory(currentDir, files);
    int chosen = 0;
    char* chosenFile = NULL;
    char* destPath;
    while(chosen == 0){
        if(choice >= entryCount) { choice = 0; }
        if(choice < 0) { choice = entryCount - 1; }
        for(int i = 0; i < entryCount; i++){
            if(i == choice)
                fprintf(stderr, "*");
            fprintf(stderr,"%s ", files[0][i]);
        }
        fprintf(stderr, "\r");
    inKey = getc(stdin);
        switch(inKey){
            case 'h':
                --choice;
            break;

            case 'l':
                ++choice;
            break;

            case 'o':
                destPath = pathConcat(currentDir, files[0][choice]);
                if(canEnter(destPath)){
                    currentDir = destPath;
                    entryCount = listDirectory(currentDir, files);
                    chosenFile = NULL;
                    choice = 0;
                } else {
                    chosen = 1;
                    chosenFile = destPath;
                } 
            break;
            case 'a':
                destPath = pathConcat(currentDir, files[0][choice]);
                chosen = 1;
                chosenFile = destPath;
            break;
        }
    }
    puts(chosenFile);
    terminalCleanup();
    return 0;
}
