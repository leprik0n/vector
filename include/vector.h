#ifndef VECTOR_H
#define VECTOR_H
#include <ostream>

class Vector {
public:
  const static unsigned long n = 3;

  Vector();

  explicit Vector(double);

  Vector(const Vector &);

  Vector &operator=(const Vector &);

  double operator[](unsigned long i) const;

  double &operator[](unsigned long i);

  Vector &operator+=(const Vector &);

  Vector &operator-=(const Vector &);

  Vector &operator*=(double);

  Vector &operator/=(double);

  friend bool operator==(const Vector &, const Vector &);

  friend Vector operator+(const Vector &, const Vector &);

  friend Vector operator-(const Vector &, const Vector &);

  friend Vector operator*(const Vector &, double);

  friend Vector operator*(double, const Vector &);

  friend Vector operator/(const Vector &, double);

  friend double operator^(const Vector &, const Vector &);
  
  friend std::ostream &operator<<(std::ostream &, const Vector &);

  Vector operator-() const;

private:
  std::array<double,n> vec;
}; // class Vector

bool operator!=(const Vector &, const Vector &);

#endif // VECTOR_H
