#include <queue>
#include <mutex>

//shared between threads
std::queue<int> sharedQueue;
std::mutex queueMutex;

//producer threads
void producer() {
	std::lock_guard<std::mutex> lock(queueMutex);
	sharedQueue.push(42);
}

//consuming thread
void consumer() {
	std::lock_guard<std::mutex> lock(queueMutex);
	if (!sharedQueue.empty()) {
		int val = sharedQueue.front();
		sharedQueue.pop();
	}
}


template<typename T, size_t Size>
class SPSCQueue {
	std::array<T, Size> buffer;
	std::atomic<size_t> readIndex{ 0 };
	std::atomic<size_t> writeIndex{ 0 };

public:
	bool push(const T& item) {
		size_t write = writeIndex.load(std::memory_order_relaxed);
		size_t nextWrite = (write + 1) % Size;

		if (nextWrite == readIndex.load(std::memory_order_acquire))
			return false;

		buffer[write] = item;
		writeIndex.store(nextWrite, std::memory_order_release);
		return true;
	}

	bool pop(T& item) {
		size_t read = readIndex.load(std::memory_order_relaxed);

		if (read == writeIndex.load(std::memory_order_acquire))
			return false;

		item = buffer[read];
		readIndex.store((read + 1) % Size, std::memory_order_release);
		return true;
	}
};