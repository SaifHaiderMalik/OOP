// ---------- POLYMORPHISM EXAMPLE ----------
 
// Polymorphism is a feature in which similar 
// objects can be treated the same, but also
// utilize their differences automatically
// for any methods marked as virtual
 
class Shape{
protected:
    double height;
    double width;
public:
    // Assume that if only 1 value is passed
    // that height and width are equal
    Shape(double length){
        height = length;
        width = length;
    }
    Shape(double h, double w){
        height = h;
        width = w;
    }
    virtual double Area(){
        return height * width;
    }
};
 
class Circle : public Shape{
public:
    Circle(double w) :
    Shape(w){
 
    }
    
    // Override Area()
    double Area(){
        return 3.14159 * std::pow((width / 2), 2);
    }
};
 
// This function receives Shapes but uses the 
// correct Area() automatically
void ShowArea(Shape& shape){
    std::cout << "Area : " << shape.Area() << "\n";
}
 
int main()
{
    Shape square(10,5);
    Circle circle(10);
    ShowArea(square);
    ShowArea(circle);
    
    return 0;
}
 
// ---------- END POLYMORPHISM EXAMPLE ----------