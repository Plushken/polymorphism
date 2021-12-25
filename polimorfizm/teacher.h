#pragma once
#include "people.h"

class teacher : public people
{
private:
	int Year_of_experience;
	string Type_of_position;
public:
	void Set_Year_of_experience(const int);
	int Get_Year_of_experience() const;
	void Set_Type_of_position(const string);
	string Get_Type_of_position() const;

	void Read_new_info() override;

	void print_info(ostream&) override;
};

