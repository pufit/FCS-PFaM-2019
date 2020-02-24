// ALARM: DON'T COPY-PASTE IT


#include <iostream>
#include <cmath>


class Complex {
public:
    Complex(double re, double im = 0) : re_{re}, im_{im} {} // NOLINT(google-explicit-constructor)

    double Re() const {
        return re_;
    }

    double Im() const {
        return im_;
    }

    Complex operator+() const {
        return *this;
    }

    Complex operator-() const {
        return {-Re(), -Im()};
    }

    Complex Conjugate() const {
        return {Re(), -Im()};
    };

    Complex& operator++() { // a = 0; std::cout << ++a   1
        ++re_;
        return *this;
    }

    const Complex operator++(int) { // a = 0; std::cout << a++  0
        return {++re_, Im()};
    }

    Complex& operator+=(const Complex& z) {
        re_ += z.Re();
        im_ += z.Im();
        return *this;
    }

    Complex& operator-=(const Complex& z) {
        re_ -= z.Re();
        im_ -= z.Im();
        return *this;
    }

private:
    double re_{0};
    double im_{0};
};


Complex operator+(const Complex& c1, const Complex& c2) {
    return {c1.Re() + c2.Re(), c1.Im() + c2.Im()};
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return {c1.Re() - c2.Re(), c1.Im() - c2.Im()};
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return {c1.Re() * c2.Re() - c1.Im() * c2.Im(), c1.Re() * c2.Im() + c1.Im() * c2.Re()};
}

double abs(const Complex& c) {
    return std::sqrt(c.Re() * c.Re() + c.Im() * c.Im());
}

Complex operator/(const Complex& z, const Complex& w) {
    const auto w_abs = abs(w) * abs(w);
    const auto x = (z * w.Conjugate());
    return {x.Re() / w_abs, x.Im() / w_abs};
}


int main() {
    Complex z = {1, 2};
    return 0;
}
