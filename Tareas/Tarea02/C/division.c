//gcc -o division.exe division.c
//Ejecución sera en ./wait.exe
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  

int main(int argc,char *argv[]){
    int i=0;

    int j=5/i;
    exit(5/i);
}