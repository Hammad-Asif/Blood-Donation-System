#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
int choice();
void info();
void taker();
int infoMenu();
void donate();

using namespace std;
string name,name1,group,group1,card,card1,address,phno,phno1;
fstream recordfile;
    
int main()
{   
label:
	int n,donor=0;
	char aa;
	n=choice();    
    if(n==1)
    {
    	donate();
	}
 else if(n==2)
	{
		taker();
	}
 else if(n==3)
	{
		info();
	}
	else
	{
		cout<<endl;
		cout << ".........Wrong Entery plz try again.........." << endl;
		system("cls");
		goto label;
	}
	cout << endl;
	cout << "Press Y to enter into main menu, Press N For exit (Y/N) : ";
	cin >> aa;
	if (aa == 'y' || aa == 'y')
		goto label;
	return 0;
}
	
			 
int choice()
{
	int n;
	cout<<"\n\n\t\t\tWelcome to Anser Blood Bank"<<endl;
    cout<<"\n\tPress 1  for blood donation"<<endl;
    cout<<"\tPress 2  for blood taken"<<endl;
    cout<<"\tPress 3  to get the information"<<endl;
    cout<<"Press: ";
	cin>>n;
	return n;
}
int infoMenu()
{
	 int n;
	
    cout<<" Press 1  for needy information"<<endl;
    cout<<" Press 2  for Donors information"<<endl; 
    cout<<" Press 3  for checking A+ blood packs"<<endl;
    cout<<" Press 4  for checking B+ blood packs"<<endl; 
    cout<<" Press 5  for checking AB+ blood packs"<<endl;
    cout<<" Press 6  for checking O+ blood packs"<<endl;
    cout<<" Press 7  for checking B- blood packs"<<endl;
    cout<<" Press 8  for checking A- blood packs"<<endl;
    cout<<" Press 9  for checking AB- blood packs"<<endl;
    cout<<" Press 10 for checking O- blood packs"<<endl;
	cin>>n;
	return n;
}
void info()
{
	int n=infoMenu();
	string bag="";
	fstream f;
	if(n==1)
	{
		char ch;
		f.open("Needy.txt",ios::in);
		cout<<"\n\nName\tId Card\tPhone No.\n";
		while(f.get(ch))
		{
			cout<<ch;
		}
	}
	else if(n==2)
	{
		char ch;
		f.open("Donar.txt",ios::in);
		cout<<"\n\nName\tBlood\tId Card\tAddress\tPhone No.\n";
		while(f.get(ch))
		{
			cout<<ch;
		}
		
	}
	else if(n==3)
	{
		f.open("A+.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of A+ Blood is avilable"<<endl;
	}
	
	else if(n==4)
	{
		f.open("B+.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of B+ Blood is avilable"<<endl;
	}
	else if(n==5)
	{
		f.open("AB+.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of AB+ Blood is avilable"<<endl;
	}
	else if(n==6)
	{
		f.open("O+.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of O+ Blood is avilable"<<endl;
	}
	else if(n==7)
	{
		f.open("A-.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of A- Blood is avilable"<<endl;
	}
	else if(n==8)
	{
		f.open("B-.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of B- Blood is avilable"<<endl;
	}
	else if(n==9)
	{
		f.open("AB-.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of AB- Blood is avilable"<<endl;
	}
	else if(n==10)
	{
		f.open("O-.txt",ios::in);
		f>>bag;
		cout<<bag<<"Bags of O- Blood is avilable"<<endl;
	}
}
void taker()
{
	loop:
	system("cls");
		cout<<"\n\t\tWelcome Blood Taker"<<endl;
		cout<<"\nWhich blood group you need: ";
		cin>>group1;
		
		for(int i=0;i<group1.length();i++)
		{
			if(isalpha(group1[i]))
			{
				group1[i]=toupper(group1[i]);
			}
		}
				
		if(!(group1=="A-" || group1=="A+" || group1=="AB+"|| group1=="AB-"|| group1=="B+"|| group1=="B-"|| group1=="O+" || group1=="O-"))
		{
			cout<<"\n\t\tPlease Enter Correct Blood Group\n\n";
			Sleep(2000);
			goto loop;
		}		
		string packets="";
		string fileName=group1+".txt";
		
		recordfile.open(fileName.c_str(),ios::in|ios::out);
		if(recordfile)
		{
			recordfile>>packets;
			if(packets!="0")
			{
				char ch;
				cout<<"\n\n\t\tBlood group Available "<<packets<<" Packets available\n";
				cout<<"\n\tDo You want donors info (Y/N)";
				cin>>ch;
				if(ch=='y'|| ch=='Y')
				{
					string counter="";
					int count;
					fstream f;
					f.open(fileName.c_str(),ios::in);
					if(f)
					{
						f>>counter;
						f.close();
						f.open(fileName.c_str(),ios::out);
						count=atoi(counter.c_str())-1;
						f<<std::to_string(count);
						f.close();
						
					}
					recordfile.close();
					fstream record;
					record.open("Donar.txt",ios::out|ios::in);
					if(record)
					{
						system("cls");
						cout<<"\n\nDonors Information\n";
						
					while(!record.eof())
					{
						record>>name>>group>>card>>address>>phno;
						if(group==group1)
						{
							cout<<"\nName: "<<name<<"\nBlood Group: "<<group<<"\nCNIC: "<<card<<"\nAddress: "<<address<<"\nPhone No. "<<phno<<"\n\n";	
						}
					}
				}
				}
				
					recordfile.close();
			}
			
		
		cout<<"Please enter your name: ";
		cin>>name1;
		cout<<"Enter your idcard number: ";
		cin>>card1;
		cout<<"Enter your contact no: ";
		cin>>phno1;
		fstream f;
		f.open("Needy.txt",ios::out|ios::in|ios::app);
		if(f)
		{
			f<<name<<"\t"<<card1<<"\t"<<phno1;
			f.close();
		}
}
}
void donate()
{
	
		string counter="",filename="";
    	system("cls");
    	cout<<"\n\t\t\twelcome for blood donation"<<endl;
    	cout<<"pleas enter your full name: ";
    	cin>>name;		
    	again:
		cout<<"please enter your blood group: ";
    	cin>>group;
    	
		for(int i=0;i<group.length();i++)
		{
			if(isalpha(group[i]))
			{
				group[i]=toupper(group[i]);
			}
		}		
		if(!(group=="A-" || group=="A+" || group=="AB+"|| group=="AB-"|| group=="B+"|| group=="B-"|| group=="O+" || group=="O-"))
		{
			cout<<"\n\t\tPlease Enter Correct Blood Group\n\n";
			Sleep(2000);
			goto again;
		}
		cout<<"please enter your idcard number: ";
    	cin>>card;
    	cout<<"please enter your address: ";
    	cin>>address;
    	cout<<"pleas enter your phone number: ";
    	cin>>phno;
		recordfile.open("Donar.txt",ios::in|ios::out|ios::app);
		if(recordfile)
		{
			recordfile<<"\n"<<name<<"\t"<<group<<"\t"<<card<<"\t"<<address<<"\t"<<phno;
			recordfile.close();
		}
		int count;
		fstream f;
		filename=group+".txt";
		f.open(filename.c_str(),ios::in);
		if(f)
		{
			f>>counter;
			f.close();
			f.open(filename.c_str(),ios::out);
			count=atoi(counter.c_str())+1;
			f<<std::to_string(count);
			f.close();
			
		}
}
