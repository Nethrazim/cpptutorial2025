#include <iostream>
#include <thread>

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
}