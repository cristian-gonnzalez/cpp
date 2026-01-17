/* Problem: Connection State Manager

You are building a system that manages network connections. A Connection object can 
be in one of the following states:

    - Disconnected — default state
    - Connecting
    - Connected

The allowed state transitions are:

    - Disconnected → Connecting
    - Connecting → Connected or Connecting → Disconnected (if failed)
    - Connected → Disconnected

*/
#include <iostream>
#include <memory>
#include <string>

// Forward declaration
struct Connection;

// Abstract State Interface
struct ConnectionState {
    virtual ~ConnectionState() = default;

    virtual void connect(Connection& conn) = 0;
    virtual void disconnect(Connection& conn) = 0;
    virtual const char* name() const = 0;
};

// Context
struct Connection {
    Connection(std::unique_ptr<ConnectionState> initial_state)
        : _state(std::move(initial_state)) {}

    void set_state(std::unique_ptr<ConnectionState> state) {
        _state = std::move(state);
    }

    void connect() {
        _state->connect(*this);
        std::cout << "Current State: " << _state->name() << "\n";
    }

    void disconnect() {
        _state->disconnect(*this);
        std::cout << "Current State: " << _state->name() << "\n";
    }

private:
    std::unique_ptr<ConnectionState> _state;
};

// Concrete States
struct DisconnectedState : public ConnectionState {
    void connect(Connection& conn) override;
    void disconnect(Connection&) override {
        std::cout << "[!] Already disconnected.\n";
    }
    const char* name() const override { return "Disconnected"; }
};

struct ConnectingState : public ConnectionState {
    void connect(Connection&) override {
        std::cout << "[!] Already connecting. Please wait...\n";
    }
    void disconnect(Connection& conn) override {
        std::cout << "[!] Cancelling connection.\n";
        conn.set_state(std::make_unique<DisconnectedState>());
    }
    const char* name() const override { return "Connecting"; }
};

struct ConnectedState : public ConnectionState {
    void connect(Connection&) override {
        std::cout << "[!] Already connected.\n";
    }
    void disconnect(Connection& conn) override {
        std::cout << "[*] Disconnecting...\n";
        conn.set_state(std::make_unique<DisconnectedState>());
    }
    const char* name() const override { return "Connected"; }
};

// Connection logic for DisconnectedState
void DisconnectedState::connect(Connection& conn) {
    std::cout << "[*] Connecting...\n";

    // Simulate successful connection
    bool success = rand() % 2;
    if (success) {
        std::cout << "[+] Connection established!\n";
        conn.set_state(std::make_unique<ConnectedState>());
    } else {
        std::cout << "[-] Connection failed. Try again.\n";
        conn.set_state(std::make_unique<DisconnectedState>());
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Connection conn(std::make_unique<DisconnectedState>());

    conn.connect();    // Try to connect
    conn.connect();    // Try to connect again (if already connected)
    conn.disconnect(); // Try to disconnect
    conn.disconnect(); // Try to disconnect again

    return 0;
}
