#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

class Matrix {
private:
	int a11;
	int a12;
	int a21;
	int a22;
public:
	Matrix() : a11(0), a12(0), a21(0), a22(0) {};
	Matrix(int a, int b, int c, int d) : a11(a), a12(b), a21(c), a22(d)
	{ };
	void get_elem()
	{
		cout << a11 << "	" << a12 << endl << a21 << "	" << a22 << endl;
	}
	int get_det()
	{
		return (a11 * a22 - a12 * a21);
	}
	Matrix operator+(Matrix b)
	{
		Matrix temp;
		temp.a11 = a11 + b.a11;
		temp.a12 = a12 + b.a12;
		temp.a21 = a21 + b.a21;
		temp.a22 = a22 + b.a22;
		return temp;
	}
	Matrix operator*(Matrix b)
	{
		Matrix temp;
		temp.a11 = a11 * b.a11 + a12 * b.a21;
		temp.a12 = a11 * b.a12 + a12 * b.a22;
		temp.a21 = a21 * b.a11 + a22 * b.a21;
		temp.a22 = a21 * b.a12 + a22 * b.a22;
		return temp;
	}
};

//найти определитель
//перемножить матрицы
class aMatrix {
private:
	string err_type = "матрицы не могут быть сложены";
	string err_type1 = "матрицы не могут быть перемножены";
	static const int SIZE_L = 3;
	static const int SIZE_C = 3;
	int arr[SIZE_L][SIZE_C];
public:
	aMatrix() {
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			arr[c1][c] = 0;
		};
	}
	void get_elem()const
	{
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; cout << endl; };
			cout << arr[c1][c] << "    ";
		};
	}
	int get_det()const
	{
		int temp;
		(SIZE_C == SIZE_L) ? (temp = 1) : (temp = 0);
		if (temp == 0) {
			return 0;
		}
		else {

		}
	}
	void set_elem()
	{
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			int temp;
			cin >> temp;
			arr[c1][c] = temp;
		};
	}
	void set_random_elem()
	{
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			int temp;
			temp = rand() % 10;
			arr[c1][c] = temp;
		};
	}
	aMatrix operator+ (aMatrix buf)
	{
		aMatrix temp;
		if (SIZE_C == buf.SIZE_C && SIZE_L == buf.SIZE_L)
		{
			for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
				if (c >= SIZE_L) { c = 0; c1++; };
				temp.arr[c1][c] = arr[c1][c] + buf.arr[c1][c];
			};
			return temp;
		}
		else {
			cout << temp.err_type;
			return temp;
		}
	}
	aMatrix operator* (int alp)
	{
		aMatrix temp;
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			temp.arr[c1][c] = arr[c1][c] * alp;
		};
		return temp;
	}
	aMatrix operator* (aMatrix buf)
	{
		aMatrix temp;
		if (SIZE_C == buf.SIZE_L)
		{
			static int sum;
			int new_size_l = SIZE_L, new_size_c = buf.SIZE_C;
			for (int i = 0; i < SIZE_L; i++)
			{
				for (int j = 0; j < buf.SIZE_L; j++)
				{
					temp.arr[i][j] = 0;
					for (int k = 0; k < buf.SIZE_C; k++)
					{
						temp.arr[i][j] += arr[i][k] * buf.arr[k][j];
					}
				}
			}
			return temp;
		}
		else {
			cout << temp.err_type1;
			return temp;
		}
	}
};

int main() {
	srand(time(NULL));
	Matrix A(12, 4, 8, 2), B(2, 3, 5, 2);
	aMatrix C, D, G, T;
	C.set_random_elem();
	C.get_elem();
	cout << endl << endl;
	D.set_random_elem();
	D.get_elem();
	cout << endl << "\n";
	T = C * D;
	T.get_elem();
	cout << endl << endl;
	G = C + D;
	G.get_elem();
	cout << endl << endl;
	G = G * 2;
	G.get_elem();
	return 0;
}