/** Behavioral pattern: C++ Strategy Design Pattern - Changing Algorithmic Behavior
 */
#include <iostream>
#include <memory>


/*
    The strategy pattern:
        Also known as the policy pattern, is a behavioral design pattern that enables selecting an algorithm at run-time. 
                                                                                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Instead of implementing a single algorithm directly, code receives run-time instructions as to which in a family of algoritms to use.
                                                                                                                  ~~~~~~~~~~~~~~~~~~~~~~~~~~
 
             ----------                      -------------                                                         
            |  Contex  |<>------------------|  IStrategy  |          
            |----------|                    |-------------|
            |          |        virtual = 0 | + execute() |    
             ----------                      --------------     
    The context is some                             ^              
 object that uses the              _________________|_______________
 pattern                          |                                 |
                         ---------------------             ---------------------                                                        
                        |  ConcreteStrategyA  |           |  ConcreteStrategyB  |          
                        |---------------------|           |---------------------|
                        | + execute()         |           | + execute()         |
                         ---------------------             ---------------------  



*/


// just the interface we want to enforce, for the diferent
// behavious (i.e. part of the strategy pattern)
struct ICombat
{
    virtual ~ICombat() {};

    virtual void execute() = 0;
    //                     ~~~  
    //                must be implemented. We enforce the different behaviour
};

struct NoCombat : public ICombat
{
    void execute()
    {
        std::cout << "NoCombat::execute()\n";
    }
};

struct MeleeCombat : public ICombat
{
    void execute()
    {
        std::cout << "MeleeCombat::execute()\n";
    }
};


// The context
class Orc
{
    public:
        Orc()
        {
            _combat_strategy = std::make_unique<NoCombat>();
        }

        // NOTE:
        //    The combat stratey is being called to execute, this means that there is no  
        // swithc statements or if or any conditionals
        // 
        //    The strategy is helping us avoing doing basicallyt this:
        //
        //    if(....)
        //    {
        //    }
        //    else if( ... )
        //    {
        //    }
        //
        void do_actions()
        {
            _combat_strategy->execute();
        }

        void set_combat_strategy( std::unique_ptr<ICombat>&& rvalue )
        {
            _combat_strategy = std::move(rvalue);
        }

    private:
        std::unique_ptr<ICombat> _combat_strategy{nullptr};
        //              ~~~~~~~
        //  This is our family of algorithm that we are going to choose 
};


int main()
{

    // NOTE: we can move this logic in a separate function
    Orc orc;
    orc.do_actions(); // NoCombat::execute()

    orc.set_combat_strategy( std::make_unique<MeleeCombat>() );
    orc.do_actions(); // MeleeCombat::execute()

    return 0;
}