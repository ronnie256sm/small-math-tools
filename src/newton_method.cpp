#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(const vector<double> coeffs, const double x, const double y)
{
	return (coeffs[0] * pow(x, 2) + coeffs[1] * pow(y, 2) + coeffs[2] * x * y + coeffs[3] * x + coeffs[4] * y + coeffs[5]);
}

double dx(const vector<double> coeffs, const double x, const double y)
{
	return (2 * coeffs[0] * x + coeffs[2] * y + coeffs[3]);
}

double dy(const vector<double> coeffs, const double x, const double y)
{
	return (2 * coeffs[1] * y + coeffs[2] * x + coeffs[4]);
}

vector<vector<double>> build_jacobian(const vector<double> f1, const vector<double> f2, const double x, const double y)
{
	vector<vector<double>> jacobian(2, vector<double>(2));
	jacobian[0][0] = dx(f1, x, y);
	jacobian[0][1] = dy(f1, x, y);
	jacobian[1][0] = dx(f2, x, y);
	jacobian[1][1] = dy(f2, x, y);

	return jacobian;
}

bool possible(const vector<vector<double>> J)
{
	double det = (J[0][0] * J[1][1]) - (J[0][1] * J[1][0]);
	if (det == 0)
		return false;
	else
		return true;
}

vector<double> build_function_vector(const vector<double> f1, const vector<double> f2, const double x, const double y)
{
	vector<double> function_vector(2);
	function_vector[0] = f(f1, x, y);
	function_vector[1] = f(f2, x, y);
	return function_vector;
}

vector<double> slae(const vector<vector<double>> J, const vector<double> F)
{
	vector<double> solution(2);
	double det = (J[0][0] * J[1][1]) - (J[1][0] * J[0][1]);
	double d1 = (F[0] * J[1][1]) - (F[1] * J[0][1]);
	double d2 = (J[0][0] * F[1]) - (J[1][0] * F[0]);

	solution[0] = d1 / det;
	solution[1] = d2 / det;

	return solution;
}

vector<double> newton_method(const vector<double> f1, const vector<double> f2, const int iter, double x, double y)
{
	vector<double> solution(2);
	solution[0] = x;
	solution[1] = y;

	for (int i = 0; i < iter; i++)
	{
		vector<double> F = build_function_vector(f1, f2, x, y);
		for (int i = 0; i < 2; i++)
			F[i] *= (-1);

		vector<vector<double>> J = build_jacobian(f1, f2, x, y);
		if (!possible(J))
		{
			cout << endl << "Jacobian is degenerate, stopping." << endl;
			break;
		}
		vector<double> deltas = slae(J, F);
		solution[0] += deltas[0];
		solution[1] += deltas[1];
	}

	return solution;
}

int main()
{
	vector<double> f1(6), f2(6);
	cout << "Equations must look like this: A*(x^2)+B*(y^2)+C*xy+D*x+E*y+F=0." << endl;
	cout << "Enter coefficients for the first equation:" << endl;
	for (int i = 0; i < 6; i++)
		cin >> f1[i];
	
	cout << "Enter coefficients for the second equation:" << endl;
	for (int i = 0; i < 6; i++)
		cin >> f2[i];

	double x0, y0 = 0;
	cout << "Enter the initial approximation (x, y):" << endl;
	cin >> x0 >> y0;

	int iter = 0;
	cout << "Enter the amount of iterations: ";
	cin >> iter;

	cout << endl;

	vector<double> solution = newton_method(f1, f2, iter, x0, y0);
	cout << "Result: x = " << solution[0] << ", y = " << solution[1] << endl;

	return 0;
}
