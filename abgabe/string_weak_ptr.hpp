#ifndef STRING_WEAK_PTR_HPP
#define STRING_WEAK_PTR_HPP
#include "string.hpp"
#include "string_shared_ptr.hpp"

class string_weak_ptr {
private:
  string *strptr;
  rc *reference;

public:
  // Konstruktor aus einem string_shared_ptr
  string_weak_ptr(const string_shared_ptr &other);
  string_shared_ptr lock();
  ~string_weak_ptr();
};
#endif