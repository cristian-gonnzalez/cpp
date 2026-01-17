/** C++ STL std::stack (a container adaptor) | Modern Cpp Series Ep. 131
 */ 


#include <iostream>
#include <stack>

/*

std::stack:

    It is a container adaptor that gives the functionality of a stack (LIFO;  last-in, first-out) data-structure.
                      ~~~~~~~

                   It is called since we use another container 
                to adpat to stack   

Defined in header <stack>
template<
    class T,
    class Container = std::deque<T>         <--- container used to be adapted
> class stack;


LIFO:  last-in, first-out

             out
              ↑
          _________
      |   \________\                       push(T)  Add new element
   in |   \________\                       pop()    Remove the top element
      |   \________\                       top()    Peeks at the top element
      |   \________\
      ↓   \________\
        

Member functions

    Element access
        top: accesses the top element


    Capacity
        empty: checks whether the container adaptor is empty
        size: returns the number of elements


    Modifiers
        push: inserts element at the top
        emplace: constructs element in-place at the top.
            It means that the object doesnt have to be copied and then push over to the stack.
        pop: removes the top element
        swap: swaps the contents
*/


void view_stack( std::stack<int> copy )
              //                 ^
              // Pass-by-value because to show the stack, we need to remove
              // all the elements
{
    // To print the stack we need to remove the elements. 
    // So the top element if the first to be printed
    int r;
    std::cout << "[";
    while(!copy.empty())
    {
        r = copy.top();
        copy.pop();

        std::cout << r << ", ";
    }
    std::cout << "]\n "; 
}


int main()
{
    {
        std::stack<int> s;

        s.push(1);
        s.push(2);
        s.push(3);

        std::cout << "the top is: " << s.top() << std::endl; // the top is: 3

        int top = s.top();

        // pop():
        //      Removes the top element from the stack. Effectively calls c.pop_back().
        //
        //      void pop();
        //      ~~~~
        // There is no return value
        //
        //      To get the element, we need to call top() before calling pop().
        s.pop();
        
        std::cout << "the new top is: " << s.top() << std::endl; // the new top is: 2

    }
    
    
    {
        // WARNING: uniform-initialization is not supported
        //
        //                  ~                    ~    
        // std::stack<int> s{-3,-2,1,0 /*, 2.3 */};
        //
        //      I cannot use uniform-initialization or std::inizializer_list 
        // because std::stack does not have an initializer-list constructor, but 
        // it does have a constructor that takes a container.
        //
        //      explicit stack(const Container& cont);
        //      explicit stack(Container&& cont);        
        //
        //      This is the correct way to construct
        //
        // std::stack<int> s({-3, -2, 1, 0}); 
        //
        // -- Why this version works: std::stack<int> s({-3, -2, 1, 0});
        //
        //      {-3, -2, 1, 0} creates a temporary container using the adaptor: 
        //
        //  std::deque<int>{-3, -2, 1, 0}
        //
        //      That container is passed to the stack constructor:
        //
        //  std::stack<int> s(std::deque<int>{ -3, -2, 1, 0 });
        //
        
        std::stack<int> s({-3,-2,1,0 /*, 2.3 */});
        //                              ~~~~~
        // narrowing conversion of '2.2999999999999998e+0' from 'double' to 'int

        view_stack(s); // [0, 1, -2, -3, ]
    }
    
    return 0;
}