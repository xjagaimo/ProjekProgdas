#include<iostream>
using namespace std;

class item {
	public:
	string nama;
	int harga;
};
	
int main() {
	item benda[5];
	
	for (int i=0; i<5; i++) {
	cout << "Nama: " ;
	cin >> benda[i].nama;
	cout << "Harga: ";
	cin >> benda[i].harga; 
	}
	
	for (int i=0; i<5; i++) {
	
	cout << benda[i].nama << endl;
	cout << benda[i].harga << endl; }
	
return 0; 
}
