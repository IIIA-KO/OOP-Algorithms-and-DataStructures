#include "HashTable.h"
#include "Menu.h"
int main()
{
	SetColor(0, 10);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*int n;
	cout << "Enter size of table: "; cin >> n;*/
	HashTable array(10);
	const char* textMenu[]{
		"1) Push student",
		"2) Delete student",
		"3) Print array of students",
		"4) Print exact student",
		"5) Save array to file",
		"6) Load array from file (you can't load array of students if you didn't load it previously)",
		"7) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");

	size_t select = 0;
	string temp_student_surname;
	Date temp_student_birthdate;
	const char* st_file = "students_array.txt";
	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 6:
			exit(-1);

		case 0: {
			cout << "Enter surname of student: "; cin >> temp_student_surname;
			cout << "Enter date of birth of student: "; temp_student_birthdate.Input_Date();
			Student temp_student(temp_student_surname, temp_student_birthdate);
			array.push(temp_student);
		}
			  break;

		case 1:
			cout << "Enter surname of student you want to delete: "; cin >> temp_student_surname;
			array.delete_student(temp_student_surname);
			break;

		case 2:
			array.Show();
			break;

		case 3:
			cout << "Enter surname of student you want to find: "; cin >> temp_student_surname;
			array.find_by_surname(temp_student_surname);
			break;

		case 4:
			array.Save(st_file);
			break;

		case 5:
			array.Load(st_file);
			break;
		}
		cout << "=========DONE=========\n";
		_getch();
	}
	return 0;
}