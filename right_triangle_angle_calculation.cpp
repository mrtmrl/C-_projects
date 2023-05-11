#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <iomanip>


using namespace std;

class RightTriangle {
private:
    double a, b, c;
    double alpha, beta, gamma;
public:
    RightTriangle(double sideA, double sideB, double sideC) {
        if (sideA < 0 || sideB < 0 || sideC < 0) {
            throw invalid_argument("Sides of triangle must be positive.");
        }
        a = sideA;
        b = sideB;
        c = sideC;
        alpha = asin(a / c) * 180 / M_PI;
        beta = asin(b / c) * 180 / M_PI;
        gamma = 90;
    }
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }
    double getAlpha() { return alpha; }
    double getBeta() { return beta; }
    double getGamma() { return gamma; }
    void setA(double sideA) {
        if (sideA < 0) {
            throw invalid_argument("Side of triangle must be positive.");
        }
        a = sideA;
        alpha = asin(a / c) * 180 / M_PI;
    }
    void setB(double sideB) {
        if (sideB < 0) {
            throw invalid_argument("Side of triangle must be positive.");
        }
        b = sideB;
        beta = asin(b / c) * 180 / M_PI;
    }
    void setC(double sideC) {
        if (sideC < 0) {
            throw invalid_argument("Side of triangle must be positive.");
        }
        c = sideC;
        alpha = asin(a / c) * 180 / M_PI;
        beta = asin(b / c) * 180 / M_PI;
    }
    friend ostream& operator<<(ostream& os, const RightTriangle& rt);
};

ostream& operator<<(ostream& os, const RightTriangle& rt) {
    os << fixed << setprecision(2); //to show 2 digits after the comma
    os << "Triangle with sides a=" << rt.a << " b=" << rt.b << " c=" << rt.c
       << " is a right triangle with angles " << rt.alpha << ", " << rt.beta
       << ", " << rt.gamma << " degrees.";
    return os;
}


class TriangleException : public exception {
private:
    double a, b, c;
public:
    TriangleException(double sideA, double sideB, double sideC)
      : a(sideA), b(sideB), c(sideC) {}
    const char* what() const throw() {
        return "Not a right triangle.";
    }
};

int main() {
    ifstream inputFile("triangles.txt");
    if (!inputFile.is_open()) {
        cerr << "Could not open input file." << endl;
        return -1;
    }

    double a, b, c;
    while (inputFile >> a >> b >> c) {
        try {
            if (a < 0) {
                cout << "Negative side " << a << " is corrected to ";
                a = abs(a);
                cout << a << "." << endl;
            }
            if (b < 0) {
                cout << "Negative side " << b << " is corrected to ";
                b = abs(b);
                cout << b << "." << endl;
            }
            if (c < 0) {
                cout << "Negative side " << c << " is corrected to ";
                c = abs(c);
                cout << c << "." << endl;
            }

            if (a * a + b * b != c * c) {
                throw TriangleException(a, b, c);
            }

            RightTriangle rt(a, b, c);
            cout<<rt<<endl;

        } catch (const invalid_argument& e) {
            cerr<<e.what()<<endl;

        } catch (const TriangleException& e) {
            cerr<<"Triangle with sides a="<<a<<" b="<<b<<" c="<<c<<" is not a right triangle."<<endl;

        } catch (...) {
            cerr<<"An unknown error occurred."<<endl;

        }
    }

    inputFile.close();
}

