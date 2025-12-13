/* Language Enhancements:

Auto:
		You can use auto with:
			- const / volatile, reference/ pointers
		    	        ^
		        represent a variable that might be changed by some kind of external process, maybe a different 
		        thread or maybe hardware. So i prevents the compiler from overzealously optimizing out colatile
		        usage

decltype:
	Lets you declare a variable to be the same type as another variable.
    
*/

#include <iostream>

// New return value syntax:
//
// C++ now provides an alternative way for you to declare the return type function
// You put 'auto' at the beginning and at the end of paranthesis you put and arrow '->' and then you specify the return type. 
// This could be usefull when you implement lambdas
auto multiply(int a, int b) -> int
{
  return a*b;
}


int main()
{
	int x = 42;
  
  	// Takes any expresion inside parenthesis, and at compile time it will deduce what type it is.
	decltype(x) y = x;  // int y = x;
  
  return 0;
}