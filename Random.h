#ifndef RANDOM
#define RANDOM

#include <cstddef>
#include <iterator>
#include <random>
#include <chrono>


namespace Random
{
	inline std::mt19937_64 getSeed()
	{
		std::random_device rd{};

		std::seed_seq ss
		{
			static_cast<std::seed_seq::result_type>(
				std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd()
		};

		return std::mt19937_64{ ss };
	}


	inline std::mt19937_64& mt()
	{
		static std::mt19937_64 generator { getSeed() };

		return generator;
	}

	inline size_t get(size_t min, size_t max)
	{
		return std::uniform_int_distribution<size_t> { min, max }( mt() );
	}

}

#endif
