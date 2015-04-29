#include <iostream>
#include <cmath>

int main()
{
    long N;
    std::cin >> N;
    bool* nums = new bool[N];

    for (long i = 0; i < N; i++)
        nums[i] = 1;

    for (long i = 2; i < ((int) std::sqrt(N) + 2); i++)
        for (long j = i * i; j <= N; j += i)
            nums[j - 1] = 0;

    for (long i = 1; i < N; i++)
        if (nums[i])
            std::cout << (i + 1) << std::endl;

    delete nums;
    return 0;
}