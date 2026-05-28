#include <iostream>
using namespace std;

/*
Kelompok 3:
1) Dzaky Adiwangsa Amri
2) Fathar Zidan Fadillah
3) Fajar Fahriansyah
4) Eka Prasetya Sumardi
*/

//pake struct biar gampang diubah aja
struct User { //blueprint database usernya
    string id;
    string namaPelanggan;
    float temperature;
    float humidity;
    int airQuality;
    float noise;
    bool smoke;
    float skorMonitoring;
    User* next; //pointer ke user selanjutnya nanti
};

//inisialisasi linked list di luar, biar global
//dibikin global biar semua fungsi bisa baca
User* daftarUser = nullptr;

// cek apakah id yang dicari ada
bool cekID(string id) {
    User* current = daftarUser;
    //explore/cari id yang cocok selama blm mentok
    while (current != nullptr){
        if (current->id == id) //kondisi kalau ketemu target
            return true;
        current = current->next; //geser
    }
    //kalo ga ketemu, berarti id ga terdaftar di list
    return false;
}

/*
Kontribusi: Dzaky Adiwangsa Amri
*/
float hitungSkor(float temperature, float humidity, int airQuality, float noise, bool smoke) {
    //nilai awal
    float skor = 0.0;
    //parameter skor
    if (temperature >= 20 && temperature <= 27) skor++;
    if (humidity >= 40 && humidity <= 60) skor++;
    if (airQuality >= 0 && airQuality <= 50) skor++;
    if (smoke == 0) skor++;
    if (noise >= 30 && noise <= 55) skor++;
    //hasil skor overall/keseluruhan
    return (skor / 5.0) * 100;
}

/*
Kontribusi: Dzaky Adiwangsa Amri
*/
void tambahUser(){
    //inisialisasi tipe data di dalem fungsi, biar ga capek input parameter di int main
    string id, nama;
    float temperature, humidity, noise;
    int airQuality;
    bool smoke;

    //daftar id baru
    cout << "Masukkan User ID          : ";
    cin >> id;

    //cek id buat menghindari duplikasi data
    if(cekID(id)){
        cout << "Gagal: User ID sudah terdaftar" << endl;
        return;
    }

    cout << "Masukkan Nama             : ";
    cin.ignore();
    getline(cin, nama);

    cout << "Temperature (-10 ~ 50)    : ";
    cin >> temperature;
    //cek suhunya di luar batas atau ndak
    if (temperature < -10 || temperature > 50){
        cout << "Gagal: temperature suhu diluar batas" << endl;
        return;
    }

    cout << "Humidity (0 ~ 100)        : ";
    cin >> humidity;
    if (humidity < 0 || humidity > 100){
        cout << "Gagal: humidity diluar batas" << endl;
        return;
    }

    cout << "Air Quality (0 ~ 500)     : ";
    cin >> airQuality;
    if (airQuality < 0 || airQuality > 500){
        cout << "Gagal: air quality diluar batas" << endl;
        return;
    }

    cout << "Smoke (0/1)               : ";
    cin >> smoke;

    cout << "Noise (0 ~ 120)           : ";
    cin >> noise;
    if (noise < 0 || noise > 120){
        cout << "Gagal, noise ada di luar batas" << endl;
        return;
    }

    //dah kelar di atas, dicatet datanya ke struct User yg baru
    User* UserBaru = new User();
    UserBaru->id = id;
    UserBaru->namaPelanggan = nama;
    UserBaru->temperature = temperature;
    UserBaru->humidity = humidity;
    UserBaru->airQuality = airQuality;
    UserBaru->noise = noise;
    UserBaru->smoke = smoke;
    UserBaru->skorMonitoring = hitungSkor(temperature, humidity, airQuality, noise, smoke);
    UserBaru->next = nullptr;

    //kalo list kosong, yaudah masukin aja
    if (daftarUser == nullptr){
        daftarUser = UserBaru;
    } else{ //kalo list ada, masukin ke linked list baru
        User* current = daftarUser;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = UserBaru;
    }

    //ywdh, display/tampilin kalo pendaftaran usernya berhasil
    cout << "\n Berhasil menambahkan user baru" << endl;
    cout << "User ID                : " << UserBaru->id << endl;
    cout << "Nama Pelanggan         : " << UserBaru->namaPelanggan << endl;
    cout << "Skor Monitoring        : " << UserBaru->skorMonitoring << "%" << endl;       
}

/*
Kontribusi: Dzaky Adiwangsa Amri
*/
void cariUser(){
    string id;

    //input id user yang mau dicari
    cout << "Masukkan User ID yang ingin dicari: ";
    cin >> id;

    User* current = daftarUser;
    while (current != nullptr){
        //kalau id cocok, tampilin datanya
        if (current->id == id){
        cout << "\n User ditemukan" << endl;
        cout << "User ID                : " << current->id << endl;
        cout << "Nama Pelanggan         : " << current->namaPelanggan << endl;
        cout << "Temperature            : " << current->temperature << endl;
        cout << "Humidity               : " << current->humidity << endl;
        cout << "Air Quality            : " << current->airQuality << endl;
        cout << "Smoke                  : " << current->smoke << endl;
        cout << "Noise                  : " << current->noise << endl;
        return;
    }
    current = current->next;
}
    cout << "\n User tidak ditemukan" << endl;
}

/*
Kontribusi: Fathar Zidan Fadillah
*/
void updateUser(){
    //inisialisasi tipe data di dalem fungsi, biar ga capek input parameter di int main
    string namaBaru, id, nama;
    float temperatureBaru, humidityBaru, noiseBaru;
    int airQualityBaru;
    bool smokeBaru;

    cout<< "Masukkan id user yang mau diupdate: ";
    cin >> id;

    User* current = daftarUser;
    while (current != nullptr){
        if(current->id == id){
            cout << "Ketemu user bernama " << current->namaPelanggan << endl;

            //Input data baru

            cout << "Masukkan Nama             : ";
            cin.ignore();
            getline(cin, namaBaru);

            cout << "Temperature (-10 ~ 50)    : ";
            cin >> temperatureBaru;

            //cek suhunya di luar batas atau ndak
            if (temperatureBaru < -10 || temperatureBaru > 50){
                cout << "Gagal: temperature suhu diluar batas" << endl;
                return;
            }

            cout << "Humidity (0 ~ 100)        : ";
            cin >> humidityBaru;
            if (humidityBaru < 0 || humidityBaru > 100){
                cout << "Gagal: humidity diluar batas" << endl;
                return;
            }

            cout << "Air Quality (0 ~ 500)     : ";
            cin >> airQualityBaru;
            if (airQualityBaru < 0 || airQualityBaru > 500){
                cout << "Gagal: air quality diluar batas" << endl;
                return;
            }

            cout << "Smoke (0/1)               : ";
            cin >> smokeBaru;

            cout << "Noise (0 ~ 120)           : ";
            cin >> noiseBaru;
            if (noiseBaru < 0 || noiseBaru > 120){
                cout << "Gagal, noise  ada di luar batas" << endl;
                return;
            }

            //update datanya
            current->namaPelanggan = namaBaru;
            current->temperature = temperatureBaru;
            current->humidity = humidityBaru;
            current->airQuality = airQualityBaru;
            current->noise = noiseBaru;
            current->smoke = smokeBaru;
            current->skorMonitoring = hitungSkor(temperatureBaru, humidityBaru, airQualityBaru, noiseBaru, smokeBaru);

            //ywdh, display/tampilin kalo update usernya berhasil
            cout << "\n Berhasil update user baru" << endl;
            cout << "User ID                : " << current->id << endl;
            cout << "Nama Pelanggan         : " << current->namaPelanggan << endl;
            cout << "Skor Monitoring        : " << current->skorMonitoring << "%" << endl;

            break;
        }
        current = current->next;
    }

}

/*
Kontribusi: Fajar Fahriansyah
*/
void hapusUser(){
    string id;
    cout << "\nMasukkan User ID yang ingin dihapus : ";
    cin >> id;

    User* current = daftarUser;
    User* prev = nullptr;

    //cari user berdasarkan input id
    while (current != nullptr) {

        // kalau id ketemu
        if (current->id == id) {

            //jika node pertama
            if (prev == nullptr) {
                daftarUser = current->next;
            } 
            //jika node tengah / akhir
            else {
                prev->next = current->next;
            }

            delete current;

            cout << "\nUser berhasil dihapus!" << endl;
            return;
        }

        prev = current;
        current = current->next;
    }

    // kalau id tidak ada
    cout << "\nUser tidak ditemukan!" << endl;
}

/*
Kontribusi: Eka Prasetya Sumardi
*/
void tampilLeaderboard(){
    cout<<endl;

    //kalau database kosong lah istilahnya
    if(daftarUser == nullptr){
        cout<<"Belum ada user yang terdaftar"<<endl;
        return;
    }

    int jumlah = 0;
    User* current = daftarUser;

    //explore & hitung jumlah user yang ada di list
    while(current != nullptr){
        jumlah++;
        current = current->next;
    }

    User** arr = new User*[jumlah];

    current = daftarUser;
    for(int i = 0; i < jumlah; i++){
        arr[i] = current;
        current = current->next;
    }

    //urutin skor pakai bubble sort (tertinggi->terendah)
    for(int i = 0; i < jumlah - 1; i++){
        for(int j = 0; j < jumlah - i - 1; j++){
            if(arr[j]->skorMonitoring < arr[j + 1]->skorMonitoring){
                User* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    //tinggal cetak leaderboard
    cout<<endl;
    cout<<"Leaderboard Rumah User"<<endl;
    for(int i = 0; i < jumlah; i++){
        cout<<i + 1 << ". "<<arr[i]->namaPelanggan<<" | ID: "<<arr[i]->id<<" | Skor: "<<arr[i]->skorMonitoring<<"%"<<endl;
    }
    cout<<endl;

    delete[] arr;
}

int main() {
    /*
    Kontribusi: Fathar Zidan Fadillah
    */
    int pilihan;

    //biar ga capek modif codingan cuma buat testing
    do {
        cout << "\nProgram Monitoring" << endl;
        cout << "[1] Menambahkan User" << endl;
        cout << "[2] Mencari User" << endl;
        cout << "[3] Memperbarui Data User" << endl;
        cout << "[4] Hapus User" << endl;
        cout << "[5] Menampilkan Peringkat Rumah User" << endl;
        cout << "[0] Keluar Sistem" << endl;
        cout << "Masukkan perintah program: "; cin >> pilihan;

        switch (pilihan) {
            //eksekusi pilihan perintah programnya
            case 1:
                tambahUser();
                break;
            case 2:
                cariUser();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                hapusUser();
                break;
            case 5:
                tampilLeaderboard();
                break;
            case 0:
                cout << "\nBlasss, shutdown!" << endl;
                break;
            default:
                cout << "\nInput masukkannya tolong diperhatikan ya" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}