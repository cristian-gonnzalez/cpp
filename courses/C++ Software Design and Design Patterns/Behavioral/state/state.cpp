/*

If I see the UML diagram, the concrete State class has the context as private variable. This can be avoid by passing the Context& as a parameter, like in my example, is perfectly valid and widely used.
✅ This avoids the need for each State to store a reference or pointer to the Context, which:
        
        - Reduces coupling between the State and the Context
        - Avoids circular dependencies
        - Keeps memory management simpler
        - Makes testing individual states easier (since they don’t depend on owning a Context)



*/

#include <iostream>
#include <memory>
#include <string>

// Forward declaration of Context
struct Context;

// Abstract State Interface
struct State {
    virtual ~State() = default;

    virtual void handle(Context& context) = 0;
    virtual std::string name() const = 0;
};

// Concrete States
struct ConcreteStateA : public State {
    void handle(Context& context) override;
    std::string name() const override { return "ConcreteStateA"; }
};

struct ConcreteStateB : public State {
    void handle(Context& context) override;
    std::string name() const override { return "ConcreteStateB"; }
};

// Context holding the current state
struct Context {
    void set_state(std::unique_ptr<State> state) {
        _state = std::move(state);
    }

    void request() {
        if (_state) {
            std::cout << "[Context] Current state: " << _state->name() << "\n";
            _state->handle(*this);
        }
    }

private:
    std::unique_ptr<State> _state;
};

// Transitions
void ConcreteStateA::handle(Context& context) {
    std::cout << "[ConcreteStateA] Handling request → Switching to StateB\n";
    context.set_state(std::make_unique<ConcreteStateB>());
}

void ConcreteStateB::handle(Context& context) {
    std::cout << "[ConcreteStateB] Handling request → Switching to StateA\n";
    context.set_state(std::make_unique<ConcreteStateA>());
}

// Driver Code
int main() {
    Context context;
    context.set_state(std::make_unique<ConcreteStateA>());

    for (int i = 0; i < 4; ++i) {
        context.request();
        std::cout << "----------------------\n";
    }

    return 0;
}
