
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <span>


void print(const auto& container, std::string_view title="" )
{
    std::cout << title << "[";
    for(const auto& e: container)
        std::cout << e << ", ";
    std::cout << "]\n";

}

void erase_test()
{
    // using erase from vector member function
    //std::list<std::string> people{"ashely","adam","michael","joe","mike"};
    std::vector<std::string> people{"ashely","adam","michael","joe","mike"};
    
    print(people);
    
    // style C++ 17 or before
    auto find_mike = std::find(begin(people), end(people), "mike");
    people.erase(find_mike);
    print(people, "vector::erase: ");
    
    // non member function in C++ 20
    // (using a value to find a match with operator ==)
    size_t michaels_removed = std::erase(people, "michael");
    print(people, "michael's removed: " + std::to_string(michaels_removed) + "\n");

    // non member function in C++ 20
    // (using predicate)
    size_t people_w_a_removed = std::erase_if(people, 
                                              [](std::string name)
                                              {
                                                return name[0] =='a';  
                                              });
    print(people, "people with 'a' removed: " + std::to_string(people_w_a_removed) + "\n");
}

int main()
{
    erase_test();
    
    return 0;
}
