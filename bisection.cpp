#include <bits/stdc++.h>
using namespace std;
double e = 0.0001;

vector<double> coef = {1, 3, -2, -12, -8};


double f(double x)
{
    double y = coef[0];
    for (int i = 1; i < coef.size(); i++)
    {

        y = y * x + coef[i];
    }
    return y;
}

void bisection(double a, double b)
{
    double c1, c2;
    if (f(a) * f(b) > 0)
        return;
    else
    {
        while (1)
        {
            c2 = (a + b) / 2;
            if (f(a) * f(c2) < 0)
                b = c2;
            else
                a = c2;
            
            if (abs(c2 - c1) <= e)
                break;
            c1 = c2;
        }
        cout << "final root = " << c2 << endl;
    }
}

int main()
{
    double a, b, lo, hi, ds = 0.1, c1 = 0, c2;
    cin >> lo >> hi;
    a = lo;
    while (1)
    {

        b = a + ds;
        if (b > hi)
        {
            b = hi;
            bisection(a, b);
            break;
        }

        bisection(a, b);
        a = b;
    }

    return 0;
}




