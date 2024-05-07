#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>
#include <vector>

namespace ml {
	class BigInt {
	public:

		BigInt() = default;
		BigInt(int val);
		BigInt(const std::string& val);

		BigInt(const BigInt& other);
		BigInt& operator=(const BigInt& other);

		//for test
		std::vector<int> GetVectorArray() const noexcept;

	private:

		bool is_positive;
		std::vector<int> number;

		void CheckIsPositive(int val) noexcept;
		void CheckIsPositive(const std::string& val) noexcept;
		void CheckIsPositive(const std::vector<int>& val) noexcept;

		void SettingSetNumber(int val);
		void SetFromStringNumber(const std::string& str) noexcept;
		void Coup();
		void SwapBigInt(BigInt& other);
	};
}

#endif // !BIG_INT_H