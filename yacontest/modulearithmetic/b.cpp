#include <iostream>
double binpow(double a, uint64_t n) {
	double res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return res;
}
int main() {
	double a;
	uint64_t n;
	std::cin >> a;
	std::cin >> n;
	std::cout << binpow(a, n);
}