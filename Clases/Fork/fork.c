
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
    fork(); //Genera 2 procesos hijo y papa es decir 2 hola mundo
  
    printf("Hello world!\n"); 
    return 0; 
} 



// #include <stdio.h> 
// #include <sys/types.h> 
// #include <unistd.h> 
// #include<stdlib.h>
// #include<sys/wait.h> 
// void forkexample() 
// { 
//     // Determinar si eres el papa o el hijo
//     // Si es 0 es hijo sino seria padre 
//     if (fork() == 0){
//         printf("Hello from Child!\n"); 
//         printf("Hijo Proceses ID = %d\n",getpid());

//         sleep(5);
        
//     }
//     else{
//         printf("Hello from Parent!\n");
//         printf("Papa Proceses ID = %d\n",getpid());
        
        
//     } 
// } 
// int main() 
// { 
//     forkexample(); 
//     return 0; 
// } 