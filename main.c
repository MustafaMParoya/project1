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
#include "project1.c"


int main (int argc, char *argv[]) {

    int opt;


    //processing command line options using get opt 
    while((opt = getopt(argc, argv, "p:sUSvc")) != -1) { //get opt to process command line options 

        switch(opt) { 

            ///cases 
            case 'p': //setting pid 
            pid = atoi(optarg);
            break; 

            case 's': //sys process 

            sFlag =1 ; //set these flags to either include or exclude the values like CPU time, process, system, etc
            break; 

            case 'U': //cpu time 
            //yes 
            UFlag = 0; 
            break; 

            //breakk

            case 'S': 
            SFlag =1; 
            break; 

            case 'v': 
            vFlag =1; 
            break; 

            case 'c': //print command line info 
            cFlag =0; 
            break; 

            default: 
            printf("Current myps -p <pid> -s -U -S -v -c\n");

            exit(-1); 



        }

    }

    if (pid ==0) { 
        //0
        user = getenv("USER"); //if pid is 0, gets current users processes by calling getpl uset 

        plgrab (user); 
    } 
    else {
        statfileparsing (pid);
        statmfileparsing (pid);
    }

    return 0; 
    //-p pid 
    //-s include system process 
    //-U exclude user cpu time 
    //include system cpu time 
    //-c print command line info 

}