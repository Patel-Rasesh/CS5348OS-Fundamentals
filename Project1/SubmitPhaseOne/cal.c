#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "INIT.H"
#define MAX_LINE_LENGTH 80

int main (int argc, char **argv) {
   char *inputFile = argv[1];
   FILE *file = fopen(inputFile, "r");
   char inputTest[100];
   const char s[2] = " ";
   char *token;
   
   char *supp_ptr = NULL;
   char *lines = fgets(inputTest, MAX_LINE_LENGTH, file);
   int numberOfLines = strtol(lines, &supp_ptr, 10);
   supp_ptr = NULL;
   while(numberOfLines != 0){
       fgets(inputTest, MAX_LINE_LENGTH, file);
       char *command = (char *) malloc(sizeof(char *));
       char *operand1 = (char *) malloc(sizeof(char *));
       char *operand2 = (char *) malloc(sizeof(char *));
       if((NULL == command) || (NULL == operand1) || (NULL == operand2)){
           return 0;
        }
       token = strtok(inputTest, s);
       strcpy(command, token);
       token = strtok(NULL, s);
       strcpy(operand1, token);  
       token = strtok(NULL, s); 
       strcpy(operand2, token);  
       int op1 = strtol(operand1, &supp_ptr, 10);
       supp_ptr = NULL;
       int op2 = strtol(operand2, &supp_ptr, 10);
       supp_ptr = NULL;
       if(strcmp(command, "quadratic") == 0){
           printf("Entered in quadratic");
           solve_quadratic(op1, op2);
           printf("\n");
       }
       else if(strcmp(command, "triples") == 0){
           printf("Entered in triples");
           find_triples(op1, op2);
           printf("\n");
       }
       else if(strcmp(command, "mod-sum") == 0){
           printf("Entered in modular-sum");
           modular_sum(op1, op2);
           printf("\n");
       }
       else{
           printf("Invalid command");
           return 0;
       }
       numberOfLines--;
       free(command);
       free(operand1);
       free(operand2);
       command = operand1 = operand2 = NULL;
       memset(&inputTest, 0, sizeof(inputTest));
   }
   return(0);
}