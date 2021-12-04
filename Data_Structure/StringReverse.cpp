#include<iostream>
using namespace std;
void reverse()
{
	char c;
	cin>>c;
	if(c=='.')
		return;
	else
	{
		reverse();
		cout<<c;
	}
}
int main()
{
	reverse();
}
