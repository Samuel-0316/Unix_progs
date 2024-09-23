// 1. Catch the signal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>

using namespace std;


int main(){
	signal(SIGINT, SIG_IGN);
	while(1)
		cout<<"samuel \t";
	return 0;
}


// 2. Taking default action
/*#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
	signal(SIGINT, SIG_DFL);
	while(1)
		cout<<"hello\t";
}*/


// 3. Ignore the Signal
/*#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
	signal(SIGINT, SIG_IGN);
	while(1)
		cout<<"hello\t";
}*/
