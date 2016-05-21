// circle.cpp (Programmiersprachen Aufgabenblatt 2)
#include <iostream>
#include "circle.hpp"

	// Default-Konstruktor
Circle::Circle(): 
r {1.0f} {

}
	
	// Konstruktor (Uebergabeparameter: center, radius, color)
Circle::Circle(float r_): 
r {r_} {

	if (r_ == 0.0f) {
		std::cerr << "/!\\ Der Radius muss groeßer Null sein!" << std::endl;
		r = 1.0f; // Wird auf Defaultradius gesetzt
	}

	else if (r_ < 0.0f) { // negativer Radius wird positiv gemacht
		r = r_ * (-1);
	}
}

	// Durchmesser: D = 2 * r
float Circle::get_diameter() const {
	return 2 * r;
}

	// Flaecheninhalt: A = pi * r^2 
float Circle::get_area() const {
	return M_PI * r * r;
}

	// Umfang: U = 2 * pi * r
float Circle::get_circumference() const {
	return 2 * M_PI * r;
}

	// Uebergibt einem Kreis einen neuen Radius
void Circle::set_radius(float r_) {
	if (r_ == 0.0f) {
		std::cerr << "/!\\ Der Radius muss groeßer Null sein!" << std::endl;
		r = 1.0f; // Wird auf Defaultradius gesetzt
	}

	else if (r_ < 0.0f) { // negativer Radius wird positiv gemacht
		r = r_ * (-1);
	}

	else r = r_;
}

	// Gibt den Radius des Kreises aus, auf dem die Funktion aufgerufen wird 
float Circle::get_radius() const {
	return r;
}

	// Vergleich == gleich
bool Circle::operator == (Circle const& c) const {
	return r == c.r;
}

	// Vergleich < kleiner 
bool Circle::operator < (Circle const& c) const {
	return r < c.r;
}

	// Vergleich > groesser
bool Circle::operator > (Circle const& c) const {
	return r > c.r;
} 
