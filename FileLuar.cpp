#include <iostream>
#include <string.h>
#include <fstream>
#include "FileLuar.h"
#include "Operasi.h"
using namespace std;

bool selesai = false;
FILE *database;
char str[200], chr[200];
string judul, penulis, genre;
int harga;
int jumlahBuku;

int FileLuar::readFile() {
  int jumlahBuku = 0;
  Operasi operasi;
  database = fopen("database.txt","r+");
  for (int line = 1; line <= 80; line++){
    if(!feof(database)){
    fgets(str, 200, database);
      if (strncmp(str, "", 1) != 0){
        switch (line%4){
          case 0:
            harga = stoi(str);
            operasi.addBuku(judul, penulis, genre, harga, line/4);
            jumlahBuku++;
            break;
          case 1:
            judul = str;
            break;
          case 2:
            penulis = str;
            break;
          case 3:
            genre = str;
            break;
        }
      }
    }
  }
  fclose(database);
  return jumlahBuku;
}

void FileLuar::writeFile(string judul, int qty, int harga) {
  int total;
  ofstream outFile;
  outFile.open("Nota.txt");

  outFile << "\t\t\t\t<>◇<>◇<>◇<>◇<>◇<>◇<>◇<>◇<>";
  outFile << "\n\t\t\t\t\t\tグラマディオスへようこそ";
  outFile << "\n\t\t\t\t\t\tGramadios Book Store";
  outFile << "\n\t\t\t\t<>◇<>◇<>◇<>◇<>◇<>◇<>◇<>◇<>\n\n";

  outFile << "Product \t: " << judul;
  outFile << "Quantity \t: " << qty;
  outFile << "\nPrice \t\t: " << harga;
  outFile << endl << "\nTotal \t\t: " << qty*harga << endl;
  
  outFile << "-------------------------------------------------------" << endl;
  outFile << "\tThank you for purchasing at グラマディオス!" << endl;
  outFile << "\n\t\t\t\t\t\t\t\td(=^･ω･^=)b" << endl;
}

void FileLuar::rewriteFile(){
  Operasi opr;
  int e = 1, a;
  database = fopen("database.txt","w");
  for(int i = 1; i<=80; i++){
    switch(i%4){
      case 0:
      {
        if(opr.printItemHarga(e)!=0){
        cout<< endl;
        sprintf(chr, "%d", opr.printItemHarga(e));
        fputs(chr,database);
        fputs("\n",database);
        }
        e++;
        break;
      }
      case 1:
      {
          strcpy(chr, opr.printItemJudul(e).c_str());
          fputs(chr,database);
        break;
      }
      case 2:
      {
          strcpy(chr, opr.printItemPenulis(e).c_str());
          fputs(chr,database);
        break;
      }
      case 3:
      {
          strcpy(chr, opr.printItemGenre(e).c_str());
          fputs(chr,database);
        break;
      }
    }

  }
  fclose(database);
}