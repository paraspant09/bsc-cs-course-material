#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
  const int size=4096;
  const char*name="OS";
  const char*msg1="Hello";
  const char*msg2="World";

  int id;
  void*ptr;
  id=shm_open(name,O_CREAT | O_RDWR,0);
  ftruncate(id,size);
  ptr=mmap(0,size,PROT_WRITE,MAP_SHARED,id,0);
  
  sprintf(ptr,"%s",msg1);
  ptr+=strlen(msg1);
  sprintf(ptr,"%s",msg2);
  ptr+=strlen(msg2);
  return 0;
}
