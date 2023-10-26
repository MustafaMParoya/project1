// warm up 2 

#include <stdio.h>
#include <stdlib.h>

void reportMemoryInfo() {
    FILE *meminfoFile = fopen("/proc/meminfo", "r"); // Open the file "/proc/meminfo" for reading and assign the file stream to the pointer variable meminfoFile


    int totalMem, freeMem, buffers; //declare varaibles to store mem info 

    // Read the values from /proc/meminfo using while loop 
    while (fscanf(meminfoFile, "%*s %d", &totalMem) != 1 ||
           fscanf(meminfoFile, "%*s %d", &freeMem) != 1 ||
           fscanf(meminfoFile, "%*s %*d %*s %d", &buffers) != 1) {
        // Skip lines that don't match the expected format
        fscanf(meminfoFile, "%*[^\n]\n") ; 
    }

    fclose(meminfoFile); //close the file stream 

    // Print the information
    printf("Free Memory: %d KB\n", freeMem); //print value declared above 
    printf("Number of Memory Buffers: %d KB\n", buffers);
}

int main() {
    reportMemoryInfo();
    return 0;
}


/* if (meminfoFile == NULL ) { //error opening the file 
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }*/