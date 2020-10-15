

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string>
#include<vector>
#include <queue> 
#include<fcntl.h> 
#include <signal.h>

using namespace std;

//maximo 10
queue<string>historial;

//Fucion que devuelve la matriz separados por espacios
char **get_input(char *input) {

    char **command = new char*;

    string temp(input);
    
    //Actualizar la entrada como el ultimo comando puesto
    

    if (temp=="!!"){
        if (historial.size()==0)
            cout<<"No hay Comandos en Historial"<<endl;
        else
            strcpy(input,(historial.back()).c_str());
    }

    //Redireccionar Salida a un archivo
    int pos = temp.find(" > ");
    if ( pos !=-1)
    {
        string Comando=temp.substr(0,pos);
        string Descriptor=temp.substr(pos+3);

        int out = open(Descriptor.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

        //Cambiar salida de la consola a archivo
        dup2(out, 1) ; 
        strcpy(input,Comando.c_str());
    }
    
    //Entrada
    pos = temp.find(" < ");
    if ( pos !=-1)
    {
        string Comando=temp.substr(0,pos);
        string Descriptor=temp.substr(pos+3);

        Comando= Comando + " " + Descriptor;

        strcpy(input,Comando.c_str());
    }


    //Signal
    pos = temp.find("parar ");
    if ( pos !=-1)
    {
        
        string pidString=temp.substr(pos+6);
        int pid=stoi(pidString.c_str());

        kill(pid, SIGSTOP); 
    }

    
    pos = temp.find("continuar ");
    if ( pos !=-1)
    {
        string pidString=temp.substr(pos+10);
      
        int pid=stoi(pidString.c_str());
        kill(pid, SIGCONT); 
    }


    /*
    pos=temp.find("&");
    if (pos!=-1)
    {
        pid_t child_pid;
        string Comando=temp.substr(0,pos);
        string Descriptor=temp.substr(pos+3);

        child_pid = fork();

        //Proceso del Hijo
        if (child_pid == 0) {
            execvp(command[0], command);
            
        } else {
            //Esperamos al hijo
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }
    }
    */
    


    if (historial.size()<10){
        historial.push(temp);
    }
    
    else {
        historial.pop();
        historial.push(temp);
    }

    char *parsed;
    int index = 0;
    char separator[]=" ";

    parsed = strtok(input, separator);

    while (parsed != NULL) {
        command[index] = parsed;
        index++;
        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;

    if (input[0]=='h'){
        queue<string> second (historial);
        int i=1;
        while (!second.empty()){
            cout<<i<<":"<<second.front()<<endl;
            second.pop();
            i++;
        }
    }
    
    
    return command;
}



int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) {
        input = readline("osh> ");
        command = get_input(input);
       
        if (!command[0]) {   
            free(input);
            free(command);
            continue;
        }

        child_pid = fork();

        //Proceso del Hijo
        if (child_pid == 0) {
            execvp(command[0], command);
            
        } else {
            //Esperamos al hijo
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }
      
        free(input);
        free(command);
    }

    return 0;
}

