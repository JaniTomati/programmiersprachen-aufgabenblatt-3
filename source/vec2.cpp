// vec2.cpp (Programmiersprachen Aufgabenblatt 2)

#include "vec2.hpp"
#include <iostream>

Vec2::Vec2(): // Standardkonstruktor Initialisiert die Paramater x und y mit 0 
x{0}, y{0} {

}

Vec2::Vec2(float x_, float y_): // Konstruktor bekommt x und y Variable des Punktes uebergeben 
x{x_}, y{y_} {

} 

// Operator += : Addiert zwei Vektoren und ueberschreibt den Vektor links vom Operator mit den neuen Werten
Vec2& Vec2::operator += (Vec2 const& v) { 
	x += v.x;
	y += v.y;
	return *this;
}

// Operator -= : Subtrahiert zwei Vektoren und ueberschreibt den Vektor links vom Operator mit den neuen Werten
Vec2& Vec2::operator -= (Vec2 const& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

// Operator *= : Multipliziert einen Vektor mit einer Gleitkommazahl und ueberschreibt den Vektor mit den neuen Werten
Vec2& Vec2::operator *= (float v) {
	x *= v;
	y *= v; 
	return *this;
}

// Operator /= : Dividiert eine Gleitkommazahl von einem Vektor und ueberschreibt den Vektor mit den neuen Werten
Vec2& Vec2::operator /= (float v) {
	if (v == 0.0f) {
		std::cout << "/!\\ Die Teilung durch 0 ist nicht erlaubt!" << std::endl; // Exception!
	}

	else {
		x /= v;
		y /= v;
		return *this;
	}

}

// Operator + : Addiert jeweils die X und Y-Werte zweier Vektoren und gibt einen neuen Vektor zurueck
Vec2 operator + (Vec2 const& u, Vec2 const& v) {
	return Vec2 {u.x + v.x, u.y + v.y};

}

// Operator - : Subtrahiert jeweils die X und Y-Werte zweier Vektoren und gibt einen neuen Vektor zurueck
Vec2 operator - (Vec2 const& u, Vec2 const& v) {
	return Vec2 {u.x - v.x, u.y - v.y};
}

// Operator * : Multipliziert jeweils die X und Y-Werte eines Vektors mit einer Gleitkommazahl und gibt einen neuen Vektor zurueck
Vec2 operator * (Vec2 const& v, float s) {
	return Vec2 {v.x * s, v.y * s};
}

Vec2 operator * (float s, Vec2 const& v) {
	return Vec2 {s * v.x, s * v.y};
}

// Operator / : Dividiert jeweils die X und Y-Werte eines Vektors durch eine Gleitkommazahl und gibt einen neuen Vektor zurueck
Vec2 operator / (Vec2 const& v, float s) { 
	if (s == 0.0f) {
		std::cout << "/!\\ Die Teilung durch 0 ist nicht erlaubt!" << std::endl;
	}
	
	else {
		return Vec2 {v.x / s, v.y / s};
	}
}
