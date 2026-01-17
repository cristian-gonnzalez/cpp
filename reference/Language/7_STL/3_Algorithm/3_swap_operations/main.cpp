#include <iostream>
#include <algorithm>
#include <vector>


void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    {
        int a = 1;
        int b = 2;

        std::cout << "a: " << a << " b: " << b << std::endl;

        swap(a, b);
        std::cout << "a: " << a << " b: " << b << std::endl;
        std::cout << std::endl;

    }

    std::vector odds{1,3,5,7,9,11,13};
    std::vector evens{2,4,6,8};

    auto print = [](auto& container)
                 { 
                    for(auto& e: container)
                        std::cout << e << " ";
                    std::cout << std::endl;
                 };
    
    std::swap( odds, evens );

    print( odds );
    print( evens );
    std::cout << std::endl;

    auto odds_it = odds.begin() + 1;
    auto evens_it = evens.begin() + 1;

    std::iter_swap(odds_it, evens_it );

    print( odds );
    print( evens );

    return 0;
}