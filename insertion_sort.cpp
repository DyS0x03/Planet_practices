#include <iostream>
#include <vector>
#include <ctime>
#include <random>

void insertion_sort(std::vector<int> &V)
{
    for (size_t i = 1; i < V.size(); ++i)
    {
        int key = V[i];
        size_t j = i - 1;
        while (key < V[j])
        {
            V[j + 1] = V[j];
            if ((j--) == 0)
                break;
        }
        V[j + 1] = key;
    }
}

int main()
{
    double start_t, end_t; //timer

    // allocate 1 million int space
    start_t = clock();
    std::vector<int> V(100000);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // init data
    start_t = clock();
    std::default_random_engine generator(time(NULL));
    std::uniform_int_distribution<int> distribution(1, 100000);
    for (size_t i = 0; i < V.size(); ++i)
        V[i] = distribution(generator);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    // sort
    start_t = clock();
    insertion_sort(V);
    end_t = clock();
    std::cout << (end_t - start_t) / (CLOCKS_PER_SEC * 60)
              << " minutes" << std::endl;

    return 0;
}