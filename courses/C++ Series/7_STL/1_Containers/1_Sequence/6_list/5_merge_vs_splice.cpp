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
    {
        std::list<int> list1{0,1,2,3,4,5,9};
	    std::list<int> list2{2,4,6,8,10};

        // merge:
        //      Merges two sorted lists into one sorted list.
        //                 ~~~~~~~~~~~~   
        //      The lists should be sorted into ascending order.
        //
        // IMPORTANT:
        //      Merge moves the second list into the first list so the second 
        // list becomes empty.
        list1.merge(list2);
        
        print_list(list1); // [0, 1, 2, 2, 3, 4, 4, 5, 6, 8, 9, 10, ]
        print_list(list2); // []

    }

    {
        // splice:
        //      Transfers elements from one list to another
        //      I can specify how many elements I want to transfer one list to 
        //  another
        //
        
        {
            // void splice( const_iterator pos, 
            //              list&& other );
            //                  ^^ Transfer ownership
            //
            std::list<int> list1{0,1,2,3,4,5,9};
            std::list<int> list2{15,25,35,45};
        
            // It is going to destroy or transfer ownership of our actual list3 leaving
            // list3 empty     
            list2.splice( end(list1),    // The position where to insert the other list
                          list2 );       // The other list

            print_list( list1 );  // [0, 1, 2, 3, 4, 5, 9, 15, 25, 35, 45, ]
            print_list( list2 );  // []
        }

        {
            //    void splice( const_iterator pos, 
            //                 list&& other,
            //                     ^^ Transfer ownership
            //                 const_iterator first, const_iterator last );
            //                                ~~~~~~                ~~~~
            //                            I can specify a range of the other list
        
            std::list<int> list1{0,1,2,3,4,5,9};
            std::list<int> list3{15,25,35,45};
            //                         ~~~~~  
            //                         ^
            //                  Advance two position
            auto list3_it = list3.begin();
            std::advance( list3_it, 2); 

            list1.splice( end(list1),      // The position where to insert the other list
                        list3,             // The other list
                        list3_it,          // The other list start pos
                        end(list3) );      // The other list final range
                        
            print_list( list1 );  // [0, 1, 2, 3, 4, 5, 9, 35, 45, ]
            print_list( list3 );  // [15, 25, ]
        }
    }    
    
    return 0;
}