// C program to demonstrate working of status 
// from wait. 
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 

void waitexample() 
{ 
	int stat; 


	if (fork() == 0) 
		exit(1); 
    //else padre
	else
        //Captura el estado con el qeu acabo
		wait(&stat); 

    //Si el programa termino normalmente
	if (WIFEXITED(stat)) 
		printf("Exit status: %d\n", WEXITSTATUS(stat)); 
    //Solicitu una señalización    
	else if (WIFSIGNALED(stat)) 
		psignal(WTERMSIG(stat), "Exit signal"); 
}

// Driver code 
int main() 
{ 
	waitexample(); 
	return 0; 
} 
