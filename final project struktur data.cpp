#include<iostream>
#include<conio.h>
#include<sstream> //mengkonversi data2 yg buka string ke string
#include<windows.h>
#include<cstdlib>

#define max 100

using namespace std;

struct cart{
	int head, tail;
	string barang[max];
	int pesanan[max];
	int jumlah[max];
	cart(){
		head = tail = 0;
	}
}keranjang;

struct tunggu{
	int head, tail;
	string tertahan[max];
	int total[max];
	string nama[max];
	string alamat[max];
	tunggu(){
		head = tail = 0;
	}
}diantar;

struct barang_barang{
	int batas;
	string nama[max];
	string keterangan[max];
	int total[max];
	barang_barang(){
		batas = 0;
	}
}log;

bool kosong();
bool penuh();
bool periksa_pengiriman();

void menu_utama(); // menu paling awal
void menu_kasir(); // menu kasir
void menu_input_pesanan(); // menu pemasukkan pesanan ke keranjang
void menu_batal_pesanan(int x); // menu pesanan yg ingin dekeluarkan dari keranjang
void menu_pengantaran_satuan(int x);
void menu_pengantaran();
void menu_log();

void menambah_cart(string x, int y, int z); //menambah isi queue
string konversi_int_ke_string(int x); //mengkonversi tipe data int ke string
void tampil_keranjang(); //menampilkan isi queue dalam struct keranjang
void pesanan_tambahan(string x,int y,int z); //menambah pesanan yang sudah tercatat sebelumnya
bool periksa_pesanan_tambahan(string x); //memeriksa apakah pesanan yg diinputkan sudah terisi apa tidak
void batal_cart(string x); // batalkan barang yang telah ada di keranjang
int jumlah_seluruh_harga();// fungsi untuk menggabungkan total pembelian
void taruh_ditampungan(); // fungsi untuk mengarahkan queue keranjang ke queue untuk menunggu pengantaran 
void batalkan_pesanan();// fungsi untuk membersihkan queue keranjang
void pesanan_ditambahkan(string x); //pesanan yang sudah ada sebelumnya ditambahkan jika yang di-request sama
void gabung_barang();
void menu_pengantaran_dibatalkan(int x);
void tampil_pengantaran();
void batalkan_pengantaran(string x);
void list_pengantaran();
void antar(string x);
void antar_semua();

string tampungan_barang;
int keseluruhan;
string alamat_pemesan;
int temp,temp_pesanan;
string pilihan;
int cadangan;
string nama_penerima;

int main(){
	menu_utama();
}

void menu_utama(){
	system("cls");
	cout << "*********************" << endl;
	cout << "1. menu kasir\n";
	cout << "2. menu pengantar\n";
	cout << "3. log penjualan\n";
	cout << "4. keluar\n";
	cout << "*********************" << endl;
	cout << "pilihan : ";
	cin >> pilihan;
	if(pilihan == "1"){
		menu_kasir();
	}
	else if(pilihan == "2"){
		if(diantar.tail == 0){
			menu_utama();
		}
		else{
		menu_pengantaran();
		}
	}
	else if(pilihan == "3"){
		if(log.batas == 0){
			menu_utama();
		}
		else{
			menu_log();
		}
	}
	else if(pilihan == "4"){
		getch();
	}
	else{
		menu_utama();
	}
}

void menu_kasir(){
	system("cls");
	cout << "*********************" << endl;
	cout << "1. input pesanan\n";
	cout << "2. batal pesanan\n";
	cout << "3. kembali ke menu utama\n";
	cout << "*********************" << endl;
	cout << "pilihan : ";
	cin >> pilihan;
	if(pilihan == "1"){
		menu_input_pesanan();
	}
	else if(pilihan == "2"){
		menu_pengantaran_dibatalkan(0);
	}
	else if(pilihan == "3"){
		menu_utama();
	}
	else{
		menu_kasir();
	}
}

void menu_input_pesanan(){
	system("cls");
	cout << "********************" << endl;
	cout << "1. telur(per-pack)\t    : 50000\n";
	cout << "2. susu(per-lusin)\t    : 15000\n";
	cout << "3. mentega(per-bungkus)\t    : 10000\n";
	cout << "4. gula(per-kg) \t    : 14000\n";
	cout << "5. kopi(per-lusin)\t    : 12000\n";
	cout << "6. teh(per-kotak)\t    : 13000\n";
	cout << "7. minyak goreng(per-liter) : 20000\n";
	cout << "8. batalkan isi keranjang\n";
	cout << "9. list keranjang\n";
	cout << "********************" << endl;
	cout << "opsi [y] untuk mengkonfirmasi, opsi [n] untuk membatalkan\n";
	cout << "pilihan : ";
	cin >> pilihan;
	if(pilihan == "1"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 50000;
		tampungan_barang = "telur";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "2"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 15000;
		tampungan_barang = "susu";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan(); 
	}
	else if(pilihan == "3"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 10000;
		tampungan_barang = "mentega";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "4"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 14000;
		tampungan_barang = "gula";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "5"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 12000;
		tampungan_barang = "kopi";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "6"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 13000;
		tampungan_barang = "teh";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "7"){
		cout << "masukkan jumlah : ";
		cin >> temp;
		keseluruhan = temp * 20000;
		tampungan_barang = "minyak goreng";
		menambah_cart(tampungan_barang, keseluruhan,temp);
		menu_input_pesanan();
	}
	else if(pilihan == "8"){
		menu_batal_pesanan(0);	
	}
	else if(pilihan == "9"){
		system("cls");
		tampil_keranjang();
		cout << "tekan y untuk selesai melihat : ";
		cin >> pilihan;
		menu_input_pesanan();
	}
	else if(pilihan == "y" or pilihan == "Y"){
		tampungan_barang = "";
		keseluruhan = jumlah_seluruh_harga();
		cout << "masukkan alamat tujuan antar : ";
		cin.ignore();
		getline(cin,alamat_pemesan);
		cout << "nama penerima : ";
		getline(cin,nama_penerima);
		gabung_barang();
		taruh_ditampungan();
		menu_kasir();
	}
	else if(pilihan == "n" or pilihan == "N"){
		batalkan_pesanan();
		menu_kasir();
	}
}

bool kosong(){
	if(keranjang.tail == 0){
		return true;
	}
	else{
		return false;
	}
}

bool penuh(){
	if(keranjang.tail == max){
		return true;
	}
	else{
		return false;
	}
}

bool periksa_pengiriman(string x){
	for(int i = diantar.head; i < diantar.tail; i++){
		if(diantar.nama[i] == x){
			return true;
		}
	}
	return false;
}

void menambah_cart(string x, int y,int z){
	if(!penuh()){
		if(periksa_pesanan_tambahan(x)){
			pesanan_tambahan(x,y,z);
			return;
		}
		keranjang.barang[keranjang.tail] = x;
		keranjang.jumlah[keranjang.tail] = y;
		keranjang.pesanan[keranjang.tail] = z;
		keranjang.tail++;
		return;
	}
	else{
		cout << "\nantrian sudah menumpuk\n";
		return;
	}
}

bool periksa_pesanan_tambahan(string x){
	for(int i = keranjang.head; i < keranjang.tail; i++){
		if(keranjang.barang[i] == x){
			return true;
		}
	}
	return false;
}

void pesanan_tambahan(string x, int y,int z){
	if(keranjang.tail == 0){
		return;
	}
	pesanan_ditambahkan(x);
	y = y + cadangan;
	z = z + temp_pesanan;
	menambah_cart(x,y,z);
	return;
}

void pesanan_ditambahkan(string x){
	int count = 0;
	for(int i = keranjang.head; i < keranjang.tail;i++){
		if(keranjang.barang[i] == x){
			for(int j = i; j < keranjang.tail; j++){
				if(count == 0){
					cadangan = keranjang.jumlah[j];
					temp_pesanan= keranjang.pesanan[j];
				}
				keranjang.barang[j] = keranjang.barang[j+1];
				keranjang.jumlah[j] = keranjang.jumlah[j+1];
			}
			keranjang.tail--;
			return;
		}
	}
	cout << "barang tak ada\n";
	return;
}

void tampil_keranjang(){
	if(!kosong()){
		for(int i = keranjang.head; i < keranjang.tail; i++){
			cout << keranjang.barang[i] << " " << keranjang.jumlah[i] << endl;
		}
	}
}

void menu_batal_pesanan(int x){
	system("cls");
	tampil_keranjang();
	cout << "masukkan yg ingin dihapus (Y untuk selesai) : ";
	if(x != 1){ //dimaksudkan karena ignore mengganggu proses pencaharian barang
		cin.ignore();
	}
	getline(cin, pilihan);
	if(pilihan == "y" or pilihan == "Y"){
		menu_input_pesanan();
	}
	batal_cart(pilihan);
	menu_batal_pesanan(1);
}

void batal_cart(string x){
	for(int i = keranjang.head; i < keranjang.tail;i++){
		if(keranjang.barang[i] == x){
			for(int j = i; j < keranjang.tail; j++){
				keranjang.barang[j] = keranjang.barang[j+1];
			}
			keranjang.tail--;
			return;
		}
	}
	cout << "barang tak ada\n";
	return;
}

string konversi_int_ke_string(int x){
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}

void gabung_barang(){
	if(kosong()){
		cout << "tak ada barang di keranjang\n";
		return;
	}
	for(int i = keranjang.head; i < keranjang.tail; i++){
		tampungan_barang += keranjang.barang[i] + " : " + konversi_int_ke_string(keranjang.pesanan[i]) + "\n";
	}
}

int jumlah_seluruh_harga(){
	int z = 0;
	for(int i = keranjang.head; i < keranjang.tail; i++){
		z += keranjang.jumlah[i];
	}
	return z;
}

void taruh_ditampungan(){
	diantar.tertahan[diantar.tail] = tampungan_barang;
	diantar.total[diantar.tail] = keseluruhan;
	diantar.alamat[diantar.tail] = alamat_pemesan;
	diantar.nama[diantar.tail] = nama_penerima;
	keranjang.tail = 0;
	diantar.tail++;
}

void batalkan_pesanan(){
	if(keranjang.head == 0){
		return;
	}
	else{
		keranjang.tail = 0;
		return;
	}
}

void tampil_pengantaran(){
	if(diantar.tail != 0){
		for(int i = diantar.head; i < diantar.tail; i++){
			cout << (i + 1) << ". " << diantar.nama[i] << endl;
		}
	}
	else{
		cout << "kosong\n";
		menu_kasir();
	}
}

void menu_pengantaran_dibatalkan(int x){
	system("cls");
	tampil_pengantaran();
	cout << "yang akan dibatalkan (y untuk menyelesaikan) : ";
	if(x == 0){
	cin.ignore();
	}
	getline(cin, pilihan);
	if(periksa_pengiriman(pilihan)){
		batalkan_pengantaran(pilihan);
		menu_pengantaran_dibatalkan(1);
	}
	else if(pilihan == "y" or pilihan == "Y"){
		menu_kasir();
	}
	menu_pengantaran_dibatalkan(1);
}

void batalkan_pengantaran(string x){
	for(int i = diantar.head; i < diantar.tail; i++){
		if(diantar.nama[i] == x){
			system("cls");
			cout << "nama penerima : " << diantar.nama[i] << endl;
			cout << "alamat : " << diantar.alamat[i] << endl;
			cout << "barang-barang yang diantar : " << endl; 
			cout << diantar.tertahan[i];
			cout << "total harga : " << diantar.total[i] << endl;
			cout << "yakin untuk menghapus [y/n] : ";
			cin >> pilihan;
			if(pilihan == "y" or pilihan == "Y"){
				for(int j = i; j < diantar.tail; j++){
					diantar.nama[j] = diantar.nama[j+1];
					diantar.tertahan[j] = diantar.tertahan[j+1];
					diantar.alamat[j] = diantar.alamat[j+1];
					diantar.total[j] = diantar.total[j+1];
				}
				diantar.tail--;
				menu_pengantaran_dibatalkan(1);
			}
			else if(pilihan == "n" or pilihan == "N"){
				menu_pengantaran_dibatalkan(1);
			}
		}
	}
}

void list_pengantaran(){
	if(diantar.tail != 0){
		for(int i = diantar.head; i < diantar.tail; i++){
			cout << (i + 1) << ". " << diantar.nama[i] << endl;
		}
	}
	else{
		menu_utama();
	}
}

void menu_pengantaran(){
	if(diantar.tail == 0){
		menu_utama();
	}
	system("cls");
	cout << "1. antar satuan\n";
	cout << "2. antar semua\n";
	cout << "3. selesai\n";
	cout << "pilihan : ";
	cin >> pilihan;
	if(pilihan == "1"){
		menu_pengantaran_satuan(0);
	}
	else if(pilihan == "2"){
		antar_semua();
	}
	else if(pilihan == "3"){
		menu_utama();
	}
	else{
		menu_pengantaran();
	}
}

void menu_pengantaran_satuan(int x){
	system("cls");
	list_pengantaran();
	cout << "masukkan pilihan antar : ";
	cin >> pilihan;
	if(x == 0){
		cin.ignore();
	}
	if(periksa_pengiriman(pilihan)){
		antar(pilihan);
	}
	else{
		menu_pengantaran_satuan(1);
	}
}

void antar(string x){
	for(int i = diantar.head; i < diantar.tail; i++){
		if(diantar.nama[i] == x){
			system("cls");
			cout << "nama penerima : " << diantar.nama[i] << endl;
			cout << "alamat : " << diantar.alamat[i] << endl;
			cout << "barang-barang yang diantar : " << endl; 
			cout << diantar.tertahan[i];
			cout << "total harga : " << diantar.total[i] << endl;
			cout << "antar [y/n] : ";
			cin >> pilihan;
			if(pilihan == "y" or pilihan == "Y"){
				for(int j = i; j < diantar.tail; j++){
					log.nama[log.batas] = diantar.nama[j];
					log.keterangan[log.batas] = diantar.tertahan[j];
					log.total[log.batas] = diantar.total[j];
					diantar.nama[j] = diantar.nama[j+1];
					diantar.tertahan[j] = diantar.tertahan[j+1];
					diantar.alamat[j] = diantar.alamat[j+1];
					diantar.total[j] = diantar.total[j+1];
				}
				diantar.tail--;
				log.batas++;
				menu_pengantaran();
			}
			else if(pilihan == "n" or pilihan == "N"){
				menu_pengantaran();
			}
		}
	}
}

void antar_semua(){
	for(int i = diantar.head; i < diantar.tail; i++){
		log.nama[log.batas] = diantar.nama[i];
		log.keterangan[log.batas] = diantar.tertahan[i];
		log.total[log.batas] = diantar.total[i];
		for(int j = diantar.head; i < diantar.tail; i++){
			diantar.nama[j] = diantar.nama[j+1];
			diantar.tertahan[j] = diantar.tertahan[j+1];
			diantar.alamat[j] = diantar.alamat[j+1];
			diantar.total[j] = diantar.total[j+1];
		}
		diantar.tail--;
		log.batas++;
	}
	menu_utama();
}

void menu_log(){
	cout << ""
}
