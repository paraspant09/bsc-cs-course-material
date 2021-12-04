#include<iostream>
using namespace std;
float func(int b,int r,float ans=1)
{
	if(r==0) return ans;
	
	if(r<0)
	{
	ans*=b;
	if(r==-1) ans=1/ans;
	return func(b,++r,ans);
	}
	else
	{
	ans*=b;
	return func(b,--r,ans);
	}
}
int main()
{
	int b,r=0;
	float ans=0;
	cout<<"\nEnter b and r:";
	cin>>b>>r;
	ans=func(b,r);
	cout<<ans;
}
