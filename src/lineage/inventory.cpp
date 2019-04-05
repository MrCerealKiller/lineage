/**
 * @file inventory.h
 * @brief Inventory and Item System
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 28/03/2019
 */

#include <inventory.h>

/*---------------------------------------------------------------------------
 * Item Base-Class
 * --------------------------------------------------------------------------
 */

Item::Item(const std::string& name,
		   const std::string& description,
		   int rarity,
		   float weight,
		   float value)
{
	m_name = name;
	m_description = description;
	m_rarity = rarity;
	m_weight = weight;
	m_value = value;

	m_category = static_cast<int>(Item::Category::MISC);
}

const std::string& Item::name() const
{
	return m_name;
}

const std::string& Item::description() const
{
	return m_description;
}

const int Item::rarity() const
{
	return m_rarity;
}

const float Item::weight() const
{
	return m_weight;
}

const float Item::value() const
{
	return m_value;
}

const int Item::category() const
{
	return m_category;
}

const bool Item::compCategory(const Item* pI1, const Item* pI2)
{
	return pI1->category() <= pI2->category();
}

const bool Item::compRarity(const Item* pI1, const Item* pI2)
{
	return pI1->rarity() >= pI2->rarity();
}

const bool Item::compWeight(const Item* pI1, const Item* pI2)
{
	return pI1->weight() >= pI2->weight();
}

const bool Item::compValue(const Item* pI1, const Item* pI2)
{
	return pI1->value() >= pI2->value();
}

/*---------------------------------------------------------------------------
 * Inventory Class
 * --------------------------------------------------------------------------
 */

const std::vector<Item*> Inventory::pItems() const
{
	return m_pItems;
}

void Inventory::addItem(Item* pItem)
{
	m_pItems.push_back(pItem);
}

void Inventory::removeItem(int idx)
{
	m_pItems.erase(m_pItems.begin() + idx);
}

void Inventory::removeItem(Item* pItem)
{
	int idx = 0;
	for (Item* p : m_pItems)
	{
		if (p = pItem)
		{
			m_pItems.erase(m_pItems.begin() + idx);
			return;
		}
		else
		{
			idx++;
		}
	}
}

void Inventory::sortCategory()
{
	std::sort(m_pItems.begin(), m_pItems.end(), Item::compCategory);
}

void Inventory::sortRarity()
{
	std::sort(m_pItems.begin(), m_pItems.end(), Item::compRarity);
}

void Inventory::sortWeight()
{
	std::sort(m_pItems.begin(), m_pItems.end(), Item::compWeight);
}

void Inventory::sortValue()
{
	std::sort(m_pItems.begin(), m_pItems.end(), Item::compValue);
}

const float Inventory::maxWeight() const
{
	return m_maxWeight;
}

const float Inventory::currWeight() const
{
	float weight = 0;
	for (Item* p : m_pItems)
	{
		weight += p->weight();
	}
}

/*---------------------------------------------------------------------------
 * Weapon Sub-Class
 * --------------------------------------------------------------------------
 */

Weapon::Weapon(const std::string& name,
	   		   const std::string& description,
	   		   int rarity,
	   		   float weight,
	   		   float value,
	   		   int type,
	   		   float maxDamage,
	   		   float minDamage)
	: Item(name, description, rarity, weight, value)
{
	m_type = type;
	m_maxDamage = maxDamage;
	m_minDamage = minDamage;

	m_category = static_cast<int>(Item::Category::WEAPON);
}

const int Weapon::type() const
{
	return m_type;
}

const float Weapon::maxDamage() const
{
	return m_maxDamage;
}

const float Weapon::minDamage() const
{
	return m_minDamage;
}

/*---------------------------------------------------------------------------
 * Clothing Sub-Class
 * --------------------------------------------------------------------------
 */

Clothing::Clothing(const std::string& name,
	   		   	   const std::string& description,
	   		   	   int rarity,
	   		   	   float weight,
	   		   	   float value,
	   		   	   int type,
	   		   	   float defense)
	: Item(name, description, rarity, weight, value)
{
	m_type = type;
	m_defense = defense;

	m_category = static_cast<int>(Item::Category::CLOTHING);
}

const int Clothing::type() const
{
	return m_type;
}

const float Clothing::defense() const
{
	return m_defense;
}