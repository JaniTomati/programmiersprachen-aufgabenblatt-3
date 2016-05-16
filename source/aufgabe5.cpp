// aufgabe5.cpp (Programmiersprachen Aufgabenblatt 3)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
#include <iostream>

bool is_even(unsigned int a);


TEST_CASE("describe_factorial", "[aufgabe3]") {

  std::vector<unsigned int> vektor(100);
  for (std::vector<unsigned int>::iterator i = vektor.begin(); i != vektor.end(); ++i) {
    *i = std::rand() % 100 + 1; // Zufallszahlen von 0 - 100
  }
  // std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));
  /* for (std::vector<unsigned int>::iterator i = vektor.begin(); i != vektor.end(); ++i) {
    if (*i % 2 != 0) {
      vektor.erase(i); // funktioniert nicht; vielleicht weil die groesse des Vektors sich staendig aendern wuerde?
    }
  } */
  // std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));
  
  std::vector<unsigned int> vektor_even(0); // Keine Loesung ohne zweiten Vektor gefunden :-(
  for (std::vector<unsigned int>::iterator i = vektor.begin(); i != vektor.end(); ++i) {
    if (*i % 2 == 0) {
      vektor_even.push_back(*i); 
    }
  } 
  // std::copy(std::begin(vektor_even), std::end(vektor_even), std::ostream_iterator<int>(std::cout, "\n"));

  // Wendet die Funktion is_even auf alle Eintrage von vektor_even an
  REQUIRE(std::all_of(vektor_even.begin(), vektor_even.end(), is_even)); 

}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

bool is_even(unsigned int a) {
  if (a % 2 == 0) {
    return true;
  }

  else return false;
}