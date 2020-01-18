#include "STUDENT.h"

using namespace std;

// конструктор по умолчанию
STUDENT::STUDENT() {
	cout << "STUDENT: empty constructor" << endl;
	name = "tmp";
	group = 1;

	for (int i = 0; i < scoresCount; i++)
		scores[i] = 5;
}

// конструктор копирования
STUDENT::STUDENT(const STUDENT & student) {
	cout << "STUDENT: copy constructor" << endl;
	name = student.name;
	group = student.group;

	for (int i = 0; i < scoresCount; i++)
		scores[i] = student.scores[i];
}

// конструктор с параметрами
STUDENT::STUDENT(string name, int group, int scores[]) {
	cout << "STUDENT: constructor with parameters" << endl;
	this->name = name;
	this->group = group;

	for (int i = 0; i < scoresCount; i++)
		this->scores[i] = scores[i];
}

// геттеры
string STUDENT::GetName() {
	return name;
}

int STUDENT::GetGroup() {
	return group;
}

int* STUDENT::GetScores() {
	return scores;
}

// получение среднего балла
double STUDENT::GetAverage() {
	double average = 0;

	for (int i = 0; i < scoresCount; i++)
		average += scores[i];

	return average / 5.0;
}

// сеттеры
void STUDENT::SetName(string name) {
	this->name = name;
}

void STUDENT::SetGroup(int group) {
	this->group = group;
}

void STUDENT::SetScores(int* scores) {
	for (int i = 0; i < scoresCount; i++)
		this->scores[i] = scores[i];
}

// оператор присваивания
STUDENT& STUDENT::operator=(const STUDENT & student) {
	if (this == &student)
		return *this;

	name = student.name;
	group = student.group;

	for (int i = 0; i < scoresCount; i++)
		scores[i] = student.scores[i];

	return *this;
}

// деструктор (освобождения памяти)
STUDENT::~STUDENT() {
	cout << "STUDENT: destructor" << endl;
}

// считывание из потока
std::istream& operator>>(std::istream & is, STUDENT & student) {
	cout << "Enter name: ";
	cin.ignore();
	getline(is, student.name); // считыванием имя

	cout << "Enter group: ";
	is >> student.group; // считывание группы

	// бросаем исключение, если номер отрицательный
	if (student.group < 1)
		throw string("Group number must be positive");


	cout << "Enter scores: ";
	bool crash = false;

	// считываем оценки
	for (int i = 0; i < scoresCount; i++) {
		is >> student.scores[i];

		if (student.scores[i] < 1 || student.scores[i] > 5)
			crash = true;
	}

	// если какая-то оценка оказалась некорректной, бросаем исключение
	if (crash)
		throw string("Score must be from 1 to 5");

	return is;
}


// оператор вывода в поток
ostream& operator<<(ostream & os, const STUDENT & student) {
	os << "Name: " << student.name << endl;
	os << "Grop: " << student.group << endl;
	os << "Scores: ";

	for (int i = 0; i < scoresCount; i++)
		os << student.scores[i] << " ";

	os << endl;

	return os;
}
