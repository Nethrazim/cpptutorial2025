#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


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
	
	std::mutex mtx;
	std::condition_variable cv;
	bool turnA = true;


	void threadA()
	{
		while (true) {
			std::unique_lock<std::mutex> lock(mtx);
			cv.wait(lock, [] { return turnA; });

			std::cout << "Thread A working\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

			turnA = false;
			cv.notify_one();
			
			cv.wait(lock, [] { return turnA; });

			std::cout << "Thread A second part working\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

			turnA = false;
			cv.notify_one();
		}
	}

	void threadB()
	{
		while (true) {
			std::unique_lock<std::mutex> lock(mtx);
			cv.wait(lock, [] { return !turnA; });

			std::cout << "Thread  B working\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

			turnA = true;
			cv.notify_one();
			

			cv.wait(lock, [] { return !turnA; });

			std::cout << "Thread B second part working\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

			turnA = true;
			cv.notify_one();
		}
	}

	void testThreadsTakingTurns() {
		std::thread tA(threadA);
		std::thread tB(threadB);
		
		tA.join();
		tB.join();
	}
}