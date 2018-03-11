#include <iostream>
#include <complex.h>
#include <vector>

using namespace std;

template <typename T>
void test_equal(T a, T b, std::string test_name)
{
    if(a != b) {
        std::cout << " [TEST FAILED] " << test_name << std::endl;
    } else {
        std::cout << " [TEST PASSED] " << test_name << std::endl;
    }
}

int main()
{
    Complex a(2, 3);
    Complex b(-1, 5);
    std::cout << (a != b);
    test_equal(a+b, Complex(1, 8), string("Addition function"));
    return 0;
}
