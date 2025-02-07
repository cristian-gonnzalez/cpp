#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>


template<typename T>
void selection_sort( std::vector< T >& container )
{
    auto start = container.begin();
    auto last = container.end() - 1;
    
    for(auto it = start; it != last; it++)
        std::iter_swap( std::min_element(it, last), 
                        it);
}

template<typename T>
void bubble_sort( std::vector< T >& container )
{
    auto start = container.begin();
    auto last = container.end() - 1;
    bool sorted;
    
    for(auto it = start; it != last; it++)
    {
        sorted = true;
        for(auto read = last; read > it; read--)
        {
            auto prev = read - 1;
            if( *prev > *read )
            {
                sorted = false;
                std::iter_swap(prev, read);
            }
        }
        if( sorted )
            break;
    }
}


template<typename T>
void insertion_sort( std::vector< T >& container )
{
    auto start = container.begin();
    auto last = container.end();
    
    for(auto it = start + 1; it != last; ++it)
        std::rotate( std::upper_bound(start, it, *it),
                     it,
                     it + 1 );
}


template<typename T>
void shell_sort( std::vector< T >& container )
{
    auto start = container.begin();
    auto last = container.end();
    int gap = std::distance(start, last) / 2;

    for(int g = gap; g > 0; g /=2 )
    {
        auto gap_it = std::next(start, g);
        for(auto read = gap_it; read < last; read++ )
        {
           for(auto it = read; it >= gap_it; it = std::prev(it, g) )
           {    
                auto prev = std::prev(it, g);
                if(*prev > *it)
                    std::iter_swap(prev, it);    
           }
        }        
    }        
}


void _merge_sort_wrapper( auto start_it, auto last_it )
{
    if(std::distance(start_it, last_it) <= 1 )
        return;
        
    auto mid_it = std::next( start_it, 
                            ( std::distance(start_it, last_it) / 2 ) );
    
    _merge_sort_wrapper( start_it, mid_it );
    _merge_sort_wrapper( mid_it, last_it );
    
    // 	mid_it is the end of the first sorted range and the beginning of the second
    std::inplace_merge(start_it, mid_it, last_it);
}

template<typename T>
void merge_sort( std::vector< T >& container )
{
    auto start_it = container.begin();
    auto last_it = container.end() - 1;
    _merge_sort_wrapper(start_it, last_it);
}


template<typename T>
void sort_test( std::string_view title, std::function< void(std::vector< T >&) > sort_cb, std::vector< T > container )
{
    std::cout << "\tSort test: " << title << std::endl;
    auto print_v = [](std::string_view message, auto v)
    {
        std::cout << message << ": [";
        for(const auto& e: v)   
            std::cout << e << ", ";
        std::cout << "]\n";
    };
    
    print_v("container", container);
    sort_cb(container);
    print_v("sorted   ", container);
    
    std::cout << std::endl;
}

#define TEST( sort_cb, container ) \
{ \
    sort_test( #sort_cb, sort_cb, container ); \
}


int main()
{
    std::vector<int> v1{3,5,1,7,4,8,4,6};
    std::vector<char> v2{'d','b','g','f','a','c','h','e'};

    TEST( bubble_sort<int>, v1 );
    TEST( bubble_sort<char>, v2 );
    TEST( selection_sort<int>, v1 );
    TEST( selection_sort<char>, v2 );
    TEST( insertion_sort<int>, v1 );
    TEST( insertion_sort<char>, v2 );
    TEST( shell_sort<int>, v1 );
    TEST( shell_sort<char>, v2 );
    TEST( merge_sort<int>, v1 );
    TEST( merge_sort<char>, v2 );

/*  Output:

        Sort test: bubble_sort<int>
    container: [3, 5, 1, 7, 4, 8, 4, 6, ]
    sorted   : [1, 3, 4, 4, 5, 6, 7, 8, ]

        Sort test: bubble_sort<char>
    container: [d, b, g, f, a, c, h, e, ]
    sorted   : [a, b, c, d, e, f, g, h, ]

        Sort test: selection_sort<int>
    container: [3, 5, 1, 7, 4, 8, 4, 6, ]
    sorted   : [1, 3, 4, 4, 5, 7, 8, 6, ]

        Sort test: selection_sort<char>
    container: [d, b, g, f, a, c, h, e, ]
    sorted   : [a, b, c, d, f, g, h, e, ]

        Sort test: insertion_sort<int>
    container: [3, 5, 1, 7, 4, 8, 4, 6, ]
    sorted   : [1, 3, 4, 4, 5, 6, 7, 8, ]

        Sort test: insertion_sort<char>
    container: [d, b, g, f, a, c, h, e, ]
    sorted   : [a, b, c, d, e, f, g, h, ]

        Sort test: shell_sort<int>
    container: [3, 5, 1, 7, 4, 8, 4, 6, ]
    sorted   : [1, 3, 4, 4, 5, 6, 7, 8, ]

        Sort test: shell_sort<char>
    container: [d, b, g, f, a, c, h, e, ]
    sorted   : [a, b, c, d, e, f, g, h, ]

        Sort test: merge_sort<int>
    container: [3, 5, 1, 7, 4, 8, 4, 6, ]
    sorted   : [1, 3, 4, 4, 5, 7, 8, 6, ]

        Sort test: merge_sort<char>
    container: [d, b, g, f, a, c, h, e, ]
    sorted   : [a, b, c, d, f, g, h, e, ]

*/


    return 0;

}