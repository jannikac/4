#ifndef STRING_SHARED_PTR_HPP
#define STRING_SHARED_PTR_HPP
#include "rc.hpp"
#include "string.hpp"
#include <cstdlib>

class string_shared_ptr {
private:
  rc *reference;
  string *strptr;
  // Konstruktor aus Zeiger zu string und Zeiger zu einem Referezzähler Objekt
  // NICHT IN IMPLEMENTIERUNG VERWENDEN, VERWENDUNG NUR IN string_weak_ptr.
  string_shared_ptr(string *ptr, rc *rc);

public:
  // Konstruktor
  string_shared_ptr(string *ptr);
  // Copy-Konstruktor
  string_shared_ptr(const string_shared_ptr &other);
  void reset();
  string *operator->();
  ~string_shared_ptr();
  // Weak pointer als friend deklarieren, um Zugriff auf reference und strptr zu
  // erlauben
  friend class string_weak_ptr;
};
#endif