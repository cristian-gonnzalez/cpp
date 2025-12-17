/** std::range_sort
 *
 */

#include <print>
#include <vector>
#include <algorithm>

struct AirLinePassenger
{
    std::string _name;
    int         _priority;
};


int main()
{
    std::vector v{ AirLinePassenger{"Mike", 100},
                   AirLinePassenger{"Bob", 50},
                   AirLinePassenger{"Randall", 50},
                   AirLinePassenger{"Alice", 75},
                   AirLinePassenger{"Natalie", 50} };
    
    std::ranges::sort(v, std::ranges::greater{}, [](auto p)
                                                {
                                                    return p._priority;
                                                } );
    std::ranges::for_each(v , [](auto e)
                              {
                                std::print("{}: {}, ", e._name, e._priority); // [7, 11, 13, 19]
                              }); // Mike: 100, Alice: 75, Bob: 50, Randall: 50, Natalie: 50, 

    return 0;
}
