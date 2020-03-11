#include <iostream>
#include <cstdint>
#include <memory>
#include <utility>
#include <cstddef>


using i32 = int32_t;

template<typename T>
class UniquePtr {
public:
    UniquePtr() noexcept = default;  // UniquePtr() {};

    explicit UniquePtr(T *ptr) noexcept : data_{std::move(ptr)} {}

    UniquePtr(UniquePtr&& other) noexcept;

    UniquePtr& operator=(std::nullptr_t p);

    UniquePtr& operator=(UniquePtr&& other) noexcept;

    const T& operator*() const {
        return *data_;
    }

    const T *operator->() const {
        return data_;
    }

    T *release();

    void reset(T *ptr);

    void swap(UniquePtr& other);

    T *get() const;

    explicit operator bool() const;

    UniquePtr& operator=(UniquePtr&) = delete;

    UniquePtr(UniquePtr&) = delete;

    ~UniquePtr();

private:
    T *data_{nullptr};

    void Delete();
};
