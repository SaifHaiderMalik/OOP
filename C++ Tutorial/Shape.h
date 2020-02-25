#ifndef SHAPE_H
#define SHAPE_H

class Shape{
protected:
    double height, width;

public:
    static int  numOfShapes;
    Shape(double length);
    Shape(double height, double width);
    Shape();
    virtual ~Shape();
    void SetHeight(double height);
    double GetHeight();
    void SetWidth(double width);
    double GetWidth();
    static int GetNumOfShapes();
    virtual double Area();

private:
};

#endif