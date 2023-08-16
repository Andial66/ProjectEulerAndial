#include <iostream>
#include <string>
#include <vector>

std::string reverse(std::string &num) {
    std::string res;
    for (int i=num.size()-2; i>=0; i--) res.push_back(num[i]);
    return res;
}

std::string sum(std::string &x, std::string &y) {
    std::string res;

    int carry = 0;
    for (int i=0; i<y.size(); i++) {
        int cur = (x[i] - '0') + (y[i] - '0') + carry;
        if (cur >= 10) {
            carry = 1; cur -= 10;
        } else carry = 0;

        res.push_back(char(cur) + '0');
    }

    for (int i=y.size(); i<x.size(); i++) {
        int cur = (x[i] - '0') + carry;
        if (cur >= 10) {
            carry = 1; cur -= 10;
        } else carry = 0;

        res.push_back((char)cur + '0');
    }

    if (carry == 1) res.push_back('1');

    return res;
}

int main() {
    std::vector<std::string> numbers(0);

    std::string line;
    while (std::getline(std::cin, line)) numbers.push_back(reverse(line));

    std::string res = numbers[0];
    for (int i=1; i<numbers.size(); i++) res = sum(res, numbers[i]);

    for(int i=0; i<10; i++) std::cout << res[res.size()-1-i];
    std::cout << std::endl; 

    return 0;
}
