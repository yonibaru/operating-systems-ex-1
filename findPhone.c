#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#define MAX_SCRIPT_LENGTH 1024
int main(int argc, char *argv[]) {
    // Ensure correct number of arguments are provided
    if(argc < 2 || argc > 3){
        printf("Incorrect # of args");
        return 1;
    }

    char phone_book[] = "phone_book.txt";

    // Create a pipe AKA communication channel between parent and child processes, fd[0] is for reading and fd[1] is for writing.
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe(2) failed");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1){
        perror("fork(2) failed");
        exit(1);
    }

    if (pid == 0){ // Child process -- tasked with writing to the pipe.

        close(fd[0]); //Close the reading end

        // Redirects any writes to STDOUT by the child process to be directed to the write end of the pipe, allowing the parent process to read from it.
        if (dup2(fd[1], STDOUT_FILENO) == -1) {
            perror("dup2(2) failed");
            exit(1);
        }
 
        // Simple grep command to fetch all relevant results (which is then redirected from STDOUT to fd[0])
        execl("/bin/grep", "grep", argv[1], phone_book, NULL);
        perror("execl failed");
        exit(1); // Close the child process

    }else{ // Parent process -- tasked with reading to the pipe.

        close(fd[1]); //Close the writing end

        // Print results from the pipe
        char line[MAX_SCRIPT_LENGTH];
        ssize_t bytes;
        //Thanks to : https://stackoverflow.com/questions/76131380/readfile-buffer-prints-garbage-using-printf
        while ((bytes = read(fd[0], line, sizeof(line) - 1)) > 0) {
            line[bytes] = '\0'; // Place a Null char' in the buffer after reading (otherwise it prints a line of garbage!)
            printf("%s", line);
        }
        close(fd[0]);
    }

    return 0;
}