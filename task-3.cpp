#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double eps = 1e-10;

    long long n1 = ceil(1.0 / eps);

    cout << "прямой ряд: "<<endl;
    cout << "n равно " << n1 << endl;

    double pi = M_PI;
    double s = pi*pi/6.0 - pi*pi*pi*pi/90.0;

    int n = 1, k = 0;
    double t;

    while (true) {
        double a = n*n;
        t = 1.0 / (a*a * (a + 1.0));
        s += t;
        k++;
        if (t < eps) break;
        n++;
    }

    cout << "преобразованный ряд:"<<endl;
    cout << "s равно " << setprecision(15) << s << endl;
    cout << "число членов: " << k << endl;

    double e2 = exp(2.0 * pi);
    double coth = (e2 + 1.0) / (e2 - 1.0);
    double exact = (pi * coth - 1.0) / 2.0;

    cout << "точная сумма: " << setprecision(15) << exact << endl;
    cout << "разница: " << fabs(s - exact) << endl;

    cout << "ускорение в " << n1 / k << " раз"<<endl;

    return 0;
}
