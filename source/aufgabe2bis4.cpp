// aufgabe2bis4.cpp (Programmiersprachen Aufgabenblatt 3)

#include <vector>
#include <list>
#include <cstdlib> 
#include <iostream>

int main() {

  // Liste mit 100 Plaetzen wird mit Zufallszahlen belegt 
  std::list<unsigned int> liste(100);
  for (std::list<unsigned int>::iterator i = liste.begin(); i != liste.end(); ++i) {
    *i = std::rand(); 
  }
  std::copy(std::begin(liste), std::end(liste), std::ostream_iterator<int>(std::cout, "\n"));

  // Liste wird in Vektor mit gleicher Groesse kopiert
  std::vector<unsigned int> vektor(liste.size());
  std::copy(std::begin(liste), std::end(liste), std::begin(vektor));
  std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));

}