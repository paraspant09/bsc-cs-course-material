#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>

int main()
{
  const int size=4096;
  const char*name="OS";
 

  int id;
  void*ptr;
  id=shm_open(name,O_RDONLY,0);
  ptr=mmap(0,size,PROT_READ,MAP_SHARED,id,0);
  
 printf("%s",(char*)ptr);
 shm_unlink(name);
  return 0;
}
