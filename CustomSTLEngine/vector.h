#pragma once

#include <iostream>

template<typename T>
class Vector
{
public:
	Vector();
	Vector(size_t size);
	Vector(size_t size, T value);

	~Vector();

	const T& operator[](size_t index) const;

	size_t size() const;

	void push_back(const T value);

private:
	void __realloc(size_t capacity);

private:
	T* m_Data = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
};

template<typename T>
Vector<T>::Vector() {
	Vector::__realloc(2);
}

template<typename T>
Vector<T>::Vector(size_t size) {
	Vector::__realloc(size);
}

template<typename T>
Vector<T>::Vector(size_t size, T value) {
	Vector::__realloc(size);

	m_Size = size;

	for (size_t i = 0; i < m_Size; ++i)
		m_Data[i] = value;
}

template<typename T>
Vector<T>::~Vector() {
	delete[] m_Data;
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	return m_Data[index];
}

template<typename T>
size_t Vector<T>::size() const {
	return m_Size;
}

template<typename T>
void Vector<T>::__realloc(size_t new_capacity) {
	T* new_block = new T[new_capacity];

	m_Size = new_capacity < m_Size ? new_capacity : m_Size;
	std::copy(m_Data, m_Data + m_Size, new_block);

	delete[] m_Data;
	m_Data = new_block;
	m_Capacity = new_capacity;
}

template<typename T>
void Vector<T>::push_back(T value) {
	if (m_Size == m_Capacity)
		Vector::__realloc(m_Capacity + m_Capacity / 2);

	m_Data[m_Size] = value;
	m_Size++;
}
