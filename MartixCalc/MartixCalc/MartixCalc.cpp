#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;

//find determinant - next
//triangular view - next
//transpos - kk (0.3)
//interface - kk (0.4)
//matrix multiplication - kk (0.1)
//left side *num - kk in meaning of use "=*" (0.3)
//overload "*=" - kk (0.3)
//overload "-" - kk (0.3)
//cin space change
//functions preload - kk (0.3)
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
			if (c >= SIZE_L) { c = 0; c1++; cout << endl; };
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
	aMatrix transpos() 
	{
		unsigned int n = SIZE_C;
		unsigned int m = SIZE_L;
		aMatrix temp(n, m);
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			temp.arr[c][c1] = arr[c1][c];
		};
		return temp;
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
	aMatrix operator- (aMatrix buf)
	{
		aMatrix temp(SIZE_L, SIZE_C);
		if (SIZE_C == buf.SIZE_C && SIZE_L == buf.SIZE_L)
		{
			for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
				if (c >= SIZE_L) { c = 0; c1++; };
				temp.arr[c1][c] = arr[c1][c] - buf.arr[c1][c];
			};
			return temp;
		}
		else {
			cout << temp.err_type;
			return temp; //empty matrix
		}
	}
	aMatrix operator*= (int alp) //fix only left side num
	{
		aMatrix temp(SIZE_L, SIZE_C);
		for (int d = 0, c = 0, c1 = 0; d < SIZE_C * SIZE_L; c++, d++) {
			if (c >= SIZE_L) { c = 0; c1++; };
			temp.arr[c1][c] = arr[c1][c] * alp;
		};
		return temp;
	}
	aMatrix operator* (int alp)
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

void functions();

int main() {
	srand(time(NULL));
	functions();
	//test
	//test
	/*
	...interface...
	*/
	char k = getchar();
	while (k != '`') {
		if (k == '`') {
			exit;
		};
		if (k != '`')
		{
			int n, m, n1, m1;
			cout << "Write n matrix A:" << endl;
			cin >> n;
			cout << "Write m matrix A:" << endl;
			cin >> m;
			cout << "Write n matrix B:" << endl;
			cin >> n1;
			cout << "Write m matrix B:" << endl;
			cin >> m1;
			aMatrix A(n, m), B(n1, m1);
			cout << "Wrirte the elements of A: " << endl << endl;
			A.set_elem();
			cout << "Wrirte the elements of B: " << endl << endl;
			B.set_elem();
			cout << "Write operation: (*, *=, +, -, T)";
			char l;
			cin >> l;
			if (l == '*') {
				cout << "Press 1 if A*B or 2 if B*A" << endl;
				cin >> l;
				if (l == '1') {
					aMatrix C(m, n1);
					C = A * B;
					C.get_elem();
					break;
				}
				else if (l == '2') {
					aMatrix C(m, n1);
					C = B * A;
					C.get_elem();
					break;
				}
			}
			if (l == '*=') {
				cout << "Write the number:" << endl;
				int alpha;
				cin >> alpha;
				cout << "Write A or B:" << endl;
				cin >> l;
				if (l == 'A') {
					aMatrix C(n, m);
					C *= alpha;
					C.get_elem();
					break;
				}
				else if (l == 'B') {
					aMatrix C(n1, m1);
					C *= alpha;
					C.get_elem();
					break;
				}
			}
			if (l == '+') {
				cout << "Write the number: " << endl;
				aMatrix C(n, m);
				C = A + B;
				C.get_elem();
				break;
			}
			if (l == '-') {
				cout << "Write the number: " << endl;
				aMatrix C(n, m);
				C = A - B;
				C.get_elem();
				break;
			}
			if (l == 'T') {
				cout << "Write A or B:" << endl;
				cin >> l;
				if (l == 'A' or l == 'a') {
					A.transpos();
					A.get_elem();
					break;
				}
				else if (l == 'B' or l =='b') {
					B.transpos();
					B.get_elem();
					break;
				}
			}
			exit;
		}
	}
	return 0;
}

void functions() {
	cout << "*= for multiplicate on num" << endl;
	cout << "* for multiplicate on matrix" << endl;
	cout << "+ or - for plus/minus with matrix" << endl;
	cout << "press ` to exit" << endl;
}