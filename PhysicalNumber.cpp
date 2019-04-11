#include <iostream>
#include "PhysicalNumber.h"
#include <stdlib.h>
using namespace ariel;
using namespace std;



PhysicalNumber::PhysicalNumber (double a,Unit unit):a(a),u(unit){

}
//copy constructor
PhysicalNumber::PhysicalNumber (const PhysicalNumber& obj):a(obj.a),u(obj.u){
	
}
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& PHnum )const{
    if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
        double c=a+b;
        c=convert_to(c);
        return PhysicalNumber(c,this->u);
    }
    
}
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& PHnum )const{
    if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
        double c=a-b;
        c=convert_to(c);
        return PhysicalNumber(c,this->u);
    }
    
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& PHnum ){
   if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    
    {
        double a=base(*this);
        double b=base(PHnum); 
        double c=a-b;
        c=convert_to(c);
        this->a=c;
        return *this;
    }
    
}


PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& PHnum ){
    if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum);   
        double c=a+b;
        c=convert_to(c);
        this->a=c;
        return *this;
    }  
}
const PhysicalNumber PhysicalNumber::operator+() const{
    return *this;
}
const PhysicalNumber PhysicalNumber::operator-() const{
    return PhysicalNumber(-1*this->a,this->u);
}

//compare operators
 bool PhysicalNumber::operator!=(const PhysicalNumber& PHnum)const{

  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
      if(a!=b)
        return true;
        else return false; 
    }
    
}
 bool PhysicalNumber::operator==(const PhysicalNumber& PHnum)const{
    
  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
      if(a==b)
        return true;
        else return false; 
    } 
}
 bool PhysicalNumber::operator<=(const PhysicalNumber& PHnum) const{
 
  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
      if(a<=b)
        return true;
        else return false; 
    }
    
}
 bool PhysicalNumber::operator>=(const PhysicalNumber& PHnum)const {

  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
      if(a>=b)
        return true;
        else return false; 
    }
    
}

 bool PhysicalNumber::operator>(const PhysicalNumber& PHnum)const {

  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
      if(a>b)
        return true;
        else return false; 
    }
    
}
 bool PhysicalNumber::operator<(const PhysicalNumber& PHnum)const {
 
  if(can_work_together(PHnum)==false)
    {
         std::__throw_bad_exception();
    }
    else
    {
        double a=base(*this);
        double b=base(PHnum); 
        if(a<b)
        return true;
        else return false; 
    }   
}
PhysicalNumber& PhysicalNumber::operator++(){
   this->a++;
   return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    this->a--;
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int)
{
   PhysicalNumber copy = *this;
    this->a++;
    return copy;
}
const PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber copy = *this;
    this->a--;
    return copy;
}
//private functins
bool PhysicalNumber::can_work_together( const PhysicalNumber& ph)const
{
int num1=(int)(this->u)%3;
int num2=(int)(ph.u)%3;
if(num1!=num2)
return false;
else return true;
}
double PhysicalNumber::base(const PhysicalNumber& ph)const{
    if ((int)ph.u%3==0)//cm/m/km
    {
        if(((int)ph.u)==0)//cm
            {
                return ph.a;
            }
        if(((int)ph.u)==3)//m
            {
                return ph.a*100;
            }
        if(((int)ph.u)==6)//km
            {
                return ph.a*100000;
            }
    }
    else if ((int)ph.u%3==1)//sec/min/hour
    {
        if ((int)ph.u==1)//sec
            {
                return ph.a;
            }
        if ((int)ph.u==4)//min
            {
                return ph.a*60;
            }
        if ((int)ph.u==7)//hour
            {
                return ph.a*3600;
            }

    }
    else //g/kg/ton
    {
        if ((int)ph.u==2)//g
            {
                return ph.a;
            }
        if ((int)ph.u==5)//kg
            {
                return ph.a*1000;
            }
        if ((int)ph.u==8)//ton
            {
                return ph.a*1000000;
            }
    } 
    return 1;  
}
double PhysicalNumber::convert_to(double num)const{
    if ((int)this->u==0)//cm
        {
    return num;
        }
    if ((int)this->u==3)//m
        {
    return num/100;
        }
    if ((int)this->u==6)//km
        {
    return num/100000;
        }
    if ((int)this->u==1)//sec
        {
    return num;
        }
    if ((int)this->u==4)//min
        {
    return num/60;
        }
    if ((int)this->u==7)//hour
        {
    return num/3600;
        }
    if ((int)this->u==2)//g
        {
    return num;
        }
    if ((int)this->u==5)//kg
        {
    return num/1000;
        }
    if ((int)this->u==8)//ton
        {
    return num/1000000;
        }
        else return 1;
}
//friends functions:
ostream& ariel::operator<<(ostream& stream, const PhysicalNumber& c){
     switch((int)(c.u))
    {
		case 2: stream<<c.a<<"[g]";
		break;
		case 5: stream<<c.a<<"[kg]";
		break;
		case 8: stream<<c.a<<"[ton]";
		break;
		case 0: stream<<c.a<<"[cm]";
		break;
		case 3: stream<<c.a<<"[m]";
		break;
		case 6: stream<<c.a<<"[km]";
		break;
		case 1: stream<<c.a<<"[sec]";
		break;
		case 4: stream<<c.a<<"[min]";
		break;
		case 7: stream<<c.a<<"[hour]";
		break;
    }
	return stream;
}
istream& ariel::operator>>(istream& input, PhysicalNumber& c )
    {
double num=-99999;
string st=" ";
input>>num;
input>>st;

if(num==-99999)
{
   std::__throw_bad_exception();
}
else
{

Unit unit;
         if(st.compare("[g]")==0)
        unit=Unit::G;
         else if(st.compare("[kg]")==0)
         {
        unit=Unit::KG;
         }
        else if(st.compare("[ton]")==0)
        unit=Unit::TON;
        else if(st.compare("[cm]")==0)
        unit=Unit::CM;
        else if(st.compare("[m]")==0)
        unit=Unit::M;
        else if(st.compare("[km]")==0)
        unit=Unit::KM;
         else if(st.compare("[sec]")==0)
        unit=Unit::SEC;
        else if(st.compare("[min]")==0)
        unit=Unit::MIN;
        else if(st.compare("[hour]")==0)
        unit=Unit::HOUR;
        else{
             std::__throw_bad_exception();
         }
         c.u=unit;
         c.a=num;
}
return input;
    }
//---------------------------------------------

