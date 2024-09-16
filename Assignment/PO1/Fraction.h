#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper method to simplify the fraction
    void reduce();

    // Helper method to calculate the GCD
    static int gcd(int a, int b);

    // Helper method to calculate the LCM
    static int lcm(int a, int b);

public:
    // Constructor
    Fraction(int num = 0, int den = 1);

    // Overloaded operators
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

    // Overload output operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);

    // Method to parse fractions from a string
    static Fraction parseFraction(const std::string& fracStr);
};

#endif
