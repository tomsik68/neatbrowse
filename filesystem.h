/* some platform-dependent code for handling filesystem operations */

/**
Concatenates two paths.
If s1 is "/home/user" and s2 "Documents", the result is "/home/user/Documents"
*/
char* pathConcat( char* s1, char* s2);

/**
Returns 1 if the specified file can be entered(is directory? + has permission?). 0 otherwise
\param path - Path to the desired file entry
\return 1 if the specified file is a directory AND can be entered, 0 otherwise
*/
int canEnter(char* path);

/**
Returns list of files(only file names) in desired directory
\param path - Path to the directory we want to list
\param names - Pointer to array of file names
\return amount of entries
*/
int listDirectory(char* path, char*** names);

/**
Checks whether or not this path exists
\param path - Path to the desired file
\return 1 if any type of file with this pathname exists, 0 otherwise
*/
int checkFileExists(char* path);
