#include <cmath>
#include <fmt/format.h>

double f(const double x) { return 4 - 0.1 * x * x; }

int main() {
    std::function g { static_cast<double (*)(const double)>(cos) };

    constexpr auto epsilon = 1e-6;
    constexpr auto dx = 0.1;
    constexpr auto MAX_STEPS = 100;

    auto n = 0;
    auto x0 = 0.0;
    auto y0 = g(x0);

    fmt::print("dx = {}   epsilon = {}\n\n", dx, epsilon);
    while (n < MAX_STEPS && abs(y0) > epsilon) {
        n ++;
        const auto slope = (g(x0 + dx) - y0) / dx;
        const auto x1 = - y0 / slope + x0;
        fmt::print("step {:2d}:   f({:10.5f}) = {:20.5f}   f\' = {:10.5f}   x1 = {:10.5f}\n", n, x0, y0, slope, x1);
        y0 = g(x1);
        x0 = x1;
    }
    fmt::print("\nfound zero f({:10.5f}) = {:20.5f}\n", x0, y0);

    return 0;
}
