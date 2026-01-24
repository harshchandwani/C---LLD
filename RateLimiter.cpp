#include <iostream>
#include <chrono>
#include <mutex>

class RateLimiter {
public:
    // Constructor: define the capacity and refill rate
    RateLimiter(int maxTokens, int refillRatePerSecond) 
        : capacity(maxTokens), tokens(maxTokens), refillRate(refillRatePerSecond) {
        lastRefillTime = std::chrono::steady_clock::now();
    }

    // The core function: returns true if request is allowed
    bool allowRequest() {
        // We will implement this together
        return true; 
    }

private:
    // TODO: What variables do we need to keep track of?
    // Think about: current tokens, max capacity, refill rate, and the last time we checked.
};