/** Mutable: M&M rule
 */
#include <iostream> 
#include <mutex> 
#include <thread> 

/*
 
 M&M rule: 
    mutable and mutex go together

*/

class ThreadsafeCounter
{
    mutable std::mutex m; // The "M&M rule": mutable and mutex go together
    int data = 0;
public:
    int get() const
    //        ^~~~~ read-only member variables 
    {
        std::lock_guard<std::mutex> lk(m);
                //                     ^
                // std::lock_guard changes the state of the mutex
                // so this must be mutable
        return data;
    }
 
    void inc()
    {
        std::lock_guard<std::mutex> lk(m);
        ++data;
    }
};

int main()
{
    
    return 0;
}