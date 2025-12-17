#include <iostream> 

struct Value
{
    int m_result1{0};
    float m_result2{0.0f};

    int operator()(int result)
    {   
        m_result1 = result;
        return result;
    }

    float operator()(float result)
    {   
        m_result2 = result;
        return result;
    }
};

int main()
{
    Value function_obj;

    function_obj(42);
    function_obj(42.7f);

    std::cout << function_obj.m_result1 << ", "
              << function_obj.m_result2 << std::endl;

    return 0;
}