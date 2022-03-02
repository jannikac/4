#include "rc.hpp"

rc::rc() {
  strongCount = 0;
  weakCount = 0;
}

// Erhöht starken Referenzzähler um 1.
void rc::inc_strong() { strongCount++; }
// Verringert starken Referenzzähler um 1.
void rc::dec_strong() { strongCount--; }
// Erhöht schwachen Referenzzähler um 1.
void rc::inc_weak() { weakCount++; }
// Verringert schwachen Referenzzähler um 1.
void rc::dec_weak() { weakCount--; }
// Gibt starken Referenzzähler aus.
int rc::getStrongCount() const { return strongCount; }
// Gibt schwachen Referenzzähler aus.
int rc::getWeakCount() const { return weakCount; }
