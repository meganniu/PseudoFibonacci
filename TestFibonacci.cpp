#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include <cmath>

#include "PseudoFibonacci.hpp"
#include "TestFibonacci.hpp"

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput if the two initial terms of 
    the sequence are positive rationals.
 */
void TestFibonacci::testPositives(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(1.45, 2.43, 10);
    std::vector<double> answer = {3.88, 6.31, 10.19, 16.5, 26.69, 43.19, 69.88, 113.07, 182.95, 296.02};
    
    CPPUNIT_ASSERT (equal(sequence, answer));
}

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput if the two initial terms of 
    the sequence are negative rationals.
 */
void TestFibonacci::testNegatives(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(-1.45, -2.43, 10);
    std::vector<double> answer = {-3.88, -6.31, -10.19, -16.5, -26.69, -43.19, -69.88, -113.07, -182.95, -296.02};
    
    CPPUNIT_ASSERT (equal(sequence, answer));
}

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput if the two initial terms of 
    the sequence are positive rational and a negative rational.
 */
void TestFibonacci::testMixed(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(-1.45, 2.43, 10);
    std::vector<double> answer = {0.98, 3.41, 4.39, 7.8, 12.19, 19.99, 32.18, 52.17, 84.35, 136.52};
    
    CPPUNIT_ASSERT (equal(sequence, answer));
}

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput if the two initial terms of 
    the sequence are zeroes.
 */
void TestFibonacci::testZeroes(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(0, 0, 10);
    std::vector<double> answer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    CPPUNIT_ASSERT (sequence == answer);
}

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput length (i.e. all requested
    terms are being calculated)
 */
void TestFibonacci::testLength(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(1, 2, 10);
    std::vector<double> answer = {3, 5, 8, 13, 21, 34, 55, 89, 144, 233};
    
    CPPUNIT_ASSERT(sequence.size() == answer.size());
}

/**
    Unit test for Pseudofibonacci::getSequence. Tests for correct ouput if the two initial terms of 
    the sequence are integers.
 */
void TestFibonacci::testIntegers(void){
  std::vector<double> sequence = PseudoFibonacci::getSequence(1, 2, 10);
    std::vector<double> answer = {3, 5, 8, 13, 21, 34, 55, 89, 144, 233};
    
    CPPUNIT_ASSERT (sequence == answer);
}

/**
    Unit test for Pseudofibonacci::getDisplay. Tests for the correct formatting of output.
 */
void TestFibonacci::testDisplay(void){
    std::vector<double> sequence = PseudoFibonacci::getSequence(1, 2, 10);
    std::string output = PseudoFibonacci::getDisplay(sequence);
    std::string answer = "3.000000\n5.000000\n8.000000\n13.000000\n21.000000\n34.000000\n55.000000\n89.000000\n144.000000\n233.000000\n";
    
    CPPUNIT_ASSERT(output.compare(answer) == 0);
}

/**
    Compares the elements of two vector containers of type double in order (i.e. compares first 
    element of v1 with first element of v2 etc.)
    
    @param v1 vector container of type double to compare
    @param v2 other vector container of type double to compare
    @return returns true only if all elements match and if sizes of the containers match
 */
bool TestFibonacci::equal(std::vector<double> v1, std::vector<double> v2){
  if(v1.size() != v2.size()){ //if the size of the containers are not the same, they are not equal
        return false;
    }
    
    int size = v2.size();
    
    for(int i = 0; i < size; i++){ //checks if each corresponding element matches
      //if the elements do not match, within a degree of error necesarry for floating point
      //arithmancy, the containers are not equal
      if(!(std::abs(v1[i] - v2[i]) < 0.0000000000001)){
            return false;
        }
    }

    //if the size and elements of the containers match, the containers are equal
    return true;
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestFibonacci);

/**
    Executes unit tests and displays results in console.
    This function was modified from: yolinux.com/TUTORIALS/CppUnit.html
    2-clause BSD License: yolinux.com/YoLinux-Terms.html
 */

int main(){
    CPPUNIT_NS::TestResult testResult;
    
    CPPUNIT_NS::TestResultCollector collectedResults;
    testResult.addListener(&collectedResults);
    
    CPPUNIT_NS::BriefTestProgressListener progress;
    testResult.addListener(&progress);
    
    CPPUNIT_NS::TestRunner testRunner;
    testRunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    
    testRunner.run(testResult);
    
    CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults, std::cout);
    compilerOutputter.write();
    
    return 0;
}
