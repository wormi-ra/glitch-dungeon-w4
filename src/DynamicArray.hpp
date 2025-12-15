#pragma once

#include <vector>

template <class T>
using DynamicArray = std::vector<T>;

// template <class T>
// class DynamicArray {
//     public:
//         constexpr DynamicArray() = default;
//         constexpr DynamicArray(const DynamicArray &x) = default;
//         constexpr DynamicArray(DynamicArray &&x) = default;
//         constexpr DynamicArray(std::initializer_list<T> init)
//             : m_array(new T[init.size()]), m_size(0), m_capacity(init.size()) {
//             for (auto &value : init) {
//                 this->push_back(value);
//             }
//         };

//         ~DynamicArray() {
//             delete []this->m_array;
//         };
        
//         constexpr DynamicArray &operator=(std::initializer_list<T> init) = default;

//         constexpr void push_back(T value);

//         // Method to insert an element at a specified index
//         constexpr void insert(T value, uint32_t index);

//         // Method to delete an element at a specified index
//         constexpr void erase(uint32_t index);

//         // Method to search for an element and return its index
//         constexpr int32_t search(T value) const;

//         // Method to get the number of elements of the array (size)
//         constexpr uint32_t size() const;

//         // Method to get the maximum size of the array
//         constexpr uint32_t capacity() const;

//         // Method to get the printf of the array
//         constexpr void trace() const;

//         // Method to merge two arrays
//         constexpr DynamicArray merge(const DynamicArray& other) const;

//         // Overloaded operator to access elements in the array
//         constexpr T &operator[](uint32_t index);

//         // Const version of the overloaded operator for read-only access
//         constexpr const T &operator[](uint32_t index) const;

//         // iterators
//         // constexpr iterator begin() noexcept;
//         // constexpr const_iterator begin() const noexcept;
//         // constexpr iterator end() noexcept;
//         // constexpr const_iterator end() const noexcept;
//         // constexpr reverse_iterator rbegin() noexcept;
//         // constexpr const_reverse_iterator rbegin() const noexcept;
//         // constexpr reverse_iterator rend() noexcept;
//         // constexpr const_reverse_iterator rend() const noexcept;
    
//         // constexpr const_iterator cbegin() const noexcept;
//         // constexpr const_iterator cend() const noexcept;
//         // constexpr const_reverse_iterator crbegin() const noexcept;
//         // constexpr const_reverse_iterator crend() const noexcept;

//     private:
//         T *m_array {nullptr};          // Pointer to the dynamically-allocated array
//         uint32_t m_size {0};     // Current number of elements in the array
//         uint32_t m_capacity {0};        // Current capacity of the array

//         // Method to resize the array
//         constexpr void resize(uint32_t size);
// };
