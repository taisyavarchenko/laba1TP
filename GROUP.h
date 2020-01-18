#pragma once
#include <iostream>#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "STUDENT.h"

class GROUP {
	STUDENT* students; // студенты
	int capacity; // ёмкость
	int size; // размер
public:
	GROUP(); // конструктор по умолчанию
	GROUP(const GROUP& group); // конструктор копирования
	GROUP(STUDENT* students, int size); // конструктор с параметрами

	GROUP& operator=(const GROUP& group); // оператор присваивания
	void Sort(); // сортировка по номеру группы
	void AddStudent(const STUDENT& student); // добавление студента
	void RemoveStudent(); // удаление студенту
	void PrintByKey(); // вывод тех, у кого балл выше 4

	~GROUP(); // деструктор (освобождение памяти)

	friend std::ostream& operator<<(std::ostream& os, const GROUP& group); // оператор вывода в поток
};
