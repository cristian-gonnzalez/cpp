/** const-overloading
 */
#include <iostream>
#include <memory>
#include <vector>

/*
  When a user of your UDTList class calls the subscript operator, the compiler selects which 
overload to call based on the constness of their UDTList. 

    If the caller has a UDTList a or UDTList& a, then a[3] will call the non-const subscript operator
and the caller will end up with a non-const reference to a T:

*/

struct UDT
{
    UDT(int i)
    : i_{i}
    {
    }

    int inspect() const
    {
        return i_;
    }

    void mutate()
    {
        i_ = (i_ + 1) * 2;
    }

    int i_{0};

};

struct UDTList
{
    public:
        UDT& operator[](size_t idx)
        {
            return _data[idx];
        }

        const UDT& operator[](size_t idx) const
        {
            return _data[idx];
        }

        void add(int v)
        {
            _data.emplace_back(v);
        }

    private:
        std::vector<UDT> _data{};
};



int main()
{
    
    UDTList ncl;
//  ^~~~~
//  Will call the non-const operator[]
    
    ncl.add(1);
    ncl.add(2);
    ncl.add(3);
    ncl.add(4);

    ncl[3].mutate();
    ncl[3].inspect(); 

    const UDTList& cl = ncl;
//  ^~~~~
//  Will call the const operator[]

    // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
    //cl[3].mutate();
    //~~~~~~~~~~~~^~
    
    cl[3].inspect(); 

    return 0;
}
