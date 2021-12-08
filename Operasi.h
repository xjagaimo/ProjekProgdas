/**
 * Project Untitled
 */


#ifndef _OPERASI_H
#define _OPERASI_H
#include "Buku.h"

class Operasi {
  public: 
    
    void addBuku(string, string, string, int, int);
    //Memasukkan data dari parameter ke atribut tiap objek
    
    void editBuku(string, string, string, int, int, int);
    //Menyunting data atribut tiap objek
    
    void delBuku(int);
    //Menghapus data atribut objekyang dipilih

    void getDetail(int);
    //Memberikan data menyeluruh dari objek yang dipilih

    string printItemJudul(int);
    //Memberikan atribut 'judul' dari sebuah objek

    int printItemHarga(int);
    ////Memberikan atribut 'harga' dari sebuah objek
    
    string printItemPenulis(int);
    //Memberikan atribut 'penulis' dari sebuah objek

    string printItemGenre(int);
    //Memberikan atribut 'genre' dari sebuah objek

    void setItemJudul(int, string);
    //Memasang nilai judul
    
    void setItemPenulis(int, string);
    //Memasang nilai penulis

    void setItemGenre(int, string);
    //Memasang nilai genre

    void setItemHarga(int, int);
    //Memasang nilai harga

};

#endif //_OPERASI_H