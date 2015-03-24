#include <iostream>
int main() {
	long double l = 0, r = -1, m = 0, qua = 1e-162, ans;
	std::cin >> ans, r = ans;
	while (r - l > qua) {
		m = l + (r - l) / 2;
		if (m * m < ans)
			l = m;
		else
			r = m;
	}
	std::cout.precision(16);
	std::cout << m << "\n";
	return 0;
}