/* Section 9 – Design Patterns (Modern C++)
✅ Exercise 3 — Implement a Strategy Pattern Without Virtuals

Goal:
Implement a sorting context object that can switch strategy at runtime.

But:

You are NOT allowed to use virtual functions.

Requirements:

Use either:

std::function

OR std::variant + std::visit

OR a template strategy with value semantics.

Strategies:

bubble_sort

quick_sort

Context:

Sorter sorter;
sorter.set_strategy(QuickSort{});
sorter.sort(vec);

*/
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>

struct QuickSort
{
    void operator()(std::vector<int>&)
    {
        std::cout << "QuickSort algorithm\n";
    }
};

struct BubbleSort
{
    void operator()(std::vector<int>&)
    {
        std::cout << "BubbleSort algorithm\n";
    }
};

class Sorter
{
public:
    void set_strategy(std::function<void(std::vector<int>&)> fn)
    {
        _strategy = std::move(fn);
    }

    void sort(std::vector<int>& vec)
    {
        if (!_strategy)
            throw std::runtime_error("Strategy not set!");

        std::invoke(_strategy, vec);
    }

private:
    std::function<void(std::vector<int>&)> _strategy;
};
