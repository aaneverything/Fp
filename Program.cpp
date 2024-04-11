#include "xycolor.h"
#include "menu.cpp"
#include <queue>
#define maxproyek 150
using namespace std;

struct proyek{
	string listproyek[maxproyek];
	string statusproyek;
    queue<string> sekaligus;	
	int penanda_array = 0;
	string listproyeksementara[maxproyek];
    string objek_proyek;
    stack<string> undoStack;
}proyek;
struct proyekwip{
	string listproyek[maxproyek];
	string statusproyek;
	int penanda_array = 0;
}proyekwip;
struct proyekfinish{
	string listproyek[maxproyek];
	string statusproyek;
	int penanda_array = 0;
}proyekfinish;
//Untuk tempat menyimpan data akun username dan password
struct akun{
	string username[99];//jono
	string password[99];//123
	int npenanda = 0;
}akuninfo;

void Login(); //Menu Login
void MenuP(); //Untuk Menu Utama Pengguna
void ListProyek();
void ListProyekWIP();//untuk list proyek WIP
void ListAntrianProyekAkun();//untuk list proyek antrian User/Akun
void ListProyekFinish();//untuk list proyek finsih
void GantiPassword();

void SearchProyek();
void SortProyek();
void UndoTambahProyek();
void UndoPindahWIP();

void SearchProyekWIP();
void SortProyekWIP();
void UndoPindahFinish();
void TambahProyekSekaligus();   

void SearchProyekFinish();
void SortProyekFinish();



void MenuP()
{

    Menu menu;
	int menu_pil;
	system("cls");
    xyColor(60, 18, 0, 14);
        cout << "                                                    " ;
    xyColor(60, 26, 0, 14);
        cout << "                                                    " ;


    menu.set_xy(75, 20);
    menu.set_color(menu.YELLOW);
	menu_pil = menu.Gmenu("List Proyek", "List Proyek WIP", "List Proyek Finish", "Ganti Password Akun/User", "Logout");
	if(menu_pil == 0)
	{
	    ListProyek();
	}
	else if(menu_pil == 1)
	{
		ListProyekWIP();
	}
	else if(menu_pil == 2)
	{
		ListProyekFinish();
	}
	else if(menu_pil == 3)
	{
 		GantiPassword();
	}
	else if(menu_pil == 4)
	{
		Login();
	}
}
void Login()
{

    //header footer
	Menu menu;
	int pil;
    system("cls");
	string username, password, user_baru, pass_baru, pass_check;
    xyColor(60, 18, 0, 10);
	cout << "                                                    " << endl;

	
    xyColor(60, 24, 0, 10);
	cout << "                                                    " << endl;
    menu.set_xy(80, 20);
    menu.set_color(menu.GREEN);
	pil = menu.Gmenu("Log In", "Sign Up", "Exit");
	if(pil == 0)
	{
        system("cls");
        xyColor(60, 18, 0, 10);
        cout << "                                                    " ;
        xyColor(60, 23, 0, 10);
        cout << "                                                    " ;

        xyColor(75, 20, 10, 0);
		cout << "Masukkan Username : ";
		cin >> username;

        xyColor(75, 21, 10, 0);
		cout << "Masukkan Password : ";
		cin >> password;
		for(int i = 0; i <= akuninfo.npenanda; i++)
		{
			if(username == akuninfo.username[i] && password == akuninfo.password[i])
			{
                xyColor(75, 22, 10, 0);
				cout << "Selamat anda berhasil login!!" << endl;
				system("cls");
				MenuP();
				break;
			}
			else if(i == akuninfo.npenanda && (username != akuninfo.username[i] || password != akuninfo.password[i]))
			{
                xyColor(75, 22, 10, 0);
				cout << "Mohon masukkan username dan password yang benar" << endl;
				
				// system("cls");
				Login();
				break;
			}
		}
	}
	else if(pil == 1)
	{
        
        system("cls");
        xyColor(60, 18, 0, 10);
        cout << "                                                    " ;
        xyColor(60, 24, 0, 10);
        cout << "                                                    " ;
        xyColor(75, 20, 10, 0);
		cout << "Masukkan Username Baru : ";
		cin >> user_baru;
        xyColor(75, 21, 10, 0);
		cout << "Masukkan Password Baru : ";
		cin >> pass_baru;
       xyColor(75, 22, 10, 0);
		cout << "Masukkan Ulang Password : ";
		cin >> pass_check;
		if(pass_baru == pass_check)
		{
			if(akuninfo.username[0] == "")
			{
			akuninfo.username[0] += user_baru;
			akuninfo.password[0] += pass_baru;
			akuninfo.npenanda++;
            xyColor(18, 23, 10, 0);
			cout << "Selamat akun telah terbuat!!" << endl;
			Login(); 	
			}
			else
			{
			akuninfo.username[akuninfo.npenanda] += user_baru;
			akuninfo.password[akuninfo.npenanda] += pass_baru; 
			akuninfo.npenanda++;
            xyColor(18, 23, 10, 0);
			cout << "Selamat akun telah terbuat!!" << endl;
			Login();
			}

		}
		else
		{
            xyColor(18, 23, 10, 0);
			cout << "Mohon maaf password tidak sama";
            Login();
		}
	}
}
void data_ada()
{
    string proyeksimpan[5] = {"Pembangunan taman bermain di sebuah kota.", "Pembangunan pusat seni dan budaya komunitas.", "Pembangunan jalan raya baru untuk mengurangi kemacetan.", "Rehabilitasi dan restorasi bangunan bersejarah"};
    for(int i = 0; i < 4; i++)
    {
        proyek.listproyek[i] += proyeksimpan[i];
        proyek.penanda_array++;
        // cout << proyek.penanda_array;
    }
}

void ListProyek()
{
    Menu menu;
    int nomor = 1;
    int count = 0;
    int pil_menu_lp;
    int proyek_hapus;
    int proyek_WIP;
    int jumlah_data;
    string proyek_sementara;
    string proyek_tambah;
    int pil_menu_lanjutan;
    system("cls");

    xyColor(55, 8, 0, 13);
    cout << "                     Tampilan List Proyek yang Ada                  " ;
    xyColor(55, 30, 0, 13);
    cout << "                                                                    " ;
   
    
    for(int i = 0; i < proyek.penanda_array; i++)
    {
        xyColor(60, i+15, 13, 0); 
        cout << nomor << ". " << proyek.listproyek[i] << endl;
        nomor++;
    }
    
    xyColor(73, 10, 0, 13);
    cout << "   Pilih Menu Dibawah Ini  " << endl;
    
    menu.set_xy(77, 12);
    menu.set_color(menu.PURPLE);
    pil_menu_lanjutan = menu.Gmenu("Menu Lanjutan","Kembali Ke Menu Utama");
    if(pil_menu_lanjutan == 0)
    {
        
        system("cls");
        xyColor(55, 11, 0, 13);
        cout << "                                                                    " ;
        xyColor(55, 22, 0, 13);
        cout << "                                                                    " ;
        menu.set_xy(80, 13);
        menu.set_color(menu.PURPLE);
        pil_menu_lp = menu.Gmenu("Tambah Proyek", "Hapus Proyek", "Pindahkan ke WIP", "Search Proyek", "Sort Proyek","Undo Tambah Proyek", "Undo Pindah WIP","Kembali");
        if(pil_menu_lp == 0)
        {
            // cout << proyek.penanda_array << endl;
            // system("cls");
            // xyColor(50, 10, 0, 13);
            // cout << "                                                                    " ;
            // xyColor(50, 16, 0, 13);
            // cout << "                                                                    " ;
            // xyColor(65, 13, 13, 0);
            // cout << "Masukkan Proyek Yang Ditambahkan : ";
            // cin.ignore(); // Menghapus sisa karakter newline sebelumnya (jika ada)
            // getline(cin, proyek_tambah);

            // proyek.listproyek[proyek.penanda_array] += proyek_tambah;
            // proyek.penanda_array++;
            // ListProyek();

            TambahProyekSekaligus();            
        }
        else if(pil_menu_lp == 1)
        {
            
            system("cls");
            xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
            xyColor(55, 17, 0, 13);
            cout << "                                                                    " ;
            xyColor(65, 13, 13, 0);
            // proyek_hapus = menu.Gmenu("Pilih proyek yang akan dihapus [1.." << proyek.penanda_array << "] : ");
            cout << "Pilih proyek yang akan dihapus [1.." << proyek.penanda_array << "] : ";
            cin >> proyek_hapus;
            for(int i = 0; i < proyek.penanda_array; i++)
            {
            if(proyek_hapus-1 == i)
            {
                proyek.listproyek[i] = "";
                break;
            }
            }
            for(int i = 0; i < proyek.penanda_array; i++)
            {
                if(proyek.listproyek[i] == "")
                {
                    proyek.listproyek[i] = proyek.listproyek[i+1];
                    proyek.listproyek[i+1] = "";
                }
            }
            proyek.penanda_array--;
            ListProyek();
        }
        else if(pil_menu_lp == 2)
        {
            system("cls");
            xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
            xyColor(65, 13, 13, 0);
            cout << "Pilih proyek yang akan dipindah ke WIP [1.." << proyek.penanda_array << "] : ";
            cin >> proyek_WIP;
            for(int i = 0; i < proyek.penanda_array; i++)
            {
                if(proyek_WIP-1 == i)
                {
                    proyekwip.listproyek[proyekwip.penanda_array] = proyek.listproyek[i];
                    proyek.listproyek[i] = "";
                    break;
                }
            }
                proyekwip.penanda_array++;
                for(int i = 0; i < proyek.penanda_array; i++)
                    {
                        if(proyek.listproyek[i] == "")
                            {
                                proyek.listproyek[i] = proyek.listproyek[i+1];
                                proyek.listproyek[i+1] = "";
                            }
                    }
            proyek.penanda_array--;
            ListProyek();
        }
        else if(pil_menu_lp == 3)
        {
            SearchProyek();
        }
        else if(pil_menu_lp == 4)
        {
            SortProyek();
        }
        else if(pil_menu_lp == 5)
        {
            UndoTambahProyek();
        }
        else if(pil_menu_lp == 6)
        {
            UndoPindahWIP();
        }
        // else if(pil_menu_lp == 7)
        // {
        //     TambahProyekSekaligus();
        // }
        else if(pil_menu_lp == 7)
        {
            ListProyek();
        }
    }
    else if(pil_menu_lanjutan == 1)
    {
        MenuP();
    }

}
void SearchProyek()
{
    Menu menu;
    string keyword;
    system("cls");
    xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
    xyColor(55, 13, 13, 0);
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    system("cls");
    xyColor(55, 10, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 16, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 12, 13, 0);
    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    for (int i = 0; i < proyek.penanda_array; i++)
    {
        if (proyek.listproyek[i].find(keyword) != string::npos)
        {
            xyColor(55, 14, 13, 0);
            cout << i + 1 << ". " << proyek.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyek();
        }
    }

    if (!found)
    {
        system("cls");
        xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
        xyColor(75, 13, 13, 0);
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyek();
    }
}
void SortProyek()
{

    system("cls");
    xyColor(55, 10, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 25, 0, 13);
    cout << "                                                                    " ;
    
    for (int i = 0; i < proyek.penanda_array - 1; i++)
    {
        
        for (int j = 0; j < proyek.penanda_array - i - 1; j++)
        {
            
            if (proyek.listproyek[j] > proyek.listproyek[j + 1])
            {
                string temp = proyek.listproyek[j];
                proyek.listproyek[j] = proyek.listproyek[j + 1];
                proyek.listproyek[j + 1] = temp;
            }
        }
    }
    // getchar();
    // Menampilkan list proyek yang telah diurutkan
    xyColor(55, 12, 13, 0);
    cout << "List Proyek setelah diurutkan:" << endl;
    for (int i = 0; i < proyek.penanda_array; i++)
    {
        xyColor(55, i+14, 13, 0);
        cout << i + 1 << ". " << proyek.listproyek[i] << endl;
    }
    getchar();
    ListProyek();
}
void UndoTambahProyek()
{
    if (proyek.penanda_array > 0)
    {
        proyek.listproyek[proyek.penanda_array - 1] = "";
        proyek.penanda_array--;
        system("cls");
        xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
        xyColor(65, 13, 13, 0);
        cout << "Proyek terakhir yang ditambahkan berhasil dihapus." << endl;
    }
    else
    {
        system("cls");
        xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
        xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
        xyColor(65, 13, 13, 0);
        cout << "Tidak ada proyek yang dapat dihapus." << endl;
    }
    getchar();
    ListProyek();
}
void UndoPindahWIP()
{

    system("cls");
    xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
    xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
    xyColor(65, 13, 13, 0);
     if (proyekwip.penanda_array > 0)
    {
        int proyek_terakhir = proyekwip.penanda_array - 1;
        proyek.listproyek[proyek.penanda_array] = proyekwip.listproyek[proyek_terakhir];
        proyek.penanda_array++;
        proyekwip.listproyek[proyek_terakhir] = "";
        proyekwip.penanda_array--;

        system("cls");
        xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
         xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
        xyColor(60, 13, 13, 0);
        cout << "Proyek berhasil di-undo dan dikembalikan ke List Proyek WIP." << endl;
    }
    else
    {
         system("cls");
        xyColor(55, 10, 0, 13);
            cout << "                                                                    " ;
        xyColor(55, 16, 0, 13);
            cout << "                                                                    " ;
        xyColor(60, 13, 13, 0);
        cout << "Tidak ada proyek yang bisa di-undo pada List Proyek WIP." << endl;
    }

    getchar();
    ListProyek();
}

void TambahProyekSekaligus() {
    int jumlah_data, i=0;
    system("cls");
    xyColor(55, 10, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 25, 0, 13);
    cout << "                                                                    " ;
    xyColor(63, 12, 13, 0);
    cout << "Berapa banyak data yang ingin dimasukkan? : ";
    cin >> jumlah_data;

    cin.ignore(); // Membersihkan newline character dari buffer
    xyColor(69, 13, 13, 0);
    for (int i = 0; i < jumlah_data; i++) {
        string nama_proyek;
        xyColor(73, i+14, 13, 0);
        cout << "Masukkan nama proyek ke-" << i + 1 << ": ";
        getline(cin, nama_proyek);
        proyek.sekaligus.push(nama_proyek);
    }
    system("cls");
    
    xyColor(55, 10, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 25, 0, 13);
    cout << "                                                                    " ;
    xyColor(75, 12, 13, 0);
    cout << "Berikut List Sementara" << endl;
    int nomersementara = 1;
    queue<string> proyek_sementara = proyek.sekaligus;
//    for (int i = 0; i!=proyek_sementara.empty(); i++) 
    while(!proyek_sementara.empty()) 
    {
        xyColor(75, nomersementara+14, 13, 0);
        cout << nomersementara << ". " << proyek_sementara.front() << endl;
        proyek_sementara.pop();
        nomersementara++;
    }
    getchar();
    system("cls");
    string pilihan_yn;
    xyColor(55, 10, 0, 13);
    cout << "                                                                    " ;
    xyColor(55, 25, 0, 13);
    cout << "                                                                    " ;
    xyColor(65, 12, 13, 0);
    cout << "Apakah Yakin ingin menambahkan ke list? (y/n) : ";
    cin >> pilihan_yn;

    if (pilihan_yn == "y") 
    {
        while (!proyek.sekaligus.empty()) 
        {

            proyek.listproyek[proyek.penanda_array] = proyek.sekaligus.front();
            proyek.sekaligus.pop();
            proyek.penanda_array++;
        }
        ListProyek();
    } else if (pilihan_yn == "n") {
        ListProyek();
    }
}

void ListProyekWIP()
{
    Menu menu;
	int nomorwip = 1;
    int countwip = 0;
    int pil_menu_wip;
    int proyek_hapus_wip;
    int proyek_pindah_finish;
    int pil_menu_lanjutan;
    system("cls");
    xyColor(55, 8, 0, 12);
    cout << "                   Tampilan List Proyek WIP yang Ada                " ;
    xyColor(55, 25, 0, 12);
    cout << "                                                                    " ;
    
    for(int i = 0; i < proyekwip.penanda_array; i++)
    {
        xyColor(60, i+15, 12, 0); 
        cout << nomorwip << ". " << proyekwip.listproyek[i] << endl;
        nomorwip++;
    }
    xyColor(75, 10, 0, 12);
    cout << "pilih Menu dibawah ini";
    menu.set_xy(77, 12);
    menu.set_color(menu.RED);
    pil_menu_lanjutan = menu.Gmenu("Menu Lanjutan","Kembali Ke Menu Utama");
    if (pil_menu_lanjutan == 0)
    {
    system("cls");
    xyColor(55, 8, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 30, 0, 12);
    cout << "                                                                    " ;

    menu.set_xy(77, 12);
    menu.set_color(menu.RED);
    pil_menu_wip = menu.Gmenu("Hapus Proyek", "Pindahkan ke Finish", "Search Proyek WIP", "Sort proyek WIP", "Undo Pindah Finish", "Kembali");
    if(pil_menu_wip == 0)
    {

           system("cls");
            xyColor(55, 10, 0, 12);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 12);
            cout << "                                                                    " ;
            xyColor(65, 13, 12, 0);
    	cout << "Pilih proyek yang akan dihapus [1.." << proyekwip.penanda_array << "] : ";
        cin >> proyek_hapus_wip;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
         if(proyek_hapus_wip-1 == i)
         {
             proyekwip.listproyek[i] = "";
             break;
         }
        }
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
            if(proyekwip.listproyek[i] == "")
            {
                proyekwip.listproyek[i] = proyekwip.listproyek[i+1];
                proyekwip.listproyek[i+1] = "";
            }
        }
        proyekwip.penanda_array--;
        ListProyekWIP();
	}
	else if(pil_menu_wip == 1)
	{
           system("cls");
            xyColor(55, 10, 0, 12);
            cout << "                                                                    " ;
            xyColor(55, 16, 0, 12);
            cout << "                                                                    " ;
            xyColor(65, 13, 12, 0);
         xyColor(65, 13, 12, 0);
		cout << "Pilih proyek yang akan dipindah ke Finish [1.." << proyekwip.penanda_array << "] : ";
        cin >> proyek_pindah_finish;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
         if(proyek_pindah_finish-1 == i)
         {
         	 proyekfinish.listproyek[proyekfinish.penanda_array] = proyekwip.listproyek[i];
             proyekwip.listproyek[i] = "";
             break;
         }
        }
        proyekfinish.penanda_array++;
        for(int i = 0; i < proyekwip.penanda_array; i++)
        {
            {
                proyekwip.listproyek[i] = proyekwip.listproyek[i+1];
                proyekwip.listproyek[i+1] = "";
            }
        }
        proyekwip.penanda_array--;
        ListProyekWIP();
	}
    else if(pil_menu_wip == 2)
    {
        SearchProyekWIP();
    }
    else if(pil_menu_wip == 3)
    {
        SortProyekWIP();
    }
    else if(pil_menu_wip == 4)
    {
        UndoPindahFinish();
    }
	else if(pil_menu_wip == 5)
	{
		ListProyekWIP();
	}

    }
    else if (pil_menu_lanjutan == 1)
    {
        MenuP();
    }
}
void SearchProyekWIP()
{
    string keyword;
    system("cls");
    xyColor(55, 10, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 16, 0, 12);
    cout << "                                                                    " ;
    xyColor(70, 13, 12, 0);
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    system("cls");
    xyColor(55, 10, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 17, 0, 12);
    cout << "                                                                    " ;
    xyColor(75, 12, 12, 0);
    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    
    for (int i = 0; i < proyekwip.penanda_array; i++)
    {
        if (proyekwip.listproyek[i].find(keyword) != string::npos)
        {
            xyColor(55, 14, 12, 0);
            cout << i + 1 << ". " << proyekwip.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyekWIP();
        }
    }

    if (!found)
    {
        system("cls");
        xyColor(55, 10, 0, 12);
        cout << "                                                                    " ;
        xyColor(55, 16, 0, 12);
        cout << "                                                                    " ;
        xyColor(75, 12, 12, 0);
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyekWIP();
    }
}
void SortProyekWIP()
{
     for (int i = 0; i < proyekwip.penanda_array - 1; i++)
    {
        for (int j = 0; j < proyekwip.penanda_array - i - 1; j++)
        {
            if (proyekwip.listproyek[j] > proyekwip.listproyek[j + 1])
            {
                string temp = proyekwip.listproyek[j];
                proyekwip.listproyek[j] = proyekwip.listproyek[j + 1];
                proyekwip.listproyek[j + 1] = temp;
            }
        }
    }
   
    // Menampilkan list proyek yang telah diurutkan
    system("cls");
    xyColor(55, 10, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 25, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 12, 12, 0);
    cout << "List Proyek setelah diurutkan:" << endl;
    for (int i = 0; i < proyekwip.penanda_array; i++)
    {
        xyColor(55, i+14, 12, 0);
        cout << i + 1 << ". " << proyekwip.listproyek[i] << endl;
    }
    getchar();
    ListProyekWIP();
}


void UndoPindahFinish()
{
    system("cls");
    xyColor(55, 10, 0, 12);
    cout << "                                                                    " ;
    xyColor(55, 16, 0, 12);
    cout << "                                                                    " ;
    xyColor(65, 13, 12, 0);
    if (proyekfinish.penanda_array > 0)
    {
        int proyek_terakhir = proyekfinish.penanda_array - 1;
        proyekwip.listproyek[proyekwip.penanda_array] = proyekfinish.listproyek[proyek_terakhir];
        proyekwip.penanda_array++;
        proyekfinish.listproyek[proyek_terakhir] = "";
        proyekfinish.penanda_array--;
        system("cls");
        xyColor(55, 10, 0, 12);
        cout << "                                                                      " ;
        xyColor(55, 16, 0, 12);
    cout << "                                                                    " ;
        xyColor(60, 13, 12, 0);
        cout << "Proyek berhasil di-undo dan dikembalikan ke List Proyek WIP." << endl;
    }
    else
    {
        system("cls");
        xyColor(55, 10, 0, 12);
        cout << "                                                                    " ;
        xyColor(55, 16, 0, 12);
        cout << "                                                                    " ;
        xyColor(60, 13, 12, 0);
        cout << "Tidak ada proyek yang bisa di-undo pada List Proyek Finish." << endl;
    }

    getchar();
    ListProyekWIP();
}




//    xyColor(73, 10, 0, 12);
//     cout << "   Menu Lanjutan  " << endl;
    
   

void ListProyekFinish()
{
    Menu menu;
	int nomorfinish = 1;
    int countfinish = 0;
    int pil_menu_finish;
    int pil_menu_lfinish;
    int proyek_hapus_finish;
    string options;

    system("cls");
    xyColor(55, 8, 0, 11);
    cout << "                 Tampilan List Proyek Finish yang Ada                  " ;
    xyColor(55, 25, 0, 11);
    cout << "                                                                       " << endl;
    xyColor(75, 10, 0, 11);
    cout << "pilih Menu dibawah ini";
    

    // xyColor(55, 30, 0, 13);
    // cout << options << endl;

    for(int i = 0; i < proyekfinish.penanda_array; i++)
    {
        xyColor(55, i+15, 11, 0);
        cout << nomorfinish << ". " << proyekfinish.listproyek[i] << endl;
        nomorfinish++;
    }


    menu.set_xy(75, 12);
    menu.set_color(menu.TURQUOISE);
    pil_menu_lfinish = menu.Gmenu("Menu Lanjutan", "Kembali Ke Menu Utama");
    if(pil_menu_lfinish == 0)
    {
        system("cls");
        xyColor(55, 11, 0, 11);
        cout << "                                                  " << endl;
        xyColor(55, 22, 0, 11);
        cout << "                                                  " << endl;

        menu.set_xy(70, 14);
        menu.set_color(menu.TURQUOISE);
        pil_menu_finish = menu.Gmenu("Hapus Proyek", "Search", "Sort", "Kembali");

        if(pil_menu_finish == 0)
        {
            system("cls");
            xyColor(55, 11, 0, 11);
            cout << "                                                  " << endl;
            xyColor(55, 15, 0, 11);
            cout << "                                                  " << endl;
            xyColor(55, 13, 11, 0);
            cout << "Pilih proyek yang akan dihapus [1.." << proyekfinish.penanda_array << "] : ";
            cin >> proyek_hapus_finish;
            for(int i = 0; i < proyekfinish.penanda_array; i++)
            {
            if(proyek_hapus_finish-1 == i)
            {
                proyekfinish.listproyek[i] = "";
                break;
            }
            }
            for(int i = 0; i < proyekfinish.penanda_array; i++)
            {
                if(proyekfinish.listproyek[i] == "")
                {
                    proyekfinish.listproyek[i] = proyekfinish.listproyek[i+1];
                    proyekfinish.listproyek[i+1] = "";
                }
            }
            proyekfinish.penanda_array--;
            ListProyekFinish();
        }
        else if(pil_menu_finish == 1)
        {
            SearchProyekFinish();
        }
        else if(pil_menu_finish == 2)
        {
            SortProyekFinish();
        }
        else if(pil_menu_finish == 3)
        {
            ListProyekFinish();
        }
    }
    else if(pil_menu_lfinish == 1)
    {
        MenuP();
    }

    
}
void SearchProyekFinish()
{
    string keyword;
    system("cls");
    xyColor(55, 8, 0, 11);
    cout << "                                                  " << endl;
    xyColor(55, 16, 0, 11);
    cout << "                                                  " << endl;

    xyColor(65, 10, 11, 0);
    cout << "Masukkan kata kunci: ";
    cin.ignore();
    getline(cin, keyword);

    xyColor(67, 12, 11, 0);
    cout << "Hasil Pencarian Proyek:" << endl;
    bool found = false;
    for (int i = 0; i < proyekfinish.penanda_array; i++)
    {
        xyColor(60 , i+15, 11, 0);
        if (proyekfinish.listproyek[i].find(keyword) != string::npos)
        {
            xyColor(55 , 14, 11, 0);
            cout << i + 1 << ". " << proyekfinish.listproyek[i] << endl;
            found = true;
            getchar();
            ListProyekFinish();
        }
    }

    if (!found)
    {
        xyColor(67, 14, 11, 0);
        cout << "Proyek tidak ditemukan." << endl;
        getchar();
        ListProyekFinish();
    }
}

void SortProyekFinish()
{
    system("cls");
     for (int i = 0; i < proyekfinish.penanda_array - 1; i++)
    {
        for (int j = 0; j < proyekfinish.penanda_array - i - 1; j++)
        {
            if (proyekfinish.listproyek[j] > proyekfinish.listproyek[j + 1])
            {
                string temp = proyekfinish.listproyek[j];
                proyekfinish.listproyek[j] = proyekfinish.listproyek[j + 1];
                proyekfinish.listproyek[j + 1] = temp;
            }
        }
    }
    xyColor(55, 8, 0, 11);
    cout << "                                                                       " << endl;
    xyColor(55, 25, 0, 11);
    cout << "                                                                       " << endl;

    xyColor(55, 11, 11, 0);
    cout << "List Proyek setelah diurutkan" << endl;
    

    for (int i = 0; i < proyekfinish.penanda_array; i++)
    {   
        xyColor(55, i+15, 11, 0);
        cout << i + 1 << ". " << proyekfinish.listproyek[i] << endl;
    }
    getchar();
    getchar();
    ListProyekFinish();
}

void ListAntrianProyekAkun()
{
	int nomorantrian = 1;
    int countantrian = 0;
    int pil_menu_antrian;
    int proyek_hapus_antrian;
    system("cls");
    cout << "Tampilan List Antrian Proyek WIP yang Ada" << endl;
    cout << "=================================" << endl << endl;
    for(int i = 0; i < proyekwip.penanda_array; i++)
    {
        cout << nomorantrian << ". " << proyekwip.listproyek[i] << endl;
        nomorantrian++;
    }
    cout << "Pilih Opsi dibawah ini [1..3]" << endl;
    cout << "[1]Hapus Proyek [2]Pindahkan ke Finish [3]Kembali : ";
    cin >> pil_menu_antrian;
    if(pil_menu_antrian == 1)
    {
    	
	}
	else if(pil_menu_antrian == 2)
	{
		
	}
	else if(pil_menu_antrian == 3)
	{
		MenuP();
	}
}
void GantiPassword()

{
     system("cls");
    string password, pass_baru;

    xyColor(55, 15, 0, 8);
	cout << "                                       " << endl;


    xyColor(55, 25, 0, 8);
	cout << "                                       " << endl;

    xyColor(60, 17, 8, 0);
    cout << "Masukkan Password : "; cin >> password;
	for(int i = 0; i <= akuninfo.npenanda; i++)
	{
		if(password == akuninfo.password[i])
		{
            xyColor(60, 18, 8, 0);
            cout << "Password berhasil diverifikasi." << endl;

            xyColor(60, 19, 8, 0);
            cout << "Masukkan Password Baru :";cin>>pass_baru;
            akuninfo.password[i] = pass_baru;
            xyColor(60, 20, 8, 0);
            cout << "Password berhasil diubah." << endl;
            getchar();
            getchar();
            MenuP();
            break;
		}
        else
        {
            system("cls");
            xyColor(55, 15, 0, 8);
            cout << "                                       " << endl;


            xyColor(55, 25, 0, 8);
            cout << "                                       " << endl;
            xyColor(60, 20, 8, 0);
            cout << "Password yang anda masukkan salah." << endl;
            getchar();
            getchar();
            MenuP();
        }

    }
}

int main()
{
    data_ada();
	Login();
}