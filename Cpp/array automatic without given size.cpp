#include <iostream>
#include <conio.h>
using namespace std;
struct node 
{
	int data;
	node *next;
};
class student
{
	private:
		node *ptr;
	public:
		student()
		{
			ptr=NULL;
		}
/*		student()
		{	
			int a;
			cout<<"Enter the 1st Student CNIC to Register : ";
			cin>>a;
			ptr=new node();
			ptr->data=a;
			ptr->next=NULL;
		}*/
		student(student & d)
		{
			cout<<"copy constructor calls"<<endl;
			ptr=new node();
			ptr->data=d.ptr->data;
			node *temp1=d.ptr;
			node *temp2=ptr;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
				temp2->next=new node();
				temp2=temp2->next;
				temp2->data=temp1->data;
				temp2->next=NULL;
			}
		}
		student& operator=(student & d)
		{
			cout<<"Assignment Operator Overload"<<endl;
			ptr=new node();
			ptr->data=d.ptr->data;
			node *temp1=d.ptr;
			node *temp2=ptr;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
				temp2->next=new node();
				temp2=temp2->next;
				temp2->data=temp1->data;
				temp2->next=NULL;
			}
		}
		int creatlist()
		{
			int c=1,x;
			do
			{
				if(c==1)
				{
					cout<<"Enter the data ";
					cin>>x;
					reg(x);
				}
				cout<<"type 1 for more entry"<<endl;
				cin>>c;
			}while(c==1);
		}
		bool isempty()
		{
				if(ptr==NULL)
			{
			
				return true;
			}
			else
			{
			
				return false;
			}
		}
		int findlength()
		{
			node *temp=ptr;
			int i=0;
			while(temp!=NULL)
			{
				temp=temp->next;
				i++;
			}
			cout<<"Length is "<<i<<endl;
			return i;
		}
		void reg(int d)
		{
			cout<<"\t\t\tWelcome To Exam Hall \nNew Entry Begins \n";
			if(ptr==NULL)
			{
				ptr=new node();
				ptr->data=d;
				ptr->next=NULL;
			}
			else
			{
				node *temp=ptr;
				while(temp->next!=NULL)
				
				{
					temp=temp->next;
				}
			
				temp->next=new node ();
				temp->next->data=d;
				temp->next->next=NULL;
			}
		}
		int insertfirst(int d)
		{
			if(ptr==NULL)
			{
				ptr=new node();
				ptr->data=d;
				ptr->next=NULL;
			}
			else
			{
				node *temp=new node();
				temp->data=d;
				temp->next=ptr;
				ptr=temp;
			}
		}
		int insertlast(int d)
		{
			if(ptr==NULL)
			{
				ptr=new node();
				ptr->data=d;
				ptr->next=NULL;
			}
			else
			{
				node *temp=ptr;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=new node ();
				temp->next->data=d;
				temp->next->next=NULL;
			}
		}
		int insertat(int d,int index)
		{
			if(index==1)
			{
				insertfirst(d);
			}
			else
			{
				node * temp=ptr;
				int i=0;
				while(temp!=NULL)
				{
					i++;
					temp=temp->next;
				}
				if(i<index)
				{
					cout<<"NOt exist here out of range index entered by you"<<endl;
				}
				else if (i==index)
				{
					insertlast(d);
				}
				else if (i>index)
				{
					node *ptr1=new node();
					ptr1->data=d;
					ptr1->next=NULL;
					node *temp=ptr;
					for(int i=1 ; i<index-1 ; i++)
					{
						temp=temp->next;
					}
					ptr1->next=temp->next;
					temp->next=ptr1;
				}
			}
		}
		int deletefirst()
		{
			if(ptr==NULL)
			{
				cout<<"Not entry exist:";
			
			}
			else if(ptr->next==NULL)
			{
				int x=ptr->data;
					ptr=NULL;
					delete ptr;
					cout<<"Data in deleted entry is : ";
					return x;
			}
			else if (ptr->next!=NULL)
			{
				node *temp=ptr;
				int x=ptr->data;
				ptr=temp->next;
				temp->next=NULL;
				delete temp;
				return x;
			}
		}
		int deletelast()
		{
			
			 if(ptr!=NULL)
			{
				 if(ptr->next==NULL)
				{
					int x=ptr->data;
					ptr=NULL;
					delete ptr;
					cout<<"Data in deleted entry is : ";
					return x;
				
				}
				else
				{
					node *temp=ptr;
					node *temp1=ptr;
					while(temp->next!=NULL)
					{	
						temp1=temp;
						temp=temp->next;
					}
				
				int x=temp->data;
				delete temp;
				temp=NULL;
				temp1->next=NULL;
				cout<<"Data in deleted entry is : "<<x<<endl;
				return x;
				}
			}
			else if(ptr==NULL)
			{
				cout<<"This Hall is empty no node is exist\n";
			}	
		}
		int deleteat(int index)
		{
			if(index==1)
			{
				deletefirst();
			}
			else
			{
				node * temp=ptr;
				int i=0;
				while(temp!=NULL)
				{
					i++;
					temp=temp->next;
				}
				if(i<index)
				{
					cout<<"NOt exist here out of range index entered by you";
				}
				else if (i==index)
				{
					deletelast();
				}
				else if (i>index)
				{
					temp=ptr;
					i=2;
					while(i<index)
					{
						temp=temp->next;
						i++;
					}
					node *ptr1=temp->next;
					temp->next=ptr1->next;
					ptr1->next=NULL;
					delete ptr1;
					
				}
			}
		}
		int sorting()
		{
			cout<<"Sorting Begins\n";
			int a;
			node *temp1=ptr;
			node *temp=ptr;
			int l=findlength();
			for(int i=0 ; i<l ; i++)
			{
				while(temp1->next!=NULL)
				{
					if(temp1->next->data<temp1->data)
					{
						a=temp1->next->data;
						temp1->next->data=temp1->data;
						temp1->data=a;
					}
					temp1=temp1->next;	
				}
				temp1=ptr;
			}
		}
		int insertsorted(int d)
		{
			sorting();
			node * ptr1=new node();
			ptr1->data=d;
			ptr1->next=NULL;
			node * temp = ptr;
			while(temp!=NULL)
			{
				if(temp->next->data>=d)
				{
					ptr1->next=temp->next;
					temp->next=ptr1;
					break;
				}
				temp=temp->next;
			}
			cout<<endl;
		}
		int search(int v)
		{
			int index=1,c=0;
			node *temp=ptr;
		
			while(temp->next!=NULL)
			{
				if(v==temp->data)
				{
					cout<<"Found at "<<index<<endl;
					c=0;
				}
				else
				{
					 c=1;
				}
				temp=temp->next;
				index++;
				
			}
			if(c==1)
			{
				cout<<"Not Found "<<endl;
			}
			cout<<endl;
		}
		void disply()
		{
			cout<<"\nCurrent Status of Exam Hall: \n";
			if(ptr==NULL)
			{
				cout<<"No Student is till Register.\n ";
			}
			node *temp=ptr;	
			while(temp!=NULL)
			{
					cout<<"Data in block is "<<temp->data<<"."<<endl;
				temp=temp->next;
			}
			cout<<endl;
		}
		int displyfirst()
		{
			cout<<"First entry is "<<ptr->data<<endl;
		}
		int displylast()
		{
			node *temp=ptr;
			while (temp->next!=NULL)
			{
				temp=temp->next;
			}
			cout<<"Last entry is "<<temp->data<<endl;
		}
		friend student & operator+(student & s1, student & s2)
		{
			node *temp1=s1.ptr;
			node *temp2=s2.ptr;
			while(temp1!=NULL)
			{
					cout<<temp1->data+temp2->data<<endl;
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
		~student()
		{
			cout<<"destructor calls";
			node *temp=ptr;
			while(temp!=NULL)
			{
				temp=temp->next;
				ptr->next=NULL;
				delete ptr;
				ptr=NULL;
				ptr=temp;
			}
		}
};
int main()
{
	int c=0, x;
	student a;
	do
	{
		if(c==1)
		{
			a.creatlist();
		}
		if(c==2)
		{
			a.deletefirst();
		}
		if(c==3)
		{
			a.deletelast();
		}
		if(c==4)
		{
			
			cout<<"Enter the Index at which you want to Delete the entry : ";
			cin>>x;
			a.deleteat(x);
		}
		if(c==5)
		{
			cout<<"Enter the data you want to insert at first : ";
			cin>>x;
			a.insertfirst(x);
		}
		if(c==6)
		{
			cout<<"Enter the data you want to inert at last : ";
			cin>>x;
			a.insertlast(x);
		}
		if(c==7)
		{
			int i;
			cout<<"Enter the index at which you want the insert : ";
			cin>>i;
			cout<<"Enter the data :";
			cin>>x;
			a.insertat(x,i);
		}
		if(c==8)
		{
			if(a.isempty()==0)
			{
				cout<<"No, Hall is not empty";
			}
			else
			{
				cout<<"yes, hall is empty";
			}
		}
		if(c==9)
		{
			a.findlength();
		}
		if(c==10)
		{
			cout<<"Enter the data you want to insert : ";
			cin>>x;
			a.insertsorted(x);
		}
		if(c==11)
		{
			cout<<"Enter the data you want to search : ";
			cin>>x;
			a.search(x);
		}
		if(c==12)
		{
			a.disply();
		}
		if(c==13)
		{
			cout<<"First entery is ";
			a.displyfirst();
		}
		if(c==14)
		{
			cout<<"Last entry is ";
			a.displylast();
		}
		if(c==15)
		{
			a.~student();
		}
		if(c==16)
		{
			a.sorting();
		}
		if(c==17)
		{
			break;
		}
		cout<<"\nType 1 \t for create the list \nType 2 \t for delete the first entry \nType 3 \t for delete the last entry \nType 4 \t to delete the entry at specific index \n";
		cout<<"Type 5 \t to insert the data at first block \nType 6 \t to insert the data at last block \nType 7 \t to insert the data at specific index \n";
		cout<<"Type 8 \t to check List is empty or not \nType 9 \t to find the length of list \nType 10 \t to insert the data sorted \nType 11 \t to search the data \n";
		cout<<"Type 12 \t to disply the current list \nType 13 \t to disply first data \nType 14 \t to disply the last data \nType 15 \t to calls the destructor\n";
		cout<<"Type 16 \t to Sort the List \nType 17 \t to Exit\n";
		cin>>c;		
	}while (c==1 || c==2 || c==3 || c==4 || c==5 || c==6 || c==7 || c==8 || c==9 || c==10 || c==11|| c==12 || c==13 || c==14 || c==15 || c==16 || c==17);
	
	student b;
	b.creatlist();
	b.disply();
	
	student e(b);
	e.disply();
}
//this aray has limit takes sze of the array its has a draw backs like if dont know limit then what shoud we do?
//extendalble situation is that it donttakes size memery alocates on new arrial only other wise dont take memory take inly that has data on it. like first come 1st block allocates when second comes 2nd allocates andd so n as studnets come memery allocates as well not loss in this caasse.
