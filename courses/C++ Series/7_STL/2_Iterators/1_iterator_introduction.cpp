#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

/*
    The idea is you have some collection such as an array, a tree and you want to transverse this data
structure. 


    [ , , , , ]                         []
                                       /  \
                                      []   []
                                    /  | \
                                   [] [] [] 

    You ace some consistent or unifor way to transverse a container structure

*/

void iterations()
{
    std::vector<int> vec{1,2,3,4,5};

    // raw loop: we need to know the interface to iterate over the data structure.
    // If the data structure is a list, tree or has_map, we need to know how to iterate
    std::cout << "Raw loop: [";
    for(size_t i=0; i<vec.size(); i++)
        std::cout << vec[i] << ",";
    std::cout << "]\n";

    // iterator form (c++ 03)
    // Iterators are a behavioral desing pattern describing how to move through a collection.
    // They show 'intent' for how to move through a data structure more clearly.
    std::cout << "C++98 style iteration loop: [";
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << ",";
    std::cout << "]\n";

    // typically a good use for auto
    std::cout << "C++98 style iteration loop (w 'auto'): [";
    for(auto it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << ",";
    std::cout << "]\n";

    // range-based loop 
    // NOTE: the compiler translate this syntax into a 'iterator form'. So we are using iterators implicity.
    std::cout << "range-for loop: [";
    for(const auto& e: vec)
        std::cout << e << ",";
    std::cout << "]\n";


   std::unordered_map<std::string, int> umap{ {"one", 1},
                                              {"two", 2},
                                              {"three", 3},
                                              {"four", 4} };

    // we know that unoreder_map is a hash_table with linked list so:
    //
    //   - how can we iterate over?
    //   - Should be visit each bucket and iterate over the bucket?
    //
    // As we use iterators and it is a design pattern that abstract the way the iterator navigates through the 
    // data structure, we dont have to worry. We just use the iterator as an array. For ex:
    std::cout << "range-for loop: [";
    for(const auto&e: umap)
        std::cout << "("<< e.first << " -> "<< e.second << "), ";
    std::cout << "]\n";
                        


}

void operations()
{
    std::vector<int> vec{1,2,3,4,5,6};

    auto it = vec.begin();
    std::advance(it, 2);
    std::cout << "3?: " << *it << std::endl;

    int distance = std::distance(it, vec.end());
    std::cout << "distance from 3 to the end(): " << distance << std::endl;
    
}


int main()
{   
    iterations();
    operations();
    return 0;
}