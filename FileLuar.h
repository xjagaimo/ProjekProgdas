#ifndef _FILELUAR_H
#define _FILELUAR_H
#include "Buku.h"

extern int jumlahBuku;

class FileLuar {
public:

void rewriteFile();
//Memperbaharui data pada file eksternal "database.txt"

int readFile();
//Membuka dan mengambil data dari file eksternal "database.txt"
    
void writeFile(string, int, int);
//Membuat file eksternal "Nota.txt" dan menuliskan output pada file tersebut

};
#endif //_FILELUAR_H