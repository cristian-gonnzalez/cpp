/** STL std::vector | Modern Cpp Series Ep. 116
 */

#include <iostream>
#include <vector>


int main()
{
    // using CTAD (Class Template Argument Deduction) we can figure out
    // or deduce the types in some cases
    std::vector v1{1,2,3};
    
    // When we add an element and we get that capacity. It doubles again.
    // It is in 3, then 6 and then 12.
    //
    // It might optimizing trading a little bit of memory because when we
    // are growing the data-structure, we dont have to pay that cost of copying
    // our vector everytime.
    std::cout << "capacity: "<< v1.capacity()
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 3   size: 3
    v1.push_back(4);
    std::cout << "capacity: "<< v1.capacity() 
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 6   size: 4
    v1.push_back(5);
    std::cout << "capacity: "<< v1.capacity() 
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 6   size: 5
    v1.push_back(6);
    std::cout << "capacity: "<< v1.capacity() 
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 6   size: 6
    v1.push_back(7);
    std::cout << "capacity: "<< v1.capacity() 
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 12  size: 7

    // operator[]
    std::cout << "[";
    for(size_t i=0; i < v1.size(); i++)
        std::cout << v1[i] << ", ";
    std::cout << "]\n";  // [1, 2, 3, 4, 5, 6, 7, ]

    // shrink_to_fit:
    //      Reduces memory usage by freeing unused memory
    //      This is sth you might consider especially if you doing lots of deletes
    v1.shrink_to_fit();
    std::cout << "capacity: "<< v1.capacity() 
              <<  "\tsize: "<< v1.size() << std::endl; // capacity: 7   size: 7

    return 0;
}