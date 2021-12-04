#include<iostream>
using namespace std;

void bubblesort(int size, int arr[])
{
	int temp;
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	cout<<endl<<"Array after bubble sort will be : "<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void insertsort(int size, int arr[])
{
	int i, j, key;
	for(int i=1; i<size; i++)
	{
		key = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	cout<<endl<<"Array after insertion sort will be : "<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void selectsort(int size, int arr[])
{
	int i, j, index, temp;
	for(i=0; i<size-1; i++)
	{
		index = i;
		for(j=i+1; j<size; j++)
		{
			if(arr[index]>arr[j])
			index = j;
		}
		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
	cout<<endl<<"Array after selection sort will be : "<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
}

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int temp;
    int i = (low - 1);   
    for (int j = low; j <= high - 1; j++)  
    {    
        if (arr[j] < pivot)  
        {  
            i++; 
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; 
        }  
    } 
		temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;  
    return (i + 1);  
}  

void quicksort(int arr[], int low, int high)
{
	 if (low < high)  
    {   
        int pi = partition(arr, low, high);  
        quicksort(arr, low, pi - 1);  
        quicksort(arr, pi + 1, high); 
    }  
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {  
        int m = (l+r)/2;
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
} 

int linearSearch(int size, int arr[], int val)
{
	for(int i=0; i<size; i++)
	{
		if(arr[i]==val)
		return 1;
	}
	return 0;
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = (l + r) / 2; 
        if (arr[mid] == x) 
            return 1; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return 0; 
} 

int main()
{
	int *arr; 
	int size;
	int val;
	cout<<"Enter the size of the array : ";
	cin>>size;
	arr = new int[size];
	cout<<endl<<"Enter the array :"<<endl;
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<endl;
	cout<<endl<<"Enter the number you want to search"<<endl;
	cin>>val;
	int res = binarySearch(arr, 0, size, val);
	if(res == 1)
	cout<<"Element found";
	else
	cout<<"Element not found";
	return 0;
}
