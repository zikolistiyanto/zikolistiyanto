#include <iostream>
#include <string>
using namespace std;

struct Jurusan
{
    string kode_jurusan;
    string nama_jurusan;
};

struct Mahasiswa
{
    string nama;
    string nim;
    Jurusan rec_jurusan;
};

const int array_size =10;

int array_counter = 0;

typedef Mahasiswa array_mahasiswa[array_size];

array_mahasiswa students;

void create_student(array_mahasiswa& data, int& array_length){
	string nim_baru;
	
	cout<<" --- entry mahasiswa baru --- " << endl;
	ulang:
	cout<< "masukan nim : ";cin>> nim_baru;
	for(int i=0; i< array_length -1;i++){
		if(nim_baru == data[i].nim){
			cout<<"--- nim sudah terdaftar! ----"<<endl;
			cout<<"--- ulangi! ----"<<endl;
			goto ulang;
		}
	}
	data[array_length].nim = nim_baru;
	cout<<"masukan nama : ";cin>>data[array_length].nama;
	cout<<"masukan kode jurusan : ";cin>>data[array_length].rec_jurusan.kode_jurusan;
	cout<<"masukan nama jurusan : ";cin>>data[array_length].rec_jurusan.nama_jurusan;
	array_length = array_length +1;
	cout<<"---- berhasil menambahkan data ! ------"<<endl;
}
	
void read_mahasiswa(array_mahasiswa data, int array_length){
	cout<<"------ cetak mahasiswa ------- "<<endl;
	for(int i=0;i<array_length; i++){
		cout<<"nama mahasiswa : "<<data[i].nama<<endl;
		cout<<"nim mahasiswa : "<<data[i].nim<<endl;
		cout<<"kode jurusan : "<<data[i].rec_jurusan.kode_jurusan<<endl;
		cout<<"nama mahasiswa : "<<data[i].rec_jurusan.nama_jurusan<<endl;
		cout<<"----------------------------"<<endl;
	}
}

void update_student(array_mahasiswa &data, int array_length){
	bool isExists = false;
	int record_position = 0;
	string param_nim;
	
	cout<<"--------------- update mahasiswa -------"<<endl;
	cout<<"masukan nim :";cin>>param_nim;
	
	for(int i=0; i<array_length; i++){
		if(data[i].nim == param_nim){
			isExists = true;
			record_position = i;
		}
	}
	
	if(isExists == false){
		cout<<"----- mahasiswa tidak ditemukan! -----"<<endl;
		return;
	}
	cout<<"update mahasiswa dengan nim : "<<data[record_position].nim<<endl;
	cout<<"masukan nama : ";cin>>data[record_position].nama;
	cout<<"masukan kode jurusan : ";cin>>data[record_position].rec_jurusan.kode_jurusan;
	cout<<"masukan nama jurusan : ";cin>>data[record_position].rec_jurusan.nama_jurusan;
	cout<<"----- berhasil mengupdate data! ----- "<<endl;
}

void delete_student(array_mahasiswa& data, int& array_length){
	bool isExists = false;
	int record_position = 0;
	string param_nim;
	
	cout<<"------ delete mahasiswa ----- "<<endl;
	cout<<"masukan nim : ";cin>>param_nim;
	
	for(int i=0; i<array_length; i++){
		if(data[i].nim==param_nim){
			isExists = true;
			record_position=i;
		}
	}
	
	if(isExists == false){
		cout<<"---- mahasiswa tidak ditemukan! -----"<<endl;
		return;
	}
	cout<<"menghapus mahasiswa dengan nim : "<<data[record_position].nim<<endl;
	for(int i= record_position; i< array_length;i++){
		data[i]=data[i+1];
	}
	array_length = array_length -1;
	cout<<"------berhasil menghapus data "<<endl;
}

void search_mahasiswa_sequential(array_mahasiswa data, int array_length){
	string nim_cari;
	cout<<"masukan NIM yang akan dicari : ";cin>>nim_cari;
	bool found = false;
	for (int i = 0; i<array_length; i++){
		if(data[i].nim == nim_cari){
			cout<<"Data ditemukan pada record ke - "<<i<<endl;
			cout<<"NIM : "<<data[i].nim<<endl;
			cout<<"Nama : "<<data[i].nama<<endl;
			cout<<"kode jurusan : "<<data[i].rec_jurusan.kode_jurusan<<endl;
			cout<<"nama mahasiswa : "<<data[i].rec_jurusan.nama_jurusan<<endl;
			found = true;
			break;
		}
	}
	if(!found){
		cout<<"data tidak ditemukan" <<endl;
	}
}

void search_mahasiswa_binary(array_mahasiswa data, int array_length){
	string nim_cari;
	cout<<"masukan NIM yang akan dicari : ";cin>>nim_cari;
	//binary search
	int low = 0, high = array_length -1;
	while (low <= high){
		int mid = low +(high - low)/2;
		if(data[mid].nim == nim_cari){
			cout<<"data ditemukan pada record ke- "<<mid<<endl;
			cout<<"NIM : "<<data[mid].nim<<endl;
			cout<<"Nama : "<<data[mid].nama<<endl;
			cout<<"kode jurusan : "<<data[mid].rec_jurusan.kode_jurusan<<endl;
			cout<<"nama mahasiswa : "<<data[mid].rec_jurusan.nama_jurusan<<endl;
			return;
		}
		else if(data[mid].nim<nim_cari){
			low = mid + 1;
		}
		else{
			high = mid -1;
		}
	}
	cout<<"data tidak ditemukan"<<endl;
}
	
void filter_nim_lebih_dari_dua_digit(array_mahasiswa data, int array_length){
	cout<<"------ Filter NIM lebih dari dua digit -----"<<endl;
	for(int i = 0;i<array_length;i++){
		if(data[i].nim.size()>2){
			cout<<"NIM : "<<data[i].nim<<endl;
			cout<<"Nama : "<<data[i].nama<<endl;
			cout<<"kode jurusan : "<<data[i].rec_jurusan.kode_jurusan<<endl;
			cout<<"nama mahasiswa : "<<data[i].rec_jurusan.nama_jurusan<<endl;
			cout<<"------------------"<<endl;
		}
	}
}

int main(){
	int pilih = 0;
	
	do{
		system("cls");
		cout<<"menu : "<<endl;
		cout<<"1. Tambah Data Mahasiswa"<<endl;
		cout<<"2. Cetak Data Mahasiswa"<<endl;
		cout<<"3. Delete Data Mahasiswa"<<endl;
		cout<<"4. Update Data Mahasiswa"<<endl;
		cout<<"5. Cari data Mahasiswa (sequential)"<<endl;
		cout<<"6. Cari data Mahasiswa (Binary)"<<endl;
		cout<<"7. Filter NIM lebih dari dua digit"<<endl;
		cout<<"0. selesai"<<endl;
		cout<<"pilih menu : ";cin>>pilih;
		
		switch(pilih){
			case 1: create_student(students,array_counter);
			case 2: if(array_counter==0) cout<<"Data kosong"<<endl;else read_mahasiswa(students, array_counter);break;
			case 3: if(array_counter==0) cout<<"Data kosong"<<endl;else delete_student(students, array_counter);break;
			case 4: if(array_counter==0) cout<<"Data kosong"<<endl;else update_student(students, array_counter);break;
			case 5: if(array_counter==0) cout<<"Data kosong"<<endl;else search_mahasiswa_sequential(students, array_counter);break;
			case 6: if(array_counter==0) cout<<"Data kosong"<<endl;else search_mahasiswa_binary(students, array_counter);break;					
			case 7: if(array_counter==0) cout<<"Data kosong"<<endl;else filter_nim_lebih_dari_dua_digit(students, array_counter);break;
			case 0: cout<<"Terimakasih "<<endl;break;
			default : cout<<"salah pilih menu"<<endl;
		}
		system("pause");
	}while (pilih !=0);
}
