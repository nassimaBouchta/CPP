#include <iostream>
#include <conio.h>
using namespace std;
//declaration
struct point{
    int x;
    int y;
    void initialise(int,int);
    void deplace(int,int);
    void affiche(int,int);
};


//definition

void point :: initialise(int abs, int ord)
{
    x=abs;
    y=ord;

}



void point :: deplace(int dx, int dy)
{
    x=x+dx;
    y=y+dy;
}
int main()
{   point a;
    a.initialise(2,4);
    getch();

    return 0;
}