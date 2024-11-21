#include <iostream>

using namespace std;

template <class T>

class Point
{
    private:
    T coord_x, coord_y;//the coordinates of a point

    public:

    Point(){};

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
    void moveX(int x ) //moves the point horizontally with x positions
    {
        coord_x += x;
    }
    void moveY(int y) // moves the point vertically with y positions
    {
        coord_y += y;
    }
    void moveXY(int x , int y ) // moves the point horizontally and vertically
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

    Point <int> p;
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

     return 0;
}
