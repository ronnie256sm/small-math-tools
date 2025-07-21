#include <iostream>
#include <vector>

using namespace std;

int rows = 0;
int collumns = 0;

void print_matrix(const vector<vector<double>> &A)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collumns; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void generate_gilbert_matrix(vector<vector<double>> &A)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < collumns; j++)
			A[i][j] = 1/(((double)i + 1) + ((double)j + 1) - 1);
}

int main()
{
	cout << "Enter the amount of rows in a matrix: ";
	cin >> rows;
	cout << "Enter the amount of collumns in a matrix: ";
	cin >> collumns;
	cout << endl;

	vector<vector<double>> A(rows, vector<double>(collumns));

	generate_gilbert_matrix(A);
	print_matrix(A);
	return 0;
}
