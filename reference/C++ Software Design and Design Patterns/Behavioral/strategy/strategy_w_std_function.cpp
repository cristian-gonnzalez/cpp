/** Runtime Strategy (std::function)
 */

 /*
✔ No inheritance
✔ Easy to swap strategy at runtime
✔ Value semantics
✔ Safe, simple, modern

Why this is modern?

The strategy is just a callable object (lambda, functor, function pointer).

No inheritance, no virtual dispatch.

Strong value semantics: strategies can be copied, moved, stored.

Works perfectly with C++11+ but shines in C++17+.

*/
#include <functional>
#include <iostream>

class ImageProcessor {
public:
    using Strategy = std::function<void(std::vector<uint8_t>&)>;

    explicit ImageProcessor(Strategy s) 
    : strategy(std::move(s)) 
    {
    }

    void set_strategy(Strategy s) 
    { 
        strategy = std::move(s); 
    }

    void process(std::vector<uint8_t>& img) 
    {
        strategy(img);
    }

private:
    Strategy strategy;
};

int main()
{
    std::vector<uint8_t> image{1,2,3};

    ImageProcessor p{ [](auto& img)
                      { 
                        /* fast sharpen */
                        std::cout << "Fast sharpen strategy\n"; 
                      } };

    p.process( image );
    p.set_strategy( [](auto& img)
                    { 
                        /* gaussian blur */
                        std::cout << "Gaussian blur strategy\n"; 
                    });

    p.process( image );

    return 0;
}

