 /**


 */

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

void random_access_iterator()
{
    std::cout << "\n\n\t\tRandom access\n\n";

    std::vector<int> container{99,2,3,4,5,6};

    // write
    auto it2 = container.begin();
    *it2 = 1;
    std::cout << "write: " << *it2 << std::endl;
    // read
    auto it = container.begin();
    std::cout << "read: " <<  *it << std::endl;
    // increment
    it++;
    std::cout << "Increment: " << *it << std::endl;
    // decrement
    it--;
    std::cout << "decrement: " << *it << std::endl;
    // random access
    it+=5;
    std::cout << "random_access: " << *it << std::endl;
    it-=2;
    std::cout << "random_access: " << *it << std::endl;

}


void bidirectional_iterator()
{
    std::cout << "\n\n\t\tBidirectional\n\n";
    
    std::list<int> container{99,2,3,4,5,6};

    // write
    auto it2 = container.begin();
    *it2 = 1;
    std::cout << "write: " << *it2 << std::endl;
    // read
    auto it = container.begin();
    std::cout << "read: " <<  *it << std::endl;
    // increment
    it++;
    std::cout << "Increment: " << *it << std::endl;
    // decrement
    it--;
    std::cout << "decrement: " << *it << std::endl;
    /* ERROR
    // random access
    it+=5;
    std::cout << "random_access: " << *it << std::endl;
    it-=2;
    std::cout << "random_access: " << *it << std::endl;
    */
}




void forward_iterator()
{
    std::cout << "\n\n\t\tForward\n\n";
    
    std::forward_list<int> container{99,2,3,4,5,6};

    // write
    auto it2 = container.begin();
    *it2 = 1;
    std::cout << "write: " << *it2 << std::endl;
    // read
    auto it = container.begin();
    std::cout << "read: " <<  *it << std::endl;
    // increment
    it++;
    std::cout << "Increment: " << *it << std::endl;
    /* ERROR
    // decrement
    it--;
    std::cout << "decrement: " << *it << std::endl;
    // random access
    it+=5;
    std::cout << "random_access: " << *it << std::endl;
    it-=2;
    std::cout << "random_access: " << *it << std::endl;
    */
}

int main()
{
    random_access_iterator();   
    bidirectional_iterator();
    forward_iterator();
    return 0;
}