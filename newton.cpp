//newton raphson
#include <bits/stdc++.h>
using namespace std;

double e = 0.0001;

vector<double> coef = {1, 3, -2, -12, -8}, temp;

double f(double x)
{
    double y = coef[0];
    for (int i = 1; i < coef.size(); i++)
    {

        y = y * x + coef[i];
    }
    return y;
}

double f_prime(double x)
{
    double y = 0;
    int n = coef.size();
    for (int i = 0; i < n - 1; i++)
    {
        y += pow(x, n - 2 - i) * coef[i] * (n - 1 - i);
    }
    return y;
}

double newton(double initialGuess)
{
    double x0 = initialGuess;
    double x1, f1;

    int i = 1;

    do
    {
        x1 = x0 - f(x0) / f_prime(x0);
        if (abs(x1 - x0) < e)
            break;
        x0 = x1;
        f1 = f(x1);

        i++;
    } while (true);

    return x1;
}

void syntheticDiv(double x)
{
    int n = coef.size();
    double y = coef[0];
    for (int i = 1; i < coef.size(); i++)
    {
        if (n > 1)
            temp.push_back(y);

        y = y * x + coef[i];
        n--;
    }

    coef = temp;
    while (!temp.empty())
    {
        temp.pop_back();
    }
}

int main()
{
    int n = coef.size();
    n--;

    while (n--)
    {
        double root = newton(1);
        syntheticDiv(root);
        cout << root << endl;
    }

    return 0;
}