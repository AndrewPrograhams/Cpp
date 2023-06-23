#include <iostream>
#include <thread>
#include <mutex>


std::mutex mtx;
int sharedVariable = 0;

/* An example of thread locking using mutex to lock threads. */
/* When the lock_guard object goes out of scope, the lock is lifted. */
/* */

void incrementSharedVariable()
{
    std::lock_guard<std::mutex> lock(mtx);

    // Critical section begins
    for (int i = 0; i < 1000000; ++i) {
        sharedVariable++;
    }
    // Critical section ends
}

int main()
{
    std::thread thread1(incrementSharedVariable);
    std::thread thread2(incrementSharedVariable);

    thread1.join();
    thread2.join();

    std::cout << "Shared variable value: " << sharedVariable << std::endl;

    return 0;
}