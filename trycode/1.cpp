#include <cstdio>
#include <iostream>
#include <thread>
#include <chrono>


int main(){
    std::thread t1{ //在创建线程的时候就开始执行
        [](){
            for(int i=1;i<=10;++i){
                std::cout << "1" << std::endl;
                std::this_thread::sleep_for(
                        std::chrono::duration<double, std::milli> (100)
                        );
            }
        }
    };

    std::thread t2{
        [](){
            for(int i=1;i<=10;++i){
                std::cout << "2" << std::endl;
                std::this_thread::sleep_for(
                        std::chrono::duration<double, std::milli> (500)
                        );
            }
        }
    };
    t2.detach();
    std::cout << "t2 end!" << std::endl;
    t1.join();
    std::cout << "in main" << std::endl;
    return 0;
}
