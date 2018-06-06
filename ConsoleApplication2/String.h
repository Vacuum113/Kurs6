#pragma once

#include <iostream>

using namespace std;

class String {

private:

	char* array = NULL;

	int size = 0;

public:

	String() {}

	String(char* name);

	String(String& name);

	String(String* name);

	~String();

	char* name() { return array; }

	int operator==(String& key);

	String & operator=(String& key);


	friend ostream &operator<<(ostream &out, String &p) {

		out << p.array;

		return out;
	}

};
