/** Abstract class (Interface): pure virtual function 
 */
#include <iostream>
#include <memory>

/*
  An abstract class is a class that cannot be instantiated, but is used as a base class 
(Interface). A class becomes abstract when it contains at least one pure virtual function.

Pure virtual function:
  A pure virtual function is a virtual function with the pure-specifier (= 0).
It acts as a 'declaration only' — it has no implementation here. Derived classes
must override and implement it.

  The pure-specifier (=0) cannot appear in a function definition or a friend declaration.


Why use an abstract class?

  Abstract classes express general concepts (Shape, Renderer, Animal). They define
a common API that all derived classes must follow. They provide a way to write code
that depends on an interface without knowing the concrete implementation.

  Example use case:
  A graphics API may have different backends (OpenGL, Vulkan, Metal), all exposing
the same interface but with platform-specific implementations.

            ┌───────────┐
            │ IRenderer │ Interface / Abstract        
            └───────────┘         
                  ↑
             _____|_________________     'is-a' relation                
            |            |          | 
    ┌─────────┐       ┌────────┐
    │ OpenGL  │       │ Vulkan │   .....
    └─────────┘       └────────┘

  Conclusion: An abstract class is usefull to define a consitent API where different 
subclasses has to implement following those rules, maybe because the same API runs in 
different hardware such as Android and iOS where the API is the same but implementation 
have to be addpated to each OS.
*/

class IRenderer
{
    public:
        virtual ~IRenderer() = default;
        
        
        virtual void draw() = 0; // This is a pure virtual function
                        //  ^~~ (pure-specifier)
                        // This must be implemented by any derived class
        virtual void update() = 0;
};

class OpenGL : public IRenderer
{
    public:
        void draw() override
        {
            std::cout << "OpenGL::draw\n";
        }
        void update() override
        {
            std::cout << "OpenGL::update\n";
        }

        // This is a method that only OpenGL has
        // Note: cannot call using a pointer or reference to Base
        void draw_optimized()
        {
            std::cout << "OpenGL::draw_optimized\n";
        }
};

class Vulkan  : public IRenderer
{
    public:
        void draw() override
        {
            std::cout << "Vulkan::draw\n";
        }
        void update() override
        {
            std::cout << "Vulkan::update\n";
        }
};


int main()
{
    //   I dont want to create a direct object of IRenderer because in the context of 
    // this program it is not meaningful. I just want this to serve as an interface 
    // of what must be implemented in OpenGL or Vulkan 
//    std::unique_ptr<IRenderer> up{ new IRenderer };
    //                                   ^~~~~~~~~
    // error: invalid new-expression of abstract class type 'IRenderer'

    std::unique_ptr<IRenderer> up{ new OpenGL };
    up->draw();
    up->update();

    // Interface pointer 

    // Cannot call subclass-specific methods since we are working with an interface
//    up->draw_optimized();
    //   ^~~~~~~~~~~~~~ 
    // error: 'class IRenderer' has no member named 'draw_optimized'

    std::unique_ptr<OpenGL> opengl{ new OpenGL };
    //              ^~~~~~              ^~~~~~
    //                 |------ == -------|
    //                   Using subclass   
    opengl->draw_optimized();
    
    return 0;
}