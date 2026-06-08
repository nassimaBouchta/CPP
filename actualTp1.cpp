#include <iostream>
#include <conio.h>
using namespace std;

int exercice1()
{
    int n;
    float x;

    cout << "entrer un nombre entier et un nombre reel: ";
    cin >> n >> x;
    cout << "le produit de " << n << " et " << x << " est " << n*x ;
    return 0;
}


int exercice2()
{
  int i, n=25, *p;
    char *CH="On est à l'IGA !";
    float x = 25.359;

    cout<<"BONJOUR\n";
    cout<<CH<<"\n";
    cout<<"BONJOUR\n"<<CH<<"\n";
    cout<<"n= "<<n<<"      x= "<<x<<"      p= "<<p<<

    getch () ;  

    return 0;
}

int exercice3()
{ 

    int n;
    char tc[30],c;
    float x;
    cout<<"Saisir un entier:";
    cin>>n;
    cout<<"Saisir un réel:";
    cin>>x;
    cout<<"Saisir une phrase:";
    cin>>tc;
    cout<<"Saisir une lettre:";
    cin>>c;
    cout<<"Affichage : "<<n<<" "<<x<<" "<<tc<<" "<<c<<"\n";
    getch () ;

return 0;

}


int exercice4(int n, float x)
{

cout << x^n;
return 0;
}





void test(int n = 0, float x = 2.5)
{
    cout << "Fonction N°1 : ";
    cout << "n= " << n << "      x=" << x << "\n";
}

void test(float x = 4.1, int n = 2)
{
    cout << "Fonction N°2 : ";
    cout << "n= " << n << "      x=" << x << "\n";
}

int main()
{
    int i = 5; float r = 3.2;
    test(i, r);    // fonction N°1
    test(r, i);    // fonction N°2
    test(i);       // fonction N°1
    test(r);       // fonction N°2

    // les appels suivants, ambiguës, sont rejetés par le
    // compilateur
    // test();
    //test (i, i);
    // test (r, r);
    // les initialisations par défaut de x à la valeur 4.1
    // et de n à 0 sont inutilisables

    getch() ;
    return 0;
}


//int main()
//{  
    // exercice1();
    // exercice2();
    // exercice3();
    // exercice4(2, 3.5);

 //   return 0;
//}

