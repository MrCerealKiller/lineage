/**
 * @file trait.h
 * @brief Trait Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 31/03/2019
 */

#include <trait.h>

/*---------------------------------------------------------------------------
 * Trait (Base Class)
 * --------------------------------------------------------------------------
 */

Trait::Tier::Tier(int a_id, int a_threshold, std::string a_tag)
{
	id = a_id;
	threshold = a_threshold;
	tag = a_tag;
}

bool operator>(const Trait::Tier& t1, const Trait::Tier& t2)
{
	return t1.threshold > t2.threshold;
}

bool operator<(const Trait::Tier& t1, const Trait::Tier& t2)
{
	return t1.threshold < t2.threshold;
}

bool operator>=(const Trait::Tier& t1, const Trait::Tier& t2)
{
	return t1.threshold >= t2.threshold;
}

bool operator<=(const Trait::Tier& t1, const Trait::Tier& t2)
{
	return t1.threshold <= t2.threshold;
}

Trait::Trait()
{
	m_val = LinRandom::getInstance()->getTraitVal();
}

// Note: Though virtual, this is necessary for sub-classes
Trait::~Trait() { }

void Trait::orderTiers()
{
	std::sort(m_tiers.begin(), m_tiers.end(), std::greater<Tier>());
}

void Trait::updateTier()
{
	int temp = 0;
	for (int i = 0; i < m_tiers.size(); i++)
	{
		if (m_val < m_tiers.at(i).threshold)
		{
			temp = i;
		}
		else
		{
			m_tier = temp;
			return;
		}
	}

	m_tier = temp;
	return;
}

int Trait::id() const
{
	return m_tiers.at(m_tier).id;
}

std::string Trait::tag() const
{
	return m_tiers.at(m_tier).tag;
}

void Trait::setVal(int val)
{
	m_val = val;
	updateTier();
}

int Trait::val() const
{
	return m_val;
}

/*---------------------------------------------------------------------------
 * Oddities
 * --------------------------------------------------------------------------
 */

void Oddities::set(uint32_t data)
{
	m_data = data;
}

uint32_t Oddities::data() const
{
	return m_data;
}

void Oddities::toggleOddity(int bit)
{
	uint32_t base = 1;
	m_data ^= base << bit;
}

bool Oddities::hasOddity(int bit) const
{
	uint32_t base = 1;
	return (bool)((m_data >> bit) & base);
}

/*---------------------------------------------------------------------------
 * Trait Sub-classes
 * --------------------------------------------------------------------------
 */

Empathy::Empathy()
{
	m_tiers =
	{
		Tier(static_cast<int>(SELFLESS),
			 static_cast<int>(SELFLESS_THRESH),
			 "Selfless"),
		Tier(static_cast<int>(EMPATHETIC),
			 static_cast<int>(EMPATHETIC_THRESH),
			 "Empathetic"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(APATHETIC),
			 static_cast<int>(APATHETIC_THRESH),
			 "Apathetic"),
		Tier(static_cast<int>(SADISTIC),
			 static_cast<int>(SADISTIC_THRESH),
			 "Sadistic")
	};

	orderTiers();
	updateTier();
}

Virtue::Virtue()
{
	m_tiers =
	{
		Tier(static_cast<int>(VIRTUOUS),
			 static_cast<int>(VIRTUOUS_THRESH),
			 "Virtuous"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(HEDONISTIC),
			 static_cast<int>(HEDONISTIC_THRESH),
			 "Hedonistic")
	};

	orderTiers();
	updateTier();
}

Caution::Caution()
{
	m_tiers =
	{
		Tier(static_cast<int>(ANXIOUS),
			 static_cast<int>(ANXIOUS_THRESH),
			 "Anxious"),
		Tier(static_cast<int>(CAUTIOUS),
			 static_cast<int>(CAUTIOUS_THRESH),
			 "Cautious"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(COMPULSIVE),
			 static_cast<int>(COMPULSIVE_THRESH),
			 "Compulsive"),
		Tier(static_cast<int>(CARELESS),
			 static_cast<int>(CARELESS_THRESH),
			 "Careless")
	};

	orderTiers();
	updateTier();
}

Honesty::Honesty()
{
	m_tiers =
	{
		Tier(static_cast<int>(HONEST),
			 static_cast<int>(HONEST_THRESH),
			 "Honest"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(DISHONEST),
			 static_cast<int>(DISHONEST_THRESH),
			 "Dishonest")
	};

	orderTiers();
	updateTier();
}

Greed::Greed()
{
	m_tiers =
	{
		Tier(static_cast<int>(BENEVOLENT),
			 static_cast<int>(BENEVOLENT_THRESH),
			 "Benevolent"),
		Tier(static_cast<int>(GENEROUS),
			 static_cast<int>(GENEROUS_THRESH),
			 "Generous"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(GREEDY),
			 static_cast<int>(GREEDY_THRESH),
			 "Greedy"),
		Tier(static_cast<int>(INSATIABLE),
			 static_cast<int>(INSATIABLE_THRESH),
			 "Insatiable")
	};

	orderTiers();
	updateTier();
}

Piety::Piety()
{
	m_tiers =
	{
		Tier(static_cast<int>(EXTREMIST),
			 static_cast<int>(EXTREMIST_THRESH),
			 "Extremist"),
		Tier(static_cast<int>(PIOUS),
			 static_cast<int>(PIOUS_THRESH),
			 "Pious"),
		Tier(static_cast<int>(SUPERSTITIOUS),
			 static_cast<int>(SUPERSTITIOUS_THRESH),
			 "Superstitious"),
		Tier(static_cast<int>(NEUTRAL),
			 static_cast<int>(NEUTRAL_THRESH),
			 "Neutral"),
		Tier(static_cast<int>(AGNOSTIC),
			 static_cast<int>(AGNOSTIC_THRESH),
			 "Agnostic"),
		Tier(static_cast<int>(ATHEISTIC),
			 static_cast<int>(ATHEISTIC_THRESH),
			 "Atheistic"),
		Tier(static_cast<int>(BLASPHEMOUS),
			 static_cast<int>(BLASPHEMOUS_THRESH),
			 "Blasphemous")
	};

	orderTiers();
	updateTier();
}