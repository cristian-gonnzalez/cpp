#include <iostream>

template<typename T, std::size_t Size>
class Container
{
    private:
        T *m_data;

    public:
        Container()
        {
            m_data = new T[Size]; 
        }
        ~Container()
        {
            delete[] m_data;
        }
        
    
    static T m_variable;
};

// static member varible, telling the compiler 'hey we exist'
template<typename T, std::size_t Size>
T Container<T, Size>::m_variable;

/* The compiler will generate the following code:

int Container<int, 5>::m_variable;
int Container<int, 7>::m_variable;

 */

int main()
{
    // c1 y c3 will share the same static member variable
    Container<int, 5> c1;
    Container<int, 7> c2;
    Container<int, 5> c3;

    Container<int, 5>::m_variable = 4;
    Container<int, 7>::m_variable = 157;

    std::cout << Container<int, 5>::m_variable << std::endl;
    std::cout << Container<int, 7>::m_variable << std::endl;
    
    /*
      OUTPUT:
      4
      157
    */

    return 0;
}