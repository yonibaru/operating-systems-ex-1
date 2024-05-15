#include <stdio.h>
#include <stdlib.h>
#define MAX_SCRIPT_LENGTH 1000

int main(int argc, char *argv[]) {
    // Insure correct number of arguments are provided
    char newLine[200]; 
    if(argc == 4){
        // argv[1]: name, argv[2]: surname, argv[3]: phone #
        snprintf(newLine, sizeof(newLine), "%s %s,%s", argv[1], argv[2], argv[3]);
    } else if (argc == 3){
        // argv[1]: name, argv[2]: phone #
        snprintf(newLine, sizeof(newLine), "%s,%s", argv[1], argv[2]);
    } else {
        printf("Incorrect # of args");
        return 1;
    }
    char phone_book[] = "phone_book.txt";

    // Using snprintf to concat txt file path (We are not allowed to use strcat!)
    // Note: Script includes line-feed.
    char awk_script[MAX_SCRIPT_LENGTH];
    snprintf(awk_script,sizeof(awk_script),"awk 'BEGIN {print \"%s\" >> \"%s\"}'",newLine,phone_book);

    // Using pipe api to execute our AWK script
    FILE *pipe = popen(awk_script, "r");
    if (!pipe) {
        perror("Failed to open pipe stream");
        exit(1);
    }
    pclose(pipe);
    return 0;
}
