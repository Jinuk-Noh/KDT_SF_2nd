#include <iostream>

using namespace std;

class Shape {
//protected:
//    virtual void draw() =0;
    int line_num;
public :
    int getLineNum() {
        return line_num;
    }
};

class Circle :public Shape {

public:
    void draw() {
        cout << "원" << endl;
    }
};

class Rect :public Shape {
    int height;
public:
    int getHeight() {
        return height;
    }


    void draw() {
        cout << "사각형" << endl;
    }

};

class Tria :public Shape {

public:
    void draw() {
        cout << "삼각형" << endl;
    }

};


int main()
{
    //Shape s = Rect();
    //배열
    //Shape shapes[2] = { Rect(), Tria() };

    //cout << s.getLineNum() << endl;
    //cout << s.getHeight() << endl; x


    //Rect r = Shape(); x

    /*Shape* rr = new Rect();
    cout << sha->getLineNum() << endl;*/
}
