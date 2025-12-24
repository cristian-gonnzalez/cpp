# C++ Learning Repository

This repository is a **personal collection of learning notes and experiments for C++**, containing small examples, code snippets, and exploratory implementations created while studying and practicing modern C++.

It is **not a single project**, but a structured collection of:

* Algorithms and data structures
* Core and modern C++ language features
* STL usage and internals
* Design patterns
* Concurrency and multithreading
* Exercises and experiments

The code is primarily written for **learning and reference purposes**.

---

## Repository Structure

### `algorithm/`

Implementations of classic algorithms.

* **Graph algorithms**: BFS, DFS, cycle detection, Dijkstra
* **Sorting algorithms**

### `data_structure/`

Core data structure implementations.

* Binary tree implementation with header/source separation

### `courses/`

This is the largest section of the repository and contains structured material grouped by topics and courses.

#### C++ Series

A comprehensive walkthrough of C++ fundamentals to advanced topics:

* Language basics (types, references, pointers, arrays)
* RAII, constructors/destructors
* Copy & move semantics
* Templates, metaprogramming, concepts
* STL containers, iterators, algorithms
* Modern C++ (C++17 / C++20 features)
* Optimization techniques

Each folder usually contains **small focused `.cpp` files** demonstrating a single concept.

#### Modern C++ Advanced Techniques and Features

Advanced language topics such as:

* Value categories
* Smart pointers
* Functional programming techniques
* `std::optional`, `std::variant`, `std::any`

#### Modern C++ Concurrency

Examples related to multithreading and concurrency:

* `std::thread`, `std::jthread`
* Mutexes, atomics, condition variables
* `std::async`
* Data races and synchronization

#### C++ Software Design and Design Patterns

Implementations and examples of common design patterns:

* Creational (Singleton, Factory)
* Structural
* Behavioral (Observer, Strategy, Command, Visitor)

#### C++ Exercises

Small problems and practical exercises, including:

* Binary search problems
* Thread pool example
* Plugin and registration system

---

## How to Use This Repository

* Browse folders by topic
* Open individual `.cpp` files to study specific concepts
* Most examples are **self-contained** and can be compiled independently

### Example compile command

```bash
g++ -std=c++20 example.cpp -o example
```

(Some files may require specific compiler flags or libraries depending on the example.)

I often use [Compiler Explorer (Godbolt)](https://godbolt.org/) for quick experimentation and inspecting generated assembly.

---

## Purpose

This repository exists primarily as:

* 📝 **Learning notes** for C++ concepts
* 🧪 **Experiments** to explore language behavior, edge cases, and pitfalls
* 📚 A **personal reference** for modern C++ features and idioms

Most files are intentionally small and focused, often written to answer a specific question or test a single idea.

---

## Disclaimer

* Code is primarily educational
* Not all examples are production-ready
* Some files may contain intentional pitfalls or incorrect usage to demonstrate problems

---

## License

This repository is a personal collection of learning notes and experiments.

The code is provided for educational purposes only.
If you intend to reuse or redistribute any part of it, please review and
respect the original licenses of any third-party material.
