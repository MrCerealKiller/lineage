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

Character::Character() : Character::Character("Timothy", 1)
{

}

Character::Character(const std::string& name, const int level)
{
	m_id = 0;
	
	m_name = name;
	m_level = level;

	m_attributes =
	{
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal(),
		m_level * LinRandom::getInstance()->getAttrVal()
	};

	m_buffs   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	m_debuffs = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	std::vector<int> attrs = this->evalAttributes();

	m_hpMax = (LinRandom::getInstance()->getBasePoints() +
			   10 * attrs.at(Attributes::VITALITY) +
			   1 * attrs.at(Attributes::FATE));
	m_hp = m_hpMax;

	m_mpMax = (LinRandom::getInstance()->getBasePoints() +
			   10 * attrs.at(Attributes::INTELLIGENCE) +
			   1 * attrs.at(Attributes::FATE));
	m_mp = m_mpMax;	
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

void Character::setHpMax(const unsigned int hp)
{
	m_hpMax = hp;
}

const unsigned int Character::hpMax() const
{
	return m_hpMax;
}

void Character::setHp(const unsigned int hp)
{
	m_hp = hp;
}

const unsigned int Character::hp() const
{
	return m_hp;
}

void Character::setMpMax(const unsigned int mp)
{
	m_mpMax = mp;
}

const unsigned int Character::mpMax() const
{
	return m_mpMax;
}

void Character::mp(const unsigned int mp)
{
	m_mp = mp;
}

const unsigned int Character::mp() const
{
	return m_mp;
}

void Character::setSanityMax(const unsigned int sanity)
{
	m_sanityMax = sanity;
}

const unsigned int Character::sanityMax() const
{
	return m_sanityMax;
}

void Character::setSanity(const unsigned int sanity)
{
	m_sanity = sanity;
}

const unsigned int Character::sanity() const
{
	return m_sanity;
}

void Character::setLevel(const int level)
{
	m_level = level;
}

const int Character::level() const
{
	return m_level;
}

void Character::setExperience(const int exp)
{
	m_experience = exp;
}

const int Character::experience() const
{
	return m_experience;
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

void Character::setEmpathy(const Empathy& empathy)
{
	m_empathy = empathy;
}

const Empathy& Character::empathy() const
{
	return m_empathy;
}

void Character::setVirtue(const Virtue& virtue)
{
	m_virtue = virtue;
}

const Virtue& Character::virtue() const
{
	return m_virtue;
}

void Character::setCaution(const Caution& caution)
{
	m_caution = caution;
}

const Caution& Character::caution() const
{
	return m_caution;
}

void Character::setHonesty(const Honesty& honesty)
{
	m_honesty = honesty;
}

const Honesty& Character::honesty() const
{
	return m_honesty;
}

void Character::setGreed(const Greed& greed)
{
	m_greed = greed;
}

const Greed& Character::greed() const
{
	return m_greed;
}

void Character::setPiety(const Piety& piety)
{
	m_piety = piety;
}

const Piety& Character::piety() const
{
	return m_piety;
}

Oddities& Character::oddities()
{
	return m_oddities;
}

Inventory& Character::inventory()
{
	return m_inventory;
}