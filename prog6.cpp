#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

int main(){
	pid_t pid;
	
	if((pid = fork()) == -1){
		perror("fork error...");
		exit(0);
	}
	
	if(pid == 0){
		cout<<"child: "<<getpid()<<" waiting for parent...\n";
	}
	if(pid > 0){
		cout<<"\n parent:  "<<getpid();
		system("ps u");
	}
	return 0;
}
