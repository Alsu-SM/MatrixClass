#include <iostream>
#include<locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

int menu();
int menu2();
void printMatrix(int, int, double**);
double** create(int, int);
double** generate(int, int);
double** load(int r, int c);



class Matrix
{


public:
	int col;
	int row;
	double** matrix_array;

    Matrix() {
        cout << "\nВведите количество строк и столбцов вашей новой матрицы: ";
        
        cin >> row;
		cin >> col;
        cout << "\n\nКак вы хотите заполнить матрицу: \n1 - вручную\n2 - сгенерировать автоматически\n3 - загрузить из файла\n" << endl;
        int ans;
		cout << "Ваш выбор: ";
		cin >> ans;
		cout << "\n";
		switch (ans) {
		case 1:
			matrix_array = create(row, col);
			break;
		case 2:
			matrix_array = generate(row, col);
			break;
		case 3:
			matrix_array = load(row, col);
			break;
		}
		printMatrix(row, col, matrix_array);
				
    }

	Matrix(int r, int c) {
		row = r;
		col = c;
		double** matrix;

		// создание
		matrix = new double* [r];    // массив указателей
		for (int i = 0; i < r; i++) {   //
			matrix[i] = new double[c];     // инициализация указателей

		}

		matrix_array = matrix;
	}
	
	void plus() {
		cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" <<endl;
		Matrix* m2 = new Matrix();
		
		Matrix* m3 = new Matrix(row, col);
		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				m3->matrix_array[i][j] = this->matrix_array[i][j] + m2->matrix_array[i][j];  //заполняем текущую ячейку

			}
		}

		printMatrix(row, col, m3->matrix_array);

	}

	void minus() {
		cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк и столбцов матриц должны совпадать.\n" << endl;
		Matrix* m2 = new Matrix();

		Matrix* m3 = new Matrix(row, col);
		for (int i = 0; i < row; i++)   //строки массива
		{
			for (int j = 0; j < col; j++)   //столбцы массива
			{
				m3->matrix_array[i][j] = this->matrix_array[i][j] - m2->matrix_array[i][j];  //заполняем текущую ячейку

			}
		}

		printMatrix(row, col, m3->matrix_array);

	}

	void times() {
		cout << "Необходимо создать новый объект для действий с другой матрицей.\nУчтите, что количество строк новой матрицы должно совпадать с количеством столбцов исходной.\n" << endl;
		Matrix* m2 = new Matrix();
		Matrix* m3 = new Matrix(m2->row, this->col);
		cout << "\n";
		for (int i = 0; i < this->row; i++)
		{
	
			cout << "\n";
			for (int j = 0; j < m2->col; j++)
			{
				
				m3->matrix_array[i][j] = 0;
				for (int k = 0; k < this->col; k++)
				{
					m3->matrix_array[i][j] += this->matrix_array[i][k] * m2->matrix_array[k][j];
					
				}
				cout << m3->matrix_array[i][j] << " ";
			}
		}

		printMatrix(m3->row, m3->col, m3->matrix_array);
	}

	
};

Matrix* m;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Привет мир!\n";
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
		cout << 1 + rand() % 10 << " ";
	cout << "\n";

	for (;;)
	{
		int v;
		v = menu();
		if (v == 1)
		
			m = new Matrix();
		
					
		if (v == 2)
			m->plus();

		if (v == 3)
			m->minus();

		if (v == 4)
			m->times();
			
	}
	return 0;
        
}


int menu()
{
	int v = 0;
	cout << "\n\nЧто вы хотите сделать?\n"<< endl;
	cout << "\n1 - Добавить новую матрицу\n2 - Операции с матрицами\n3 - Загрузить матрицу из файла\n4 - Сохранить матрицу в файл \n5 - Выход" << endl;

	for (;;)
	{
		cout << "\nВаш выбор: ";
		cin >> v;
		cout << "\n";

		if (v <= 0 || v > 5) {
			cout << "Пожалуйста, введите числа от 1 до 5.\n\n" << endl;
			continue;
		}

		return v;
	}
}

int menu2()
{
	

	for (;;)
	{
		int v2 = 0;
		cout << "\n\nОперации над матрицами\n" << endl;
		cout << "\n1 - сложение с другой матрцией\n2 - умножение на другую матрицу\n3 - умножение на скаляр\n4 - деление на скаляр\n5 - выход" << endl;
		cout << "\nВаш выбор: ";
		cin >> v2;
		cout << "\n";

		if (v2 <= 0 || v2 > 5) {
			cout << "Пожалуйста, введите числа от 1 до 5.\n\n" << endl;
			continue;
		}
		
		return v2;
	}
}

double** create(int r, int c)

{
	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}

	for (int i = 0; i < r; i++) {
		cout << "Вводим " << i + 1 << " строку: ";
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	
	
	return matrix;

}

double** generate(int r, int c) {

	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}
	
	for (int i = 0; i < r; i++)   //строки массива
	{
		for (int j = 0; j < c; j++)   //столбцы массива
		{
			matrix[i][j] = 1 + rand() % 9;  //заполняем текущую ячейку
			
		}
	}

	return matrix;


}

double** load(int r, int c) {
	cout << "\nЗагружаю матрицу из файла..." << endl;

	double** matrix;

	// создание
	matrix = new double* [r];    // массив указателей
	for (int i = 0; i < r; i++) {   //
		matrix[i] = new double[c];     // инициализация указателей

	}

	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");

	if (in.is_open())
	{
		//Если открытие файла прошло успешно
		//Считаем матрицу из файла
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				in >> matrix[i][j];
	}

	
	return matrix;

}


void printMatrix(int r, int c, double** matrix) {
	
	
	for (int i = 0; i < r; i++) {
		{
			cout << "\n";
			for (int j = 0; j < c; j++) {
				cout << matrix[i][j]<< " ";
			}
		}
	}
}

