#include "Fraction.h"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>

// Constructor
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}

// Helper method to reduce the fraction
void Fraction::reduce() {
    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue;

    if (denominator < 0) { // Keep denominator positive
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Helper method to calculate GCD
int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Helper method to calculate LCM
int Fraction::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Overloaded addition operator
Fraction Fraction::operator+(const Fraction& other) const {
    int lcd = lcm(denominator, other.denominator);
    int adjustedNum1 = numerator * (lcd / denominator);
    int adjustedNum2 = other.numerator * (lcd / other.denominator);
    return Fraction(adjustedNum1 + adjustedNum2, lcd);
}

// Overloaded subtraction operator
Fraction Fraction::operator-(const Fraction& other) const {
    int lcd = lcm(denominator, other.denominator);
    int adjustedNum1 = numerator * (lcd / denominator);
    int adjustedNum2 = other.numerator * (lcd / other.denominator);
    return Fraction(adjustedNum1 - adjustedNum2, lcd);
}

// Overloaded multiplication operator
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

// Overloaded division operator
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

// Overloaded equality operator
bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

// Overload output operator
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

// Parse fractions from a string
Fraction Fraction::parseFraction(const std::string& fracStr) {
    std::istringstream iss(fracStr);
    int num, den;
    char slash;
    iss >> num >> slash >> den;
    return Fraction(num, den);
}

// Main Function for File Input and Testing
int main() {
    std::ifstream infile("fractions.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string frac1Str, frac2Str, op;
        iss >> frac1Str >> op >> frac2Str;

        Fraction frac1 = Fraction::parseFraction(frac1Str);
        Fraction frac2 = Fraction::parseFraction(frac2Str);
        Fraction result;

        if (op == "+") {
            result = frac1 + frac2;
        } else if (op == "-") {
            result = frac1 - frac2;
        } else if (op == "*") {
            result = frac1 * frac2;
        } else if (op == "/") {
            result = frac1 / frac2;
        } else {
            std::cerr << "Unknown operator: " << op << std::endl;
            continue;
        }

        std::cout << frac1 << " " << op << " " << frac2 << " = " << result << std::endl;
    }

    infile.close();
    return 0;
}
