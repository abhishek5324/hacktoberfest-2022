#include <iostream>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;
class phone
{
	friend istream & operator>>(istream & ,phone &);
	friend ostream & operator<<(ostream &,const phone &);
	private:
		string exchange,aeracode,line,countrycode;
};
istream & operator>>(istream & input ,phone & p)
{ 
	input>>setw(3)>>p.countrycode;
	input>>setw(3)>>p.aeracode;
	input>>setw(3)>>p.exchange;
	input>>setw(4)>>p.line;
	return input;
}
ostream & operator<<(ostream & output,const phone & p)
{
	output<<p.countrycode<<" "<<p.aeracode<<" "<<p.exchange<<p.line;
	return output;
}

int main(int argc, char** argv) {
	phone p1;
	cin>>p1;
	cout<<p1;
	return 0;
}
