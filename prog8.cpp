#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void pr_exit(int status){

	if (WIFEXITED(status))
		cout<<"\n Normal termination, exit status ="<< WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		cout <<"\nAbnormal termination, signal number = "<<WTERMSIG(status);
	else if (WIFSTOPPED(status))
		cout<<"\nChild stopped, signal number = "<<WSTOPSIG(status);
		
}


int main(){

	pid_t pid, childpid;
	
	int status;
	
	if ((pid = fork()) == -1){
		perror("\nFork Error");
		return 0;
	}
	
	if(pid == 0)
		exit(23);
	childpid=wait(&status);
	pr_exit(status);
	
	if ((pid = fork()) == -1){
		perror("\nFork Error");
		return 0;
	}
	
	if(pid == 0)
		abort();
	childpid=wait(&status);
	pr_exit(status);
	
	if ((pid = fork()) == -1){
		perror("\nFork Error");
		return 0;
	}
	
	if(pid == 0)
		//int res = 5/0;
	childpid=wait(&status);
	pr_exit(status);
	return 0;
	
}
