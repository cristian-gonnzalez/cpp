/** STL std::deque | Modern Cpp Series Ep. 120
 */
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>

void print_data(const std::deque<int>& data)
{
    std::cout << "deque: [";
    std::for_each(std::begin(data), std::end(data),
                  [](const int& n)
                  {
                        std::fputs(std::to_string(n).c_str(), stdout );   
                        std::fputs(", ", stdout );   
                  });
                  
    std::cout << "]\n";
}

int main()
{
    std::deque<int> dq1{1,2,3,4};
    print_data(dq1);
    int third = dq1[2];
    std::cout << "third: " << third << std::endl;

    auto it = dq1.begin();
    it++;
    it++;
    dq1.insert( it, 500 );
    print_data(dq1);

    auto end = dq1.end();
    int distance = std::distance(it, end);
    
    it = dq1.begin();
    std::advance(it, distance);
    dq1.insert(it, 7);
    print_data(dq1);

    dq1.push_back(123);
    dq1.push_front(999);
    print_data(dq1);
    return 0;
}