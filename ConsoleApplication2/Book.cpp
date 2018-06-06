#include "stdafx.h"
#include "Book.h"
#include "String.h"


void Book::print() {

	cout << FIO;

	cout << TITLE;

	cout << year;

	cout << count;

}

void Book::add(String& F, String& T, int Y, int C) {

	FIO = F;

	TITLE = T;

	year = Y;

	count = C;

}


void Book::addOpen(String F, String T, int Y, int C) {

	FIO = F;

	TITLE = T;

	year = Y;

	count = C;

}


Book::Book(Book* name) {

	if (*name == *this) {

		return;

	}

	else {

		year = name->year;

		count = name->count;

		FIO = name->FIO;

		TITLE = name->TITLE;

	}

}


int Book::operator== (Book& name) {

	if (year != name.year) {

		return 0;

	}

	if (count != name.count) {

		return 0;

	}

	if (!(FIO == name.FIO)) {

		return 0;

	}

	if (!(TITLE == name.TITLE)) {

		return 0;

	}

	return 1;

}

int Book::operator<(Book& book) {

	if (strcmp(book.fio(), fio()) < 0) {

		return 1;

	}

	return 0;
}

int Book::operator>(Book& book) {

	if (strcmp(book.fio(), fio()) > 0) {

		return 1;

	}

	return 0;
}

int Book::comp(Book  b1, Book  b2){

	if (b1.year > b2.year) return 1;

	else return 0;

}