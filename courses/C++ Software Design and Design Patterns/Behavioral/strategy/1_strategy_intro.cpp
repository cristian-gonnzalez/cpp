/** Behavioral pattern: C++ Strategy Design Pattern - Changing Algorithmic Behavior
 */
#include <iostream>
#include <memory>


/*
    The strategy pattern:
        Also known as the policy pattern, is a behavioral design pattern that enables selecting an algorithm at run-time. 
                                                                                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Instead of implementing a single algorithm directly, code receives run-time instructions as to which in a family of algoritms to use.
                                                                                                                  ~~~~~~~~~~~~~~~~~~~~~~~~~~

Changing algorithmic behaviour with branching (if, else or switch):

    When we execute programs, we may want to change the behaviour for many reasons:
        
        - The 'workload has changed' (e.g. number of elements to sort)
               ~~~~~~~~~~~~~~~~~~~~
        - The 'state change in the application requires adaptation'
               ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            (e.g The mode in a Game (easy, medium, hard) change based on user)
        - Our 'system has more or less cpu resources' available
               ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        - We have entererd 'some error state'.
                            ~~~~~~~~~~~~~~~~

    This is an example of choosing different behaviour based on the number of elements

template< typename _RandomAccessIterator >
void _final_insertion_sort( _RandomAccessIterator first, _RandomAccessIterator last )
{
    
    if( last - first > 16 )
    {
        std::insertion_sort( first, first + 16 );
        std::unguarded_insertion_sort( first + 16, last );
    }
    else
        std::insertion_sort( first, last );
    
}

    This is a way to change behaviour but how maintanale is this? Is it reasonable?

if( threehold < 16 )
    insertion_sort( ... );
else if( threehold >= 16  && threehold < 64)
    tim_sort( ... );
else if( threehold >= 64  && threehold < 128)
    merge_sort( ... );
else if( threehold >= 128  && threehold < 256)
    quick_sort( ... );
else if ......


    We want to be able to change behaviour at run-time but also perhaps at compile-time (using templates).

    Observe we have a family of related algoritms, operating on the same data. So one mechanism to group related
types is by using 'inheritance' (is-a relationship). So in the context of our sorting problem:

                ISort
                  ^
        __________|___________                     We can use run-time polymorphism to choose the algorithm
       |          |           |
    Insertion   Bubble    QuickSort 


Note:
    We have encapsulated the behavour (sorting) into an object

    The advangage we get with inheritance is we have some type checking (I cannot assign to anythng
outside the ISort hierarchy) adn we can easily enforce the interface with pure virtual functions

    If you are anti-OOP, we could have free functions suing functions pointers or std::function or
a functional approach using std::variant holding different function pointers.


*/

struct ISort
{
    virtual ~ISort() = default;

    virtual void sort( /* Container params */) = 0;
};

struct InsertioSort : public ISort
{
    void sort( /* Container params */) override
    {
        std::cout << "InsertionSort sort\n";
    }
};

struct BubleSort : public ISort
{
    void sort( /* Container params */)  override
    {
        std::cout << "BubleSort sort\n";
    }
};


int main()
{   
    std::unique_ptr<ISort> algo{ std::make_unique<InsertioSort>() };

    // When I run the sort here I just use run-time polymorphism and it will call the appropiate
    // sorting algorithm
    algo->sort();

    return 0;
}