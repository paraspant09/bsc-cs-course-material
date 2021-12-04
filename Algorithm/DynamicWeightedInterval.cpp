#include<iostream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

int WeightedInterval(int V[],int P[],int n){
	int M[n];
	M[0]=0;
	
	for(int i=1;i<n;++i)
	{
		int previousValue=M[i-1];
		int newValue=V[i]+M[P[i]];
		if( previousValue > newValue )
			M[i]=previousValue;
		else
			M[i]=newValue;
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<M[i]<<" ";
	}
	
	return M[n-1];
}
//the scheduling must be such that a schedules preindex must not be greater than its index
int main(){
	int *start;		
	int *end;
	int *endIndeces;
	int *duration;
	int *PreIndex;
	int n;		//number of items
	
	cout<<"\nEnter number of Items:";
	cin>>n;
	
	start=new int[n];
	cout<<"\nEnter their start time:";
	for(int i=0;i<n;++i)
	{
		cin>>start[i];
	}
	
	end=new int[n];
	cout<<"\nEnter their end time:";
	for(int i=0;i<n;++i)
	{
		cin>>end[i];
	}
	
	duration=new int[n+1];
	duration[0]=0;
	for(int i=1;i<=n;++i)
	{
		duration[i]=end[i-1]-start[i-1];
	}
	
	endIndeces=new int[n];
	for(int i=0;i<n;++i)
		endIndeces[i]=i+1;
		
	for (int i = 0; i < n-1; i++)      
	    for (int j = 0; j < n-i-1; j++)  
	        if (end[j] > end[j+1]) {
	            swap(&end[j], &end[j+1]);   
	            swap(&endIndeces[j], &endIndeces[j+1]);   
			} 
	
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<endIndeces[i]<<" ";
//	}
	
	PreIndex=new int[n+1];
	PreIndex[0]=0;
	for (int i = 0; i < n; i++)    {
		int j;
		for (j = 0; j < n; j++)  
	    {
	    	if (end[j] > start[i]) {
	            break;
			} 
		}
		int a=i+1;
		int b=endIndeces[j-1];
		if(j==0)	PreIndex[i+1]=0;
		else if(a < b)
		{
			cout<<endl<<a<<" and "<<b<<" schedules must be swapped.";
			return 0;
		}
		else
			PreIndex[i+1]=b;
	}  
	
	cout<<endl<<"Preindexes:";
	for(int i=0;i<=n;i++){
		cout<<PreIndex[i]<<" ";
	}
	cout<<endl<<"Durations";
	for(int i=0;i<=n;i++){
		cout<<duration[i]<<" ";
	}
	
	cout<<"\nTotal Scheduled time :"<<WeightedInterval(duration,PreIndex,n+1);
}
