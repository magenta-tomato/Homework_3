#pragma once
#include <memory>
using namespace std;

template<class T, class Allocator = std::allocator<T>>
class CustomVector
{

public:
	void push_back(const T& x)
	{
		if (count == capacity) {
			capacity = capacity * 2 + 1;
			T* newData = std::allocator_traits<Allocator>::allocate(alloc, capacity);
			if (count > 0) {

				std::copy(data, data + count, newData);
			}
			data = newData;
		}
		std::allocator_traits<Allocator>::construct(alloc, data + count, x);
		count++;
	}

	T* begin() { return data; }
	T* end() { return data + count; }

private:
	int count = 0;
	int capacity = 0;
	T* data = nullptr;
	Allocator alloc;
};
