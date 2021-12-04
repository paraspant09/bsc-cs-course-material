#include<iostream>
#include<math.h>
using namespace std;
class Stack
{
 int *arr;
 int n,top;
 public:
        Stack(int a)	
        {
        	n=a;
        	arr=new int[n];
        	top=-1;
		}
		void StackPrintReverse()
		{
			for(int i=top;i>=0;i--)
			    cout<<arr[i];
			cout<"\n";
		}
	    void PUSH(int a)
		{
			if(top==n-1)
			   cout<<"OverFlow";
			else
			   arr[++top]=a;
		}
	    int POP()
		{
			if(top==-1)
			   cout<<"UnderFlow";
			else
			   return (arr[top--]);
			return -1;
		}
		bool isempty()
		{
			if(top==-1)
			    return true;
			return false;
		}
};
void AddLargeNos(long int a,long int b)
{
	long int c,ret=0,no;
	int res_len,i,a_MSB,b_MSB,carry,sum=0;
	c=a;
// no use of reslen if mam say to remove StackPrintReverse then use it
	while(c!=0)
	{
		c=c/10;
		i++;
	}
	
	c=a;
    a_MSB=i-1;
    Stack ob1(i);
    for(int j=a_MSB;j>=0;j--)
    {
     no=pow(10,j);
     ob1.PUSH(c/no);
     c%=no;
	}

	i=0,c=b;
	
	while(c!=0)
	{
		c=c/10;
		i++;
	}
	
	c=b;
	b_MSB=i-1;
	Stack ob2(i);
	for(int j=b_MSB;j>=0;j--)
    {
    	no=pow(10,j);
    	ob2.PUSH(c/no);
    	c%=no;
	}

	if(a_MSB <= b_MSB)
	    c=a_MSB;
	else
	    c=b_MSB;
	    
	Stack ob3(a_MSB+b_MSB+2);
	carry=0;
	do
	{
	 sum=ob1.POP()+ob2.POP()+carry;   
	 ob3.PUSH(sum%10);
	 carry=sum/10;
	 c--;
	 res_len++;	
	}while(c>=0);
//Add the remaining stack until it is empty
	while(ob1.isempty()&&!ob2.isempty()) 
	{
		sum=ob2.POP()+carry;
		carry=sum/10;
		ob3.PUSH(sum%10);
		res_len++;
	}
	while(!ob1.isempty()&&ob2.isempty())
	{
		sum=ob1.POP()+carry;
		carry=sum/10;
		ob3.PUSH(sum%10);
		res_len++;
	}
	if(carry!=0)
	{
	   ob3.PUSH(carry);
	   res_len++;   
    } 
	ob3.StackPrintReverse();
}
int main()
{
	long int a,b;
	cout<<"Enter 2 nos to be added ";
	cin>>a>>b;
	cout<<"Sum is: ";
	AddLargeNos(a,b);
}
