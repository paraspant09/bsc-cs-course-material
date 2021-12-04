





#include<iostream>

#include<stdlib.h>

void kernalVersion();

void cpuInfo();

void memInfo();

using namespace std;



int main()

{



  kernalVersion();

  cpuInfo();

  memInfo();

 

}

void kernalVersion()

{

   system("grep ' Kernal Version: ' SystemInfo.cpp |awk '{print  $3 $4}'");

   system("cat /proc/sys/kernel/osrelease");

  // system("cat /proc/version");

}

void cpuInfo()

{

   system("echo 'CPU_name_and_model: '");

   system("grep -m1 'model name' /proc/cpuinfo ");

   system("cat /proc/cpuinfo | grep -m1 cpu");

   system("cat /proc/cpuinfo | grep -m1 model");

}

void memInfo()

{

    system("echo ' Total_Memory: ' ");

    system("grep 'MemTotal' /proc/meminfo | awk '{print $2 $3}'");

    

    system("echo ' Available_Memory: ' ");

    system("grep 'MemAvailable' /proc/meminfo | awk '{print $2 $3}'");



   /* system("echo '\nVirtual Memory Statistics'");

    system("vmstat -s | grep -m1 used");

    system("free -m");*/

}


