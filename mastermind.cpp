#include <iostream>
#include <cmath> 
#include <stdlib.h> 
#include <string.h>

using namespace std;
int main(){
	char condit;
	int seed, rng, stdround, round;
	int arr[4],tmp[4];
	bool play=true;
	stdround=12;
	cout<<"Enter seed: ";
	cin>>seed;
	cout<<endl;
	srand(seed);
	while (play==true){
		for (int i = 0; i<4;i++){
		arr[i]=rand()%6+1;
		}
		cout<<"Mastermind\nEnter four digits (1-6) separated by a space\n--------------------------------------------\n";
		for(round=0;round<stdround+1;round++){
			if (tmp[0]==arr[0]&&tmp[1]==arr[1]&&tmp[2]==arr[2]&&tmp[3]==arr[3])
			{
				cout<<"Congratulations! You win in "<< round<< " round(s)!\nSecret code:";
				for (int i = 0; i<4;i++){
				cout<<arr[i]<<" ";
				}
			cout<<"\nPlay again? (y)es or (n)o: ";
			cin>>condit;
				if(condit=='y'){
					cout<<"\n";
					play=true;
					break;
					}
			else if(condit=='n'){
				cout<<"\n";
				play=false;
				break;
			}
		}
		else if(round==stdround){
			cout<<"You lose!\nSecret code:";
			for (int i = 0; i<4;i++){
			cout<<arr[i]<<" ";
			}
			cout<<"\nPlay again? (y)es or (n)o: ";
			cin>>condit;
			if(condit=='y'){
			cout<<"\n";
			play=true;
			}
			else if(condit=='n'){
			cout<<"\n";
			play=false;
			}
	}
	else {
	cout<<"Round "<<round+1<<":\nEnter guess: ";
		for (int j = 0; j<4;j++){
		cin>>tmp[j];	
		}
	int checknum=0,checkpo=0;
	bool checkarr[4], checktmp[4];
		for (int i=0;i<4;i++){
			if(tmp[i]==arr[i])
			{
			checkarr[i]=true;
			checknum+=1;
			checkpo+=1;
			}
		}
	/* 
	next part may need some explanation
	tmp array is used to hold user input
	arr array is used to hold secret code
	checkarr is used to check the boolean relationship between tmp and arr
	if elemnt in tmp is used to compare element in arr and is successfully found, the checkarr will then update to TRUE
	if the elemnet is on right position and is right number, checknum and checkpo will add 1
	if the element is right number but wrong position, only checknum will add 1
	
	{
	for instance
	
	tmp[0]!=arr[0] 
	(checkarr[0]!=true)
	but tmp[0]==arr[1]
	also need to check chararr[1]!=TRUE, since if chararr[1] is TRUE means tmp[1]==arr[1], and thus will cause fail
	if both condition fit, then checknum add 1
	
	}
	
	however, checktmp is also needed
	
	{
	for instance
	
	tmp[1]!=arr[1] 
	(checkarr[1]!=true)
	tmp[1]==arr[2]
	then checknum add 1
	
	but if we do checkarr[2]=TRUE (mark that no need to compare arr[2])
	when we need to compare tmp[2] with any arr[i] and still checking checkarr[2], the case failed
	since checkarr[i] is used to check tmp[i]=arr[i]
	it should not used to check tmp[j]=arr[i], where j!=i
	so checktmp[] is declared to do it
	
	in this case
	update checktmp[2]=TRUE instead of checkchar
	and when checktmp[2]==TRUE, other element in tmp[] no need to compare with arr[2]
	
	}
	therefore, three condition is needed to check
	*/
	if (tmp[0]==arr[1]&&checkarr[0]!=true&&checkarr[1]!=true){
		checknum+=1;
		checktmp[1]=true;
	}
	else if (tmp[0]==arr[2]&&checkarr[0]!=true&&checkarr[2]!=true){
		checknum+=1;
		checktmp[2]=true;
	}
	else if (tmp[0]==arr[3]&&checkarr[0]!=true&&checkarr[3]!=true){
		checknum+=1;
		checktmp[3]=true;
	}
	if (tmp[1]==arr[0]&&checkarr[1]!=true&&checktmp[0]!=true&&checkarr[0]!=true){
		checknum+=1;
		checktmp[0]=true;
	}
	else if (tmp[1]==arr[2]&&checkarr[1]!=true&&checktmp[2]!=true&&checkarr[2]!=true){
		checknum+=1;
		checktmp[2]=true;
	}
	else if (tmp[1]==arr[3]&&checkarr[1]!=true&&checktmp[3]!=true&&checkarr[3]!=true){
		checknum+=1;
		checktmp[3]=true;
	}
	if (tmp[2]==arr[0]&&checkarr[2]!=true&&checktmp[0]!=true&&checkarr[0]!=true){
		checknum+=1;
		checktmp[0]=true;
	}
	else if (tmp[2]==arr[1]&&checkarr[2]!=true&&checktmp[1]!=true&&checkarr[1]!=true){
		checknum+=1;
		checktmp[1]=true;
	}
	else if (tmp[2]==arr[3]&&checkarr[2]!=true&&checktmp[3]!=true&&checkarr[3]!=true){
		checknum+=1;
		checktmp[3]=true;
	}
	if (tmp[3]==arr[0]&&checkarr[3]!=true&&checktmp[0]!=true&&checkarr[0]!=true){
		checknum+=1;
		checktmp[0]=true;
	}
	else if (tmp[3]==arr[1]&&checkarr[3]!=true&&checktmp[1]!=true&&checkarr[1]!=true){
		checknum+=1;
		checktmp[1]=true;
	}
	else if (tmp[3]==arr[2]&&checkarr[3]!=true&&checktmp[2]!=true&&checkarr[2]!=true){
		checknum+=1;
		checktmp[2]=true;
	}
	
	if(checknum==4&&checkpo==4)
	cout<<"B B B B"<<endl;
	else if(checknum==4&&checkpo==3)
	cout<<"B B B W"<<endl;
	else if(checknum==4&&checkpo==2)
	cout<<"B B W W"<<endl;
	else if(checknum==4&&checkpo==1)
	cout<<"B W W W"<<endl;
	else if(checknum==4&&checkpo==0)
	cout<<"W W W W"<<endl;
	else if(checknum==3&&checkpo==3)
	cout<<"B B B"<<endl;
	else if(checknum==3&&checkpo==2)
	cout<<"B B W"<<endl;
	else if(checknum==3&&checkpo==1)
	cout<<"B W W"<<endl;
	else if(checknum==3&&checkpo==0)
	cout<<"W W W"<<endl;
	else if(checknum==2&&checkpo==2)
	cout<<"B B"<<endl;
	else if(checknum==2&&checkpo==1)
	cout<<"B W"<<endl;
	else if(checknum==2&&checkpo==0)
	cout<<"W W"<<endl;
	else if(checknum==1&&checkpo==1)
	cout<<"B"<<endl;
	else if(checknum==1&&checkpo==0)
	cout<<"W"<<endl;
	else if(checknum==0&&checkpo==0)
	cout<<""<<endl;
	for (int i=0;i<4;i++){
		checkarr[i]=false;
		checktmp[i]=false;
	}
	cout<<"--------------------------------------------"<<endl;
	}
	}
	}	
	system("pause");

	return 0;
}
