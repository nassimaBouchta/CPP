#include <iostream>
#include <cmath>
using namespace std;

// --- Exercise 1, 3, 4, 5: Point Class ---
class Point {
private:
    int x, y;

public:
    // Default Constructor (Ex 3)
    Point() : x(0), y(0) {}

    // Parameterized Constructor (Ex 4)
    Point(int a, int b) : x(a), y(b) {}

    // Destructor (Ex 5)
    ~Point() {
        cout << "Destructor called for point (" << x << ", " << y << ")" << endl;
    }

    // Methods
    void initialiser(int a, int b) { x = a; y = b; }
    void deplacer(int dx, int dy) { x += dx; y += dy; }
    void afficher() const { cout << "Point (" << x << ", " << y << ")" << endl; }
    void effacer() { x = 0; y = 0; }
};

// --- Exercise 6: SuiteAr (Arithmetic Sequence) ---
class SuiteAr {
private:
    int* val; // Dynamic array
    int n;

public:
    SuiteAr(int nb) : n(nb) {
        val = new int[n]; // Allocation
        // Calculate first n terms of arithmetic sequence (e.g. n*2)
        for(int i = 0; i < n; i++) {
            val[i] = i * 2; 
        }
    }

    ~SuiteAr() {
        delete[] val; // Deallocation
    }
};

// --- Exercise 7: Hasard (Random Numbers) ---
class Hasard {
private:
    int* val;
    int n;

public:
    Hasard(int nb) : n(nb) {
        val = new int[n];
        for(int i = 0; i < n; i++) {
            val[i] = rand() % 100; // Random 0-99
        }
    }

    ~Hasard() { delete[] val; }
};

// --- Exercise 8: Complex Class ---
class Complex {
private:
    double x, y; // x real, y imaginary

public:
    // Constructors
    Complex() : x(0), y(0) {}
    Complex(double a, double b) : x(a), y(b) {}
    Complex(const Complex& c) : x(c.x), y(c.y) {} // Copy

    void set(double a, double b) { x = a; y = b; }
    double module() const { return sqrt(x*x + y*y); }
    void afficher() const {
        if(y >= 0) cout << x << "+" << y << "i" << endl;
        else cout << x << y << "i" << endl;
    }
};

int main() {
    // Testing Point
    cout << "--- TP2 Testing ---" << endl;
    Point p1;
    p1.initialiser(5, 10);
    p1.afficher();
    p1.deplacer(2, 3);
    p1.afficher();

    Point p2(20, 30); // Testing constructor
    p2.afficher();

    return 0;
}