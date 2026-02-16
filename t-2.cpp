#include <iostream>
#include <iomanip>
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


int main() {
    const double e = 3e-8;
    const double e2 = e / 2.0;

    cout << fixed << setprecision(2);

    double sq = 2.0 / e2;
    double n = sq * sq;

    long long n1 = ceil(n);
    long long n2 = 2LL * n1;

    cout << "n на 1 ряд ≥ " << n1 << "\n";
    cout << "всего членов: " << n2 << "\n";

    const double t_m = 500.0;
    const double t_s  = t_m * 1e-6;

    double t1 = n1 * t_s;
    double t2 = n2 * t_s;

    const double t_y = 365 * 24 * 3600.0;

    double y1 = t1 / t_y;
    double y2 = t2 / t_y;

    cout << "время на одно слагаемое: " << t_m << " мкс"<<endl;

    cout << "время на один ряд: " << t1 << " c или "<< (long long)y1 << " лет"<<endl;

    cout << "время на оба ряда: "<< t2 << " c или " << (long long)y2 << " лет"<<endl;

    double xs[] = {0.5, 0.999999999};

    cout << fixed << setprecision(8);

    for (double x : xs)
    {
        int n = 0;
        double result = func(x, n);

        cout << x << " " << result << " " << n << endl;
    }

    return 0;
}
