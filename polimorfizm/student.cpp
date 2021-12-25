#include "student.h"
void student::Set_Course(const int d)
{
	if (d < 1 || d > 5)
		throw exception("Неправильный курс обучения!");
	Course = d;
}

int student::Get_Course() const
{
	return Course;
}

void student::Set_Type_of_education(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("Тип обучения не может быть пустым или состоять только из пробелов!");
	Type_of_education = s;
	Space_delete(Type_of_education);
}

string student::Get_Type_of_education() const
{
	return Type_of_education;
}

void student::Set_Name_of_faculty(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("Название факультета не может быть пустым или состоять только из пробелов!");
	Name_of_faculty = s;
	Space_delete(Name_of_faculty);
}

string student::GetName_of_faculty() const
{
	return Name_of_faculty;
}

void student::Read_new_info()
{
	string faculty_name;
	string type_education;
	int number_course;
	while (true)
	{
		cin.ignore();
		cout << "\nВведите тип обучения: ";
		getline(cin, type_education);
		cout << "\nВведите название факультета: ";
		getline(cin, faculty_name);
		cout << "\nВведите курс обучения: ";
		cin >> number_course;

		try
		{
			Space_delete(faculty_name);
			Space_delete(type_education);
			Set_Name_of_faculty(faculty_name);
			Set_Course(number_course);
			Set_Type_of_education(type_education);
		}
		catch (exception& ex)
		{
			cout << ex.what() << '\n';
			continue;
		}
		break;
	}
}

void student::print_info(ostream& os)
{
	people::print_info(os);
	os << "\nНазвание факультета: " << Name_of_faculty << '\n';
	os << "\nНомер курса: " << Course << '\n';
	os << "\nТип обучения: " << Type_of_education << '\n';
}