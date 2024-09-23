#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[]){
	int fd,n,skval;
	char c;
	
	if(argc != 2){
		cout<<"usage:: filename";
		exit(1);
	}
	
	if((fd = open(argv[1], O_RDONLY)) == -1){
		cout<<"can't open the file for reading...";
		exit(0);
	}

	while((n = read(fd, &c, 1)) == 1){
		cout<<"\n char:  "<<c;
		skval = lseek(fd, 99, 1);
		cout<<"\n new seek value is:  "<<skval;
	}
	exit(0);
	return 0;
}
