#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace maya {

	//�ʏ�̐������}�������ɕϊ�����
	template <typename NormalNum, typename MayaNum>
	void mayaNumber(NormalNum num_, std::vector<MayaNum>& maya_num_) {
		//�e�ʂ̏���l
		constexpr NormalNum num_20 = (NormalNum)20;
		constexpr NormalNum num_18 = (NormalNum)18;
		constexpr NormalNum num_0 = (NormalNum)0;
		//�v�f������
		maya_num_.clear();
		//���̐�����0�ȉ��̏ꍇ
		if (num_ <= num_0) {
			maya_num_.emplace_back((MayaNum)0);
			return;
		}
		//1���ڂ�I�� (0~19)
		maya_num_.emplace_back((MayaNum)(num_ % num_20));
		if ((num_ /= num_20) == 0) return;
		//2���ڂ�I�� (0~17)
		maya_num_.emplace_back((MayaNum)(num_ % num_18));
		if ((num_ /= num_18) == 0) return;
		//3���ڈȍ~��I�� (0~19)
		while (true) {
			maya_num_.emplace_back((MayaNum)(num_ % num_20));
			if ((num_ /= num_20) == 0) return;
		}
	}
	template <typename MayaNum>
	void mayaNumber(const float num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	template <typename MayaNum>
	void mayaNumber(const double num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	template <typename MayaNum>
	void mayaNumber(const long double num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	//�}���������o�͂���
	template <typename MayaNum>
	void mayaNumberOutput(const std::vector<MayaNum>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << maya_num_[i] << ',';
	}
	template <>
	void mayaNumberOutput(const std::vector<unsigned char>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << (int)maya_num_[i] << ',';
	}
	template <>
	void mayaNumberOutput(const std::vector<signed char>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << (int)maya_num_[i] << ',';
	}
	//�ʏ�̐������}�������ɕϊ����ďo�͂���
	template <typename NormalNum, typename MayaNum>
	void mayaNumberOutput(const NormalNum& num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber(num_, maya_num_);
		mayaNumberOutput(maya_num_);
	}
	//�ʏ�̐������}�������ɕϊ����ďo�͂���
	template <typename NormalNum>
	void mayaNumberOutput(const NormalNum& num_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberOutput(maya_num_);
	}

	//�}�������𕶎��`���ɕϊ�����
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::u32string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;)
			str_.push_back((char32_t)((MayaNum)0x1D2E0 + maya_num_[--i]));
	}
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::u16string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;) {
			str_.push_back((char16_t)0xD834);
			str_.push_back((char16_t)((MayaNum)0xDEE0 + maya_num_[--i]));
		}
	}
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;) {
			str_.push_back((char)0xF0);
			str_.push_back((char)0x9D);
			str_.push_back((char)0x8B);
			str_.push_back((char)((MayaNum)0xA0 + maya_num_[--i]));
		}
	}
	//�ʏ�̐������}�������̕����`���ɕϊ�����
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::u16string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::u16string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::u32string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::u32string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
}