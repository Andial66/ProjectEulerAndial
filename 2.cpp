#include <iostream>

int main() {
    int f1 = 1; int f2 = 1;
    int cnt = 0;

    while (f1 < 4000000) {
        int ftemp = f1 + f2;
        f1 = f2; f2 = ftemp;

        if (!(f1 & 1)) cnt += f1;
    }

    std::cout << cnt << std::endl;

    return 0;
}
