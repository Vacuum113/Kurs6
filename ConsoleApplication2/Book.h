#pragma once
#include "String.h"
#include <iostream>

using namespace std;



class Book {

private:

	String FIO;

	String TITLE;

	int year;

	int count;

public:

	Book() {}
	
	~Book() {}

	void print();

	//Добавление данных в объект

	void add(String& F, String& T, int Y, int C);

	void addOpen(String F, String T, int Y, int C);

	char* title() { return TITLE.name(); }

	char* fio() { return FIO.name(); }

	int Year() { return year; }

	int Count() { return count; }

	Book(Book* name);

	//Перегрузка оператора сравнения

	int operator== (Book& name);

	//Перегрузка оператора сравнения по ФИО

	int operator<(Book& book);

	//Перегрузка оператора сравнения по ФИО

	int operator>(Book& book);

	//Перегрузка оператора сравнения по году

	static int comp(Book, Book);

};

