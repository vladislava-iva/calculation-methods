// #define _USE_MATH_DEFINES
// #include <iostream>
// #include <iomanip>
// #include <cmath>

// using namespace std;

// int main() {
//     const double eps = 1e-10;

//     double N_direct_min = 1.0 / eps;
//     long long terms_direct = ceil(N_direct_min);

//     cout << "Оценка числа членов для прямого суммирования:\n";
//     cout << "N ≈ " << terms_direct << " (порядка 10^{10})\n";
//     cout << "(Невозможно вычислить напрямую в цикле — слишком много итераций)\n\n";

//     // ──────────────────────────────────────────────────────────────
//     // Пункт 2: Преобразованный ряд (ускоренная сходимость)
//     // S = π²/6 - π⁴/90 + ∑_{n=1}^∞ 1/(n⁴ (n² + 1))
//     // ──────────────────────────────────────────────────────────────
//     cout << "=== Преобразованный ряд ===\n";

//     const double pi = M_PI;
//     const double pi2_6 = pi * pi / 6.0;
//     const double pi4_90 = pi * pi * pi * pi / 90.0;

//     double S_accel = pi2_6 - pi4_90;
//     int terms_accel = 0;
//     double max_term = 0.0;  // Для контроля максимального члена

//     for (int n = 1; ; n++) {
//         double n2 = (double)n * n;
//         double n4 = n2 * n2;
//         double term = 1.0 / (n4 * (n2 + 1.0));

//         S_accel += term;
//         terms_accel++;
//         max_term = max(max_term, term);

//         if (term < eps) {
//             break;
//         }
//     }

//     cout << "Вычисленная сумма S ≈ " << setprecision(15) << S_accel << "\n";
//     cout << "Количество сложений членов ряда: " << terms_accel << "\n\n";

//     // ──────────────────────────────────────────────────────────────
//     // Проверка точности: сравнение с точной формулой S = (π coth(π) - 1)/2
//     // ──────────────────────────────────────────────────────────────
//     double exp_2pi = exp(2.0 * pi);
//     double coth_pi = (exp_2pi + 1.0) / (exp_2pi - 1.0);
//     double S_exact = (pi * coth_pi - 1.0) / 2.0;

//     cout << "Точная сумма (по формуле (π coth(π) - 1)/2): " << setprecision(15) << S_exact << "\n";
//     cout << "Разница между вычисленной и точной: " << abs(S_accel - S_exact) << " (меньше " << eps << ")\n\n";

//     // ──────────────────────────────────────────────────────────────
//     // Сравнение скорости сходимости
//     // ──────────────────────────────────────────────────────────────
//     cout << "=== Сравнение скорости сходимости ===\n";
//     cout << "Исходный ряд: ~10^{10} членов (медленная сходимость ~1/n²)\n";
//     cout << "Преобразованный ряд: " << terms_accel << " членов (быстрая сходимость ~1/n^6)\n";
//     cout << "Ускорение: примерно в " << terms_direct / terms_accel << " раз!\n";

//     return 0;
// }

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
