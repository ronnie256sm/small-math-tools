#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n = 0;

void print_matrix(const vector<vector<double>> &A)
{
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << A[i][j] << " ";

      cout << endl;
   }
}

void print_vector(const vector<double> &rhs)
{
   cout << endl;
   for (int i = 0; i < n; i++)
      cout << rhs[i] << " ";

   cout << endl;
}

void enter_matrix(vector<vector<double>> &A)
{
   cout << "Enter matrix. You should enter " << n << " lines. Each line must have " << n << " elements." << endl;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> A[i][j];
}

void enter_vector(vector<double> &rhs)
{
   cout << "Enter right hand side vector. It must have " << n << " elements." << endl;
   for (int i = 0; i < n; i++)
      cin >> rhs[i];
}

vector<vector<double>> cholesky_decompose(const vector<vector<double>> A)
{
   vector<vector<double>> L(n, vector<double>(n));

   if (A[0][0] >= 0)
      L[0][0] = sqrt(A[0][0]);
   else
   {
      cerr << endl << "The matrix is not positively determined." << endl;
      exit(1);
   }

   for (int j = 1; j < n; j++)
      L[j][0] = A[j][0] / L[0][0];

   for (int i = 1; i < n; i++)
   {
      double sum = 0;
      for (int p = 0; p < i; p++)
         sum += pow(L[i][p], 2);

      if (A[i][i] - sum >= 0)
         L[i][i] = sqrt(A[i][i] - sum);
      else
      {
         cerr << endl << "The matrix is not positively determined." << endl;
         exit(1);
      }

      for (int j = i + 1; j < n; j++)
      {
         sum = 0;
         for (int p = 0; p < i; p++)
            sum += L[i][p] * L[j][p];

         L[j][i] = (1 / L[i][i]) * (A[j][i] - sum);
      }
   }

   return L;
}

vector<vector<double>> transpose(const vector<vector<double>> A)
{
   vector<vector<double>> At(n, vector<double>(n));

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         At[j][i] = A[i][j];

   return At;
}

vector<double> solve_ly(const vector<vector<double>> L, const vector<double> rhs)
{
   vector<double> y(n);

   for (int i = 0; i < n; i++)
   {
      double sum = 0.0;
      for (int j = 0; j < i; j++)
         sum += L[i][j] * y[j];

      y[i] = (rhs[i] - sum) / L[i][i];
   }
   return y;
}

vector<double> solve_ltx(const vector<vector<double>> Lt, const vector<double> y)
{
   vector<double> x(n);

   for (int i = n - 1; i >= 0; i--)
   {
      double sum = 0.0;
      for (int j = i + 1; j < n; j++)
         sum += Lt[i][j] * x[j];

      x[i] = (y[i] - sum) / Lt[i][i];
   }
   return x;
}

vector<double> solve_slae(const vector<vector<double>> L, const vector<double> rhs)
{
   vector<double> y = solve_ly(L, rhs);
   vector<double> x = solve_ltx(transpose(L), y);

   return x;
}

bool is_symmetrical(const vector<vector<double>> A)
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (A[i][j] != A[j][i])
            return false;

   return true;
}

int main()
{
   cout << "Enter matrix size: ";
   cin >> n;

   if (n < 1)
   {
       cerr << "Incorrect size." << endl;
       exit(1);
   }

   vector<vector<double>> A(n, vector<double>(n));
   vector<double> rhs(n);
   enter_matrix(A);
   enter_vector(rhs);

   cout << endl << "You entered: A = ";
   print_matrix(A);
   cout << "rhs = ";
   print_vector(rhs);

   if (!is_symmetrical(A))
   {
      cerr << endl << "The matrix is not symmetrical." << endl;
      exit(1);
   }

   cout << endl << "L = ";
   vector<vector<double>> L = cholesky_decompose(A);
   print_matrix(L);
   
   vector<double> slae_solution = solve_slae(L, rhs);
   cout << endl << "SLAE solution = ";
   print_vector(slae_solution);

   return 0;
}
