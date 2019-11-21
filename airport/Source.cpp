#include<iostream>
#include<fstream>
#include<string>
#include"Header.h"
using namespace std;	

	
	Air::Air()
	{
		name[22]='0';passport[11]='0000';visacard[19]='00',date[12]='0';CLASS[15]='eco';    
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";

    cout<<"\t\t\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\t*   Welcome To Travel Agency Program    *\n";
    cout<<"\t\t\t\t\t*                                       *\n";
    cout<<"\t\t\t\t\t*****************************************\n";
    cout<<"                                                Press Enter to loge in ";

	cin.get();
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t***********************************";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*\tChoose operator :         *\n\t\t\t\t\t\t*\t1-insert                  *\n\t\t\t\t\t\t*\t2-Display                 *\n\t\t\t\t\t\t*\t3-search                  *\n\t\t\t\t\t\t*\t4-delete                  *\n\t\t\t\t\t\t*\t5-update                  * "<<endl;
	cout<<"\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t***********************************";
	}
	Air::~Air()
	{
	cout<<"Thanks to use our program"<<endl;system("pause");
	}
	
void	Air:: in()
	{
		cout<<"Name: ";
		cin.ignore();
	cin.getline(name,22);
	cout<<"\nPassport: ";
	cin.getline(passport,11);
	cout<<"\nVisacard: ";
	cin.getline(visacard,19);
	cout<<"\ndate: ";
	cin.getline(date,12);
	cout<<"\nClass: ";
	cin.getline(CLASS,15);
	
	}
	void Air:: insert()
	{   
	fstream in;
	in.open("in.txt",ios::out|ios::app);
	in<<name<<'/'<<passport<<'/'<<visacard<<'/'<<date<<'/'<<CLASS<<'\n';
	cout<<"Add successful"<<endl;
	
	in.close();
	}
	void Air::display()
	{
	fstream out;
	out.open("in.txt",ios::in);
	
	while(!out.eof())
	{
		
		
		out.getline(name,22,'/');
		out.getline(passport,11,'/');
		out.getline(visacard,19,'/');
		out.getline(date,12,'/');
		out.getline(CLASS,15);
		cout<<"\n"<<"Name: "<<name<<"\n  Passport: "<<passport<<" \nVisacard : "<<visacard<<" \n date: "<<date<<" \n CLASS: "<<CLASS<<endl;

	}
	out.close();
	}
	void Air::search()
	{
		int flag=0;
	fstream print;
	print.open("in.txt",ios::in);
	char searcher[22];
	cin.ignore();
	cout<<"Enter Name of client you want to search about :";
	cin.getline(searcher,22);
	system("cls");
	while(!print.eof()){
	

	print.getline(name,22,'/');
	print.getline(passport,11,'/');
	print.getline(visacard,19,'/');
	print.getline(date,12,'/');
	print.getline(CLASS,15);
	
if(strcmp(name,searcher)==0)
	{
		
	cout<<"\n"<<"Name: "<<name<<"\n  Passport: "<<passport<<" \nVisacard : "<<visacard<<" \n date: "<<date<<" \n CLASS: "<<CLASS<<endl;
	flag=1;
}
	
	
	}
	if (flag==1)
	{
		cout<<"Done process!"<<endl;
	
	}
	else {
		cout<<"Nothing is Found"<<endl;}
	print.close();
	}
	void Delete_:: Delete()
	{
		int flag1=0;
		fstream Delete;
		fstream Temp;
		Delete.open("in.txt",ios::in);
		Temp.open("Temp.txt",ios::out);
		cout<<"Enter Name you want to Delete His Record:";
		cin.ignore();
		cin.getline(Deleter,15);
		while(!Delete.eof())
		{
	Delete.getline(name,22,'/');
	Delete.getline(passport,11,'/');
	Delete.getline(visacard,19,'/');
	Delete.getline(date,12,'/');
	Delete.getline(CLASS,15);
		
		if(strcmp(name,Deleter)==0)
		{
			flag1=1;
			continue;
		
		
		
		}
		else
			Temp<<name<<'/'<<passport<<'/'<<visacard<<'/'<<date<<'/'<<CLASS<<'\n';

	
	
	
	}
		Delete.close();
		Temp.close();
		Delete.open("in.txt",ios::out);
		Temp.open("Temp.txt",ios::in);
		while(!Temp.eof())
		{
		
	Temp.getline(name,22,'/');
	Temp.getline(passport,11,'/');
	Temp.getline(visacard,19,'/');
	Temp.getline(date,12,'/');
	Temp.getline(CLASS,15);

		Delete<<name<<'/'<<passport<<'/'<<visacard<<'/'<<date<<'/'<<CLASS<<'\n';
		}
		Delete.close();
		Temp.close();
		remove("Temp.txt");
		if(flag1==1)
		{
			cout<<"Remove Successful (;"<<endl;
		}
		else 
			cout<<"Not Found This Client"<<endl;

	}
	void update::up()
	{
		int flag=0;
	fstream update;
	fstream Temp;
	update.open("in.txt",ios::in);
	Temp.open("Temp.txt",ios::out);	
	cout<<"Enter Client name you want to update his information :";
	cin.ignore();
	cin.getline(updater,15);
	system("cls");
	while(!update.eof())
	{
		
	update.getline(name,22,'/');
	update.getline(passport,11,'/');
	update.getline(visacard,19,'/');
	update.getline(date,12,'/');
	update.getline(CLASS,15);
	if (strcmp(name,updater)==0)
	{
		flag=1;
	cout<<"Enter Full Information For:"<<updater<<endl;
	cout<<"Name: ";
		
	cin.getline(name,22);
	cout<<"\nPassport: ";
	cin.getline(passport,11);
	cout<<"\n Visacard: ";
	cin.getline(visacard,19);
	cout<<"\n date: ";
	cin.getline(date,12);
	cout<<"\n Class: ";
	cin.getline(CLASS,15);
	
	Temp<<name<<'/'<<passport<<'/'<<visacard<<'/'<<date<<'/'<<CLASS<<'\n';
	}
	}
	
	update.close();
	Temp.close();
	update.open("in.txt",ios::out);
	Temp.open("Temp.txt",ios::in);
	while(!Temp.eof())
	{
	Temp.getline(name,22,'/');
	Temp.getline(passport,11,'/');
	Temp.getline(visacard,19,'/');
	Temp.getline(date,12,'/');
	Temp.getline(CLASS,15);
	update<<name<<'/'<<passport<<'/'<<visacard<<'/'<<date<<'/'<<CLASS<<'\n';
	}
	update.close();
	Temp.close();
	remove("Temp.txt");
	if(flag==1)
	{
	cout<<"Record Updated "<<endl;
	}
	else 
		cout<<"Not found Client"<<endl;
	
	}
	
	
	 
	int	main()
{
	system("color B");
	as obj;
	Delete_ obj1;
	update obj2;
	
	int choose;
	char con='y';
	

	while(con='y'){
		cin>>choose;
		system("cls");
		
	switch(choose)
	{
	case 1:obj.in();
	obj.insert();
	break;
	case 2:obj.display();
		break;
	case 3:obj.search();
		break;
	case 4:obj1.Delete();
		break;
	case 5:obj2.up();
		break;
	default:cout<<"Choose correct operator"<<endl;cin>>choose;
		
	}
	cout<<"Do you want to choose another operation :";
	cin>>con;
	if(con=='y')
	{
		system("cls");
	cout<<"\n\n\n\t\t\t\t\t\t***********************************";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*\tChoose operator :         *\n\t\t\t\t\t\t*\t1-insert                  *\n\t\t\t\t\t\t*\t2-Display                 *\n\t\t\t\t\t\t*\t3-search                  *\n\t\t\t\t\t\t*\t4-delete                  *\n\t\t\t\t\t\t*\t5-update                  * "<<endl;
	cout<<"\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t*                                 *";
	cout<<"\n\t\t\t\t\t\t***********************************";
	}
	}
	
return 0;
}
