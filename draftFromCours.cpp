#include <iostream>
#include <conio.h>
using namespace std;
int i=11;
int main()
{  /*int x;
    cout << "entrer un nombre entier : ";
    cin >> x;
    cout << "le carre de " << x << " est " << x*x ;
    return 0;

    char c='m', d=25 , e;
    int i=42,j;
    float r=678.9, s;
    j=c;
    cout << j << endl;
    j=r;
    cout << j << endl;
    s=d;
    cout << s << endl;
    e=i;
    cout << e << endl;
  */


int i=34;
{
    int i=23;
    ::i=::i+1;
    cout << ::i << " " << i << endl;
}
    cout << ::i << " " << i << endl;

    return 0;
    


}



