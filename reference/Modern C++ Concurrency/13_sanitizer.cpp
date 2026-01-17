/** Example of gcc and clang thread sanitizer to detect data race 
 */
// @file datarace.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


/*
    See https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html

    Sanitazers:
        The idea is monitoring memory access. It will add around potential function calls or places
    where we are reading and writing memory

-fsanitize=thread
        Enable ThreadSanitizer, a fast data race detector. Memory access instructions are instrumented 
to detect data race bugs. See https://github.com/google/sanitizers/wiki#threadsanitizer for more details. 
The run-time behavior can be influenced using the TSAN_OPTIONS environment variable; 
see https://github.com/google/sanitizers/wiki/ThreadSanitizerFlags for a list of supported options. 
The option cannot be combined with -fsanitize=address, -fsanitize=leak.

    When compiling with -fsanitize=thread, you should also use -g to produce more meaningful output.

    Note that sanitized atomic builtins cannot throw exceptions when operating on invalid memory addresses 
with non-call exceptions (-fnon-call-exceptions).


> g++ -fsanitize=thread -std=c++17 datarace.cpp -o prog -lpthread

  ==================
WARNING: ThreadSanitizer: data race (pid=1)              <----- DETECT A DATA RACE
  Read of size 4 at 0x000000408214 by thread T2:
    #0 shared_value_increment() /app/example.cpp:37 (output.s+0x4022d4) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #1 void std::__invoke_impl<void, void (*)()>(std::__invoke_other, void (*&&)()) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/invoke.h:63 (output.s+0x404316) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #2 std::__invoke_result<void (*)()>::type std::__invoke<void (*)()>(void (*&&)()) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/invoke.h:98 (output.s+0x40428c) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #3 void std::thread::_Invoker<std::tuple<void (*)()> >::_M_invoke<0ul>(std::_Index_tuple<0ul>) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:303 (output.s+0x404202) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #4 std::thread::_Invoker<std::tuple<void (*)()> >::operator()() /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:310 (output.s+0x4041ac) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #5 std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)()> > >::_M_run() /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:255 (output.s+0x404166) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #6 <null> <null> (libstdc++.so.6+0xf2ca3) (BuildId: fac422a459bf619e821fd13769b77c0b934f64b1)

  Previous write of size 4 at 0x000000408214 by thread T1:
    #0 shared_value_increment() /app/example.cpp:37 (output.s+0x4022e7) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #1 void std::__invoke_impl<void, void (*)()>(std::__invoke_other, void (*&&)()) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/invoke.h:63 (output.s+0x404316) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #2 std::__invoke_result<void (*)()>::type std::__invoke<void (*)()>(void (*&&)()) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/invoke.h:98 (output.s+0x40428c) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #3 void std::thread::_Invoker<std::tuple<void (*)()> >::_M_invoke<0ul>(std::_Index_tuple<0ul>) /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:303 (output.s+0x404202) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #4 std::thread::_Invoker<std::tuple<void (*)()> >::operator()() /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:310 (output.s+0x4041ac) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #5 std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)()> > >::_M_run() /cefs/22/22e6cdc013c8541ce3d1548e_consolidated/compilers_c++_x86_gcc_15.2.0/include/c++/15.2.0/bits/std_thread.h:255 (output.s+0x404166) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)
    #6 <null> <null> (libstdc++.so.6+0xf2ca3) (BuildId: fac422a459bf619e821fd13769b77c0b934f64b1)

  Location is global 'shared_value' of size 4 at 0x000000408214 (output.s+0x408214)

  Thread T2 (tid=4, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.2+0x5f090) (BuildId: d5d680a1035ee999a8de76940812285b233760e5)
    #1 std::thread::_M_start_thread(std::unique_ptr<std::thread::_State, std::default_delete<std::thread::_State> >, void (*)()) <null> (libstdc++.so.6+0xf2d78) (BuildId: fac422a459bf619e821fd13769b77c0b934f64b1)
    #2 main /app/example.cpp:44 (output.s+0x402346) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)

  Thread T1 (tid=3, finished) created by main thread at:
    #0 pthread_create <null> (libtsan.so.2+0x5f090) (BuildId: d5d680a1035ee999a8de76940812285b233760e5)
    #1 std::thread::_M_start_thread(std::unique_ptr<std::thread::_State, std::default_delete<std::thread::_State> >, void (*)()) <null> (libstdc++.so.6+0xf2d78) (BuildId: fac422a459bf619e821fd13769b77c0b934f64b1)
    #2 main /app/example.cpp:44 (output.s+0x402346) (BuildId: 725cf0b397a0f258917ddaacca1349e264a7104e)

SUMMARY: ThreadSanitizer: data race /app/example.cpp:37 in shared_value_increment()  
*/


// This is our shared resource (critical section) to be access by multiple threads
static int shared_value= 0;


void shared_value_increment(){
        shared_value = shared_value + 1;
}

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 100; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 100; i++){
        threads[i].join(); 
    }

    std::cout << "Shared value:" << shared_value << std::endl;  // random outputs
    return 0;
}
