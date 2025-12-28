// https://github.com/pritpal20/vector
// lni::vector by Jasmine "lnishan" Chen is licensed under a Creative Commons Attribution 4.0 International License.

#pragma once

// #include <cstddef>
#include <cstring>
// #include <utility>
// #include <memory>
#include <iterator>

#define LNI_VECTOR_MAX_SZ 1000000000

namespace lni {

	template <typename T>
	class vector {
		public:
			// types:
			typedef T                                     value_type;
			typedef T &                                   reference;
			typedef const T &                             const_reference;
			typedef T *                                   pointer;
			typedef const T *                             const_pointer;
			typedef T *                                   iterator;
			typedef const T *                             const_iterator;
			typedef std::reverse_iterator<iterator>       reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef ptrdiff_t                             difference_type;
			typedef unsigned int                          size_type;

			// 23.3.11.2, construct/copy/destroy:
			constexpr vector() noexcept;
			constexpr explicit vector(size_type n);
			constexpr vector(size_type n, const T &val);
			template <class InputIt> constexpr vector(InputIt first, InputIt last); //v1(v2.begin(),v2.end())
			constexpr vector(std::initializer_list<T>);
			constexpr vector(const vector<T> &);
			constexpr vector(vector<T> &&) noexcept;
			~vector();
			constexpr vector<T> & operator = (const vector<T> &);
			constexpr vector<T> & operator = (vector<T> &&);
			constexpr vector<T> & operator = (std::initializer_list<T>);
			constexpr void assign(size_type, const T &value);
			template <class InputIt> constexpr void assign(InputIt, InputIt);
			constexpr void assign(std::initializer_list<T>);

			// iterators:
			constexpr iterator begin() noexcept;
			constexpr const_iterator begin() const noexcept;
			constexpr const_iterator cbegin() const noexcept;
			constexpr iterator end() noexcept;
			constexpr const_iterator end() const noexcept;
			constexpr const_iterator cend() const noexcept;
			constexpr reverse_iterator rbegin() noexcept;
			constexpr const_reverse_iterator crbegin() const noexcept;
			constexpr reverse_iterator rend() noexcept;
			constexpr const_reverse_iterator crend() const noexcept;

			// 23.3.11.3, capacity:
			constexpr bool empty() const noexcept;
			constexpr size_type size() const noexcept;
			constexpr size_type max_size() const noexcept;
			constexpr size_type capacity() const noexcept;
			constexpr void resize(size_type);
			constexpr void resize(size_type, const T &);
			constexpr void reserve(size_type);
			constexpr void shrink_to_fit();

			// element access
			constexpr reference operator [](size_type);
			constexpr const_reference operator [](size_type) const;
			constexpr reference at(size_type);
			constexpr const_reference at(size_type) const;
			constexpr reference front();
			constexpr const_reference front() const;
			constexpr reference back();
			constexpr const_reference back() const;

			// 23.3.11.4, data access:
			constexpr T * data() noexcept;
			constexpr const T * data() const noexcept; 

			// 23.3.11.5, modifiers:
			template <class ... Args> constexpr void emplace_back(Args && ... args);
			constexpr void push_back(const T &);
			constexpr void push_back(T &&);
			constexpr void pop_back();
	
			template <class ... Args> constexpr iterator emplace(const_iterator, Args && ...); 
			constexpr iterator insert(const_iterator, const T &);
			constexpr iterator insert(const_iterator, T &&);
			constexpr iterator insert(const_iterator, size_type, const T&);
			template <class InputIt> constexpr iterator insert(const_iterator, InputIt, InputIt);
			constexpr iterator insert(const_iterator, std::initializer_list<T>);
			constexpr iterator erase(const_iterator);
			constexpr iterator erase(const_iterator, const_iterator);
			constexpr void swap(vector<T> &);
			constexpr void clear() noexcept;

			constexpr bool operator == (const vector<T> &) const;
			constexpr bool operator != (const vector<T> &) const;
			constexpr bool operator < (const vector<T> &) const;
			constexpr bool operator <= (const vector<T> &) const;
			constexpr bool operator > (const vector<T> &) const;
			constexpr bool operator >= (const vector<T> &) const;
			
		private:
			size_type rsrv_sz = 4;
			size_type vec_sz = 0;
			T *arr;

			inline void reallocate();

	};

    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunused-variable"
    #pragma clang diagnostic ignored "-Wsign-conversion"

    template <typename T>
    constexpr vector<T>::vector() noexcept {
        arr = new T[rsrv_sz];
    }

    template <typename T>
    constexpr vector<T>::vector(typename vector<T>::size_type n) {
        size_type i {};
        rsrv_sz = n << 2;
        arr = new T[rsrv_sz];
        for (i = 0; i < n; ++i)
            arr[i] = T();
        vec_sz = n;
    }

    template <typename T>
    constexpr vector<T>::vector(typename vector<T>::size_type n, const T &value) {
        size_type i {};
        rsrv_sz = n << 2;
        arr = new T[rsrv_sz];
        for (i = 0; i < n; ++i)
            arr[i] = value;
        vec_sz = n;
    }

    template <typename T>
    template <class InputIt>
    constexpr vector<T>::vector(InputIt first, InputIt last) {
        size_type i {}, count = last - first;
        rsrv_sz = count << 2;
        vec_sz = count;
        arr = new T[rsrv_sz];
        for (i = 0; i < count; ++i, ++first)
            arr[i] = *first;
    }

    template <typename T>
    constexpr vector<T>::vector(std::initializer_list<T> lst) {
        rsrv_sz = lst.size() << 2;
        arr = new T[rsrv_sz];
        for (auto &item: lst)
            arr[vec_sz++] = item;
    }

    template <typename T>
    constexpr vector<T>::vector(const vector<T> &other) {
        size_type i {};
        rsrv_sz = other.rsrv_sz;
        arr = new T[rsrv_sz];
        for (i = 0; i < other.vec_sz; ++i)
            arr[i] = other.arr[i];
        vec_sz = other.vec_sz;
    }

    template <typename T>
    constexpr vector<T>::vector(vector<T> &&other) noexcept {
        size_type i {};
        rsrv_sz = other.rsrv_sz;
        arr = new T[rsrv_sz];
        for (i = 0; i < other.vec_sz; ++i)
            arr[i] = std::move(other.arr[i]);
        vec_sz = other.vec_sz;
    }

    template <typename T>
    vector<T>::~vector() {
        delete [] arr;
    }

    template <typename T>
    constexpr vector<T> & vector<T>::operator = (const vector<T> &other) {
        
        if(this == &other)
        {
            return *this;
        }
        size_type i {};
        if (rsrv_sz < other.vec_sz) {
            rsrv_sz = other.vec_sz << 2;
            reallocate();
        }
        for (i = 0; i < other.vec_sz; ++i)
            arr[i] = other.arr[i];
        vec_sz = other.vec_sz;
        return *this;
    }

    template <typename T>
    constexpr vector<T> & vector<T>::operator = (vector<T> &&other) {
        size_type i {};
        if (rsrv_sz < other.vec_sz) {
            rsrv_sz = other.vec_sz << 2;
            reallocate();
        }
        for (i = 0; i < other.vec_sz; ++i)
            arr[i] = std::move(other.arr[i]);
        vec_sz = other.vec_sz;
        return *this;
    }

    template <typename T>
    constexpr vector<T> & vector<T>::operator = (std::initializer_list<T> lst) {
        if (rsrv_sz < lst.size()) {
            rsrv_sz = lst.size() << 2;
            reallocate();
        }
        vec_sz = 0;
        for (auto &item: lst)
            arr[vec_sz++] = item;
        return *this;
    }

    template <typename T>
    constexpr void vector<T>::assign(typename vector<T>::size_type count, const T &value) {
        size_type i {};
        if (count > rsrv_sz) {
            rsrv_sz = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i)
            arr[i] = value;
        vec_sz = count;
    }

    template <typename T>
    template <class InputIt>
    constexpr void vector<T>::assign(InputIt first, InputIt last) {
        size_type i {}, count = last - first;
        if (count > rsrv_sz) {
            rsrv_sz = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i, ++first)
            arr[i] = *first;
        vec_sz = count;
    }

    template <typename T>
    constexpr void vector<T>::assign(std::initializer_list<T> lst) {
        size_type i {}, count = lst.size();
        if (count > rsrv_sz) {
            rsrv_sz = count << 2;
            reallocate();
        }
        i = 0;
        for (auto &item: lst)
            arr[i++] = item;
    }


    template <typename T>
    constexpr inline typename vector<T>::iterator vector<T>::begin() noexcept {
        return arr;
    }

    template <typename T>
    constexpr inline typename vector<T>::const_iterator vector<T>::begin() const noexcept {
        return arr;
    }

    template <typename T>
    constexpr inline typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
        return arr;
    }

    template <typename T>
    constexpr inline typename vector<T>::iterator vector<T>::end() noexcept {
        return arr + vec_sz;
    }

    template <typename T>
    constexpr inline typename vector<T>::const_iterator vector<T>::end() const noexcept {
        return arr + vec_sz;
    }

    template <typename T>
    constexpr inline typename vector<T>::const_iterator vector<T>::cend() const noexcept {
        return arr + vec_sz;
    }

    template <typename T>
    constexpr inline typename vector<T>::reverse_iterator vector<T>::rbegin() noexcept {
        return reverse_iterator(arr + vec_sz);
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reverse_iterator vector<T>::crbegin() const noexcept {
        return reverse_iterator(arr + vec_sz);
    }

    template <typename T>
    constexpr inline typename vector<T>::reverse_iterator vector<T>::rend() noexcept {
        return reverse_iterator(arr);
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reverse_iterator vector<T>::crend() const noexcept {
        return reverse_iterator(arr);
    }


    template <typename T>
    inline void vector<T>::reallocate() {
        T *tarr = new T[rsrv_sz];
        memcpy(tarr, arr, vec_sz * sizeof(T));
        delete [] arr;
        arr = tarr;
    }


    template <typename T>
    constexpr inline bool vector<T>::empty() const noexcept {
        return vec_sz == 0;
    }

    template <typename T>
    constexpr inline typename vector<T>::size_type vector<T>::size() const noexcept{
        return vec_sz;
    }

    template <typename T>
    constexpr inline typename vector<T>::size_type vector<T>::max_size() const noexcept {
        return LNI_VECTOR_MAX_SZ;
    }

    template <typename T>
    constexpr inline typename vector<T>::size_type vector<T>::capacity() const noexcept {
        return rsrv_sz;
    }

    template <typename T>
    constexpr void vector<T>::resize(typename vector<T>::size_type sz) {
        if (sz > vec_sz) {
            if (sz > rsrv_sz) {
                rsrv_sz = sz;
                reallocate();
            }
        } else {
            size_type i {};
            for (i = vec_sz; i < sz; ++i)
                arr[i].~T();
        }
        vec_sz = sz;
    }

    template <typename T>
    constexpr void vector<T>::resize(typename vector<T>::size_type sz, const T &c) {
        if (sz > vec_sz) {
            if (sz > rsrv_sz) {
                rsrv_sz = sz;
                reallocate();
            }
            size_type i {};
            for (i = vec_sz; i < sz; ++i)
                arr[i] = c;
        } else {
            size_type i {};
            for (i = vec_sz; i < sz; ++i)
                arr[i].~T();
        }
        vec_sz = sz;
    }

    template <typename T>
    constexpr void vector<T>::reserve(typename vector<T>::size_type _sz) {
        if (_sz > rsrv_sz) {
            rsrv_sz = _sz;
            reallocate();
        }
    }

    template <typename T>
    constexpr void vector<T>::shrink_to_fit() {
        rsrv_sz = vec_sz;
        reallocate();
    }


    template <typename T>
    constexpr inline typename vector<T>::reference vector<T>::operator [](typename vector<T>::size_type idx) {
        return arr[idx];
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reference vector<T>::operator [](typename vector<T>::size_type idx) const {
        return arr[idx];
    }

    template <typename T>
    constexpr inline typename vector<T>::reference vector<T>::at(size_type pos) {
        return arr[pos];
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reference vector<T>::at(size_type pos) const {
        return arr[pos];
    }

    template <typename T>
    constexpr inline typename vector<T>::reference vector<T>::front() {
        return arr[0];
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reference vector<T>::front() const {
        return arr[0];
    }

    template <typename T>
    constexpr inline typename vector<T>::reference vector<T>::back() {
        return arr[vec_sz - 1];
    }

    template <typename T>
    constexpr inline typename vector<T>::const_reference vector<T>::back() const {
        return arr[vec_sz - 1];
    }


    template <typename T>
    constexpr inline T * vector<T>::data() noexcept {
        return arr;
    }

    template <typename T>
    constexpr inline const T * vector<T>::data() const noexcept {
        return arr;
    }


    template <typename T>
    template <class ... Args>
    constexpr void vector<T>::emplace_back(Args && ... args) {
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        arr[vec_sz] = std::move( T( std::forward<Args>(args) ... ) );
        ++vec_sz;
    }

    template <typename T>
    constexpr void vector<T>::push_back(const T &val) {
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        arr[vec_sz] = val;
        ++vec_sz;
    }

    template <typename T>
    constexpr void vector<T>::push_back(T &&val) {
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        arr[vec_sz] = std::move(val);
        ++vec_sz;
    }

    template <typename T>
    constexpr void vector<T>::pop_back() {
        --vec_sz;
        arr[vec_sz].~T();
    }


    template <typename T>
    template <class ... Args>
    constexpr typename vector<T>::iterator vector<T>::emplace(typename vector<T>::const_iterator it, Args && ... args) {
        iterator iit = &arr[it - arr];
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (vec_sz - (it - arr)) * sizeof(T));
        (*iit) = std::move( T( std::forward<Args>(args) ... ) );
        ++vec_sz;
        return iit;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, const T &val) {
        iterator iit = &arr[it - arr];
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (vec_sz - (it - arr)) * sizeof(T));
        (*iit) = val;
        ++vec_sz;
        return iit;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, T &&val) {
        iterator iit = &arr[it - arr];
        if (vec_sz == rsrv_sz) {
            rsrv_sz <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (vec_sz - (it - arr)) * sizeof(T));
        (*iit) = std::move(val);
        ++vec_sz;
        return iit;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, typename vector<T>::size_type cnt, const T &val) {
        iterator f = &arr[it - arr];
        if (!cnt) return f;
        if (vec_sz + cnt > rsrv_sz) {
            rsrv_sz = (vec_sz + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (vec_sz - (it - arr)) * sizeof(T));
        vec_sz += cnt;
        for (iterator it = f; cnt--; ++it)
            (*it) = val;
        return f;
    }

    template <typename T>
    template <class InputIt>
    constexpr typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, InputIt first, InputIt last) {
        iterator f = &arr[it - arr];
        size_type cnt = last - first;
        if (!cnt) return f;
        if (vec_sz + cnt > rsrv_sz) {
            rsrv_sz = (vec_sz + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (vec_sz - (it - arr)) * sizeof(T));
        for (iterator it = f; first != last; ++it, ++first)
            (*it) = *first;
        vec_sz += cnt;
        return f;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, std::initializer_list<T> lst) {
        size_type cnt = lst.size();
        iterator f = &arr[it - arr];
        if (!cnt) return f;
        if (vec_sz + cnt > rsrv_sz) {
            rsrv_sz = (vec_sz + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (vec_sz - (it - arr)) * sizeof(T));
        iterator iit = f;
        for (auto &item: lst) {
            (*iit) = item;
            ++iit;
        }
        vec_sz += cnt;
        return f;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::erase(typename vector<T>::const_iterator it) {
        iterator iit = &arr[it - arr];
        (*iit).~T();
        memmove(iit, iit + 1, (vec_sz - (it - arr) - 1) * sizeof(T));
        --vec_sz;
        return iit;
    }

    template <typename T>
    constexpr typename vector<T>::iterator vector<T>::erase(typename vector<T>::const_iterator first, typename vector<T>::const_iterator last) {
        iterator f = &arr[first - arr];
        if (first == last) return f;
        for ( ; first != last; ++first)
            (*first).~T();
        memmove(f, last, (vec_sz - (last - arr)) * sizeof(T));
        vec_sz -= last - first;
        return f;
    }

    template <typename T>
    constexpr void vector<T>::swap(vector<T> &rhs) {
        size_t tvec_sz = vec_sz,
                trsrv_sz = rsrv_sz;
        T *tarr = arr;

        vec_sz = rhs.vec_sz;
        rsrv_sz = rhs.rsrv_sz;
        arr = rhs.arr;

        rhs.vec_sz = tvec_sz;
        rhs.rsrv_sz = trsrv_sz;
        rhs.arr = tarr;
    }

    template <typename T>
    constexpr void vector<T>::clear() noexcept {
        size_type i {};
        for (i = 0; i < vec_sz; ++i)
            arr[i].~T();
        vec_sz = 0;
    }


    template <typename T>
    constexpr bool vector<T>::operator == (const vector<T> &rhs) const {
        if (vec_sz != rhs.vec_sz) return false;
        size_type i {};
        for (i = 0; i < vec_sz; ++i)
            if (arr[i] != rhs.arr[i])
                return false;
        return true;
    }

    template <typename T>
    constexpr bool vector<T>::operator != (const vector<T> &rhs) const {
        if (vec_sz != rhs.vec_sz) return true;
        size_type i {};
        for (i = 0; i < vec_sz; ++i)
            if (arr[i] != rhs.arr[i])
                return true;
        return false;
    }

    template <typename T>
    constexpr bool vector<T>::operator < (const vector<T> &rhs) const {
        size_type i {}, j {}, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
        for (i = 0; i < ub; ++i)
            if (arr[i] != rhs.arr[i])
                return arr[i] < rhs.arr[i];
        return vec_sz < rhs.vec_sz;
    }

    template <typename T>
    constexpr bool vector<T>::operator <= (const vector<T> &rhs) const {
        size_type i {}, j {}, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
        for (i = 0; i < ub; ++i)
            if (arr[i] != rhs.arr[i])
                return arr[i] < rhs.arr[i];
        return vec_sz <= rhs.vec_sz;
    }

    template <typename T>
    constexpr bool vector<T>::operator > (const vector<T> &rhs) const {
        size_type i {}, j {}, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
        for (i = 0; i < ub; ++i)
            if (arr[i] != rhs.arr[i])
                return arr[i] > rhs.arr[i];
        return vec_sz > rhs.vec_sz;
    }

    template <typename T>
    constexpr bool vector<T>::operator >= (const vector<T> &rhs) const {
        size_type i {}, j {}, ub = vec_sz < rhs.vec_sz ? vec_sz : rhs.vec_sz;
        for (i = 0; i < ub; ++i)
            if (arr[i] != rhs.arr[i])
                return arr[i] > rhs.arr[i];
        return vec_sz >= rhs.vec_sz;
    }

    #pragma clang diagnostic pop

}

template <class T>
using DynamicArray = lni::vector<T>;

// #include <vector>

// template <class T>
// using DynamicArray = std::vector<T>;
