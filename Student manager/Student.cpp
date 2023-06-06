#include<iostream>
#include<cstdlib>
#include<fstream>//для роботи з файлами 
#include<conio.h>//текстовий ввід-вивід 

using namespace std;

class Student {
private:
	string number, name, surname, course, mark, address, email, contact;
public:
	void Menu();
	void insert();
	void Display();
	void Change();
	void Search();
	void Delete();
};
void Student::Menu() {
	menustart:
	system("cls");
	cout << "\n\n\t\t\t\t\t\t Welcome to Student Management System!";
	cout << "\n\n\t Select an option:";
	cout << "\n\n\t\t 1) Make a new note ";
	cout << "\n\n\t\t 2) Show notes  ";
	cout << "\n\n\t\t 3) Change notes ";
	cout << "\n\n\t\t 4) Find a note ";
	cout << "\n\n\t\t 5) Delete note ";
	cout << "\n\n\t\t 6) Exit ";
	cout << "\n\n\n\tEnter your choice:  ";
	int choice;
	char x;
	cin >> choice;
	switch (choice)
	{
	case 1:
		do {
			insert();
			cout << "\n\n\n\tDo you want to add another student? (Y - yes/N - no) -  ";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	default:
		cout << "\n\n\t\t Incorrect choice, enter a number from the list! ";

	case 2:
		Display();
		break;

	case 3:
		Change();
		break;

	case 4:
		Search();
		break;

	case 5:
		Delete();
		break;

	case 6:
		exit(0);
		break;
	}
	_getch();
	goto menustart;
}

void Student::insert(){
	system("cls");
	fstream file; 
	cout << "\n\n\t\t\t\t\t\t Add student data";
	cout << "\n\n\n\t Enter number in the list: ";
		cin >> number;
		cout << "\n\n\n\t Enter name: ";
		cin >> name;
		cout << "\n\n\n\t Enter surname: ";
		cin >> surname;
		cout << "\n\n\n\t Enter course: ";
		cin >> course;
		cout << "\n\n\n\t Enter mark: ";
		cin >> mark;
		cout << "\n\n\n\t Enter address: ";
		cin >> address;
		cout << "\n\n\n\t Enter email: ";
		cin >> email;
		cout << "\n\n\n\t Enter contact: ";
		cin >>contact;
		file.open("StudentNotes.txt", ios::app | ios::out);//створює текстовий документ з даними  
		file<< " " << number <<" " << name << " " << surname << " " << course << " " << mark << " " << address << " " << email << " " << contact << "\n";
	    file.close();
}

void Student::Display() {
	system("cls");
	fstream file;
	int total = 0;
	cout << "\n\n\t\t\t\t\t\t Table of student records";
	file.open("StudentNotes.txt", ios::in);//Ввід даних у файл
	if (!file) {
		cout << "\n\n\n\t There is no data in the list! ";//Якщо файл пустий 
		file.close();
	}
	else {
		file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		while (!file.eof()) { //повертає true, якщо файл пустий, а якщо не пустий, то false 
			cout << "\n\n\n\t No: " << total++ <<endl;
			cout << "\t Student number in the list: " << number <<endl;
			cout << "\t Student name: " << name <<endl;
			cout << "\t Student surname: " << surname <<endl;
			cout << "\t Student course: " << course <<endl;
			cout << "\t Student mark: " << mark <<endl;
			cout << "\t Student address: " << address <<endl;
			cout << "\t Student email: " << email <<endl;
			cout << "\t Student contact: " << contact <<endl;
			file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		}
		if (total == 0) {
			cout << "\n\n\n\t There is no data in the list! ";
		}
	}
	file.close();
}

void Student::Change() {
	system("cls");
	fstream file, file1;//додатковий файл для змінених даних 
	string number1;
	int found = 0;
	cout << "\n\n\t\t\t\t\t\t Change student details";
	file.open("StudentNotes.txt", ios::in);
	if (!file) {
		cout << "\n\n\n\t There is no data in the list! ";
	}
	else {
		cout << "\n\n\n\t Enter the number in the list of the student whose data you want to change: ";
		cin >> number1;
		file1.open("NewNotes.txt", ios::app | ios::out);
		file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		while (!file.eof()) {
			if (number != number1) {
				file1 << " " << number << " " << name << " " << surname << " " << course << " " << mark << " " << address << " " << email << " " << contact << "\n";
			}
			else {
				cout << "\n\n\n\t Enter number in the list: ";
				cin >> number;
				cout << "\n\n\n\t Enter name: ";
				cin >> name;
				cout << "\n\n\n\t Enter surname: ";
				cin >> surname;
				cout << "\n\n\n\t Enter course: ";
				cin >> course;
				cout << "\n\n\n\t Enter mark: ";
				cin >> mark;
				cout << "\n\n\n\t Enter address: ";
				cin >> address;
				cout << "\n\n\n\t Enter email: ";
				cin >> email;
				cout << "\n\n\n\t Enter contact: ";
				cin >> contact;
				file1 << " " << number << " " << name << " " << surname << " " << course << " " << mark << " " << address << " " << email << " " << contact << "\n";
				found++;
			}
			file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
			if (found == 0) {
				cout << "\n\n\n\t There is no student with this number! ";
			}
		}
		file1.close();
		file.close();
		remove("StudentNotes.txt"); //Видаляє старий StudentNotes 
		rename("NewNotes.txt", "StudentNotes.txt");  //створює новий StudentNotes зі змінами
	}
}

void Student::Search() {
	system("cls");
	fstream file; 
	int found = 0;
	file.open("StudentNotes.txt", ios::in);
	if (!file) {
		cout << "\n\n\t\t\t\t\t\t Student search";
		cout << "\n\n\n\t There is no data in the list! ";
	}
	else {
		string number1;
		cout << "\n\n\t\t\t\t\t\t Student search";
		cout << "\n\n\n\t Enter the number in the list of the student you want to find: ";
		cin>>number1;
		file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		while (!file.eof()) {
			if (number1 == number) { //якщо співпадає, виводить дані студента 
				cout << "\t Student number in the list: " << number << endl;
				cout << "\t Student name: " << name << endl;
				cout << "\t Student surname: " << surname << endl;
				cout << "\t Student course: " << course << endl;
				cout << "\t Student mark: " << mark << endl;
				cout << "\t Student address: " << address << endl;
				cout << "\t Student email: " << email << endl;
				cout << "\t Student contact: " << contact << endl;
				found++;
			}
			file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		}
		if (found == 0) {
			cout << "\n\n\n\t There is no student with this number! ";
		}
		file.close();
	}
}

void Student::Delete() {
	system("cls");
	fstream file, file1;
	string number1;
	int found = 0;
	cout << "\n\n\t\t\t\t\t\t Deleting student data";
	file.open("StudentNotes.txt", ios::in);
	if (!file) {
		cout << "\n\n\n\t There is no data in the list! ";
	}
	else {
		cout << "\n\n\n\t Enter the number in the list of the student you want to delete: ";
		cin >> number1;
		file1.open("NewNotes.txt", ios::app | ios::out);
		file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		while (!file.eof()) {
			if (number1 != number) {
				file1 << " " << number << " " << name << " " << surname << " " << course << " " << mark << " " << address << " " << email << " " << contact << "\n";
			}
			else {
				found++;
				cout << "\n\n\n\t Data deleted successfully! ";
			}
			file >> number >> name >> surname >> course >> mark >> address >> email >> contact;
		}
		if (found == 0) {
			cout << "\n\n\n\t There is no student with this number! ";
		}
		file1.close();
		file.close(); 
		remove("StudentNotes.txt");                  // Видаляє старий файл
		rename("NewNotes.txt","StudentNotes.txt" ); // Створює новий і перейменовує  
	}
}

int main() {
	system("title Student Management.exe");
	Student board;
	board.Menu();
	return 0;
}
