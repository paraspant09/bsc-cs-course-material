#include<iostream>
using namespace std;
class MM{
	int **arr;
	int RAM;
	int MemCounter;
	int PSize;
	int pno;
	public:
		MM()
		{
			cout<<"\nEnter The size of RAM(in Bytes):";
			cin>>RAM;
			//Asuming maximum no. of columns possible in array to be equal to RAM size (taking each process size to be 1)
			arr=new int*[3];	//arr[0]=for process no.,arr[1]=for ini addr.,arr[2]=for end addr.
			for(int i=0;i<3;i++)
			{
				arr[i]=new int[RAM];
			}
			for(int i=0;i<RAM;i++)
			{
				arr[0][i]=arr[1][i]=arr[2][i]=0;
			}
			MemCounter=0;
			pno=0;
		}
		void ADD(int j)
		{
			pno++;
			arr[0][j]=pno;
			arr[1][j]=MemCounter;
			MemCounter+=PSize;
			arr[2][j]=MemCounter-1;
		}
		void ADD_FF()
		{
			int j=0,extra=0;
			
			cout<<"\nEnter Process Size:";
			cin>>PSize;
			
			for(;j<RAM;j++)
			{
				extra+=(arr[2][j]-arr[1][j]+1);
				if(arr[0][j]==0)
				{
					if(MemCounter==RAM)
						cout<<"\nMemory is FULL \n";
					else if(PSize > (RAM-MemCounter))			
						cout<<"\nAdding Process Size is Greater than Left out Memory";
					else if(extra >= RAM)
						cout<<"\nLeft out Spaces are not Sufficient for Process\n";
					else
						ADD(j);
					break;
				}
				else if(arr[0][j]==-1)
				{
					int diff=((arr[2][j]-arr[1][j]+1) - PSize);
					if(diff>=0)
					{
						pno++;
						arr[0][j]=pno;
						
						if(j!=0)  arr[1][j]=arr[2][j-1]+1;
						else 	arr[1][j]=0;
						
						MemCounter+=PSize;
						arr[2][j]=arr[1][j]+PSize-1;
						
						if(diff!=0)
						{
							for(int i=j+1;i<RAM;i++)
							{
								if(arr[0][i]==0)
								{
									arr[0][i]=-1;
									arr[1][i]=arr[2][j]+1;
									arr[2][i]=arr[2][j]+diff;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		void ADD_BF()
		{
			int j=0,extra=0,min=RAM,val=-1,diff=-1;
			
			cout<<"\nEnter Process Size:";
			cin>>PSize;
			
			for(;j<RAM;j++)
			{
				if(arr[0][j]==0)
					break;
				else if(arr[0][j]==-1)
				{
					diff=((arr[2][j]-arr[1][j]+1) - PSize);
					if(diff>=0)
					{
						if(diff < min)
						{
							val=j;
							min=diff;
						}
					}
				}
			}
			
			if(min!=RAM)
			{
				j=val;
				pno++;
				arr[0][j]=pno;
				
				if(j!=0)  arr[1][j]=arr[2][j-1]+1;
				else 	arr[1][j]=0;
				
				MemCounter+=PSize;
				arr[2][j]=arr[1][j]+PSize-1;
			
				if(diff!=0)
				{
					for(int i=j+1;i<RAM;i++)
					{
						if(arr[0][i]==0)
						{
							arr[0][i]=-1;
							arr[1][i]=arr[2][j]+1;
							arr[2][i]=arr[2][j]+diff;
							break;
						}
					}
				}
			}
			else if(arr[0][j]==0)
			{
				extra+=(arr[2][j]-arr[1][j]+1);
				if(MemCounter==RAM)
					cout<<"\nMemory is FULL \n";
				else if(PSize > (RAM-MemCounter))			
					cout<<"\nAdding Process Size is Greater than Left out Memory";
				else if(extra >= RAM)
					cout<<"\nLeft out Spaces are not Sufficient for Process\n";
				else
					ADD(j);
			}
		}
		void ADD_WF()
		{
			int j=0,extra=0,max=-1,val=-1,diff=-1;
			
			cout<<"\nEnter Process Size:";
			cin>>PSize;
			
			for(;j<RAM;j++)
			{
				if(arr[0][j]==0)
					break;
				else if(arr[0][j]==-1)
				{
					diff=((arr[2][j]-arr[1][j]+1) - PSize);
					if(diff>=0)
					{
						if(diff > max)
						{
							val=j;
							max=diff;
						}
					}
				}
			}
			
			if(max!=-1)
			{
				j=val;
				pno++;
				arr[0][j]=pno;
				
				if(j!=0)  arr[1][j]=arr[2][j-1]+1;
				else 	arr[1][j]=0;
				
				MemCounter+=PSize;
				arr[2][j]=arr[1][j]+PSize-1;
			
				if(diff!=0)
				{
					for(int i=j+1;i<RAM;i++)
					{
						if(arr[0][i]==0)
						{
							arr[0][i]=-1;
							arr[1][i]=arr[2][j]+1;
							arr[2][i]=arr[2][j]+diff;
							break;
						}
					}
				}
			}
			else if(arr[0][j]==0)
			{
				extra+=(arr[2][j]-arr[1][j]+1);
				if(MemCounter==RAM)
					cout<<"\nMemory is FULL \n";
				else if(PSize > (RAM-MemCounter))			
					cout<<"\nAdding Process Size is Greater than Left out Memory";
				else if(extra >= RAM)
					cout<<"\nLeft out Spaces are not Sufficient for Process\n";
				else
					ADD(j);
			}
		}
		void Display()
		{
			cout<<"\nProcess No.	Initial Addr.	End Addr.	";
			for(int i=0;i<RAM;i++)
			{
				if(arr[0][i]==0)
					break;
				else if(arr[0][i]==-1)
				{
					cout<<"\nHole		"<<arr[1][i]<<"		"<<arr[2][i];
				}
				else
				{
					cout<<"\n"<<arr[0][i]<<"		"<<arr[1][i]<<"		"<<arr[2][i];
				}
			}
		}
		void Remove()
		{
			int processNo,Not=1;
			if(pno)
			{
				cout<<"\nEnter Process No. to remove possible no./no.s is/are 1 ";
				if(pno!=1) cout<<"to "<<pno<<" ";
				cin>>processNo;
				if(processNo>0 && processNo<=pno)
				{
					for(int i=0;i<RAM;i++)
					{
						if(arr[0][i]==processNo)
						{
							arr[0][i]=-1;
							MemCounter-=(arr[2][i]-arr[1][i]+1);
							Not=0;
						}
					}
					if(Not) cout<<"\nProcess is Already Removed";
				}
				else
					cout<<"\nWrong Process No.";
			}
			else
				cout<<"\nNo Process in Memory to Remove\n";
		}
};
int main()
{
	MM ob;
	int a;
	char ch;
	cout<<"\nPress \n1)First Fit \n2)Best Fit \n3)Worst Fit \n";
	cin>>a;
	switch(a)
	{
	case 1:
		do
		{
			cout<<"\nPress \n1)Add \n2)Remove \n3)Display \n";
			cin>>a;
			switch(a)
			{
				case 1: ob.ADD_FF();
						break;
				case 2:	ob.Remove();
						break;
				case 3:	ob.Display();
						break;
				default:cout<<"\n!!Wrong Choice!!";
			}
			cout<<"\nPress y/Y to continue:";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
		break;
	case 2:
		do
		{
			cout<<"\nPress \n1)Add \n2)Remove \n3)Display \n";
			cin>>a;
			switch(a)
			{
				case 1: ob.ADD_BF();
						break;
				case 2:	ob.Remove();
						break;
				case 3:	ob.Display();
						break;
				default:cout<<"\n!!Wrong Choice!!";
			}
			cout<<"\nPress y/Y to continue:";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
		break;
	case 3:
		do
		{
			cout<<"\nPress \n1)Add \n2)Remove \n3)Display \n";
			cin>>a;
			switch(a)
			{
				case 1: ob.ADD_WF();
						break;
				case 2:	ob.Remove();
						break;
				case 3:	ob.Display();
						break;
				default:cout<<"\n!!Wrong Choice!!";
			}
			cout<<"\nPress y/Y to continue:";
			cin>>ch;
		}while(ch=='y' || ch=='Y');
		break;
	default:cout<<"\n!!Wrong Choice!!";
	}
}
