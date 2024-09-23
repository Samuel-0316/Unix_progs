#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	struct stat sb;
	
	if (argc != 2) {
		cout<<"Usage: ./a.out FileName \n";
		exit(0);
	}
	
	if (stat(argv[1], &sb) == -1) {
		perror("stat");
		exit(0);
	}
	
	cout<<"File: "<<argv[1]<<" is ";
	
	switch (sb.st_mode& S_IFMT) {
	
		case S_IFBLK: cout<<"Block device file \n";
			break;
		case S_IFCHR: cout<<"Character device file\n";
			break;
		case S_IFDIR: cout<<"Directory file\n";
			break;
		case S_IFIFO: cout<<"FIFO/pipe file\n";
			break;
		case S_IFLNK: cout<<"Symbolic link file \n";
			break;
		case S_IFREG: cout<<"Regular file \n";
			break;
		default: cout<<"Unknown file? \n";
		
	}
	
	cout<<"and its Inode number is : "<< sb.st_ino <<endl;
	return 0;
}
