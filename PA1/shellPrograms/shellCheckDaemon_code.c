#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{
    char *buffer = NULL;
    size_t line_size, size = 0;

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
    for (;;)
    {
        if (system(command) != -1) break;
    }

   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
    FILE *fp = fopen("output.txt", "r");
    if (fp != NULL)
    {
        // 2. Fetch line by line using getline()
        while ((line_size = getline(&buffer, &size, fp)) != -1) {
            // 3. Increase the daemon count whenever we encounter a line
            live_daemons++;
            fwrite(buffer, line_size, 1, stdout);
        };
    }

   // 4. Close the file
    fclose(fp);

   // 5. print your result

   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }


   // TODO: close any file pointers and free any statically allocated memory
   free(command);

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}