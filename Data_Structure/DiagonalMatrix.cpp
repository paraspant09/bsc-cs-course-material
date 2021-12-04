#include<iostream>
using namespace std;

class diagonal{
	int n;
	int *arr;
	public:
		diagonal(int size){
			n=size;
			arr=new int[n];
			for(int i=0;i<n;i++)
				arr[i]=0;
		}
		void store(int i,int j,int val){
			if(0<=i<=n-1&&0<=j<=n-1){
				if(i==j){
					arr[i]=val;
				}
				else{
					if(val!=0)
						cout<<"\nELEMENT ENTERED IS NOT AT DIAGONAL POSITION ";
				}
			}
			else
				cout<<"\nINVALID INDEX ";
		}
		int retrieve(int i,int j){
				if(0<=i<n&&0<=j<n){
				if(i==j)
					return arr[i];
				else
					return 0;
				}
		}
		void display(){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++)
					cout<<retrieve(x,y)<<" ";
				cout<<"\n";
			}
		}
};

int main()
{
	int i,j,val,size;
	char rep;
	cout<<"\nENTER THE SIZE OF MATRIX ";
	cin>>size;
	diagonal d(size);
do{
	cout<<"\nENTER THE INDEXES(i,j) ";
    cin>>i>>j;
    cout<<"\nENTER THE VALUE ";
    cin>>val;
    d.store(i,j,val);
    cout<<"\nDo you want to enter more? ";
    cin>>rep;
}while(rep=='y'||rep=='Y');
	d.display();
}
