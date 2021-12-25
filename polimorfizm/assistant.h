#pragma once
#include "people.h"

class assistant : public people
{
private:
	string Name_of_department;
public:
	void Set_Name_of_department(const string);
	string Get_Name_of_department() const;

	void Read_new_info() override;

	void print_info(ostream&) override;
};

