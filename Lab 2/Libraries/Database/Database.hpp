//
// Created by DJ Tape on 26.02.2024.
//

#ifndef LABS_DATABASE_HPP
#define LABS_DATABASE_HPP

#include <iostream>

namespace Database {

	template <typename T>
	class Database {
	private:
		T* vec{};
		size_t size{};
		size_t capacity{};
		size_t growthFactor = 2;

	public:

		Database() {
			vec = new T[1];
			this->capacity = 1;
			//size = 0;
		}

		explicit Database(size_t size) {
			vec = new T[size];
			this->capacity = size;
			this->size = size;
		}

		~Database() {
			delete[] vec;
			vec = nullptr;
		}
/*
		Database<T>& operator= (const Database<T>& v) {
			if (this == &v)
				return *this; // Защита от самоприсваивания
			this->reset(v);
			return *this;
		}
*/
		T& operator[] (const size_t index) {
			if (index < size)
				return vec[index];
			std::cout << "Index Error" << std::endl;
		}

		const T& operator[] (const size_t index) const {
			if (index < size)
				return vec[index];
			std::cout << "Index Error" << std::endl;
		}

		void reset() {
			delete[] vec;
			vec = nullptr;
		}
/*
		void reset(const Database<T>& v) {
			size = 0;
			this->pushBack(v);
		}
*/
		void clear() {
			for(size_t i{}; i < capacity; ++i)
				delete vec[i];
			size = 0;
		}

		Database<T>& pushBack(const T* data) { //TODO: Возможно не нужен const
			if (size == capacity) {
				T* temp = new T[capacity * growthFactor];

				for (size_t i{}; i < size; i++) {
					temp[i] = vec[i];
				}

				delete[] vec;
				capacity *= growthFactor;
				vec = temp;
			}
			vec[size] = *data;
			size++;
			return *this;
		}
/*
		Database<T>& pushBack(const Database<T>& v) {
			if (v.getSize() == 0)
				return *this;
			for (size_t i{}; i < v.getSize(); i++) {
				this->pushBack(v[i]);
			}
			return *this;
		}
*/
		Database<T>& popBack(size_t pop_size = 1) {
			delete vec[size - 1];
			size -= pop_size;
			return *this;
		}
/*
		Database<T>& reverse() {
			size_t half = static_cast<size_t>(size / 2);
			for (size_t i{}; i < half; i++) {
				std::swap(vec[i], vec[size - 1 - i]);
			}
			return *this;
		}

		T getDataByIndex(size_t index) const {
			if (index >= 0 and index < size)
				return vec[index];
			std::cout << "Index Error" << std::endl;
		}
*/
		[[nodiscard]] size_t getSize() const {
			return size;
		}

		[[nodiscard]] size_t getCapacity() const {
			return capacity;
		}
/*
		void print() const {
			for (size_t i{}; i < size; i++) {
				std::cout << vec[i];
			}
			std::cout << std::endl;
		}

		void copy(Database<T>& v) {
			if (v.getSize() == 0) {
				for (size_t i{}; i < size; i++) {
					v.pushBack(vec[i]);
				}
			}
			else
				std::cout << "Vector is not empty" << std::endl;
		}

		bool isEqual(const Database<T>& v) const {
			if (v.getSize() != size)
				return false;
			size_t counter{};
			for (size_t i{}; i < size; i++) {
				if (vec[i] == v[i])
					counter++;
			}
			if (counter == size)
				return true;
			return false;
		}

		Database<T>& slice(Database<T>& slice, const size_t begin, const size_t end) {
			if (slice.getSize() == 0) {
				for (size_t i = begin; i < end; i++) {
					slice.pushBack((*this)[i]);
				}
				return slice;
			}
			std::cout << "Vector is not empty" << std::endl;
			return *this;
		}

		Database<T>& getLastWord(Database<T>& v) const {
			if (v.getSize() == 0 and this->getSize() > 1) {
				for (size_t elem = this->getSize() - 2; (*this)[elem] != ' '; elem--) {
					v.pushBack((*this)[elem]);
					if (elem == 0)
						break;
				}
				v.reverse();
				return v;
			}
			std::cout << "Source Vector is empty or destination Vector is not empty" << std::endl;
			return v;
		}
*/
	};

} // Database

#endif //LABS_DATABASE_HPP
