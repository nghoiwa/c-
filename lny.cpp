#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long int y, m, a, b, c, j, d, n, day,date,month;
	long double	k;
	cout << "Enter a year: ";
	cin >> y;
	
	m = 1;
	month=m;
	d = 21;
	a = floor((14 - m) / 12);
	b = m + 12 * a - 3;
	c = y + 4800 - a;
	j = d + floor((153 * b + 2) / 5) + 365 * c + floor(c / 4) - floor(c / 100) + floor(c / 400) - 32045;
	k = (j - 2451551.0923611) / 29.530587981;
	n = floor(29.530587981*(ceil(k) - k));
	day = ((j+n) % 7) + 1;
	cout << "LNY of "<<y<<" is around: ";
	switch(day){
		case 1:
			cout << "Mon";
			break;
		case 2:
			cout << "Tue";
			break;
		case 3:
			cout << "Wed";
			break;
		case 4:
			cout << "Thu";
			break;
		case 5:
			cout << "Fri";
			break;
		case 6:
			cout << "Sat";
			break;
		default:
			cout << "Sun";
			break;
	}
	
	cout<<", ";
	
	date=d+n;
	if(date>31){
		month+=1;
		date-=31;
	}
	cout<<date<<" ";
	
	switch(month){
		case 1:
			cout<<"Jan ";
			break;
		case 2:
			cout<<"Feb ";
			break;
	}
	cout<<y;
	return 0;
}

