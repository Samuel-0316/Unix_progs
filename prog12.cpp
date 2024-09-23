#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
	int pdfs[2];
	char buff[30];
	
	if((pipe(pdfs)) == -1){
		perror("pipe error...");
		exit(0);
	}
	
	cout<<"writing to file descrp  "<<pdfs[1]<<endl;
	write(pdfs[1],"samuel", 5);
	
	cout<<"reading from the file descrp  "<<pdfs[0]<<endl;
	read(pdfs[0], buff, 5);
	
	cout<<"reading in buffer:  "<<buff<<endl;
	return 0;
}
