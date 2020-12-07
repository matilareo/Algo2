#include <iostream>

using namespace std;

int sum_of_squares(int n)
{
    if (!n)
        return 0;
    return n * n + sum_of_squares(n - 1);
}

int main(void)
{

    cout << sum_of_squares(3) << endl;
}