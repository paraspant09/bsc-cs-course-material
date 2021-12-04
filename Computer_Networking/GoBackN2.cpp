#include<iostream>
#include <time.h>
#include<math.h>
using namespace std; 
void sleep(unsigned int mseconds)		//Only for checking timeout by sleeping 1 sending and receiving
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
class StopNWait
{
	string arr,arr2;
	int n,Sn;
	int Rn;
	char *Window;
	char *toSend,ack;		//Buffer for sending data and receiving ack(No corrupted frame checking so ack is char var)
	int timer,start;
	bool Send,Receive,timeout,end;
	int m,WindowSize,Sf;		//for starting of window
	int index;		//for putting value from array to window
	
	int check,check2,check3,check4;	//only for checking duplicacy or corrupted frame and lost ack resp.
	//Corrupted is only checked here but in later ones corrupted frames are checked on receiver side
	public:
	StopNWait()
	{
		cout<<"\nEnter the data to be sent:";
		getline(cin,arr);
		
		cout<<"\nEnter m for size of window(2^m-1):";
		cin>>m;
		WindowSize=pow(2,m)-1;
		Window=new char[WindowSize];	//Sending buffer deals with window not original array
		
		toSend=new char[2];		//Sending buffer
		
		n=arr.length();
		
		Sf=Sn=Rn=0;
		
		Send=true;
		Receive=false;
		
		for(int i=0;i<WindowSize;i++) 
			Window[i]=arr[i];
		cout<<"Window is ["<<Window<<"] ";
		
		toSend[0]=-1;
		toSend[1]=0;
		
		ack=Rn;
		timer=1;
		timeout=false;
		index=WindowSize;
		
		check=1;
		check3=check4=check2=1;
	}
	void Slide()
	{
		if(arr[WindowSize]!=arr[n-1])
		{
		 	int i;
	    	for(i=0;i<(WindowSize-1);i++)
				Window[i]=Window[i+1];
			Window[i]=arr[index];
			index++;
		}
	}
	void Sender()
	{
		if(timeout)		//Resend for timeout
		{
			Sn=Sf;		
			timeout=false;
		}
		
		if(ack)
		{
			if(ack>Sf && ack<=Sn)
			{
				cout<<"Reached of frame "<<Sn-1<<"\n";	
				while(Sf<ack)	//until it is not become Sf == ack 
				{
					Slide();
					Sf+=1;
					if(Sn!=n) cout<<"Window is ["<<Window<<"] ";
				}
			}
			else
				cout<<"Lost of frame "<<Sn-1<<"\n";
			ack=0;
		}
		if(Sn-Sf==WindowSize)		//Send until reached end of the window
		{
			Send=false;
			Receive=true;
		}
		if(Send && Sn!=n)		
		{
		//	cout<<Sf<<" "<<Sn;
			toSend[0]=Window[Sn-Sf];
			toSend[1]=Sn;	//data number
			
			cout<<"\nSending frame "<<Sn;	
			if((Sn-Sf)==0)	start=clock();	//Start timer
	
			if(Sn==3 && check )		//Only to check for lost frames
			{
				toSend[1]=100;		
				check=0;
			}	
			
				++Sn;
			Receive=true;
		}
	}
	void Receiver()
	{
		if(Receive)
		{
			if((clock()-start)>timer)	//for timeout
			{
				if(Sn==Rn)
				{
					Rn=Sf;
					cout<<"\n\nTimeout while at frame "<<Sn-1;	//just to show as receiver do not have Sn variable
					cout<<"\nDue to lost ACK from "<<Rn<<" to "<<Sn-1<<"\n";
				}
				else
				{
					cout<<"\n\nTimeout while at frame "<<Sn-1;	//just to show as receiver do not have Sn variable
					cout<<"\nDue to lost frame at "<<Rn<<"\n";
				}
				timeout=true;
				Receive=false;
				Send=true;
			}
			else if(toSend[0]!=-1 && toSend[1]==Rn)		//we have something to receive and frame do not lost so that any further frame will not be received
			{
				arr2[Rn]=toSend[0];	//Receive frame
				cout<<"\nReceiving frame "<<Rn<<"\n";		
			
				++Rn;
				ack=Rn;		//Sending ack of next bit to receive 
				
				cout<<"\nACK "<<Rn<<" ";	
				
				if(Rn==2 && check2)		//Only to check for 1 lost ack 
				{
					ack=100;	
					check2=0;	
				}		
				if(Rn==3 && check3)	//to check for 2 lost ack
				{
					ack=100;	
					check3=0;	
				}
			/*	if(Rn==4 && check4)	//to check for window of 2 size lost ack
				{
					ack=100;	
					check4=0;	
				}*/
				Receive=false;
				toSend[0]=-1;
			}
		}
	}
	bool End()
	{
		return (Rn==n);
	}
	void DisplaySender()
	{
		cout<<"\n\nSender Data is:";
		for(int i=0;i<n;i++)
			cout<<arr[i];
		cout<<endl;
	}
	void DisplayReceiver()
	{
		cout<<"\nReceiver Data is:";
		for(int i=0;i<n;i++)
			cout<<arr2[i];
		cout<<endl;
	}
};
int main()
{
	StopNWait ob;
	ob.Sender();
	while(!ob.End())
	{
		ob.Receiver();
		ob.Sender();
	}
	ob.DisplaySender();
	ob.DisplayReceiver();
}
