/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:45:22 by irifarac          #+#    #+#             */
/*   Updated: 2025/02/28 12:45:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bank.hpp"
#include "../includes/tests.hpp"

void	printAccounts(const Bank &bank);

static void	test_bank_fee()
{
	Bank	bank;

	bank.createAccount(1, 100);
	bank.modifyMoneyAccount(1, 100);

	ASSERT(bank.getLiquidity() == 10, "Bank receives 10% of deposits");
}

static void	test_unique_account_id()
{
	Bank	bank;

	bank.createAccount(1, 100);
	bank.createAccount(1, 200);

	ASSERT(bank.getAccounts().size() == 1,
			"Duplicate accounts should not be created"
			);
}

static void	test_account_deletion()
{
	{
		Bank	bank;

		bank.createAccount(1, 100);
		bank.removeAccount(1);
		ASSERT(bank.getAccounts().empty(),
				"Account should be deleted"
				);
	}
	Bank	bank;

	bank.createAccount(1, 100);
	bank.createAccount(2, 100);
	bank.createAccount(10, 100);
	bank.removeAccount(1);
	bank.removeAccount(3); // ID does not exist
	bank.removeAccount(10);
	ASSERT(bank.getAccounts().size() == 1,
			"Account should be deleted");
}

static void	test_give_loan()
{
	Bank	bank(100);

	bank.createAccount(1, 50);
	bank.giveLoan(1, 50);
	ASSERT(bank.getAccountValue(1) == 96,
			"Bank must be able to give a loan with a fee");
	bank.giveLoan(1, 5000); // Not enough liquidity
}

static void	test_modify_value()
{
	Bank	bank;

	bank.createAccount(1, 200);
	bank.modifyMoneyAccount(1, 100);
	ASSERT(bank.getAccountValue(1) == 285,
			"Bank must be able to modify the account value");
}

void	run_bank_tests()
{
	std::cout << "\n=== Running Bank Tests ===\n";
	test_bank_fee();
	test_unique_account_id();
	test_account_deletion();
	test_give_loan();
	test_modify_value();
	std::cout << "\n=== Finished Bank Tests ===\n";
}

int	main()
{
	run_bank_tests();
	return (0);
}

