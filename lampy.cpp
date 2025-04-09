#include<iostream>
#include<queue>
#include<iomanip>

const int MAX_LICZBA_LAMP=1e5+7;
int DlugosciPrzerw[MAX_LICZBA_LAMP];
int IleLampWPrzerwie[MAX_LICZBA_LAMP];
std::priority_queue < std::pair<double, int> > kolejka_najwiekszych_popraw;

double CiemnaPrzestrzenPrzerwy (int dlugosc_przerwy, int ile_lampy_w_przerwie) {
      	
  int liczba_trojkatow;
  double przeciwprostokatna;
  double pole_trojkata;
  double pole_wszystkich_trojkotow;
  
  liczba_trojkatow = ile_lampy_w_przerwie+1;
  przeciwprostokatna = (double)dlugosc_przerwy / (double)liczba_trojkatow;
  pole_trojkata = przeciwprostokatna * przeciwprostokatna / (double)4;
  pole_wszystkich_trojkotow = (double)liczba_trojkatow * pole_trojkata;

  return pole_wszystkich_trojkotow;
}

int main (){
 std::ios_base::sync_with_stdio(0);
 std::cin.tie(0);
 std::cout.tie(0);

 int ile_oryginalnych_lamp, ile_dodatkowych_lamp, ile_przerw, dlugosc_kotarza;
 long long pozycja_poprzedniej_lampy, pozycja_akt_lampy;	
 int numer_przerwy, i;
 double suma_ciemnej_przestrzeni, kolejna_poprawa;
 std::pair <double, int> najwieksza_poprawa;

 std::cin >> ile_oryginalnych_lamp >> ile_dodatkowych_lamp >> dlugosc_kotarza;
 ile_przerw = ile_oryginalnych_lamp-1;
	
 std::cin >> pozycja_poprzedniej_lampy;
 for(i=0; i<ile_przerw; ++i){
	std::cin >> pozycja_akt_lampy;
	DlugosciPrzerw[i] = pozycja_akt_lampy - pozycja_poprzedniej_lampy;
	pozycja_poprzedniej_lampy = pozycja_akt_lampy;
 }
 
 for(i=0; i<ile_przerw; ++i){
	kolejna_poprawa = CiemnaPrzestrzenPrzerwy(DlugosciPrzerw[i], 0) - CiemnaPrzestrzenPrzerwy(DlugosciPrzerw[i], 1);
	kolejka_najwiekszych_popraw.push( std::make_pair(kolejna_poprawa, i) );
 }
 
 for(i=0; i<ile_dodatkowych_lamp; ++i){
    najwieksza_poprawa = kolejka_najwiekszych_popraw.top();
	kolejka_najwiekszych_popraw.pop();
	numer_przerwy = najwieksza_poprawa.second;
	++IleLampWPrzerwie[numer_przerwy];
	kolejna_poprawa = CiemnaPrzestrzenPrzerwy (DlugosciPrzerw[numer_przerwy], IleLampWPrzerwie[numer_przerwy]) -
	                  CiemnaPrzestrzenPrzerwy (DlugosciPrzerw[numer_przerwy], IleLampWPrzerwie[numer_przerwy]+1);
	kolejka_najwiekszych_popraw.push( std::make_pair(kolejna_poprawa, numer_przerwy) );
 }

 suma_ciemnej_przestrzeni = 0;
 for(i=0; i<ile_przerw; i++){
	suma_ciemnej_przestrzeni += CiemnaPrzestrzenPrzerwy(DlugosciPrzerw[i], IleLampWPrzerwie[i]);
 }
 
 std::cout << std::fixed << std::setprecision(9) << suma_ciemnej_przestrzeni << "\n";
 return 0;
}
