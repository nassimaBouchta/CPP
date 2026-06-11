#include <iostream>
using namespace std;

// --- Base Class: Forme ---
class Forme {
protected:
    short couleur;

public:
    Forme(short c = 1) : couleur(c) {}
    Forme(const Forme& f) : couleur(f.couleur) {}

    virtual void affiche() {
        cout << "Couleur: " << couleur << endl;
    }
    
    // Operator =
    Forme& operator=(const Forme& f) {
        if(this != &f) {
            this->couleur = f.couleur;
        }
        return *this;
    }
    
    virtual ~Forme() {}
};

// --- Derived: Coordonnee (Used by most shapes) ---
class Coordonnee {
protected:
    int x, y;

public:
    Coordonnee(int a = 0, int b = 0) : x(a), y(b) {}
    void deplace(int dx, int dy) { x += dx; y += dy; }
};

// --- Derived: Cercle (inherits Forme) ---
class Cercle : public Forme {
protected:
    Coordonnee centre;
    short rayon;

public:
    // Constructor matches image parameters
    Cercle(int a, int b, short r, short c) : Forme(c), centre(a, b), rayon(r) {}
    
    Cercle(const Cercle& ce) : Forme(ce), centre(ce.centre), rayon(ce.rayon) {}

    void affiche() {
        Forme::affiche(); // Call base class display
        cout << "Cercle Centre: (" << centre.x << "," << centre.y << ") Rayon: " << rayon << endl;
    }

    void deplace(int dx, int dy) { centre.deplace(dx, dy); }
    
    int surface() { return 3.14 * rayon * rayon; }
    int perimetre() { return 2 * 3.14 * rayon; }
    
    Cercle operator=(const Cercle& c) {
        if(this != &c) {
            Forme::operator=(c);
            this->centre = c.centre;
            this->rayon = c.rayon;
        }
        return *this;
    }
};

// --- Derived: Triangle (Partie 3) ---
class Triangle : public Forme {
protected:
    Coordonnee a, b, c;

public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, short col) 
        : Forme(col), a(x1, y1), b(x2, y2), c(x3, y3) {}

    void affiche() {
        Forme::affiche();
        cout << "Triangle: A(" << a.x << "," << a.y << ") B(" << b.x << "," << b.y << ") C(" << c.x << "," << c.y << ")" << endl;
    }
    
    void deplace(int dx, int dy) {
        a.deplace(dx, dy); b.deplace(dx, dy); c.deplace(dx, dy);
    }
};

// --- Derived: Rectangle (Partie 4) ---
class Rectangle : public Forme {
protected:
    Coordonnee a, b; // Assuming a=top-left, b=bottom-right based on text

public:
    Rectangle(int x1, int y1, int x2, int y2, short col) 
        : Forme(col), a(x1, y1), b(x2, y2) {}

    void affiche() {
        Forme::affiche();
        cout << "Rectangle: HG(" << a.x << "," << a.y << ") BD(" << b.x << "," << b.y << ")" << endl;
    }
    
    void deplace(int dx, int dy) {
        a.deplace(dx, dy); b.deplace(dx, dy);
    }
};

// --- Derived: Carre (Partie 5, inherits Rectangle) ---
class Carre : public Rectangle {
private:
    short cote;

public:
    Carre(int x, int y, short c, short col) 
        : Rectangle(x, y, x + c, y + c, col), cote(c) {}

    void affiche() {
        Rectangle::affiche();
        cout << "Cote: " << cote << endl;
    }
};

int main() {
    cout << "--- TP5 Shapes Testing ---" << endl;

    // Test Cercle
    Cercle cl(10, 20, 5, 12);
    cl.affiche();
    cl.deplace(5, 4);
    cl.affiche();

    // Test Triangle
    Triangle T(10, 20, 30, 40, 50, 50, 11);
    T.affiche();
    T.deplace(5, 4);
    T.affiche();

    // Test Rectangle
    Rectangle R(20, 20, 40, 50, 60);
    R.affiche();
    R.deplace(5, 4);
    R.affiche();

    // Test Carre
    Carre C(10, 20, 5, 10);
    C.affiche();
    C.deplace(5, 4);
    C.affiche();

    return 0;
}