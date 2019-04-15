#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>

void binary_search(std::vector<int> &V, int key)
{
    int L = 0, R = V.size() - 1;
    // using size_t may cause overflow 0 - 1 -> Maximum (since R is decreasing)
    while (L <= R)
    {
        int M = L + (R - L) / 2;
        if (V[M] < key)
            L = M + 1;
        else if (key < V[M])
            R = M - 1;
        else
        {
            std::cout << "Index:" << M << " Successfully find!" << std::endl;
            return;
        }
    }
}

int main()
{
    double start_t, end_t; //timer

    // allocate 0.1 billion int space
    start_t = clock();
    std::vector<int> V(100000000);
    // allocate temp place to store ordered numbers
    std::vector<int> Vtemp(V.size());
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // init data
    start_t = clock();
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distribution(1, 500000);
    for (size_t i = 0; i < V.size(); ++i)
        V[i] = distribution(generator);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // stl_sort and search
    start_t = clock();
    int key = 333;
    std::sort(V.begin(), V.end());
    binary_search(V, key);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    return 0;
}