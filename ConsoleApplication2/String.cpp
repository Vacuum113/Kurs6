#include "stdafx.h"
#include "String.h"


String::String(char* name) {

	while (name[size] != '\0') {

		size++;

	}

	size++;

	array = new char[size];

	array[0] = '\0';

	strcpy_s(array, size, name);
}

String::String(String& name) {

	if (name == *this) { return; }

	else {

		size = name.size;

		array = new char[size];

		strcpy_s(array, size, name.array);

	}

}

String::String(String* name) {

	if (*name == *this) { return; }

	else {

		size = name->size;

		array = new char[size];

		strcpy_s(array, size, name->array);

	}

}

String::~String() {

	if (array != NULL) {

		delete array;

	}

}

int String::operator==(String& key) {

	if (key.array == NULL) {

		return 0;

	}

	if (strcmp(key.array, array) == 0) {

		return 1;

	}

	return 0;

}

String& String::operator=(String& key) {

	if (this == &key)

		return *this;

	size = 0;

	if (this->array != NULL)

		delete array;

	int s = 0;

	while (key.name()[s] != '\0') {

		s++;

	}

	s++;

	size = s;

	this->array = new char[size];

	strcpy_s(this->array, size, key.name());

	return *this;

}
