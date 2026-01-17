/** const-overloading
 */
#include <iostream>
#include <vector>

/*

Problem:

  I have an object where I want to be read-only but the problem to this is that 
const makes the object inaccesible meaning that I cannot read the object.

*/

class MyList
{
    public:
        MyList()
        {
            for(size_t i = 0; i< 10; i++)
                _data.push_back( (i+1)*2 );
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
        // Cannot access the data to inspect since I have non-cons methods only
        const MyList ml;
    
        // error: assignment of read-only location 'ml.MyList::operator[](2)'
    //    ml[2] = 5;
        //      ^~~ 
        // Im modifying the object
        
        // Im NOT modifying the object
        std::cout << "[";
        for(size_t i=0; i< 10; i++)
            std::cout << ml[i] << ", ";
        //                 ^~~ 
        // error: passing 'const MyList' as 'this' argument discards qualifiers [-fpermissive]
        std::cout << "]\n";
    }

    return 0;
}
