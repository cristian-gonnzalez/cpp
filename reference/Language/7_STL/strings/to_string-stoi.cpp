#include <iostream>
#include <string>
#include <sstream>


// udt class
struct GameCharacter
{
    int level{-1};
    std::string name{"unknown"};
};

// writing my ouwn udt to_string function definition
std::string to_string(GameCharacter c)
{
    // Here goes your serialization code

    return "{ 'name': '" + c.name + "' , level: " + std::to_string( c.level ) + " }";
}




void string_to_number()
{
    std::string s1 = "+45";
    std::string s2 = "   -45";
    std::string s3 = "4.5";

    // string to integer function
    int is1 = std::stoi(s1);
    int is2 = std::stoi(s2);
    int is3 = std::stoi(s3);
  
    std::cout << is1 << std::endl; // 45
    std::cout << is2 << std::endl; // -45
    std::cout << is3 << std::endl; // 4   /* as it is string to integer function, it is just going to truncate. It is not rounding up */
  
    // string to float function
    float fs3 = std::stof(s3);
    std::cout << fs3 << std::endl; // 4.5
  
    std::string base16 = "A0";
    /*
     Error 'std::invalid_argument' what():  stoi
     We are working with base 10 by default
    int ibase16 = std::stoi(base16);
    */
    int ibase16 = std::stoi(base16, nullptr, 16);   
    std::cout << ibase16 << std::endl; // 160

    std::string s4 = "    -45";
    std::size_t pos;
    int is4 = std::stoi(s4, &pos);
    std::cout << is4 << "\tcharacters processed: " << pos << std::endl; // 160

    // stringstream with stoi functions for a calculator
    std::string expr =  "54 + 46";
    std::stringstream ss{expr};

    std::cout << "ss.str(): " << ss.str() << std::endl;

    int op1, op2;
    std::string token;

    ss >> token;
    op1 = std::stoi( token );

    ss >> token; // '+' sign

    ss >> token;
    op2 = std::stoi( token );

    std::cout << "op1 + op2? is " << (op1 + op2) << std::endl;

}

void number_to_string()
{
    std::string s1 = std::to_string(54);
    std::string s2 = std::to_string(3.14f);

    std::cout << s1 << std::endl; // 
    std::cout << s2 << std::endl;

    /* OUTPUT:
        54
        3.140000
     */

    GameCharacter gc;
    std::cout << to_string( gc ) << std::endl; 
    
}

int main()
{
    string_to_number();
    number_to_string();

    return 0;
}