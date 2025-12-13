/** Friend declaration
 */
#include <iostream>

/*
Friend declaration
    We can apply to functions and classes as well.

    The friend declaration appears in a class body and grants a function or another class access to private and protected members 
 of the class where the friend declaration appears.
    
*/

class PrivateSecurityData
{
    private:
        int _passcode;

    // These are my friends: class
    friend class UDT;       //  -> This means that UDT can access to private/protected members
};

class UDT 
{
    public:
    UDT()
    : _private_var{9}, _data{} 
    {
        _data._passcode = 7;
        //    ^~~~~~~~~
        //    private variable of UDT
    }
    
    private:
        int _private_var;
        PrivateSecurityData _data;

    // These are my friends: function
    friend void print_udt_private_var(const UDT& u); 
};

void print_udt_private_var(const UDT& u)
{
    std::cout << u._private_var << std::endl;
}
    

int main(int argc, char* argv[])
{
    UDT u;
    print_udt_private_var(u);

    return 0;
}