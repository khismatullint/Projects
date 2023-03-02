#include <iostream>;
#include <vector>;
double f(const double& a, const double& b, const double& c, const double& d,
         const double& x) {
    return (a * x * x * x + b * x * x + c * x + d);
}
int main() {
    const long double eps = 1e-6;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(8);
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long double left = -10000, right = 10000, middle;
    while (right - left > eps) {
        middle = (right + left) / 2;
        if (f(a, b, c, d, middle) > 0) {
            if (a > 0)
                right = middle;
            else
                left = middle;
        } else if (a > 0)
            left = middle;
        else
            right = middle;
    }
    std::cout << left;
}