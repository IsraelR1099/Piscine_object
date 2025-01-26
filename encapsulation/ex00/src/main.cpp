#include "Bank.hpp"

void	printAccounts(const Bank &bank);

int	main()
{
	Bank	test;

	test.createAccount(1);
	test.createAccount(2, 100);
	test.createAccount(3, 200);
	printAccounts(test);

	std::cout << "Adding 100 to account 1" << std::endl;
	test.addMoneyToAccount(1, 100);
	printAccounts(test);
	return (0);
}

