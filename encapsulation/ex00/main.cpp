#include "Bank.hpp"

void	printAccounts(const Bank &bank);

int	main()
{
	Bank	test;

	test.createAccount(1);
	test.createAccount(2, 100);
	test.createAccount(3, 200);
	printAccounts(test);
	return (0);
}

