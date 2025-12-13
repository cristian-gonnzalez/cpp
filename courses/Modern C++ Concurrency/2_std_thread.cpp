/** First thread with std::thread
 */

/*
    A thread is what's know as a 'ligtweight process'. So per proccess we have always had some main thread 
    A 'thread' allows us to execute two control flows at the same time
    

        main thread:                   thread 1:
        -------                        ------- 
       | main  |                      | fun() |   
        -------                        ------- 
            -------                        ---------   
           | foo() |                      | func2() |  
            -------                        ---------
            -------                        ---------
           | bar() |                      | func3() |  
            -------                        ---------
                -------                         ---------
               | bar() |                       | func4() |  
                -------                         ---------

        ~~~~~~~~~~~~~~~~               ~~~~~~~~~~~~~~~~~~~
        The 'main thread' is where           ^
        our program starts                   |
                                      we may have 1 or more additional threads:
                                        - excecution a block of code -> its own his logical control flow
                                        - excecution other functions
                                        - And overall -- sharing the same code, and the same data and libraries

                                      All while our main thread also excutes


High level view of thread:
-------------------------

1 Process (i.e. your application) can have many threads:


                        Thread 1 (main thread)              Thread 2 (main thread)             Shared code and data   

                         ---------------------             ---------------------               ------------------------
     Unique stack ----> |    stack1           |           |      stack2         |              |   shared libraries    |
       per thread        ---------------------             ---------------------               |                       |    Each thread shares the samww
          ^                                                                                    |   run-time heap       |   code, data, heap and kernel context
          |              ---------------------             ---------------------               |   read/write data     |  
          |             | Thread 1 context:   |           | Thread 2 context:   |              |   read-only code/data |   
          |             |    Data registers   |           |    Data registers   |              |                       |
          |             |    Condition codes  |           |    Condition codes  |               -----------------------
          |             |    SP1              |           |    SP2              |
          |             |    PC1              |           |    PC2              |                 Kernel context:
          |              ---------------------             ---------------------                     VM structures
          |                  ^                                                                       Descriptor table
          |                  |                                                                       brk pointer
          |                  |
      It's own data reguster too keep track                                                         
     of different local variables, where you are                                                            
     returning from

      A thread has its own thread id


    
    The mechanism for having miltiple threads is what's known as context switching. You will notice that each thread has a separate
    PC (Program Counter) and SP (Stack Pointer)


*/                                 

// g++ -std=c++17  thead1.cpp -o prog  -lpthread
//                                     ^^
//                                 we need to link with p_thread library
//                                 This means that std::thread is implemented with pthread 


#include <iostream>
#include <thread>   // Include the thread library


// std::thread::thread
//  C++ Concurrency support library std::thread 
// 
// thread() noexcept;                               (1) (since C++11)
// 
// thread( thread&& other ) noexcept;               (2) (since C++11)      -> We can move 
// 
// template< class F, class... Args >
// explicit thread( F&& f, Args&&... args );        (3) (since C++11)
//                  ~~~~~  ~~~~~~~~~~~~~~
//                    ^         Arguments 
//                    |
//                  Function
//
// thread( const thread& ) = delete;                (4) (since C++11)      -> Threads are not copyable
//
// 

// Test function which we'll launch threads from
void test(int x){
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
}


int main(){

    // Creates a new thread and pass one parameter
    std::thread myThread(&test, 100);

    // join with the main thread 
    // Blocks the current thread until the thread identified by *this finishes its execution
    myThread.join();

    // Continue executing the main thread
    std::cout << "hello from my main thread" << std::endl;

    return 0;
}

/*
            main thread:
            -------                        
           | main  |       
            -------                   
            -----------------------------------            ----------
           | std::thread myThread(&test, 100); | -------> | myThread |  
            -----------------------------------            ---------
            --------                                       -----------
           | join() | <------------------------           | std::cout |  
            --------                           |           -----------
            --------                           |           ---------
           | return |                          |--------- | return |  
            --------                                       ---------


stdout
    Hello from thread!
    Argument passed in: 100
    hello from my main thread

*/