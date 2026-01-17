/** Behavioral pattern: C++ Strategy Design Pattern - Changing Algorithmic Behavior
 */
#include <iostream>
#include <memory>


/*
    Now, this code is becoming a little bit more maintainable. In this case following the Single 
Responsability Principle (SRP) using inheritance for a family of similar algorithms.                                                                                                             ~~~~~~~~~~~~~~~~~~~~~~~~~~

                ISort
                  ^
        __________|___________
       |          |           |
    Insertion   Bubble    QuickSort 

    Now, we can use a 'generic_sort' function 


When to use the strategy pattern:

    When you have a 'family' of related algorithm that are interchangeable within the family
        
        - different sorts
        - different compression algoritms
        - exporting dataset to different text formats (e.g raw, json, xml)
        - different graph traversals

    When you observe that a class has multiple consitional statements 
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

int collection_size = 52;

void generic_sort( /* Container params */ )
{
    std::unique_ptr<ISort> algo{ std::make_unique<InsertioSort>() };
    if(collection_size < 16 )
        algo = std::make_unique<BubleSort>();
    
    algo->sort();
}


int main()
{   
    generic_sort( /* Container params */ ); // InsertionSort sort

    
    return 0;
}