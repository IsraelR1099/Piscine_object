#include "Bank.hpp"

Account	*Bank::getAccount(int id)
{
	std::vector<Account *>::iterator	it = clientAccounts.begin();
	std::vector<Account *>::iterator	ite = clientAccounts.end();

	for (; it != ite; it++)
	{
		if ((*it)->getId() == id)
			return (*it);
	}
	return (NULL);
}

void	Bank::createAccount(int id, int value)
{
	int	fee;

	if (id < 0 || value < 0)
	{
		std::cerr << "Invalid account creation" << std::endl;
		return ;
	}
	if (getAccount(id))
	{
		std::cerr << "Account already exists" << std::endl;
		return ;
	}
	fee = static_cast<int>(value * 0.05);
	m_liquidity += fee;
	clientAccounts.push_back(new Account(id, value - fee));
}

void	Bank::addMoneyToAccount(int id, int value)
{
	int		fee;
	Account	*account;

	if (value < 0 || id < 0)
	{
		std::cerr << "Invalid account creation" << std::endl;
		return ;
	}
	fee = static_cast<int>(value * 0.05);
	account = getAccount(id);
	if (!account)
	{
		std::cerr << "Account not found" << std::endl;
		return ;
	}
	m_liquidity += fee;
	account->addValue(value - fee);
}

void	Bank::removeAccount(int id)
{
	std::vector<Account *>::iterator	it = clientAccounts.begin();
	std::vector<Account *>::iterator	ite = clientAccounts.end();

	if (id < 0)
	{
		std::cerr << "Invalid account removal" << std::endl;
		return ;
	}
	for (; it != ite; it++)
	{
		if ((*it)->getId() == id)
		{
			delete *it;
			clientAccounts.erase(it);
			return ;
		}
	}
	std::cerr << "Account not found" << std::endl;
}

void	Bank::giveLoan(int id, int value)
{
	Account	*account;

	if (value < 0 || id < 0)
	{
		std::cerr << "Invalid loan" << std::endl;
		return ;
	}
	if (m_liquidity < value)
	{
		std::cerr << "Not enough liquidity" << std::endl;
		return ;
	}
	account = getAccount(id);
	if (account)
	{
		m_liquidity -= value;
		account->addValue(value);
	}
	else
		std::cerr << "Account not found" << std::endl;
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
