/** STL std::forward_list | Modern Cpp Series Ep. 119
 */
#include <iostream>
#include <forward_list>

void print_list(const std::forward_list<int>& list)
{
	std::cout << "[";
	for(const auto& e:list)
		std::cout << e << ", ";
	std::cout << "]\n";
}

int main()
{
    {
        std::forward_list<int> list1{-7, -5, -2, 0, 1, 2, 3, 4, 5, 6};
        std::forward_list<int> list2{66,77,88,99};

        // splice_after:
        //          Transfers elements from another forward_list
        //
        //
        //  void splice_after( const_iterator pos, forward_list&& other )
        list1.splice_after( list1.begin(), // element after which the content will be inserted
                            list2);               // another container to transfer the content from

        print_list(list1);  // [-7, 66, 77, 88, 99, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]
                            //      ~~~~~~~~~~~~~~
        print_list(list2);  // []
    }

    {
        // NOTE: if we want to splice at the begining, we have a member function 
        // called before_begin()

        std::forward_list<int> list1{-7, -5, -2, 0, 1, 2, 3, 4, 5, 6};
        std::forward_list<int> list2{66,77,88,99};

        list1.splice_after( list1.before_begin(), // element after which the content will be inserted
        //                        ~~~~~~~~~~~~
        //                     returns an iterator to the element before beginning   
                            list2);               // another container to transfer the content from

        print_list(list1);  // [66, 77, 88, 99, -7, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]
                            //  ~~~~~~~~~~~~~~
        print_list(list2);  // []
    }
	
    {
        // void splice_after( const_iterator pos, forward_list&& other,
        //                    const_iterator first, const_iterator last )
        std::forward_list<int> list1{-7, -5, -2, 0, 1, 2, 3, 4, 5, 6};
        std::forward_list<int> list3{33,44,55,66};

        list1.splice_after(list1.before_begin(),  // element after which the content will be inserted
                            list3,                // The other list
                            begin(list3), list3.end() );
                        //  ~~~~~~~~~~~~~~~~~~~~~~~   // range of the other list

        print_list(list1);  // [44, 55, 66, -7, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]
        print_list(list3);  // [33]

    }
    
    {
        std::forward_list<int> list1{-7, -5, -2, 0, 1, 2, 3, 4, 5, 6};
        std::forward_list<int> list3{33,44,55,66};

        list1.splice_after(list1.before_begin(),  // element after which the content will be inserted
                            list3,                // The other list
                            list3.before_begin(), list3.end() );
                        //  ~~~~~~~~~~~~~~~~~~~~~~~   // range of the other list

        print_list(list1);  // [33, 44, 55, 66, -7, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]
        print_list(list3);  // []

    }
    
    {
        std::forward_list<int> list1{-7, -5, -2, 0, 1, 2, 3, 4, 5, 6};
        std::forward_list<int> list3{33,44,55,66};

        auto it3 = list3.begin();
        std::advance(it3, 2);

        list1.splice_after(list1.before_begin(),  // element after which the content will be inserted
                            list3,                // The other list
                            list3.before_begin(), it3 );
                        //  ~~~~~~~~~~~~~~~~~~~~~~~   // range of the other list

        print_list(list1);  // [33, 44, -7, -5, -2, 0, 1, 2, 3, 4, 5, 6, ]
        print_list(list3);  // [55, 66, ]

    }
    return 0;
}