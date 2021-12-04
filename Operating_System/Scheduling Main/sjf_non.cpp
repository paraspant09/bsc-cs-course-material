//sjf non preemptive
#include <iostream>
using namespace std;  

int main()
{
    int burst_time[20],process[20],waiting_time[20],tat[20];
	int i,j,n,total=0,temp;
    float wait_avg,TAT_avg;
 
    cout<<"Enter number of process: ";
    cin>>n;
    cout<<"\nEnter Burst time: \n";
    for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;      //Process Number
    }
//Sorting
       for(i=0;i<n-1;i++)
    	{
        	for(j=i+1;j<n;j++)
        	{
        	    if(burst_time[j]<burst_time[i])
        		{			
        			temp=burst_time[i];
        			burst_time[i]=burst_time[j];
       				burst_time[j]=temp;

        			temp=process[i];
        			process[i]=process[j];
        			process[j]=temp;
				}
        	}
    	}
    //First process has 0 waiting time 
    waiting_time[0]=0;           

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
      wait_avg=(float)total/n;
      total=0;

   cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i]; 	//Calculating Turnaround Time     
        total+=tat[i];
        cout<<"\np"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<tat[i];
    }
    TAT_avg=(float)total/n;    
    cout<<"\n\nAverage Waiting Time: "<<wait_avg;
    cout<<"\nAverage Turnaround Time: "<<TAT_avg;
    return 0;
}
