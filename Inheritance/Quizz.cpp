#include "Quizz.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int level = 0;

int gcn(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fraction::Fraction() {
	numerator = rand() % 50;
	denominator = 1 + rand() % 50;
}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
}

Fraction Fraction::operator+(const Fraction& f) {
	int num = this->numerator * f.denominator + f.numerator * this->denominator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator-(const Fraction& f) {
	int num = this->numerator * f.denominator - f.numerator * this->denominator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator*(const Fraction& f) {
	int num = this->numerator * f.numerator;
	int denom = this->denominator * f.denominator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

Fraction Fraction::operator/(const Fraction& f) {
	int num = this->numerator * f.denominator;
	int denom = this->denominator * f.numerator;
	int u = gcn(abs(num), abs(denom));
	Fraction newFrac(num / u, denom / u);
	return newFrac;
}

bool Fraction::operator==(const Fraction& fr) {
	return (Fraction::operator-(fr).numerator == 0);
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
	cout << "\n\tTu so: ";
	in >> frac.numerator;
	cout << "\tMau so: ";
	in >> frac.denominator;
	return in;
}

ArithmeticExpression::ArithmeticExpression() {
	a = 0; b = 1; operation = '+';
	char oper[4] = { '+', '-', 'x', ':'};
	if (level == 1) {		
		operation = oper[rand() % 2];
		a = rand() % 31;
		if (operation == '-') {
			b = rand() % (a + 1);
		}
		else {
			b = rand() % 31;
		}
	}
	else if (level == 2) {
		operation = oper[rand() % 2];
		a = 30 + rand() % 71;
		if (operation == '-') {
			b = 30 + rand() % (a - 29);
		}
		else {
			b = 30 + rand() % 71;
		}
	}
	else if (level == 3) {
		operation = oper[2 + rand() % 2];
		a = rand() % 31;
		if (operation == ':') {
			while (a % b != 0) {
				b = 1 + rand() % (a + 1);
			}
		}
		else {
			b = rand() % 31;
		}
	}
	else if (level == 4) {
		operation = oper[rand() % 4];
		aF = Fraction(rand() % 11, 1 + rand() % 10);
		if (operation == ':') {
			bF = Fraction(1 + rand() % 11, 1 + rand() % 10);
		}
		else {
			bF = Fraction(rand() % 11, 1 + rand() % 10);
		}
	}
}

std::ostream& operator<<(std::ostream& out, const ArithmeticExpression& ae) {
	if (level <= 3) {
		out << ae.a << " " << ae.operation << " " << ae.b << " = ?";
	}
	else if (level == 4) {
		out << "(" << ae.aF << ") " << ae.operation << " (" << ae.bF << ")" << " = ?";
	}
	return out;
}

std::istream& operator>>(std::istream& in, ArithmeticExpression& ae) {
	in >> ae.a >> ae.operation >> ae.b;
	return in;
}

bool ArithmeticExpression::check(int ans) const {
	int correctAns;
	switch (operation) {
	case '+': correctAns = a + b; break;
	case '-': correctAns = a - b; break;
	case 'x': correctAns = a * b; break;
	case ':': correctAns = a / b; break;
	default: throw std::invalid_argument("Invalid operation");
	}
	return ans == correctAns;
}

bool ArithmeticExpression::check1(Fraction& ans) {
	Fraction correctAns;
	switch (operation) {
	case '+': correctAns = aF + bF; break;
	case '-': correctAns = aF - bF; break;
	case 'x': correctAns = aF * bF; break;
	case ':': correctAns = aF / bF; break;
	default: throw std::invalid_argument("Invalid operation");
	}
	return ans == correctAns;
}