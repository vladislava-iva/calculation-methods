#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double erf_res(double x, int &k)
{
    const double PI = 3.14159265358979323;

    double sum = 0.0;
    double a_n = x;  
    int n = 0;

    while (true)
    {
        double new_sum = sum + a_n;

        if (new_sum == sum)
            break;

        sum = new_sum;

        a_n = -a_n * x * x * (2 * n + 1) / ((n + 1) * (2 * n + 3));

        n++;
    }

    k = n;
    return 2.0 * sum / sqrt(PI);
}

int main()
{
    double xs[] = {0.5, 1.0, 5.0, 10.0};
    cout << fixed << setprecision(15);

    for (double x : xs)
    {
        int terms = 0;
        double result =erf_res(x, terms);
        double e = erf(x);

        std::cout << x << " " << result << " "<< e << " "<< result - e << " "<< terms << endl;
    }

    return 0;
}
