#include<iostream>
#include<string.h>
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
void AddLargeNos(char a[],int n1,char b[],int n2)
{
	int res_len,carry,sum,one,c,two=0;
    Stack ob1(n1);
    //Pushing 1st no. in 1st Stack from MSB to LSB
    for(int j=0;j<n1;j++)
    {
     ob1.PUSH(a[j]-'0');
	}

	Stack ob2(n2);
	//Pushing 2nd no. in 2nd Stack from MSB to LSB
	for(int j=0;j<n2;j++)
    {
     ob2.PUSH(b[j]-'0');
	}
    //Getting bigger no.'s MSB  among 2 for sum stack size
	if(n1 >= n2)
	    c=n1;
	else
	    c=n2;
	    
	Stack ob3(c+1);     // +2 because MSB=i-1 and last carry bit
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
	char a[100],b[100];
	cout<<"\nEnter number 1 to be added ";
	cin>>a;
	cout<<"\nEnter number 2 to be added ";
	cin>>b;
	cout<<"Sum is: ";
	AddLargeNos(a,strlen(a),b,strlen(b));
}
