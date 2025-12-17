#include <iostream>
#include <numeric>
#include <vector>


std::vector<int> range(int start, int end)
{
    std::vector<int> result(end-start);
    std::iota(result.begin(), result.end(), start);

    return result;
}

int main()
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);

    for(const auto&e: v)
        std::cout << e << " ";
    std::cout << std::endl;
    /*  OUTPUT:
        0 1 2 3 4 5 6 7 8 9
     */

    for(const auto&e: range(5,9))
        std::cout << e << " ";
    std::cout << std::endl;
    /* OUTPUT:
       5 6 7 8
    */

    return 0;
}