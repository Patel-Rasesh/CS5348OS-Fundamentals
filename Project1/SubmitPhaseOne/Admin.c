#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "init.h"
#include "cal-new.c"
#define MAX_LINE_LENGTH 80

int main(int argc, char **argv) {

    int parentToChild[2];
    int childToParent[2];

    //string data
    char message1[200] = {'\0'};
    char readBuffer[120];
    pipe(parentToChild);
    pipe(childToParent);
    int processId , bytes;
    // Read count as the number of lines (line 1) from the input file
    char *supp_ptr = NULL;
    char inputTest[100];
    char *inputFile = argv[1];
    FILE *file = fopen(inputFile, "r");
    char *lines = fgets(inputTest, MAX_LINE_LENGTH, file);
    int numberOfLines = strtol(lines, &supp_ptr, 10);
    if((processId = fork())== -1){
        printf("error while creating a child process");
    }
    
    if(processId == 0){
        //child process here
        //send message from child to parent

        //recive message from parent
        while(numberOfLines != 0){
            
            close(parentToChild[1]);
            bytes = read(parentToChild[0] , readBuffer , sizeof(readBuffer));
            printf("Parent to Child - command: %s", readBuffer);
            
            // Read command from parentToChild pipe and execute it in cal process
            printf("\t\t Executing the command now ---- ");
            cal_function(readBuffer);

            strcat(message1, "OK status : ");
            strcat(message1, readBuffer);
            strcat(message1, "\n");
            close(childToParent[0]);
            write(childToParent[1] , message1 , strlen(message1)+1);
            for(int i=0; i<=sizeof(message1); i++){
                message1[i]='\0';
            }
            numberOfLines--;
        }
        // exit(1);
    }

    if(processId !=0 ){
        
        // Number of Lines if the first line from the input file
        while(numberOfLines != 0){

            close(parentToChild[0]);
            fgets(inputTest, MAX_LINE_LENGTH, file);
            write(parentToChild[1] , inputTest , strlen(inputTest)+1);

            //receive message from child
            close(childToParent[1]);
            bytes = read(childToParent[0] , readBuffer , sizeof(readBuffer));

            printf("Child to Parent - acknowledgment : ");
            printf("%s", readBuffer);
            printf("-------------------------------------------------------------------------------------------------\n");
            // exit(1);
            numberOfLines--;
        }
    }

    return 0;
}