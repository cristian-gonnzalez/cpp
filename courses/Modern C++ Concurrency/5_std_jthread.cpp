/** jthread std::jthread in C++ 20 
 */
//
// g++ -std=c++20 thread4.cpp -o prog -lpthread
//

// @file thread4.cpp
#include <iostream>
#include <thread>
#include <vector>

//
// std::jthread:
//
//      std::thread with support for auto-joining and cancellation.
//
//      It is using a concept of RAII (Resource acqusition is Initialization) where dutint the destruction
//    it'll actually  make sure that it is joined with the current calling thread.
//
// (destructor) -> if the thread is joinable, then a stop is requested and the thread joins


int main(){

    auto lambda=[](int x){
        std::cout << "Hello from thread!" << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::vector<std::jthread> jthreads;
    for(int i=0; i < 10; i++){
        jthreads.push_back(std::jthread(lambda, i));
    }


    std::cout << "hello from my main thread" << std::endl;
    return 0;
} // all jthreads will join right at the end of the scope

/*


stdout
Hello from thread!139161782711872
Argument passed in: 0
Hello from thread!139161774319168
Argument passed in: 1
Hello from thread!139161757533760
Argument passed in: 3
Hello from thread!139161765926464
Argument passed in: 2
Hello from thread!139161749141056
Argument passed in: 4
Hello from thread!139161740748352
Argument passed in: 5
Hello from thread!139161715570240
Argument passed in: 8
hello from my main thread
Hello from thread!139161732355648
Argument passed in: 6
Hello from thread!139161723962944
Argument passed in: 7
Hello from thread!139161638008384
Argument passed in: 9
*/