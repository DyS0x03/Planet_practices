#include <iostream>
#include <vector>
#include <ctime>
#include <random>

void merge(std::vector<int> &V, std::vector<int> &Vtemp, size_t start, size_t middle, size_t end)
{
    // point to tempVector
    size_t temp = start;
    size_t L = start;
    size_t R = middle + 1;
    while (L <= middle && R <= end)
    {
        if (V[L] < V[R])
            Vtemp[temp++] = V[L++];
        else
            Vtemp[temp++] = V[R++];
    }
    // wind up
    if (L == middle + 1)
        while (R <= end)
            Vtemp[temp++] = V[R++];
    else
        while (L <= middle)
            Vtemp[temp++] = V[L++];
    // copy back
    for (size_t i = start; i <= end; ++i)
        V[i] = Vtemp[i];
}

void merge_sort(std::vector<int> &V, std::vector<int> &Vtemp, size_t start, size_t end)
{
    // it's important, the least number of set is 1(not 0)
    if (start < end)
    {
        size_t middle = start + (end - start) / 2;
        merge_sort(V, Vtemp, start, middle);
        merge_sort(V, Vtemp, middle + 1, end);
        merge(V, Vtemp, start, middle, end);
    }
}

int main()
{
    double start_t, end_t; // timer

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
    std::uniform_int_distribution<int> distribution(1, 100000000);
    for (size_t i = 0; i < V.size(); ++i)
        V[i] = distribution(generator);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // sort
    start_t = clock();
    merge_sort(V, Vtemp, 0, V.size() - 1);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    return 0;
}