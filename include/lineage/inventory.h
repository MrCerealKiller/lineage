/**
 * @file inventory.h
 * @brief Inventory and Item System
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 28/03/2019
 */

#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <string>
#include <vector>
#include <algorithm>

/**
 * @class Item
 * @brief Provides player-charcter statistics and functionality
 */
class Item
{	
public:
	/**
	 * @brief defines broad category for classifying items (default = MISC)
	 */
	enum Category
	{
		WEAPON,
		CLOTHING,
		MISC
	};
	/**
	 * @brief Expresses the rarity of the item
	 */
	enum Rarity
	{
		COMMON,
		UNCOMMON,
		RARE,
		MYTHIC,
		UNIQUE
	};

	// TODO: implement for random generation Item(int level);
	
	/**
	 * @brief Manual constructor for item base class
	 * @param name the name of the item
	 * @param description brief description of the item
	 * @param rarity the rarity of the item (see Rarity enum)
	 * @param weight the weight (in "kg") of the item
	 * @param value the value in (in currency) of the item
	 */
	Item(const std::string& name,
		 const std::string& description,
		 int rarity,
		 float weight,
		 float value);

	/**
	 * @brief name accessor
	 * @return the current name
	 */
	const std::string& name() const;
	/**
	 * @brief description accessor
	 * @return the current description
	 */
	const std::string& description() const;
	/**
	 * @brief rarity accessor
	 * @return the current rarity
	 */
	const int rarity() const;
	/**
	 * @brief weight accessor
	 * @return the current weight (in "kg")
	 */
	const float weight() const;
	/**
	 * @brief value accessor
	 * @return the current value (in currency)
	 */
	const float value() const;
	/**
	 * @brief category accessor
	 * @return the current category (see Category enum)
	 */
	const int category() const;

	/**
	 * @brief compares two Item* based on their category
	 * @param  pI1 first Item*
	 * @param  pI2 second Item*
	 * @return true if catergory1 is <= category2 (see Category enum)
	 */
	static const bool compCategory(const Item* i1, const Item* i2);
	/**
	 * @brief compares two Item* based on their rarity
	 * @param  pI1 first Item*
	 * @param  pI2 second Item*
	 * @return true if rarity1 is >= rarity2; false otherwise;
	 */
	static const bool compRarity(const Item* i1, const Item* i2);
	/**
	 * @brief compares two Item* based on their weight
	 * @param  pI1 first Item*
	 * @param  pI2 second Item*
	 * @return true if weight1 is >= weight2; false otherwise;
	 */
	static const bool compWeight(const Item* i1, const Item* i2);
	/**
	 * @brief compares two Item* based on their value
	 * @param  pI1 first Item*
	 * @param  pI2 second Item*
	 * @return true if value1 is >= value2; false otherwise;
	 */
	static const bool compValue(const Item* i1, const Item* i2);

protected:
	std::string m_name;			///< item name
	std::string m_description;	///< item description
	int m_rarity;				///< rarity (see Rarity enum)
	float m_weight;				///< weight of the item (in "kg")
	float m_value;				///< value of the item (in currency)
	int m_category;				///< category of the item (see Category enum)
};

/**
 * @class Inventory
 * @brief class that contains a character items
 */
class Inventory
{
public:
	/**
	 * @brief pItems accessor
	 * @return the current list of item pointers
	 */
	const std::vector<Item*> pItems() const;

	/**
	 * @brief push a new item pointer to the inventory
	 * @param pItem a pointer to the added item
	 */
	void addItem(Item* pItem);
	/**
	 * @brief remove an item pointer at a given index
	 * @param idx index of the pointer to be removed
	 */
	void removeItem(int idx);
	/**
	 * @brief remove an item pointer of a given value
	 * @param pItem item pointer to be removed
	 */
	void removeItem(Item* pItem);

	/**
	 * @brief sort the inventory vector by type
	 */
	void sortCategory();
	/**
	 * @brief sort the inventory vector by rarity
	 */
	void sortRarity();
	/**
	 * @brief sort the inventory vector by weight
	 */
	void sortWeight();
	/**
	 * @brief sort the inventory vector by value
	 */
	void sortValue();

	/**
	 * @brief maxWeight accessor
	 * @return the current max weight
	 */
	const float maxWeight() const;
	/**
	 * @brief calculate the current weight
	 * @return the sum of weights for all items
	 */
	const float currWeight() const;
private:
	float m_maxWeight;				///< Available carry weight
	std::vector<Item*> m_pItems;	///< Stores pointers to all inventory items
};

/**
 * @class Weapon
 * @brief Item sub-class for weapons (i.e. have damage)
 */
class Weapon : public Item
{
public:
	/**
	 * @brief weapon types for classification, proficiency, etc.
	 */
	enum Type
	{
		SWORD,
		DAGGER,
		BOW,
		STAFF
	};

	// TODO: implement for random generation Weapon(int level);
	
	/**
	 * @brief Manual constructor for weapon sub-class
	 * @param name the name of the item (passed to Item)
	 * @param description brief description of the item (passed to Item)
	 * @param rarity the rarity of the item (see Rarity enum) (passed to Item)
	 * @param weight the weight (in "kg") of the item (passed to Item)
	 * @param value the value in (in currency) of the item (passed to Item)
	 * @param type the type of weapon (see Type enum)
	 * @param maxDamage the max damage the weapon is capable of
	 * @param minDamage the min damage the weapon is capable of
	 */
	Weapon(const std::string& name,
		   const std::string& description,
		   int rarity,
		   float weight,
		   float value,
		   int type,
		   float maxDamage,
		   float minDamage);

	/**
	 * @brief type accessor
	 * @return current type
	 */
	const int type() const;
	/**
	 * @brief maxDamage accessor
	 * @return current maxDamage
	 */
	const float maxDamage() const;
	/**
	 * @brief minDamage
	 * @return current minDamage
	 */
	const float minDamage() const;

private:
	int m_type;			///< the type of the weapon (see Type enum)
	float m_maxDamage;	///< the max possible damage of the weapon
	float m_minDamage;	///< the min possible damage of the weapon
};

/**
 * @class Clothing
 * @brief Item sub-class for clothing (i.e. worn by the character)
 */
class Clothing : public Item
{
public:
	/**
	 * @brief clothing types for classification and usage
	 */
	enum Type
	{
		HEAD,
		NECK,
		TORSO,
		ARMS,
		HAND,
		RING,
		LEG,
		BOOT
	};

	// TODO: implement for random generation Clothing(int level);
	
	/**
	 * @brief Manual constructor for weapon sub-class
	 * @param name the name of the item (passed to Item)
	 * @param description brief description of the item (passed to Item)
	 * @param rarity the rarity of the item (see Rarity enum) (passed to Item)
	 * @param weight the weight (in "kg") of the item (passed to Item)
	 * @param value the value in (in currency) of the item (passed to Item)
	 * @param type the type of clothing (see Type enum)
	 * @param defense the defense rating of the clothing
	 */
	Clothing(const std::string& name,
		     const std::string& description,
		     int rarity,
		     float weight,
		     float value,
		     int type,
		     float defense);

	/**
	 * @brief type accessor
	 * @return current type
	 */
	const int type() const;
	/**
	 * @brief defense accessor
	 * @return current defense
	 */
	const float defense() const;

private:
	int m_type;			///< the type of the clothing (see Type enum)
	float m_defense;	///< the defense rating of the clothing object
};

#endif //_INVENTORY_H