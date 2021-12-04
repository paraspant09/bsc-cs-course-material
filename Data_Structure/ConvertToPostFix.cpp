#include<iostream>
#include<string.h>
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
		X topel()
		{
			return arr[top];
		}
};
//Compare 2 operator's precedence 
bool isGreater(char ch1,char ch2)
{
	switch(ch1)
	{
		case '*':switch(ch2)
		         {
		         	case '+':return true;
		         	case '-':return true;
		         	default :return false;
				 }
		case '/':switch(ch2)
		         {
		         	case '+':return true;
		         	case '-':return true;
		         	default :return false;
				 }
		default: return false;
	}
}
void ConvertToPostFix(char str[])
{
  Stack <char>ob(strlen(str));
  char temp,str2[strlen(str)],ch,ch1;
  int a=0;
  for(int i=0;str[i]!='\0';i++)
  {
  	ch=str[i];
  	if(isdigit(ch))           //if it is digit then put it to the output string
  	{
  	  str2[a]=ch;
      a++;	
	}
	else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')  //if operator then check for precedence
	{
	  if(isGreater(ob.topel(),ch))   //if it is greater then POP bigger element to output string and Push smaller one in stack
	  {
	  	str2[a]=ob.POP();
	  	ob.PUSH(ch);
	  	a++;
	  }
	  else
	    ob.PUSH(ch);
	}
	else if(ch=='('||ch=='{'||ch=='[')      //if openening bracket then Push in Stack 
	  ob.PUSH(ch);
	else      //if closing bracket,then pop operators in stack to output string until opening bracket comes in stack and POP it as well 
	  { 
	  	if(ch==')')
	  	 do
	   	 {
	  		ch1=ob.POP();
	  		if(ch1!='(')                //for matching of opening and closing ones
	  		{
			 str2[a]=ch1;
		     a++;
		    }
		 }while(ch1!='(');
		else if(ch=='}')
	  	 do
	  	 {
	  	 	ch1=ob.POP();
	  		if(ch1!='(')
	  		{
			 str2[a]=ch1;
		     a++;
		    }
		 }while(ch1!='{');
		else if(ch==']')
	  	  do
	   	  {
	   	  	ch1=ob.POP();
	  		if(ch1!='[')
	  		{
			 str2[a]=ch1;
		     a++;
		    }
		  }while(ch1!='[');
	  }
  }
  while(!ob.isempty())                       //for remaining operators in stack to push them into output string
  { 
   str2[a]=ob.POP();
   a++;
  }
  cout<<str2;
}
int main()
{
	int n;
	cout<<"\nEnter size of the inFix Expression\n";
    cin>>n;
    char str[n];
    cout<<"\nEnter the inFix Expression ";
    cin>>str;
    cout<<"\nPostFix Expression is:";
	ConvertToPostFix(str);
}
