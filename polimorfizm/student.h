#pragma once
#include "people.h"

class student : public people
{
private:
	int Course;
	string Type_of_education;
	string Name_of_faculty;
public:
	void Set_Course(const int);
	int Get_Course() const;
	void Set_Type_of_education(const string);
	string Get_Type_of_education() const;
	void Set_Name_of_faculty(const string);
	string GetName_of_faculty() const;

	void Read_new_info() override;

	void print_info(ostream&) override;
};

