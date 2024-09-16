/*Napisz funkcję, która zarezerwuje 10-elementową tablicę,  a jej adres przekaże wskaźnikowi
o nazwie linijka.  Ma to być tablica, w której można przechowywać  wskaźniki do tablic znaków.

Następnie za pomocą pętli for  dla każdego z 10 elementów tej tablicy linijka:
– zarezerwuj operatorem new tablicę  80 znaków,
– jej adres wpisz do kolejnego elementu tablicy linijka,
– w tej 80-znakowej tablicy znaków umieść C-string  "to jest linijka nr n", gdzie n  jest
kolejnym numerem linijki (0 – 9).
Po zrobieniu tego wobec wszystkich 10 elementów tablicy linijka  za pomocą pętli for wypisz
na  ekranie kolejno zawartość tych C-stringów.
W tablicy wskaźników linijka dokonaj  takiej zamiany, by zamienić zawartość elementu trzeciego
 z szóstym.
Za pomocą takiej samej jak poprzednio pętli for  wypisz na ekranie naszych 10 C-stringów.
Zlikwiduj wszystkie rezerwowane operatorem new  obiekty. (Jest ich 11).
*/

#include <iostream>
#include <cstring>

void wyswietl(char *linijka[]);
void wyczysc(char **linijka);

int main()
{
	using type = char *;
	type *linijka = new type[10];
	for (int i = 0; i < 10; ++i)
	{
		linijka[i] = new char[80];
		strcpy(linijka[i], "To jest linijka nr ");

		char l[2] = " ";
		l[0] = char('0' + i);
		strcat(linijka[i], l);
	}	

	wyswietl(linijka);

	char *tmp = linijka[3];
	linijka[3]=linijka[6];
	linijka[6]=tmp;

	std::cout<<"\n";
	wyswietl(linijka);

	wyczysc(linijka);
	return 0;
}

void wyswietl(char *linijka[])
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << linijka[i] << std::endl;
	}
}

void wyczysc(char **linijka){
	for (int i = 0; i < 10; ++i) delete[] linijka[i];
	delete[] linijka;
}