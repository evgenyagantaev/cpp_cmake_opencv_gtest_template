#include <cassert>
#include <iostream>
 
class Drob
{
private:
    int m_numerator;
    int m_denominator;
 
public:
    // Конструктор по умолчанию
    Drob(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }
 
    friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
};
 
std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}