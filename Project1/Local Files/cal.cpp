#define MAX_LINE_LENGTH 80
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "quadratic.c"
#include "triples.c"
#include "sum.c"
#include <cstring>

using namespace std;
// TODO
// Include compile commands in a make file
// Run make file from the shell script
// To use make commands we require Linux distribution - either WSL or install in remote

int main(int argc, char **argv){
    char *ptr;
    char *inputFile = argv[1];
    char testText[MAX_LINE_LENGTH] = {0};
    FILE *file = fopen(inputFile, "r");
    char *numberOfLines = fgets(testText, MAX_LINE_LENGTH, file);
    int lines = strtol(numberOfLines, &ptr, 10);
    cout << "Printing the number of lines : " << numberOfLines << endl;
    while(0 != lines){
        fgets(testText, MAX_LINE_LENGTH, file);
        lines--;
        string command;
        int i;
        for(i=0; i<strlen(testText); i++){
            if(testText[i] == ' '){
                cout << command << endl;
                i++;
                break;
            }
            else{
                command += testText[i];
            }
        }
        //char *operand1 = NULL;
        string operand1 = "";
        for(i; i<strlen(testText); i++){
            if(testText[i] == ' '){
                cout << operand1 << endl;
                i++;
                break;
            }
            else{
                operand1 += testText[i];
            }
        }
        char *operand1Input = strdup((const char*)operand1);
        // if(NULL == operand1Input){
        //     return 0;
        // }

        memcpy(operand1Input,&operand1,sizeof(operand1));

        cout << "test Print" << " " << operand1Input << endl;
        int op1 = strtol(operand1Input, &ptr, 10);
        
        cout << op1 <<endl; 
        string operand2 = "";
        for(i; i<=strlen(testText); i++){
            if(testText[i] == ' ' || testText[i] == '\n'){
                break;
            }
            else{
                operand2 += testText[i];
            }
        }
        char *operand2Input = (char *) malloc(sizeof(operand2));
         if(NULL == operand2Input){
            return 0;
        }

        memcpy(operand2Input,&operand2,sizeof(operand2));

        int op2 = strtol(operand2Input, &ptr, 10);
        //int op2 = strtol(operand2, &ptr, 10);
        if(command == "quadratic"){
            cout << "Runnig quadratic function with " << op1 << " and " << op2 << endl;
            solve_quadratic(op1, op2);
        }
        // else if(command == "triples"){
        //     cout << "Finding triples with " << op1 << " and " << op2 << endl;
        //     find_triples(op1, op2);
        // }
        // else if(command == "mod-sum"){
        //     cout << "Runnig modular sum function with " << op1 << " and " << op2 << endl;
        //     modular_sum(op1, op2);
        //}
        else{
            cout << "Throw an exception"<< endl;
        }
    }
    fclose(file);
}
