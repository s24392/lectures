#include <iostream>
#include <cstdlib>
#include <windows.h>

int *** macierz;
int * wiersze;
int * kolumny;
float *** wynik;



void zwalnianie_pamieci_macierz(int liczba_macierzy){

    for (int ktora_macierz = 0; ktora_macierz < liczba_macierzy-1 ; ktora_macierz++) {
        for (int ktory_wiersz = 0; ktory_wiersz < wiersze[ktora_macierz]; ktory_wiersz++) {
            for (int ktora_kolumna = 0; ktora_kolumna < kolumny[ktora_macierz]; ktora_kolumna++) {
                delete[] macierz[ktory_wiersz][ktora_kolumna];
            }
            delete[] macierz[ktory_wiersz];
        }
    }
    delete[] macierz;
    delete[] kolumny;
    delete [] wiersze;
}

void zwalnianie_pamieci_wynik(int liczaba_wynikow){

    for (int ktory_wynik = 0; ktory_wynik < liczaba_wynikow-1 ; ktory_wynik++) {
        for (int ktory_wiersz = 0; ktory_wiersz < wiersze[ktory_wynik]; ktory_wiersz++) {
            for (int ktora_kolumna = 0; ktora_kolumna < kolumny[ktory_wynik]; ktora_kolumna++) {
                delete[] wynik[ktory_wiersz][ktora_kolumna];
            }
            delete[] wynik[ktory_wiersz];
        }
    }
}



void tworzenie_wynikow(int liczba_macierzy){

	wynik = new float **[liczba_macierzy];
	for ( int ktora_macierz = 0; ktora_macierz < liczba_macierzy; ktora_macierz++)
	{
        if(liczba_macierzy>1){
		wynik[ktora_macierz] = new float * [wiersze[1]];
		for (int ktory_wiersz = 0; ktory_wiersz < wiersze[1]; ktory_wiersz++)
		{
			wynik[ktora_macierz][ktory_wiersz] = new float[kolumny[0]];
		}

        } else{
            wynik[ktora_macierz] = new float * [wiersze[0]];
            for (int ktory_wiersz = 0; ktory_wiersz < wiersze[0]; ktory_wiersz++)
            {
                wynik[ktora_macierz][ktory_wiersz] = new float[kolumny[0]];
            }

        }
	}
}


void tworzenie_macierzy(int liczba_macierzy){
    int error=0;
	wiersze = new int[liczba_macierzy];
	kolumny = new int[liczba_macierzy];
	macierz = new int** [liczba_macierzy];
	int ktora_macierz;
	int ktory_wiersz;
		
	for (ktora_macierz = 0; ktora_macierz < liczba_macierzy; ktora_macierz++)
	{
		std::cout << "podaj ilosc wierszy "<< ktora_macierz + 1 << " macierzy:";
		std::cin >> wiersze[ktora_macierz];
        system("cls");
        if (wiersze[ktora_macierz]<1){
            std::cout<<"ERR";
            if(ktora_macierz>0)
            {
                zwalnianie_pamieci_macierz(1);

            }
            else{
                delete [] macierz;
                delete [] kolumny;
                delete [] wiersze;
            }
            exit (0);
        }

		macierz[ktora_macierz] = new int * [wiersze[ktora_macierz]];

		std::cout << "podaj ilosc kolumn " << ktora_macierz + 1 << " macierzy:";
		std::cin >> kolumny[ktora_macierz];
        system("cls");
        if(kolumny[ktora_macierz]<1){
            error=1;
            kolumny[ktora_macierz]=1;
        }

		for (ktory_wiersz = 0; ktory_wiersz < wiersze[ktora_macierz]; ktory_wiersz++)
		{
			macierz[ktora_macierz][ktory_wiersz] = new int[kolumny[ktora_macierz]];
		}

        if (error==1)
        {   std::cout<<"ERR";
            zwalnianie_pamieci_macierz(ktora_macierz);
            exit(0);
        }
		/*uzupelnianie macierzy*/
		for (ktory_wiersz = 0; ktory_wiersz < wiersze[ktora_macierz]; ktory_wiersz++)
		{
			for (int ktotra_kolumna = 0; ktotra_kolumna < kolumny[ktora_macierz]; ktotra_kolumna++)
			{
				std::cout << "podaj " << ktotra_kolumna + 1 << " wartosc macierzy w " << ktory_wiersz + 1 << " wierszu " << ktora_macierz + 1 << " macierzy" << ":";
				std::cin >> macierz[ktora_macierz][ktory_wiersz][ktotra_kolumna];
                system("cls");
			}
		}
	}
}

int main() {
	int wybor;
    std::cout<<"1.Dodawanie i odejmowanie macierzy"<<"\n"
    <<"2.Mnozenie macierzy"<<"\n"
    <<"3.Transpozycja macierzy"<<"\n"
    <<"4.Obliczanie wyznacznika macierzy kwadratowej"<<"\n";
	std::cin >> wybor;
    system("cls");
	switch (wybor)
	{
	case 1:
		tworzenie_macierzy(2);
        if(wiersze[0]!=wiersze[1] || kolumny[0]!=kolumny[1]) {
            std::cout<<"ERR";
            zwalnianie_pamieci_macierz(2);
            break;
        }

		tworzenie_wynikow(2);
		
		std::cout << "wynik dodawania macierzy:" << "\n";
		for (int i = 0; i < wiersze[0]; i++)
		{ 
			for (int z = 0; z < kolumny[0]; z++)
			{
				wynik[0][i][z] = macierz[0][i][z] + macierz[1][i][z];
				std::cout << wynik[0][i][z] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "wynik odejmowania macierzy:" << "\n";
		for (int i = 0; i < wiersze[1]; i++)
		{
			for (int z = 0; z < kolumny[1]; z++)
			{
				wynik[1][i][z] = macierz[0][i][z] - macierz[1][i][z];
				std::cout << wynik[1][i][z] << " ";
			}
			std::cout << "\n";
		}
            zwalnianie_pamieci_wynik(2);
            zwalnianie_pamieci_macierz(2);


		break;


	case 2:
        tworzenie_macierzy(2);
            if(wiersze[1]!=kolumny[0]) {
                std::cout<<"ERR";
                zwalnianie_pamieci_macierz(2);
                break;
            }
            kolumny[0]=kolumny[1];
            tworzenie_wynikow(1);
            std::cout << "wynik mnozenia macierzy:" << "\n";
            for (int i = 0; i < wiersze[0]; i++) {
                for (int z = 0; z < kolumny[1]; z++) {

                    wynik[0][i][z] = 0;
                    for (int x = 0; x < kolumny[0]; x++){
                        wynik[0][i][z] = wynik[0][i][z] + (macierz[0][i][x] * macierz[1][x][z]);
                }
                    std::cout << wynik[0][i][z] << " ";
                }
                std::cout<<"\n";
            }
            zwalnianie_pamieci_wynik(1);
            zwalnianie_pamieci_macierz(2);
		break;

	case 3:
        tworzenie_macierzy(1);
        int transpozycja_kolumn , transpozycja_wierszy;
        transpozycja_wierszy=wiersze[0];
        transpozycja_kolumn=kolumny[0];
        wiersze[0]=transpozycja_kolumn;
        kolumny[0]=transpozycja_wierszy;
        tworzenie_wynikow(1);
            for (int i = 0; i < wiersze[0]; i++) {
                for (int z = 0; z < kolumny[0]; z++) {
                    wynik[0][i][z] = macierz[0][z][i];
                    std::cout << wynik[0][i][z] << " ";
                }
                std::cout<<"\n";
            }
            zwalnianie_pamieci_wynik(1);
            wiersze[0]=transpozycja_wierszy;
            kolumny[0]=transpozycja_kolumn;
            zwalnianie_pamieci_macierz(1);
		break;


	case 4:
        wiersze=new int [1];
        kolumny=new int [1];
        wiersze[0]=2;
        kolumny[0]=2;
            tworzenie_wynikow(1);
            for (int ktory_wiersz = 0; ktory_wiersz < wiersze[0]; ktory_wiersz++) {
                for (int ktotra_kolumna = 0; ktotra_kolumna < kolumny[0]; ktotra_kolumna++) {
                    std::cout << "podaj " << ktotra_kolumna + 1 << " wartosc macierzy w " << ktory_wiersz + 1
                              << " wierszu macierzy" << ":";
                    std::cin >> wynik[0][ktory_wiersz][ktotra_kolumna];
                    system("cls");
                }
            }
                std::cout <<"Wyznacznik tej macierzy jest rowny:"<<(wynik[0][0][0]*wynik[0][1][1])-(wynik[0][0][1]*wynik[0][1][0]);
                zwalnianie_pamieci_wynik(1);
                delete [] kolumny;
                delete [] wiersze;

		break;

	default:
		std::cout << "Nie wybarales zadnej z powyzszych opcji.";
		break;
	}
}