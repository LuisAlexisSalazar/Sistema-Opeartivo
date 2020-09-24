#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 

#include<iostream>
using namespace std;

void waitexample() 
{ 
	int stat; 

    //Si eres hijo ejecutar programa Division.exe
	if (fork() == 0) {
        char *args[]={"./Division.exe",NULL}; 
        execvp(args[0],args); 
    }
		 
    //Ejecución de Padre
	else
        //Captura el estado
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