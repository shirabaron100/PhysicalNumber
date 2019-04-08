/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    //my test
    PhysicalNumber a1(1, Unit::KM);
    PhysicalNumber b1(1000, Unit::M);
    PhysicalNumber c1(100000, Unit::CM);
    PhysicalNumber d1(1, Unit::HOUR);
    PhysicalNumber e1(60, Unit::MIN);
    PhysicalNumber f1(3600, Unit::SEC);
    PhysicalNumber g1(1, Unit::TON);
    PhysicalNumber h1(1000, Unit::KG);
    PhysicalNumber i1(1000000, Unit::G);
    testcase
.setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

.setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

.setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

.setname("Operator '>' binary - Compatible dimensions")
    .CHECK_EQUAL(a1>a1,false)                                         //2[cm] >= 2[cm]
    .CHECK_EQUAL(b1>a1,false)                                         //3[km]  >= 2[cm]                                        
    .CHECK_EQUAL(a1>c1,false)                                         //3[km] >= 0.1[km]
    .CHECK_EQUAL(d1>e1,false)                                         //4[hour] >= 0.1[hour]
    .CHECK_EQUAL(PhysicalNumber(10,Unit::MIN)>=b1,false)               //10[min] >= 0.1[hour]
    .CHECK_EQUAL(e1>f1,false)                                         //4[ton] >= 3[kg]
    .CHECK_EQUAL(f1>d1,false) 

.setname("Operator '>=' binary - Compatible dimensions")
    .CHECK_EQUAL(a1>=a1,true)                                         //2[cm] >= 2[cm]
    .CHECK_EQUAL(b1>=a1,true)                                         //3[km]  >= 2[cm]                                        
    .CHECK_EQUAL(a1>=c1,true)                                         //3[km] >= 0.1[km]
    .CHECK_EQUAL(d1>=e1,true)                                         //4[hour] >= 0.1[hour]
    .CHECK_EQUAL(PhysicalNumber(10,Unit::MIN)>=b1,true)               //10[min] >= 0.1[hour]
    .CHECK_EQUAL(e1>=f1,true)                                         //4[ton] >= 3[kg]
    .CHECK_EQUAL(f1>=d1,true)                                         //0.1[ton] >= 2[g]

.setname(" my Incompatible dimensions")

    .CHECK_THROWS(a1+d1)
    .CHECK_THROWS(a1+e1)
    .CHECK_THROWS(a1+f1)
    .CHECK_THROWS(b1+g1)
    .CHECK_THROWS(b1+h1)
    .CHECK_THROWS(b1+i1)
    .CHECK_THROWS(d1+g1)
    .CHECK_THROWS(e1+h1)
    .CHECK_THROWS(f1+i1)
    .CHECK_THROWS(e1+c1)
    .CHECK_THROWS(a1+i1)
    .CHECK_THROWS(e1+c1)
    .CHECK_THROWS(a1+i1)
    .CHECK_THROWS(e1+c1)
    .CHECK_THROWS(a1+i1)
    .CHECK_THROWS(e1+c1)


 .setname("Operator '==' binary - Compatible dimensions")
    .CHECK_EQUAL(a1==a1,true)                                         
    .CHECK_EQUAL(a1==PhysicalNumber(1000,Unit::M),true)                                                    
    .CHECK_EQUAL(b1==PhysicalNumber(1,Unit::KM),true)                                        
    .CHECK_EQUAL(b1==b1,true)
    .CHECK_EQUAL(d1==PhysicalNumber(1800,Unit::SEC),false)             
    .CHECK_EQUAL(e1==PhysicalNumber(0.05,Unit::HOUR),false)            

.setname("Operator '==' binary - Incompatible dimensions")
    .CHECK_THROWS(a1==d1)                                         
    .CHECK_THROWS(a1==f1)                                               
    .CHECK_THROWS(b1==h1)                                       
    .CHECK_THROWS(d1==g1)
    .CHECK_THROWS(d1==h1)             
    .CHECK_THROWS(e1==b1) 

.setname("Operator '!=' binary - Compatible dimensions")
    .CHECK_EQUAL(a1!=b1,false)                                                                                
    .CHECK_EQUAL(a1!=PhysicalNumber(3000,Unit::M),true)                                                    
    .CHECK_EQUAL(c1!=PhysicalNumber(0.004,Unit::KM),true)                                         
    .CHECK_EQUAL(b1!=b1,false)                                        
    .CHECK_EQUAL(b1!=PhysicalNumber(180,Unit::SEC),true)             
    .CHECK_EQUAL(b1!=PhysicalNumber(0.05,Unit::HOUR),true)            

  .setname("Operator '-=' binary - Compatible dimensions")
    .CHECK_OUTPUT((a1-=b1), "0[km]")                                 
    .CHECK_OUTPUT((c1-=b1), "0[cm]")                                
    .CHECK_OUTPUT((f1-=e1), "0[sec]")                               
    .CHECK_OUTPUT((h1-=i1), "0[kg]")                                   
    .CHECK_OUTPUT((i1-=h1), "1000000[g]")                                


.setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

.setname("my Basic input")
.CHECK_OK(istringstream("1[km]") >> a1)
.CHECK_OK(istringstream("1000[m]") >> b1)
.CHECK_OK(istringstream("100000[cm]") >> c1)
.CHECK_OK(istringstream("1[hour]") >> d1)
.CHECK_OK(istringstream("60[min]") >> e1)
.CHECK_OK(istringstream("3600[sec]") >> f1)
.CHECK_OK(istringstream("1[ton]") >> g1)
.CHECK_OK(istringstream("1000[kg]") >> h1)
.CHECK_OK(istringstream("1000000[g]") >> i1)
.CHECK_OUTPUT((a1 += PhysicalNumber(2000, Unit::M)), "3[km]")
.CHECK_OUTPUT((b1 += PhysicalNumber(700, Unit::M)), "1700[m]")
.CHECK_OUTPUT((c1 += PhysicalNumber(1, Unit::KM)), "200000[cm]")
.CHECK_OUTPUT((d1 += PhysicalNumber(30, Unit::MIN)),"1.5[hour]")
.CHECK_OUTPUT((f1 += PhysicalNumber(1800, Unit::SEC)),"5400[sec]")
.CHECK_OUTPUT((g1 += PhysicalNumber(1, Unit::TON)), "0[ton]")
.CHECK_OUTPUT((h1 += PhysicalNumber(1, Unit::TON)), "0[kg]")
.CHECK_OUTPUT((i1 += PhysicalNumber(1, Unit::TON)), "2000000[g]")




      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}