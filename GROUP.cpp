#include "GROUP.h"

using namespace std;

// конструктор по умолчанию
GROUP::GROUP() {
	cout << "GROUP: empty constructor" << endl;
	size = 0;
	capacity = 1;
	students = new STUDENT[capacity];
}

// конструктор копирования
GROUP::GROUP(const GROUP& group) {
	cout << "GROUP: copy constructor" << endl;

	size = group.size;
	capacity = group.capacity;
	students = new STUDENT[capacity];

	for (int i = 0; i < size; i++)
		students[i] = group.students[i];
}

GROUP::GROUP(STUDENT * students, int size) {
	cout << "GROUP: constructor with parameters" << endl;

	this->size = size;
	capacity = size + 1;
	this->students = new STUDENT[capacity];

	for (int i = 0; i < size; i++) {
		this->students[i] = students[i];
	}
}

// оператор присваивания
GROUP& GROUP::operator=(const GROUP & group) {
	if (this == &group)
		return *this;

	size = group.size;
	capacity = group.capacity;
	students = new STUDENT[capacity];

	for (int i = 0; i < size; i++)
		students[i] = group.students[i];

	return *this;
}

// добавление студента
void GROUP::AddStudent(const STUDENT & student) {
	students[size++] = student; // записываем его в массив
	cout << endl << "Student has been added" << endl;
	Sort(); // сортируем по группе

	// расширяем память, если требуется
	if (size >= capacity) {
		capacity *= 2;

		STUDENT* tmp = new STUDENT[capacity];

		for (int i = 0; i < size; i++)
			tmp[i] = students[i];

		delete[] students;
		students = tmp;
	}
}

// удаление студента
void GROUP::RemoveStudent() {
	if (size == 0)
		throw string("Unable to delete student. Group is empty");

	int number; // номер студента

	cout << "Enter student number to delete: ";
	cin >> number; // считываем номер

	// если номер не входит в нужный интервал, бросаем исключение
	if (number < 1 || number > size)
		throw string("Student number must be from 1 to " + to_string(size));

	// сдвигаем студентов
	for (int i = number; i < size; i++) {
		students[i - 1] = students[i];
	}

	size--; // уменьшаем размер
	cout << "Student has been removed" << endl;
}

// сортировка по группе
void GROUP::Sort() {
	// обычная сортировка пузырьком
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (students[j].GetGroup() > students[j + 1].GetGroup()) {
				STUDENT tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
			}
		}
	}
}

// вывод тех, у кого балл > 4
void GROUP::PrintByKey() {
	int count = 0; // число студентов

	// проверяем каждого студенты
	for (int i = 0; i < size; i++) {
		// если балл выше 4, выводим его
		if (students[i].GetAverage() > 4) {
			// если это был 1 студент, то выводим инфу
			if (count == 0)
				cout << endl << "Student with average score more then 4" << endl << endl;

			cout << students[i] << endl;
			count++;
		}
	}

	// если не было ни одного студенты, то выводим это
	if (count == 0)
		cout << endl << "No one student with average score more then 4" << endl;
}


// деструктор (освобождения памяти)
GROUP::~GROUP() {
	cout << "GROUP: destructor" << endl;
	delete[] students;
}

// оператор вывода в поток
ostream& operator<<(ostream & os, const GROUP & group) {
	if (group.size == 0)
		os << endl << "Empty group" << endl;

	for (int i = 0; i < group.size; i++) {
		os << "Student " << (i + 1) << endl;
		os << group.students[i] << endl;
	}

	return os;
}
