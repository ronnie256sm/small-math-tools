#include <iostream>
#include <vector>

using namespace std;

int n = 0;
double value = 0;

double find_value(const vector<double> x, const vector<double> f)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		double composition = 1;
		for (int j = 0; j < n; j++)
			if (j != i)
				composition *= (value - x[j]) / (x[i] - x[j]);
		result += f[i] * composition;
	}
	return result;
}

int main()
{
	cout << "Enter an amount of points: ";
	cin >> n;
	if (n < 2)
	{
		cerr << "Incorrect size." << endl;
		exit(1);
	}

	vector<double> x(n), f(n);

	cout << "Enter x values, there must be " << n << " of them:" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	cout << "Enter f(x) values, there must be " << n << " of them:" << endl;
	for (int i = 0; i < n; i++)
		cin >> f[i];

	cout << "Enter a point to find the value of the polynomial in: ";
	cin >> value;

	double result = find_value(x, f);
	cout << "Result = " << result << endl;
	
	return 0;
}
