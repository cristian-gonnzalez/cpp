/** noncopyable
 */
#include <iostream>
#include <memory>

/*  
    noncopyable example
*/

struct noncopyable
{
        virtual ~noncopyable() = default;
        noncopyable() = default;

        noncopyable(const noncopyable& ) = delete;
        noncopyable& operator=(const noncopyable& ) = delete;
};

struct Dog : public noncopyable
{
        virtual ~Dog() = default;
        
        virtual void bark()
        {
            std::cout << "Dog::bark\n";
        }
};

struct Golden : public Dog
{
        virtual ~Golden() = default;
        
        virtual void bark() override
        {
            std::cout << "Golden::bark\n";
        }
};

struct BorderCollie : public Dog
{
        virtual ~BorderCollie() = default;
        
        virtual void bark()  override
        {
            std::cout << "BorderCollie::bark\n";
        }
};


struct Coltriver : public Golden, BorderCollie
//                        ^~~~~~  ^~~~~~~~~~~~
//                        Multiple Inheritance 
{
        ~Coltriver() = default;
        
        void bark() override
        {
            std::cout << "Coltriver::bark\n";
        }
};


int main()
{
//   No problem when working with concrete type on the left (static dispatch)
// since it knows what type is exaclty
//  ^~~
    Dog dog;
    dog.bark();            // Dog::bark

//    Dog dog2 = dog;
    //         ^~~
    // error: use of deleted function 'Dog::Dog(const Dog&)'
    // note: 'Dog::Dog(const Dog&)' is implicitly deleted because the default definition would be ill-formed:
    // error: use of deleted function 'noncopyable::noncopyable(const noncopyable&)'

    Golden golden;
    golden.bark();         // Golden::bark

//    Golden golden2 = golden;
    //               ^~~~~~
    // error: use of deleted function 'Golden::Golden(const Golden&)'
    // note: 'Dog::Dog(const Dog&)' is implicitly deleted because the default definition would be ill-formed:
    // error: use of deleted function 'noncopyable::noncopyable(const noncopyable&)'
    
 
    return 0;
}