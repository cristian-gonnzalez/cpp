/** Function pointers: typedef
 */

#include <iostream>

typedef int (*op_cb_t)(int, int);  
  
int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int main()
{       
    // As it is a pointer, we have to point to sth
    op_cb_t op = add;
    
    std::cout << "2 + 2 = " << op(2,2) << std::endl;       // 2 + 2 = 4

    op = multiply;
    std::cout << "7 * 5 = " << op(7,5) << std::endl;       // 7 * 5 = 35

    return 0; 
}
 