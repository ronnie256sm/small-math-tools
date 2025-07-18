#include <iostream>
#include <vector>

using namespace std;

int n = 0;

void enter_matrix(vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
}

void print_matrix(vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void initialize(vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = 0;
}

void lu_decomposition(const vector<vector<double>> A, vector<vector<double>> &L, vector<vector<double>> &U)
{
	initialize(L);
	initialize(U);
	for (int i = 0; i < n; i++)
	{
		L[i][i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (i <= j)
			{
				double sum = 0;
				for (int k = 0; k < i; k++)
					sum += L[i][k] * U[k][j];
				U[i][j] = A[i][j] - sum;
			}
			if (i > j)
			{
				double sum = 0;
				for (int k = 0; k < j; k++)
					sum += L[i][k] * U[k][j];
				L[i][j] = (A[i][j] - sum) / U[j][j];
			}
		}
	}	
}

int main()
{
	cout << "Enter the size of a matrix: ";
	cin >> n;

	vector<vector<double>> A(n, vector<double>(n)), L(n, vector<double>(n)), U(n, vector<double>(n));
	cout << "Enter A. You should enter " << n << " lines each containing " << n << " elements." << endl;
	enter_matrix(A);
	lu_decomposition(A, L, U);
	cout << endl << "L =" << endl;
	print_matrix(L);
	cout << endl << "U =" << endl;
	print_matrix(U);
	
	return 0;
}
