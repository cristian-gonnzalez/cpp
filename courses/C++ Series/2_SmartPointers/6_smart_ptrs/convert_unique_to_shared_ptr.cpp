/* To convert a std::unique_ptr to a std::shared_ptr in C++, you move the unique_ptr into a shared_ptr constructor.

✅ Correct way

std::unique_ptr<Foo> up = std::make_unique<Foo>();
std::shared_ptr<Foo> sp = std::move(up);

✔ Why this works

std::shared_ptr has a constructor that takes a unique_ptr<T>&&.
When you std::move the unique_ptr into it:

Ownership transfers from unique_ptr → shared_ptr

up becomes empty (nullptr)

The object is now reference-counted

⚠ Important notes

Never attempt to copy a unique_ptr — only move it.

After conversion, do not use up, as it no longer owns anything.

This transfer is one-way: you cannot convert a shared_ptr back to a unique_ptr unless you're the only owner.

Example

*/
#include <memory>
#include <iostream>

int main() {
    auto up = std::make_unique<int>(42);

    std::shared_ptr<int> sp = std::move(up);

    std::cout << *sp << "\n";  // prints 42
    std::cout << (up == nullptr) << "\n";  // prints 1 (true)

    return 0;
}

