#include<iostream>
using namespace std;

class lowtri{
	int n;
	int *arr;
	public:
		lowtri(int size){
			n=size;
			arr=new int[(size*(size+1))/2];
			for(int i=0;i<(size*(size+1))/2;i++)
				arr[i]=0;
		}
		void store(int i,int j,int val){
			if(0<=i<=n-1&&0<=j<=n-1){
				if(i>=j){
					arr[(i*(i+1))/2+j]=val;
				}
				else{
					if(val!=0)
						cout<<"\nELEMENT ENTERED IS NOT AT LOWER TRIANGULAR POSITION ";
				}
			}
			else
				cout<<"\nINVALID INDEX ";
		}
		int retrieve(int i,int j){
				if(0<=i<n&&0<=j<n){
				if(i>=j)
					return arr[(i*(i+1))/2+j];
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
	lowtri l(size);
do{
	cout<<"\nENTER THE INDEXES(i,j) ";
    cin>>i>>j;
    cout<<"\nENTER THE VALUE ";
    cin>>val;
    l.store(i,j,val);
    cout<<"\nDo you want to enter more? ";
    cin>>rep;
}while(rep=='y'||rep=='Y');
	l.display();
}
