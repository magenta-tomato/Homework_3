#pragma once

#include <map>
#include <vector>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------
// Аллокатора для map
template<class T, size_t reserved>
class AllocatorMap
{
public:
	~AllocatorMap() {}
	AllocatorMap() {}

	T* allocate(size_t numObjects)
	{
		//cout << numObjects << endl;
		// выход за границу зарезервированной памяти
		if (cur + numObjects > reserved) {
			throw::std::bad_alloc();
		}
		T* res = data + cur;
		cur += numObjects;
		return reinterpret_cast<T*>(res);
	}
	void deallocate(T* data, std::size_t numObjects) {}

	using value_type = T;

	template<class U>
	struct rebind
	{
		typedef AllocatorMap<U, reserved> other;
	};

private:
	//зарезервированная память
	T data[reserved];
	size_t cur = 0;
};

//-------------------------------------------------------------------------------
// Аллокатор для вектора
template<class T, size_t reserved>
class AllocatorVec
{
public:

	~AllocatorVec() {}
	AllocatorVec() {}

	T* allocate(size_t numObjects)
	{
		// выход за границу зарезервированной памяти
		if (numObjects > reserved) {
			throw::std::bad_alloc();
		}
		return reinterpret_cast<T*>(data);
	}
	void deallocate(T* data, std::size_t numObjects) {}

	using value_type = T;

	template <class U>
	struct rebind
	{
		typedef AllocatorVec<U, reserved> other;
	};

private:
	//зарезервированная память
	T data[reserved];
	size_t cur = 0;
};