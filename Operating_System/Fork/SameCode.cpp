#include <unistd.h>
#include<sys/types.h>	
#include<iostream>
using namespace std;
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	cout<<"Fork Failed"<<pid<<endl;
/*	else if(pid==0)
	cout<<"PId of the child process is: "<<pid<<endl;
	else 
	cout<<"PId of the parent process is: "<<pid<<endl;*/
	cout<<"Forking\n";
}
