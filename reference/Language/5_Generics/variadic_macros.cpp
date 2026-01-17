#include <iostream>


#define LOG(...) write(__VA_ARGS__)


template<typename ...Args>
void write(Args&& ...values)
{

    (..., (std::cout << values << std::endl)); // pack fold expression c++ 17
}

int main()
{
    write(0, 21, "hola");
    return 0;
}
