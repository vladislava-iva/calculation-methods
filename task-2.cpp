#include <iostream>
#include <cmath>

using namespace std;

double func(double x, int &k)
{
    const double eps = 3e-8;

    double summa = 0.0;
    k = 0;

    for (int i = 1; ; i++)
    {
        double k3 = (double)i * i * i;
        if (k3 <= x) continue;

        double sqrt1 = sqrt(k3 + x);
        double sqrt2 = sqrt(k3 - x);

        double a_n =
            (-2.0 * x) /
            (sqrt1 * sqrt2 * (sqrt1 + sqrt2));

        summa += a_n;
        k++;

        if (fabs(a_n) < eps)
            break;
    }

    return summa;
}


int main()
{
    double xs[] = {0.5, 0.999999999};

    for (double x : xs)
    {
        int n = 0;
        double result = func(x, n);

        cout << x << " " << result << " " << n << endl;
    }

    return 0;
}
