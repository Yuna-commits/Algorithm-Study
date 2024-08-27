// 실수 오차를 해결할 수 있는 방법??

#include <iostream>

double Inclination(int a, int b, int c, int d)
{
	if (b - d == 0)				// 수직일 경우
		return 0.0f;
	else if (a - c == b - d)	// 수평일 경우
		return 1.0f;
	else if (a - c != 0)		// 수직, 수평이 아닐 경우
		return (static_cast<double>(b - d) / static_cast<double>(a - c));
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto xs = 0, ys = 0;
	std::cin >> xs >> ys;

	auto xe = 0, ye = 0, dx = 0, dy = 0;
	std::cin >> xe >> ye >> dx >> dy;

	auto nx = xe + dx, ny = ye + dy;
	auto bx = xe, by = ye;

	for (auto x = -100; x <= 100; x++)
	{
		auto y1 = Inclination(xe, ye, nx, ny) * (x - xe) + ye;
		auto y2 = -Inclination(ye, xe, ny, nx) * (x - xs) + ys;

		if (std::abs(y1 - y2) <= 0.1f)
		{
			bx = static_cast<int>(x);
			by = static_cast<int>(y1);
			break;
		}
	}
	std::cout << bx << " " << by;

	return 0;
}