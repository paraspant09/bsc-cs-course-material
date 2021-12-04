#include<iostream>
#include<string.h>
using namespace std;
class IPAddressing{
	string str;
	int len;
	int arr[32];
	
	public:
	IPAddressing()
	{
	cout<<"\nEnter the IP address:\n";
	cin>>str;
	len=str.length();
	}
	void MakeIP()
	{
		int temp=0,a=1,b=1;
		for(int i=0;i<=len;i++)
		{
			if(str[i]=='.' || i==len)
			{					
				int i=8*b-1;
				while(i>=8*(b-1))
				{
					arr[i]=temp%2;
					temp=temp/2;
					i--;
				}
				b++;
				temp=0;
				a=1;
			}
			else
			{
				temp*=a;
				temp+=(str[i]-'0');
				a=10;
			}
		}
	}
	void Disp()
	{
		int b=1;
		cout<<endl;
		while(b!=5)
		{
		for(int i=8*(b-1);i<8*b;i++)
		{
			cout<<arr[i];
		}
		if(b!=4) cout<<".";
		b++;
		}
	}
	void FindClass()
	{
		cout<<"\nClass is:";
		for(int i=0;i<4;i++)
		{
			if(arr[i]==0)
			{
				cout<<(char)(i+'A');
				break;
			}
			if(i==3)
				cout<<"E";
		}
	}
};
int main()
{
	IPAddressing ob;
	ob.MakeIP();
	ob.Disp();
	ob.FindClass();
}
