#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void taskA()
{
    for (int i = 1; i <= 19; i + 2)
    {
        sleep(1);
        printf("Task A: %d\n", i);
        fflush(stdout);
    }
}

void taskB()
{
    for (int i = 2; i <= 20; i + 2)
    {
        sleep(1);
        printf("Task B: %d\n", i);
        fflush(stdout);
    }
}

int main()
{
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();
    return 0;
}
