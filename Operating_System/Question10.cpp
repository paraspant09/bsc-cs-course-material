#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
class Paging{
	int *procID,n;	//Contains id's of proccesses 
	int **pageTable; //index of process array gives page tables of each process through index of page table which contains frame no. as data
	int *noPages;
	int memSize;
	int pageSize;
	public:
	void Input()
	{
		cout<<"\nEnter Memory Size:";
		cin>>memSize;
		
		cout<<"\nEnter No. of processes:";
		cin>>n;
		
		cout<<"\nEnter page Size:";
		cin>>pageSize;
		
		procID=new int[n];
		pageTable=new int*[n];
		noPages=new int[n];
		
		for(int i=0;i<n;i++)
		{
			int procSize;
			cout<<"\n\nFor Process P"<<i+1<<",";
			cout<<"\nEnter Size "<<":";
			cin>>procSize;
			cout<<"\nEnter ID "<<":";
			cin>>procID[i];
			noPages[i]=ceil((float)procSize/(float)pageSize);
			pageTable[i]=new int[noPages[i]];
		}
	}
	void AssignFrames()
	{
		int *Frames;
		int noFrames;
		noFrames=(memSize/pageSize);
		Frames=new int[noFrames];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<noPages[i];j++)
			{
				int a;
				do
				{
					a=rand()%noFrames;
				}while(Frames[a]==1);
				pageTable[i][j]=a;
				Frames[a]=1;
			}
		}
	}
	void Print()
	{
		for(int i=0;i<n;i++)
		{
			if(!procID[i])	continue;
			
			cout<<"\n\nPage Table of Process having ID="<<procID[i]<<" is:";
			cout<<"\nPage number      |    Frame number   \n";
			for(int j=0;j<noPages[i];j++)
			{
				cout<<"p"<<j<<"                     "<<pageTable[i][j]<<"\n";
			}
		}
	}
	void FindFrameNo()
	{
		int pID,pageNo;
		int index=-1;
		cout<<"\nEnter Proccess ID:";
		cin>>pID;
		cout<<"\nEnter page No.:";
		cin>>pageNo;
		for(int i=0;i<n;i++)
			if(procID[i]==pID)
				index=i;
		
		if(index!=-1) 
		{
			if(pageNo<noPages[index] && pageNo>=0)
				cout<<"\nFrame No. is:"<<pageTable[index][pageNo];
			else
				cout<<"\nWrong Page No.";
		}
		else 
			cout<<"\nWrong proccess ID";
	}
	void DisplayFrameTable()
	{
		cout<<"\n\nFrame Table is:";
		cout<<"\nFrame number      |    Process ID      |       Page number\n";
		for(int i=0;i<n;i++)
		{
			if(!procID[i])	continue;
			
			for(int j=0;j<noPages[i];j++)
			{
				cout<<pageTable[i][j]<<"                     	"<<procID[i]<<"                     p"<<j<<"\n";
			}
		}
	}
	void Deallocate()
	{
		int pID,index=-1;
		cout<<"\n\nEnter Proccess ID to deallocate proccess:";
		cin>>pID;
		for(int i=0;i<n;i++)
			if(procID[i]==pID)
				index=i;
				
		if(index!=-1) 
		{
			procID[index]=0;
			delete [] pageTable[index];
			pageTable[index]=0;
			noPages[index]=0;
		}
		else 
			cout<<"\nWrong proccess ID";
	}
};
int main()
{
	Paging ob;
	ob.Input();
	ob.AssignFrames();
	ob.Print();
	ob.DisplayFrameTable();
	ob.FindFrameNo();
	ob.Deallocate();
	ob.Print();
	ob.DisplayFrameTable();
}
