  
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 


int main() 
{ 
    printf("my_Exec Proceses ID = %d\n",getpid());

    // char *args[]={"./X.exe","A1","A2","A3",NULL}; 

    char *args[]={"./X.exe","A1","A2","A3",NULL}; 

    execvp(args[0],args); 
      
    

    printf("my_Exec Proceses ID = %d\n",getpid());

    printf("Ending-----"); 
      
    return 0; 
}