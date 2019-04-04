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
 * Item Class
 * --------------------------------------------------------------------------
 */

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