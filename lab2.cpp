#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long double a, b, c;
    cin >> a >> b >> c;

    long double eps = 1e-18;

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                cout << "бесконечное число решений";
            else
                cout << "нет решений";
        } else {
            cout << "x = " << -c / b;
        }
        return 0;
    }

    long double D = b*b - 4*a*c;

    if (D < 0) {
        long double real = -b / (2*a);
        long double imag = sqrt(-D) / (2*a);

        cout << "x1 = " << real << " + " << imag << "i\n";
        cout << "x2 = " << real << " - " << imag << "i\n";
        return 0;
    }

    long double s = sqrt(D);
    long double x1, x2;

    if (b >= 0)
        x1 = (-b - s) / (2*a);
    else
        x1 = (-b + s) / (2*a);

    x2 = c / (a * x1);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;
}