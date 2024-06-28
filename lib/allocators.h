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
	AllocatorMap() {
		data = reinterpret_cast<T*>(::operator new(reserved * sizeof(T)));
	}
	~AllocatorMap() 
	{
		::operator delete(data);
	}

	T* allocate(size_t numObjects)
	{
		//cout << numObjects << endl;
		// выход за границу зарезервированной памяти
		if (cur + numObjects > reserved) {
			throw::std::bad_alloc();
		}
		T* res = data + cur;
		cur += numObjects;
		return res;
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
	T* data;
	size_t cur = 0;
};

//-------------------------------------------------------------------------------
// Аллокатор для вектора
template<class T, size_t reserved>
class AllocatorVec
{
public:
	AllocatorVec() {
		data = reinterpret_cast<T*>(::operator new(reserved * sizeof(T)));
	}

	~AllocatorVec() 
	{
		::operator delete(data);
	}

	T* allocate(size_t numObjects)
	{
		// выход за границу зарезервированной памяти
		if (numObjects > reserved) {
			throw::std::bad_alloc();
		}
		return data;
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
	T* data;
};
