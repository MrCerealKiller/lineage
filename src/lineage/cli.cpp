/**
 * @file cli.cpp
 * @brief Command line interface library for Lineage
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 02/04/2019
 */

#include <cli.h>

void CLI::printStats(Character& c)
{
	std::vector<int> attrs = c.evalAttributes();

	std::cout << std::endl
			  << "\tName: " << c.name() << std::endl
			  << "\t================================" << std::endl
			  << "\tAttributes" << std::endl
			  << "\t--------------------------------" << std::endl
			  << "\t ->  Strength\t\t| "
			  << attrs.at(Character::Attributes::STRENGTH) << std::endl
			  << "\t ->  Vitality\t\t| "
			  << attrs.at(Character::Attributes::VITALITY) << std::endl
			  << "\t ->  Resiliance\t\t| "
			  << attrs.at(Character::Attributes::RESILIANCE) << std::endl
			  << "\t ->  Dexterity\t\t| "
			  << attrs.at(Character::Attributes::DEXTERITY) << std::endl
			  << "\t ->  Intelligence\t| "
			  << attrs.at(Character::Attributes::INTELLIGENCE) << std::endl
			  << "\t ->  Charisma\t\t| "
			  << attrs.at(Character::Attributes::CHARISMA) << std::endl
			  << "\t ->  Perception\t\t| "
			  << attrs.at(Character::Attributes::PERCEPTION) << std::endl
			  << "\t ->  Sanity\t\t| "
			  << attrs.at(Character::Attributes::SANITY) << std::endl
			  << "\t ->  Fate\t\t| "
			  << attrs.at(Character::Attributes::FATE) << std::endl
  			  << "\t================================" << std::endl
			  << "\tPersonality" << std::endl
			  << "\t--------------------------------" << std::endl;

	if (c.empathy().id() != Empathy::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.empathy().tag()
				  << " (" << c.empathy().val() << ")" << std::endl;
	}

	if (c.virtue().id() != Virtue::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.virtue().tag()
				  << " (" << c.virtue().val() << ")" << std::endl;
	}

	if (c.caution().id() != Caution::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.caution().tag()
				  << " (" << c.caution().val() << ")" << std::endl;
	}

	if (c.honesty().id() != Honesty::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.honesty().tag()
				  << " (" << c.honesty().val() << ")" << std::endl;
	}

	if (c.greed().id() != Greed::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.greed().tag()
				  << " (" << c.greed().val() << ")" << std::endl;
	}

	if (c.piety().id() != Piety::TierId::NEUTRAL)
	{
		std::cout << "\t ->  " << c.piety().tag()
				  << " (" << c.piety().val() << ")" << std::endl;
	}

	std::cout  << "\t================================" << std::endl
	  		   << "\tOddities" << std::endl
	  		   << "\t--------------------------------" << std::endl;
	if (c.oddities().hasAnyOddity())
	{
		for (int i = 0; i < Oddities::OddityFlags::SIZE; i++)
		{
			if (c.oddities().hasOddity(i))
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