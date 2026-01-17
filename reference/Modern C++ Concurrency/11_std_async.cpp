/** std::future and std::async in Modern cpp
 */

// @file async.cpp
#include <iostream>
#include <future>      // This give me the access to std::async

int square(int x){
    return x*x;
}

int main(){

    std::future<int> asyncFunction = std::async(&square,12);
    //          ~~~                       ~~~~~
    //         result                    without sychonization
    //
    //  This means that I launc a thread adn I wont'be clokec on that thread, I can
    // execute another operations
    //

    // The idea is that as soon as I start executin this asynchronously thread, I 
    // can start doung some other work
    for(int i=0; i< 10; i++){
        std::cout << square(i) << std::endl;
    }

    // We are blocked at the 'get()' operation, until our result has computed
    int result = asyncFunction.get();

    std::cout << "result is: " << result << std::endl;

    return 0;
}
