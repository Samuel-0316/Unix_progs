#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//USING FORK()

/*int main(){

	pid_t pid;
	cout<<"\n Original Process:"<<getpid()<<"\tParent Process:"<<getppid()<<endl;
	
	if ((pid = fork()) == -1){
		perror("Fork Error");
		exit(0);
	}
	
	if (pid == 0) {						
		cout<<"\n Child Process: "<<getpid()<<"\tParent Process:"<<getppid()<<endl;
	}
	
	if (pid > 0) { 						
		cout<<"\n Original Process:"<<getpid()<<"\tParent Process:"<< getppid() <<endl;
	}
	
	cout<<"\n end of Main\n";
	
	return 0;
}
*/


//USING VFORK()


int main(){
	pid_t pid;
	
	cout<<"original process: "<<getpid()<<" parent process: "<<getppid()<<endl;
	
	if((pid = fork()) == -1){
		perror("fork error...");
		exit(0);
	}
	
	if(pid == 0){
		cout<<"\n child process: "<<getpid()<<" parent process: "<<getppid()<<endl;
	}
	
	if(pid > 0){
		cout<<"\n original process: "<<getpid()<<" parent process: "<<getppid()<<endl;
	}
	return 0;
}
