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
    /* input key typed in terminal */
    char inKey = ' ';
    /* number of file currently chosen by user */
    int choice = 0;
    /* pointer to array of filenames which may be chosen */
    char*** files = malloc(sizeof(char**));
    /* count of filenames in the array `files` */
    int entryCount = listDirectory(currentDir, files);
    /* whether the user has already chosen a file(0 = NO, other values = YES) */
    int chosen = 0;
    /* full path to file chosen by user */
    char* chosenFile = NULL;
   /* index variable used in for loops */
    unsigned int i;
    
    /* the user may specify a starting directory in the first argument */
    if(argc > 1){
        currentDir = argv[1];
    } else {
        /* if the directory is not specified, it defaults to HOME
         * TODO: it might be better to get to `pwd` somehow... */
        
        currentDir = getenv("HOME");
    }
    /* setup terminal for our needs(no waiting for newline etc.) */
    terminalInit();
    /* while the user hasn't chosen file */
    while(chosen == 0){
        /* array bounds checks for `choice` variable + wrapping around */
        if(choice >= entryCount) { choice = 0; }
        if(choice < 0) { choice = entryCount - 1; }

        /* print out all the options
         *  - start 2 before the chosen one
         *  - end 2 after the chosen one
         *  ^^ the above limits are present not to spam the entire terminal
         */
        for(i = MAX(choice-2, 0); i < MIN(choice+3,entryCount-1); i++){
            /* chosen filename is wrapped around by arrows ->ABC<- */
            if(i == choice){
                fprintf(stderr," ->%s<- ", files[0][i]);
            } else {
                fprintf(stderr, "%s ", files[0][i]);
            }                
        }

        /* this is to overwrite longer filenames that might've been present */
        for(i = 0; i < 80; ++i){
            fprintf(stderr, " ");
        }

        /* return to the beginning of line */ 
        fprintf(stderr, "\r");

        /* ask the user what to do */
        inKey = getchar();
        switch(inKey){
            /* move choice to the left */
            case 'h':
                --choice;
            break;
            /* move choice to the right */
            case 'l':
                ++choice;
            break;
            /* (O)pen directory */
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
            /* (A)ccept currently selected file */
            case 'a':
                chosenFile = pathConcat(currentDir, files[0][choice]);
                chosen = 1;
            break;
        }
    }
    /* write out full path to chosen file */
    puts(chosenFile);

    /* get the old terminal configuration back(cancel any changes that were done to the terminal) */
    terminalCleanup();

    return 0;
}
