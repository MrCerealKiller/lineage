/**
 * @file character.h
 * @brief Character Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date $Date: 28/03/2019 $
 */

#include <character.h>
#include <trait.h>
#include <linrandom.h>

/**
 * Game entry-point
 * @param  argc Arguments
 * @param  argv Arguments
 * @return      Exit code
 */
int main(int argc, char* argv[])
{
	Character pc;
	pc.printStats();
}