/**
 * @file linrandom.h
 * @brief LinRandom Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 01/04/2019
 */

#ifndef _LIN_RANDOM_H
#define _LIN_RANDOM_H

#include <random>
#include <chrono>
#include <iostream>

/**
 * @class LinRandom
 * @brief Singleton that handles RNG for the game
 */
class LinRandom
{
public:
	typedef std::default_random_engine Engine;
	typedef std::uniform_int_distribution<int> Distribution;

	/**
	 * @brief deleted to prevent use
	 */
	LinRandom(const LinRandom&) = delete;
	/**
	 * @brief deleted to prevent use
	 */
	void operator=(const LinRandom&) = delete;

	/**
	 * @brief accessor for the singleton pointer
	 * @return the pointer for the singleton object
	 */
	static LinRandom* getInstance();
	/**
	 * @brief seeds and initializes the RNG
	 */
	void initialize();

	/**
	 * @brief generates a random number for creating a trait
	 * @return a random number within the bounds set for a trait
	 */
	int getTraitVal();
	/**
	 * @brief generates a random number for creating a attribute
	 * @return a random number within the bounds set for an attribute
	 */
	int getAttrVal();

private:
	/**
	 * @brief private constructor to hide creating new objects
	 */
	LinRandom();
	
	static LinRandom* m_pInstance; 	///< pointer storing the singleton instance
	bool isInitialized = false;		///< true if initialized
	Engine m_generator;			    ///< engine used for RNG
};

#endif //_LIN_RANDOM_H