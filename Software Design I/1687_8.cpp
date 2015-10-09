#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	double n;
	while (cin >> n)
	{
		int sum = 0;

		int max100 = n / 100;
		int max50 = n / 50;
		int max20 = n / 20;
		int max10 = n /10;
		int max5 = n / 5;
		int max1 = n;
		int max0_5 = n * 2;

		for (int i = 0; i <= max100; ++i)
		{
			if (100*i == n)
			{
				sum++;
				break;
			}

			for (int j = 0; j <= max50; ++j)
			{
				if (100*i + 50*j == n)
				{
					sum++;
					break;
				}

				for (int k = 0; k <= max20; ++k)
				{
					if (100*i + 50*j + 20*k == n)
					{
						sum++;
						break;
					}

					for (int m = 0; m <= max10; ++m)
					{
						if (100*i + 50*j + 20*k + 10*m == n)
						{
							sum++;
							break;
						}

						for (int w = 0; w <= max5; ++w)
						{
							
							if (100*i + 50*j + 20*k + 10*m + 5*w == n)
							{
								sum++;
								break;
							}


							for (int p = 0; p <= max1; ++p)
							{
								
								if (100*i + 50*j + 20*k + 10*m + 5*w + p == n)
								{
									sum++;
									break;
								}

								for (int q = 0; q <= max0_5; ++q)
								{
									if (100*i + 50*j + 20*k + 10*m + 5*w + p + .5*q == n)
									{
										sum++;
										break;
									}

									if (100*i + 50*j + 20*k + 10*m + 5*w + p + .5*q <= n)
										sum++;
								}
							}
						}
					}
				}
			}
		}

		cout << sum << endl;
	}
	return 0;
}