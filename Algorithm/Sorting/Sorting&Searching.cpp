#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<vector>

using namespace std;


void Insertion_Sort(int arr[],int len)
{
	int j;
	int comp=0;
	for(int i=1;i<len;i++)
	{
		int temp_comp=comp;
		int temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j=j-1;
			++comp;
		}
		++comp;
		arr[j+1]=temp;
/*		cout<<"\n\nPASS - "<<i<<endl;
		for(int i=0;i<len;i++) 
			cout<<arr[i]<<" ";
		cout<<"\nComparisons:"<<comp-temp_comp;*/
	}
/*	cout<<"\n\nSwapped array is:";
	for(int i=0;i<len;i++) 
		cout<<arr[i]<<" ";*/
	cout<<"\nNo. of comparison:"<<comp;
}



void Selection_Sort(int arr[],int len)
{
	int j=0;
	int comp=0;
	for(int i=0;i<len;i++)
	{
		int temp_comp=comp;
		int min=arr[i];
		int k=i;
		for(int j=i+1;j<len;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
				k=j;
			}
			++comp;
		}
		if(k!=i)
		{
			arr[k]=arr[i];
			arr[i]=min;
		}
//		cout<<"\n\nPASS - "<<i<<endl;
//		for(int i=0;i<len;i++) 
//			cout<<arr[i]<<" ";
//		cout<<"\nComparisons:"<<comp-temp_comp;
	}
//	cout<<"\n\nSwapped array is:";
//	for(int i=0;i<len;i++) 
//		cout<<arr[i]<<" ";
	cout<<"\nNo. of comparison:"<<comp;
}


void Bubble_Sort(int arr[],int len)
{
	bool check=false;
	int comp=0;
	for(int i=0;i<len-1;i++)
	{
		check=false;
//		int temp_comp=comp;
//		cout<<"\n\nPASS - "<<i<<endl;
		for(int j=0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				check=true;
			}
			comp++;
		}
//		for(int i=0;i<len;i++) 
//			cout<<arr[i]<<" ";
//		cout<<"\nComparisons:"<<comp-temp_comp;
		if(!check)
		{
			break;
		}
	}
//	cout<<"\n\nSwapped array is:";
//	for(int i=0;i<len;i++) 
//		cout<<arr[i]<<" ";
	cout<<"\nNo. of comparison:"<<comp;
}


int cmp=0;
void Merge(int arr[],int l,int m,int r)
{
	int A[r-l+1];
	int i=l,j=m+1,k=0;
	while(i<=m && j<=r)
	{
		cmp++;
		if(arr[i]<=arr[j])
		{
			A[k++]=arr[i];
			i++;
		}
		else
		{
			A[k++]=arr[j];
			j++;
		}
	}
	cmp++;
	while(i<=m)
	{
		A[k++]=arr[i];
		i++;	
		cmp++;
	}
	cmp++;
	while(j<=r)
	{
		A[k++]=arr[j];
		j++;	
		cmp++;
	}
	cmp++;
	for(int i=0;i<k;i++)
		arr[l++]=A[i];
}
void Merge_Sort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		Merge_Sort(a,l,mid);
		Merge_Sort(a,mid+1,r);
		Merge(a,l,mid,r);
	}
}


void Swap(int &a,int &b)
{
	int temp=a;
		a=b;
		b=temp;
}
int Partition(int a[],int l,int r)	//first pivot element
{
	int i=l,j=r;
	int pivot=a[l];
	while(i<j)
	{
		while(pivot>=a[++i] );
		while(pivot<a[--j] );
		if(i<j)
		{
			Swap(a[i],a[j]);
		}
	}
	Swap(a[l],a[j]);
	return j;
}
int Partition2(int a[],int l,int r)		//last pivot element
{
	int i=l-1,j=l;
	int pivot=a[r-1];
	for(;j<r-1;j++)
	{
		if(a[j]<=pivot)
		{
			Swap(a[++i],a[j]);
		}
		cmp++;
	}
	Swap(a[i+1],a[r-1]);
	return i+1;
}
void Quick_Sort_1(int a[],int l,int r)
{
	if(l<r)
	{
		int j=Partition(a,l,r);
		Quick_Sort_1(a,l,j);
		Quick_Sort_1(a,j+1,r);
	}
}
void Quick_Sort_2(int a[],int l,int r)
{
	if(l<r)
	{
		int j=Partition2(a,l,r);
		Quick_Sort_2(a,l,j);
		Quick_Sort_2(a,j+1,r);
	}
}

void Heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;		//i starting from 0
	int r=2*i+2;
	if(++cmp && l<=n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(++cmp && r<=n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(++cmp && largest!=i)
	{
		Swap(arr[i],arr[largest]);
		Heapify(arr,n,largest);
	}
}
void Heap_Sort(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		Heapify(arr,n,i);
	}
	for(int i=n;i>=0;i--)
	{
		Swap(arr[0],arr[i]);
		Heapify(arr,--n,0);
	}
}

int Max_Val(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void Count_Sort(int arr[],int n)
{
	int temp[n];
	int max=Max_Val(arr,n);
	int count[max+1];
	for(int i=0;i<=max;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
	{
		++count[arr[i]];
	}
	for(int i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		temp[--count[arr[i]]]=arr[i];
	}
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}


void CountForRadix(int arr[],int n,int pos,int max)
{
	int temp[n];
	int count[max+1];
	for(int i=0;i<=max;i++)
		count[i]=0;
	for(int i=0;i<n;i++)
	{
		++count[(arr[i]/pos)%10];
	}
	for(int i=1;i<=max;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		temp[--count[(arr[i]/pos)%10]]=arr[i];
	}
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}
void Radix_Sort(int arr[],int n)
{
	int max=Max_Val(arr,n);
	for(int pos=1;(max/pos)>0;pos*=10)
	{
		CountForRadix(arr,n,pos,max);
	}
}

void Bucket_Sort(float arr[],int n)
{
	vector<float> b[n];
	
	for(int i=0;i<n;i++)
	{
		int index=n*arr[i];
		b[index].push_back(arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		sort(b[i].begin(),b[i].end());
	}
	
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			arr[k++]=b[i][j];
		}
	}
}

int Linear_Search(int arr[],int n,int el)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==el)
			return i; 
	}
	return -1;
}

int Binary_Search(int arr[],int n,int el)
{
	Bubble_Sort(arr,n);
	cout<<"\n\nSorted array is:";
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<" ";
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(el==arr[mid])
			return mid;
		else if(arr[mid]>el)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main()
{
	int n=0;
	cout<<"\nEnter No. of elements:";
	cin>>n;
	
	int *arr;
	arr=new int[n];
	
	srand(time(0));
	cout<<"\nElements are:";
	for(int i=0;i<n;i++) 
	{
		arr[i]=rand()%n +1;
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	
	int choice;
	cout<<"\n-------------------------------MENU------------------------------\n1)Insertion Sort.";
	cout<<"\n2)Selection Sort.\n3)Bubble Sort.\n4)Merge Sort.\n5)Quick Sort(1st element pivot).";
	cout<<"\n6)Quick Sort(last element pivot).\n7)Heap Sort.\n8)Count Sort.\n9)Raddix Sort.";
	cout<<"\n10)Linear Search.\n11)Binary Search.\nEnter your choice:";
	cin>>choice;
	
	int el,pos;
	
	switch(choice){
		case 1: Insertion_Sort(arr,n);
				break;
		case 2: Selection_Sort(arr,n);
				break;
		case 3: Bubble_Sort(arr,n);
				break;
		case 4: Merge_Sort(arr,0,n-1);
				cout<<"\nNo. of comparisons in Merge Sort:"<<cmp;
				break;
		case 5: Quick_Sort_1(arr,0,n);
				cout<<"\nNo. of comparisons in Quick Sort:"<<cmp;
				break;
		case 6: Quick_Sort_2(arr,0,n);
				cout<<"\nNo. of comparisons in Quick Sort:"<<cmp;
				break;
		case 7: Heap_Sort(arr,n-1);
				cout<<"\nNo. of comparisons in Heap Sort:"<<cmp;
				break;
		case 8:Count_Sort(arr,n);
				break;
		case 9:Radix_Sort(arr,n);
				break;
	}
	
	if(choice == 10 || choice == 11){
		cout<<"\nEnter element to be searched:";
		cin>>el;
		if(choice == 10)
			pos=Linear_Search(arr,n,el);
		else
			pos=Binary_Search(arr,n,el);
			
		if(pos!=-1)
			cout<<"\nElement found at position:"<<pos;
		else
			cout<<"\nNot Found";
	}
	else if(choice<12 && choice>0){
		cout<<"\n\nSorted array is:";
		for(int i=0;i<n;i++) 
			cout<<arr[i]<<" ";
	}
	else
		cout<<"\nWrong Choice.\n";
}
