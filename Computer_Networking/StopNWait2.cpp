#include<iostream>
#include <time.h>
#include <cstdlib>
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
	char *toSend,*ack;		//Buffer for sending data and receiving ack
	int timer,start;
	int count,count2;		//to end sending(used for both sender and receiver)
	bool Send,Receive,timeout,end;
	
	public:
	StopNWait()
	{
		toSend=new char[2];
		ack=new char[2];
		
		cout<<"\nEnter the data to be sent:";
		getline(cin,arr);
		
		n=arr.length();
		
		Sn=Rn=0;
		count=count2=0;
		
		Send=true;
		Receive=false;
		
		toSend[0]=-1;
		toSend[1]=0;
		
		ack[1]=Rn;
		timer=100;
		timeout=false;
		start=clock();
		
	}
	void Sender()
	{
		if((clock()-start)>timer)	//for timeout(before it sender must get ack and receiver must get data)
		{
				cout<<"\n\nDue to Lost ack,";
				
				cout<<"\nTimeout while at frame "<<count-1<<"\n";	//just to show as receiver do not have count variable
				timeout=true;
				start=clock();
		}
		if(timeout	||	arr[count-1]!=ack[0]	&&	count!=0)		//Resend for timeout or corrupted frame
		{
			if(arr[count-1]!=ack[0] && !timeout)	cout<<"\nCorrupted frame "<<count-1;	//here in condition you can but error detecting code
			count--;
			Sn=(++Sn)%2;
			ack[1]=Sn;		
			timeout=false;
		}
		
		if(Sn!=ack[1])		//if sender do not get ack of previous frame due to lost ack or lost frame
		{
			Send=false;
			Receive=true;
			toSend[0]=-1;	//Receiver do not receive anything as sender will not send anything 
		}
		
		if(Send && count!=n	)		
		{
			toSend[0]=arr[count];
			toSend[1]=Sn;	//data number
			
			cout<<"\nSending frame "<<count;	
			start=clock();	//Start timer
	
				count++;
				Sn=(++Sn)%2;
			Send=false;
			Receive=true;
		}	
			
		if(!(rand()%7))
     {
         int to = 100 + rand()%(64000 - 24600)  + 1;
         for(int i=0;i<64000;i++)
             for(int j=0;j<to;j++) {}
     }
	}
	void Receiver()
	{
		if(Receive)
		{
			if((clock()-start)>timer)	//for timeout(before it sender must get ack and receiver must get data)
			{
				cout<<"\n\nDue to Lost frame,";
				
				cout<<"\nTimeout while at frame "<<count-1<<"\n";	//just to show as receiver do not have count variable
				timeout=true;
				Receive=false;
				Send=true;
				start=clock();
			}
			else if(toSend[0]!=-1)		//we have something to receive
			{
				if(Rn!=toSend[1])	//for duplicacy(if sender is resending previous frame because of error in it or lost ack)
				{
					Rn=(++Rn)%2;	
					count2--;
				}
				arr2[count2]=toSend[0];	//Receive frame
				cout<<"\nReceiving frame "<<count2<<"\n";		
			
				ack[0]=arr2[count2];	
			
				Rn=(++Rn)%2;
				ack[1]=Rn;		//Sending ack of next bit to receive 
			
				count2++;
				
				Receive=false;
				Send=true;
				toSend[0]=-1;
				
				if(!(rand()%7))
    			{
         			int to = 100 + rand()%(64000 - 24600)  + 1;
        			 for(int i=0;i<64000;i++)
        		    	 for(int j=0;j<to;j++) {}
     			}
			}
		}
	}
	bool End()
	{
		return (count2==n);
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
	srand(time(0)); 
	ob.Sender();
	while(!ob.End())
	{
		ob.Receiver();
		ob.Sender();
	}
	ob.DisplaySender();
	ob.DisplayReceiver();
}
