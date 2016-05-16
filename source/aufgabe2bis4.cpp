// aufgabe2bis4.cpp (Programmiersprachen Aufgabenblatt 3)

#include <vector>
#include <list>
#include <cstdlib> 
#include <iostream>
#include <iterator> 
#include <algorithm> 
#include <set>
#include <map>

int main() {

  // Liste mit 100 Plaetzen wird mit Zufallszahlen belegt 
  std::list<unsigned int> liste(100);
  for (std::list<unsigned int>::iterator i = liste.begin(); i != liste.end(); ++i) {
    *i = std::rand() % 100 + 1; // Zufallszahlen von 0 - 100
  }
  // Testausgabe
  // std::copy(std::begin(liste), std::end(liste), std::ostream_iterator<int>(std::cout, "\n"));

  // "Liste" wird in Vektor mit gleicher Groesse kopiert
  std::vector<unsigned int> vektor(liste.size());
  std::copy(std::begin(liste), std::end(liste), std::begin(vektor));
  // Testausgabe
  // std::copy(std::begin(vektor), std::end(vektor), std::ostream_iterator<int>(std::cout, "\n"));

  // Erstellt ein Set aus Werten der Liste (Sortiert + ohne doppelte Werte)
  std::set<unsigned int> set_liste(std::begin(liste), std::end(liste)); // in range
  // Testausgabe
  // std::copy(std::begin(set_liste), std::end(set_liste), std::ostream_iterator<int>(std::cout, "\n"));
  std::cout << "Die Liste enthaelt " << set_liste.size() << " verschiedene Werte." << std::endl;
  
  // Ausgabe aller Zahlen, die sich nicht in "Liste" befinden
  std::cout << "Folgende Zahlen befinden sich nicht in der Liste: " << std::endl;
  for (int i = 0; i <= 100; ++i) {
    if (set_liste.count(i) == false) {
      std::cout << i << " ";
    }
  }  
  std::cout << std::endl;

}