#include "string_shared_ptr.hpp"

// Erstellt einen Shared Pointer auf ein String Objekt aus einem Zeiger auf
// dieses.
string_shared_ptr::string_shared_ptr(string *ptr) {
  // rc stellt ein Objekt zum Referenzzählen dar
  reference = new rc();
  strptr = ptr;
  // Referenz zu starken Zeigern bei Erstellung eines Shared Pointers erhöhen
  reference->inc_strong();
}

// Wird zur Konvertierung aus einem Weak Pointer auf ein String Objekt in einen
// Shared Pointer auf ein String Objekt verwendet.

string_shared_ptr::string_shared_ptr(string *ptr, rc *rc) {
  reference = rc;
  strptr = ptr;
  // Referenz erhöhen
  reference->inc_strong();
}

// Copy Konstruktor
string_shared_ptr::string_shared_ptr(const string_shared_ptr &other) {
  // refCount des neuen Zeigers auf Refcount des alten setzen
  reference = other.reference;
  strptr = other.strptr;
  // Neue Referenz wurde erstellt, daher refCount erhöhen
  reference->inc_strong();
};

// Destruktor
string_shared_ptr::~string_shared_ptr() {
  // Starken Referenzzähler um 1 verringern
  reference->dec_strong();
  // Wenn Starker Referenzzähler 0, String Objekt hinter dem strptr löschen
  if (reference->getStrongCount() == 0) {
    delete strptr;
    // Wenn auch schwacher Referenzzähler 0, Referenzzähler selbst löschen
    if (reference->getWeakCount() == 0) {
      delete reference;
    }
  }
}

// Setzt internen `strptr` auf einen `nullptr` zurück.
void string_shared_ptr::reset() { strptr = nullptr; }

// Pfeil Operator.
string *string_shared_ptr::operator->() { return strptr; }
