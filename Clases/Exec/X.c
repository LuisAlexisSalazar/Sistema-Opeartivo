#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h>

int main(int argc,char *argv[]) 
{ 
    int i; 
      
    printf("Hola yo soy X.c llamado por execvp() \n");

    printf("X.exe Proceses ID = %d\n",getpid());
    

    //Impresion de Argumentos
    printf("Parametro 0 = %s\n",argv[0]);    
    printf("Parametro 1 = %s\n",argv[1]);

    printf("\n"); 
      
    return 0; 
} 
