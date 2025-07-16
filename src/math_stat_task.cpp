#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double find_e(const int n, const vector<double> x, const vector<double> p)
{
	double result = 0;
	for (int i = 0; i < n; i++)
		result += x[i] * p[i];

	return result;
}

double find_d(const int n, const double e, const vector<double> x, const vector<double> p)
{
	double result = 0;
	for (int i = 0; i < n; i++)
		result += pow(x[i], 2) * p[i];
	result -= pow(e, 2);

	return result;
}

double find_sigma(const double d)
{
	return sqrt(d);
}

int main()
{
	int n = 0;
	cout << "Enter the amount of values: ";
	cin >> n;

	vector<double> x(n), p(n);

	cout << "Enter x values:" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	cout << "Enter P(x) values:" << endl;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	cout << endl;

	double e = find_e(n, x, p);
	double d = find_d(n, e, x, p);
	double sigma = find_sigma(d);

	cout << "E(x) = " << e << endl;
	cout << "D(x) = " << d << endl;
	cout << "sigma(x) = " << sigma << endl;
	
	return 0;
}
