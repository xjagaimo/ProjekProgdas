#include <iostream>
#include <string>
#include "Buku.h"

/**
 * Buku implementation
 */


/**
 * @param string judul
 * @param string penulis
 * @param int harga
 * @param string genre
 */
Buku::Buku(string judul, string penulis, int harga, string genre) {
    Buku::judul = judul;
    Buku::penulis = penulis;
    Buku::genre = genre;
    Buku::harga = harga;
}

void Buku::setJudul(string judul) {
    Buku::judul = judul;
}

void Buku::setPenulis(string penulis) {
    Buku::penulis = penulis;
}

void Buku::setHarga(int harga) {
    Buku::harga = harga;
}

void Buku::setGenre(string genre) {
    Buku::genre = genre;
}

string Buku::getJudul() const{
    return Buku::judul;
}

string Buku::getPenulis() const{
    return Buku::penulis;
}

int Buku::getHarga() const{
    return Buku::harga;
}

string Buku::getGenre() const{
    return Buku::genre;
}