#include <iostream>

int main() {

    int cnt = 0;
    for (int i=3; i<1000; i++)
        if (i%3==0 || i%5==0) 
            cnt += i;

    std::cout << cnt << std::endl;

    return 0;
}