// std::cin >> std::hex >> value  // 26 -> 38

// 'kx + b' - линейная
// 'ax^2 + bx + c' - парабола

#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>

class BaseMathFunc {
public:
    virtual double operator()(double x) const = 0;

    virtual ~BaseMathFunc() = default;
};


class LinearFunc : public BaseMathFunc {
public:
    LinearFunc(double k, double b) : k_{k}, b_{b} {}

    double operator()(double x) const override {
        return k_ * x + b_;
    }

private:
    double k_{0};
    double b_{0};
};


class SquareFunc : public BaseMathFunc {
public:
    SquareFunc(double a, double b, double c) : a_{a}, b_{b}, c_{c} {}

    double operator()(double x) const override {
        return a_ * x * x + b_ * x + c_;
    }

private:
    double a_{0};
    double b_{0};
    double c_{0};
};


double Applyer(const std::vector<std::unique_ptr<BaseMathFunc>>& funcs, double x) {  // f g h x
    double res = x;
    for (auto it = funcs.rbegin(); it != funcs.rend(); ++it) {
        res = (**it)(res);
    }
}


int main() {

    std::vector<std::unique_ptr<BaseMathFunc>> v;
    v.push_back(std::make_unique<LinearFunc>(1, 2));
    v.push_back(std::make_unique<SquareFunc>(1, 2, 1));
    v.push_back(std::make_unique<SquareFunc>(2, 4, 3));

    std::cout << Applyer(v, 10) << '\n';
}
