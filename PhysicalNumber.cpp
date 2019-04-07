#include <iostream>
#include "PhysicalNumber.h"
#include <stdlib.h>
#include <iostream>
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber (double a,Unit unit):a(a),u(unit){

}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj):a(obj.a),u(obj.u){
	
}
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& PHnum )const{
    return PhysicalNumber(0,this->u);
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& PHnum )const{
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& PHnum ){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& PHnum ){
    return *this;
}

PhysicalNumber PhysicalNumber::operator+() const{
    return *this;
}
PhysicalNumber PhysicalNumber::operator-(){
    return *this;
}

//compare operators
bool PhysicalNumber::operator!= ( const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator==(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator<=(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator>=(const PhysicalNumber& PHnum){
    return true;
}

bool PhysicalNumber::operator>(const PhysicalNumber& PHnum){
    return true;
}
bool PhysicalNumber::operator<(const PhysicalNumber& PHnum){
    return true;
}


PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
}

//friends functions:
ostream& ariel::operator<<(ostream& os, const PhysicalNumber& c){
    return os;
    
}
istream& ariel::operator>>(istream& input,const PhysicalNumber& c ){

    return input;
    //---------------------------------------------
}