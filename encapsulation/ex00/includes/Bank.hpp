#pragma once

# include <vector>
# include <iostream>
# include <cstdlib>

class	Bank
{
	private:
		int						m_liquidity;
		struct Account
		{
			private:
				int	m_id;
				int	m_value;
				Account() : m_id(-1), m_value(0) {}
				Account(int id, int value) : m_id(id), m_value(value) {}
				friend class	Bank;
			public:
				const int	&getId() const { return (m_id); }
				const int	&getValue() const { return (m_value); }
		};
		std::vector<Account *>	clientAccounts;
	public:
		Bank() : m_liquidity(0) {}
		explicit Bank(int liquidity) : m_liquidity(liquidity) {}
		void			setLiquidity(int liquidity) { m_liquidity = liquidity; }
		const int		&getLiquidity() const { return (m_liquidity); }
	
		void			createAccount(int id=1, int value=0);
		void			modifyMoneyAccount(int id, int value);
		void			removeAccount(int id);
		void			giveLoan(int id, int value);
		const int		&getAccountValue(int id);
        Bank::Account &operator[](int id);
        const Account	&operator[](int id) const;
		const std::vector<Account *>	&getAccounts() const { return (clientAccounts); }
		~Bank();
};
