#include <iostream>
#include <vector>


std::vector<double> SumVectors(const std::vector<double> &vec1, const std::vector<double> &vec2) {
	if (vec1.size() != vec2.size()) {
		return std::vector<double>(0);
	}
	std::vector<double> resVec(vec1.size());
	for (size_t i{}; i < vec1.size(); ++i) {
		resVec[i] = vec1[i] + vec2[i];
	}
	return resVec;
}

void PrintVec(const std::vector<double> &v) {
	if (v.empty()) {
		std::cout << "Vector is empty" << std::endl;
		return;
	}
	std::cout << "Vector:" << std::endl;
	size_t i{};
	std::cout << v[i++];
	for (; i < v.size(); ++i) {
		std::cout << " " << v[i];
	}
	std::cout << std::endl;
}

void InitVector(std::vector<double> &v) {
	for (size_t i{}; i < v.size(); ++i) {
		v[i] = 0.1 * static_cast<double>(i) * (static_cast<int>(i % 2) * -1);
	}
}

int main(){
	std::vector<double> vec1(25), vec2(25);
	InitVector(vec1);
	InitVector(vec2);
	PrintVec(vec1);
	PrintVec(vec2);
	PrintVec(SumVectors(vec1, vec2));
	return 0;
}
