#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{

public:
Unit u;
double a;
//constructor
PhysicalNumber (double a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber& PHnum);

const PhysicalNumber operator+ (const PhysicalNumber& PHnum) const;
const PhysicalNumber operator- (const PhysicalNumber& PHnum) const;

//unery operators
const PhysicalNumber operator-() const;
const PhysicalNumber operator+() const;

PhysicalNumber& operator-= (const PhysicalNumber& PHnum);
PhysicalNumber& operator+= (const PhysicalNumber& PHnum);

//compare operators
bool operator!=( const PhysicalNumber& PHnum)const;
bool operator==(const PhysicalNumber& PHnum) const;
bool operator<=(const PhysicalNumber& PHnum) const;
bool operator>=(const PhysicalNumber& PHnum) const;
bool operator>(const PhysicalNumber& PHnum) const;
bool operator<(const PhysicalNumber& PHnum) const;

//prefix
PhysicalNumber& operator++();
PhysicalNumber& operator--();
//postfix
const PhysicalNumber operator++(int);
const PhysicalNumber operator--(int);
double convert_to(double num)const;
double base(const PhysicalNumber& ph)const;
bool can_work_together(const PhysicalNumber& ph)const;
//friends functions:
friend ostream& operator<<(ostream&, const PhysicalNumber& c);
friend istream& operator>>(istream&,  PhysicalNumber& c);
};

}