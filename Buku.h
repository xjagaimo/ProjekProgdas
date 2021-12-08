/**
 * Project Untitled
 */


#ifndef _BUKU_H
#define _BUKU_H

#include <string>
using namespace std;

class Buku {
    public: 
    
/**
 * @param string judul
 * @param string penulis
 * @param int harga
 * @param string genre
 */
        void setJudul(string judul);
            //Function untuk set judul buku
            //Postcondition: Buku::judul = judul

        void setPenulis(string penulis);
            //Function untuk set penulis buku
            //Postcondition: Buku::penulis = penulis
    
        void setHarga(int harga);
            //Function untuk set harga buku
            //Postcondition: Buku::harga = harga
    
        void setGenre(string genre);
            //Function untuk set genre buku
            //Postcondition: Buku::genre = genre

        string getJudul() const;
            //Function untuk mereturn genre buku
            //Postcondition: return string Buku::judul
    
        string getPenulis() const;
            //Function untuk mereturn penulis buku
            //Postcondition: return string Buku::penulis
    
        int getHarga() const;
            //Function untuk mereturn harga buku
            //Postcondition: return nilai Buku::harga
    
        string getGenre() const;
            //Function untuk mereturn genre buku
            //Postcondition: return string Buku::genre

        Buku(string judul = "", string penulis = "", int harga = 0, string genre = "");
            //Constructor
            //Set judul, penulis, harga, dan genre ke dalam atribut private yang bersesuaian dalam Buku
            //Nilai default judul, penulis, dan genre adalah string kosong, nilai default harga adalah 0
            //Postcondition: Buku::judul = judul
            //               Buku::penulis = penulis
            //               Buku::harga = harga
            //               Buku::genre = genre

    private: 
        string judul;
        string penulis;
        int harga;
        string genre;
};

#endif //_BUKU_H