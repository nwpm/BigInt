#include "bigint.hpp"

namespace ml {
//Public
	BigInt::BigInt(int val) : is_positive(true) {
		CheckIsPositive(val);
		SettingSetNumber(val);
	}

	BigInt::BigInt(const std::string& val) : is_positive(true) {
		CheckIsPositive(val);
		SetFromStringNumber(val);
		Coup();
	}

	BigInt::BigInt(const BigInt& other) : is_positive(other.is_positive) {
		number = other.number;
		//or you can use
		//number.resize(other.number.size());
		//std::copy(other.number.begin(), other.number.end(), number.begin());
	}

	BigInt& BigInt::operator=(const BigInt& other) {
		BigInt tmp(other);
		SwapBigInt(tmp);
		return *this;
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
		if (val == 0) {
			number.push_back(0);
		}
		while (val != 0){
			number.push_back(val % 10);
			val /= 10;
		}
	}

	void BigInt::SetFromStringNumber(const std::string& str) noexcept {
		size_t i = 0;
		if (!is_positive) {
			++i;
		}
		for (; i < str.length(); ++i) {
			number.push_back(str[i] - '0');
		}
	}

	void BigInt::Coup() {
		for (size_t i = 0; i < number.size() / 2; ++i) {
			std::swap(number[i], number[number.size() - 1 - i]);
		}
	}

	void BigInt::SwapBigInt(BigInt& other) {
		std::swap(is_positive, other.is_positive);
		std::swap(number, other.number);
	}
}