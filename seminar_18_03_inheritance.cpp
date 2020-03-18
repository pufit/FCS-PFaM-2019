#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class Figure {
public:
    virtual ~Figure() = default;
    virtual double Area() const = 0;
};

class Rectangle : public Figure {
public:
    Rectangle(double horizontalSide, double verticalSide)
        : horizontalSide_(horizontalSide), verticalSide_(verticalSide) {
    }

    double Area() const override {
        return horizontalSide_ * verticalSide_;
    }

    ~Rectangle() {
        delete[] array_;
    }

private:
    double horizontalSide_ = 0.0;
    double verticalSide_ = 0.0;

    int* array_ = new int[10]{0};
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
    }
};

class Circle : public Figure {
public:
    Circle(double radius) : radius_(radius) {
    }

    double Area() const final {
        return M_PI * radius_ * radius_;
    }

private:
    double radius_ = 0.0;
};

void printAreas(const std::vector<Figure*>& figures) {
    for (auto figurePtr : figures) {
        std::cout << figurePtr->Area() << '\n';
    }
}

int main() {
    std::unique_ptr<Figure> rect = std::make_unique<Square>(2);
    std::cout << rect->Area() << '\n';
}
