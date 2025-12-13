/** Creational patterns - Singleton Pattern | Explanation and Implementation in C++
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
    Creational design pattern:
        It is concerned with how we create objects 

    The singleton pattern: 
        It allows/enforces only the creation of 1 instance of an object

*/

class Logger
{
    public:
        
        // Retrieve the single intance of the object created
        // and we will enforce only 1 of these objects gets 
        // created in our code logic
        static Logger& get_instance()
        {
            static Logger instance{};
            //~~~~
            // This is thread-safe. This means that static variable will instanciate once no matter
            // how many thread access this
            
            return instance;
        }

        void print_messages() const 
        {
            std::cout << "Accessing the log:\n";
            for(auto& e: _messages)
                std::cout << e << std::endl;
        }

        void add_message( const std::string s )
        {
            _messages.push_back( s );
        }

    private:
        Logger()
        {
            std::cout << "Logger was created\n";
        }

        // ~Logger can be private and it will be destroyed
        //
        // Why is it good that the destructor is private?
        //
        // Because it prevents this:
        //
        // Logger* p = &Logger::get_instance();
        // delete p;   // ❌ ERROR — destructor is private
        //
        // NOTE: 
        //      Its destruction is automatically handled by the C++ runtime
        //      When main() ends, the C++ runtime destroys all static objects regardless of 
        //  whether their destructors are public or private.
        ~Logger()
        {
            std::cout << "Logger was destroyed\n";    
        }
        
        std::vector< std::string > _messages{};
};

int main()
{
  /*  {
        Logger l1;
        Logger l2;
    }*/

    for(size_t i=0; i<4; i++ )
        Logger::get_instance().add_message("Hello, message"); 
    // Logger was created

    Logger::get_instance().print_messages();
    /*
    Accessing the log:
    Hello, message
    Hello, message
    Hello, message
    Hello, message
    
    */
    return 0;
}  // Logger was destroyed