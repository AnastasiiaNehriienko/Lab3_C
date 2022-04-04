#include <iostream>
#include <string>
#include "Class.h"
//#include <Windows.h>
using namespace std;
Student create_stud(int);  //введення інформації по кожному студенту
Student** list_of_groups(int, int);  //визначення кількості та створення списку груп
Student* list_of_students(int);  //визначення кількості та створення списку студентів групи
void print_middle_res(int, int, Student**);  //виведення проміжних результатів
void deleting(int, Student**);  //видалення динамічних структур
void find_group(int, int, Student**);  //у якій группі шукати?
void find_oldest(int, Student*);  //пошук найстаршого
Student create_stud(int group) {
	Student person;
	string n, s;
	int d, m, y;
	cout << "Enter the name and surname: ";
	cin >> n >> s;
	person.SetStudent(s, n);
	cout << "Enter the birthday with spaces between: ";
	cin >> d >> m >> y;
	person.setBday(d, m, y);
	person.setNum(group);
	return person;
}
Student** list_of_groups(int n, int m) {
	Student** p = new Student * [n];
	for (int i = 0; i < n; i++) {
		p[i] = list_of_students(m);
	}
	return p;
}
Student* list_of_students(int m) {
	Student* p = new Student[m];
	int group_num;
	cout << "What is the number of group? ";
	cin >> group_num;
	for (int j = 0; j < m; j++) {
		p[j] = create_stud(group_num);
	}
	return p;
}
void print_middle_res(int n, int m, Student** p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j].get_Stud();
		}
	}
}
void deleting(int n, Student** p) {
	for (int i = 0; i < n; i++)
		delete[] p[i];
	delete[] p;
}
void find_group(int n, int m, Student** p) {
	int group, i=0;
	bool found=false;
	int n_found = -1;
	cout << "Enter the number of group you want to find the student in: "; cin >> group;
	while (i < n && !found) {
		if (p[i][0].getNum() == group) {
			found = true;
			n_found = i;
		}
		i++;
	}
	if (n_found == -1)
		cout << "Group is not found!";
	else find_oldest(m, p[n_found]);
}
void find_oldest(int m, Student* p) {
	int oldest = 0;  //потрібний студент
	Date bday=p[0].get_Bday();  //дата для порівняння
	Date tempor_bday;
	for (int i = 1; i < m; i++) {
		tempor_bday = p[i].get_Bday();
		if (tempor_bday.getY() < bday.getY())  //якщо рік раніше
		{
			bday = tempor_bday; oldest = i;
		}
		else if (tempor_bday.getY() == bday.getY() && tempor_bday.getM() < bday.getM())  //якщо рік рівний, місяць раніше
		{
			bday = tempor_bday; oldest = i;
		}
		else if (tempor_bday.getY() == bday.getY() && tempor_bday.getM() == bday.getM() && tempor_bday.getD() < bday.getD())  //день раніше
		{
			bday = tempor_bday; oldest = i;
		}
	}
	cout << "The oldest is\n";
	p[oldest].get_Stud();
}