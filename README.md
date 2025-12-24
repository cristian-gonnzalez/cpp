# C++ Reference and Explorations

This repository is a personal reference and exploration space for C++, built over
time through hands-on work with the language in real projects.

It contains small, focused examples, experiments, and notes covering core
language features, modern C++ idioms, design patterns, and concurrency. Rather
than being a single cohesive application, the repository is organized by topic so
each example can be understood in isolation.

I use this repository both as a reference and as a place to validate ideas before
applying them.

---

## Contents

This repository includes material covering:

- Algorithms and data structures
- Core and modern C++ language features
- STL usage and behavior
- Design patterns and software design techniques
- Concurrency and multithreading
- Small focused exercises and experiments

Each example is intentionally scoped to highlight a specific concept or
implementation detail.

---

## Repository Structure

### `algorithm/`

Implementations of classic algorithms, including:

- Graph algorithms (BFS, DFS, cycle detection, Dijkstra)
- Sorting algorithms

### `data_structure/`

Core data structure implementations, including:

- Binary tree implementations with header/source separation

### `courses/`

A structured collection of examples grouped by topic.

#### C++ Series

Coverage from fundamental to advanced topics, including:

- Language fundamentals (types, references, pointers, arrays)
- RAII and object lifetime
- Copy and move semantics
- Templates, metaprogramming, and concepts
- STL containers, iterators, and algorithms
- Modern C++ features (C++17 / C++20)
- Performance and optimization considerations

Each folder typically contains **small focused `.cpp` files**, each illustrating
a single concept.

#### Modern C++ Advanced Techniques

Examples covering advanced language topics such as:

- Value categories
- Smart pointers
- Functional-style programming
- `std::optional`, `std::variant`, `std::any`

#### Modern C++ Concurrency

Examples related to multithreading and concurrency, including:

- `std::thread`, `std::jthread`
- Mutexes, atomics, and condition variables
- `std::async`
- Synchronization and data race scenarios

#### C++ Software Design and Design Patterns

Examples and implementations of common design patterns, including:

- Creational patterns (Singleton, Factory)
- Structural patterns
- Behavioral patterns (Observer, Strategy, Command, Visitor)

#### C++ Exercises

Small practical problems and focused exercises, such as:

- Binary search problems
- Thread pool example
- Plugin and registration systems

---

## Usage

```bash
g++ -std=c++20 example.cpp -o example

```
(Some examples may require additional compiler flags or libraries.)

For quick experimentation and inspection of generated assembly, I often use
Compiler Explorer (Godbolt).

---
