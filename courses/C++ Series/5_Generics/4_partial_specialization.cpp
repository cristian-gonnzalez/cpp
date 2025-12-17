#include <iostream> 
#include <cmath> 

template< typename T>
bool euqal(T a, T b) {
    return ( a == b );
}

template<>
bool euqal<float>(float a, float b) {
    std::cout << "equal<float>\n";
    return ( fabs(a - b) < 0.00001f );
}

template<>
bool euqal<double>(double a, double b) {
    std::cout << "equal<double>\n"; 
    return ( abs(a - b) < 0.0000001f );
}

int main()
{
    std::cout << euqal<int>(2, 2) << std::endl;
    std::cout << euqal<int>(2, 3) << std::endl;
    
    
    std::cout << euqal<float>(1.0f-0.999999f, 0.000001f) << std::endl;
    std::cout << euqal<double>(1.0f-0.999999f, 0.000001f) << std::endl;


    return 0;
}
