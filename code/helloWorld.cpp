#include <iostream>
#include <thread>

void hello(){
    std::cout << "hello world!" << std::endl;
}

int main(){
    std::thread t(hello); //创建一个thread对象，参数为函数名
    t.join(); // 等待线程结束
    return 0;
}
