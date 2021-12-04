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
void AddLargeNos(long a,long b)
{
	long c,ret=0,no;
	int res_len,i,a_MSB,b_MSB,carry,sum,one,two=0;
	c=a;
// no use of reslen if mam say to remove StackPrintReverse then use it
	// Size of first no. for obtaining MSB
	while(c!=0)
	{
		c=c/10;
		i++;
	}
	
	c=a;
    a_MSB=i-1;
    Stack ob1(i);
    //Pushing 1st no. in 1st Stack from MSB to LSB
    for(int j=a_MSB;j>=0;j--)
    {
     no=pow(10,j);
     ob1.PUSH(c/no);
     c%=no;
	}

	i=0,c=b;
	// Size of Second no. for obtaining MSB
	while(c!=0)
	{
		c=c/10;
		i++;
	}
	
	c=b;
	b_MSB=i-1;
	Stack ob2(i);
	//Pushing 2nd no. in 2nd Stack from MSB to LSB
	for(int j=b_MSB;j>=0;j--)
    {
    	no=pow(10,j);
    	ob2.PUSH(c/no);
    	c%=no;
	}
    //Getting bigger no.'s MSB  among 2 for sum stack size
	if(a_MSB >= b_MSB)
	    c=a_MSB;
	else
	    c=b_MSB;
	    
	Stack ob3(c+2);     // +2 because MSB=i-1 and last carry bit
	carry=0;
	do
	{
	if(!ob1.isempty())            // POP First stack until it is empty then give value 0 if it is empty
	   one=ob1.POP();	
	else
	   one=0;
	   
	if(!ob2.isempty())            // POP Second stack until it is empty then give value 0 if it is empty
	   two=ob2.POP();	
	else
	   two=0;
	   
	 sum=one+two+carry;           //Sum of each place of 2 stacks+carry
	 ob3.PUSH(sum%10);
	 carry=sum/10;
	 c--;
	 res_len++;	
	}while(c>=0);

	if(carry!=0)                  //Atlast if carry remains push it
	{
	   ob3.PUSH(carry);
	   res_len++;   
    } 
    
	ob3.StackPrintReverse();       // Print Stack
}
int main()
{
	long a,b;
	cout<<"Enter 2 nos to be added ";
	cin>>a>>b;
	cout<<"Sum is: ";
	AddLargeNos(a,b);
}
