#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    pid_t cpid; 


    if (fork()== 0) {
        printf("Child pid = %d\n", getpid()); 
        sleep(5);
        exit(0);     
    }      

    else{
        //Procesos Padre Espera al hijo
        cpid = wait(NULL); 
        }

    printf("Parent pid = %d\n", getpid());
    //Imprime el pid del hijo desde el proceso padre 
    printf("Child pid = %d\n", cpid); 
  
    return 0; 
} 