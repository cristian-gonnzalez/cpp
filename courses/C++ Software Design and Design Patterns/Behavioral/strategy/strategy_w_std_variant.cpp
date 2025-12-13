/** Hybrid Strategy (std::variant or concepts)
 */

/*
✔ No std::function overhead
✔ No virtuals
✔ Multiple strategies stored in one object

    C++17 with std::variant:

🧠 When to use each
    Approach	Good for	Notes
    std::function	runtime switching	cleanest API, small overhead
    Templates (CRTP)	performance critical	compile-time strategy selection
    variant + visit	few known strategies	avoids heap + avoids std::function
*/
#include <variant>
#include <iostream>
#include <concepts>

template<typename T>
concept Strategy = requires(T s, int x) {
    { s.apply(x) } -> std::same_as<int>;
};


struct FastStrategy {
    int apply(int x) const {
        return x * 2;
    }
};

struct AccurateStrategy {
    int apply(int x) const {
        return x * x;
    }
};

struct ExperimentalStrategy {
    int apply(int x) const {
        return x + 42;
    }
};

class Processor {
    public:
        using StrategyVariant = std::variant<FastStrategy, AccurateStrategy, ExperimentalStrategy>;

        Processor(Strategy auto s)
            : strategy_{std::move(s)} {}

        void setStrategy(Strategy auto s) {
            strategy_ = std::move(s);
        }

        int process(int x) const {
            return std::visit([&](auto const& s) {
                return s.apply(x);
            }, strategy_);
        }

    private:
        StrategyVariant strategy_;
};

int main()
{
    Processor p(FastStrategy{});

    std::cout << p.process(5) << "\n";   // 10

    p.setStrategy(AccurateStrategy{});
    std::cout << p.process(5) << "\n";   // 25

    p.setStrategy(ExperimentalStrategy{});
    std::cout << p.process(5) << "\n";   // 47

    return 0;
}