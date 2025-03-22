#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class koneisto {
    public:
        struct aggregaatti {
            struct polttomoottori {
                std::string cppcode;
            };
        };
};

int main() {

    // Määritellään polttomoottori
    koneisto::aggregaatti::polttomoottori polttomoottori;

    // Pitää emuloida polttomoottori joka tuottaa signaalia on/off muodossa, (binääriä)
    // generaattoria ajaa polttomoottori, syö polttoainetta c++ ja tuottaa mekaanista energiaa eli tässä tapauksessa assembly koodia,
    // jonka generaattori muuttaa edelleen sähköenergiaksi eli on/off signaaleiksi (binääriksi).
    // Korjaus: sähköenergiaa tai mekanista energiaahan tällä ei pystytä tuottamaan.
    // mutta voidaan simuloida polttoaine (c++) assemblyksi, ja mekaaninen energia (assembly) binääriksi.
    // Tämä olisi emuloitu aggregaatti.

    std::cout << "Pistetään c++ polttomoottoriin!" << std::endl;
    polttomoottori.cppcode = "int main () { char a = 'a'; return 0; }";

    // Polttomoottori
    // Write c++ code to a file
    ofstream assemblyfile("cppcode.cpp");      // Create and open a text file
    assemblyfile << polttomoottori.cppcode;    // Write to the file
    assemblyfile.close();                      // Close the file

    // Generaattori
    // Polttoaine (cppcode.cpp) -> Assembly koodi (assembly.s)...
    system("g++ -S -o assembly.s cppcode.cpp");

    // Generaattori 2
    // Kokoa biinäritiedosto assembly koodista
    system("g++ -o output.exe assembly.s");

    // Tulosta binäärit
    system("xxd -b output.exe");
    
    return 0;
}