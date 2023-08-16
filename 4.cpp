#include <iostream>
#include <vector>

bool isPalindrome(int x) {
    std::vector<int> digits(0);

    while (x>0) {
        digits.push_back(x%10); x/=10;
    }

    for (int i=0; i<digits.size()/2; i++)
        if (digits[i] != digits[digits.size()-1-i])
            return false;

    return true;
}

int main() {
    int best = 1;

    for (int i=100; i<1000; i++)
        for (int j=100; j<1000; j++)
            if (isPalindrome(i*j) && best < i*j)
                best = i*j;

    std::cout << best << std::endl;

    return 0;
}