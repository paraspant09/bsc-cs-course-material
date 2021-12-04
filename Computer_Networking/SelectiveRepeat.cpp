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
	int Rf,Rn;		//For those frames whose ack are received
	char *Window,*RecWindow;
	char *toSend,ack;		//Buffer for sending data and receiving ack(No corrupted frame checking so ack is char var)
	int NAK;
	int *start;
	int timer,times;
	bool Send,Receive,timeout,end;
	int m,WindowSize,Sf;		//for starting of window
	int index,Recindex;		//for putting value from array to window
	int ExtraBitS,ExtraBitR,count,count2;
	int check,check2,check3,check4;	//only for checking duplicacy or corrupted frame and lost ack resp.
	//Corrupted is only checked here but in later ones corrupted frames are checked on receiver side
	public:
	StopNWait()
	{
		cout<<"\nEnter the data to be sent:";
		getline(cin,arr);
		
		cout<<"\nEnter m for size of window(2^(m-1)):";
		cin>>m;
		WindowSize=pow(2,m-1);
		Window=new char[WindowSize];	//Sending buffer deals with window not original array
		RecWindow=new char[WindowSize];
		
		toSend=new char[2];		//Sending buffer
		start=new int[WindowSize];
		for(int i=0;i<WindowSize;i++) 
			start[i]=-1;
			
		n=arr.length();
		
		Rf=Sf=Sn=Rn=0;
		times=1;
		
		Send=true;
		Receive=false;
		
		for(int i=0;i<WindowSize;i++) 
			Window[i]=arr[i];
		DisplayWindow();
		
		toSend[0]=-1;
		toSend[1]=0;
		
		ack=Rn;
		NAK=-1;
		
		timer=10;
		timeout=false;
		index=WindowSize;
		Recindex=WindowSize;
		
		ExtraBitS=0;
		ExtraBitR=-1;
		count=count2=0;
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
		times=1;
	}
	void HandleNAK()	//Receive NAK when Timeout of that frame
	{
		int a=TimeOUTFrame();
		
		if(WindowSize==1) NAK=0;
		
		if(a!=-1 && NAK!=-1)	//for timeout
		{
			cout<<"\nTimeout of frame "<<a<<" of window\n";
			toSend[0]=Window[NAK];
			toSend[1]=NAK;	//data number
			
			cout<<"\nReSending frame "<<NAK<<" of Window";	
			start[NAK]=clock();	//Start timer Sn-Sf is not required becoz of timer for each frame
			
			Send=false;
			Receive=true;
		}
	}
	void Sender()
	{
		int Sf=0;
		HandleNAK();
		if(ack<=WindowSize && ack)
		{	
		ack=Sn;
				while(Sf<ack)	//until it is not become Sf == ack 
				{
					Slide();
					DisplayWindow();
					start[Sf]=-1;	//timeout all frames whose ack is reached from reverse
					Sf=(Sf+1)%(WindowSize+1);
					if(Sn!=0)	Sn=(--Sn)%WindowSize;
				}
			Send=true;
			ack=0;
		}

		if(Send && count!=n)		
		{
			toSend[0]=Window[Sn];
			toSend[1]=Sn;	//data number

			cout<<"\nSending frame "<<count<<" of array and "<<Sn<<" of Window";	
			start[Sn]=clock();	//Start timer Sn-Sf is not required becoz of timer for each frame
	
			if(count==3 && check )		//Only to check for lost frames
			{
				toSend[0]=-1;		
				check=0;
			}
			
			count++;	

			if(Sn+1==WindowSize)		//Send until reached end of the window
			{
				Send=false;
			}
			Sn++;
			Receive=true;
		}
	}
	void RecSlide(int t)
	{
		while(t)
		{
			arr2[count2]=RecWindow[0];	//put frame from buffer to array
			count2++;
		
		if(WindowSize!=n-1)
		{
		 	int i;
	    	for(i=0;i<(WindowSize-1);i++)
				RecWindow[i]=RecWindow[i+1];
			RecWindow[i]=arr2[Recindex];
			Recindex++;
		}
		t--;
		}
	}
	int TimeOUTFrame()
	{
		for(int i=0;i<WindowSize;i++)
		{
			if((start[i]!=-1) && (clock()-start[i])>timer)
			{
				start[i]=-1;
				return i;
			}
		}
		return -1;	
	}
	void Receiver()
	{
		if(Receive)
		{
			if(toSend[0]!=-1 )		//we have something to receive and frame do not lost so that any further frame will not be received
			{
				Rn=toSend[1];
				RecWindow[Rn]=toSend[0];		//Saving received frame in buffer
				
				cout<<"\nReceiving frame "<<Rn<<" of Window\n";		
				
				if((ExtraBitR+1)%WindowSize!=Rn)
				{
					NAK=ExtraBitR+1;
					times++;
				}
				else
				{
				//	cout<<"A";
					NAK=-1;
					RecSlide(times);
					ack=Rn+1;
					ExtraBitR=-1;
				}
				
				Receive=false;
				toSend[0]=-1;
			}
			else if(Send)
				cout<<"\nFrame LOST Sending Next Frame";
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
/*	void Timeoutarray()
	{
		cout<<"\nTime out array is:";
		for(int i=0;i<WindowSize;i++)
			cout<<start[i]<<" ";
		cout<<endl;
	}*/
	void DisplayWindow()
	{
		cout<<"\nWindow is:[";
		for(int i=0;i<WindowSize;i++)
			cout<<Window[i];
		cout<<"]"<<endl;
	}
/*	void DisplayRecWindow()
	{
		cout<<"\nRecWindow is:[";
		for(int i=0;i<WindowSize;i++)
			cout<<RecWindow[i];
		cout<<"]"<<endl;
	}*/
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
