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

	m_attributes =
	{
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal(),
		LinRandom::getInstance()->getAttrVal()
	};
	
	m_buffs 	= {0, 0, 0, 0, 0, 0, 0, 0, 0};
	m_debuffs 	= {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
			  << "\t--------------------------------" << std::endl;

	if (m_empathy.id() != Empathy::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_empathy.tag()
				  << " (" << m_empathy.val() << ")" << std::endl;
	}

	if (m_virtue.id() != Virtue::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_virtue.tag()
				  << " (" << m_virtue.val() << ")" << std::endl;
	}

	if (m_caution.id() != Caution::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_caution.tag()
				  << " (" << m_caution.val() << ")" << std::endl;
	}

	if (m_honesty.id() != Honesty::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_honesty.tag()
				  << " (" << m_honesty.val() << ")" << std::endl;
	}

	if (m_greed.id() != Greed::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_greed.tag()
				  << " (" << m_greed.val() << ")" << std::endl;
	}

	if (m_piety.id() != Piety::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << m_piety.tag()
				  << " (" << m_piety.val() << ")" << std::endl;
	}

	std::cout  << "\t================================" << std::endl
	  		   << "\tOddities" << std::endl
	  		   << "\t--------------------------------" << std::endl;
	if (m_oddities.hasAnyOddity())
	{
		for (int i = 0; i < Oddities::OddityFlags::SIZE; i++)
		{
			if (m_oddities.hasOddity(i))
			{
				std::cout << "\t -> " << Oddities::oddityName(i) << std::endl;
			}
		}
	}
	else
	{
		std::cout << "\t  (None)" << std::endl;
	}
	std::cout << "\t================================" << std::endl << std::endl;
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

void Character::setOddities(const Oddities& oddities)
{
	m_oddities = oddities;
}

const Oddities& Character::oddities() const
{
	return m_oddities;
}