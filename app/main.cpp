#include "allocators.h"
#include "customVector.h"

#include <iostream>
using namespace std;

int factorial(unsigned int n) {
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}


int main(int argc, char* argv[])
{
	cout << "Default map, default allocator" << endl;
	map<int, int> mapDefaultAllocator;
	for (int i = 0; i < 10; i++) {
		mapDefaultAllocator.insert(make_pair(i, factorial(i)));
	}
	for (auto it = mapDefaultAllocator.begin(); it != mapDefaultAllocator.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	cout << "\nDefault map, custom allocator\n" << endl;
	map<int, int, std::less<int>, AllocatorMap<int, 10> > mapCustomAllocator;
	for (int i = 0; i < 10; i++) {
		mapCustomAllocator[i] = factorial(i);
	}
	for (auto it = mapCustomAllocator.begin(); it != mapCustomAllocator.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	
	cout << "\nCustom vector, default allocator" << endl;
	CustomVector<int> customVectorDefaultAllocator;
	for (int i = 0; i < 10; i++) {
		customVectorDefaultAllocator.push_back(factorial(i));
	}
	for (auto i : customVectorDefaultAllocator ) {
		cout << i << endl;
	}

	cout << "\nCustom vector, custom allocator" << endl;
	CustomVector<int, AllocatorVec<int, 10>> customVectorCustomAllocator;
	for (int i = 0; i < 10; i++) {
		customVectorCustomAllocator.push_back(factorial(i));
	}
	for (auto i : customVectorCustomAllocator) {
		cout << i << endl;
	}
	
}
