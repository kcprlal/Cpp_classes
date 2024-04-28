// jak wpisujesz adres to w formacie liczba liczba liczba liczba
// nie wpisuj nic innego bo nie jestem w stanie stwierdzic co sie stanie

#include <iostream>
#include <cstdlib>
#include <ctime>

int przypiszmaske(int);
void zerujtablice(int *, int *);
void wyswietl(int *);
void wprowadz(int *);
void oblicz_siec_rozglosz(int *, int *, int *, int *);
bool sprawdz(int *, int *);

int main()
{
    bool koniec = false, test;
    int adres[4], maska[4];
    srand((unsigned)time(NULL));

    while (true)
    {
        int adres_sieci[4]{}, adres_rozglosz[4]{}, uip[4]{}, ubroadcast[4]{}, los = rand() % 31;
        zerujtablice(adres, maska);
        // przypisywanie adresu i maski
        int los2 = los;
        for (int i = 0; i < 4; i++)
        {
            adres[i] = rand() % 256;
            if (los - 8 >= 0)
                maska[i] = 255;
            else
                maska[i] = przypiszmaske(los);
            los -= 8;
        }

        oblicz_siec_rozglosz(adres, maska, adres_sieci, adres_rozglosz);

        std::cout << "IP:    ";
        wyswietl(adres);

        std::cout << "maska: /" << los2 << "\n";
        //wyswietl(maska);

        std::cout << "------------------------\n"
                  << std::endl
                  << "Wprowadz adres sieci, a nastepnie adres rozgloszeniowy\n";

        wprowadz(uip);
        wprowadz(ubroadcast);

        std::cout << "------------------\n";

        test = sprawdz(uip, adres_sieci);

        if (test)
            std::cout << "Adres sieci jest git\n";
        else
            std::cout << "zly adres sieci ;(\n";

        test = sprawdz(ubroadcast, adres_rozglosz);

        if (test)
            std::cout << "Adres rozgloszeniowy jest git\n";
        else
            std::cout << "zly adres rozgloszeniowy ;(\n";

        std::cout << "------------------\n";

        std::cout << "porawny adres sieci: ";
        wyswietl(adres_sieci);

        std::cout << "poprawny adres rozgloszeniowy: ";
        wyswietl(adres_rozglosz);

        std::cout << "\nlecimy dalej?(jak chcesz dalej wpisz 0)\n";
        std::cin >> koniec;

        if (koniec)
            break;
    }
    return 0;
}

int przypiszmaske(int los)
{
    int result = 0, i = 1;
    for (los; los > 0; los--)
    {
        result += 128 / i;
        i *= 2;
    }
    return result;
}

bool sprawdz(int *wprowadz, int *porownaj)
{
    for (int i = 0; i < 4; i++)
    {
        if (wprowadz[i] != porownaj[i])
        {
            return false;
        }
    }
    return true;
}

void zerujtablice(int adres[], int maska[])
{
    for (int i = 0; i < 4; i++)
    {
        adres[i] = 0;
        maska[i] = 0;
    }
}

void wyswietl(int tab[])
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << tab[i] << ".";
    }
    std::cout << std::endl;
}

void wprowadz(int tab[])
{
    for (int i = 0; i < 4; i++)
    {
        std::cin >> tab[i];
    }
}

void oblicz_siec_rozglosz(int adres[], int maska[], int adres_sieci[], int adres_rozglosz[])
{
    for (int i = 0; i < 4; i++)
    {
        adres_sieci[i] = adres[i] & maska[i];

        if (maska[i] == 255)
            adres_rozglosz[i] = adres[i];

        else if (maska[i] == 0)
        {
            adres_rozglosz[i] = 255;
        }

        else
            adres_rozglosz[i] = adres_sieci[i] + 255 - maska[i];
    }
}