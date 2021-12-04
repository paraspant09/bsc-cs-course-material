#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
  int sfd,tfd;
  char sfname[20];
  char tfname[20];
  char buffer[50];
  cout<<"Enter the source file name: ";
  cin>>sfname;
  cin.clear();
  cout<<"Enter the target file name: ";
  cin>>tfname;
  sfd=open(sfname,O_RDONLY);
  tfd=open(tfname,O_CREAT|O_WRONLY);
  if(sfd<0)
    { 
      cout<<"Error in opening source file";
      return 0;
    }
   if(tfd<0)
    { 
      cout<<"Error in opening target file";
      return 1;
    }

  int i=0;
   while(read(sfd,buffer,strlen(buffer)))
   {
    i++;
    write(tfd,buffer,strlen(buffer));
   }
    


  if(close(sfd))
   {
     cout<<"Error while closing source file";
     return 2;
   }
   if(close(tfd))
   {
    cout<<"Error while closing target file";
    return 3;
   }
  cout<<"file copied";
  cout<<endl;

}
