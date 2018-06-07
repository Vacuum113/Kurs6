#pragma once

#include "Element.h"
#include "String.h"



template <class TKey, class TValue>
class Map {

private:

	int size;

	int count = 0;

public:

	Element<TKey, TValue> *array;

	Map(int  k);

	~Map();

	void put(TKey key, TValue value);

	TValue* get(TKey key, int &number);

	void remove(TValue value);

	int Count();

	void getALL(TValue*& newArr);

	void sort_descen();

	void sort_ascen();

	void sort_spec_ascen();

	void sort_spec_descen();

};

//Конструктор

template <class TKey, class TValue>
Map<TKey,TValue>::Map(int  k) {

	size = k;

	array = new Element<TKey, TValue>[size];

}

//Деструктор

template <class TKey, class TValue>
Map<TKey, TValue>::~Map() {

	delete[] array;

}

//Метод для внесение элеменда в коллекцию

template <class TKey, class TValue>
void Map<TKey, TValue>::put(TKey key, TValue value) {

	if (count == size) {

		Element<TKey, TValue> *tmp = array;

		size *= 2;

		array = new Element<TKey, TValue>[size];

		memcpy(array, tmp, sizeof(Element<TKey, TValue>) * count);

		delete[] tmp;

	}

	array[count].key = key;

	array[count].value = value;

	count++;

}

//Метод для получения элемента из коллекции

template <class TKey, class TValue>
TValue* Map<TKey, TValue>::get(TKey key, int &number) {

	int n = 0;

	bool no = true;

	TValue *tmp = new TValue[1024];

	for (int i = 0; i < count; i++) {

		if (array[i].key == key) {

			tmp[n] = array[i].value;

			n++;

			no = false;

		}

	}

	if (no) {

		return NULL;

	}

	TValue *newArr = new TValue[n];

	for (int i = 0; i < n; i++) {

		newArr[i] = tmp[i];

	}

	number = n;

	return newArr;

}

//Метод для удаления элемента

template <class TKey, class TValue>
void Map<TKey, TValue>::remove(TValue value) {

	for (int i = 0; i < count; i++) {

		if (value == array[i].value) {

			array[i] = array[count - 1];

			count--;

		}

	}

}

//Метод для получения значения count

template <class TKey, class TValue>
int Map<TKey, TValue>::Count(){

	return count;
}

//Метод для получения всех элементов в новый массив

template <class TKey, class TValue>
void Map<TKey, TValue>::getALL(TValue*& newArr) {

	newArr = new TValue[count];

	TValue *tmp = new TValue[count];

	for (int i = 0; i < count; i++) {

		tmp[i] = array[i].value;

		newArr[i] = tmp[i];

	}

}

//Обычная сортировка по убыванию по ФИО

template <class TKey, class TValue>
void Map<TKey, TValue>::sort_descen() {

	TValue tmp;

	for (int i = 0; i < count; i++) {

		for (int j = i; j < count; j++) {

			if (array[i].value < array[j].value) {

				tmp = array[j].value;

				array[j].value = array[i].value;

				array[i].value = tmp;

			}

		}

	}

}

//Обычная сортировка по возрастанию по ФИО

template <class TKey, class TValue>
void Map<TKey, TValue>::sort_ascen() {

	TValue tmp;

	for (int i = 0; i < count; i++) {

		for (int j = i; j < count; j++) {

			if (array[i].value > array[j].value) {

				tmp = array[i].value;

				array[i].value = array[j].value;

				array[j].value = tmp;

			}

		}

	}

}

//Сортировка по возрастанию по году

template <class TKey, class TValue>
void Map<TKey, TValue>::sort_spec_ascen() {

	TValue tmp;

	for (int i = 0; i < count; i++) {

		for (int j = i; j < count; j++) {

			if (Book::comp(array[i].value, array[j].value) == 1) {

				tmp = array[i].value;

				array[i].value = array[j].value;

				array[j].value = tmp;

			}

		}

	}

}


//Сортировка по убыванию по году

template <class TKey, class TValue>
void Map<TKey, TValue>::sort_spec_descen() {

	TValue tmp;

	for (int i = 0; i < count; i++) {

		for (int j = i; j < count; j++) {

			if (Book::comp(array[i].value, array[j].value) == 0) {

				tmp = array[j].value;

				array[j].value = array[i].value;

				array[i].value = tmp;

			}

		}

	}

}