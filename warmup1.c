//warm up 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define NULL


void get_cpu_info() {

    FILE *cpuinfo_file = fopen("/proc/cpuinfo", "r"); //opening file of cpu 

    if (cpuinfo_file == NULL ) {
        perror ("Sorry there was an error opening /proc/cpuinfo ");  //error handling 
        return; 
    }

    int num_cpus = 0;  //declare 
    char line [MAX_LINE_LENGTH]; 
    char cache_size [MAX_LINE_LENGTH];  //array declaration 
    int current_cpu = -1; 

    while (fgets (line, sizeof(line), cpuinfo_file) != NULL) { //read line by line and get info 
        if (strstr(line, "processor")) {
            sscanf(line, "processor : %d", &current_cpu);
            num_cpus++; //increase number of cpus 

        } else if (strstr(line, "cache size")) {
            sscanf(line, " with cache size : %[^\n]", cache_size); // cache size 
            if (current_cpu >= 0) {
                printf("CPU %d:\n", current_cpu);
                printf("Cache Size: %s\n\n", cache_size);

            }

        }

    }

    fclose(cpuinfo_file); 
    printf("Number of CPUs: %d\n", num_cpus); // return number of cpus 
}

int main () {
    get_cpu_info(); //run 
    return 0;

}