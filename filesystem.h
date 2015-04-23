// some platform-dependent code for handling filesystem operations

/**
Returns 1 if the specified file can be entered(is directory? + has permission?). 0 otherwise
\param path - Path to the desired file entry
\return 1 if the specified file is a directory AND can be entered, 0 otherwise
*/
int canEnter(char* path);

/**
Returns list of files(only file names) in desired directory
\param path - Path to the directory we want to list
\return List of file names(only basenames, not full path) in the current directory
*/
char** listDirectory(char* path);
