#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

//find determinant - next
//matrix multiplication - kk
//left side *num
//overload *=
//overload -
//cin space change
//functions preload
class aMatrix {
private: 
	string err_type = "Matrices can't be stacked";
	string err_type1 = "Matrices can't be multiplicate";
	int SIZE_L;
	int SIZE_C;
	int** arr;
public:
	aMatrix(unsigned int n, unsigned int m) {
		SIZE_L = n;
		SIZE_C = m;
		arr = new int* [n];
		for (int i = 0; i < m; i++)
		{
			arr[i] = new int[m];
		}
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
		const double EPS = 1E-9;
		(SIZE_C == SIZE_L) ? (temp = 1) : (temp = 0);
		if (temp == 0) {
			return 0;
		}
		else {
			return 0; //find det next
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
		aMatrix temp(SIZE_L, SIZE_C);
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
			return temp; //empty matrix
		}
	}
	aMatrix operator* (int alp) //fix only left side num
	{
		aMatrix temp(SIZE_L, SIZE_C);
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			temp.arr[c1][c] = arr[c1][c] * alp;
		};
		return temp;
	}
	aMatrix operator* (aMatrix buf)
	{
		aMatrix temp(SIZE_L, SIZE_C);
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
			return temp; //empty matrix
		}
	}
};

int main() {
	srand(time(NULL));
	aMatrix C(2, 2), D(2, 2), G(2, 2), T(2, 2);
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