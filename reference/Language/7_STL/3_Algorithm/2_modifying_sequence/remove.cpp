#include <iostream>
#include <vector>
#include <algorithm>

void print_v(std::string_view title, const auto& container)
{
    std::cout << title << " [";
    for(const auto& e: container)
        std::cout << e << ", ";
    std::cout << "]\n";

}

void remove_test()
{
    std::cout << "\n\t\tremove\n\n";
    
    std::vector<int> container{1,2,3,4,12,12,5,6,12,12,7,8};
    print_v("container", container);
    
    //--------------------------------------------------
    //      erase-remove idiom
    //--------------------------------------------------
    // if we truly want to 'erase', then we cature the 'new end point' of out std::remove operatiorn
    //, which shifts all the 'values' that match (in this case 12) what we ant to remove, to the end
    auto new_end = std::remove(begin(container), end(container), 12);

    std::cout << "new end at index: " << std::distance( begin(container), new_end) << std::endl;
    print_v("container", container);
    
    // now perform the actual removal of the elements
    container.erase(new_end, end(container));
    print_v("container", container);
    
}

void remove_if_test()
{
    std::cout << "\n\t\tremove_if\n\n";
    std::vector<int> container{1,2,3,4,12,12,5,6,12,12,7,8};
    print_v("container", container);
    
    // if we truly want to 'erase', then we cature the 'new end point' of out std::remove operatiorn
    //, which shifts all the 'values' that match (in this case 12) what we ant to remove, to the end
    auto new_end = std::remove_if(begin(container), end(container), 
                                  [](auto elem)
                                  {
                                    return (elem % 2 == 0);
                                  });

    std::cout << "new end at index: " << std::distance( begin(container), new_end) << std::endl;
    print_v("after remove", container);
    
    // now perform the actual removal of the elements
    container.erase(new_end, end(container));
    print_v("after erase", container);
}

void remove_copy_if_test()
{
    std::cout << "\n\t\remove_copy_if\n\n";
    
    std::vector<std::string> people{"ashley", "adam", "michael", "joe", "mike"};
    std::vector<std::string> target(people.size()); // where I will copy stuff into
    
    print_v("people", people);
    print_v("target", target);
    
    std::remove_copy_if(begin(people), end(people), 
                        begin(target),
                        [](std::string s)
                        {
                            return (s[0] == 'm');
                        });
    std::cout << "after calling remove_copy_if ...\n";
    print_v("people", people);
    print_v("target", target);
}

int main()
{
    
    //--------------------------------------------------
    //      erase-remove idiom
    //--------------------------------------------------
    // if we truly want to 'erase', then we cature the 'new end point' of out std::remove operatiorn
    //, which shifts all the 'values' that match (in this case 12) what we ant to remove, to the end

    remove_test();
    remove_if_test();
    remove_copy_if_test();
}