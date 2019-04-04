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

/**
 * @class Character
 * @brief Provides player-charcter statistics and functionality
 */
class Character
{
public:
	/**
	 * @brief Constants in the character class namespace
	 */
	enum
	{
		NAME_SIZE			= 20,
		ATTRIBUTES_SIZE 	= 9,
		PERSONALITY_SIZE 	= 4,
		ATTRIBUTE_MIN		= 0,
		ATTRIBUTE_MAX		= 10
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
		INTELLIGENCE	= 4,
		CHARISMA		= 5,
		PERCEPTION		= 6,
		SANITY			= 7,
		FATE			= 8
	};

	/**
	 * @brief Character constructor (random generation)
	 */
	Character();
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
	 * @brief oddities mutator
	 * @param oddities new oddity
	 */
	void setOddities(const Oddities& oddities);
	/**
	 * @brief oddities accessor
	 * @return current oddities
	 */
	const Oddities& oddities() const;

private:
	unsigned int m_id;				///< Unique ID for the character
	std::string m_name;				///< Player-given name
	std::vector<int> m_attributes;	///< Base attributes (stats)
	std::vector<int> m_buffs;	  	///< Buffs applied to base attributes
	std::vector<int> m_debuffs;	  	///< Debuffs applied to base attributes

	Empathy m_empathy;
	Virtue m_virtue;
	Caution m_caution;
	Honesty m_honesty;
	Greed m_greed;
	Piety m_piety;

	Oddities m_oddities;
};
#endif //_CHARACTER_H
