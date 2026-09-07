#include <chrono>

#include <cstdint>

#include <iostream>



std::uint64_t workload()

{

volatile std::uint64_t value = 0;



for (std::uint64_t i = 0; i < 1'000'000; ++i)

{

value += i;

}



return value;

}



int main()

{

using clock = std::chrono::steady_clock;



const auto start = clock::now();



const auto result = workload();



const auto end = clock::now();



const auto elapsed =

std::chrono::duration_cast<std::chrono::microseconds>(

end - start

);



std::cout << "Workload result: " << result << '\n';

std::cout << "Elapsed time: "

<< elapsed.count()

<< " microseconds\n";



return 0;

}
//comments A B C