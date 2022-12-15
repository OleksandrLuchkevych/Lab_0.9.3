#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

struct Note
{
	string prizv;
	string name;
	unsigned tel_number;
	int birthday[3];
};
void Create(Note* p, const int N, int& birthday);
void Print(Note* p, const int N, int birthday, int tel_number);
void Sort(Note* p, const int N);
int BinSearch(Note* p, const int N, const string prizv);
void Inform(Note* p, const int N, string prizv);
void SaveToFile(Note* p, const int N, const char* filename);
void LoadFromFile(Note*& p, int& N, const char* filename);


int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу  
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть кількість людей N: "; cin >> N;
	int birthday[3];

	Note* p = new Note[N];
	int m=0;
	string prizv;
	int found;
	int tel_number{};
	char filename[100];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - бінарний пошук особи за прізвищем" << endl;
		cout << " [5] - запис даних у файл" << endl;
		cout << " [6] - зчитування даних із файлу" << endl << endl;


		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N, birthday[3]);
			break;
		case 2:
			Print(p, N, birthday[3], tel_number);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cout << " прізвище: "; cin >> prizv;

			Inform(p, N, prizv);
			break;

		case 5:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 6:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		}


	} while (menuItem != 0);
	return 0;
}
void Create(Note* p, const int N, int& birthday)
{
	//int birthday[3];
	for (int i = 0; i < N; i++)
	{
	
		
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " ім'я: "; cin >> p[i].name;
		cout << " номер телефону: "; cin >> p[i].tel_number;
		cout << " день народження: "; cin >> p[i].birthday[0];
		cout << " місяць народження: "; cin >> p[i].birthday[1];
		cout << " рік народження: "; cin >> p[i].birthday[2];

	}
}
void Print(Note* p, const int N, int birthday, int tel_number)
{
	cout << "=================================================================================================="
		<< endl;
	cout << "| № | Прізвище |   Ім'я   | Номер телефону | День народження | Місяць народження | Рік народження|" 
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
	
		cout << "| " << setw(2) << i + 1;
		cout << "| " << setw(9) << p[i].prizv;
		cout << "| " << setw(9) << p[i].name;
		cout << "| " << setw(15) << p[i].tel_number;
		cout << "| " << setw(16) << p[i].birthday[0];
		cout << "| " << setw(18) << p[i].birthday[1];
		cout << "| " << setw(14) << p[i].birthday[2] << "|";
		cout << endl;
	}
	cout << "=================================================================================================="
		<< endl;
	cout << endl;
}
void Sort(Note* p, const int N)
{
	Note tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (p[i1].tel_number < p[i1+1].tel_number)
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
int BinSearch(Note* p, const int N, const string prizv)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv)
			return m;
		if (p[m].prizv < prizv)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
void Inform(Note* p, const int N, string prizv)
{
	for (int m = 0; m < N; m++)
	{
		if (p[m].prizv == prizv)
		{
			cout << "=============================================================================================="
				<< endl;
			cout << "| Прізвище |   Ім'я   | Номер телефону | День народження | Місяць народження | Рік народження|"
				<< endl;
			cout << "----------------------------------------------------------------------------------------------"
				<< endl;

			//cout << "| " << setw(2) << m + 1;
			cout << "| " << setw(9) << p[m].prizv;
			cout << "| " << setw(9) << p[m].name;
			cout << "| " << setw(15) << p[m].tel_number;
			cout << "| " << setw(16) << p[m].birthday[0];
			cout << "| " << setw(18) << p[m].birthday[1];
			cout << "| " << setw(14) << p[m].birthday[2] << "|";
			cout << endl;

			cout << "=============================================================================================="
				<< endl;
			cout << endl;
			return;
		}
		
	}
	cout << "Даної особи не найдено" << endl;
}
void SaveToFile(Note* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Note)); // записали елементи масиву
	fout.close(); // закрили файл
}
void LoadFromFile(Note*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Note[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Note)); // прочитали елементи масиву
	fin.close(); // закрили файл
}


