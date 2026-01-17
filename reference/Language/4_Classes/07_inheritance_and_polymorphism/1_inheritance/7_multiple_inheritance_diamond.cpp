/** Multiple Inheritance: Diamond Problem
 */
#include <iostream>
#include <memory>

/*  

    A class uses multiple inheritance when it inherits from more than 
one base class at the same time.

    ┌────┐       ┌───┐
    │ A  │       │ B │ 
    └────┘       └───┘
      ↑            ↑ 
      |____________|     'is-a' relation                
            |                   
          ┌───┐
          │ C │       C is a A class and a B class      
          └───┘         

Diamond Problem:

  The goal is to model this hierarchy:

            ┌───────────┐
            │    Dog    │         
            └───────────┘         
                  ↑
             _____|______     'is-a' relation                
            |            |       
    ┌─────────┐       ┌───────────────┐
    │ Golden  │       │ Border-Collie │   <- Multiple Inheritance
    └─────────┘       └───────────────┘
            ↑            ↑ 
            |____________|     'is-a' relation                
                   |                   
             ┌───────────┐
             │ Coltriver │         
             └───────────┘         

  However, we implement this:
    
    ┌───────────┐    ┌───────────┐
    │    Dog    │    │    Dog    │         
    └───────────┘    └───────────┘         
            ↑            ↑
            |            |       
    ┌─────────┐       ┌───────────────┐
    │ Golden  │       │ Border-Collie │ 
    └─────────┘       └───────────────┘
            ↑            ↑ 
            |____________|     'is-a' relation                
                |                   
            ┌───────────┐
            │ Coltriver │         
            └───────────┘         

  Because Golden and BorderCollie both inherit from Dog 'independently', a Coltriver
contains 'two separate Dog subobjects'.

  This duplication causes ambiguity: the compiler cannot know which Dog subobject
you mean when converting Coltriver to Dog or when calling a Dog method.

*/

struct Dog
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
    {
    //   No problem when working with concrete type on the left (static dispatch)
    // since it knows what type is exaclty
    //  ^~~
        Dog dog;
        dog.bark();            // Dog::bark
        
        Golden golden;
        golden.bark();         // Golden::bark

        BorderCollie bordercollie;
        bordercollie.bark();   // BorderCollie::bark
        
        Coltriver coltriver;
        coltriver.bark();      // Coltriver::bark
    }

    {
    //   No problem when working with Base type on the left and first subclass level (dynamic dispatch)
        std::unique_ptr<Dog> dog{ std::make_unique<Dog>() };
        dog->bark();            // Dog::bark
        
        std::unique_ptr<Dog>  golden{ std::make_unique<Golden>() };
        golden->bark();         // Golden::bark

        std::unique_ptr<Dog>  bordercollie{ std::make_unique<BorderCollie>() };
        bordercollie->bark();   // BorderCollie::bark       
    }

    {
    //    Dog*  coltriver{ new Coltriver };
        //                   ^~~~~~~~~
        // error: 'Dog' is an ambiguous base of 'Coltriver'
        //                    ^~~~~~~~~~
        //   The compiler cannot decide which Dog choose (Goldern or BorderCollie)
        // since Coltriver inherits Dog twice:  Golden -> Dog and BorderCollie -> Dog
        //  
        //      ┌───────────┐    ┌───────────┐
        //      │    Dog    │    │    Dog    │         
        //      └───────────┘    └───────────┘         
        //             ↑            ↑
        //             |            |       
        //     ┌─────────┐       ┌───────────────┐
        //     │ Golden  │       │ Border-Collie │ 
        //     └─────────┘       └───────────────┘
        //             ↑            ↑ 
        //             |____________|     'is-a' relation                
        //                    |                   
        //              ┌───────────┐
        //              │ Coltriver │         
        //              └───────────┘         

        //
        // Note: Using unique_ptr has the same error but the error message is not clear
    //    std::unique_ptr<Dog>  coltriver( std::make_unique<Coltriver>() );    
    }


    return 0;
}