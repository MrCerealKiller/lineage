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

	Empathy e;
	std::cout << "Empathy:" << std::endl;
	std::cout << "  Raw value:\t" << e.val() << std::endl;
	std::cout << "  ID value:\t" << e.id() << std::endl;
	std::cout << "  Tag value:\t" << e.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;

	Virtue v;
	std::cout << "Virtue:" << std::endl;
	std::cout << "  Raw value:\t" << v.val() << std::endl;
	std::cout << "  ID value:\t" << v.id() << std::endl;
	std::cout << "  Tag value:\t" << v.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;

	Caution c;
	std::cout << "Caution" << std::endl;
	std::cout << "  Raw value:\t" << c.val() << std::endl;
	std::cout << "  ID value:\t" << c.id() << std::endl;
	std::cout << "  Tag value:\t" << c.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;

	Honesty h;
	std::cout << "Honesty:" << std::endl;
	std::cout << "  Raw value:\t" << h.val() << std::endl;
	std::cout << "  ID value:\t" << h.id() << std::endl;
	std::cout << "  Tag value:\t" << h.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;

	Greed g;
	std::cout << "Virtue:" << std::endl;
	std::cout << "  Raw value:\t" << g.val() << std::endl;
	std::cout << "  ID value:\t" << g.id() << std::endl;
	std::cout << "  Tag value:\t" << g.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;

	Piety p;
	std::cout << "Piety:" << std::endl;
	std::cout << "  Raw value:\t" << p.val() << std::endl;
	std::cout << "  ID value:\t" << p.id() << std::endl;
	std::cout << "  Tag value:\t" << p.tag() << std::endl;
	std::cout << "------------------------" << std::endl << std::endl;
}