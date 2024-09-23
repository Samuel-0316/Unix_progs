#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 3){
		cout<<"usage: source link";
		exit(0);
	}
	
	if(( link( argv[1], argv[2] )) == -1)
		perror("link error!!");
	
	else
		cout<<"link has been created with "<<argv[2];
	
	return 0;
}

/*
int main(int argc, char *argv[]){
	if(argc <= 1){
		cout<<"usage:: filename1 filename2..";
	}
	
	for(int i = 1; i < argc; i++){
		if((unlink(argv[i])) == -1){
			perror("delete error...");
		}
		else{
			cout<<"the file "<<argv[i]<<" deleted";
		}
	}
	return 0;
}
*/


/*
int main(int argc, char *argv[]){
	if(argc != 3){
		cout<<"usage:: souce link";
		exit(0);
	}
	
	if((link(argv[1], argv[2])) == -1){
		perror("link error...");
	}
	else{
		unlink(argv[1]);
	}
	return 0;
}
*/
