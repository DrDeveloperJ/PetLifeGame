#pragma once
#include <chrono>
#include <iostream>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	// Start the timer when the object is created
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	// End the timer when the object is destroyed and display the duration
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};