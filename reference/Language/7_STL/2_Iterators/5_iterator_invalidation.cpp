#include <iostream>
#include <vector>
#include <typeinfo>


int main()
{
    std::vector<int> vec{10,20,30,40,50,60};

    std::cout << typeid(vec).name() << std::endl;

    // bad way
    auto it=vec.begin();
    auto end=vec.end();
    for(; it!=end; it++)
    {
        if(*it == 30)
        {
            it = vec.erase(it);
            vec.push_back(30);
            vec.push_back(70);
            
        }
        
        std::cout << *it << std::endl;   
    }

    // Good way
    for (auto it = c.begin(); it != c.end();)
    {
        if (*it % 2 == 0)
            // returns the iterator following the last removed element.
            it = c.erase(it);
        else
            ++it;
    }
    return 0;
}