#include <iostream>
#include <vector>

using namespace std;

int n = 0;

void print_matrix(vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void create_L_matrix(vector<vector<double>> &L)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			L[i][j] = rand() % 10;
}

vector<vector<double>> transpose_matrix(const vector<vector<double>> L)
{
	vector<vector<double>> Lt(n, vector<double>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Lt[i][j] = L[j][i];
	return Lt;
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

int main()
{
	cout << "Enter the size of a matrix: ";
	cin >> n;
	
	vector<vector<double>> L(n, vector<double>(n)), Lt(n, vector<double>(n)), A(n, vector<double>(n));
	create_L_matrix(L);
	Lt = transpose_matrix(L);
	A = multiply_matrices(L, Lt);

	cout << endl << "L = " << endl;
	print_matrix(L);

	cout << endl << "A = " << endl;
	print_matrix(A);

	return 0;
}
