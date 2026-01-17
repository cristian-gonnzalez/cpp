/** lvalue references
 */

#include <iostream>

void set_value_to_99(int& change_me)
{
    change_me = 99;
}

int main()
{   
    {
        int i = 10;    // 'i' is an lvalue
        int& ref = i;  // 'ref' is an lvalue-reference

        set_value_to_99(i);
    }    
    
   {
      // int& ref = 10;
      //          ^~  
      // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
      //
      // An lvalue reference implies that you can modify the object and 10 can not be changed
      // since it is a number. 
      // 
      // Although we pass an rvalue temporary object, makes no sense to allowed this
      // since we will modify sth that is temporary and would be destroyed any moment

      // set_value_to_99(10);
      //                 ^~ 
      // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'


      const int& ref2 = 10;
      //   This is allowed by the compiler since I will not modify 10
      //
      // Note:  
      //   In this case, the compiler materialize a temp-object to hold the number 10 (see assembly)
      //
      //   Equivalent:
      //
      //        int temp = 10;
      //        const int& ref2 = temp;
                      
   }


    return 0; 
}
 