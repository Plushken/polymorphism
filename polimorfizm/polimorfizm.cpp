#include "assistant.h"
#include "teacher.h"
#include "student.h"
#include "windows.h"
#include "people.h"

int amount_of_objects()
{
    int amount;
    while (true)
    {
        cout << "Введите количество объектов классов \"Студент\", \"Преподавателб\", \"Ассистент\": ";
        cin >> amount;
        if (amount < 0)
        {
            cout << "\nНеправильное количество!\n";
            continue;
        }
        break;
    }
    return amount;
}

int class_choice()
{
    cout << "\nВыберите класс для объекта(1-Студент, 2-Преподаватель, 3-Ассистент): ";
    int choice;
    while (true)
    {
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Неверный номер! Попробуйте ещё раз: ";
            continue;
        }
        break;
    }
    return choice;
}

void name_input(people**& array_of_pointers, int i)
{
    cin.ignore();
    string name;
    while (true)
    {
        cout << "\nВведите имя человека: ";
        getline(cin, name);
        try
        {
            array_of_pointers[i]->Set_Name(name);
        }
        catch (exception& ex)
        {
            cout << ex.what() << '\n';
            continue;
        }
        break;
    }
}

void surname_input(people**& array_of_pointers, int i)
{
    string surname;
    while (true)
    {
        cout << "\nВведите фамилию человека: ";
        getline(cin, surname);
        try
        {
            array_of_pointers[i]->Set_Surname(surname);
        }
        catch (exception& ex)
        {
            cout << ex.what() << '\n';
            continue;
        }
        break;
    }
}

void patronymic_input(people**& array_of_pointers, int i)
{
    string patronymic;
    while (true)
    {
        cout << "\nВведите отчество человека: ";
        getline(cin, patronymic);
        try
        {
            array_of_pointers[i]->Set_Patronymic(patronymic);
        }
        catch (exception& ex)
        {
            cout << ex.what() << '\n';
            continue;
        }
        break;
    }
}

void gender_input(people**& array_of_pointers, int i)
{
    string gender;
    while (true)
    {
        cout << "\nВведите пол человека: ";
        getline(cin, gender);
        try
        {
            array_of_pointers[i]->Set_Gender(gender);
        }
        catch (exception& ex)
        {
            cout << ex.what() << '\n';
            continue;
        }
        break;
    }
}

void year_of_birth_input(people**& array_of_pointers, int i)
{
    int year;
    while (true)
    {
        cout << "\nВведите год рождения: ";
        cin >> year;
        try
        {
            array_of_pointers[i]->Set_Year_of_birth(year);
        }
        catch (exception& ex)
        {
            cout << ex.what() << '\n';
            continue;
        }
        break;
    }
}

void Print_objects_info(int amount, people**& array_of_pointers)
{
    for (int i = 0; i < amount; i++)
    {
        cout << '\n';
        array_of_pointers[i]->print_info(cout);
        cout << '\n';
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int amount = amount_of_objects();
    people** array_of_pointers;
    array_of_pointers = new people * [amount];
    for (int i = 0; i < amount; i++)
    {
        int number = class_choice();
        switch (number)
        {
        case 1: array_of_pointers[i] = new student(); break;
        case 2: array_of_pointers[i] = new teacher(); break;
        case 3: array_of_pointers[i] = new assistant(); break;
        }

        name_input(array_of_pointers, i);
        surname_input(array_of_pointers, i);
        patronymic_input(array_of_pointers, i);
        gender_input(array_of_pointers, i);
        year_of_birth_input(array_of_pointers, i);

        array_of_pointers[i]->Read_new_info();
    }
    cout << '\n';
    if (amount != 0)
        cout << "\nВывод информации об объектах:\n";
    Print_objects_info(amount, array_of_pointers);
    delete[] array_of_pointers;
}