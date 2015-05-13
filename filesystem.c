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

    /* if the path ends by path separator, remove it and replace with \0 */
    if(s1[s1Len - 1] == PATH_SEPARATOR_CHAR){
        s1[s1Len - 1] = '\0';
        s1Len -= 1;
    }

    int s2Len = strlen(s2);
    /* destination string will have length of s1 + s2 + 1(path separator) + 1(terminating \0) */
    char* dest = malloc((s1Len + s2Len + 2)* sizeof(char));
    /* set end of the string to its beginning */
    dest[0] = '\0';
    /* do the actual string concatenation */
    dest = strcat(dest, s1);
    dest = strcat(dest, PATH_SEPARATOR);
    dest = strcat(dest, s2);
    return dest;
}

int canEnter(char* path){
    int result = 0;
    /* if the directory with this path can be opened, that means we can list it 
     * to clear this out - this function should fail if `path` doesn't refer to directory, we have no permission to access it etc.
     * */
    DIR* dir = opendir(path);
    result = ((dir != NULL) ? 1 : 0);
    closedir(dir);

    return result;
}
/* thank you StackOverflow for this function :)
 * it's basically comparator for two dirent structures
 * */
static int RubyCompare(const struct dirent **a,
  const struct dirent **b)
{
    return(strcmp((*a)->d_name, (*b)->d_name));
}

/* lists directory contents, saves result into array pointed to by names and returns count of filenames */
int listDirectory(char* path, char*** names){
    /* array that will store list of files(not names) in directory */
    struct dirent **namelist;
    /* for-loop index variable */
    unsigned int i;
    /* retrieve list of dirent structures sorted using the RubyCompare function */
    int result = scandir(path, &namelist, 0, RubyCompare);
    /* allocate the array where it's supposed to be */
    names[0] = malloc(result * sizeof(char*));

    for(i = 0; i < result; ++i){
        /* retrieve name of dirent */
        char* name = namelist[i]->d_name;
        /* allocate a string in the array */
        names[0][i] = malloc((strlen(name) + 1) * sizeof(char));
        /* copy the string from `name` variable to the array */
        strcpy(names[0][i], name);
    }
    return result;
}

/* currently not used ;) */
int checkFileExists(char* path){
    return 0;
}
