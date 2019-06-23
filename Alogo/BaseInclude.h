#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "StopWatch.h"

using namespace stopwatch;
using namespace std;

namespace BaseInclude
{
	Stopwatch watch;

	std::uint64_t elapsed_ns;
	// .. in microseconds
	std::uint64_t elapsed_mus;
	// .. in milliseconds (default template argument, therefore not needed)
	std::uint64_t elapsed_ms;
	// .. in seconds
	std::uint64_t elapsed_s;

	void TimeStart()
	{
		watch.start();
	}

	void TimePrint()
	{
		elapsed_ns = watch.elapsed<nanoseconds>();
		elapsed_mus = watch.elapsed<microseconds>();
		elapsed_ms = watch.elapsed();
		elapsed_s = watch.elapsed<seconds>();
		std::cout << "---------------" << std::endl;
		std::cout << elapsed_ns << " ns" << std::endl;
		std::cout << elapsed_mus << " mus" << std::endl;
		std::cout << elapsed_ms << " ms" << std::endl;
		std::cout << elapsed_s << " s" << std::endl;
		std::cout << "---------------" << std::endl;
	}
}
