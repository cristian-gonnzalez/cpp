/** The C++ Standard Template Library
 */

#include <iostream>
/*

    The STL library is all of the various functions, algorithms, data-strucutres or containers and iterators
that are available to us in C++. THis means regardless of the compiler, we can rely on having a common
set of tools to work with and implent C++ in.

    It is templated meaning that you can reuse these containers or algorithms on different sorts of data
types. It is general purpose 

    The three keys we are interested are Containers, Algorithms and Iterators libraries.


     ------------ 
    | Containers |
     ------------
        ^
     data-structures
        - A collection of <elements>

        
     ------------ 
    | Algoritms  |
     ------------
        ^
     Operations on elemens

            [ , , , , ] array      [] -> [] -> [] linked-list
             ^
             |              
        Regardless of the data-structure, the algorithms can process the data 

     ------------ 
    | Iterators  |
     ------------
        ^
    Abstractrion for accessing out container in a sequencial or random-access manner. Different way
    to mnuer through containers 

                   |                        | 
                   |                        |
       [ , , , , ] |  <---- Iterator -----> |  Algorithms
        Container  |          ^             |  
                       iterator is sort of the bridge into the actual container, saying
                    how we get access (sequencial / random-access) and then the algorithms
                    tell us ho to maneuver throeugh each elements


        It is important to understand that the algorithms and containers are separated


    NOTE:
        A pair of iteratos (start, end) makes a 'range'.
        A range is where your computation is working on.

        [ , , , , , , , ]
             ^       ^
            start   end

*/
int main()
{
   
    return 0;
}