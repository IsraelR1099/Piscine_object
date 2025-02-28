/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:56:20 by irifarac          #+#    #+#             */
/*   Updated: 2025/02/28 12:56:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <iostream>
# include <cstdlib>
# include "Account.hpp"

class	Bank
{
	private:
		int						m_liquidity;
		std::vector<Account *>	clientAccounts;
		Account					*getAccount(int id);
	public:
		Bank() : m_liquidity(0) {}
		explicit Bank(int liquidity) : m_liquidity(liquidity) {}
		void			setLiquidity(int liquidity) { m_liquidity = liquidity; }
		const int		&getLiquidity() const { return (m_liquidity); }
		void			createAccount(int id=1, int value=0);
		const std::vector<Account *>	&getAccounts() const { return (clientAccounts); }
		void			modifyMoneyAccount(int id, int value);
		void			removeAccount(int id);
		void			giveLoan(int id, int value);
		const int		&getAccountValue(int id);
		~Bank();
};
