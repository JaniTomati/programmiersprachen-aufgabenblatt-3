// circle.hpp (Programmiersprachen Aufgabenblatt 2)
// Teilweise uebernommen von den Vorlesungsfolien Nr. 3

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include <cmath>

class Circle {
public: 
	// Konstruktoren
	Circle();
	Circle(float r);

	// Memberfunktionen
	float get_diameter() const;
	float get_area() const; 
	float get_circumference() const;
	void set_radius(float r_); 
	float get_radius() const; 
	bool operator == (Circle const& c) const;
	bool operator < (Circle const& c) const;
	bool operator > (Circle const& c) const;
	bool operator() (Circle const& c1, Circle const& c2) const {
            return c1.get_radius() < c2.get_radius();
}

private:
	// Membervariablen
	float r; // radius

};

#endif // CIRCLE_HPP