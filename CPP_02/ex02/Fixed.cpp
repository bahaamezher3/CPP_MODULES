#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(n * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _value = rhs._value;
    return *this;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}


bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }


Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    result._value = _value + rhs._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    result._value = _value - rhs._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    long tmp = static_cast<long>(_value) * rhs._value;
    result._value = static_cast<int>(tmp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed result;
    long tmp = (static_cast<long>(_value) << _fractionalBits) / rhs._value;
    result._value = static_cast<int>(tmp);
    return result;
}



Fixed& Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_value;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_value;
    return tmp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
