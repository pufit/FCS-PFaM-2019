#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>


template <class T>
struct State {
    T* data = nullptr;
    int counter = 0;

    State(T* data) : data(data), counter(1) {
    }

    ~State() {
        delete data;
    }
};

template <class T>
class SharedPtr {
public:
    SharedPtr(T* data) : state_(new State<T>(data)) {
    }

    SharedPtr(const SharedPtr& rhs) : state_(rhs.state_) {
        ++state_->counter;
    }

    SharedPtr(SharedPtr&& rhs) : state_(rhs.state_) {
        rhs.state_ = nullptr;
    }

    SharedPtr& operator=(SharedPtr rhs) {
        Swap(rhs);
        return *this;
    }

    void Swap(SharedPtr& rhs) {
        std::swap(state_, rhs.state_);
    }

    ~SharedPtr() {
        if (state_ == nullptr) {
            return;
        }
        if (state_->counter == 1) {
            delete state_;
        } else {
            assert(state_->counter > 1);
            --state_->counter;
        }
    }

    T& operator*() {
        return *state_->data;
    }

private:
    State<T>* state_;
};

int main() {
    SharedPtr<int> p1(new int(5));
    SharedPtr<int> p2(std::move(p1));
    p2 = std::move(p2);
    assert(5 == *p2);
}
