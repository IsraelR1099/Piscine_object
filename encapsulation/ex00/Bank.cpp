#include "Bank.hpp"

void	Bank::createAccount(int id, int value)
{
	std::vector<Account *>::iterator	it = clientAccounts.begin();
	std::vector<Account *>::iterator	ite = clientAccounts.end();
	int									fee;

	if (id < 0 || value < 0)
		throw std::runtime_error("Invalid account creation");
	for (; it != ite; it++)
	{
		if ((*it)->getId() == id)
			throw std::runtime_error("Account already exists");
	}
	fee = static_cast<int>(value * 0.05);
	m_liquidity += fee;
	clientAccounts.push_back(new Account(id, value - fee));
}

Bank::~Bank()
{
	std::vector<Account *>::iterator	it = clientAccounts.begin();
	std::vector<Account *>::iterator	ite = clientAccounts.end();

	for (; it != ite; it++)
		delete *it;
}

void	printAccounts(const Bank &bank)
{
	std::vector<Account *>	accounts = bank.getAccounts();
	std::vector<Account *>::iterator	it = accounts.begin();
	std::vector<Account *>::iterator	ite = accounts.end();

	for (; it != ite; it++)
	{
		std::cout << "Account " << (*it)->getId() << " : " << (*it)->getValue() << std::endl;
	}
}
