#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
template<class X> class Stack
{
 X *arr;
 int n,top;
 public:
        Stack(int a)	
        {
        	n=a;
        	arr=new X[n];
        	top=-1;
		}
	    void PUSH(X a)
		{
			if(top==n-1)
			   cout<<"OverFlow";
			else
			   arr[++top]=a;
		}
	    X POP()
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
int StackEvaluate(char str[])
{
	char ch;
	int a,b,i=0,c=0,d=0,t=-1;
	Stack <int>ob1(strlen(str));
	for(i=0;str[i]!='\0';i++)
	{
		ch=str[i];
		if(isdigit(ch))     //if char is digit then Push in stack with its integer format else if it is binary operator POP 2 elements
		{
			d=i;
			while(isdigit(str[i]))
			{
				i++;
				t++;
			}
			i=d;
		 	while(isdigit(str[i]))
	        {
	        		c+=(str[i]-'0')*pow(10,t);
	        		i++;
	        		t--;
	        }
	        i--;
			ob1.PUSH(c);
			t=-1;
			c=0;
	    }
	    else if(str[i]!='_')
	    {  
	    	a=ob1.POP();
	    	b=ob1.POP();  //Acc. to correct operator perform operation and push back the result into the stack
         
		 if(ch=='+')
		    ob1.PUSH(b+a);
		 else if(ch=='-')
		    ob1.PUSH(b-a);
		 else if(ch=='*')
		    ob1.PUSH(b*a);
		 else if(ch=='/')
		    ob1.PUSH(b/a);
		}
	}
	return ob1.POP();    //POP out the 1 and only result left in stack
}
int main()
{
	int n;
	cout<<"\nEnter size of the Expression\n";
    cin>>n;
    char str[n];
    cout<<"\nEnter the Expression(insert underscore(_) in between for seperating each number)\n ";
    cin>>str;
    cout<<"Evaluated value is:"<<StackEvaluate(str);
}
