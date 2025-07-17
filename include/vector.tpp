// vector.tpp
#ifndef INCLUDE_VECTOR_TPP_H
#define INCLUDE_VECTOR_TPP_H

#include "maths_ops.hpp"

template<typename T>
vec<T> vec<T>::operator+(const vec<T>& other) const {
    if (size() != other.size()) throw std::invalid_argument("Size mismatch");
    vec<T> result(size());
    for (size_t i = 0; i < size(); ++i)
        result[i] = data_[i] + other[i];
    return result;
}

template<typename T>
vec<T> vec<T>::operator-(const vec<T>& other) const {
    if (size() != other.size()) throw std::invalid_argument("Size mismatch");
    vec<T> result(size());
    for (size_t i = 0; i < size(); ++i)
        result[i] = data_[i] - other[i];
    return result;
}

template<typename T>
vec<T> vec<T>::operator*(T scalar) const {
    vec<T> result(size());
    for (size_t i = 0; i < size(); ++i)
        result[i] = data_[i] * scalar;
    return result;
}

template<typename T>
vec<T> vec<T>::operator/(T scalar) const {
    if (scalar == T{}) throw std::invalid_argument("Division by zero");
    vec<T> result(size());
    for (size_t i = 0; i < size(); ++i)
        result[i] = data_[i] / scalar;
    return result;
}

template<typename T>
vec<T>& vec<T>::operator+=(const vec<T>& other) {
    if (size() != other.size()) throw std::invalid_argument("Size mismatch");
    for (size_t i = 0; i < size(); ++i)
        data_[i] += other[i];
    return *this;
}

template<typename T>
vec<T>& vec<T>::operator-=(const vec<T>& other) {
    if (size() != other.size()) throw std::invalid_argument("Size mismatch");
    for (size_t i = 0; i < size(); ++i)
        data_[i] -= other[i];
    return *this;
}

template<typename T>
vec<T>& vec<T>::operator*=(T scalar) {
    for (auto& val : data_) val *= scalar;
    return *this;
}

template<typename T>
vec<T>& vec<T>::operator/=(T scalar) {
    if (scalar == T{}) throw std::invalid_argument("Division by zero");
    for (auto& val : data_) val /= scalar;
    return *this;
}

template<typename T>
T vec<T>::dot(const vec<T>& other) const {
    if (size() != other.size()) throw std::invalid_argument("Size mismatch");
    T result = T{};
    for (size_t i = 0; i < size(); ++i)
        result += data_[i] * other[i];
    return result;
}

template<typename T>
T vec<T>::norm() const {
    return std::sqrt(dot(*this));
}

template<typename T>
void vec<T>::print() const {
    std::cout << "[ ";
    for (const auto& val : data_) std::cout << val << " ";
    std::cout << "]\n";
}

#endif // INCLUDE_VECTOR_TPP_H