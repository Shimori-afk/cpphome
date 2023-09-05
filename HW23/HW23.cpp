#include "HW23.h"

int main()
{
	InplaceArray<int, 5> m_container;
	m_container.push_back(25);
	m_container.push_back(30);
	m_container.push_back(10);
	m_container.push_back(39);
	m_container.push_back(55);

	//m_container.pop_back();
	//m_container.clear();


	for (std::size_t i = 0; i < m_container.getSize(); ++i)
	{
		std::cout << m_container[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Capacity: " << m_container.getCapacity() << std::endl;

	//m_container.reserve(8);
	//std::cout << "Capacity after reserve: " << m_container.getCapacity() << std::endl;

	m_container.shrinkToFit();
	std::cout << "Capacity after shrinkToFit: " << m_container.getCapacity() << std::endl;

	return 0;
}