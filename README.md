# project1

Compile and Run
-In order to execute my program, first you would need to transfer the files to the server using filezilla. Once they have been transferred sucessfully, you connect to the server with your log in and once conected, proceed with compiling and executing the program with -Wall amd -Werror flags like gcc -o main main.c -Wall -Werror


Design Section
- Some design decisions were made while programming. I have the program split into 3 fucntions where one was created to get the process list by looping through the files in the proc directory and getting the path to the entry in the directory. This function will return the processes that are owned by the user, which is why *user is a parameter 
- Then two other fucntions that parse the stat and statm files that take pid as a parameter which is the process ID, and constructs a path to the stat files. Uses scanf to parse from the file and extract, and U and S flag whuch returns user and system time
- These functions are used in main whe there is no -p option, so it will ge the process list and parse by using the functions. I was ver 



- Testing Plan
- How did you test your program throughout. Talk about bugs you had
- I test this program througout by changing things constantly and seeing how it affects overall. I tested with specific process IDs and also modified enviornment variables. Also to test my error handling, i would put incorrect code on purpose to see how the handling works and what to improve. Some bugs that I had was reagrding inconsistent fucntion declarations, overusing the exit(-1) commands a lot when not needed and A LOT OF SPELLING MISTAKES. 
