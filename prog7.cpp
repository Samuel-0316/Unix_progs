#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(){

	pid_t pid;
	
	if((pid = fork()) == -1){
		perror("fork error...");
		exit(0);
	}
	
	if(pid == 0){
		cout<<"\n child:  "<<getpid()<<" orphan parent: "<<getppid()<<endl;
	}
	
	if(pid > 0){
		cout<<"original parent "<<getpid()<<endl;
	}
	return 0;
}
