#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "Matrix.h"
using namespace std;

int row, col;
int col2, row2;
int file_col, file_row;
int ans;
double scal;

Matrix* m;
Matrix* m2;
Matrix* m3;

int main()
{
    setlocale(LC_ALL, "Russian");
	readFile(file_col, file_row);

	for (;;)
	{
		int v;
		v = menu();
		switch (v) {

		case 1: //создание новой матрицы
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
			
			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";
			if (ans == 1 || ans == 2)
			{
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";

				cin >> row;
				cin >> col;
			}
			if (ans == 3) {
				row = file_row;
				col = file_col;

			}
			m = new Matrix(row, col, ans);
			cout << "Матрица успешно создана\n";
			m->printMatrix();
			break;


		case 2: //плюс
			
			
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически"; 
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}
			

			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";
			m2 = new Matrix(row, col, ans);
			m3 = new Matrix(row, col, 0);
			
			m->plus(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();
			
			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";

			break;



		case 3: //минус

			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_col != col || file_row != row) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}


			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";
			m2 = new Matrix(row, col, ans);
			m3 = new Matrix(row, col, 0);

			m->minus(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";
			
			break;


		case 4: //умножение на матрицу

			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически";
			if (file_row != col) {
				cout << "\nЗагрузка из файла недоступна\n" << endl;
			}
			else {
				cout << "\n3 - загрузить из файла\n" << endl;
			}

			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";

			if (ans == 1 || ans == 2)
			{
				cout << "\nВведите количество столбцов второй матрицы: ";
				cin >> col2;	
			}
			if (ans == 3)
				col2 = file_col;
			row2 = col;

			
			m2 = new Matrix(row2, col2, ans);
			m3 = new Matrix(row, col2, 0);

			m->times(m2, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";

			break;

		case 5: //умножение на скаляр
			scal;
			cout << "\nДля умножения матрицы на скаляр, введите число: ";
			cin >> scal;
			cout << "\n\n";
			m3 = new Matrix(row, col, 0);
			m->times_scal(scal, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";

			break;


		case 6: //деление на скаляр

			scal;
			cout << "\nДля деления матрицы на скаляр, введите число: ";
			cin >> scal;

			while (scal == 0) {
				cout << "\nДеление на ноль запрещено, введите новое число: ";
				cin >> scal;
			}

			m3 = new Matrix(row, col, 0);
			m->divide_scal(scal, m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";

			break;

		case 7: //возведение в степень

			if (row != col) {

				cout << "Возведение в степень доступно только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {

				int pow = -1;
				cout << "\nДля возведения матрицы в степень введите целое положительное число: ";
				cin >> pow;

				while (pow <= 0) {
					cout << "\nВведите целое положительное число: ";
					cin >> pow;
				}

				m3 = new Matrix(row, col, 0);

				m->pow(pow, m3);

				cout << "Результирующая матрица: \n";

				m3->printMatrix();

				cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
				cin >> ans;
				m->chooseMatrix(m3, ans);

				cout << "\nГотово!";
			}
			break;

		case 8: //сравнение с матрицей
			cout << "С какой матрицей вы хотите сравнить исходную матрицу?\n";
			cout << "Как вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;

			cout << "Ваш выбор: ";
			cin >> ans;
			cout << "\n";
			if (ans == 1 || ans == 2)
			{
				cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";

				cin >> row;
				cin >> col;
			}
			if (ans == 3) {
				row = file_row;
				col = file_col;

			}
			m2 = new Matrix(row, col, ans);
			cout << "\nМатрица 1: \n\n";
			m->printMatrix();
			cout << "\nМатрица 2: \n\n";
			m2->printMatrix();

			if (m->areEqual(m2)) {
				cout << "\n\nМатрицы равны\n\n";
			}
			else {
				cout << "\n\nМатрицы не равны\n\n";
			}
			break;

		case 9: //проверка типа матрицы
			
			cout << "\nТип матрицы:\n\n";
			if (m->checkType()[0]) cout << "Квадратная" << endl;
			if (m->checkType()[1]) cout << "Диагональная" << endl;
			if (m->checkType()[2]) cout << "Нулевая" << endl;
			if (m->checkType()[3]) cout << "Единичная" << endl;
			if (m->checkType()[4]) cout << "Симметрическая" << endl;
			if (m->checkType()[5]) cout << "Верхняя треугольная" << endl;
			if (m->checkType()[6]) cout << "Нижняя треугольная" << endl;
			if (m->checkType()[7]) cout << "Не принадлежит ни к одному из особых типов" << endl;

			break;

		case 10: //транспонированная матрица
			m3 = new Matrix(row, col, 0);
			m->transMatrix(m3);

			cout << "Результирующая матрица: \n";

			m3->printMatrix();

			cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
			cin >> ans;
			m->chooseMatrix(m3, ans);

			cout << "\nГотово!";

			break;

		case 11: //поиск определителя
			if (row != col) {

				cout << "Поиск определителя доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {
				double Det = m->findDet();
				cout << "\nДетерминант = " << Det << "\n";
			}

			break;

		case 12: //поиск обратной матрицы

			if (row != col) {

				cout << "Поиск обратной матрицы доступен только для квадратных матриц\nВыберите другое действие или создайте новую матрицу\n";
			}
			else {

				if (m->findDet() == 0)
				{
					cout << "Матрица вырожденная, определитель равен нулю.\nОбратной матрицы не существует\nВыберите другое действие или создайте новую матрицу\n";
				}
				else {
					m3 = new Matrix(row, col, 0);
					m->invertMatrix(m3);
					
					cout << "Результирующая матрица: \n";

					m3->printMatrix();

					cout << "\n\nС какой матрицей продолжаем работать?\n1 - исходная\n2 - результирующая\n" << endl;
					cin >> ans;
					m->chooseMatrix(m3, ans);

					cout << "\nГотово!";
				}

			}

			break;

		case 13: //Сохранение матрицы в файл

			m->save();
			cout << "Матрица успешно сохранена в файле \'output.txt\'" << endl;

			break; //выход из программы
		case 0:
			exit(1);
			break;
		}
		
	}

	return 0;
        
}

