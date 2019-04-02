/**
 * @file trait.h
 * @brief Attribute Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 31/03/2019
 */

#ifndef _TRAIT_H
#define _TRAIT_H

#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <random>
#include <iostream>

#include <linrandom.h>

/**
 * @class Trait
 * @brief Defines a particular personality trait
 */
class Trait
{
public:
	/**
	 * @class Tier
	 * @brief Convenience data structure for defining trait thresholds
	 */
	struct Tier
	{
		int id;				///< Can be cast to sub-class enums for get type
		int threshold;		///< Upper limit of val where this trait applies
		std::string tag;	///< Human-readable tag for the threshold

		/**
		 * @brief Tier constructor
		 */
		Tier(int a_id, int a_threshold, std::string a_tag);
	};

	/**
	 * @brief Initializes m_val with a random number
	 */
	Trait();
	/**
	 * @brief Virtual destructor to qualify the class as abstract
	 */
	virtual ~Trait() = 0;

	/**
	 * @brief tier id accessor
	 * @return the id [int] of the tier corresponding to m_val
	 */
	int id() const;
	/**
	 * @brief tier tag accessor
	 * @return human-readable tag assigned to the tier
	 */
	std::string tag() const;

	/**
	 * @brief val mutator
	 * @param val new val
	 */
	void setVal(int val);
	/**
	 * val accessor
	 * @return 
	 */
	int val() const;

protected:
	static const int MAX_TRAIT_VAL = 100;
	static const int MIN_TRAIT_VAL = 0;

	int m_val;					///< Numerical "stat" for the personality trait
	std::vector<Tier> m_tiers;	///< The set of tiers for trait [private]
	int m_tier;					///< Stores the current tier of the trait

	/**
	 * @brief Rearrange the tiers such that they are in the required order
	 */
	void orderTiers();
	/**
	 * @brief Update m_tier to reflect the character's current tier
	 */
	void updateTier();
};

/**
 * @brief overload the comparison operator to easily sort tiers
 */
bool operator>(const Trait::Tier& t1, const Trait::Tier& t2);
/**
 * @brief overload the comparison operator to easily sort tiers
 */
bool operator<(const Trait::Tier& t1, const Trait::Tier& t2);
/**
 * @brief overload the comparison operator to easily sort tiers
 */
bool operator>=(const Trait::Tier& t1, const Trait::Tier& t2);
/**
 * @brief overload the comparison operator to easily sort tiers
 */		
bool operator<=(const Trait::Tier& t1, const Trait::Tier& t2);


/**
 * @class Oddities
 * @brief A set of misc. binary traits
 */
class Oddities
{
public:
	/**
	 * @brief Flags used to identify oddities with bit manipulation
	 */
	enum OddityFlags
	{
		PARANOID,
		INDECISIVE,
		OBSESSIVE
	};

	/**
	 * @brief sets the entire data property
	 * @param data 4-bytes of data to respresent character oddities
	 */
	void set(uint32_t data);
	/**
	 * @brief data accessor
	 * @return current data
	 */
	uint32_t data() const;
	
	/**
	 * @brief toggles the presence of a single oddity
	 * @param bit the bit index to toggle (can cast from OddityFlags)
	 */
	void toggleOddity(int bit);
	/**
	 * @brief indicates whether the character has the oddity
	 * @param bit the bit index to toggle (can cast from OddityFlags)
	 * @return true, if the character has this trait; false otherwise
	 */
	bool hasOddity(int bit) const;

private:
	uint32_t m_data; ///< Raw data that uses bits to represent oddities
};

/**
 * @class Empathy
 * @brief Sub-class for the empathy trait
 */
class Empathy : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		SELFLESS,
		EMPATHETIC,
		NEUTRAL,
		APATHETIC,
		SADISTIC
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		SELFLESS_THRESH		= 100,
		EMPATHETIC_THRESH	= 90,
		NEUTRAL_THRESH		= 75,
		APATHETIC_THRESH	= 25,
		SADISTIC_THRESH		= 10
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Empathy();
};

/**
 * @class Virtue
 * @brief Sub-class for the virtue trait
 */
class Virtue : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		VIRTUOUS,
		NEUTRAL,
		HEDONISTIC
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		VIRTUOUS_THRESH		= 100,
		NEUTRAL_THRESH		= 80,
		HEDONISTIC_THRESH	= 20
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Virtue();
};

/**
 * @class Caution
 * @brief Sub-class for the caution trait
 */
class Caution : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		ANXIOUS,
		CAUTIOUS,
		NEUTRAL,
		COMPULSIVE,
		CARELESS
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		ANXIOUS_THRESH		= 100,
		CAUTIOUS_THRESH		= 90,
		NEUTRAL_THRESH		= 75,
		COMPULSIVE_THRESH	= 25,
		CARELESS_THRESH		= 10
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Caution();
};

/**
 * @class Honesty
 * @brief Sub-class for the honest trait
 */
class Honesty : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		HONEST,
		NEUTRAL,
		DISHONEST
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		HONEST_THRESH 		= 100,
		NEUTRAL_THRESH		= 75,
		DISHONEST_THRESH	= 25
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Honesty();
};

/**
 * @class Greed
 * @brief Sub-class for greed trait
 */
class Greed : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		BENEVOLENT,
		GENEROUS,
		NEUTRAL,
		GREEDY,
		INSATIABLE
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		BENEVOLENT_THRESH	= 100,
		GENEROUS_THRESH		= 90,
		NEUTRAL_THRESH		= 75,
		GREEDY_THRESH		= 25,
		INSATIABLE_THRESH	= 10
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Greed();
};

/**
 * @class Piety
 * @brief Sub-class for piety trait
 */
class Piety : public Trait
{
public:
	/**
	 * @brief enum used to identify the traits tiers
	 */
	enum TierId
	{
		EXTREMIST,
		PIOUS,
		SUPERSTITIOUS,
		NEUTRAL,
		AGNOSTIC,
		ATHEISTIC,
		BLASPHEMOUS
	};

	/**
	 * @brief enum used to set tier thresholds
	 */
	enum TierThreshold
	{
		EXTREMIST_THRESH		= 100,
		PIOUS_THRESH			= 95,
		SUPERSTITIOUS_THRESH	= 80,
		NEUTRAL_THRESH			= 60,
		AGNOSTIC_THRESH			= 40,
		ATHEISTIC_THRESH		= 20,
		BLASPHEMOUS_THRESH		= 5
	};

	/**
	 * @brief sub-class constructor that sets up the traits thresholds
	 */
	Piety();
};

#endif //_TRAIT_H