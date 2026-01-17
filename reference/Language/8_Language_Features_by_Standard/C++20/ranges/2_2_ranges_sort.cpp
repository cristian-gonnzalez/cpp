/** std::range_sort
 *
 */

#include <print>
#include <vector>
#include <algorithm>

// Sorts the elements in the range in non-descending order (std::less). 
// Notice the order of equivalent elements is not guaranteed to be perserved 
// (In that case, use ranges::stable_sort).
//
// tamplate< ...... >
//
// sort( R&& r, Comp comp = {}; Porj proj = {} );
//                   ~~~~            ~~~~
//                    ^                ^
//                    |              Projection to apply to the elements
//                    |                      default = std::identity
//      Comparison to apply to the projected elements
//                 defaultd = ranges::less


int main()
{
    std::vector v{13,7,11,19};

    std::ranges::sort(v);
    std::println("{}", v); // [7, 11, 13, 19]


    std::ranges::sort(v, std::ranges::greater{} );
    //                                       ~~
    //                                  Initialize it as an object in-place
    std::println("{}", v); // [19, 13, 11, 7]

    std::ranges::sort(v, std::ranges::less{}, [](auto i)
                                                {
                                                    if( i == 7)
                                                        return i+5; // return 12
                                                    return i;
                                                } );
    std::println("{}", v); // [11, 7, 13, 19]
                           //      ~
                           

    return 0;

}
