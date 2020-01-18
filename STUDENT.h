#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int scoresCount = 5;

// класс студент
class STUDENT {
	string name; // фаимилия и инициалы
	int group; // группа
	int scores[scoresCount]; // оценки

public:
	STUDENT(); // конструктор по умолчанию
	STUDENT(const STUDENT& student); // конструктор копирования
	STUDENT(string name, int group, int scores[]); // конструктор копирования

	// геттеры
	string GetName(); // получение имени
	int GetGroup(); // получение группы
	int* GetScores(); // получение оценок

	// сеттеры
	void SetName(string name);
	void SetGroup(int group);
	void SetScores(int* scores);

	double GetAverage(); // получение среднего балла

	STUDENT& operator=(const STUDENT& student); // оператор присваивания

	~STUDENT(); // деструктор (освобождение памяти)

	friend std::ostream& operator<<(std::ostream& os, const STUDENT& student); // оператор вывода в поток
	friend std::istream& operator>>(std::istream& os, STUDENT& student); // оператор считывания из потока
};
