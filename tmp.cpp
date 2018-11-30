#include <iostream>

int main() {
    double hot, cold, water;
    double cur_hot, cur_water;
    std::cout << "请以此输入最高温度，最低温度，最低湿度" << std::endl;
    std::cin >> hot >> cold >> water;
    std::cout << "请输入当前温度，湿度" << std::endl;
    while (std::cin >> cur_hot >> cur_water) {
        if (cur_hot > hot) std::cout << "降温\n";
        if (cur_hot < cold) std::cout << "加热\n";
        if (cur_water < water) std::cout << "加湿\n";
        std::cout << "请输入当前温度，湿度" << std::endl;
    }
    return 0;
}
