#include<iostream>
using namespace std;

const int numberOfCoins=2;
int coins[numberOfCoins]={1,2};

int combos(int index,int amount){
	if(amount==0)
		return 1;
	if(index>=numberOfCoins || amount<0)
		return 0;
	
	int leftSubtreeAnswer=combos(index,amount-coins[index]);	//we are at left subtree take the coin from left subtree
	int rightSubtreeAnswer=combos(index+1,amount);		//to go to the right sub tree with same amount
	return leftSubtreeAnswer+rightSubtreeAnswer;
}

int main(){
	int amount=4;
	
	cout<<combos(0,amount);
}
