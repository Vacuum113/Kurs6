// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Map.h"
#include "Element.h"
#include "String.h"
#include "Book.h"


using namespace std;


void print(Book* array, int count, int number) {

	setlocale(LC_ALL, "Russian");

	system("CLS");

	if (number == 0) {

		if (count == 0) { cout << "Книг нет" << endl; }

		else {

			for (int i = 0; i < count; i++) {

				cout << array[i].fio() << " ";

				cout << array[i].title() << " ";

				printf("%d %d\n", array[i].Year(), array[i].Count());

			}

		}

	}

	else {

		int k = 0;

		for (int i = 0; i < count; i++) {

			cout << k << ") " << array[i].fio() << " ";

			cout << array[i].title() << " ";

			printf("%d %d\n", array[i].Year(), array[i].Count());

			k++;

		}

	}

}

void menu() {

	setlocale(LC_ALL, "Russian");

	char Menu[] = "Menu:\n\
1) Добавть книгу\n\
2) Удалить книгу\n\
3) Отсортировать книги по авторам\n\
4) Отсортировать книги по датм издания\n\
0) Выйти\n\
";

	Map<String, Book> arr_FIO(4);


	ifstream Save("C:\\Games\\Libre\\Save.txt");

	char simvol[128];

	Save.get(simvol, 128, ' ');

	char* F = new char[128];

	char* T = new char[128];

	int Y;

	int C;

	int i = 0;

	while (simvol[0] != '\0') {

		if (i == 4) {

			i = 0;

			Book bookopen;

			String Fio(F), Title(T);

			bookopen.addOpen(Fio, Title, Y, C);

			String fio(bookopen.fio());

			arr_FIO.put(fio, bookopen);

			if (simvol[0] == '\n') { break; }

		}

		if (i == 0) { strcpy_s(F, 128, simvol); }

		else if (i == 1) { strcpy_s(T, 128, simvol); }

		else if (i == 2) { Y = atoi(simvol); }

		else if (i == 3) { C = atoi(simvol); }

		i++;

		Save.get(simvol[0]);

		int a = 1;

		while (simvol[a] != '\0') {

			simvol[a] = NULL;

			a++;

		}

		Save.get(simvol, 128, ' ');


		delete[] T;
		delete[] F;
	}

	Save.close();

	while (1) {

		system("CLS");

		Book* newArr = nullptr;

		arr_FIO.getALL(newArr);

		print(newArr, arr_FIO.Count(), 0);

		cout << Menu;

		int n;

		cin >> n;

		switch (n){

		case 0:
		{
			ofstream Save("C:\\Games\\Libre\\Save.txt");

			Book* arrayBooksSave = nullptr;

			arr_FIO.getALL(arrayBooksSave);

			for (int i = 0; i < arr_FIO.Count(); i++) {

				Save << arrayBooksSave[i].fio() << " ";

				Save << arrayBooksSave[i].title() << " ";

				Save << arrayBooksSave[i].Year() << " ";

				Save << arrayBooksSave[i].Count() << " ";

			}

			Save << "\n";

			Save.close();
			

			return;
		}

		case 1:
		{

			Book book;

			char* FIO;

			char* TITLE;

			int year, cownt;

			cout << "Ведите имя автора: ";

			FIO = new char[128];

			cin >> FIO;

			cout << "Ведите название книги: ";

			TITLE = new char[128];

			cin >> TITLE;

			cout << "Ведите дату издания: ";

			cin >> year;

			cout << "Ведите количество копий: ";

			cin >> cownt;

			String fio(FIO), title(TITLE);

			book.add(fio, title, year, cownt);

			arr_FIO.put(fio, book);

			delete[] FIO;
			delete[] TITLE;

			break;
		}
		

		case 2: 
		{

			cout << "Введите имя автора: ";

			char* name;

			name = new char[128];

			cin >> name;

			String Name(name);

			int i = 0;

			Book *tmp;

			tmp = arr_FIO.get(Name, i);

			if (tmp == NULL) cout << "Книг этого автора не найдено.";

			if (i != 0) {

				print(tmp, i, 1);

				cout << "Выберите № книги, которую хотите удалить: ";

				int m;

				cin >> m;

				arr_FIO.remove(tmp[m]);

			}

			Sleep(1000);
			
			delete[] name;

			break;
		}


		case 3:
		{

			cout << "1) По убыванию \n2) По возрастанию " << endl;

			int n;

			cin >> n;

			if (n == 1) {

				arr_FIO.sort_descen();

			}

			if (n == 2)
			{
				arr_FIO.sort_ascen();

			}

			if ((n != 2) & (n != 1)) cout << "Не верный выбор";
			
			Sleep(1000);

			break;
		}
		

		case 4: 
		{

			cout << "1) По убыванию \n2) По возрастанию " << endl;

			int n;

			cin >> n;

			if (n == 1) {

				arr_FIO.sort_spec_descen();

			}

			if (n == 2)
			{
				arr_FIO.sort_spec_ascen();

			}

			if ((n != 2) & (n != 1)) cout << "Не верный выбор";

			Sleep(1000);

			break;
		}


		default:
			cout << "Не вернны выбор.";
			break;

		}

		
	}


}

int main()
{

	menu();

	system("pause");

	return 0;

}