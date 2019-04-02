/**
 * @file character.h
 * @brief Character Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 28/03/2019
 */

#include <character.h>

/*---------------------------------------------------------------------------
 * Class Construction and Destruction
 * --------------------------------------------------------------------------
 */

Character::Character()
{
	m_id = 0;
	m_name = "Timothy";

	m_attributes = {3, 5, 3, 9, 7, 4, 8, 6, 4};
	m_buffs 	 = {2, 2, 2, 0, 0, 1, 0, 1, 0};
	m_debuffs 	 = {0, 0, 0, 1, 0, 0, 1, 0, 0};

	m_personality = { 4, 8, 2, 3 };
}

Character::Character(const Character &ccp)
{

}

Character::~Character()
{

}

/*---------------------------------------------------------------------------
 * Member Functions
 * --------------------------------------------------------------------------
 */

std::vector<int> Character::evalAttributes() const
{
	std::vector<int> attrs;

	for (int i = 0; i < ATTRIBUTES_SIZE; i++)
	{
		int val = m_attributes.at(i) + m_buffs.at(i) - m_debuffs.at(i);
		val = (val < ATTRIBUTE_MIN) ? ATTRIBUTE_MIN : val;
		val = (val > ATTRIBUTE_MAX) ? ATTRIBUTE_MAX : val;
		attrs.push_back(val);
	}

	return attrs;
}

void Character::printStats() const
{
	std::vector<int> attrs = this->evalAttributes();

	std::cout << std::endl
			  << "\tName: " << m_name << std::endl
			  << "\t================================" << std::endl
			  << "\tAttributes" << std::endl
			  << "\t--------------------------------" << std::endl
			  << "\t ->  Strength\t\t| "
			  << attrs.at(Attributes::STRENGTH) << std::endl
			  << "\t ->  Vitality\t\t| "
			  << attrs.at(Attributes::VITALITY) << std::endl
			  << "\t ->  Resiliance\t\t| "
			  << attrs.at(Attributes::RESILIANCE) << std::endl
			  << "\t ->  Dexterity\t\t| "
			  << attrs.at(Attributes::DEXTERITY) << std::endl
			  << "\t ->  Intelligence\t| "
			  << attrs.at(Attributes::INTELLIGENCE) << std::endl
			  << "\t ->  Charisma\t\t| "
			  << attrs.at(Attributes::CHARISMA) << std::endl
			  << "\t ->  Perception\t\t| "
			  << attrs.at(Attributes::PERCEPTION) << std::endl
			  << "\t ->  Sanity\t\t| "
			  << attrs.at(Attributes::SANITY) << std::endl
			  << "\t ->  Fate\t\t| "
			  << attrs.at(Attributes::FATE) << std::endl
  			  << "\t================================" << std::endl
			  << "\tPersonality" << std::endl
			  << "\t--------------------------------" << std::endl
			  << std::endl;
}

/*---------------------------------------------------------------------------
 * Mutators and Accessors below
 * --------------------------------------------------------------------------
 */

unsigned int Character::id() const
{
	return m_id;
}

void Character::setName(const std::string& name)
{ 
	m_name = name;
}

const std::string& Character::name() const
{
	return m_name;
}

void Character::setAttributes(const std::vector<int>& attributes)
{
	m_attributes = attributes;
}

const std::vector<int>& Character::attributes() const
{
	return m_attributes;
}

void Character::setBuffs(const std::vector<int>& buffs)
{
	m_buffs = buffs;
}

const std::vector<int>& Character::buffs()
{
	return m_buffs;
}

void Character::setDebuffs(const std::vector<int>&debuffs)
{
	m_debuffs = debuffs;
}

const std::vector<int>& Character::debuffs() const
{
	return m_debuffs;
}

void Character::setPersonality(const std::vector<int>& personality)
{
	m_personality = personality;
}

const std::vector<int>& Character::personality() const
{
	return m_personality;
}