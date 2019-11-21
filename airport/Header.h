#ifndef N_H
#define N_H
#include<iostream>
using namespace std;
class variable
{
protected:char name[22] ;char passport[11],visacard[19],date[12],CLASS[15];

};
class Air :public variable
{

	public:
		Air();
		~Air();
		void in();
		void insert();
		void display();
		void search();
		
	
};
class as : public Air
{
public:


};
class Delete_:public variable
{

public:
	char Deleter[15];
	void Delete();

};
class update:public variable
{
public:
	
	char updater[15];
	void up();
	

};

#endif