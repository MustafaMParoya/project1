#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
//global variables 



void plgrab (char *user);

//parse functions declarations 
void statfileparsing (int pid);
void statmfileparsing (int pid);
