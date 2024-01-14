#include "List.h"
#include "Student.h"
#include "Menu.h"
int main()
{
	SetColor(0, 10);
	int choice = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Push_back student",
		"2) Push student by index",
		"3) Delete_back student",
		"4) Delete student by index",
		"5) Print array of students",
		"6) Print exact student",
		"7) Find student by surname",
		"8) Sort array of students",
		"9) Save array to file",
		"10) Load array from file (you can't load array of students if you didn't load it previously)",
		"11) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");

	size_t select = 0;
	List array;
	String temp_student_surname;
	Date temp_student_birthdate;
	const char* st_file = "students_array.txt";
	const char* st_file_def = "default_students_array.txt";
	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 10:
			exit(-1);

		case 0: {
			cout << "Enter surname of student: "; temp_student_surname.Input_Str();
			cout << "Enter date of birth of student: "; temp_student_birthdate.Input_Date();
			Student temp_student(temp_student_surname, temp_student_birthdate);
			array.push_back(temp_student);
		}
			  break;

		case 1: {
			int insert_index;
			cout << "Enter index where you want to push student: "; cin >> insert_index;
			cout << "Enter surname of student: "; temp_student_surname.Input_Str();
			cout << "Enter date of birth of student: "; temp_student_birthdate.Input_Date();
			Student temp_student(temp_student_surname, temp_student_birthdate);
			array.insert(temp_student, insert_index);
		}
			  break;

		case 2:
			array.del_tail();
			break;

		case 3: {
			int del_index;
			cout << "Enter index of student you want to delete from array: "; cin >> del_index;
			array.del_ind(del_index);
		}
			  break;

		case 4:
			array.Show();
			break;

		case 5: {
			int ind = 0;
			cout << "Enter index of student you want to print: "; cin >> ind;
			array.Show_exact(ind);
		}
			  break;

		case 6:
			cout << "Enter surname of student you want to find: "; cin >> temp_student_surname;
			array.FindBySurname(temp_student_surname);
			break;

		case 7:
			array.Sort();
			break;

		case 8:
			array.Save_Students(st_file, array);
			break;

		case 9:
			array.Load_Students(st_file);			//можна використати деволтний список, передавши у функцію 'Load_Students' змінну 'st_file_def'
			break;
		}
		cout << "=========DONE=========\n";
		_getch();
	}
	return 0;
}