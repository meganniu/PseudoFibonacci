#build an executable named PseudoFibonacci from RunFibonacci.cpp
#AND build an executable named TestFibonacci from PseudoFibonacci.cpp and TestFibonacci.cpp
all: RunFibonacci.cpp PseudoFibonacci.cpp TestFibonacci.cpp
	g++ -std=c++11 -o RunFibonacci RunFibonacci.cpp PseudoFibonacci.cpp 
	g++ -std=c++11 -o TestFibonacci PseudoFibonacci.cpp TestFibonacci.cpp -lcppunit

#build an executable named RunFibonacci from RunFibonacci.cpp
run: RunFibonacci.cpp
	g++ -std=c++11 -o RunFibonacci RunFibonacci.cpp PseudoFibonacci.cpp 

#build an executable named TestFibonacci from PseudoFibonacci.cpp and TestFibonacci.cpp
test: PseudoFibonacci.cpp TestFibonacci.cpp
	g++ -std=c++11 -o TestFibonacci PseudoFibonacci.cpp TestFibonacci.cpp -lcppunit

#open html documentation of program in firefox browser
openDocFirefox:
	firefox html/index.html

#open html documentation of progam in google chrome browser
openDocChrome:
	google-chrome html/index.html

#delete all executable files of the program
clean:
	rm -f RunFibonacci TestFibonacci
