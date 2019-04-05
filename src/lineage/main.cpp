/**
 * @file character.h
 * @brief Character Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date $Date: 28/03/2019 $
 */

#include <linrandom.h>
#include <trait.h>
#include <character.h>
#include <inventory.h>
#include <cli.h>

/**
 * Game entry-point
 * @param  argc Arguments
 * @param  argv Arguments
 * @return      Exit code
 */
int main(int argc, char* argv[])
{
	CLI cli;
	Character pc;

	Item questItem("Strange Key", "Ornate cast iron skeleton key", (int)Item::Rarity::UNIQUE, 0.10, 50);
	Item treasItem("Embellished Goblet", "Goblet cased in gold and jewels", (int)Item::Rarity::UNCOMMON, 0.70, 80);
	Item coinItem("Pouch of gold", "Several gold coins of unknown origin", (int)Item::Rarity::UNCOMMON, 0.20, 20);

	Weapon weapon1("Goblin's Prick", "Crude but effective dagger tipped with a strange poisen", (int)Item::Rarity::UNCOMMON, 2.25, 20, (int)Weapon::Type::DAGGER, 1.6, 0.9);
	Weapon weapon2("Judgement", "Two-handed sword wielded by paladin executioners", (int)Item::Rarity::UNCOMMON, 5.30, 70, (int)Weapon::Type::SWORD, 3.5, 2.6);
	Weapon weapon3("Staff of Caelegg", "Ancient staff of a sage who tamed winds", (int)Item::Rarity::RARE, 4.60, 150, (int)Weapon::Type::STAFF, 9.0, 0.5);

	Clothing cloth1("Soldier's Gambeson", "Standard armor for his Majesty's guard", (int)Item::Rarity::COMMON, 1.90, 15, (int)Clothing::Type::TORSO, 3.0);
	Clothing cloth2("Hunting Vambraces", "Leather vambraces initially for protecting against a bowstring", (int)Item::Rarity::COMMON, 0.2, 10, (int)Clothing::Type::ARMS, 0.3);
	Clothing cloth3("Maw of the Dragoon", "Helm shaped like a dragon and worn by commander's of his Majesty's Dragoons", (int)Item::Rarity::RARE, 2.5, 100, (int)Clothing::Type::HEAD, 4.0);

	pc.inventory().addItem(&weapon3);
	pc.inventory().addItem(&treasItem);
	pc.inventory().addItem(&questItem);
	pc.inventory().addItem(&cloth1);
	pc.inventory().addItem(&weapon2);
	pc.inventory().addItem(&cloth2);
	pc.inventory().addItem(&weapon1);
	pc.inventory().addItem(&coinItem);
	pc.inventory().addItem(&cloth3);
	pc.inventory().sortCategory();

	cli.printStats(pc);
	cli.printInventory(pc.inventory(), true);
}