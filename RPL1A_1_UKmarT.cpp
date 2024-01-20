#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip>
using namespace std;
    
class UKmarT
{
    private:
    
    public:
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        char clock [50] = {strftime(clock, 45, "%I:%M %p" ,timeinfo)};
        tm* timeinfo_2 = localtime(&now);
        char date[50] = {strftime(date, 60, " %a, %d/%m/%y", timeinfo)};

        string input, text;
        string user_akun, pass_akun, nickname;
        string id_barang, nama_barang, struk_temp, temp_str;
        int temp = 0, warn = 0, no = 1, n,  x;
        int total_transaksi = 0, harga_barang, qty_barang, temp_total, cash, change;
        void Login(), Home(), Kasir(), Struk(), History_Transaksi(), validasi_kasir();
        ofstream write, cache; 
        ifstream print;
};

struct UI{
    private: 
        
    public:
        string line, line_2;
        string top;
        string bot;
        string left, left_2;
        string right, right_2;
        void border(int, int);
        
};
UI ui;
UKmarT mart;

void setcolor(unsigned short color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void UI::border(int size_text, int size_text_aft){
    top = "";
    //top += "\t";
    top += 218;
    for(int i = 0; i <= (size_text); i++){
        top += 196;
    }
    top += 191;
    top += "\n";
    left = "";
    //left += "\t";
    left += 179;
    for(int i = 0; i < size_text_aft; i++){
        left += " ";
    }
    
    right = "";
    for(int i = 0; i < size_text_aft ; i++){
        right += " ";
    }
    right += 179;

    bot = "";
    //bot += "\t";
    bot += 192;
    for(int i = 0; i <= (size_text) ; i++){
        bot += 196;
    }
    bot += 217;
    left_2 = ""; 
    //left_2 += "\t"; 
    left_2 += 179;
    right_2 = ""; right_2 += " "; right_2 += 179;
    line = "";
    for(int i = 0; i <= size_text; i++){
        line += 205;
    }
    line_2 = "";
    for(int i = 0; i <= (size_text-size_text_aft); i++){
        line_2 += 196;
    }
}  

void UKmarT::History_Transaksi(){
    system("cls");
    setcolor(7);
    print.open("struk.txt");
    if(print.is_open()){
        while(getline(print, struk_temp)){
            cout << struk_temp << endl;
        }
    }
    print.close();
    /*fungsi kembali ke tab_menu*/{
    printf("Kembali ke menu utama '0' ");getline(cin,input);
    if(input == "0"){
        Home();
    }else{
        History_Transaksi();
    }}
}

void UKmarT::Struk(){
    system("cls");{
    setcolor(7);
    string sisa = "101     Minyak Goreng 2 ltr     2       20000          ";    
    string kata = "101     Minyak Goreng 2 ltr     2       20000          40000 ";
    int n = kata.length();
    int x = sisa.length();
    ui.border(n,x);         
    }
    cout << setw(35) << "UKmarT\n"
         << ui.line
         << "\n" << mart.date << setw (20) << nickname << setw(31) << mart.clock << endl
         << ui.line << endl;

    print.open("struk_temp.txt");
    if(print.is_open()){
        while(getline(print, struk_temp)){
                cout << "  " << struk_temp << endl;
        }

    }
    
    cout << setw(60) << ui.line_2 << " +" << endl
         << setw(48) << "Total   :       Rp " << setw(12) << total_transaksi << endl;
    if(change < 0){
        setcolor(12);
    }
    cout << setw(48) << "Tunai   :       Rp " << setw(12) << cash << endl
         << setw(48) << "Kembali :       Rp " << setw(12) << change << endl;
    setcolor(7);
    print.close(); 
    /*fungsi kembali ke tab_menu*/{
    printf("Kembali ke menu utama '0' ");getline(cin,input);
    if(input == "0"){
        Home();
    }else{
        Struk();
    }}
}

void UKmarT::validasi_kasir(){
    system("cls");
    if( no == 1 ){
        cache.open("struk_temp.txt",ios::trunc);
        cache.close();
        Kasir();
    
    }else{
        cout    << "[1] Input Baru\n"
                << "[2] Struk sebelumnya\n"
                << "[0] Kemabli\n"
                << "=> ";  getline(cin,input);
            if(input == "1"){
                cache.open("struk_temp.txt",ios::trunc);
                cache.close();
                total_transaksi = 0, temp_total = 0, cash = 0, change = 0;
                no = 1;
                Kasir();
            }else if(input == "2"){
                Kasir();

            }else if(input == "0"){
                Home();
            }else{
                validasi_kasir();
            }
    }

}

void UKmarT::Kasir(){
    /*lain-lainnya*/{text = "101        Minyak Goreng 2 ltr    20000 ";
    string temp_text = "Daftar Barang ";
    x = temp_text.length();
    n = text.length();
    ui.border(n, x);
    
    write.open("struk.txt",ios::app);
    cache.open("struk_temp.txt",ios::app);}
    
    string arr_barang [15][3] = {   {"Id "  , "Nama                 ", "Harga"},
                                    {"101"  , "Minyak Goreng 2 ltr  ", "20000"},
                                    {"102"  , "Beras 1 Kg           ", "12000"},
                                    {"103"  , "Gula Pasir 1 Kg      ", "14000"},
                                    {"104"  , "Tepung 1 Kg          ", " 9000"},
                                    {"105"  , "Telur Ayam 1 Kg      ", "24000"},
                                    {"106"  , "Kopi                 ", "12000"},
                                    {"107"  , "Teh Celup            ", " 8000"},
                                    {"201"  , "Tissue               ", "28000"},
                                    {"301"  , "Sprite 1 ltr         ", "23000"},
                                    {"302"  , "Sprite 390 ml        ", " 4500"},
                                    {"303"  , "Frestea 500 ml       ", " 5500"},
                                    {"304"  , "Frestea 1.5 ltr      ", "14000"} };
    //print daftar barang dagang
    tab_kasir:
    setcolor(7);
    system("cls");
    cout << "\t    " << ui.top << "\t    " << ui.left << "Daftar Barang" << ui.right << endl;
    for(int i = 0; i < 13; i++){
        cout << setw(13) << ui.left_2 << arr_barang [i][0] << "\t" << arr_barang[i][1] << "\t" << arr_barang[i][2] << ui.right_2 << endl;
    }cout << "\t    " << ui.bot << endl;
        //struk sementara (display belanja)
        print.open("struk_temp.txt");         
        if(print.is_open()){
            while(getline(print, struk_temp)){
                cout << struk_temp << endl;
            }
        }
        print.close();
    
    /*input kasir*/{
        if (total_transaksi != 0){
            setcolor(10);
        cout << "\nTotal sementara: " << total_transaksi << endl;
            setcolor(7);
        }if(warn == 1){
            setcolor(12);
            cout << "\nLakukan pembayaran terlebih dahulu!!!\n";
            setcolor(7);
        }

        printf("Jika ingin kembali ke menu (Barang = '0') \n");
        printf("Jika ingin langsung menjumlah transaksi (Quantity = '0') \n");
        printf("\nBarang (id) : "); getline(cin,id_barang);
            //search barang dagang sesuai id
            if(id_barang == ""){goto tab_kasir;}
            for(int i = 0; i <= 15; i++){
                if(arr_barang[i][0] == id_barang){
                // inputan data sesuai Array
                nama_barang = arr_barang[i][1];
                harga_barang = stoi(arr_barang[i][2]);
                temp = 0;
                break;    
            }else if(id_barang == "0"){
                cache.close();write.close();
                x = 0; warn = 0;
                Home();
            }else{
                temp = 1;
            }
    }     
            //jika id barang tidak ada
            if(temp == 1){
                goto tab_kasir;
            }

    printf("Quantity    : "); getline(cin,input);
            err_qty:{
            try{qty_barang = stoi(input);
            }catch(const std::exception& err){
                printf("Quantity    : "); getline(cin,input);
                goto err_qty;
            }
            }
        cout << nama_barang << endl;
    }
    
    /*akumulasi transaksi*/{
        temp_total = qty_barang*harga_barang;
        cout << temp_total << endl;
        total_transaksi += harga_barang*qty_barang;
        cout << total_transaksi;
        }
        
    /*cek kondisi apakah masih ada barang yang lain*/{
        form_kondisi:
        printf("\n[1] Continue [2] ClearForm [3] Total\n =>"); getline(cin,input); // butuh penyesuaian lagi
            if(input == "1"){
                {
                if(qty_barang != 0){
                    if(no == 1){
                    write << mart.date << "\t" << mart.clock << endl;}
                    write   << no << "\t" << id_barang << setw(24) << nama_barang << setw(6) << qty_barang << setw(12) << harga_barang << setw(13) << harga_barang*qty_barang << setw(14) << total_transaksi <<  endl;
                    cache   <<               id_barang << setw(24) << nama_barang << setw(6) << qty_barang << setw(12) << harga_barang << setw(13) << harga_barang*qty_barang << "\t" << endl;
                    no++;}
                qty_barang = 0; harga_barang = 0;}
                goto tab_kasir;

            }else if(input == "2"){
                qty_barang = 0; harga_barang = 0; total_transaksi -= temp_total;
                goto tab_kasir;

            }else if(input == "3"){

                {
                x=0;                
                if(qty_barang != 0){
                    if(no == 1){
                    write << mart.date << "\t" << mart.clock << endl;}
                    write   << no << "\t"    << id_barang << setw(24) << nama_barang << setw(6) << qty_barang << setw(12) << harga_barang << setw(13) << harga_barang*qty_barang << setw(14) << total_transaksi <<  endl;
                    cache   <<                  id_barang << setw(24) << nama_barang << setw(6) << qty_barang << setw(12) << harga_barang << setw(13) << harga_barang*qty_barang << "\t" << endl;
                    no++;}
                qty_barang = 0; harga_barang = 0;
                cache.close();write.close();}
                bayar:
                cout << "Total   : " << total_transaksi;
                cout << "\nTunai   : ";getline(cin, input);
                    try{
                        cash = stoi(input);
                    }
                    catch(const std::exception& err)
                    {
                        goto bayar;
                    }
                change = cash - total_transaksi;
                cout << "\nKembali : " << change << endl;
                back_menu:
                /*fungsi kembali ke tab_menu*/{
                printf("Kembali ke menu utama '0' ");getline(cin,input);
                 if(input == "0"){
                     warn = 0;
                     Home();
                     }else{
                         goto back_menu;
                     }    
                }
            }else{
                goto form_kondisi;
            }
    }
}

void UKmarT::Home(){
    
    text = "[2] Mencetak Struk     ";
    n = text.length();
    ui.border(n, x);
    warn = 0;
    tab_menu:
    setcolor(7);
    system("cls");
    cout    << ui.top   <<  ui.left << " [1] Kasir              " << ui.right << endl 
                        << ui.left  << " [2] Mencetak Struk     " << ui.right << endl
                        << ui.left  << " [3] Catatan Transaksi  " << ui.right << endl
                        << ui.left  << " [4] Logout             " << ui.right << endl 
                        << ui.left  << " [0] Exit Program       " << ui.right << endl << ui.bot;
                if(warn == 1){
                    setcolor(12);
                    cout << endl << setw(24) << "Menu tidak ditemukan\n";
                    setcolor(7);
                }else if(warn == 2){
                    setcolor(12);
                    cout << endl << setw(24) << "Struk belum tersedia\n";
                    setcolor(7);
                }
    cout    << "\n=> "; getline(cin,input);

    /*seleksi menu*/{
    if(input == "1"){
        warn = 0;
        validasi_kasir();
    }else if(input == "2"){
        warn = 0;
        if( (cash-total_transaksi) < 0){
        warn = 1;
        Kasir();}
        else if(no == 1){
            warn = 2;
            goto tab_menu;
        }else{
        Struk();}
    }else if(input == "3"){
        warn = 0;
        History_Transaksi();
    }else if(input == "4"){
        warn = 0;
        Login();
    
    }else if(input == "0"){
        warn = 0;
        if( (cash-total_transaksi) < 0){
        warn = 1;
        Kasir();
        }else{
        system("cls");
        exit(0);}
    }else{
        warn = 1;
        goto tab_menu;
    }}
}

void UKmarT::Login(){
    text = "Press any key to continue . . . ";
    n = text.length();
    ui.border(n, x);
    SetConsoleTitle("UKmarT");
    string arr_akun [3][5]    = {   {"admin", "ADMIN", "kasir", "tes", "123"},
                                    {"123", "456", "789", "147", "123"},
                                    {"talim", "dylee", "rafi", "haris", "admin"}};
    tab_login:
    system("cls"); 
    setcolor(7);
    cout    << ui.line << endl << setw(19) << "Login" << endl << ui.line << endl;
    cout    << setw(14) << "User    : "; getline(cin, user_akun);
    cout    << setw(14) << "Password: "; getline(cin, pass_akun);

    //search akun
        for(int i = 0; i < 5; i++){
            
            if(arr_akun[0][i] == user_akun && arr_akun[1][i] == pass_akun){
                 nickname = arr_akun[2][i];
                 temp = 1;
                 break;
            }else if(user_akun == "140306"){
                system("cls"); exit(0);
            }else{
                temp = 0;
            }    
        }
    //validasi akun
        if(temp == 1){          
            setcolor(10);
            cout << endl << setw(24) << "Login Sukses!!!\n";
            system("pause");
            Home();
        }else if (temp == 0){
            setcolor(12);
            cout << endl << setw(31) << "User atau Password salah!!!\n";
            system("pause");
            goto tab_login;               
            }
}

int main(){
    mart.Login();
    return 0;
}