#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filesystem.h"
#include <unistd.h>
#include "terminal.h"

/* utilities */
#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)


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
    unsigned int i;
    
    while(chosen == 0){
        if(choice >= entryCount) { choice = 0; }
        if(choice < 0) { choice = entryCount - 1; }

        for(i = MAX(choice-2, 0); i < MIN(choice+3,entryCount-1); i++){
            /* chosen filename is wrapped around by arrows ->ABC<- */
            if(i == choice){
                fprintf(stderr," ->%s<- ", files[0][i]);
            } else {
                fprintf(stderr, "%s ", files[0][i]);
            }                
        }

        for(i = 0; i < 80; ++i){
            fprintf(stderr, " ");
        }
 
        fprintf(stderr, "\r");
        inKey = getchar();
        switch(inKey){
            case 'h':
                --choice;
            break;

            case 'l':
                ++choice;
            break;

            case 'o':
                chosenFile = pathConcat(currentDir, files[0][choice]);
                /* but only if it is a directory */
                if(canEnter(chosenFile)){
                    currentDir = chosenFile;
                    entryCount = listDirectory(currentDir, files);
                    chosenFile = NULL;
                    choice = 0;
                }
            break;
            case 'a':
                chosenFile = pathConcat(currentDir, files[0][choice]);
                chosen = 1;
            break;
        }
   }
    puts(chosenFile);
    terminalCleanup();
    return 0;
}
