#include "filesystem.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#define PATH_SEPARATOR "/"
#define PATH_SEPARATOR_CHAR '/'

char* pathConcat(char* s1, char* s2){
    int s1Len = strlen(s1);
    if(s1[s1Len - 1] == PATH_SEPARATOR_CHAR){
        s1[s1Len - 1] = '\0';
        s1Len -= 1;
    }
    int s2Len = strlen(s2);
    char* dest = malloc((s1Len + s2Len + 2)* sizeof(char));
    dest[0] = '\0';
    dest = strcat(dest, s1);
    dest = strcat(dest, PATH_SEPARATOR);
    dest = strcat(dest, s2);
    return dest;
}

int canEnter(char* path){
    int result = 0;
    
    DIR* dir = opendir(path);
    result = ((dir != NULL) ? 1 : 0);
    closedir(dir);

    return result;
}

static inline int
RubyCompare(const struct dirent **a,
  const struct dirent **b)
{
    return(strcmp((*a)->d_name, (*b)->d_name));
}

int listDirectory(char* path, char*** names){
    struct dirent **namelist;
    int result = scandir(path, &namelist, 0, RubyCompare);
    names[0] = malloc(result * sizeof(char*));
    for(int i = 0; i < result; ++i){
        char* name = namelist[i]->d_name;
        names[0][i] = malloc((strlen(name) + 1) * sizeof(char));
        strcpy(names[0][i], name);
    }
    return result;
}

int checkFileExists(char* path){
    return 0;
}
