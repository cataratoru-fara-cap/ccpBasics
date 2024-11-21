#include <iostream>

using namespace std;

template <class T>
class Point

{   private:
    T coord_x, coord_y; //the coordinates of a point

    public:

    Point(){};
    Point(T coord_x, T coord_y) : coord_x(coord_x), coord_y(coord_y) {};
    //created new constructor just for fun

    T getCoordX()
    {
        return coord_x;
    }
    T getCoordY()
    {
        return coord_y;
    }

    void reset() //places the point into the origin
    {
    coord_x = coord_y = 0;
    }
    void moveX(T x ) //moves the point horizontally with x positions
    {
        coord_x += x;
    }
    void moveY(T y) // moves the point vertically with y positions
    {
        coord_y += y;
    }
    void moveXY(T x , T y ) // moves the point horizontally and vertically
    {
        coord_x += x;
        coord_y += y;
    }
};

int main()
{
    int n;
    cout << " Give n:" << endl;
    cin>>n;

    Point<int> p; // Add template argument to specify the type of Point
    p.reset();
    cout<<p.getCoordX()<<" "<<p.getCoordY()<<endl;

    p.moveX(n);
    cout<<p.getCoordX()<<" "<<p.getCoordY()<<endl;

    p.moveY(1);
    cout<<p.getCoordX()<<" "<<p.getCoordY()<<endl;

    p.moveX(-n);
    cout<<p.getCoordX()<<" "<<p.getCoordY()<<endl;

    p.moveY(-1);
    cout<<p.getCoordX()<<" "<<p.getCoordY()<<endl;

    float e;
    cout << " Give e:" << endl;
    cin>>e;

    Point <float> p2(3.2, 4); //tested constructor
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;

    p2.reset();
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;

    p2.moveX(e);
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;

    p2.moveY(1.2);
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;

    p2.moveX(-e);
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;

    p2.moveY(-1.2);
    cout<<p2.getCoordX()<<" "<<p2.getCoordY()<<endl;
     return 0;
}
