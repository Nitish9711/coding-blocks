#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    virtual double area() const {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    virtual double area() const {
        return width * height;
    }

private:
    double width;
    double height;
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(3.0);
    shapes[1] = new Rectangle(4.0, 5.0);

    for (int i = 0; i < 2; i++) {
        std::cout << "Shape " << i + 1 << " has area " << shapes[i]->area() << std::endl;
    }

    delete shapes[0];
    delete shapes[1];

    return 0;
}
