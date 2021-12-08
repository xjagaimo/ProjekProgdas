/**
 * Project Untitled
 */


#ifndef _DISPLAY_H
#define _DISPLAY_H

class Display {
  public:  
    void menuMain();
    //Menampilkan menu utama pertama
    
    void menuBuku();
    //Menampilkan daftar buku yang tersedia dalam database

    void menuLogin();
    //Menampilkan halaman login admin toko  
    
    void menuAdmin(int);
    //Menampilkan opsi add, edit, dan delete entri buku bagi admin
    
    void menuBuy();
    //Menampilkan detail buku yang akan dibeli
    
    void menuEdit();
    //Menampilkan halaman untuk mengedit buku yang tersedia dalam database

    void menuDelete();
    //Menampilkan halaman untuk menghapus buku yang tersedia dalam database

    void menuAdd();
    //Menampilkan halaman untuk menambah buku yang tersedia dalam database
};

#endif //_DISPLAY_H