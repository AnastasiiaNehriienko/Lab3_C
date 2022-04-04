/*Розробити клас «Студент», який характеризується ім'ям студента, номером його группи,
датою народження (у форматі ММ-ДД-РРРР). Створити масив об'єктів даного класу.
Визначити найстаршого студента вказаної групи.*/
#include "Funcs.h"
int main() {
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	Student** points;  //динамічний двовимірний масив для груп та їх студентів
	int n, m;  //розмірність
	cout << "Enter the ammount of groups: "; cin >> n;
	cout << "Enter the ammount of students: "; cin >> m;
	points = list_of_groups(n, m);  //створення масиву
	print_middle_res(n, m, points);  //виведення проміжних результатів
	find_group(n, m, points);  //пошук старшого у потрібній групі
	deleting(n, points);  //видалення динамічної структури
	return 0;
}