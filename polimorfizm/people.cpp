#include "people.h"

void people::Space_delete(string& name)
{
	int i = 0;
	while (name[i] == ' ')
		name.erase(i, 1);

	for (i; i < name.size(); i++)
	{
		if (i + 1 == name.size())
		{
			if (name[i] == ' ')
				name.erase(i, 1);
			break;
		}
		if (name[i] == ' ' && name[i + 1] == ' ')
		{
			name.erase(i, 1);
			i--;
		}
	}
}

void people::Set_Name(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("��� �������� �� ����� ���� ������ ��� �������� ������ �� ��������!");
	Name = s;
	Space_delete(Name);
}

void people::Set_Surname(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("������� �������� �� ����� ���� ������ ��� �������� ������ �� ��������!");
	Surname = s;
	Space_delete(Name);
}

void people::Set_Patronymic(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("�������� �������� �� ����� ���� ������ ��� �������� ������ �� ��������!");
	Patronymic = s;
	Space_delete(Patronymic);
}

void people::Set_Year_of_birth(const int d)
{
	if (d < 1900 || d > 2021)
		throw exception("������������ ��� ��������!");
	Year_of_birth = d;
}

void people::Set_Gender(const string s)
{
	if (s.empty() || s.find_first_not_of(' ') == string::npos)
		throw exception("������ �������� �� ����� ���� ������ ��� �������� ������ �� ��������!");
	Gender = s;
	Space_delete(Gender);
}

string people::Get_Name() const
{
	return Name;
}

string people::Get_Surname() const
{
	return Surname;
}

string people::Get_Patronymic() const
{
	return Patronymic;
}

int people::Get_Year_of_birth() const
{
	return Year_of_birth;
}

string people::Get_Gender() const
{
	return Gender;
}

void people::print_info(ostream& os)
{
	os << "\n��� ��������: " << Name << '\n';
	os << "\n������� ��������: " << Surname << '\n';
	os << "\n�������� ��������: " << Patronymic << '\n';
	os << "\n��� ��������: " << Gender << '\n';
	os << "\n��� �������� ��������: " << Year_of_birth << '\n';
}
