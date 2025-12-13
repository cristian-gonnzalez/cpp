/** Using std::atomic in modern C++ to update a shared value 
 */

// @file atomics.cpp
#include <iostream>
#include <thread>
#include <atomic>   // std::atomic
#include <vector>


// Another way to synchronized threads where by default we only want one value to be updated or incremented.
// There is a better solution to do that instead of std::mutex

//
// std::atomic
//

//      Atomic you can think of like atom or something that is indivisible so that means some operation where  
// you wouldnt want an interleaving of reads and writes to cause a data race
//
// Defined in header <atomic>
//
//  template< class T >
//  struct atomic;
//
//      This is implemented with some sort of hardware mechanism.
//
//      You can also work with your own data types as well. The idea is that your type has to essentially be 
// just a collection of bits that you are operating on, the hardware primitives that support this operation 
// that sth has changed    

static std::atomic<int> shared_value= 0;
//                 ~~~
//               data-type  
//          std::atomics works with all the primitives types

void shared_value_increment(){
    shared_value += 1;
    //           ~~~~~
    //         This is the atomic operation

    // We have to be carefully. Only these operation are allowed
    // increments or decrements the atomic value by one
    //
    //      operator++/operator++(int)
    //      operator--/operator--(int)
    // 

    // shared_value = shared_value + 1  -> This will cause data race and unbehaviour result since thi is 
    //                                     anr interleaved operation
    // 
}

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 100; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 100; i++){
        threads[i].join(); 
    }

    std::cout << "Shared value: " << shared_value << std::endl; // Shared value: 100

    return 0;
}
