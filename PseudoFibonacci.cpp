#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PseudoFibonacci.hpp"

/**
    Calculates the following terms of a recursive sequence given the first two terms.
    Terms are calculated using the formula: Fn = Fn-1 + Fn-2
    
    @param fn2 the first term of the sequence
    @param fn1 the second term of the sequence
    @param terms the number of terms to calculate
    @return a vector container with the requested sequence
 */
std::vector<double> PseudoFibonacci::getSequence(double fn2, double fn1, int terms){
    double fn; //next term in the sequence
    std::vector<double> sequence; //container for the sequence
    sequence.reserve(terms); 

    for(int i = 0; i < terms; i++){ //calculate the amount of terms requested
        //calculate the next term and add it to the container
        fn = fn2 + fn1;
        sequence.push_back(fn);
        fn2 = fn1;
        fn1 = fn;
    }
    
    return sequence;
}

/**
    Creates a string of the sequence to display.

    @param sequence the sequence of numbers to display
    @return the string that is to be displayed
 */
std::string PseudoFibonacci::getDisplay(std::vector<double> sequence){
    int terms = sequence.size();//number of terms in the sequence
    std::string output = "";//string that contains the output
    
    for(int i = 0; i < terms; i++){//add all the elements in the sequence to the output string
        output += std::to_string(sequence[i]) + "\n";
    }
    
    return output;
}

/**
   Displays the sequence in console

   @param sequence a string of the terms in the sequence
 */
void PseudoFibonacci::displaySequence(std::string sequence){
    std::cout << sequence; //display the string with the sequence of numbers
}

/**
   Sanitize user input for a number (which may be a decimal or an integer)
   
   @param message the messaget for the user, asking for input
   @param &num the number specified by the user (i.e. the input)
 */
void PseudoFibonacci::getNum(std::string message, double &num){
    bool numberEntered = false;//true only if valid input is entered by used
    std:: string input;
    std::stringstream sstrm;

    while(!numberEntered){//continue to ask for input as long as input is not valid (i.e. not a number)
        std::cout << message; //prompt user to enter input
        getline(std::cin, input);
        sstrm.str(input);
        sstrm >> num;//attempt to convert the input into a number
        
        if(sstrm.fail()){//if input is not a number, print an error message
            std::cout << "Input not valid " << sstrm.str() << std::endl;
            sstrm.clear();
        }
        else{ //if input is a number, return user input
            numberEntered = true;
        }
    }
}
