#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Abstract Base Class
class BasicShape {
private:
    double area;
    string name;
public:
    BasicShape() : area(0.0), name("") {}
    virtual ~BasicShape() {}

    void setArea(double a) { area = a; }
    double getArea() const { return area; }

    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    virtual void calcArea() = 0; // Pure virtual
};

// Derived Class - Circle
class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;
public:
    Circle(double x, double y, double r, const string& n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n);
        calcArea();
    }

    void calcArea() override {
        double area = 3.14159 * radius * radius;
        setArea(area);
    }

    double getXCenter() const { return xCenter; }
    double getYCenter() const { return yCenter; }
    double getRadius() const { return radius; }
};

// Derived Class - Rectangle
class Rectangle : public BasicShape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w, const string& n = "Rectangle")
        : length(l), width(w) {
        setName(n);
        calcArea();
    }

    void calcArea() override {
        double area = length * width;
        setArea(area);
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
};

// Derived Class - Square (inherits from Rectangle)
class Square : public Rectangle {
private:
    double side;
public:
    Square(double s, const string& n = "Square")
        : Rectangle(s, s, n), side(s) {
        setName(n);
        // No need to call calcArea() here, Rectangle constructor already does
    }

    double getSide() const { return side; }
};

int main() {
    // Create array (vector) of BasicShape pointers
    vector<BasicShape*> shapes;

    // Add two Rectangles
    shapes.push_back(new Rectangle(4.0, 5.0, "BigRectangle"));
    shapes.push_back(new Rectangle(3.5, 2.0, "SmallRectangle"));

    // Add two Circles
    shapes.push_back(new Circle(0.0, 0.0, 2.5, "FirstCircle"));
    shapes.push_back(new Circle(1.0, 1.0, 4.0, "SecondCircle"));

    // Add one Square
    shapes.push_back(new Square(3.0, "PerfectSquare"));

    // Display name and area
    for (auto shape : shapes) {
        cout << shape->getName() << " area: " << shape->getArea() << endl;
    }

    // Clean up memory
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
