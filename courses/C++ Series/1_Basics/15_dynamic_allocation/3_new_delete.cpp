/** Dynamic Memory allocation with new and delete (and delete[])
 *  Modern Cpp Series Ep. 25
 */
#include <iostream>
#include <numeric> // std::iota

/*
    Working with heap memory is where dynamic allocation occurs,
  and we can define sizes at run-time.

    In contrast, when using stack memory, variables must have
  a size known at compile-time.
*/

int main()
{
    {
        // Creating a local array of 100 integers in the stack
        // This is a fixed-size array defined at compile-time
        int students[100];
        std::iota(std::begin(students), std::end(students), 0);

        // What happens if, at runtime, I need to store 200 students?
        //
        // The answer is: I CANNOT, because the size was defined at compile-time
        // and cannot be changed. 
    }

    int num_students = 0;

    // If we give a very large number, it may cause stack overflow.
    std::cout << "How many students in our class?\n";
    std::cin >> num_students; 

    {
        int students[num_students];
        //           ^~~~~~~~~~~~  VLA Illegal in C++
        
        // What is happening here?
        //
        // int students[num_students];
        //              ^~~~~~~~~~~~
        //   This is a Variable Length Array (VLA).
        //
        //     - In C (since C99): VLAs are valid and allocated on the stack at runtime.
        //     - In C++: VLAs are NOT part of the language (illegal in standard C++).
        //
        //   g++ accepts VLAs as an extension, so the array is allocated on the stack.
        // But this is non-portable and not real C++.
        //
        // Note: Stack memory in standard C++ must be fully determined at compile time

    }    

    // This is why we need new/delete: to allocate memory at 'run-time'.
    //
    //   - 'new/new[]' allows us to allocate memory dynamically (on the heap).
    //   - The return value is a pointer to the allocated memory.

    {
        // We allocate at runtime with 'new' the number of elements we need.

                      // These blocks of memory are allocated on the heap.
                      //    ^~~~~~~~~~~~~~~~~
        int* students = new int[num_students];
        //   ^~~~~~~~ 
        //   This pointer itself lives on the stack.
        //   It points to dynamically allocated memory in the heap.
        //
        //   If the pointer goes out of scope without calling delete[], we will lose the 
        // address and the heap memory will not be released ('memory leak').
           
        for(size_t i=0; i<num_students; i++)
            students[i] = i;

        delete[] students;
        //    ^~
        // Must use delete[] for arrays allocated with new[].
        
    } // Since 'students' was a stack variable (local variable) 
      // It is unavailable outside the scope. If we had not freed the heap memory
      // before leaving the scope, we would have leaked memory.
    
    return 0;
}