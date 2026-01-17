#include <iostream>





// I define function for only one arg
template<typename T>
T sum(T arg)
{
  return arg;
}


// typename... packagename
// the ... means multiple arguments. So we need to tell the compiler that the argument we want to use has multiple args
// I define the function for two or more args
template<typename T, typename... Args>
T sum(T start, Args... args)
{
  return start + sum(args...);
}

int main()
{
    // use version chose by compiler
	std::cout << sum(1,1,3.7,4,5) << std::endl;
    
    // use version sum( double start, Args... args)
	std::cout << sum<double>(1,1,3.7,4,5) << std::endl;
	
    // use version sum( double start, double... args)
	std::cout << sum<double,double>(1,1,3.7,4,5) << std::endl;
	
	
	/*
	OUTPUT
	14
    14
    14.7
	*/
	
	// CONCLUSION: we have to be specific on chossing the version of template function we 
	// want to use. In this case, we want to work with double to not lose precision but
	// using double as first parameter does not asure to not lose precision although we know that we are
	// returning double too. So, at the end, we need the two template parameter to be double.
    
}