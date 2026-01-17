/** Variadic templates
 *      Template can take any number/type of parameters
 */
#include <iostream>
#include <memory>


/*
template<typename... Types>
                 ~~~~~~~~~
             This means you can pass in as many type parameters -> std::tuple<int, char, double> t1;
class tuple;

template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args&&... params);
                ^                    ~~~~~~~~~~~
        T type you want to create          ^
                                           |
                                  Whatever parameters T constructor needs  


A variadic template has at least one 'parameter pack' (... syntax).
    - A parameter pack is a template parameter that accepts zero or more template arguments

*/

template<typename... ArgsF1>
void f1(ArgsF1... args)
{
    // do sth
}


template<typename... ArgsF2>
void f2(ArgsF2... args)
{
    f1(&args...); 
    // ^~~~~~~~
    // |    args... is a 'pack expansion' -> It basically expands the arguments into a ',' separated sequence
    // |      &args is its pattern
    //
    // You can apply some syntax to add onto each parameter, i.e. &args, we put the '&' before each argument 
    // So what this will do is it'll basically expand the parameter into a coma separeted sequence with '&'
    //
    //   f1(&p1, &p2, &p3)
}

/*
// First instantiated from: insights.cpp:37
template<>
void f1<int *, float *, const char **>(int * __args0, float * __args1, const char ** __args2)
{
}

// First instantiated from: insights.cpp:43 
template<>
void f2<int, float, const char *>(int __args0, float __args1, const char * __args2)
{
  f1(&__args0, &__args1, &__args2);
}

*/

int main()
{
    f2(1, 0.2f, "a");
    
    return 0;
}