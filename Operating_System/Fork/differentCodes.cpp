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
	else if(pid==0)
	cout<<"Executing Child Process "<<pid<<endl;
	else
	cout<<"Executing Parent Process"<<pid<<endl;
}
