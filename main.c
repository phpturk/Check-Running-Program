#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <libgen.h>


int check_program(char *program_name)
{
	char program_path[256];
	char *real_path = realpath(program_name, program_path);
	char popen_command[120];
	sprintf(popen_command, "pidof %s", basename(program_path));
	char line[200];
	FILE * command = popen(popen_command,"r");
	fgets(line,100,command);
	char *token;
   token = strtok(line, " ");
   int counter = 0;
   while( token != NULL ) {
      token = strtok(NULL, " ");
      counter++;
   }
	return counter;
	pclose(command);	
}

int main(int argc, char* argv[]) 
{
	int active_pid = check_program(argv[0]);
	if(active_pid  < 2)
	{
		while(1)
		{
			printf("Program Başladı = %d\n", active_pid);
			sleep(3);
		}		
	}
   return 0;
}
