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
class uptri{
	int n;
	int *arr;
	public:
		uptri(int size){
			n=size;
			arr=new int[(size*(size+1))/2];
			for(int i=0;i<(size*(size+1))/2;i++)
				arr[i]=0;
		}
		void store(int i,int j,int val){
			if(0<=i<=n-1&&0<=j<=n-1){
				if(i<=j){
					arr[(j*(j+1))/2+i]=val;
				}
				else{
					if(val!=0)
						cout<<"\nELEMENT ENTERED IS NOT AT UPPER TRIANGULAR POSITION ";
				}
			}
			else
				cout<<"\nINVALID INDEX ";
		}
		int retrieve(int i,int j){
				if(0<=i<n&&0<=j<n){
				if(i<=j)
					return arr[(j*(j+1))/2+i];
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
class symmetric{
	int n;
	int *arr;
	public:
		symmetric(int size){
			n=size;
			arr=new int[(size*(size+1))/2];
			for(int i=0;i<(size*(size+1))/2;i++)
				arr[i]=0;
		}
		void store(int i,int j,int val){
			int temp;
			if(0<=i<=n-1&&0<=j<=n-1){
				if(i>=j)
					arr[(i*(i+1))/2+j]=val;
				else if(i<j)
					arr[(j*(j+1))/2+i]=val;
			}
			else
				cout<<"\nINVALID INDEX ";
		}
		int retrieve(int i,int j){
				if(0<=i<n&&0<=j<n){
				if(i>=j)
					return arr[(i*(i+1))/2+j];
				else if(i<j)
					return arr[(j*(j+1))/2+i];
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
	int num,i,j,val,size;
	char ans,rep;
	cout<<"\nENTER THE SIZE OF MATRIX ";
	cin>>size;
	diagonal d(size);
	lowtri l(size);
	uptri u(size);
	symmetric s(size);
	do
    {
        cout<<"\n\t\tMENU";
        cout<<"\n1. DIAGONAL MATRIX";
        cout<<"\n2. LOWER TRIANGULAR MATRIX";
        cout<<"\n3. UPPER TRIANGULAR MATRIX";
        cout<<"\n4. SYMMETRIC MATRIX";
        cout<<"\n5. EXIT";
        cout<<"\nEnter your choice: ";
        cin>>num;
        
        switch(num)
        {
        	case 1: do{
        				cout<<"\nENTER THE INDEXES(i,j) ";
        				cin>>i>>j;
        				cout<<"\nENTER THE VALUE ";
        				cin>>val;
        				d.store(i,j,val);
        				cout<<"\nDo you want to enter more? ";
        				cin>>rep;
						}while(rep=='y'||rep=='Y');
					d.display();
					break;
			case 2: do{
        				cout<<"\nENTER THE INDEXES(i,j) ";
        				cin>>i>>j;
        				cout<<"\nENTER THE VALUE ";
        				cin>>val;
        				l.store(i,j,val);
        				cout<<"\nDo you want to enter more? ";
        				cin>>rep;
						}while(rep=='y'||rep=='Y');
					l.display();
					break;
			case 3: do{
        				cout<<"\nENTER THE INDEXES(i,j) ";
        				cin>>i>>j;
        				cout<<"\nENTER THE VALUE ";
        				cin>>val;
        				u.store(i,j,val);
        				cout<<"\nDo you want to enter more? ";
        				cin>>rep;
						}while(rep=='y'||rep=='Y');
					u.display();
					break;
			case 4: do{
        				cout<<"\nENTER THE INDEXES(i,j) ";
        				cin>>i>>j;
        				cout<<"\nENTER THE VALUE ";
        				cin>>val;
        				s.store(i,j,val);
        				cout<<"\nDo you want to enter more? ";
        				cin>>rep;
						}while(rep=='y'||rep=='Y');
					s.display();
					break;
			case 5: exit(1);
					break;
			default:cout<<"\nINVALID CHOICE";
					break;
		}
		cout<<"\nDo you want to continue? ";
        cin>>ans;		
	}while(ans=='y'||ans=='Y');
}
