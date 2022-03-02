#include "string_weak_ptr.hpp"
#include "string_shared_ptr.hpp"

// Konstruktor aus einem Shared Pointer.
string_weak_ptr::string_weak_ptr(const string_shared_ptr &other) {
  // Pointer auf den String des string_shared_ptr kopieren
  strptr = other.strptr;
  // Pointer auf das rc Referenzzählerobjekt kopieren
  reference = other.reference;
  // Referenzzähler für schwache Referenzen erhöhen, wenn starker Referenzzähler
  // > 0 ist
  if (reference->getStrongCount() > 0) {
    reference->inc_weak();
  }
}

// "konvertiert" einen string_weak_ptr zu einem string_shared_ptr, wenn das Ziel
// des string_shared_ptr noch existiert, also strongCount > 0.
string_shared_ptr string_weak_ptr::lock() {
  // Wenn ein anderer Shared Pointer existiert, neuen string_shared_ptr
  // zurückgeben
  if (reference->getStrongCount() > 0) {
    return string_shared_ptr(strptr, reference);
  } else {
    // Wenn kein anderer Shared Pointer existiert, ist das Ziel des strptr durch
    // den Destruktor gelöscht worden und es existiert nicht mehr. Ein Shared
    // Pointer kann somit nicht erstellt werden.
    return nullptr;
  }
}

// Destruktor.
string_weak_ptr::~string_weak_ptr() { reference->dec_weak(); }