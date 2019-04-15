#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

int main()
{
    double start_t, end_t; // timer

    // allocate 0.1 billion int space
    start_t = clock();
    std::vector<int> V(100000000);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // init data
    start_t = clock();
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distribution(1, 100000000);
    for (size_t i = 0; i < V.size(); ++i)
        V[i] = distribution(generator);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // sort
    start_t = clock();
    std::sort(V.begin(), V.end());
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    return 0;
}