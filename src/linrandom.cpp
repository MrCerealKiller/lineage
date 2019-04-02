/**
 * @file linrandom.cpp
 * @brief LinRandom Class
 *
 * @author Jeremy Mallette (MrCerealKiller)
 * @version 0.1
 * @date 01/04/2019
 */

#include <linrandom.h>

// Ensures only a single instance is created
LinRandom* LinRandom::m_pInstance = NULL;

LinRandom::LinRandom() { }

LinRandom* LinRandom::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new LinRandom;
		m_pInstance->initialize();
	}

	return m_pInstance;
}

void LinRandom::initialize()
{
	unsigned long seed =
		std::chrono::system_clock::now().time_since_epoch().count();

	m_generator.seed(seed);
}

int LinRandom::getTraitVal()
{
	Distribution dist(0, 100);
	return dist(m_generator);
}

int LinRandom::getAttrVal()
{
	Distribution dist(0, 10);
	return dist(m_generator);
}