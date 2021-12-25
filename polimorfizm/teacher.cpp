#include "teacher.h"

void teacher::Set_Year_of_experience(const int d)
{
	if (d < 1 || d > 100)
		throw exception("Неправильный стаж!");
	Year_of_experience = d;
}

int teacher::Get_Year_of_experience() const
{
	return Year_of_experience;
}

void teacher::Set_Type_of_position(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("Должность не может быть пустым или состоять только из пробелов!");
	Type_of_position = s;
	Space_delete(Type_of_position);
}

string teacher::Get_Type_of_position() const
{
	return Type_of_position;
}

void teacher::Read_new_info()
{
	string position;
	int experience;
	while (true)
	{
		cin.ignore();
		cout << "\nВведите название должности: ";
		getline(cin, position);
		cout << "\nВведите стаж преподавателя: ";
		cin >> experience;
		try
		{
			Space_delete(position);
			Set_Type_of_position(position);
			Set_Year_of_experience(experience);
		}
		catch (exception& ex)
		{
			cout << ex.what() << '\n';
			continue;
		}
		break;
	}
}

void teacher::print_info(ostream& os)
{
	people::print_info(os);
	os << "\nСтаж преподавания: " << Year_of_experience << '\n';
	os << "\nДолжность: " << Type_of_position << '\n';
}
