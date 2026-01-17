/** Modern Strategy Pattern — Compile-Time Strategy (Templates)
 *
 *  This avoids any runtime overhead.
 *
 *      Fully inlined: zero-cost abstraction
 *      Uses static polymorphism
 *      Very fast (no virtual dispatch)
 *      Great for high-performance code
 */

#include <iostream>

struct CreditCardStrategy {
    void operator()(double amount) const {
        std::cout << "Paying with credit card: " << amount << "\n";
    }
};

struct PayPalStrategy {
    void operator()(double amount) const {
        std::cout << "Paying with PayPal: " << amount << "\n";
    }
};

template<typename Strategy>
class PaymentProcessor {
public:
    void process(double amount) {
        strategy_(amount);
    }

private:
    Strategy strategy_;
};

int main() {
    PaymentProcessor<CreditCardStrategy> a;
    a.process(100);

    PaymentProcessor<PayPalStrategy> b;
    b.process(50);
}
