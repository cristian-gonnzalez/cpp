// Since C++ 17

#include <iostream>

// Defining template param list with default values
template<typename T=int, std::size_t Size=10>
class Container
{
    private:
        T *m_data;

    public:
        Container()
        {
            m_data = new T[Size]; 
            std::cout << Size << std::endl;
        }
        ~Container()
        {
            delete[] m_data;
        }
};


int main()
{
    Container<int, 7> c1;

    // Using default values
    Container c2;
    
    return 0;
}