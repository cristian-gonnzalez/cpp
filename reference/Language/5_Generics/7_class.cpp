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
};

/* Template is a tool that generates code. In this example, will be instanciating these classes

template<>
class Container<int, 5>
{
  
  private: 
  int * m_data;
  
  public: 
  inline Container()
  {
    this->m_data = new int[5UL];
  }
  
  inline ~Container() noexcept
  {
    delete[] this->m_data;
  }
  
};

template<>
class Container<int, 7>
{
  
  private: 
  int * m_data;
  
  public: 
  inline Container()
  {
    this->m_data = new int[7UL];
  }
  
  inline ~Container() noexcept
  {
    delete[] this->m_data;
  }
  
};

template<>
class Container<float, 10>
{
  
  private: 
  float * m_data;
  
  public: 
  inline Container()
  {
    this->m_data = new float[10UL];
  }
  
  inline ~Container() noexcept
  {
    delete[] this->m_data;
  }
  
};

 */

int main()
{
    Container<int, 5> c1;
    Container<int, 7> c2;
    Container<float, 10> c3;
    return 0;
}