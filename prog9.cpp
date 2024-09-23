#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>

void char_time(const char *str){
	const char *ptr;
	int c;
	for(ptr = str; (c = *ptr++) != 0;){
		putc(c, stdout);
	}
}

int main(){
	pid_t pid;
	
	if((pid = fork()) == -1){
		perror("fork error...");
		return 1;
	}
	
	if(pid == 0){
		char_time("child is writing to terminal...");
	}
	
	if(pid > 0){
		char_time("parent is writing to terminal...");
	}
}
