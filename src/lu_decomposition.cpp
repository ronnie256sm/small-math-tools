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

vector<vector<double>> multiply_matrices(const vector<vector<double>> A, const vector<vector<double>> B)
{
        vector<vector<double>> result(n, vector<double>(n));

        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        for (int k = 0; k < n; k++)
                                result[i][j] += A[i][k] * B[k][j];

        return result;
}

bool correct(const vector<vector<double>> A, const vector<vector<double>> L, const vector<vector<double>> U)
{
	vector<vector<double>> LU = multiply_matrices(L, U);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] != LU[i][j])
				return false;
	return true;
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
	if (correct(A, L, U))
		cout << endl << "Decomposition is correct." << endl;
	else
		cout << endl << "Decomposition is incorrect." << endl;
	
	return 0;
}
