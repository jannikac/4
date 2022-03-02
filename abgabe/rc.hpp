#ifndef RC_HPP
#define RC_HPP

class rc {
private:
  // Zähler für starke Referenzen (shared_ptr)
  int strongCount;
  // Zähler für schwache Referenzen (shared_ptr)
  int weakCount;

public:
  rc();
  void inc_strong();
  void dec_strong();
  void inc_weak();
  void dec_weak();
  int getStrongCount() const;
  int getWeakCount() const;
};

#endif