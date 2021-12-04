#include<iostream>
using namespace std; 

int main() 
{ 
  int x,j,n,k=1,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  cin>>n; 
  remain=n; 
  
  for(x=0;x<n;x++) 
  { 
    cout<<"Enter Arrival Time and Burst Time for Process Process Number :"<<x+1<<endl; 
    cin>>at[x]; 
    cin>>bt[x]; 
    rt[x]=bt[x]; 
  } 
  printf("Enter Time Quantum:\t"); 
  cin>>time_quantum; 
  
  cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n"; 
  for(time=0,x=0;remain!=0;) 
  { 
    if(rt[x]<=time_quantum && rt[x]>0) 
    { 
      time+=rt[x]; 
      rt[x]=0; 
      flag=1; 
    } 
    else if(rt[x]>0) 
    { 
      rt[x]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[x]==0 && flag==1) 
    { 
      remain--; 
      cout<<"p["<<x+1<<"]"<<"\t\t"<<time-at[x]<<"\t\t"<<time-at[x]-bt[x]<<endl; 
      wait_time+=time-at[x]-bt[x]; 
      turnaround_time+=time-at[x]; 
      flag=0; 
    } 
    if(x==n-1) 
      x=0; 
    else if(at[x+1]<=time) 
      x++; 
    else 
      x=0; 
  } 
  cout<<"\nAverage Waiting Time= "<<wait_time/n<<endl; 
  cout<<"Avg Turnaround Time = "<<turnaround_time/n<<endl; 
  return 0; 
}

