// vec2.hpp (Programmiersprachen Aufgabenblatt 2)

#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition 
class Vec2 {
public: 
	// Konstruktoren 
	Vec2(); 
	Vec2(float x, float y);
	
	// Memebervariablen
	float x; 
	float y;

	// Memberfunktionen
	Vec2& operator += (Vec2 const& v);
	Vec2& operator -= (Vec2 const& v);
	Vec2& operator *= (float v);
	Vec2& operator /= (float v);
};

Vec2 operator + (Vec2 const& u, Vec2 const& v);
Vec2 operator - (Vec2 const& u, Vec2 const& v);
Vec2 operator * (Vec2 const& v, float s);
Vec2 operator / (Vec2 const& v, float s);
Vec2 operator * (float s, Vec2 const& v);  

#endif // VEC2_HPP