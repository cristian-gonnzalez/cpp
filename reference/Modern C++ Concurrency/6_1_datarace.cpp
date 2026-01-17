// @file datarace.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


/*
    Data race:

        The idea that based on of the order that threads access some shared-resource, yuo
    can get a non-deterministic result:

        For ex: If we dont synchronized our shared value (critical section/shared resource), 
    this could happend

     t3
      |
      |
     ----------------
    |  shared_value  |                               shared_value = shared_value + 1
     ----------------                                               ~~~~~~~~~~~~         
      ^            ^                                                  read
      |            |                                                ~~~~~~~~~~~~~~~~
      |            |                                                   write
      |            |
     t1            t2
   read 0        read 0

   t1 access and read 0 from shared_value, then t2 access and read also 0 from shared_value.
   t1 do +1 and update shared_value to 1 and then t2 also do +1 and update the shared_value to 1. 
   So two threads even thoogh increments twice, have only updated the shared_value by one.
*/


// This is our shared resource (critical section) to be access by multiple threads
static int shared_value= 0;


void shared_value_increment(){
        shared_value = shared_value + 1;
}

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 1000; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 1000; i++){
        threads[i].join(); 
    }

    std::cout << "Shared value:" << shared_value << std::endl;  // random outputs
    return 0;
}
