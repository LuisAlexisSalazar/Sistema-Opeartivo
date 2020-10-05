// gcc -o wait.exe wait.c
// ./wait.exe
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 


void waitexample() 
{ 
	int stat; 

  
	if (fork() == 0) {
        char *args[]={"./division.exe",NULL}; 
        execvp(args[0],args); 
    }
		 
  
	else
		wait(&stat); 

        if (WIFEXITED(stat)) 
            printf("Exit status: %d\n", WEXITSTATUS(stat)); 
		else if (WIFSIGNALED(stat)) 
		    psignal(WTERMSIG(stat), "Exit signal");
} 

// Driver code 
int main() 
{ 
	waitexample(); 
	return 0; 
}