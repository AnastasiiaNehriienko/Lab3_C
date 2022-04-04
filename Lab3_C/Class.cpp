#include <iostream>
#include <string>
#include "Class.h"
using namespace std;
void Date::setD(int d, int m, int y) {
	day = d; month = m; year = y;  //задання дати
}
void Date::print() {
	printf("%02d-%02d-%4d\n", day, month, year);  //виведення дати у форматі DD-MM-YYYY
}
int Date::getD() {
	return day;  //отримання дня
}
int Date::getM() {
	return month;  //отримання місяця
}
int Date::getY() {
	return year;  //отримання року
}

void Student::SetStudent(string s, string n) {  //задання імені студента
	surname = s;
	name = n;
}
void Student::setNum(int group) {  //задання номеру групи
	group_num = group;
}
void Student::setBday(int d, int m, int y) {  //задання дня народження
	birthday.setD(d, m, y);
}
Date Student::get_Bday() {  //отримання дня народження
	return birthday;
}
void Student::get_Stud() {  //виведення інформації про студента
	cout << name << " " << surname << ". Group number is " << group_num << ".\n";
	cout << "Birthday: ";
	birthday.print();
}
int Student::getNum() {  //отримання номеру групи
	return group_num;
}