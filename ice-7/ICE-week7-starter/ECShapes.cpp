// Created by Y. Wu, Feb 27, 2023
// Base class: Shape for different kinds of geometry
// One interface function: CalcArea(), no parameter, return int (area of the shape). How should you define it?
class Shape {
public:
...
};

// Rectangle class: define two constructors
// (i) take two parameters, width and height
// (ii) take four parameters: x1,y1,x2,y2  where (x1,y1) is the upper left corner and (x2,y2) is the lower right corner
class Rectangle : public Shape {
public:
...
private:
};

// Class Square: a special rectangle
// One constructor: side length
class Square : public Rectangle {
public:
...
};

