#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0;

double f(double x)
{
	return (-2 - 7 * x + 4 * pow(x, 2));
}

vector<double> initialize_grid(const double a, const double b)
{
	double step = (b - a) / n;

	vector<double> grid(n + 1);
	grid[0] = a;
	for (int i = 1; i <= n; i++)
		grid[i] = grid[i - 1] + step;

	return grid;
}

double simpson_method(const double a, const double b)
{
	vector<double> grid = initialize_grid(a, b);
	double result = 0;
	for (int i = 0; i < n; i++)
		result += ((grid[i + 1] - grid[i]) / 6) * (f(grid[i]) + 4 * f((grid[i] + grid[i + 1]) / 2) + f(grid[i + 1]));

	return result;
}

double trapezioid_method(const double a, const double b)
{
	vector<double> grid = initialize_grid(a, b);
	double result = 0;
	for (int i = 0; i < n; i++)
		result += (grid[i + 1] - grid[i]) * (f(grid[i]) + f(grid[i + 1])) / 2;
	
	return result;
}

int main()
{
	cout << "Enter the amount of intervals: ";
	cin >> n;

	double a, b = 0;
	cout << "Enter the lower boundary of integration: ";
	cin >> a;
	cout << "Enter the upper boundary of integration: ";
	cin >> b;

	cout << endl;

	double result_simpson = simpson_method(a, b);
	double result_trapezioid = trapezioid_method(a, b);

	cout << "Simpson method = " << result_simpson << endl;
	cout << "Trapezioid method = " << result_trapezioid << endl;

	return 0;
}
