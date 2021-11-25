#include<iostream>
using namespace std;

class item {
	public:
	string nama;
	int harga;
};

item benda[3];

void display() {
	for (int i=0; i<3; i++) { // display
	cout << benda[i].nama << endl;
	cout << benda[i].harga << endl; 
	}
}
	
int main() {
	
	bool edit = 0;
	int a;
	
	for (int i=0; i<3; i++) { //add item
	cout << "Nama: " ;
	cin >> benda[i].nama;
	cout << "Harga: ";
	cin >> benda[i].harga; 
	}
	display();
		
	cout << "mau ngedit gan? [true/false]";	// edit
	cin >> edit;
	if (edit) {
	cout << "barang ke berapa gan?";
	cin >> a;
	cout << "Barang ke"<<a<<endl;
	cout << "Nama: " ;
	cin >> benda[a].nama;
	cout << "Harga: ";
	cin >> benda[a].harga;
	display(); 
	}
return 0; 
}
