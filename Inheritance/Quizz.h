#pragma once
#ifndef QUIZZ_H
#define QUIZZ_H
#include <iostream>

extern int level;

class Fraction {
protected:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int num, int denom);
	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);
	bool operator==(const Fraction& fr);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
	friend std::istream& operator>>(std::istream& in, Fraction& frac);
};

class ArithmeticExpression : public Fraction {
protected:
	int a;
	int b;
	Fraction aF;
	Fraction bF;
	char operation;
public:
	ArithmeticExpression();
	friend std::ostream& operator<<(std::ostream& out, const ArithmeticExpression& ae);
	friend std::istream& operator>>(std::istream& in, ArithmeticExpression& ae);
	bool check(int ans) const;
	bool check1(Fraction& ans);
};


#endif // !QUIZZ_H
