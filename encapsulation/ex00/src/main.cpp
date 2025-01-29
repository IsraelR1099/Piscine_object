#include "Bank.hpp"

void	printAccounts(const Bank &bank);

static bool	testCreate()
{
	bool	ret;

	ret = false;
	std::cout << "Creating with default values\n";
	{
		Bank	test;

		std::cout << "Default liquidity: " << test.getLiquidity() << std::endl;
		test.createAccount();
		printAccounts(test);
		ret = true;
	}
	std::cout << "Duplicate IDs\n";
	{
		Bank	test;
		Bank	testDuplicate;

		test.createAccount(1, 500);
		test.createAccount();
		std::cout << "test liquidity: " << test.getLiquidity() << std::endl;
		test.modifyMoneyAccount(1, -1200);
		std::cout << "test liquidity: " << test.getLiquidity() << std::endl;
		printAccounts(test);
	}
	return (ret);
}

static void	testDelete()
{
	{
		Bank	test;

		test.createAccount(2, 200);
		printAccounts(test);
		test.removeAccount(2);
		printAccounts(test);
	}
}

int	main()
{
	if (testCreate())
	{
		std::cout << "Test create passed\n";
	}
	else
		std::cout << "Test create failed\n";
	testDelete();
	return (0);
}

