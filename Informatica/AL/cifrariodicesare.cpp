/******************************************************************************
 *
 * cifrariodicesare.cpp
 *
 * Questo programma chiede all'utente di scrivere un testo
 * Successivamente la chiave di codifica
 * Lo codifica mostrando il risultato a video
 *  Salva il testo codificato in un file
 *  Legge il file
 * Chiede la chiave di decodifica
 * Mostra il risultato in chiaro (se la chiave e' corretta)
 * 
 * (c) Giacomo Alessandroni, Feb 24th 2023, GNU/GPL 3.0
 * 
 ******************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class codifica {
    private:
        string plainText;   // Testo in chiaro
        string codedText;   // Testo codificato
        int key = 0;        // Chiave di cifratura
    public:
        // Acquisisce il testo
        void getText() {
            getline(cin, plainText);
            // Converte il testo in maiuscolo
            transform(plainText.begin(), plainText.end(), plainText.begin(), toupper);
        }
        
        // Imposta la chiave di cifratura
        void getKey() {
            key = 0;
            while (key < 1 || key > 25)
                cin >> key;
        }
        
        // Codifica il testo
        void code() {
            codedText = "";
            for (int i = 0; i < plainText.length(); i++)
                if (plainText[i] != ' ')
                    codedText += ( plainText[i] - 'A' + key ) % 26 + 'A';
                else
                    codedText += ' ';
            cout << "|-> " << codedText << " <-|\n";
        }

        // Decodifica il testo
        void decode() {
            plainText = "";
            for (int i = 0; i < codedText.length(); i++)
                if (codedText[i] != ' ')
                    plainText += ( codedText[i] - 'A' - key + 26 ) % 26 + 'A';
                else
                    plainText += ' ';
            cout << "|-> " << plainText << " <-|\n";
        }        
};


int main()
{
    cout << "Cifrario di Cesare\n\n";
    
    codifica cifra;
    
    // Acquisisce il testo
    cout << "Digitare il testo da cifrare\n";
    cifra.getText();
    
    // Imposta la chiave di cifratura
    cout << "Inserire la chiave di cifratura (1 ... 25): ";
    cifra.getKey();
    
    // Codifica il testo
    cout << "Di seguito il testo criptato\n"; 
    cifra.code();

    // Imposta la chiave di decifratura
    cout << "Inserire la chiave di decifratura (1 ... 25): ";
    cifra.getKey();
    
    // Decodifica il testo
    cout << "Di seguito il testo in chiaro\n";
    cifra.decode();    

    return 0;
}
