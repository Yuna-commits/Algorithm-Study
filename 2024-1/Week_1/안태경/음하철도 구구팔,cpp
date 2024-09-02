#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int Xs, Ys;
	cin >> Xs >> Ys;
	int Xe, Ye, dx, dy;
	cin >> Xe >> Ye >> dx >> dy;

	// X(t) = Xe + dx * t
	// Y(t) = Ye + dy * t

	/* 
	d(t)^2 = D(t) = (X(t) - Xs)^2 + (Y(t) - Ys)^2                     =    A*t^2 + B*t + C
	 = (dx*t + Xe - Xs)^2 + (dy*t + Ye - Ys)^2
	 i) A = dx^2 + dy^2
	 ii) B = 2(dx * (Xe - Xs)) + 2(dy * (Ye - Ys))       =         2(dx * (Xe - Xs) + dy * (Ye - Ys))
	 iii) C = (Xe - Xs)^2 + (Ye - Ys)^2

	 iV) t_min = -B / 2*A

	 V)
	  result_x = Xe + dx * t_min
	  result_y = Ye + dy * t_min

	*/

	double A = dx * dx + dy * dy;
	double B = 2 * (dx * (Xe - Xs) + dy * (Ye - Ys));
	double C = (Xe - Xs) * (Xe - Xs) + (Ye - Ys) * (Ye - Ys);

	double t_min = -B / (2 * A);

	if (t_min < 0) t_min = 0;

	int result_x = Xe + dx * t_min;
	int result_y = Ye + dy * t_min;

	cout << result_x << ' ' << result_y;


	return 0;
}
