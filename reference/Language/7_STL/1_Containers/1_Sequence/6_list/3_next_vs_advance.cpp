/** STL std::list | Modern Cpp Series Ep. 118
 */
#include <iostream>
#include <list>

void print_list(const std::list<int>& list)
{
	std::cout << "[";
	for(const auto& e:list)
		std::cout << e << ", ";
	std::cout << "]\n";
}

int main()
{
	std::list<int> my_list{1,2,3,4};

    //
    // Inserting in the middle of the list
    //

    // Sets the position of the iterator at the begining
    // Now we will advance our iterator a specific number of steps.
	auto start = cbegin(my_list);
          //     ^ 
          // constant

    // The Iterator library gives function to operator over containers
    // such as begin, end, next and advance
    
    {
        // std::next: 
        //      Increment an iterator
        //
        //                                 n                         
        //                          ~~~~~~~~~~~~~~~~
        auto it = std::next( start, my_list.size()/2 );
    //       ^    ~~~~~~~~~      
    //       |    Advance the iterator to the middle 
    // Return an InputIt at the n position

        my_list.insert( it, 9  );

        print_list(my_list); // [1, 2, 9, 3, 4, ]

    }
    
    {
        auto it = start;

        // std::advance:
        //      Advances an iterator by given distance. It does not return a value
        //
        std::advance( it, my_list.size()/2  );
                   //     ~~~~~~~~~~~~~~~~
                   //    Advance this iteratrot to the middle position
                   
        std::cout << "The midle is " << *it << std::endl; // The midle is 9
        //                              ^
        //                          de-reference our iterator
    }
    

	return 0;
}