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

	Map(int  k) {

		size = k;

		array = new Element<TKey, TValue>[size];

	}

	~Map() {

		delete[] array;

	}

	void put(TKey key, TValue value) {

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

	TValue* get(TKey key, int &number) {

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

	void remove(TValue value) {

		for (int i = 0; i < count; i++) {

			if (value == array[i].value) {

				array[i] = array[count - 1];

				count--;

			}

		}

	}

	int Count() { return count; }

	void getALL(TValue*& newArr) {

		newArr = new TValue[count];

		TValue *tmp = new TValue[count];

		for (int i = 0; i < count; i++) {

			tmp[i] = array[i].value;

			newArr[i] = tmp[i];

		}

	}

	void sort_descen() {

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


	void sort_ascen() {

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

	void sort_spec_ascen() {

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

	void sort_spec_descen() {

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

	template <class K2>
	void rearrange(Map<K2, TValue>& rhs) {

		int n = 0;

		for (int i = 0; i < count; i++) {

			for (int j = 0; j < count; j++) {

				if (this->array[i].value == rhs.array[j].value) {

					n = j;

					break;

				}

			}

			Element<TKey, TValue>* tmp = new Element<TKey, TValue>();

			tmp->value = this->array[n].value;

			tmp->key = this->array[n].key;

			this->array[n].value = this->array[i].value;

			this->array[n].key = this->array[i].key;

			this->array[i].value = tmp->value;

			this->array[i].key = tmp->key;

		}

	}

};

