#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{
    int count = 0;
    char *buffer = NULL;
    size_t size = 0;

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    FILE *fp = fopen(args[1], "r");
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file '%s'\n", args[1]);
        return EXIT_FAILURE;
    }

    while (getline(&buffer, &size, fp) >= 0) {
        // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
        count++;
    };

    free(buffer);
    buffer = NULL;
    // 6. Close the FILE*
    fclose(fp);
    // 7. Print out how many lines are there in this particular filename
    printf("There are %d lines in %s\n", count, args[1]);
    // 8. Return 1, to exit program
    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}