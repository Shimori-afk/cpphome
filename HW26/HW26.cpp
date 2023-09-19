#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <numeric>
#include <algorithm>

int sumSingleThread(const std::vector<int>& data) {
	int result = 0;
	for (int element : data) {
		result += element;
	}
	return result;
}

int sumMultiThread(const std::vector<int>& data, int numThreads) {
	int dataSize = data.size();
	int chunkSize = dataSize / numThreads;

	std::vector<std::thread> threads;
	std::vector<int> partialSums(numThreads, 0);

	for (int i = 0; i < numThreads; ++i) {
		int start = i * chunkSize;
		int end = (i == numThreads - 1) ? dataSize : (start + chunkSize);

		threads.emplace_back([start, end, &data, &partialSums, i]() {
			int partialSum = 0;
			for (int j = start; j < end; ++j) {
				partialSum += data[j];
			}
			partialSums[i] = partialSum;
			});
	}

	for (std::thread& thread : threads) {
		thread.join();
	}

	return std::accumulate(partialSums.begin(), partialSums.end(), 0);
}

int main() {
	std::vector<int> data1(1000000, 1);
	std::vector<int> data2(10000000, 1);
	std::vector<int> data3(100000000, 1);

	auto start = std::chrono::high_resolution_clock::now();
	int result1 = sumSingleThread(data1);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	double time1 = elapsed.count();

	start = std::chrono::high_resolution_clock::now();
	int result2 = sumMultiThread(data2, 2);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	double time2 = elapsed.count();

	int numThreads = std::thread::hardware_concurrency();
	start = std::chrono::high_resolution_clock::now();
	int result3 = sumMultiThread(data3, numThreads);
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	double time3 = elapsed.count();

	std::cout << "Vector Size\tSingle Thread\t2 Threads\tMax Threads\n";
	std::cout << "1M\t" << time1 << "\t" << time2 << "\t" << time3 << "\n";

	double boost2 = time1 / time2;
	double boost3 = time1 / time3;

	std::cout << "Boost (2 Threads)\tBoost (Max Threads)\n";
	std::cout << boost2 << "\t" << boost3 << "\n";

	return 0;
}
