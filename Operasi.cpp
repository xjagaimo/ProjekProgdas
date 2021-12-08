#include <iostream>
#include "Operasi.h"
#include "Buku.h"
#include "FileLuar.h"
using namespace std;


/**
 * Operasi implementation
 */
Buku itemBuku[20];

void Operasi::addBuku(string judul, string penulis, string genre, int harga, int bukuKe){
  itemBuku[bukuKe].setJudul(judul);
  itemBuku[bukuKe].setPenulis(penulis);
  itemBuku[bukuKe].setGenre(genre);
  itemBuku[bukuKe].setHarga(harga);
}

void Operasi::editBuku(string judul = "", string penulis = "", string genre = "", int harga = 0, int bukuKe = 0, int editNo = 0) 
{
    switch (editNo){
    case 1:
      itemBuku[bukuKe].setJudul(judul);
      break;
    case 2:
      itemBuku[bukuKe].setPenulis(penulis);
      break;
    case 3:
      itemBuku[bukuKe].setGenre(genre);
      break;
    case 4:
      itemBuku[bukuKe].setHarga(harga);
      break;
  }
}

void Operasi::delBuku(int bukuKe){
  itemBuku[bukuKe].setJudul("");
  itemBuku[bukuKe].setPenulis("");
  itemBuku[bukuKe].setGenre("");
  itemBuku[bukuKe].setHarga(0);
  FileLuar fl;
  fl.rewriteFile();
}

void Operasi::getDetail(int bukuKe) {
  cout << endl << bukuKe << ". " << itemBuku[bukuKe].getJudul();
  cout << "Author: " << itemBuku[bukuKe].getPenulis();
  cout << "Genre: " << itemBuku[bukuKe].getGenre();
  cout << "Price: " << itemBuku[bukuKe].getHarga();
}


string Operasi::printItemJudul(int bukuKe) {
  return itemBuku[bukuKe].getJudul();
}

int Operasi::printItemHarga(int bukuKe) {
  return itemBuku[bukuKe].getHarga();
}

string Operasi::printItemPenulis(int bukuKe) {
  return itemBuku[bukuKe].getPenulis();
}

string Operasi::printItemGenre(int bukuKe) {
  return itemBuku[bukuKe].getGenre();
}

void Operasi::setItemJudul(int bukuKe, string Judul) {
  itemBuku[bukuKe].setJudul(Judul);
}

void Operasi::setItemPenulis(int bukuKe, string Penulis) {
  itemBuku[bukuKe].setPenulis(Penulis);
}

void Operasi::setItemGenre(int bukuKe, string Genre) {
  itemBuku[bukuKe].setGenre(Genre);
}

void Operasi::setItemHarga(int bukuKe, int Harga) {
  itemBuku[bukuKe].setHarga(Harga);
}