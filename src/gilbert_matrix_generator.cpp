#include <iostream>
#include <vector>

using namespace std;

int n = 0;

void print_matrix(const vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void generate_gilbert_matrix(vector<vector<double>> &A)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = 1/(((double)i + 1) + ((double)j + 1) - 1);
}

int main()
{
	cout << "Enter the size of a matrix: ";
	cin >> n;
	cout << endl;

	vector<vector<double>> A(n, vector<double>(n));

	generate_gilbert_matrix(A);
	print_matrix(A);
	return 0;
}
