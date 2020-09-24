#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdlib.h>
#include<sys/wait.h> 

void forkexample() 
{ 
    // Determinar si eres el papa o el hijo
    // Si es 0 es hijo sino seria padre 
    if (fork() == 0){
        printf("Hola desde Hijo!\n"); 
        printf("Hijo Proceses ID = %d\n",getpid());

        sleep(5);
        
    }
    else{
        printf("Hola desde Papá!\n");
        printf("Papá Proceses ID = %d\n",getpid());
    } 
} 


int main() 
{ 
    forkexample(); 
    return 0; 
} 