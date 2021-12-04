#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>


void *runner(void*);
int main(int argc,char* argv[])
{
  pthread_t id;
  pthread_attr_t attr;
  
  if(argc!=2)
  {
    printf("%s","No argument passed");
    return 0;
  }
  if(atoi(argv[1])<0)
  {
    printf("%s","Argument must be positive");
    return 0;
   }
   
  pthread_attr_init(&attr);
  pthread_create(&id,&attr,&runner,argv[1]);
  pthread_join(id,NULL);
   
}

void* runner(void *param)
{
  char* times=(char*)param;
  int len=atoi(times),i;
  for(i=0;i<len;i++)
  {
  printf("%s","Paras");
  printf("%d",i+1);
  printf("\n");
   }
  pthread_exit(0);
}
