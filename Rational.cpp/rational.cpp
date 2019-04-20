// rational.cpp
// example of operator overloading
// written by M.Auguston
#include <iostream>
using namespace std;

class Rational{
	int a, b;

// this function is private for the class
	int gcd(int x, int y){
		while(x && x != y) {
			if (x > y) x = x % y;
			else {
				int t;
				t = x;
				x = y;
				y = t;}
		}
		return y;
	}

public:
	// normal constructors
	Rational (){ a = 0; b = 1;}

	Rational(int x, int y){
		int w;

		if(x==0) {
			a = 0;
			b = 1;
			return; }
		
		if (y==0) { 
			cout << "denominator is 0"<< endl;
			y = INT_MAX;}
		else if (y < 0) { 
				y = abs(y); 
				x = -x;}
		
		w = gcd( abs(x), y);
		a = x/w; b = y/w;
	}
	

	Rational operator+(Rational x){
		return *new Rational(a*x.b + b*x.a, b*x.b);}

	Rational operator-(Rational x){
		return *new Rational(a*x.b - b*x.a, b*x.b);}

	Rational operator*(Rational x){
		return *new Rational(a*x.a, b*x.b);}

	Rational operator/(Rational x){
		if (x.a == 0) {
			cout << "Division by 0";
			return *new Rational;};

		return *new Rational(a*x.b, b*x.a);}

	Rational & operator=(Rational x){
		a = x.a;
		b = x.b;
		return *this;}

	Rational & operator+=(Rational x){
		int t;
		a = a*x.b + x.a*b;
		b = b*x.b;
		t = gcd(a, b);
		a = a/t;
		b = b/t;
		return *this;}

	bool operator==(Rational x){
		return ( a == x.a && b == x.b);}

	bool operator>(Rational x){
		return (a*x.b - b*x.a) > 0; }

	void print(){
		cout<< a <<"/" << b << ' ';}

	friend ostream & operator<<(ostream & s, Rational x);

	friend istream & operator>>(istream & i, Rational x);
	
};

ostream & operator<<(ostream & s, Rational x){
	s << x.a << '/' << x.b;
	return s;
}

istream & operator>>(istream & i, Rational x){
	i >> x.a >> x.b;
	return i;
}


int main(){
	Rational i(3,4), j(2, 8), k;

	i.print();
	j.print();
	k.print();
	k = i + j;
	k.print();

	k = k * i;
	k.print();

	cout << "\nprinting with cout: "<< k << endl; // << is also overloaded
	
	k += i;
	k.print();
	
	cout<<"\nComparing two numbers ";
	k.print(); cout<< " and "; j.print();cout<<" the result: ";
	if (k == j) cout<< "Equal ";
	else cout<< "Not equal";
	cout<< endl;
	
	return 0;
}
