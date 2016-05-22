// swap.hpp (Programmiersprachen Aufgabenblatt 3)

#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T> 
  void Swap (T& obj1, T& obj2) { // Es wird direkt mit den eingegebenen Paramtern gearbeitet; Veraenderung erlaubt 
    T temp = obj1; // temp wird obj1 zugewiesen
    obj1 = obj2; // obj1 uebernimmt Wert von obj2
    obj2 = temp; // obj2 uebernimmt Wert von temp (obj1)
  }

#endif // SWAP_HPP