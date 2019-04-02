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
#include <iostream>

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
	 * @brief print character statistics
	 */
	void printStats() const;

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
	void setDebuffs(const std::vector<int>&debuffs);
	/**
	 * @brief debuffs accessor
	 * @return current debuffs
	 */
	const std::vector<int>& debuffs() const;

	/**
	 * @brief personality mutator
	 * @param personality new personality
	 */
	void setPersonality(const std::vector<int>& personality);
	/**
	 * @brief personality accessor
	 * @return current personality
	 */
	const std::vector<int>& personality() const;

private:
	unsigned int m_id;				///< Unique ID for the character
	std::string m_name;				///< Player-given name
	std::vector<int> m_attributes;	///< Base attributes (stats)
	std::vector<int> m_buffs;	  	///< Buffs applied to base attributes
	std::vector<int> m_debuffs;	  	///< Debuffs applied to base attributes
	std::vector<int> m_personality;	///< Personality modifiers
};
#endif //_CHARACTER_H
