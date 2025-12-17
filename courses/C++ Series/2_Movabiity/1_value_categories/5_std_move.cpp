/** std::move
 */

#include <iostream>

/*
std::move:

  std::move is used to indicate that an object t may be "moved from", i.e. 
allowing the efficient transfer of resources from t to another object.

        Defined in header <utility>
        template< class T >
        typename std::remove_reference<T>::type&& move( T&& t ) noexcept;

  Important:
    std::move does NOT actually move anything. It simply performs a cast to an rvalue reference (xvalue).
  This 'enables' move semantics but does not perform the move itself.

    It is exactly equivalent to: 
        
        static_cast<T&&>(t)


- Moving vs Copying:

    Instead of making copies, we are actually going to be moving the data: that
  is transferring the ownership from one object to another -- stealing the resource 
  from an object --. 

  For ex:

        The location where we are actually going to store sth
            lvalue
                ^~
    std::string s1 = "Long string .....";
                    ^~~~~~~~~~~~~~~~~~~  rvalue
    std::string s2 = s1;                   it's sth that doesnt have any sort of 
                ^                     named storage, no location but it is sth 
        invoke the copy constructor     that has to be allocated somewhere (temp object)


    void function(std::string s);  // pass by value

    Calling:

        function("A string");
                 ^~~~~~~~~~
            uses the std::string(const char*) constructor 
          to create a temporary copy and pass to function. 
          This is very inneficient

    Sometimes we do NOT want an extra copy — we want to transfer ownership. Move semantics 
  allows us to avoid making a copy but transfer owernship. So we are moving the lifetime of 
  some object.

    To indicate that sth will be moved, use the rvalue reference

            void function(std::string&& s);

*/

int main()
{   
    // Note:
    //   s1 is contructed with 'copy-initialization'
    //   The compiler will implicity call std::string s1("copy construct me");
    std::string s1 = "copy construct me";
    
    {
        std::string s2;
        std::cout << "s1: " << s1 << std::endl  // s1: copy construct me
                  << "s2: " << s2 << std::endl;  // s2: 

        s2 = s1; // copy assignment
        
        std::cout << "s1: " << s1 << std::endl   // s1: copy construct me 
                  << "s2: " << s2 << std::endl;  // s2: copy construct me
        
    }

    {
        std::string s2;
        std::cout << "s1: " << s1 << std::endl  // s1: copy construct me
                  << "s2: " << s2 << std::endl;  // s2: 

        // std::move allows us to 'adopt' or 'steal' the value
        s2 = std::move( s1 );
    //  ^~               ^~
    //  |            It is losing the resource but it will be left in some 'valid state' 
    //  |                                                                   ^~~~~~~~~~~  
    // Gets the resources                                            It means you dont have to
    //                                                             worry about this object 
    //                                                             crashing the program       

        // Equivalent:
        // s2 = static_cast< std::string&& >(s1);
        //      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //         Explicity say this is an rvalue reference so use the move assigment operator    
        //       and steal this resource 
        
        // Note here, s1 is still some 'valid' value.
        // Maybe it strores 'nullptr' in the data in the string
        // but it still exists
        std::cout << "s1: " << s1 << std::endl  // s1: 
                  << "s2: " << s2 << std::endl;  // s2: copy construct me
                //             ^~
                // We have transferred succesfully the resources and avoided making
                // any copues    
    }
     return 0;
} 