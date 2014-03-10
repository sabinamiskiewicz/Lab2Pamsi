#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int *wczytajdotablicy1(int &ilosc);
int *wczytajdotablicy2(int &ilosc);
int *mnozenie2(int *tablica,int ilosc);
void porownanie(int *tablica,int *tablica_porownawcza,int ilosc);
void zmianamiejscami(int *tablica,int i, int j);
void wyswietl(int *tablica, int ilosc);
void odwroctablice(int *tablica, int ilosc);
int *dodajelem(int *tablica,int& ilosc,int elem);
int *dodajelemy(int *tablica,int ilosc,int *tablica_porownawcza);


/*!
* \brief Funkcja glowna
*
* Funkcja glowna zapoczatkowywuje dzialanie programu.
* Zawiera wywolania funcji.
*/
int main()
{ 
  int ilosc;
  int elem=15;
  int i=2;
  int j=3;
  int *tablica = wczytajdotablicy1(ilosc);
  int *tablica_porownawcza = wczytajdotablicy2(ilosc);
  tablica=mnozenie2(tablica,5);
  porownanie(tablica,tablica_porownawcza, ilosc);
  zmianamiejscami(tablica,i,j);
  wyswietl(tablica,ilosc);
  odwroctablice(tablica,ilosc);
  wyswietl(tablica,ilosc);
  
  tablica =dodajelem(tablica,ilosc,elem);
  wyswietl(tablica,ilosc);

  system("PAUSE");
return 0;
}

/*!
* \brief Wczytuje dane z pliku 'Dane1' do tablicy
*
* Otwiera plik 'Dane1'.
* Z pliku 'Dane1' pobiera warosci i zapisuje je w tablicy.
* Zamyka plik 'Dane1'.
*/
int *wczytajdotablicy1(int &ilosc)
{
	int *tablica = new int[5];				/*!Tablica do ktorej wczytujemy dane z pliku 'DANE1'*/
 
	fstream plik;
  
	plik.open("Dane1.txt", ios::in);   /*!Plik otwarty w trybie do odczytu*/
  
	if(plik.good())     /*! Jesli plik poprawnie otwarty*/
	{
		plik >> ilosc;
	  for(int i = 0; i<ilosc; i++)
	    {
	      plik >> tablica[i];     /*! Czytaj do tablicy*/
		}
	}
      
	plik.close();		/*!Zamknij plik*/

	return tablica;
}

/*!
* \brief Wczytuje dane z pliku 'Dane2' do tablicy
*
* Otwiera plik 'Dane2'.
* Z pliku 'Dane2' pobiera warosci i zapisuje je w tablicy.
* Zamyka plik 'Dane2'.
*/
int *wczytajdotablicy2(int &ilosc)
{
	fstream plik;
	int *tablica_porownawcza = new int[5];
	plik.open("Dane2.txt", ios::in);		/*!Plik otwarty w trybie do odczytu */
  
	if(plik.good())     /*! Jesli plik poprawnie otwarty*/
	{
		plik>>ilosc;
	  for(int i = 0; i<ilosc; i++)
	  {
	    plik >> tablica_porownawcza[i];     /*! Czytaj do tablicy*/
	  }
	}
	plik.close();		/*!Zamknij plik*/
	return tablica_porownawcza;
		
}

/*!
* \brief Mnozy wartosci z tablicy przez 2
*
* Mnozy wartosci z tablicy przez 2.
*/
int * mnozenie2(int *tablica,int ilosc)
{
    for(int i = 0; i < ilosc; i++)	/*! for w ktorym mnozymy kazdy wyraz tablicy przez 2*/
      tablica[i] *= 2;
    return tablica;
}

/*!
* \brief Porowuje tablice z tablica porownawcza
*
* Sprawdza czy wyniki mnozenia sa zgodne z przewidywanymi wynikami.
* Wyswietla komunikat o zgodnosci lub niezgodnosci.
*/
void porownanie(int *tablica,int *tablica_porownawcza,int ilosc)
{
    for(int i = 0; i < ilosc; i++)	/*!for w ktorym sprawdzamy kazdy wyraz tablicy pomnozonej z tablica poprawnych*/
      if(tablica[i] == tablica_porownawcza[i])	/*! Porownanie elementow tablicy  porwnawczej z tablica pomnozonych*/
	cout << "Pod indeksem " << i << " wartosci tablic sa identyczne." << endl;
      else
	cout << "Pod indeksem " <<, i << " wartosci tablic sa rozne." << endl;
    
    for(int i = 0; i < ilosc; i++)
      cout << tablica[i] << "   " << tablica_porownawcza[i] << endl;

}
/*!
* \brief Zamienia miejscami dwa elementy tablicy
*
* Tworzy zmienna pomocnicza.
* Zapisuje w zm pomocniczej wartosc z tablicy ktora ma zmienic.
* Zamienia miejscami dwoch elementow.
*/
void zmianamiejscami(int *tablica,int i, int j)
{
int pom;
pom=tablica[i];
tablica[i]=tablica[j];
tablica[j]=pom;
}

/*!
* \brief Wyswietla tablice
*
* Wyswietla zawartosc tablicy.
*/
void wyswietl(int *tablica, int ilosc)
{
	cout<<endl;
for(int i=0;i<ilosc;i++)
	cout<<tablica[i]<<endl;
}
/*!
* \brief Odwraca tablice
*
* Funkcja odwraca tablice.
* Zamienia wartosci tab z 0 na n, z 1 na n-1 itp.
*/
void odwroctablice(int *tablica, int ilosc)
{
int i;
int pomoc;
for(i=0;i<ilosc/2;i++)
	{
		pomoc=tablica[i];
		tablica[i]=tablica[ilosc-i-1];
		tablica[ilosc-i-1]=pomoc;
	}	
}
/*!
* \brief Dodaje element do tablicy
*
* Tworzy nowa tablice 'pomoc' o ilosc+1 elementach.
* Uzupenia tab 'pomoc' wartosciami z tablicy.
* Dla pomoc[ilosc+1] dodaje nowa zadana wartosc.
*/
int *dodajelem(int *tablica,int &ilosc,int elem)
{
	int i;
int *pomoc=new int[ilosc+1];
for(i=0;i<ilosc;i++)
{
		pomoc[i]=tablica[i];
}
pomoc[ilosc]=elem;
ilosc++;
return pomoc;
}
/*!
* \brief Dodaje elementy do tablicy
*
* Tworzy nowa tablice pomoc.
* Do polowy wypenia ja wartosciami z tablicy tablica.
* Druga polowe wypelnia tablica tablica_porownawcza.
*/
int *dodajelemy(int *tablica,int ilosc,int *tablica_porownawcza)
{
int *pomoc=new int[ilosc*2+1];
*pomoc=ilosc*2;
for(int i=1;i<ilosc+1;i++)
	{
		pomoc[i]=tablica[i];
	}
for(int i=ilosc+1;i<=ilosc*2+1;i++)
	{
		pomoc[i]=tablica_porownawcza[i];
	}
return pomoc;
}