#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
// #include<dos.h>
using namespace std;
void spacing()
{
	cout<<"\n\t\t\t\t\t";
}
class person
{
	protected:
	string name;
	int aadhar_no;
	int mobile_no;
	
};
class customer : protected person
{
	protected :
		int total_cost;
};
class admin
{	
	protected :
	int salary;
	string type;
	public:
		admin()
		{
			if(type=="Manager")
			{
				salary=100000;
			}
			else if(type=="Concierge")
			{
				salary=60000;
			}
			else if(type=="Housekeeper")
			{
				salary=40000;
			}
		}
};
class hotel : protected customer 
{
	private:
	int room_no;
	int days;	
	public:
		void main_menu();		
		void book_room();			
		void display_record(); 		
		void display_rooms();			
		void edit();		
		int check_vacancy(int);			
		void modify_record(int);		
		void delete_record(int);		
		void print_bill(int);
		void restaurant_booking();
		void check_out();
		void customer_options();
		void admin_options();
};
void hotel :: main_menu()
{
	system("cls");
	spacing();
	cout<<"********** Welcome to La Paricien *********** ";
	spacing();
	cout<<"**** Main Menu **** ";
	spacing();
	cout<<"1 . customer ";
	spacing();
	cout<<"2. Admin ";
	spacing();
	int choice;
	do
	{
		cout<<"Enter choice : ";
		cin>>choice;
		if(choice==1)
		customer_options();
		//else if(choice==2)
		//admin_option();
		else
		{
			spacing();
			cout<<"Invalid entry";
			spacing();
			cout<<"Enter again";
			spacing();
		}
	}while(choice!=1 && choice!=2);
};
void hotel :: customer_options()
{
	system("cls");
	spacing();
	cout<<"***** Customer Menu *****";
	spacing();
	cout<<"1. Book Room ";
	spacing();
	cout<<"2. Restaurant booking";
	spacing();
	cout<<"3. Check out ";
	spacing();
	int num;
	do
	{
		cout<<"Enter choice : ";
		cin>>num;
		if(num==1)
		book_room();
		//else if(num==2)
		//restaurant_booking();
		//else if(num==3)
		//check_out;
		else
		{
			spacing();
			cout<<"Invalid entry";
			spacing();
			cout<<"Enter again";
			spacing();
		}
	}while(num!=1 && num!=2 && num!=3);
}
void hotel::display_rooms(){
ifstream fin("example.txt",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";


while(!fin.eof())
{
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t\t\t"<<aadhar_no<<"  "<<mobile_no<<" "<<total_cost<<" "<<days;
fin.read((char*)this,sizeof(hotel));
}
fin.close();
}
void hotel :: book_room()
{
	system("cls");
	// ofstream outfile("example.txt",ios::app);
	ofstream outfile("example.txt",ios::app);
	spacing();
	cout<<"***** Rooms Available *****";
	spacing();
	cout<<"1. Single Room";
	spacing();
	cout<<"2. Duplex ";
	spacing();
	cout<<"3. Suite";
	spacing();
	cout<<"4. luxury";
	int num,flag;
	do
	{
		spacing();
		cout<<"Enter your choice : ";
		cin>>num;
		if(num==1)
		{
			for(int i=1;i<=50;i++)
			{
				flag=check_vacancy(i);
				if(flag==0)
				{
					room_no=i;
					cout<<room_no;
					break;
				}
			}
			if(flag==1)
			{
				spacing();
				cout<<"**** Sorry !!! No rooms available ****";
				spacing();
				cout<<"Select another room type";
				num=4;
		    }
		}
		else if(num==2)
		{
			for(int i=51;i<=100;i++)
			{
				flag=check_vacancy(i);
				if(flag==0)
				{
					room_no=i;
				}
			}
			if(flag==1)
			{
				spacing();
				cout<<"**** Sorry !!! No rooms available ****";
				spacing();
				cout<<"Select another room type";
				num=4;
		    }
		}
		else if(num==3)
		{
			for(int i=101;i<=150;i++)
			{
				flag=check_vacancy(i);
				if(flag==0)
				{
					room_no=i;
				}
			}
			if(flag==1)
			{
				spacing();
				cout<<"**** Sorry !!! No rooms available ****";
				spacing();
				cout<<"Select another room type";
				num=4;
		    }
		}
	}while(num!=1 && num!=2 && num!=3);
	spacing();
	cout<<"**** Enter Details *****";
	spacing();
	cout<<"Enter Name : ";
	cin>>name;
	spacing();
	cout<<"Enter aadhar number : ";
	cin>>aadhar_no;
	spacing();
	cout<<"Enter mobile number : ";
	cin>>mobile_no;
	spacing();
	total_cost=1000;
	days=10;
	outfile.write((char*)this,sizeof(hotel));
	cout<<"Room is booked !!!";
	spacing();
	cout<<"Press any key to continue !!!";
    display_rooms();
	outfile.close();
}

int hotel::check_vacancy(int r)
{

	int flag=0;
	ifstream infile("example.txt",ios::in);
	while(!infile.eof())
	{
		infile.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			flag=1;
			break;
    	} 
	}
	infile.close();
	return(flag);	
}
int main()
{
	hotel person;
	person.main_menu();
	return 0;
}
