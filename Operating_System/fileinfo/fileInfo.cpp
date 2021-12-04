#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
#include<time.h>
void displayTime(long);
using namespace std;

int main(int argc,char*argv[])
{
  struct stat statBuf;
  struct passwd *pass;
  
 if(stat(argv[1],&statBuf)<0){
  cout<<"Error!";
  return 1;
}

  cout<<"Owner id: "<<statBuf.st_uid;
  pass=getpwuid(statBuf.st_uid);
  cout<<endl<<"Name: "<<pass->pw_name<<endl;

 cout<<endl<<"ACCESS PERMISSIONS"<<endl;
 cout<<"OWNER: ";

 if((statBuf.st_mode && S_IRUSR))
   cout<<"r";
  else
   cout<<"_";
if(statBuf.st_mode && S_IWUSR)
  cout<<"w";
else
  cout<<"_";
if(statBuf.st_mode && S_IXUSR)
  cout<<"x";
else
  cout<<"_";


cout<<endl<<"GROUP: ";
if((statBuf.st_mode && S_IRGRP))
   cout<<"r";
  else
   cout<<"_";
if(statBuf.st_mode && S_IWGRP)
  cout<<"w";
else
  cout<<"_";
if(statBuf.st_mode && S_IXGRP)
  cout<<"x";
else
  cout<<"_";


cout<<endl<<"OTHERS: ";
if((statBuf.st_mode && S_IROTH))
   cout<<"r";
  else
   cout<<"_";
if(statBuf.st_mode && S_IWOTH)
  cout<<"w";
else
  cout<<"_";
if(statBuf.st_mode && S_IXOTH)
  cout<<"x";
else
  cout<<"_";


cout<<endl;

cout<<endl<<"ACCESS TIME";

cout<<endl<<"Last Access: "; displayTime(statBuf.st_atime);
cout<<endl<<"Last modification: "; displayTime(statBuf.st_mtime);
cout<<endl<<"Last status change: "; displayTime(statBuf.st_ctime);
cout<<endl;
}

void displayTime(long l){

struct tm *tp=localtime(&l);
cout<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec<<"     "<<tp->tm_mday<<"/"<<tp->tm_mon+1<<"/"<<tp->tm_year+1900;

}
















