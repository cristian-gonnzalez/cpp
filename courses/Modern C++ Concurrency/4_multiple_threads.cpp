// @file thread3.cpp
#include <iostream>
#include <thread>
#include <vector>

int main(){

    auto lambda=[](int x){
        std::cout << "Hello from thread! " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::vector<std::thread> threads;
    for(int i=0; i < 10; i++){
        threads.push_back(std::thread(lambda, i));
    }

    for(int i=0; i < 10; i++){
        threads[i].join(); 
    }

    std::cout << "hello from my main thread" << std::endl;
    return 0;
}

/*
stdout
Hello from thread! 124194117383744
Argument passed in: 0
Hello from thread! 124193964291648
Argument passed in: 2
Hello from thread! 124194108991040
Argument passed in: 1
Hello from thread! 124194100598336
Argument passed in: 3
Hello from thread! 124194092205632
Argument passed in: 4
Hello from thread! 124194012526144
Argument passed in: 5
Hello from thread! 124194004133440
Argument passed in: 6
Hello from thread! 124193995740736
Hello from thread! 124193987348032
Argument passed in: 8
Argument passed in: 7
Hello from thread! 124193978955328
Argument passed in: 9
hello from my main thread

*/