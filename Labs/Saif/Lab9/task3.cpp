#include<iostream>
#include<cmath>
using namespace std;

class Acute;

class Obtuse{

    double length;
    double breadth;
    double obtuseAngle;


    public:
    
    Obtuse(){

    }

    Obtuse(double _length,double _breadth,double _angle){

        length = _length;
        breadth = _breadth;
        obtuseAngle = _angle;
    }

    void setLength(double len){

        length = len;

    }

    void setBreadth(double bre){

        breadth = bre;
    }

    void setangle(double angle){

        obtuseAngle = angle;
    }

    friend void CalculateArea(Acute &,Obtuse &);

};


class Acute{

    double length;
    double breadth;
    double acuteAngle;

    public:

    Acute(){

    }
        
    Acute(double _length,double _breadth,double _angle){

        length = _length;
        breadth = _breadth;
        acuteAngle = _angle;
    }

    void setLength(double len){

        length = len;

    }

    void setBreadth(double bre){

        breadth = bre;
    }

    void setangle(double angle){

        acuteAngle = angle;
    }

    friend void CalculateArea(Acute &,Obtuse &);


};


void CalculateArea(Acute &a,Obtuse &o){


    cout << "Area of Trinagle for Acute: " << (a.length*a.breadth)/2*sin(a.acuteAngle) <<endl;
    cout << "Area of Trinagle for Obtuse: " << (o.length*o.breadth)*sin(o.obtuseAngle)*1/2<<endl; 
}


int main(void){

  

    Acute ac;
    Obtuse ob;

    double length;
    double breadth;
    double angle;

    cout <<"Enter length: " <<endl;
    cin >> length;

    cout << "Enter Breadth: " <<endl;
    cin >> breadth;

    cout << "Enter Angle: " <<endl;
    cin >> angle;

    if(angle < 90){

        ac.setLength(length);
        ac.setBreadth(breadth);

        angle = angle *3.142/180;

        ac.setangle(angle);
    }

    else{
        
        ob.setLength(length);
        ob.setBreadth(breadth);

        angle = angle * 3.142/180;

        ob.setangle(angle);

    }


    CalculateArea(ac,ob);
    
}