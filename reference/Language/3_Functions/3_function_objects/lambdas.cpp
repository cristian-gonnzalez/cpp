#include <iostream>
#include <vector>
#include <algorithm>

// syntax: [ captures ]( params ) { body }

void func_print_v(int n)
{
    std::cout << n << ", ";
}

void lambda_no_captures()
{
    std::vector<int> v{1,2,3,4,5};

    auto print_v = [](int n)
                    {
                        std::cout << n << ", ";
                    };
    
    std::for_each( begin(v), end(v), 
                   print_v );
                   // func_print_v); // is the same 

 
}

void lambda_by_refence()
{
    
    std::vector<int> v{1,2,3,4,5};

    int result{0};
    auto print_v = [&](int n)
                    {
                        result+=n;
                    };
    
    std::for_each( begin(v), end(v), 
                   print_v );

    
    std::cout << result << std::endl; 

}

int global = 137;
static int st_var = 41;

void global_and_static_var()
{
    
    std::vector<int> v{1,2,3,4,5};

    auto print_v = [=](int n)
                    {
                        global = 1;
                        st_var = 2;
                    };
    
    std::for_each( begin(v), end(v), 
                   print_v );

    
    std::cout << global << std::endl; 
    std::cout << st_var << std::endl; 

}


int main()
{
    std::vector<int> v{1,2,3,4,5};

    auto print_v = [=](int n)
                    {
                        global = 1;
                        st_var = 2;
                    };
    
    std::for_each( begin(v), end(v), 
                   print_v );

    
    std::cout << global << std::endl; 
    std::cout << st_var << std::endl; 

    return 0;
}