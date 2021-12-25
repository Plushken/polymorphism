#include "assistant.h"

void assistant::Set_Name_of_department(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("Название должность не может быть пустым или состоять только из пробелов!");
	Name_of_department = s;
	Space_delete(Name_of_department);
}

string assistant::Get_Name_of_department() const
{
	return Name_of_department;
}

void assistant::Read_new_info()
{
	string kafedra;
	cin.ignore();
	while (true)
	{
		cout << "\nВведите название кафедры: ";
		getline(cin, kafedra);
		try
		{
			Space_delete(kafedra);
			Set_Name_of_department(kafedra);
		}
		catch (exception& ex)
		{
			cout << ex.what() << '\n';
			continue;
		}
		break;
	}
}

void assistant::print_info(ostream& os)
{
	people::print_info(os);
	os << "\nНазвание кафедры: " << Name_of_department << '\n';
}
