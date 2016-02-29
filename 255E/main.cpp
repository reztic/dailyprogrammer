#include <fstream>
#include <iostream>
#include <chrono>

using namespace std::chrono;
int main()
{
    auto start_time = high_resolution_clock::now();
    std::ifstream pfile("input.txt");
    int begin,end,size,onswitch;
    pfile >> size;
    bool* lightswitches = new bool[size];
    while (pfile >> begin >> end) {
        if ( begin > end)
            for( int index = end; index <= begin; ++index)
                lightswitches[index] = !lightswitches[index];
        else
            for( int index = begin; index <= end; ++index)
                lightswitches[index] = !lightswitches[index];
    }
    for (int i = 0; i < size; ++i)
    {
        if (lightswitches[i])
            onswitch++;
    }
    auto end_time = high_resolution_clock::now();
    //auto int_ms = duration_cast<milliseconds>(end_time - start_time);
    duration<double, std::milli> fp_ms = end_time - start_time;
    std::cout << fp_ms.count() << std::endl;
    std::cout << onswitch << std::endl;
    return 0;
}