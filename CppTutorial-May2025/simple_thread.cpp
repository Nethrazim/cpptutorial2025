#include <iostream>
#include <thread>
#include <mutex>

namespace MultithreadindConcurrency
{
	void work() {
		std::cout << "Hello from thread\n";
	}

	void printNumber(int number)
	{
		std::cout << number << std::endl;
	}

	void testSimpleThreads() {
		std::thread t(work);
		t.join();
		std::cout << "Thread has finished" << std::endl;

		std::thread t2(printNumber, 32); //pass parameters
		t2.join();

		std::thread t3lambda([]() {
			std::cout << "Running inside a lambda thread\n";
			});
		t3lambda.join();

		std::thread t4(work);
		std::thread t5(work);

		t4.join();
		t5.join();
	}

	void testThreadWithLambda() {
		std::thread t([] {
			std::cout << "Hello from thread\n";
		});
	}

	int counter = 0;
	std::mutex m;


	void increment() {
		for (int i = 0; i < 1000; ++i)
		{
			std::lock_guard<std::mutex> lock(m);
			counter++;
		}
	}

	void testThreadsWithMutex() {
		std::thread t1(increment);
		std::thread t2(increment);

		t1.join();
		t2.join();

		std::cout << "Counter = " << counter << "\n";
	}

	void testThreadsWithoutMutex()
	{
		std::cout << "should be 2000" << std::endl;

		std::thread t1(increment);
		std::thread t2(increment);

		t1.join();
		t2.join();

		std::cout << "Counter = " << counter << "\n";
	}
}