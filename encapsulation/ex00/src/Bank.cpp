#include "../includes/Bank.hpp"

void	Bank::createAccount(int id, int value)
{
	int		fee;

	if (id < 0 || value < 0)
	{
		std::cerr << "Invalid account creation" << std::endl;
		return ;
	}
	try
	{
		const Account	&account = (*this)[id];
		(void)account;
		throw std::invalid_argument("Account already exists");
	}
	catch (std::out_of_range &e)
	{
	}
	fee = static_cast<int>(value * 0.05);
	m_liquidity += fee;
	clientAccounts.push_back(new Account(id, value - fee));
}

void	Bank::modifyMoneyAccount(int id, int value)
{
	int				fee;
	Account	&account = (*this)[id];
	int				netValue;

	if (id < 0)
	{
		std::cerr << "Invalid account creation" << std::endl;
		return ;
	}
	fee = static_cast<int>(std::abs(value) * 0.05);
	netValue = account.getValue() + (value - fee);
	if (netValue < -1000)
	{
		std::cerr << "You are bankrupt\n";
		return ;
	}
	m_liquidity += fee;
	account.m_value = netValue;
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
	int		fee;
	int		netLoan;

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
		fee = static_cast<int>(value * 0.05);
		netLoan = value - fee;
		m_liquidity -= value;
		account->addValue(netLoan);
		m_liquidity += fee;
	}
	else
		std::cerr << "Account not found" << std::endl;
}

const int	&Bank::getAccountValue(int id)
{
	Account	*account;

	if (id < 0)
	{
		std::cerr << "ID not valid\n";
	}
	account = getAccount(id);
	if (!account)
	{
		std::cerr << "Account not found\n";
	}
	return (account->getValue());
}

Bank::Account	&Bank::operator[](int id)
{
	if (id < 0)
		throw std::out_of_range("ID not valid");
	if (id >= static_cast<int>(clientAccounts.size()))
		throw std::out_of_range("Account not found");
	return (*clientAccounts[id]);
}


const Bank::Account	&Bank::operator[](int id) const
{
	if (id < 0)
		throw std::out_of_range("ID not valid");
	if (id >= static_cast<int>(clientAccounts.size()))
		throw std::out_of_range("Account not found");
	return (*clientAccounts[id]);
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
		std::cout << "Account ID: " << (*it)->getId() << " Value: " << (*it)->getValue() << std::endl;
	}
}
