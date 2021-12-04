#include<iostream>
using namespace std;
class Scheduling
{
	int *pro,*arv,*bur,*pri,n;
	int *wait,*tat;
	int **tmp;
	float wt,tt;
	int timer;
	int *queue;
	public:
	Scheduling()
	{
		cout<<"\nEnter Number of processes:";
		cin>>n;
		pro=new int[n];
		arv=new int[n];
		bur=new int[n];
		pri=new int[n];
		
		timer=wt=tt=0;
		queue=new int[n];
		for(int i=0;i<n;i++)
			queue[i]=-1;
		
		wait=new int[n];
		tat=new int[n];
			
		for(int b=0;b<n;b++)
			tat[b]=wait[b]=0;
		
		tmp=new int*[4];
		for(int i=0;i<4;i++)
		{
			tmp[i]=new int[n];
		}
	}
	void Table()
	{
		cout<<"\nProcesses	Arrival Times	Burst Times\n";
		for(int i=0;i<n;i++)
		{
			cout<<pro[i]<<"		"<<arv[i]<<"		"<<bur[i]<<endl;
		}
		cout<<endl;
	}
	void OutTable()
	{
		cout<<"\nProcesses	Arrival Times	Burst Times	Waiting Time	Turn around time\n";
		for(int i=0;i<n;i++)
		{
			cout<<pro[i]<<"		"<<arv[i]<<"		"<<bur[i]<<"		"<<wait[i]<<"		"<<tat[i]<<endl;
		}
		cout<<endl;
	}
	void TableWithPri()
	{
		cout<<"\nProcesses	Arrival Times	Burst Times	Priority\n";
		for(int i=0;i<n;i++)
		{
			cout<<pro[i]<<"		"<<arv[i]<<"		"<<bur[i]<<"		"<<pri[i]<<endl;
		}
		cout<<endl;
	}
	void OutTableWithPri()
	{
		cout<<"\nProcesses	Arrival Times	Burst Times	Priority	Waiting Time	Turn around time\n";
		for(int i=0;i<n;i++)
		{
			cout<<pro[i]<<"		"<<arv[i]<<"		"<<bur[i]<<"		"<<pri[i]<<"		"<<wait[i]<<"		"<<tat[i]<<endl;
		}
		cout<<endl;
	}
	void Output()
	{
		cout<<"\nAverage wating time is:"<<wt;
		cout<<"\nAverage turn around time is:"<<tt;
	}
	void Input()
	{
		for(int i=0;i<n;i++)
		{
			pro[i]=i+1;
		}
		cout<<"\nEnter Arrival time of processes:";
		for(int i=0;i<n;i++)
			cin>>arv[i];
		cout<<"\nEnter Burst time of processes:";
		for(int i=0;i<n;i++)
			cin>>bur[i];
				
		for(int i=0;i<n;i++)
		{
			tmp[0][i]=i+1;
			tmp[1][i]=arv[i];
			tmp[2][i]=bur[i];
		}
	}
	void InputPriority()
	{
		Input();
		cout<<"\nEnter Priorities of processes:";
		for(int i=0;i<n;i++)
		{
			cin>>pri[i];
			tmp[3][i]=pri[i];
		}
	}
	void Swap(int &a,int &b)
	{
		int k=a;
			a=b;
			b=k;
	}
	void AscAT()
	{
		int c;
		for(int i=0;i<n;i++)
		{
			c=0;
			for(int j=0;j<n-i-1;j++)
			{
				if(tmp[1][j]>tmp[1][j+1])
				{
					for(int k=0;k<3;k++)
						Swap(tmp[k][j],tmp[k][j+1]);
					c++;
				}
			}
			if(c==0)
				break;
		}
		for(int i=0;i<n;i++)
		{
			pro[i]=tmp[0][i];
			arv[i]=tmp[1][i];
			bur[i]=tmp[2][i];
		}
	}
	void AscATWithPri()
	{
		int c;
		for(int i=0;i<n;i++)
		{
			c=0;
			for(int j=0;j<n-i-1;j++)
			{
				if(tmp[1][j]>tmp[1][j+1])
				{
					for(int k=0;k<4;k++)
						Swap(tmp[k][j],tmp[k][j+1]);
					c++;
				}
			}
			if(c==0)
				break;
		}
		for(int i=0;i<n;i++)
		{
			pro[i]=tmp[0][i];
			arv[i]=tmp[1][i];
			bur[i]=tmp[2][i];
			pri[i]=tmp[3][i];
		}
	}
	void FCFS()
	{
		AscAT();
		int i=0,cpu=0;
		while(i!=n)
		{	
			if(cpu >= arv[i])
			{
			wait[i]=cpu-arv[i];
			tat[i]=wait[i]+bur[i];
			
			wt+=wait[i];
			tt+=tat[i];
			
			cpu+=bur[i];
			i++;
			}
			else
				cpu++;
		}
		wt=wt/n;
		tt=tt/n;
	}
	void SJFS()
	{
		AscAT();
		int min,ind,cpu=0;
		for(int i=0;i<n;i++)
		{	
			if(cpu >= arv[i])
			{
				if(i<n-1)
				{
				min=bur[i];
				ind=i;
				for(int j=i+1;j<n;j++)
				{
					if(arv[j]<=cpu)
					{
						if(bur[j]<min)
						{
							min=bur[j];
							ind=j;
						}
					}
					else
						break;
				}
				if(min != bur[i])
				{
				Swap(bur[ind],bur[i]);
				Swap(pro[ind],pro[i]);
				Swap(arv[ind],arv[i]);
				}
				
				}
						
				wait[i]=cpu-arv[i];
				tat[i]=wait[i]+bur[i];
						
				wt+=wait[i];
				tt+=tat[i];
				
				cpu+=bur[i];
			
			}
			else
			{
				cpu++;
				i--;
			}
		}
		wt=wt/n;
		tt=tt/n;
	}

	void Priority()
	{
		AscATWithPri();
		int min,ind,cpu=0;
		for(int i=0;i<n;i++)
		{	
			if(cpu >= arv[i])
			{		
				if(i<n-1)
				{
				min=pri[i];
				ind=i;
				for(int j=i+1;j<n;j++)
				{
					if(arv[j]<=cpu)
					{
						if(pri[j]<min)		//if > Higher number higher priority and if < vice versa.
						{
							min=pri[j];
							ind=j;
						}
					}
				}
				if(min != pri[i])
				{
				Swap(bur[ind],bur[i]);
				Swap(pro[ind],pro[i]);
				Swap(arv[ind],arv[i]);
				Swap(pri[ind],pri[i]);
				}
				}
				
				wait[i]=cpu-arv[i];
				tat[i]=wait[i]+bur[i];
						
				wt+=wait[i];
				tt+=tat[i];
				
				cpu+=bur[i];
				
			//	TableWithPri();
			}
			else
			{
				cpu++;
				i--;
			}
		}
		wt=wt/n;
		tt=tt/n;	
		
	}
	bool CheckForBT()
	{
		for(int i=0;i<n;i++)
			if(tmp[2][i]!=0)
				return true;
		return false;
	}
	void SJFS_P()
	{
		AscAT();
		int min,ind,cpu=0;
		int i=0;
		while(CheckForBT())
		{	
			if(cpu >= arv[i])
			{
			if(i<n-1)
			{
				min=tmp[2][i];
				ind=i;
				for(int j=i+1;j<n;j++)		//j!=i;j=(++j)%n) is not neceesary becoz i++ will not happen until process at i is not become 0 by BT
				{
					if(arv[j]<=cpu)
					{
						if(tmp[2][j]<min)		//&& tmp[2][j]!=0) also not necessary
						{
							min=tmp[2][j];
							ind=j;
						}
					}
				}

				if(min != tmp[2][i])
				{
				Swap(bur[ind],bur[i]);
				Swap(pro[ind],pro[i]);
				Swap(arv[ind],arv[i]);
				Swap(pri[ind],pri[i]);
				Swap(tmp[2][ind],tmp[2][i]);
				}	
			}
				cpu++;
				tmp[2][i]--;
				
				if(tmp[2][i]==0)
				{
				wait[i]=cpu-arv[i]-bur[i];	//exit time - entry time - cpuusage time = waiting time
				tat[i]+=wait[i]+bur[i];
				
				wt+=wait[i];
				tt+=tat[i];
				
				i++;
				}
		}
		else
		{
			cpu++;
		}
		}
		wt=wt/n;
		tt=tt/n;
	}
	void Priority_P()
	{
		AscATWithPri();
		int min,ind,cpu=0;
		int i=0;
		while(CheckForBT())
		{	
			if(cpu >= arv[i])
			{
			if(i<n-1)
			{
				min=pri[i];
				ind=i;
				for(int j=i+1;j<n;j++)		//j!=i;j=(++j)%n) is not neceesary becoz i++ will not happen until process at i is not become 0 by BT
				{
					if(arv[j]<=cpu)
					{
						if(pri[j]>min) 		//&& tmp[2][j]!=0) also not necessary ,if > Higher number higher priority and if < vice versa.
						{
							min=pri[j];
							ind=j;
						}
					}
				}
				if(min != pri[i])
				{
				Swap(bur[ind],bur[i]);
				Swap(pro[ind],pro[i]);
				Swap(arv[ind],arv[i]);
				Swap(pri[ind],pri[i]);
				Swap(tmp[2][ind],tmp[2][i]);
				}
			}
				cpu++;
				tmp[2][i]--;
				
				if(tmp[2][i]==0)
				{
				wait[i]=cpu-arv[i]-bur[i];	//exit time - entry time - cpuusage time = waiting time
				tat[i]+=wait[i]+bur[i];
				
				wt+=wait[i];
				tt+=tat[i];
				
				i++;
				}
		}
		else
		{
			cpu++;
		}
		}
		wt=wt/n;
		tt=tt/n;
	}
	void InputTimer()
	{
		cout<<"\nEnter the timer for RRB:";
		cin>>timer;
	}
	void RRB()
	{
		InputTimer();
		AscAT();
		int min,ind,cpu=0;
		int i=0,temp,index=0;
		int j,b,frd=1;
		
		while(CheckForBT())
		{	
			if(cpu >= arv[i])
			{
			temp=timer;
			while(tmp[2][i]!=0 && temp!=0)		//acc. to timer run each process until timer expires or burst time ends
			{
				cpu++;
				tmp[2][i]--;
				temp--;
			}
			
			if(frd!=n)						//adding processes in queue whose arrival time is less than cpu	until last process to arrived
			{							//and again starting from next process to last process which is arrived after each timer
				for(j=frd;j<n;j++)
				{
					if(cpu>=arv[j])
					{
						queue[index]=j;
						index++;
						frd=j+1;
					}
				}
			}
			
				if(tmp[2][i]==0)		//if burst time ends then compute everything of that process and decr. index of queue
				{
				wait[i]=cpu-arv[i]-bur[i];	//exit time - entry time - cpuusage time = waiting time
				tat[i]+=wait[i]+bur[i];
				
				wt+=wait[i];
				tt+=tat[i];
				
				index--;
				}
				else 		//adding current process in queue
				{
					queue[index]=i;
				}
			i=queue[0];		//removing first process from queue for next iteration
			
			for(b=0;b!=n-1;b++)		//and arrange the queue
			{
				queue[b]=queue[b+1];
			}
			queue[n-1]=-1;

			}
			else
			{
				cpu++;
			}
		}
		wt=wt/n;
		tt=tt/n;
	}
};
int main()
{
	Scheduling ob;
	int a;
	char ch;
	do
	{
		cout<<"\nPress \n1)FCFS \n2)SJFS \n3)SJFS(Pre-emptive) \n4)Priority";
		cout<<"\n5)Priority(Pre-emptive)\n6)Round Robin\n";
		cin>>a;
		switch(a)
		{
			case 1: ob.Input();
					ob.Table();
					ob.FCFS();
					ob.OutTable();
					break;
			case 2:	ob.Input();
					ob.Table();
					ob.SJFS();
					ob.OutTable();
					break;
			case 3:	ob.Input();
					ob.Table();
					ob.SJFS_P();
					ob.OutTable();
					break;
			case 4:	ob.InputPriority();
					ob.TableWithPri();
					ob.Priority();
					ob.OutTableWithPri();
					break;
			case 5: ob.InputPriority();
					ob.TableWithPri();
					ob.Priority_P();
					ob.OutTableWithPri();
					break;
			case 6: ob.Input();
					ob.Table();
					ob.RRB();
					ob.OutTable();
					break;
			default:cout<<"\n!!Wrong Choice!!";
		}
		ob.Output();
		cout<<"\nPress y/Y to continue:";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
