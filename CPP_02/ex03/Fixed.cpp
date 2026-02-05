#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) { _value = n << _fractionalBits; }

Fixed::Fixed(const float n)
{
    _value = static_cast<int>(roundf(n * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        _value = rhs._value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _value >> _fractionalBits; }

bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed r;
    r._value = _value + rhs._value;
    return r;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed r;
    r._value = _value - rhs._value;
    return r;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed r;
    long tmp = static_cast<long>(_value) * rhs._value;
    r._value = static_cast<int>(tmp >> _fractionalBits);
    return r;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed r;
    long tmp = (static_cast<long>(_value) << _fractionalBits) / rhs._value;
    r._value = static_cast<int>(tmp);
    return r;
}

Fixed& Fixed::operator++() { ++_value; return *this; }
Fixed Fixed::operator++(int) { Fixed t(*this); ++_value; return t; }
Fixed& Fixed::operator--() { --_value; return *this; }
Fixed Fixed::operator--(int) { Fixed t(*this); --_value; return t; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
