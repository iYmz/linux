//////////////////////////////////////////////////////////////////
//author:TwinkleN1
//email:qq941903680@outlook.com
//2018-6-5 14:00:40
//description:
//	simulating a shell which could accept a command ,
// 	it will fork a child to excute.
//	if accept "exit',child process will exit 
//	and returns status 0 to parent process
//	to stop the parent process. 
/////////////////////////////////////////////////////////////////
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#define TRUE 1
#define FALSE 0

#define UNKONWCOMMAND -1
void type_prompt();
int main()
{

type_prompt();
char command[256];
int status;

while(TRUE)
{
	if(fork()!=0)
	{
	waitpid(-1,&status,0);
  	if(!status)
		exit(0);
	}
	else
	{
	read_command(command);
	int suchi=0;
	suchi=strcmp(command,"exit");
	if(!suchi)
	{
	system("echo Goodbye!");
	exit(0);
	}
	else
	system(command);
	
	}
}

return 0;
}


void type_prompt(){
system("echo Simulate_Shell:\r");
}
int read_command(char *cmd){
if(gets(cmd)!=NULL)return TRUE;
else return FALSE;
}
else return FALSE;
}
