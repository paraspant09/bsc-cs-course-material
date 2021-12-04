#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>	
#include<iostream>
using namespace std;
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	cout<<"Fork failed"<<endl;
	else if(pid==0)
	{
           cout<<endl<<"Child Executing........"<<endl;
          execlp("/bin/ls","ls",NULL);
       
        }
	else
       {
        wait(NULL);
	cout<<endl<<"Parent Executing........ "<<endl;
       }
}
