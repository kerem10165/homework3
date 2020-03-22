#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//a�a��daki sat�rlar� yoruma alarak kodunuzu farkl� �ekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{

	/*base case'ler*/

	if (numberOfStones == 1)
	{
		return 1;
	}
	
	else if (numberOfStones == 2)
	{
		return 2;
	}

	else if (numberOfStones == 3)
	{
		return 4;
	}


	//recursive k�s�m burada 3'l� toplamalar yap�l�yor ��nk� kendinden �nceki 3 ad�m say�s�n�n toplam� o ad�m� veriyor
	else
	{
		return recursiveFunction(numberOfStones - 1) + recursiveFunction(numberOfStones - 2) + recursiveFunction(numberOfStones - 3);
	}

}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	static long long dizi[72] = { 1,2,4 };//ilk �� durumun atamas�n� elle yapt�m di�er de�erleri o �� duruma g�re bulacak

	int i;

	//for d�ng�s�n� 1 ta� say�s�ndan ba�lama ihtimalimize g�re tasarlanm��t�r 

	if (numberOfStones >= 4)
	{
		i = numberOfStones-4;
		for (; i < numberOfStones-1; i++)//bu d�ng�de kendisinden �nceki �� de�eri toplat�p dizideki s�radaki eleman atmas�n� sa�lad�m
		{
			dizi[numberOfStones - 1] += dizi[i];
		}
	}
	
	return dizi[numberOfStones - 1];
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}