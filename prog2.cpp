#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	int n,fd1,fd2;
	char buff[10];

	if(argc != 3){
		cout<<"usage:: source dist";
		exit(1);
	}
	
	if((fd1 = open(argv[1], O_RDONLY)) == -1){
		cout<<"can't open the file... for reading";
		exit(0);
	}
	
	if((fd2 = open(argv[2], O_WRONLY)) == -1){
		cout<<"can't open the file for writing...";
		exit(0);
	}
	
	while((n = read(fd1, buff, 1)) > 0){
		write(1, buff, n);
		write(fd2, buff, n);
	}
	
	close(fd1);
	close(fd2);
	return 0;
}
