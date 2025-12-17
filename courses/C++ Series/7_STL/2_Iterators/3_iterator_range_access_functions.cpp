/*

Range access
These non-member function templates provide a generic interface for containers, plain arrays, and std::initializer_list.

std::begin()
std::end()
std::size()
std::empty()
std::data()

 */

#include <iostream>
#include <vector>


int main()
{
    std::vector<int> container{1,2,3,4,5};

    // using member function
    //auto it = container.begin();

    // using non member function
    auto it = begin( container );
    
    std::cout << "begin( container ) : " << *it << std::endl;
    it++;
    std::cout << "it++               : " << *it << std::endl;
    
    auto cit = cbegin( container );
    // ERROR: read only iterator (const)
    //*cit = 5;
    
    // reverse iterator 
    auto rit = rbegin( container );
    std::cout << "rbegin( container ): " << *rit << std::endl; // poinst to the last element
    
    std::cout << "size               : " << size( container ) << std::endl;
    int *my_data = data( container ); 
    
    // raw loop
    std::cout << "data               : [";
    for(size_t i=0; i<size( container ); i++)
        std::cout << my_data[i] << ", ";
    std::cout << "]\n";

    std::cout << "empty              : " << empty( container ) << std::endl;
    
    return 0;
}
