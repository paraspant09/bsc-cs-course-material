#include<iostream>
#include<math.h>
#include <time.h>
using namespace std; 
void sleep(unsigned int mseconds)		//Only for checking timeout by sleeping 1 sending and receiving
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
class StopNWait
{
	int *arr,n,Sn,Sf;
	int *arr2,Rn;
	int *toSend,ack;		//Buffer for sending data and receiving ack
	int WindowSize,m,cnt;	//cnt is count for toSend frame
	int timer,start;
	bool Send,Receive,timeout,end;
	
	int check,check2;	//only for checking duplicacy or corrupted frame and lost ack resp.
	
	public:
	StopNWait()
	{
		cout<<"\nEnter number of bits in data:";
		cin>>n;
		cout<<"\nEnter m for size of window(2^m-1):";
		cin>>m;
		
		cnt=1;
		WindowSize=pow(2,m)-1;
		toSend=new int[WindowSize+1];		//toSend[0] has data of sending frame		Here Ack buffer size is 1
		
		arr=new int[n];
		arr2=new int[n];
		cout<<"\nEnter the data to be sent:";
		for(int i=0;i<n;i++) 
			cin>>arr[i];
		Sf=0;
		Sn=Rn=0;
		Send=true;
		Receive=false;
		
		toSend[0]=-1;
		for(int i=1;i<=WindowSize;i++) 
			toSend[i]=0;
		
		ack=Rn;
		timer=1;
		timeout=false;
		
		check=1;
		check2=1;
	}
	void Slide(int times)
	{
		if(arr[WindowSize]!=arr[n-1])
		{
		int i;
		while(times)
		{
		for(i=1;i<=WindowSize;i++)
			toSend[i]=toSend[i+1];
		toSend[i+1]=arr[WindowSize+1];
		}
		}
	}
	void Sender()
	{
		if(timeout)		//Resend for timeout 
		{
			ack=Sf;
			timeout=false;
		}
		for(int i=1;i<=WindowSize;i++)
		{
			if((Sf+i)==ack)
			{
				Slide(i);
				Sf+=i;
				break;
			}
		}

		while(Send && Sn!=n	)		//Sn==ack[1] is for acknowledgement
		{
			toSend[0]=arr[Sn];
			toSend[1]=Sn;	//data number
			
			cout<<"\nSending frame "<<Sn;	
			start=clock();	//Start timer
			
		/*	if(Sn==2 && check)		//Only to check for corrupted frames
			{
				toSend[0]=100;		
				check=0;
			}	*/
				
				Sn++;
			Receive=true;
			sleep(100);		//for timer to work properly
		}
		
		if(arr[Sn]==arr[WindowSize])
		{
			Send=false;
			Receive=true;
		}
		
		if(Sn==n && !Receive )
		{
			Send=Receive=false;
		}
	}
	void Receiver()
	{
		while(Receive)
		{
			if((clock()-start)>timer)	//for timeout(before it sender must get ack and receiver must get data)
			{
				cout<<"\nTimeout while at frame "<<Rn;
				
				timeout=true;
				Receive=false;
				Send=true;
			}
			else if(toSend[0]!=-1)		//we have something to receive
			{
				if(Rn-1==toSend[1])		Rn--;	//for duplicacy(if sender is resending previous frame because of error in it or lost ack)
				
				arr2[Rn]=toSend[0];	//Receive frame
				cout<<"\nReceiving frame "<<Rn<<"\n";		
			
				Rn++;
				
				ack=Rn;		//Sending ack of next bit to receive 
			
			/*	if(Rn==4 && check2)		//Only to check for lost ack
				{
					ack[1]=100;		
					check2=0;
				}		*/
				
				Receive=false;
				Send=true;
				toSend[0]=-1;
			}
		}
	}
	bool End()
	{
		return (!(Send||Receive));
	}
	void DisplaySender()
	{
		cout<<"\n\nSender Data is:";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	void DisplayReceiver()
	{
		cout<<"\nReceiver Data is:";
		for(int i=0;i<n;i++)
			cout<<arr2[i]<<" ";
		cout<<endl;
	}
};
int main()
{
	StopNWait ob;
	int i=0;	//for checking timeout or frame lost
	ob.Sender();
	while(!ob.End())
	{
/*		if(i==1)	sleep(100);		//Sleep at 1 to check timeout or frame lost	*/
		ob.Receiver();
		ob.Sender();
		i++;
	}
	ob.DisplaySender();
	ob.DisplayReceiver();
}
