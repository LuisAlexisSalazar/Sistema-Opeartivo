//g++ -o Wait.exe  Wait.cpp 
// ./Wait.exe


#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include <cassert>
#include<iostream>
using namespace std;



template <size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == NULL));

  return execvp(file, const_cast<char* const*>(argv));
}



void waitexample() 
{ 
	int stat; 

    const char* const args[]={"-al",NULL}; 
    //Si eres hijo ejecutar programa Division.exe
	if (fork() == 0) {
        execvp("./Division.exe",args); 
    }
		 
    //Ejecución de Padre
	else
        //Captura el estado
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