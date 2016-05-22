// aufgabe5.cpp (Programmiersprachen Aufgabenblatt 3)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
#include <iostream>
#include "circle.hpp"
#include "swap.hpp"
#include "filter.hpp"

bool is_even(unsigned int a) {
  return a % 2 == 0;
}

bool is_odd(unsigned int a) {
  return a % 2 == 1;
}

// fuellt "vektor" mit Zufallszahlen und entfernt die ungeraden Zahlen, sodass "vektor" am Ende nur noch gerade Zahlen enthaelt
TEST_CASE("describe_factorial", "[aufgabe3.5]") {

  std::vector<unsigned int> vektor(100);
  for (std::vector<unsigned int>::iterator i = vektor.begin(); i != vektor.end(); ++i) {
    *i = std::rand() % 100 + 1; // Zufallszahlen von 0 - 100
  }
  // std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));

  vektor.erase(std::remove_if(vektor.begin(), vektor.end(), is_odd), vektor.end()); // erase <3

  // std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));
  
  /* std::vector<unsigned int> vektor_even(0); // Keine Loesung ohne zweiten Vektor gefunden :-(
  for (std::vector<unsigned int>::iterator i = vektor.begin(); i != vektor.end(); ++i) {
    if (*i % 2 == 0) {
      vektor_even.push_back(*i); 
    }
  } */
  // std::copy(std::begin(vektor_even), std::end(vektor_even), std::ostream_iterator<int>(std::cout, "\n"));

  // Wendet die Funktion is_even auf alle Eintrage von vektor_even an
  REQUIRE(std::all_of(vektor.begin(), vektor.end(), is_even)); 

}

// Sortiert die Elemente von "kreise" und prueft anschließend mit hilfe von is_sorted 
TEST_CASE("describe_operator", "[aufgabe3.7]") {
  std::vector<Circle> kreise(10);

  for (int i = 0; i <= 10; ++i) {
    kreise[i].set_radius(rand());
  }

  // sortiert den mit Kreisobjekten gefüllten Vektor "Kreise"
  std::sort(std::begin(kreise), std::end(kreise));

  REQUIRE(std::is_sorted(kreise.begin(), kreise.end()));
}

// swap.hpp vertauscht zwei Objekte gleichen Typs
TEST_CASE("describe_swap", "[aufgabe3.8]") {
  Circle c1 {1.0f};
  Circle c2 {3.0f};

  Swap(c1, c2);
  REQUIRE(c1 == 3.0f);
  REQUIRE(c2 == 1.0f);

  int eins = 1;
  int vierzehn = 14;

  Swap(eins, vierzehn);
  REQUIRE(eins == 14);
  REQUIRE(vierzehn == 1);

  double zwei = 2.0;
  double neun = 9.0;

  Swap(zwei, neun);
  REQUIRE(zwei == 9.0);
  REQUIRE(neun == 2.0);

}

// Sortiert die Eintraege in "kreise" mit Hilfe eines Lambdas 
TEST_CASE("describe_sortLambda", "[aufgabe3.9]") {
  std::vector<Circle> kreise(10);

  for (int i = 0; i <= 9; ++i) {
    kreise[i].set_radius(rand());
  }

  std::sort(std::begin(kreise), std::end(kreise),
        // Lambda expression begins
    [] (Circle const& c1, Circle const& c2) {
      return (c1.get_radius() < c2.get_radius());
      } // end of lambda expression
    );

  REQUIRE(std::is_sorted(std::begin(kreise), std::end(kreise)));
}

// Cointainer Addition. Prueft, ob alle Eintraege in v3 == 10 sind 
TEST_CASE("describe_ContainerAdd", "[Aufgabe3.10]") {
  std::vector<int> v1 {1,2,3,4,5,6,7,8,9}; 
  std::vector<int> v2 {9,8,7,6,5,4,3,2,1}; 
  std::vector<int> v3 (9);

  std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
    []  (int o1, int o2) { 
      return o1 + o2; 
    }
  );

  REQUIRE(std::all_of(v3.begin(), v3.end(), 
    []  (int a) { 
      return a == 10; 
    })
  );
}

// filter.hpp template uebernimmt Container als ersten Parameter und Praedikat als zweiten 
TEST_CASE("describe_filter", "[Aufgabe3.11]") {
  std::vector<int> v{1,2,3,4,5,6}; 
  std::vector<int> alleven = filter(v, is_even);

  REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));
}

// neuer Vektor "Viktor" mit den Kreisen aus circles, deren Radien groesser 4.0f sind
TEST_CASE("describe_CopyIf", "[Aufgabe3.13]") {
  std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
  std::vector<Circle> viktor(3);
  std::copy_if(circles.begin(), circles.end(), viktor.begin(),
    []  (Circle c) { 
      return c.get_radius() > 4.0f;
    }
  );

  REQUIRE(std::all_of(viktor.begin(), viktor.end(), 
    [] (Circle c) {
      return c.get_radius() > 3.0f;
    })
  );
}

// Loesung der Aufgabe 3.9 mit Hilfe eines Funktors (circle.hpp)
TEST_CASE("describe_sortFunctor", "[aufgabe3.14]") {
  std::vector<Circle> kreise(10);

  for (int i = 0; i <= 9; ++i) {
    kreise[i].set_radius(rand());
  }

  std::sort(std::begin(kreise), std::end(kreise), Circle());

  REQUIRE(std::is_sorted(std::begin(kreise), std::end(kreise)));
}

// main!
int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}