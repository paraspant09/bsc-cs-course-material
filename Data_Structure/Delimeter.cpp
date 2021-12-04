#include<iostream>
#include<stdio.h>
using namespace std;
class Stack{
	int *arr,n,top;
	public:
		Stack()
		{
			cout<<"Enter the size of the array used for Stack";
			cin>>n;
			arr=new int[n];
			top=-1;
		}
		void PUSH(int x)
		{
			if(top==(n-1))
	             cout<<"Overflow";
	        else
                 arr[++top]=x;
		}
		int POP()
		{
			if(top==-1)
			{
			   cout<<"Underflow";
			   return -1;
		    }
			else
			  return(arr[top--]);	
		}
		bool isempty()
		{
			if(top==-1)
			   return true;
			return false;
		}
		bool isfull()
		{
			if(top==n-1)
			   return true;
			return false;
		}
		int topel()
		{
			return(arr[top]);
		}
};
int Delimeter()
{
	Stack ob;
	int len;
	cout<<"\nEnter Size of String";
	cin>>len;
	char str[len],ch,ch2;
	cout<<"\nEnter String";
	gets(str);
	for(int i=0;i<len;i++)
	{
		ch=str[i];
		if(ch=='(' || ch=='{' || ch=='[')
		    ob.PUSH(ch);
		if(ch==')' || ch=='}' || ch==']')
		{
			if(ob.isempty())
			   return 0;
			ch2=ob.POP();
			if(ch2='(')
		}
	}
}
