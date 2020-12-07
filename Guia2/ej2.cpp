#include <iostream>

using namespace std;

int C(size_t n, size_t k)
{
    if (k == n || k == 0)
    {
        return 1;
    }
    return C(n - 1, k) + C(n - 1, k - 1);
}

int main(void)
{

    cout << C(4, 2) << endl;
}