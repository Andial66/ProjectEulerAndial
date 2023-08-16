#include <iostream>
#include <cmath>

int main() {

    bool end = false;
    for (int a=1; a<1000 && !end; a++) {
        for (int b=a+1; b<1000 && !end; b++) {
            int c = (int) std::sqrt(a*a + b*b);
            if (c*c==a*a + b*b && a+b+c == 1000) {
                std::cout << a << " " << b << " " << c << std::endl;
                std::cout << a*b*c << std::endl;
                end = true;
            }
        }
    }

    return 0;
}