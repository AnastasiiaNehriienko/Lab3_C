#include <string>
using namespace std;
class Date {  //класс для дат. Зокрема, для дати народження
	int day, month, year;
public:
	void setD(int, int, int);
	void print();
	int getD();
	int getM();
	int getY();
};

class Student {  //класс для студента
	string surname, name;
	int group_num;
	Date birthday;
public:
	void SetStudent(string, string);
	void setNum(int);
	int getNum();
	void setBday(int, int, int);
	Date get_Bday();
	void get_Stud();
};