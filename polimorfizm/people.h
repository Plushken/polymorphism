#pragma once
#include <iostream>
#include <string>

using namespace std;
class people
{
private:
	string Name; 
	string Surname;
	string Patronymic;
	int Year_of_birth;
	string Gender;
protected:
	void Space_delete(string& name);
public:
	virtual void Set_Name(const string);
	virtual void Set_Surname(const string);
	virtual void Set_Patronymic(const string);
	virtual void Set_Year_of_birth(const int);
	virtual void Set_Gender(const string);
	virtual string Get_Name() const;
	virtual string Get_Surname() const;
	virtual string Get_Patronymic() const;
	virtual int Get_Year_of_birth() const;
	virtual string Get_Gender() const;

	virtual void Read_new_info() = 0;

	virtual void print_info(ostream&);
};

