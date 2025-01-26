#pragma once

# include <vector>
# include <iostream>
# include "Account.hpp"

class	Bank
{
	private:
		int	m_liquidity;
		std::vector<Account *>	clientAccounts;
	public:
		Bank() : m_liquidity(0) {}
		explicit Bank(int liquidity) : m_liquidity(liquidity) {}
		void			setLiquidity(int liquidity) { m_liquidity = liquidity; }
		const int		&getLiquidity() const { return (m_liquidity); }
		void			createAccount(int id=1, int value=0);
		std::vector<Account *>	getAccounts() const { return (clientAccounts); }
		void			addMoneyToAccount(int id, int value);
		void			removeAccount(int id);
		void			giveLoan(int id, int value);
		Account			*getAccount(int id);
		~Bank();
};
