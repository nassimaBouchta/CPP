#include <iostream>
using namespace std;

// --- Exercise 1: Static Counter ---
class Compteur {
private:
    static int nb_objets; // Static member

public:
    Compteur() { nb_objets++; }
    ~Compteur() { nb_objets--; }
    static int getNombre() { return nb_objets; }
};
int Compteur::nb_objets = 0; // Initialize static member

// --- Exercise 2, 4, 5, 6: Point with References ---
class Point {
private:
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    void affiche() const { 
        cout << "(" << x << "," << y << ")" << endl; 
    }
    
    void affiche(char* name) const {
        cout << "Point " << name << " (" << x << "," << y << ")" << endl;
    }

    // Exercise 4: Coincidence (Pass by Value) - Ex 4
    bool coincidence(Point p) {
        return (x == p.x && y == p.y);
    }

    // Exercise 5 & 6: Coincidence (Pass by Reference) - Ex 5/6
    bool coincidence2(const Point& p) {
        return (x == p.x && y == p.y);
    }

    // Exercise 7: Setter
    void setXY(int a, int b) { x = a; y = b; }
};

// --- Exercise 7 & 8: Vector Class ---
class vecteur {
private:
    float x, y;

public:
    vecteur(float a = 0, float b = 0) : x(a), y(b) {}
    
    void homothie(float val) { // Modifies internally
        x *= val; 
        y *= val;
    }
    
    // Version returning modified by VALUE (Ex 8 part 1)
    vecteur homothie2(float val) {
        return vecteur(x * val, y * val);
    }
    
    // Version passing by REFERENCE (Ex 8 part 3)
    void homothie3(vecteur& v, float val) {
        v.x *= val;
        v.y *= val;
    }

    void affiche() const {
        cout << "Vect (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Test Static
    Compteur c1, c2;
    cout << "Nb Objects: " << Compteur::getNombre() << endl;

    // Test Point & Coincidence
    Point p1(10, 20);
    Point p2(10, 20);
    if(p1.coincidence2(p2)) cout << "Points are identical" << endl;

    // Test Vector
    vecteur v1(3, 4);
    v1.homothie(2.0);
    v1.affiche();
    
    return 0;
}