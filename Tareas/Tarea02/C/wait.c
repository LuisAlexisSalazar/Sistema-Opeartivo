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
} 

// Driver code 
int main() 
{ 
	waitexample(); 
	return 0; 
}