#include<iostream>
#include<conio.h>
using namespace std;
class testcenter
{
	private:
	string name;
	int *arr;
	int size;
	public:
			 
		void getid();
		void display();
		int length;
	testcenter()
	{
		cout<<"enter size =";
		cin>>size;
		arr=new int[size];
	    
	}
	testcenter (testcenter &t)
	{
		this->size=t.size;
		this->arr=new int[this->size];
		for(int i=0;i<t.length;i++)
		{
			this->arr[i]=t.arr[i];
			length++;
			this->length=t.length;
		}
	}
};
void testcenter::getid(){
	cout<<" enter length =";
	cin>>length;
	cout<<" enter size =";
	cin>>size;
}
void testcenter::display(){
	for(int i=0;i<=length;i++)
	cout<<arr[i];
}
int main()
{
	testcenter t;
	t.getid();
	cout<<" array of t=";
	t.display();
	testcenter t1(t);
	cout<<"\n array of t1=";
	t1.display();
	
	return 0;
}
