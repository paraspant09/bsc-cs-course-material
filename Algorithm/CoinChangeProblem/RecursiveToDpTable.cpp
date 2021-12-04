#include<iostream>
using namespace std;

const int numberOfCoins=3;
const int amount=12;
int coins[numberOfCoins]={1,2,5};
int dpTable[numberOfCoins][amount+1];

void printTable(int dpTable[][amount+1]){
	for(int i=0;i<numberOfCoins;i++)
	{
		for(int j=0;j<=amount;j++)
		{
			cout<<dpTable[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n";
}

int combos(int index,int amount){
//	printTable(dpTable);
	if(amount==0)
		return 1;
	if(index>=numberOfCoins || amount<0)
		return 0;
	if(dpTable[index][amount]!=-1)
		return dpTable[index][amount];
		
	int leftSubtreeAnswer=combos(index,amount-coins[index]);	//we are at left subtree take the coin from left subtree
	int rightSubtreeAnswer=combos(index+1,amount);		//to go to the right sub tree with same amount
	return dpTable[index][amount]=leftSubtreeAnswer+rightSubtreeAnswer;
}

int main(){
	for(int i=0;i<numberOfCoins;i++)
	{
		for(int j=0;j<=amount;j++)
		{
			dpTable[i][j]=-1;
		}
	}
	cout<<combos(0,amount);
}
