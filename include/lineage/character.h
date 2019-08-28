/**
 * @file character.h
 * @brief Character Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 28/03/2019
 */

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>
#include <vector>

#include <trait.h>
#include <inventory.h>

/**
 * @class Character
 * @brief Provides player-charcter statistics and functionality
 */
class Character
{
public:
	/**
	 * @brief Experience required to trigger a level up
	 */
	static const int LEVEL_UP_EXP = 100;

	/**
	 * @brief Constants in the character class namespace
	 */
	enum
	{
		NAME_SIZE			= 20,
		ATTRIBUTES_SIZE 	= 10,
		PERSONALITY_SIZE 	= 4,
		ATTRIBUTE_MIN		= 0,
		ATTRIBUTE_MAX		= 1000
	};
	/**
	 * @brief Flags denoting indices for the attributes array
	 */
	enum Attributes
	{
		STRENGTH 		= 0,
		VITALITY		= 1,
		RESILIANCE		= 2,
		DEXTERITY		= 3,
		WILLPOWER		= 4,
		INTELLIGENCE	= 5,
		CHARISMA		= 6,
		PERCEPTION		= 7,
		SANITY			= 8,
		FATE			= 9
	};

	/**
	 * @brief Character constructor (random generation)
	 */
	Character();
	/**
	 * @brief Character constructor (with name and level)
	 */
	Character(const std::string& name, const int level);
	/**
	 * @brief Character copy constructor
	 */
	Character(const Character &ccp);
	/**
	 * @brief Character destructor
	 */
	~Character();

	/**
	 * @brief get modified attributes by applying buffs/debuffs
	 * @return a vector of modified attributes
	 */
	std::vector<int> evalAttributes() const;

	/**
	 * @brief id accessor
	 * @return current id
	 */
	unsigned int id() const;

	/**
	 * @brief name mutator
	 * @param name new name
	 */
	void setName(const std::string& name);
	/**
	 * @brief name accessor
	 * @return current name
	 */
	const std::string& name() const;

	/**
	 * @brief max hp mutator
	 * @param hp new max hp
	 */
	void setHpMax(const unsigned int hp);
	/**
	 * @brief max hp accessor
	 * @return current max hp
	 */
	const unsigned int hpMax() const;

	/**
	 * @brief hp mutator
	 * @param hp new hp
	 */
	void setHp(const unsigned int hp);
	/**
	 * @brief hp accessor
	 * @return current hp
	 */
	const unsigned int hp() const;

	/**
	 * @brief max mp mutator
	 * @param mp new max mp
	 */
	void setMpMax(const unsigned int mp);
	/**
	 * @brief max mp accessor
	 * @return current max mp
	 */
	const unsigned int mpMax() const;

	/**
	 * @brief mp mutator
	 * @param mp new mp
	 */
	void mp(const unsigned int mp);
	/**
	 * @brief mp accessor
	 * @return current mp
	 */
	const unsigned int mp() const;

	/**
	 * @brief max sanity mutator
	 * @param sanity new max sanity
	 */
	void setSanityMax(const unsigned int sanity);
	/**
	 * @brief max sanity accessor
	 * @return current max sanity
	 */
	const unsigned int sanityMax() const;

	/**
	 * @brief sanity mutator
	 * @param sanity new sanity
	 */
	void setSanity(const unsigned int sanity);
	/**
	 * @brief sanity accessor
	 * @return current sanity
	 */	
	const unsigned int sanity() const;

	/**
	 * @brief level mutator
	 * @param level new level
	 */
	void setLevel(const int level);
	/**
	 * @brief level accessor
	 * @return current level
	 */	
	const int level() const;

	/**
	 * @brief experience mutator
	 * @param experience new experience
	 */
	void setExperience(const int exp);
	/**
	 * @brief experience accessor
	 * @return current experience
	 */	
	const int experience() const;

	/**
	 * @brief attributes mutator
	 * @param attributes new attributes
	 */
	void setAttributes(const std::vector<int>& attributes);
	/**
	 * @brief attributes accessor
	 * @return current attributes
	 */
	const std::vector<int>& attributes() const;

	/**
	 * @brief buffs mutator
	 * @param buffs new buffs
	 */
	void setBuffs(const std::vector<int>& buffs);
	/**
	 * @brief buffs accessor
	 * @return current buffs
	 */
	const std::vector<int>& buffs();

	/**
	 * @brief debuffs mutator
	 * @param debuffs new debuffs
	 */
	void setDebuffs(const std::vector<int>& debuffs);
	/**
	 * @brief debuffs accessor
	 * @return current debuffs
	 */
	const std::vector<int>& debuffs() const;

	/**
	 * @brief empathy mutator
	 * @param empathy new empathy
	 */
	void setEmpathy(const Empathy& empathy);
	/**
	 * @brief empathy accessor
	 * @return current empathy
	 */
	const Empathy& empathy() const;

	/**
	 * @brief virtue mutator
	 * @param virtue new virtue
	 */
	void setVirtue(const Virtue& virtue);
	/**
	 * @brief virtue accessor
	 * @return current virtue
	 */
	const Virtue& virtue() const;

	/**
	 * @brief caution mutator
	 * @param caution new caution
	 */
	void setCaution(const Caution& caution);
	/**
	 * @brief caution accessor
	 * @return current caution
	 */
	const Caution& caution() const;

	/**
	 * @brief honesty mutator
	 * @param honesty new honesty
	 */
	void setHonesty(const Honesty& honesty);
	/**
	 * @brief honesty accessor
	 * @return current honesty
	 */
	const Honesty& honesty() const;

	/**
	 * @brief greed mutator
	 * @param greed new greed
	 */
	void setGreed(const Greed& greed);
	/**
	 * @brief greed accessor
	 * @return current greed
	 */
	const Greed& greed() const;

	/**
	 * @brief piety mutator
	 * @param piety new piety
	 */
	void setPiety(const Piety& piety);
	/**
	 * @brief piety accessor
	 * @return current piety
	 */
	const Piety& piety() const;

	/**
	 * @brief oddities accessor
	 * @return current oddities
	 */
	Oddities& oddities();

	/**
	 * @brief inventory accessor
	 * @return current inventory
	 */
	Inventory& inventory();

private:
	// General
	unsigned int m_id;				///< Unique ID for the character
	std::string m_name;				///< Player-given name

	// Status
	unsigned int m_hpMax;			///< Max hit points
	unsigned int m_hp;				///< Current hit points
	unsigned int m_mpMax;			///< Max magic points
	unsigned int m_mp;				///< Current magic points
	unsigned int m_sanityMax;		///< Max sanity points
	unsigned int m_sanity;			///< Current sanity points
	
	int m_level;					///< Current pc level
	int m_experience;				///< Current pc experience

	// Attributes and Modifiers
	std::vector<int> m_attributes;	///< Base attributes (stats)
	std::vector<int> m_buffs;	  	///< Buffs applied to base attributes
	std::vector<int> m_debuffs;	  	///< Debuffs applied to base attributes

	// Personality Modifiers
	Empathy m_empathy;				///< Empathy personality modifier
	Virtue m_virtue;				///< Virtue personality modifier
	Caution m_caution;				///< Caution personality modifier
	Honesty m_honesty;				///< Honesty personality modifier
	Greed m_greed;					///< Greed personality modifier
	Piety m_piety;					///< Piety personality modifier

	Oddities m_oddities;			///< Personality oddities

	Inventory m_inventory;			///< The character's inventory
};
#endif //_CHARACTER_H
