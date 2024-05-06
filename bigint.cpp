#include "bigint.hpp"

namespace ml {
//Public
	BigInt::BigInt(int val) : is_positive(true) {
		CheckIsPositive(val);
		SettingSetNumber(val);
	}

	BigInt::BigInt(const std::string& val) : is_positive(true) {
		CheckIsPositive(val);
	}

	BigInt::BigInt(const std::vector<int>& val) : is_positive(true) {
		CheckIsPositive(val);
	}

	std::vector<int> BigInt::GetVectorArray() const noexcept {
		return number;
	}

//Private
	void BigInt::CheckIsPositive(int val) noexcept {
		is_positive = val > 0 ? true : false;
	}

	void BigInt::CheckIsPositive(const std::string& val) noexcept {
		if (!val.empty()) {
			is_positive = val.front() == '-' ? false : true;
		} 
	}

	void BigInt::CheckIsPositive(const std::vector<int>& val) noexcept {
		if (!val.empty()) {
			is_positive = val.front() > 0 ? true : false;
		}
	}

	void BigInt::SettingSetNumber(int val) {
		std::string str_val = std::to_string(val);
		for (size_t i = 0; i < str_val.length(); ++i) {
			number.push_back(str_val[i] - '0');
		}
	}
}