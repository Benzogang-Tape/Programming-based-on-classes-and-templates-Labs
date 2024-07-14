#include <iostream>
#include "mymath/mymath.hpp"
#include "MyLib/MyLib.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    MyLib::PrintInfo("Some Info");
    return 0;
}
