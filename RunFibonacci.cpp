#include <iostream>
#include <vector>
#include "PseudoFibonacci.hpp"

/*
    Request user input for the first two terms of the series. Then display the next 10 terms using
    methods in PseudoFibonacci.cpp
 */
int main(){
    double firstNum, secondNum;
    std::vector<double> sequence;
    std::string output;
    
    PseudoFibonacci::getNum("First Number: ", firstNum);
    PseudoFibonacci::getNum("Second Number: ", secondNum);
    
    sequence = PseudoFibonacci::getSequence(firstNum, secondNum, 10);
    output = PseudoFibonacci::getDisplay(sequence);
    PseudoFibonacci::displaySequence(output);
    return 0;
}
