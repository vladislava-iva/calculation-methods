#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

const double E = 3e-8;
const double T = 500.0;

double a(double x, long long k) {
	double k3 = (double)k * k * k;
	double k6 = k3 * k3;

	double r1 = sqrt(k3 - x);
	double r2 = sqrt(k3 + x);

	double r3 = sqrt(k6 - x * x);

	return -2.0 * x / (r3 * (r1 + r2));
}

void sh(double x, int K = 10) {
	double prev = a(x, 1);
	for (int k = 1; k <= K; k++) {
		double cur = a(x, k);

		if (k > 1) {
			double rat = cur / prev;
			cout << k << " " << scientific << setprecision(6) << cur << " " << rat << endl;
		}
		else {
			cout << k << " " << cur << endl;
		}
		prev = cur;
	}
}

double summa(double x, long long& n, double& t_sec) {
	double s = 0.0;
	long long k = 1;

	while (true) {
		s += a(x, k);
		double r = fabs(x) * (2.0 / 7.0) * pow((double)k, -3.5);
		if (r < E) {
			n = k;
			break;
		}
		k++;
	}
	t_sec = n * T * 1e-6;
	return s;
}

void est1() {
	double N = pow(2.0 / (7.0 * E), 1.0 / 3.5);

	cout << llround(N);
}

void est2() {
	double n_slow = pow(2.0 / E, 2.0);
	double t_sec = 2.0 * n_slow * T * 1e-6;
	double t_year = t_sec / (365.25 * 24 * 3600);

	cout << scientific << setprecision(3);

	cout << n_slow << endl;
	cout << t_sec << " " << t_year << endl;
}
void calc() {
	cout << fixed << setprecision(12);

	vector <double> x = { 0.5,0.999999999 };

	for (double xx : x) {
		long long n = 0;
		double t = 0.0;
		double s = summa(xx, n, t);
		cout << setw(10) << " " << setw(18) << " " << setw(6) << " " << setw(8) << " " << fixed << setprecision(6) << " " << t << " ";
	}
}

int main() {
	sh(0.5);
	est1();
	est2();
	calc();
}
