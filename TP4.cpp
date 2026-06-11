#include <iostream>
#include <string>
using namespace std;

class Note {
private:
    double val; // Real value between 0 and 20

public:
    // Constructor
    Note() : val(0) {}
    
    // Methods
    void input() {
        do {
            cout << "Enter note (0-20): ";
            cin >> val;
        } while(val < 0 || val > 20);
    }

    void print() const {
        cout << "Note: " << val << endl;
    }

    void set(float n) {
        if(n >= 0 && n <= 20) val = n;
        else cout << "Invalid note value" << endl;
    }

    double get() const { return val; }

    string apprecie() const {
        if(val < 8) return "Very Bad";
        else if(val < 10) return "Bad";
        else if(val < 12) return "Passable";
        else if(val < 14) return "Fair";
        else if(val < 16) return "Good";
        else return "Excellent";
    }

    // TP4 Exercise 2a: Harmoniser
    void harmonise(double& ref) {
        if(this->val > ref) {
            // Add logic specific to requirement
            // Example: Pass by reference parameter adjustment
            // This is loosely defined in image, assuming:
            this->val = ref; 
        }
    }

    // TP4 Exercise 2b: Moyenne (Static)
    static double moyenne(Note* tab, int n) {
        double sum = 0;
        for(int i = 0; i < n; i++) {
            sum += tab[i].get();
        }
        return (n > 0) ? sum / n : 0;
    }
};

int main() {
    int n;
    cout << "Number of notes: ";
    cin >> n;

    // Dynamic Allocation of Array
    Note* tableau = new Note[n];

    // Saisie
    for(int i = 0; i < n; i++) {
        cout << "Note " << i+1 << ": ";
        tableau[i].input();
    }

    // Display
    for(int i = 0; i < n; i++) {
        tableau[i].print();
        cout << "Appreciation: " << tableau[i].apprecie() << endl;
    }

    // Delete dynamic memory
    delete[] tableau;

    return 0;
}