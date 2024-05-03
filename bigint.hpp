#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>

namespace ml {
	class BigInt {
	public:

		BigInt() = default;


	private:
		size_t capacity = 0;
		size_t size_ = 0;
		char* arr_ = nullptr;
	};
}

#endif // !BIG_INT_H