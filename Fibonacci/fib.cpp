
#include <iostream>
#include <string>

// n-te Fibonaaci Zahl iterativ berechnet O(n)
int fibI(int n) {
	int f1,f2, f;

	if(n <= 1) return 1;

	f1 = 1;
	f2 = 0;

	for(int i = 1; i<=n; i++) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}

	return f2;
}

// n-te Fibonaaci Zahl rekursiv berechnet
int fibR(int n) {
	if(n <= 1)
		return n;
	else
		return fibR(n-1) + fibR(n-2);

}


int main()
{

	int n;
	std::cout << "What fibonacci number would you like to know?" << std::endl;
	std::cin >> n;

	int fib = fibI(n);

	std::cout << "The fibonacci number is: " << fib << std::endl;

    return 0;
    
}
