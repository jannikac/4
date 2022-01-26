// numerics.hpp
#if !defined(INCLUDED__BLATT5__NUMERICS_HPP)
#define INCLUDED__BLATT5__NUMERICS_HPP
#if !defined(PRECISION)
// No explicit precision selected.
#define PRECISION double
#endif
struct vector {
  PRECISION x, y, z;
};
vector my_vector();
#endif /* !defined(INCLUDED__BLATT5__NUMERICS_HPP) */