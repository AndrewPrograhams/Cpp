#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mtx;

// Function to print vector elements
void printVector(const std::vector<int>& vec, const std::string& name)
{
    std::lock_guard<std::mutex> lock(mtx);

    std::cout << name << " vector elements: ";
    for (const auto& element : vec) {
        std::cout << element << " ";

        // Wait for the other thread to finish printing its element
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vector1 = {1, 2, 3, 4, 5};
    std::vector<int> vector2 = {6, 7, 8, 9, 10};

    // Create threads to print vectors
    std::thread thread1(printVector, std::ref(vector1), "Vector 1");
    std::thread thread2(printVector, std::ref(vector2), "Vector 2");

    // Wait for threads to finish
    thread1.join();
    thread2.join();

    return 0;
}