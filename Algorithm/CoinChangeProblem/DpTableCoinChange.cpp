#include<iostream>
using namespace std;

const int numberOfCoins=3;
int coins[numberOfCoins]={1,2,5};
int amount=12;

void printTable(int dpTable[]){
	for(int k=0;k<amount+1;k++){
		cout<<dpTable[k]<<" ";
	}
	cout<<"\n";
}

int combos(){
	int dpTable[amount+1];
	
	dpTable[0]=1;
	for(int k=1;k<amount+1;k++){
		dpTable[k]=0;
	}
	
	for(int i=0;i<numberOfCoins;i++){
		for(int j=1;j<amount+1;j++){
			if(j>=coins[i])
				dpTable[j]+=dpTable[j-coins[i]];
			
			printTable(dpTable);
		}
	}
	
	return dpTable[amount];
}

int main(){
	cout<<combos();
}
