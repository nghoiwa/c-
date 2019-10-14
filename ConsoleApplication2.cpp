// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int power(int base, int pow) {
	int a;
	a = base;
	if (pow == 0) {
		base = 1;
	}
	else {
		for (int i = 0; i < pow - 1; i++) {
			base = base * a;
		}
	}
	return base;
}
int status(int board, int pos) {
	int num;
	num = (board / (power(10, 9-pos)))%10;
	return num;
	
}
void printboard(int board) {
	int tmpboard,tmpboard2,j;
	tmpboard2=board;
	j=0;
	while(tmpboard2>0){
		tmpboard2 = tmpboard2 / 10;
		j+=1;
	}
	if(j==9){
	for (int i = 9; i > 0; i--) {
		tmpboard = board / (power(10, i-1));
		cout << tmpboard % 10;
		if (i == 7 ) {
			cout << "\n";
			cout << "|\\|/|\n";
		}
		else if (i==4){
			cout <<"\n";
			cout << "|/|\\|\n";
		}
		else if (i == 1) {
			continue;
		}
		else {
			cout << "-";
		}
	}
	}
	else if (j<9){
		for (int i = 9; i > 0; i--) {
		
		if ((i == 7 )&&i>j) {
			cout << "0";
			cout << "\n";
			cout << "|\\|/|\n";
		}
		else if ((i == 4)&&i>j) {
			cout << "0";
			cout << "\n";
			cout << "|/|\\|\n";
		}
		else if (i>j&&(i != 7 || i != 4)){
			cout << "0";
			cout << "-";
		}
		else if ((i == 7 || i == 4)&&i<=j) {
			tmpboard = board / (power(10, i-1));
			cout << tmpboard % 10;
			cout << "\n";
			cout << "|\\|/|\n";
		}
		else if (i == 1) {
			tmpboard = board / (power(10, i-1));
			cout << tmpboard % 10;
		}
		else {
			tmpboard = board / (power(10, i-1));
			cout << tmpboard % 10;
			cout << "-";
		}
	}
}
}
void updateboard(int &board, int from, int to, int p) {
	board=board-power(10,9-from)*p;
	board=board+power(10,9-to)*p;
}
int formline(int board) {
	int checkline=0;
	if(status(board,4)==1&&status(board,5)==1&&status(board,6)==1){
		checkline=1;
	}
	else if(status(board,7)==1&&status(board,8)==1&&status(board,9)==1){
		checkline=1;
	}
	else if(status(board,1)==1&&status(board,4)==1&&status(board,7)==1){
		checkline=1;
	}
	else if(status(board,2)==1&&status(board,5)==1&&status(board,9)==1){
		checkline=1;
	}
	else if(status(board,3)==1&&status(board,6)==1&&status(board,9)==1){
		checkline=1;
	}
	else if(status(board,1)==1&&status(board,5)==1&&status(board,9)==1){
		checkline=1;
	}
	else if(status(board,3)==1&&status(board,5)==1&&status(board,7)==1){
		checkline=1;
	}
	else if(status(board,1)==2&&status(board,2)==2&&status(board,3)==2){
		checkline=2;
	}
	else if(status(board,4)==2&&status(board,5)==2&&status(board,6)==2){
		checkline=2;
	}
	else if(status(board,1)==2&&status(board,4)==2&&status(board,7)==2){
		checkline=2;
	}
	else if(status(board,2)==2&&status(board,5)==2&&status(board,9)==2){
		checkline=2;
	}
	else if(status(board,3)==2&&status(board,6)==2&&status(board,9)==2){
		checkline=2;
	}
	else if(status(board,1)==2&&status(board,5)==2&&status(board,9)==2){
		checkline=2;
	}
	else if(status(board,3)==2&&status(board,5)==2&&status(board,7)==2){
		checkline=2;
	}
	
	return checkline;
}
int main()
{
	int board;
	int inputfrom, inputto, inputp;
	bool checkinput=false;
	board = 111000222;
	inputp=1;
	int win=0;
	while(win==0){
	printboard(board);
	while (checkinput==false){
	cout << "\nPlayer "<<inputp<<" (from to): "; 
	cin >> inputfrom; 
	cin >> inputto; 
	if(status(board,inputfrom)==inputp&&status(board,inputto)==0){
		if(inputfrom==1&&(inputto==2||inputto==4||inputto==5)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==2&&(inputto==1||inputto==3||inputto==5)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==3&&(inputto==2||inputto==5||inputto==6)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==4&&(inputto==1||inputto==5||inputto==7)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==5){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==6&&(inputto==3||inputto==5||inputto==9)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==7&&(inputto==4||inputto==5||inputto==8)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==8&&(inputto==5||inputto==7||inputto==9)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else if(inputfrom==9&&(inputto==5||inputto==6||inputto==8)){
			updateboard(board,inputfrom, inputto, inputp);
			break;
		}
		else{
			cout << "Invalid. Try again!";
			continue;
		}
	}
	else{
		cout << "Invalid. Try again!";
		continue;
	}
	}
	if(inputp==1){
		inputp=2;
	}
	else if (inputp==2){
		inputp=1;
	}
	if(formline(board)==1){
		printboard(board);
		cout<<"\nPlayer 1 wins!";
	}
	else if(formline(board)==2){
		printboard(board);
		cout<<"\nPlayer 2 wins!";
	}
	win=formline(board);
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
