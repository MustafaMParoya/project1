#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include "project1.h"

extern char *user; 
extern int pid;
extern int sFlag;
extern int UFlag ;
extern int SFlag; 
extern int vFlag; 
extern int cFlag ; 


  //-p pid 
    //-s include system process 
    //-U exclude user cpu time 
    //include system cpu time 
    //-c print command line info 

void statmfileparsing (int pid) {

    char statmFile[1024]; 
    int size; 

    //open stat file 
    sprintf(statmFile, "/proc/%d/statm", pid);
    FILE *fp = fopen(statmFile, "r");
    if (fp == NULL ) {
        perror("open"); 
        exit(-1); 
    }


    if(fscanf(fp, "%d", &size) != 1) {
        fprintf(stderr, "Could not Parse, Sorry  %s\n", statmFile);
        exit(-1);

    }




    // c and v flags 
    if(vFlag == 1) {
        printf("%d\t", size);

    }

    if (cFlag == 1) {
        printf("%s\n", "/proc/[PID]/cmdline");

    } else {
        printf("\n");

    }

    fclose(fp); 


//open statm using fopen and fclose to close
}

void statfileparsing  (int pid) {

    char  statFile[1024]; //magic number which is the max computer memory adresses 
    char state; 
    int user; //user 
    int system; //system 

    sprintf(statFile, "/proc/%d/stat", pid); //constructs path using pid
    FILE *fp = fopen(statFile, "r"); //open stat file in read mode
// opening and reading the file 


    if (fp ==NULL ) {

        perror("open");
        //error handling  
        exit(-1); 

    }

    if(fscanf(fp, "%*d %*s %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d", &state, &user, &system ) != 3) {
        fprintf(stderr, "Sorry, this was not able to be parsed.. %s\n", statFile);
        //scan is used to parse values from the file 


        //exit as error 
        exit(-1);//parsing and error handling 

    }
    printf("%d\t%c\t", pid, state); //outputs

    if(UFlag == 1) { 
        //u flag 
        printf("%d\t", system);
        //outputs extracted info PID, process state,  cpu time 

    }
    fclose(fp); 

}


void plgrab ( char *user ) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    //open proc directory w opendir 
    dir = opendir("/proc");

    if (dir == NULL ) { 
        perror("opendir"); //fails to open dir 
        exit (-1); //error code 
    }

    while((entry = readdir(dir)) != NULL) {  //read
        //while loop used to iterate over the entries 
        if(entry->d_type != DT_DIR) {
            continue; //skips the non dir entires... 
        }

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
            //entries with . or ... are skipped, avoid useless parsing 
        }
        char path[1024];
        strcpy(path, "/proc/");
        strcat(path, entry->d_name); //concatenates the path to each entry, 


// stat is used to get info about the file...
        if(stat(path, &statbuf) == -1) {
            perror("stat");
            exit(-1);

        }
        //owened by the user ? check the ownership ^^^

        if(statbuf.st_uid == getuid()) {
            pid = atoi(entry->d_name);
            if (pid > 0) { // if pid is 0, then call the functions cause its valid
                statfileparsing (pid); //parsing 
                statmfileparsing(pid);
                //call these functions to get info of the certain process 
                
            }

        }

    }

    closedir(dir); //proc directory is closed 

}


//void process options 





