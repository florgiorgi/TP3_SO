#include <stdlib.h>
#include <stdio.h>
#include <types.h>
#include <string.h>
#include <pipe.h>
#include "./include/processRead.h"

char * string1 = "Hola llegue";
char * string2 = "hola mundillo";

int main (void){
	int start = 0;
	int childPID;
	int pid;
	char firstString[20];
	char secondString[20];
	clear_screen();
	childPID = startProcess("processWrite");
	pid = pipe(childPID);
	
	printStaringMessageTest();

	do{
		start = 0;
		printf("To start the test please press 1 : ");
		getNum(&start);
	} while(start != 1);

	whenStringIsReceived(firstString,strlen(string1),pid);
	thenFirstStringIsReceived(firstString);

	printf("\nNow we are gonna read another string to check if IPC supports multiple readings\n");

	whenStringIsReceived(secondString,strlen(string2),pid);
	thenSecondStringIsReceived(secondString);

	do{
		start = 0;
		printf("\nTo finilize the test please press 1 : ");
		getNum(&start);
	}while(start != 1);
	clear_screen();
	exitProcess();
	return 0;
}

void printStaringMessageTest(){
	printf("			---------------IPC TEST---------------\n\n");
	printf("The test consists in read 2 times from a pipe\n");
	printf("The test will succed only if both strings are the expected ones\n\n");
}

void whenStringIsReceived(char * firstString, int charsToRead, int pid){
	read(pid,firstString,charsToRead);
}

void thenFirstStringIsReceived(char * firstString){
	if(strcmp(firstString,string1)){
		printf("\nSUCCESS!!!!! --------- First string received: %s\n",firstString);
	}else{
		printf("\nERROR!!!!! --------- First string received: %s\n",firstString);
	}
}

void thenSecondStringIsReceived(char * secondString){
	if(strcmp(secondString,string2)){
		printf("\nSUCCESS!!!!! --------- Second string received: %s\n",secondString);
	}else{
		printf("\nERROR!!!!! --------- Second string received: %s\n",secondString);
	}
}

