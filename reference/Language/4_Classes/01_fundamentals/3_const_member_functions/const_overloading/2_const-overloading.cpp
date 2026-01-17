/** const-overloading
 */
#include <iostream>
#include <vector>

/*
  const overloading is when you have an inspector method (const method) and a mutator 
method (non-const methd) with the same name and the same number of and types of parameters.

  The two distinct methods differ only in that the inspector is const and the mutator 
is non-const.

  The most common use of const overloading is with the subscript operator []. The rule of 
thumb: subscript operators often come in pairs.

        const int& operator[](size_t idx) const;        ->     inspector
        int& operator[](size_t idx);                    ->     mutator 
        
  The const subscript operator returns a 'const T&', so the compiler will prevent callers 
from inadvertently mutating/changing the T object. 

  The non-const subscript operator returns a non-const T&, which is your way of telling 
your callers (and the compiler) that your callers are allowed to modify the T object.

*/

class MyList
{
    public:
        MyList()
        {
            for(size_t i = 0; i< 10; i++)
                _data.push_back( (i+1)*2 );
        }

        // const subscript  a[idx]  
        const int& operator[](size_t idx) const
        {
            return _data[idx];
        }

        // non-const subscript  a[idx]  
        int& operator[](size_t idx)
        {
            return _data[idx];
        }
        
    private:
        std::vector<int> _data{10};
};


int main()
{
    {
        MyList ml;
        
        ml[2] = 5;
        //    ^~~ 
        // Im modifying the object
        
        std::cout << "[";
        for(size_t i=0; i< 10; i++)
            std::cout << ml[i] << ", ";
        //                 ^~~ 
        // Im NOT modifying the object
        std::cout << "]\n";  // [10, 2, 5, 6, 8, 10, 12, 14, 16, 18, ]
    }


    {
        // I just want to be read-only object
        const MyList ml;

        // error: assignment of read-only location 'ml.MyList::operator[](2)'
    //    ml[2] = 5;
        //      ^~~ 
        // Im modifying the object
        
        std::cout << "[";
        for(size_t i=0; i< 10; i++)
            std::cout << ml[i] << ", ";
        //                 ^~~ 
        // Im NOT modifying the object
        std::cout << "]\n";  // [10, 2, 4, 6, 8, 10, 12, 14, 16, 18, ]
    }

    return 0;
}
