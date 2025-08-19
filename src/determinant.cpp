#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0;

double determinant(vector<vector<double>> &A)
{
	double det = 0;

	if (n == 1)
		return A[0][0];
	if (n == 2)
		return A[0][0] * A[1][1] - A[0][1] * A[1][0];

	for (int j = 0; j < n; j++)
	{
		vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
		
		for (int i = 1; i < n; i++)
		{
			int sub_j = 0;
			for (int k = 0; k < n; k++)
			{
				if (k == j)
					continue;
				submatrix[i - 1][sub_j] = A[i][k];
				sub_j++;
			}
		}

		int temp_n = n;
		n -= 1;
		double sub_det = determinant(submatrix);
		n = temp_n;

		det += A[0][j] * pow(-1, j) * sub_det;
	}

	return det;
}

int main()
{
	cout << "Enter the size of a matrix: ";
	cin >> n;

	if (n <= 0)
	{
		cout << "Error. Incorrect matrix size." << endl;
		return 1;
	}

	vector<vector<double>> A(n, vector<double>(n));
	cout << "Enter matrix: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	
	double result = determinant(A);
	cout << "det(A) = " << result << endl;

	return 0;
}
