#ifndef RATIONAL
#define RATIONAL
#include <iostream>
class Rational {
  public:
    class DivisionByZeroError : public std::runtime_error {
      public:
        DivisionByZeroError(std::string message = "error: division by zero")
            : std::runtime_error(message) {}
    };
    Rational(int num = 0, int denum = 1);
    Rational& operator=(const Rational& rhs) = default;
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    ~Rational() = default;
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator<=(const Rational& rhs) const;
    bool operator>=(const Rational& rhs) const;
    Rational operator-() const;
    Rational operator+() const;

    Rational& operator++();
    Rational& operator--();

    Rational operator++(int);
    Rational operator--(int);

    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    void reduce();
    void SetValues(int num, int denum);
    static int NOD(int a, int b);
    static int NOK(int a, int b);
    friend std::ostream& operator<<(std::ostream& ostream,
                                    const Rational& data);
    friend std::istream& operator>>(std::istream& istream, Rational& data);

  private:
    static const char kSeparator{'/'};
    int num_{0};
    int denum_{1};
};
#endif
