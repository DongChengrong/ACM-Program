#include <iostream>

int main() {
    double hot, cold, water;
    double cur_hot, cur_water;
    std::cout << "���Դ���������¶ȣ�����¶ȣ����ʪ��" << std::endl;
    std::cin >> hot >> cold >> water;
    std::cout << "�����뵱ǰ�¶ȣ�ʪ��" << std::endl;
    while (std::cin >> cur_hot >> cur_water) {
        if (cur_hot > hot) std::cout << "����\n";
        if (cur_hot < cold) std::cout << "����\n";
        if (cur_water < water) std::cout << "��ʪ\n";
        std::cout << "�����뵱ǰ�¶ȣ�ʪ��" << std::endl;
    }
    return 0;
}
