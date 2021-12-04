#include<iostream>
using namespace std;
int main()
{
	int n,p[10],at[10],bt[10],rt[10],tat[10],ct[10],wt[10],pr[10];
	int tbt=0;
	cout<<" enter te number of processes\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]";
		p[i]=i+1;
		cout<<"\narrival time\n";
		cin>>at[i];
		cout<<"\nenter burst time\n";
		cin>>bt[i];
		rt[i]=bt[i];
		tbt+=bt[i];
	}
	int max=0;
	for(int i=1;i<n;i++)
	{
		if(rt[i]>rt[max])
			max=i;
	}
	for(int time=0;time<tbt;)
	{
		for(int i=0;i<n;i++)
			if(rt[i]>0&&at[i]<=time&&bt[i]<bt[max])
				max=i;
			rt[max]--;
			time++;
			if(rt[max]==0)
			{
				ct[max]=time;
				wt[max]=time-at[max]-bt[max];
				tat[max]=time-at[max];
				for(int i=0;i<n;i++)
					if(bt[i]>bt[max])
					max=i;
			}
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<"  ::"<<bt[i]<<"  ::"<<at[i]<<"  ::"<<ct[i]<<"  ::"<<wt[i]<<"  ::"<<tat[i]<<"\n";
	}
}
