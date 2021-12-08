#include "Display.h"
#include "Operasi.h"
#include "FileLuar.h"
#include <iostream>
#include <string>
using namespace std;

void Display::menuMain()
{
  int choice;
  p:
  system("clear");
  cout << "\n\t\t\t\tグラマディオスへようこそ\n"; 
  cout << "\t\t\t\t (Gramadios Book Store)\n\n"; 
  cout << "1. Browse Book" << endl;
  cout << "2. Login as Admin" << endl;
  cout << "0. Close App\n\n";

  cout << "Enter your choice = "; 
  cin >> choice;

  switch (choice) {
    case 1:
      menuBuy();
      break;
    case 2:
      menuLogin();
      break;
    case 0:
      exit(0);
      break;
    default:
      goto p;
  }
}

void Display::menuBuku()
{
  system("clear");
  FileLuar fl;
  Operasi opr;
  cout << "List of Titles :" << endl;
  for (int i = 1; i <= fl.readFile(); i++){
    cout << i << ". "<< opr.printItemJudul(i);
  }
}

void Display::menuAdmin(int mes)
{
  FileLuar fl;
  int choice = 0; 
  p:
  system("clear");

  switch (mes){
    case 1:
      cout << "Changes saved."<< endl << endl;
      break;
    case 2:
      cout << "Changes not saved."<< endl << endl;
      break;
    default:
      cout << "Login successful!" << endl << endl;
  }

  cout << "1. Add Book" << endl;
  cout << "2. Edit Book" << endl;
  cout << "3. Delete Book" << endl;
  cout << "4. Back to Main Menu" << endl << endl;

  cout << "Enter your choice: "; 
  cin >> choice;

  switch (choice)
  {
    case 1:
      menuAdd();
      break; 
    case 2:
      menuEdit();
      break;
    case 3:
      menuDelete();
      break;
    case 4:
      menuMain();
      break;
    default:
      goto p;
  }
}

void Display::menuLogin()
{
  system("clear");
  string uname, pass;
  cout << "Login as Admin" << endl;
  cout<<"Enter your username : "; 
  cin>>uname;
  cout<<"Enter your password : ";
  cin>>pass;
 
  if(uname=="admin" && pass=="admin")
  {
    menuAdmin(0);
  }
  else
  {
    int choice;
    p:
    system("clear");
    cout << "Your username or password is incorrect" << endl;
    cout << "1. Back to Main Menu" << endl;
    cout << "2. Try Again" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
          menuMain();
          break;
        case 2:
          menuLogin();
          break;
        default:
          goto p;
    }
  }
}

void Display::menuEdit()
{
  int a, e;
  Operasi ed;
  FileLuar fl;
  p:
  menuBuku();
  cout << "Whick book do you want to edit: ";
  cin >> a;
  ed.getDetail(a);
  cout << "\n1. Edit Title" << endl;
  cout << "2. Edit Author" << endl;
  cout << "3. Edit Genre" << endl;
  cout << "4. Edit Price" << endl;
  cout << "\nChoose an option: ";
  cin >> e;
  system("clear");

  switch (e)
  {
    case 1: {
      string title;
      cout << "New Title: ";
      cin.get();
      getline(cin, title);
      ed.editBuku(title+"\n", "", "", 0, a, 1);
      break; }
    case 2: {
      string author;
      cout << "New Author: ";
      cin.get();
      getline(cin, author);
      ed.editBuku("", author+"\n", "", 0, a, 2);
      break; }
    case 3: {
      string genre;
      cout << "New Genre: ";
      cin.get();
      getline(cin, genre);
      ed.editBuku("", "", genre+"\n", 0, a, 3);
      break; }
    case 4: {
      int price;
      cout << "New Price: ";
      cin >> price;
      ed.editBuku("", "", "", price, a, 4);
      break; }
    default:
      goto p;
  }

  fl.rewriteFile();
  fl.readFile();
  menuAdmin(1);
}

void Display::menuBuy(){
  int qty = 0, harga, i, e;
  string buy;
  string judul;
  p:
  menuBuku();
  cout << "\nAction: " << endl;
  cout << "1. Choose Book" << endl; 
  cout << "0. Back" << endl;
  cout << "Input: ";
  cin >> i;

  switch (i){
    case 1: 
      cout << endl << "Input Book Number: ";
      cin >> e;

      if (0<e && e <= 20) {
        Operasi opr;
        opr.getDetail(e);
        judul = opr.printItemJudul(e);
        harga = opr.printItemHarga(e);
        cout << endl << "Are you sure you want to buy? (yes/no): ";
        cin >> buy;

          if (buy=="true" || buy == "1" || buy == "yes" || buy == "y"){
            cout << "How many copies?: ";
            cin >> qty;
            FileLuar nota;
            nota.writeFile(judul, qty, harga);
          
            cout << "\nTransaction completed successfully" << endl;
            cout << "\t\t\tThank you for purchasing at グラマディオス!" << endl;
            cout << "\t\t\t\tWe hope to see you againヾ(＾∇＾) " << endl;
          }
          else goto p;
      }
      else goto p;
      break;
    case 0: 
      menuMain();
      break;
    default:
      goto p;
  }
}

void Display::menuDelete(){
  Operasi opr;
  string tempJudul,tempPenulis, tempGenre;
  FileLuar fl;
  int e, tempHarga;
  string a;
  menuBuku();
  if (fl.readFile()!= 0){
  cout << "Delete which book? ";
  cin >> e;
  cout << "Are you sure? ";
  cin >> a;
  if (a=="yes" || a=="y"){
    //menukarkan nilai (judul, penulis, genre, harga) pada item yang akan dihapus dengan item terakhir. Hal ini dilakukan sebab ada bug jika tidak dilakukan.
    tempJudul = opr.printItemJudul(fl.readFile());
    tempPenulis = opr.printItemPenulis(fl.readFile());
    tempGenre = opr.printItemGenre(fl.readFile());
    tempHarga = opr.printItemHarga(fl.readFile());
    opr.setItemJudul(fl.readFile(), opr.printItemPenulis(e));
    opr.setItemPenulis(fl.readFile(), opr.printItemPenulis(e));
    opr.setItemGenre(fl.readFile(), opr.printItemGenre(e));
    opr.setItemHarga(fl.readFile(), opr.printItemHarga(e));
    opr.setItemJudul(e, tempJudul);
    opr.setItemPenulis(e, tempPenulis);
    opr.setItemGenre(e, tempGenre);
    opr.setItemHarga(e, tempHarga);
    
    fl.rewriteFile();
    opr.delBuku(fl.readFile());
    fl.readFile();
    menuAdmin(1);
  }
  else{
    menuAdmin(2);
  }}
  else{
    cout << "You cannot delete more books. ";
    menuAdmin(2);
  }
}

void Display::menuAdd(){
  FileLuar fl;
  if( fl.readFile() != 20){
    Operasi opr;
    FileLuar fl;
    string judul, penulis, genre;
    int harga;
    cout << "New book name: ";
    cin.get();
    getline(cin,judul);
    cout << "New book author: ";
    getline(cin,penulis);
    cout << "New book genre: ";
    getline(cin,genre);
    cout << "New book price: ";
    cin >> harga;
    opr.addBuku(judul+"\n", penulis+"\n", genre+"\n", harga, fl.readFile()+1);
    fl.rewriteFile();
    fl.readFile();
    menuAdmin(1);
  }
  else{
    cout << "You cannot add more books. ";
    menuAdmin(2);
  }
}