#include<iostream>
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
int Delimeter()
{
	int len;
	char ch,ch2;
	cout<<"\nEnter Size of String :";
	cin>>len;
	char str[len];
	Stack <char>ob(len);
	cout<<"\nEnter String ";
	cin>>str;
	for(int i=0;i<len;i++)
	{
		ch=str[i];
		if(ch=='('||ch=='{'||ch=='[')             //if opening bracket then push into stack
		    ob.PUSH(ch);
		else if(ch==')'||ch=='}'||ch==']')        //if closing bracket is present 
		{
			if(ob.isempty())                      //but no any opening pair of it in stack then invalid format else POP the opening bracket
			    return 0; 
			else 
			    ch2=ob.POP();
			
			if(ch==')' && ch2=='(')              //Check for the correct opening pair in stack else invalid format
			     continue;
		    else if(ch=='}' && ch2=='{')
		    	 continue;
			else if(ch==']' && ch2=='[')
				 continue;
			else 
				 return 0;
	    }
	}
	if(ob.isempty())                              //Atlast if stack empty then valid else inalid
	    return 1;
	return 0;
}
int main()
{
	if(Delimeter()==0)
	   cout<<"Invalid Format\n";
	else 
	   cout<<"Valid Format\n";
}
