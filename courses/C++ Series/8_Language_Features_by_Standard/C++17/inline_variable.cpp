#include <iostream>

// The inline specifiers means sth different than what inlining means for variables

// The inline specifier is used in a declaration of a valirable with static storage 

//
// Before C++ 17
//

/*
// Struct.h
//#pragma once

struct Struct
{
	// we define an static varibale
	static const int SomeConstValue{105};
	//     ~~~~ 
    // There is no problem to declare a const and initialize it as static storage 

    //static int SomeValue=8;
    //                    ~~
    // C++ forbids in-class initialization of non-const static member 'Struct::SomeValue'
	
    
    // we define an static varibale
	static int SomeValue;
	//~~~~~~
    // The static variable needs to be initialized outside the class. Otherwise, we get a lining error:
    // "undefined reference to `Struct::SomeValue'"

};

// Struc.cpp

// Inizializes outside the class
int Struct::SomeValue = 1;

*/

//
// C++ 17
//

struct Struct
{
	static const int SomeConstValue{105};

    // constexpr is implicity an inline variable
	static constexpr int SomeConstExprValue{175};
    //     ~~~~~~~~~
    //     read-only (const)


	// if we use inline, we can initialize in the definition (we dont need to initialize the variable outisde the class)
	inline static int SomeValue{67};
};

int main()
{
	std::cout << Struct::SomeConstValue << std::endl;  // 105
	std::cout << Struct::SomeConstExprValue << std::endl;  // 175

	Struct s;

	Struct::SomeValue = 94;
	std::cout << Struct::SomeValue << std::endl;  // 94


	return 0;
}

