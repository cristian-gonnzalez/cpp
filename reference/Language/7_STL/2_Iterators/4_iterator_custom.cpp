#include <iostream>
#include <algorithm>

// Fixed size array that will allocate memory on the heap
template<
    typename T,
    size_t SIZE
> 
class FixedSizeArray
{
    public:
        /**
         *  Iterator implementation
         *
         **/ 

        // Iterator subclass
        // The iterator is a nested class for our specific datatype
        //
        // We dont wanto to be able to create the iterator other than from our 'begin' and 'end' function
        struct iterator {
                // this using is done by convention
                
                // Iterator tags
                // NOTE: We could add more power to this paticular iterator, but for now I will define it 
                //       as a std::forward_iterator
                //       We might use these tags appropriaterly for various algorithms and efficiency.
                //
                // NOTE: We use also now have iterator concepts.
                //
                // NOTE: If we change this tag, we must implement '--' so you can move forwartds and 
                //       backwards with your iterator
                //
                // Properties of out iterator
                using Category         = std::forward_iterator_tag;
                using Distance         = std::ptrdiff_t; // this tell us how many bytes we need to jump to get the next element
                // 'Shorthand' so we dont make mistakes
                using value_type       = T;
                using Pointer          = T*;
                using Reference        = T&;

                // Iterator constructor
                // When we create the iterator, we need to have it hand us a specific location 
                // as to where it 'starts' from.
                //
                // NOTE: We could potentially supply other parameters, and in an 'array' based
                //       data structure have it index into a specific location.
                iterator(Pointer ptr)
                :m_ptr{ptr}
                {}
                ~iterator()
                {}

                // Unary 'start' operator for dereferencing (thus no arguments)
                // So we just returm the dereferenced pointer, thus retrieving our
                // index.
                Reference operator*() const
                {
                    // T* p; *p
                    // 'dereference' unary operator
                    // get back the 'thing' (actual data)  that out iterator is pointing to.
                    return *m_ptr;
                }

                // obj->type
                Pointer operator->()
                {
                    return m_ptr;
                }

                // Pre-increment operator operators directly on the 'thing' that is
                // modifying, in this case our pointer.
                //
                // ++it
                iterator operator++()
                {
                    ++m_ptr;
                    return *this;
                }

                // Post-increment returns us a copy of the modified value
                //
                // it++
                iterator operator++(T)
                {
                    iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }

                // test if two iterators are equal
                friend bool operator==(const iterator& a, const iterator& b) 
                {
                    return a.m_ptr == b.m_ptr;
                }

                friend bool operator!=(const iterator& a, const iterator& b) 
                {
                    return a.m_ptr != b.m_ptr;
                }

            private:
                // Iterators needs to keep track of its location
                //
                // NOTE: This could be a simple 'int' for our data type. It just depends
                //       on the properties of our container.
                Pointer m_ptr;
        };

        /**
         * Iterator member function implementation 
         * 
         * Return pointers to the begining and end.
         * These two functions are needed in order for transformation of range-based
         **/
        
        iterator begin()
        {
            return iterator(&m_data[0]);
        }

        // Observe we are '1' past or otherwise beyond our container
        iterator end()
        {   
            return iterator(&m_data[m_size]);
        }


    private:
        // member variable of class
        T* m_data{nullptr};
        size_t m_size{0};
    
    public:
        FixedSizeArray()
        {
            m_data = new T[SIZE];
            m_size = SIZE;
        }
        ~FixedSizeArray()
        {
            delete[] m_data;
            m_data = nullptr;
        }

        T& operator[](const size_t index) const
        {
            if( index < 0 || index >= m_size )
                throw "Index out of bounds";
            return m_data[index];
        }

        size_t size() const {
            return m_size;
        }


};

int main()
{
    FixedSizeArray<int, 10> container;
    container[0] = 1;
    container[1] = 2;
    container[2] = 3;
    container[3] = 4;

    // nothing wrong with this
    std::cout << "Raw loop: [";
    for(size_t i=0; i<container.size(); i++)
        std::cout << container[i] << ", ";
    std::cout << "]\n";

    // we need to implement iterators however in order to use range-based loop
    std::cout << "range-for loop: [";
    for(const auto& e: container)  
        std::cout << e << ", ";
    std::cout << "]\n";

    std::cout << "C++98 style iteration loop: [";
    // we need to implement iterators
    for(FixedSizeArray<int, 10>::iterator it=container.begin(); it != container.end(); it++)
        std::cout << *it << ", ";
    std::cout << "]\n";

    // iterators also will give us access to std::algoritm
    std::cout << "std::algorithm loop: [";
    std::for_each(container.begin(),
                  container.end(),
                  []( const int e) 
                  {
                    std::cout << e << ", ";
                  } );
    std::cout << "]\n";
    
    return 0;
}