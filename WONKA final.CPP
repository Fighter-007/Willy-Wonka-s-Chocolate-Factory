// Program to aid in Willy Wonka's Chocolate factory management

// #include<stdlib.h>
// #include<iostream.h>
// #include<conio.h>
// #include<string.h>
// #include<process.h>
// #include<fstream.h>
// #include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

char pause;
string password;
char dept[20];
fstream f;
long k;

void pattern(int n){
	for(int i=0; i<50; i++){
		cout<<char(n)<<" ";
		for(k=0; k<1e7*3; k++);
	}
}

void dep();

class _sale   // To differ its name from function sale
{
	protected:
		string code; // Code of the item sold
		string country;
		long qty;
		long amt; //amount
		string date;
	public:
		void sinput()
		{
			cout<<"\nEnter the details: ";
			cout<<"\nCode of the item sold (1-23): ";
			cin>>code;
			cout<<"\nCountry: ";
			cin>>country;
			cout<<"\nQuantity(kg): ";
			cin>>qty;
			cout<<"\nAmount(Rs): ";
			cin>>amt;
			cout<<"\nDate of sale (MM-DD-YYYY): ";
			cin>>date;
		}

		void soutput()
		{
			cout<<"\n"<<code<<'\t'<<country<<"\t\t"<<qty<<'\t'<<amt<<'\t'<<date<<'\n';

			// cout<<"\nCode of the item sold: "<<code;
			// cout<<"\nCountry: "<<country;
			// cout<<"\nQuantity(kg): "<<qty;
			// cout<<"\nAmount(Rs): "<<amt;
			// cout<<"\nDate of sale(MM-DD-YYYY): "<<date;
		}
} s;

// In the above class reusable(inheritable) variables are declared under protected section.

class purch : public _sale    //Inheriting a class publicly
{                             // Class to take in purchase details

	public:
	   //	char buy[30],item[30];
		void pinput()
		{
			cout<<"\nCountry: ";
			cin>>country;
			cout<<"\nEnter the item bought: ";
			cin>>code;
		     //	strcpy(item,buy);
			cout<<"\nQuantity(kg): ";
			cin>>qty;
			cout<<"\nAmount(Rs): ";
			cin>>amt;
			cout<<"\nDate of purchase (MM-DD-YY): ";
			cin>>date;

		}
		void poutput()
		{
			cout<<"\nCountry: "<<country;
			cout<<"\nItem: "<<code;
			cout<<"\nQuantity(kg): "<<qty;
			cout<<"\nAmount(Rs): "<<amt;
			cout<<"\nDate of purchase(MM-DD-YYYY) : "<<date;
		}

}p;

class fund                //Class to record the charity funds donated by the factory
{
	long amt; //Donation amount
	char org[50]; //name of organization
	char date[11];

	public:
		void finput()
		{
			cout<<"\nEnter details: ";
			cout<<"\nName of organization: ";
			gets(org);
			cout<<"\nAmount donated (Rs): ";
			cin>>amt;
			cout<<"\nDate (MM-DD-YYYY): ";
			gets(date);
		}
		void foutput()
		{
			cout<<"\nName of organization: "<<org;
			cout<<"\nAmount donated: "<<amt;
			cout<<"\nDate (MM-DD-YYYY): "<<date<<endl;
		}
}c;

class ol //Oompa loompa
{
	int code; // code of department
	int no; //oompa loompa number
	int hr; //No. of hours worked
	int sal; //salary
	char date[10];
	public:
		void oinput()
		{
			cout<<"\nEnter details: ";
			cout<<"\nDate (MM-DD-YYYY): ";
			gets(date);
			cout<<"\nCode of department(1-10): ";
			cin>>code;
			cout<<"\nOompa loompa number: ";
			cin>>no;
			cout<<"\nNo. of hours worked on this day: ";
			cin>>hr;

		}
		int getsal()
		{
			if(code>=1 && code<=5)
				return(150);
			else if(code>=6 && code<=10)
				return(200);
			else
				return(0);
		}
		void ooutput()
		{
			cout<<"\nDate (MM-DY-YYY): "<<date;
			cout<<"\nCode of department: "<<code;
			cout<<"\nOompa loompa number: "<<no;
			cout<<"\nNo. of hours worked on this day: "<<hr;
			sal=getsal()*hr;
			cout<<"\nSalary for the day(MM-DD-YYYY): "<<sal<<endl;
		}
} o;

class winner       // To keep record of the details of the winners.
{
	int age;
	long tno;  // Ticket number
	char phone[11];
	char address[100];

	protected:

		char email[30];

	public:

		void input()
		{
			cout<<"\nEnter your age: ";
			cin>>age;
			cout<<"\nEnter your address: ";
			gets(address);
			cout<<"\nEnter the ticket number: ";
			cin>>tno;
			cout<<"\nEnter your phone number: ";
			gets(phone);
			cout<<"\nEnter your e-mail ID: ";
			gets(email);
		}

		void output()
		{
			cout<<"\nHere are your details: "<<endl;
			cout<<"\nAge: "<<age<<endl;
			cout<<"Address: "<<address<<endl;
			cout<<"Ticket No.: "<<tno<<endl;
			cout<<"Phone no.: "<<phone<<endl;
			cout<<"Email: "<<email<<endl;
		}

		long ticket()
		{
			return tno;
		}

		void _age()
		{
			cout<<"\nDo you want to change age? (Y/N) ";
			cin>>pause;
			if(pause=='y' || pause=='Y')
			{
				cout<<"\nEnter new age: ";
				cin>>age;
			}
		}

		void _address()
		{
			cout<<"\nDo you want to change address? (Y/N) ";
			cin>>pause;
			if(pause=='y' || pause=='Y')
			{
				cout<<"\nEnter new address: ";
				gets(address);
			}
		}

		void _phone()
		{
			cout<<"\nDo you want to change phone no.? (Y/N) ";
			cin>>pause;
			if(pause=='y' || pause=='Y')
			{
				cout<<"\nEnter new phone no. : ";
				gets(phone);
			}
		}

		void _email()
		{
			cout<<"\nDo you want to change email? (Y/N) ";
			cin>>pause;
			if(pause=='y' || pause=='Y')
			{
				cout<<"\nEnter new email: ";
				gets(email);
			}
		}

} w;	 //end of class

void sale()          //
{

	system("cls");
	int i;
	f.open("sale.dat", ios::in | ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError";
		return;
	}

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tSALE RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	while(1)
	{
		cout<<"\nWant to enter records? (Y/N)";
		cin>>pause;
		if(pause=='n' || pause=='N')
			break;
		s.sinput();
		f.write((char *) &s, sizeof(s));
	}
	system("cls");
	f.seekg(0, ios::beg);
		cout<<"\nThe sales are as follows: "<<endl;

	pattern(21);
	cout<<"\n\n\t\t\t\tSALE RECORDS"<<endl<<endl;
	pattern(21);
	
	cout<<"\n\nCode\tCountry\t\tQty\tAmount\tDate\n";
	while(f.read((char *) &s, sizeof(s)))
	{
		s.soutput();
		cout<<endl;
	}
	f.close();
}

void purchase()
{
	system("cls");
	int i;
	f.open("purchase.dat",  ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError";
		return;
	}
	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tPURCHASE RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	while(1)
	{
		cout<<"\nWant to enter records? (Y/N)";
		cin>>pause;
		if(pause=='n' || pause=='N')
			break;
		p.pinput();
	       f.write((char *) &p, sizeof(p));

	}
	f.close();

	system("cls");
	f.open("purchase.dat", ios::in | ios::binary);
	if(!f)
		cout<<"ERROR: READ";
	cout<<"\nThe purchases are as follows: "<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tPURCHASE RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	f.seekg(0, ios::beg);
	while(f.read((char *) &p, sizeof(p)))
	{
		p.poutput();
		cout<<endl;
	}
	f.close();
}


void choose()        // Function to choose the 5 golden tickets using random function
{

while(1)
{
	system("cls");
	int i;
	long a,b,c,d;
	pattern(25);
	cout<<"\n\n\t\t\tChoosing the GOLDEN ticket WINNER!"<<endl<<endl;

	pattern(25);
	cout<<"\nWe will be using a random game to choose the five lucky Golden Ticket Winners!"<<endl;
	cout<<"\nThe number on the chocolate packs are from 1 to 1,00,000";
	cout<<"\nYou are requested to enter any number you fancy";
	cout<<"\nEnter a number";
	cin>>a;
	a=(a/5)+2;
	b=rand();
	while(b<a)
	{
		cout<<"\nEnter a random number.  ";
		cin>>c;
		d=d-(rand()*(b+c)*2)-a;
		cout<<"\nWant to enter again? (Y/N)"<<endl;
		cin>>pause;
		b++;
		if(pause=='n' || pause=='N')
			break;
	}
	d=d++;
	while(d>100000 || d<0)
	{
	      if(d>100000)
	      {
		d=d+a;
		d=d/1000;
	      }

	      if(d<=0)
	      {
		d=d+(a*b +c);
		d=d*(abs(a));
	      }
	}

	f.open("tickets.txt", ios::app);
	f<<"************************"<<endl;
	system("cls");
	cout<<endl<<endl;
	for(a=0; a<40; a++)
	{
		cout<<"* ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\nThe Lucky Ticket number is: "<<d<<endl<<endl;
	f<<"\nThe Lucky Ticket number is: "<<d<<endl;

	for(a=0; a<40; a++)
	{
		cout<<"* ";
		for(k=0; k<500000; k++);
	}
	cout<<"\nWant to choose the ticket again? (Y/N)"<<endl;
	cin>>pause;
	if(pause=='n' || pause== 'N')
		break;

}
	f.close();
}

void charity()
{
	system("cls");
	int i;
	f.open("charity.dat", ios::in | ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError";
		return;
	}
	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tCHARITY RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	while(1)
	{
		cout<<"\nWant to enter more records? (Y/N)";
		cin>>pause;
		if(pause=='n' || pause=='N')
			break;
		c.finput();
		f.write((char *) &c, sizeof(c));
	}
	system("cls");
	for( i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tCHARITY RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	f.seekg(0, ios::beg);
	while(f.read((char *) &c, sizeof(c)))
	{
		c.foutput();
		cout<<endl;
	}
	f.close();

}

void salary() //Oompa Loompa salary
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tSALARY RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	f.open("salary.dat", ios::in | ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError";
		return;
	}
	while(1)
	{
		cout<<"\nWant to enter records? (Y/N)";
		cin>>pause;
		if(pause=='n' || pause=='N')
			break;
		o.oinput();
		f.write((char *) &o, sizeof(o));

	}
	system("cls");
	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\tSALARY RECORDS"<<endl<<endl;

	for(i=0; i<40; i++)
	{
		cout<<char(21)<<" ";
		for(k=0; k<500000; k++);
	}
	f.seekg(0, ios::beg);
	cout<<endl;
	while(f.read((char *) &o, sizeof(o)))
	{
		o.ooutput();
		cout<<endl;
	}

	f.close();
}

void wonka()
{
      int ch, i;
      system("cls");
      cout<<endl;
      for(i=0; i<40; i++)
      {
		cout<<"- ";
		for(k=0; k<500000; k++);
      }
      cout<<"\nIt's weird to say hello to myself but nothing is weird for weird people! "<<endl;
      cout<<"So, hello myself "<<char(2)<<endl;
      while(1)
      {

      cout<<"\n1. Sale";
      cout<<"\n2. Purchase";
      cout<<"\n3. Information about departments.";
      cout<<"\n4. Choose the golden tickets";
      cout<<"\n5. Charity Funds";
      cout<<"\n6. Oompa Loompa Salary\n\n";

      for(i=0; i<40; i++)
      {
		cout<<"- ";
		for(k=0; k<500000; k++);
      }
      cout<<"\n\nEnter your choice.";
      b:
      cin>>ch;
      switch(ch)
      {
	       case 1 : sale();
			break;
	       case 2:  purchase();
			break;
	       case 3 : dep();
			break;
	       case 4 : choose();
			break;
	       case 5 : charity();
			break;
	       case 6 : salary();
			break;
	       default: cout<<"\n Oops... Choose again";
			goto b;
      }
      cout<<"\nMr. Willy Wonka would you like to enter again? (Y/N)";
      cin>>pause;
      if(pause=='n' || pause=='N')
		break;

      }
}

void order()       //To place an order/enquiry/complaint/Update
{
	f.open("order.txt", ios::app);
	f<<"----------------------------------"<<endl<<endl;
	cout<<"Enter your department: ";
	gets(dept);
	f<<"Department: "<<dept<<endl;
	cout<<"Order / Enquiry / Complaint / Update :";
	cin>>dept;
	f<<dept<<endl;
	cout<<"Enter the details: (Press * to end)\n";
	while(pause != '*')
	{
		cin.get(pause);
		f<<pause;
	}
	f.close();
	cout<<"\nThis will be taken into consideration as soon as possible!"<<endl;
	cout<<"\nThank You ............Willy Wonka."<<endl;
}


void meadow()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Chocolate Meadow"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\nLast updated: Dec 7, 2019";
	cout<<"\nNo. of choco tress: 750";
	cout<<"\nAmount of chocolate in river and waterfall(kg): 1020 ";
	cout<<"\nSugar grass per m"<<char(253)<<"(kg) : 0.232";
	cout<<"\nNo. of oompa loompas working in meadow:   579";

	cout<<"\nDo you want to place an order/enquiry/complaint?/Update (Y/N)";
	cin>>pause;
	if(pause=='y' || pause=='Y')
		order();
	else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void drinks()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Drinks"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 7,2019.";
       cout<<"\n Water supply: 200 l per hour";
       cout<<"\nSugar : 20 ton";
       cout<<"\nFlavors and preservatives: Shortage!!!";
       cout<<"\nPackaging material: Available"<<endl;
       cout<<"\nNo. of oompa loompas: 250";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N)";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void boat()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Candy Boat"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 7,2019.";
       cout<<"\nNo. of candy boats: 10";
       cout<<"\nNo. of oars: 2310";
       cout<<"\nNo. of oompa loompas: 651";
       cout<<"\nFlow of river: Steady";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void gum()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Everlasting Chewing gum"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 9,2019.";
       cout<<"\nAmount of gum-material(kg): 2140";
       cout<<"\nPackaging material: Shortage";
       cout<<"\nNo. of oompa loompas: 305";
       cout<<"\nFlavours: Abundance (1203 units)";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void candy()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Candies & Toffees"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 8,2019.";
       cout<<"\nAmount of sugar syrup(kg): 7040";
       cout<<"\nPackaging material: Adequate";
       cout<<"\nNo. of oompa loompas: 490";
       cout<<"\nFlavours:  601 units";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void bars()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Wonka's Special Bars"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 10,2019.";
       cout<<"\nAmount of cocoa beans(kg): 1024";
       cout<<"\nAmount of milk: 3000 l";
       cout<<"\nAmount of sugar: 8 ton";
       cout<<"\nWonka especial paper wrap: 10000 units";
       cout<<"\nNo. of oompa loompas: 678";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void ice()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Ice - cream"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 7,2019.";
       cout<<"\nAmount of chocolate(kg): 490";
       cout<<"\nAmount of milk: 5002 l";
       cout<<"\nAmount of sugar: 5 ton";
       cout<<"\nWonka especial paper wrap: 4400 units";
       cout<<"\nNo. of oompa loompas: 570";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void nuts()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Nuts"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 9,2019.";
       cout<<"\nAmount of nuts(ton): 1.6";
       cout<<"\nChute passage: Clear!";
       cout<<"\nNo. of squirrels: 403";
       cout<<"\nNo. of oompa loompas: 10";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void tv()
{
	system("cls");
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}
	cout<<"\n\t\t\tDepartment: Choco TV Room"<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(4)<<" ";
		for(k=0; k<500000; k++);
	}

       cout<<"\n\nLast updated Dec 7,2019.";
       cout<<"\nCables: 789";
       cout<<"\nNo. of Wonka Bars: 67";
       cout<<"\nWonka especial electric suits: 120 units";
       cout<<"\nNo. of oompa loompas: 100";
       cout<<"\nDo you want to place an order/enquiry/complaint/update? (Y/N) ";
       cin>>pause;
       if(pause=='y' || pause=='Y')
		order();
       else
		cout<<"\nThank You ............Willy Wonka."<<endl;
}

void choco()
{
	system("cls");
	cout<<"\nFollowing are the mouth-watering items you must be eager to taste... "<<char(2);
	cout<<"\n "<<char(167)<<"  1. Evercold Icecream";
	cout<<"\n "<<char(167)<<"  2. Marshmallows (violet)";
	cout<<"\n "<<char(167)<<"  3. Colour changing caramels (5 in a pack) (Change color every 10 seconds)";
	cout<<"\n "<<char(167)<<"  4. Candy Balloons";
	cout<<"\n "<<char(167)<<"  5. Wonka's Whipple-Scrumptious Fudgemallow Delight";
	cout<<"\n "<<char(167)<<"  6. Wonka's Nutty Crunch Surprise";
	cout<<"\n "<<char(167)<<"  7. Strawberry Fudge";
	cout<<"\n "<<char(167)<<"  8. Jelly beans (200 g)";
	cout<<"\n "<<char(167)<<"  9. Everlasting Gobstoppers";
	cout<<"\n "<<char(167)<<"  10.Hair toffee";
	cout<<"\n "<<char(167)<<"  11.Hot ice-cream";
	cout<<"\n "<<char(167)<<"  12.Fizzy drinks (mega pack of 5)";
	cout<<"\n "<<char(167)<<"  13.Square candies that look round(10 in a pack)";
	cout<<"\n "<<char(167)<<"  14.Butterscotch Delight";
	cout<<"\n "<<char(167)<<"  15.Buttergins";
	cout<<"\n "<<char(167)<<"  16.Cockernut Ice";
	cout<<"\n "<<char(167)<<"  17.Strawberry Juice pistol";
	cout<<"\n "<<char(167)<<"  18.Exploding Candy";
	cout<<"\n "<<char(167)<<"  19.Luminous lollies (10 in a pack)";
	cout<<"\n "<<char(167)<<"  20.Mint jujubes";
	cout<<"\n "<<char(167)<<"  21.Candy coated pencils";
	cout<<"\n "<<char(167)<<"  22.Rainbow drops";
	cout<<"\n "<<char(167)<<"  23.Super-vitamin candy\n";

}

void oompa()
{
	system("cls");
	int ch, i;
	for(i=0; i<80; i++)
	{
		cout<<char(176);
		for(k=0; k<500000; k++);
	}
	cout<<"\nHello OOMPA LOOMPA! Good to see you. I shake you by the hand."<<endl;
	cout<<"Kindly choose the department you're concerned with. \n"<<char(2)<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(254)<<' ';
		for(k=0; k<500000; k++);
	}
	cout<<"\n\nDepartments: "<<endl;
	cout<<"\n1. Chocolate Meadow";
	cout<<"\n2. Drinks";
	cout<<"\n3. Candy Boat";
	cout<<"\n4. Everlasting Chewing Gum";
	cout<<"\n5. Candies & Toffees ";
	cout<<"\n6. Wonka's special Bars";
	cout<<"\n7. Ice-creams";
	cout<<"\n8. Nuts";
	cout<<"\n9. Choco TV Room";
	cout<<"\n10. Other"<<endl;
	cout<<"Enter the number corresponding to your department: ";
	cin>>ch;
	switch(ch)
	{
		case 1 : meadow();
			 break;
		case 2 : drinks();
			 break;
		case 3 : boat();
			 break;
		case 4 : gum();
			 break;
		case 5 : candy();
			 break;
		case 6 : bars();
			 break;
		case 7 : ice();
			 break;
		case 8 : nuts();
			 break;
		case 9 : tv();
			 break;
		case 10 : order();
			  break;

		default : cout<<"You've knocked the wrong door! "<<char(2)<<endl;
	}

}

void dep()       // For factory owner to see the progress of other departments
{

while(1)
{     int ch, i;
	system("cls");
	cout<<endl;
	for(int i=0; i<40; i++)
	{
		cout<<char(254)<<' ';
		for(k=0; k<500000; k++);
	}
	cout<<"Kindly choose the department you're concerned with. \n"<<char(2)<<endl;
	for (i=0; i<40; i++)
	{
		cout<<char(254)<<' ';
		for(k=0; k<500000; k++);
	}
	cout<<"\n\nDepartments: "<<endl;
	cout<<"\n1. Chocolate Meadow";
	cout<<"\n2. Drinks";
	cout<<"\n3. Candy Boat";
	cout<<"\n4. Everlasting Chewing Gum";
	cout<<"\n5. Candies & Toffees ";
	cout<<"\n6. Wonka's special Bars";
	cout<<"\n7. Ice-creams";
	cout<<"\n8. Nuts";
	cout<<"\n9. Choco TV Room";
	cout<<"\n10. Other"<<endl;
	cout<<"Enter the number corresponding to the department: ";
	cin>>ch;
	switch(ch)
	{
		case 1 : meadow();
			 break;
		case 2 : drinks();
			 break;
		case 3 : boat();
			 break;
		case 4 : gum();
			 break;
		case 5 : candy();
			 break;
		case 6 : bars();
			 break;
		case 7 : ice();
			 break;
		case 8 : nuts();
			 break;
		case 9 : tv();
			 break;
		case 10 : order();
			  break;

		default : cout<<"You've knocked the wrong door! "<<char(2)<<endl;
	}

	cout<<"Mr. Willy Wonka do you want to see the progress of any other department? (Y/N)"<<endl;
	cin>>pause;
	if(pause=='n' || pause=='N')
		break;
}
}

float price( int code) // Function to return price of an item depending on the code
{
	float r;
	switch(code)
	{
		case 1  :   r=450;
			    break;
		case 2  :   r=70;
			    break;
		case 3  :   r=50;
			    break;
		case 4  :   r=30;
			    break;
		case 5  :   r=250;
			    break;
		case 6  :   r=370;
			    break;
		case 7  :   r=90;
			    break;
		case 8  :   r=150;
			    break;
		case 9  :   r=25;
			    break;
		case 10 :   r=75;
			    break;
		case 11 :   r=300;
			    break;
		case 12 :   r=560;
			    break;
		case 13 :   r=100;
			    break;
		case 14 :   r=90;
			    break;
		case 15 :   r=130;
			    break;
		case 16 :   r=90;
			    break;
		case 17 :   r=120;
			    break;
		case 18 :   r=30;
			    break;
		case 19 :   r=340;
			    break;
		case 20 :   r=70;
			    break;
		case 21 :   r=20;
			    break;
		case 22 :   r=30;
			    break;
		case 23 :   r=16;
			    break;
		default :  r=0;
	}
	return(r);
}

void customer()
{
	system("cls");
	char name[40]; //Name
	char ph[10];   //Phone number
	char add[100]; //Address
	f.open("customer.txt", ios::app);
	f<<"*********************"<<endl;
	float r;  //Rate
	int code; //Code of item
	char d; //confirmation for buying the product
	int qty; //no. of items of each type
	float sum=0.0; //calculating total amount
	int i;
	for(i=0; i<40; i++)
	{
		cout<<char(3)<<' ';
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\tWelcome Dear Customer!!!\n";
	cout<<"\nIt's an honour for me to supply you the chocolate of finest quality.";

	cout<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(3)<<' ';
		for(k=0; k<500000; k++);
	}

	cout<<"\nTo see the special offers press an alphabet.";
	cin>>pause;

	system("cls");
	cout<<endl<<endl;
	for(i=0; i<40; i++)
	{
		cout<<char(232)<<' ';
		for(k=0; k<500000; k++);
	}
	cout<<"\n\n\t\t\t\t SPECIAL OFFERS: "<<endl;
	cout<<"\n\t\t If you shop above\t\t Discount";
	cout<<"\n\t\t 2000\t\t\t\t   5%";
	cout<<"\n\t\t 5000\t\t\t\t   20%";
	cout<<"\n\t\t 7000\t\t\t\t   25%";
	cout<<"\n\t\t 10000\t\t\t\t   34%";
	cout<<"\n\n\n\t\t\t ***** FREE DELIVERY *****\n\n";
	for(i=0; i<40; i++)
	{
		cout<<char(232)<<' ';
		for(k=0; k<500000; k++);
	}

	cout<<"\n\nPress an alphabet to view the items we sell.";
	cin>>pause;
	choco();
	cout<<"Does your tongue wanna taste Willy Wonka's magic? Then hit a yes! (Y/N)"<<endl;
	cin>>pause;
	if(pause=='y' || pause=='Y')
	{
		while(1)
		{
			cout<<"\nDo you want to see the list of items again?";
				cin>>pause;
			if(pause=='y' || pause=='Y')
				choco();

			 cout<<"\nEnter the Code of the item you want to buy: ";
			 cin>>code;

			r=price(code);
			cout<<"Price per 1 unit: "<<r<<endl;
			cout<<"Add to the cart?";
			cin>>d;
			if(d=='y' || d=='Y')
			{
				cout<<"Quantity: ";
				cin>>qty;
				f<<"Code: "<<code<<"\t Quantity: "<<qty<<endl;
				sum = sum + (r*qty); //To calculate total amount
			}

			cout<<"\nDo you want to choose something else buddy?"<<endl;
			cin>>pause;
			if(pause =='n' || pause=='N')
				break;

		}
		system("cls");
		cout<<"# Total bill = "<<sum<<endl;
		if(sum<5000 && sum>=2000)     //Calculating bill after discount
			sum=sum-(sum*0.05);

		if(sum<7000 && sum>=5000)
			sum=sum-(sum*0.2);

		if(sum<10000 && sum>=7000)
			sum=sum-(sum*0.25);

		if(sum>=10000)
			sum=sum-(sum*0.34);
		cout<<"\n# Bill after the dicount = "<<sum<<endl;
		f<<"Final bill: "<<sum<<endl;
		cout<<"\n# Mode of payment : Cash on Delivery!"<<endl;
		cout<<"\nEnter your details:"<<endl;
		cout<<"Enter name: ";
		gets(name);
		f<<"\nName: "<<name<<endl;
		cout<<"Enter address.";
		gets(add);
		f<<"Address: "<<add<<endl;
		cout<<"Enter phone no.";
		gets(ph);
		f<<"Phone No.: "<<ph<<endl;
		f.close();
		cout<<"\n*****  Thank You For Shopping with us!  *****"<<endl;

		for(i=0; i<40; i++)
		{
			cout<<char(3)<<' ';
			for(k=0; k<500000; k++);
		}
	  }
	  else
	  {
		cout<<" \"Bada pachtaoge...\"\n \"Bada pachtaoge...\" "<<char(14)<<' '<<char(14)<<' '<<char(14)<<endl;
		cout<<"Just kidding dear! That's the style of an eccentric chocolate maker!"<<endl;
	  }
}

void binary( char* name[30], long t) //Storing details of winner using binary file
{
      int n=0,pos, i;
      f.open("winners.dat" , ios::app | ios::out | ios::in | ios::binary );
      if(!f)
      {
		cout<<"ERROR";
		return;
      }
      cout<<endl<<endl;
      pattern(236);

      cout<<endl<<endl;

      f.seekg(0,ios::beg);
      while( f.read((char *) &w, sizeof(w)))
      {
	    pos=f.tellg();
	    pos=pos-sizeof(w);
	    if(t==w.ticket()) // Finding the ticket no.
	    {
		n=1;          //Record found
		w.output();
		cout<<"\nDo you want to modify them? (Y/N)";
		cin>>pause;
		if(pause=='y' || pause=='Y')
		{
			w._age();
			w._address();
			w._phone();
			w._email();
			cout<<"\nsize:"<<sizeof(w);
			cout<<"\npos : "<<pos;
			f.seekg( pos, ios::beg);
			cout<<"\n after "<<f.tellp();
			f.write((char*) &w, sizeof(w));
			cout<<"\n After write: "<<f.tellp();
			cout<<"\nName : "<<name<<endl;
			w.output();
		}
	    }
      }
      f.close();
      if(n==0)  // If record isn't found
      {
		cout<<endl<<"\n# Fill in the exact ticket number otherwise you will be disqualified.\n";
		f.open("winners.dat" , ios::app | ios::binary );
		cout<<"\nWe don't have your details. Kindly enter them."<<endl;
		w.input();
		if(!f.write((char *) &w, sizeof(w)))
			cout<<"Error";
		system("cls");
		cout<<endl<<endl;
		pattern(236);
		cout<<endl<<endl<<"Hello "<<name<<endl;
		w.output();
		f.close();
      }

}
void gold()
{
	system("cls");
	char ch;
	f.open("gold.txt" , ios::in );

	if(!f)
		cout<<"Unable to open file\n";

	else
	{
		while(!f.eof())
		{
			pause=f.get();
			cout<<pause;
		}
		f.close();
		cin>>ch;
		cout<<"Enter password: ";
		cin>>password;

		switch(ch)
		{
			case '1' : if(password=="food")
				   {
					system("cls");
					cout<<"\n\t\t*****  Hello Augustus Gloop!  *****\n\t\t\t Ticket No. : 967  "<<char(1);
					//binary("Augustus Gloop",967);
				   }
				   else
					cout<<"\nWrong password";
				   break;
			case '2' : if(password=="gum")
				   {
					system("cls");
					cout<<"\n\t\t*****  Hello Violet Beauregrade!   *****\n\t\t\t Ticket No.: 5098  "<<char(1);
					// binary("Violet Beauregrade",5098);
				   }
				   else
					cout<<"\nWrong password";
				   break;
			case '3' : if(password=="daddy")
				   {
					system("cls");
					cout<<"\n\t\t*****  Hello Veruca Salt!  *****\n\t\t\t Ticket No.: 92876  "<<char(1);
					// binary("Veruca Salt",92876);
				   }
				   else
					cout<<"\nWrong password";
				   break;
			case '4' : if(password=="tv")
				   {
					system("cls");
					cout<<"\n\t\t*****  Hello Mike Teavee!  ***** \n\t\t\t Ticket No.: 3  "<<char(1);
					// binary("Mike Teavee",3);
				   }
				   else
					cout<<"\nWrong password";
				   break;
			case '5' : if(password=="hero")
				   {
					 system("cls");
					 cout<<"\n\t\t*****  Hello Charlie Bucket!  *****\n\t\t\t Ticket No.: 25  "<<char(1);
					 // binary("Charlie Bucket",25);
				   }
				    else
					cout<<"\nWrong password";
				   break;
			default : cout<<"Hi Child! You're not allowed. Bye!";

		     }
	}
}

void know()     // Brief the user about the factory
{
	system("cls");
	int ch, i;
	char c;

	pattern(4);

	cout<<"\n\n\t\t WELCOME TO THE VERY SPECIAL, UNPRECEDENTED\n "<<endl;

	cout<<"\t\t\t\t|  | | |   |   \\ /"<<endl;
	cout<<"\t\t\t\t|/\\| | |__ |__  |";
	cout<<"\n\n\t\t\tWONKA'S CHOCLATE FACTORY !!!"<<endl;
	cout<<"\t\t\tEndless treasure of surprises!\n"<<endl;
	cout<<"\n\t\t\tHead Office: Ladakh, India.";
	cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"  "<<char(2)<<' '<<char(2)<<' '<<char(2)<<'\n'<<endl;

	pattern(4);
	cout<<"Hello friends!"<<endl;
	cout<<"You're talking to Mr. Willy Wonka. Wondering who's this person with a strange";
	cout<<"\nfunny name is...";
	cout<<"Well, he is the owner of the best and unique chocolate factory  of the world, a place where marvel and wonder are commonplace events!";
	cout<<"\n\nI'm making you excited... ain't I! ";
	cout<<" Can't help, I am as crazy and sweet as my   choclates are!";
	cout<<" So, before you get tired of my incessant talking I shall tell you something about my factory!";
	cout<<"\nPress an alphabet to continue.";
	cin>>pause;
	cout<<endl<<char(15)<<" In my factory there are no perfectly human workers (except for myself)"<<endl;
	cout<<"  Some very skilled Oompa Loompas work here. These creatures who barely reach   our knees belong to the Loompaland.";
	cout<<" Wanna see them? I won't let you unless you are my Golden Ticket Winner :)"<<endl;
	cout<<"\n"<<char(15)<<" Undoubtedly, people are very curious about my factory. So, to satiate their   hunger I'm inviting lucky 5 children to visit my factory.";
	cout<<" Do you think you can  be that fortunate fellow? ";
	cout<<"\n\n"<<char(15)<<" Then run and buy a chocolate and find the Golden Ticket! :)\n";
	cout<<"But first of all, decide what you want to buy.";
	cout<<"Press an alphabet to see the list of items."<<endl;
	cin>>pause;
	choco();
	cout<<"Do you want to buy something? ( 'y' for yes)";
	cin>>c;
	if(c=='y' || c=='Y')
		customer();
	else
		cout<<"Thank You for visting us! "<<char(3);


}

int main()
{

while(1)
{
	system("cls");
	char ch;
	int i;
	pattern(4);

	cout<<"\n\n\t\t WELCOME TO THE VERY SPECIAL, UNPRECEDENTED\n "<<endl;

	cout<<"\t\t\t\t|  | | |   |   \\ /"<<endl;
	cout<<"\t\t\t\t|/\\| | |__ |__  |";
	cout<<"\n\n\t\t\tWONKA'S CHOCOLATE FACTORY !!!"<<endl;
	cout<<"\t\t\tEndless treasure of surprises!\n"<<endl;
	cout<<"\n\t\t\tHead Office: Ladakh, India";
	cout<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"  "<<char(2)<<' '<<char(2)<<' '<<char(2)<<'\n'<<endl;

	pattern(4);

	cout<<"\n\nWe are at your service... Kindly identify yourself. "<<endl;
	cout<<"1. Mr. Willy Wonka";
	cout<<"\n2. Oompa Loompa";
	cout<<"\n3. Customer/Retailer";
	cout<<"\n4. Golden Ticket winner"<<endl;
	cout<<"5. Curious about the factory?"<<endl;
	cout<<"Please enter the corresponding digit: ";
	a:
	char l;
	cin>>ch;
	//cin>>l;
	//cout<<ch<<" "<<l<<endl<<"Oh";
	// Clear the newline character from the input buffer
	// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//cin.ignore(255, '\n');
	switch(ch)
	{
		case '1' : cout<<"Enter the password: ";
			   cin>>password;
			   if(password=="Glass_07")
				wonka();
			   else
				cout<<"Wrong Password. I don't like cheaters. :( "<<endl;

			   break;

		case '2' : cout<<"Enter the password: ";
			   cin>>password;
			   if(password=="Singing")
				oompa();
			   else
				cout<<"Wrong Password. I don't like cheaters. :( "<<endl;
			   break;

		case '3' : customer();
			   break;

		case '4' : cout<<"Enter the password: ";
			   cin>>password;
			   if(password == "I love chocolates")
				 gold();
			   else
				cout<<"Wrong Password. I don't like cheaters. :( "<<endl;
			   break;

		case '5' : know();
			   break;

		default :  cout<<"Invalid choice. Enter choice again.";
			   goto a;

	}

	cout<<"\nDo you want to switch user? (Y/N)";
	cin>>pause;
	if(pause=='n' || pause=='N')
		break;
}
	//getch();
	return 0;
}
