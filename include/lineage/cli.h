/**
 * @file cli.h
 * @brief Command line interface library for Lineage
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 02/04/2019
 */

#ifndef _CLI_H
#define _CLI_H

#include <iostream>

#include <character.h>
#include <inventory.h>

/**
 * @class CLI
 * @brief Command line interface for the game
 */
class CLI
{
public:
	/**
	 * @brief prints the character's stats
	 * @param c the character
	 */
	void printStats(Character& c);

	/**
	 * @brief prints the name of inventory items
	 * @param inv the inventory
	 */
	void printInventory(Inventory& inv, bool simpleView);
};
#endif //_CLI_H