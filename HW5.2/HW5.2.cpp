#include <iostream>


int fibonachi(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonachi(n - 1) + fibonachi(n - 2);
}
int main()
{
	int n;
	std::cout << "Enter number: ";
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cout << "F(n) = " << fibonachi(i) << std::endl;
	}


}