#include "Unit.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace ariel{
class PhysicalNumber{
public:
Unit u;
int a;
//constructor
PhysicalNumber (int a,Unit unit);
//copy constructor
PhysicalNumber (const PhysicalNumber&);

PhysicalNumber operator+ (const PhysicalNumber&) const;
PhysicalNumber operator- (const PhysicalNumber&) const;

//unery operators
PhysicalNumber operator-();
PhysicalNumber operator+() const;

const PhysicalNumber& operator-= (const PhysicalNumber&);
const PhysicalNumber& operator+= (const PhysicalNumber&);
const PhysicalNumber& operator=(const PhysicalNumber&);

//compare operators
bool operator!= ( const PhysicalNumber&);
bool operator==(const PhysicalNumber&);
bool operator<=(const PhysicalNumber&);
bool operator>=(const PhysicalNumber&);
bool operator>(const PhysicalNumber&);
bool operator<(const PhysicalNumber&);


PhysicalNumber& operator++();
PhysicalNumber& operator--();


//friends functions:
friend ostream& operator<<(ostream&, const PhysicalNumber&);
friend istream& operator>>(istream&, const PhysicalNumber&);
};
}