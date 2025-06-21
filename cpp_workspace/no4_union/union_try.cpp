#include <iostream>

int main() {
    union {
        float data_n[4];
        float normal[3];
    } u;

    u.data_n[0] = 1.0f;
    u.data_n[1] = 2.0f;
    u.data_n[2] = 3.0f;
    u.normal[2] = 4.0f;

    std::cout << "data_n[0]: " << u.data_n[0] << std::endl;
    std::cout << "data_n[1]: " << u.data_n[1] << std::endl;
    std::cout << "data_n[2]: " << u.data_n[2] << std::endl;
    std::cout << "data_n[3]: " << u.data_n[3] << std::endl;

    std::cout << "normal[0]: " << u.normal[0] << std::endl;
    std::cout << "normal[1]: " << u.normal[1] << std::endl;
    std::cout << "normal[2]: " << u.normal[2] << std::endl;

    return 0;
}
/*
zhangzh6@zhangzh6-ThinkPad-P52:~/cpp_ws$ ./union_try 
data_n[0]: 1
data_n[1]: 2
data_n[2]: 4
data_n[3]: 3.07249e-41
normal[0]: 1
normal[1]: 2
normal[2]: 4
*/
