#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>


struct data{
    int stok;
    char id[30], menu[30], jenis[30], harga[10], rwt[100];
}dat[100];
int jum=0, tot=0,temp, jumlah = 0, menuu = 0,tmp;
char temps[30], cri[50];

void login () {
	char ch;
	system("Color F1");
	char username[20]="admin", password[20]="123";

	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSELAMAT DATANG DI DATABASE RESTORAN\n\n");
	get_time();
	printf("\t\t\t\t\t====================================\n");
	printf("\t\t\t\t\t Masukkan Username\t: ");
	scanf("%s", &username);
	printf("\n\t\t\t\t\t Masukkan Password\t: ");
	int i=0;
	 while(1)
    {
        ch = getch();
        if(ch != '\r')
        {
            password[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        else
        {
            break;
        }
        i++;
	}
	printf("\n\t\t\t\t\t====================================\n");

	if (strcmp(username,"admin") == 0 && strcmp(password,"123") == 0) {
		printf("\n\t\t\t\t\t\t    Welcome Admin\n\n\n");
		printf("\t\t\t\t\t  Tekan apa saja untuk melanjutkan"); getch();
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t===================================================\n");
    	printf("\t\t\t\t====== Selamat Datang Admin Restoran Spaneng ======\n");
	    printf("\t\t\t\t===================================================\n\n");
	    printf("\t\t\t\t\t\tSilahkan tunggu \n");
	    Sleep(500);
	    printf("\t\t\t\t\t\t. ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
	    Sleep(500);
	    printf(". ");
		main_menu();

	}
	else {
		printf("\n\t\t\t\t\t      Username / Password Salah\n");
		getch();
		system("cls");
		login();

	}

}

void get_time()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime );
    timeinfo = localtime (&rawtime);
    printf ("\t\t\t\t\t      %s", asctime (timeinfo) );
}

void tambah(){
	int i, j = 1;
    system("cls");
    system("color 9A");
    printf("\n\n\n\t\t\t\t==================================================\n");
    printf("\t\t\t\t========== Tambah Menu Restoran Spaneng ==========\n");
    printf("\t\t\t\t==================================================\n\n");
    printf("\n\t\t\t\tMasukkan Jumlah Menu yang Ingin Dimasukkan: "); scanf("%d", &jum);
    if (jum <= 0) {
    	printf("Menu gagal ditambahkan!");
	}
	else {
		menuu++;
        for(i = tot ; i < tot+jum ; i++){
        	printf("\n");
            printf("\t\t\t\t%i. ID Menu\t: ", j); scanf(" %[^\n]", &dat[i].id);
            printf("   \t\t\t\t   Nama Menu\t: "); scanf(" %[^\n]", &dat[i].menu);
            printf("   \t\t\t\t   Harga Menu\t: "); scanf(" %[^\n]", &dat[i].harga);
            printf("   \t\t\t\t   Stok Menu\t: "); scanf("%d", &dat[i].stok);
            printf("   \t\t\t\t   Jenis Menu\t: "); scanf(" %[^\n]", &dat[i].jenis);
            j++;

        }
        jumlah++;
        printf("\n\t\t\t\tMenu Berhasil Ditambahkan");
        strcpy(dat[jumlah].rwt, "Admin Menambahkan Menu");

    }

    tot += jum;
    printf("\n\t\t\t\t==================================================");
    printf("\n\n\t\t\t\tTekan Enter Untuk Kembali");
    getch();
	main_menu();
}

void lihat(){
	int i;
    system("cls");
    system("color D2");
    jumlah++;

	if (menuu <= 0) {
		printf("\n\t\tMenu Belum ada!\n");
	}
	else {
		printf("\t\t==================================================================================\n");
		printf("\t\t========================== Daftar Menu Restoran Spaneng ==========================\n");
		printf("\t\t==================================================================================\n\n");
		printf("\t\tNo\tID Menu\t\tNama Menu\tHarga\t\tStok Menu\tJenis Menu\n\n");
	    for(i = 0 ; i < tot ; i++){
	    		printf("\t\t%i.\t%s\t\t%s\t%s\t\t%d\t\t%s\n", i+1, dat[i].id, dat[i].menu, dat[i].harga, dat[i].stok, dat[i].jenis);
	        }
	    strcpy(dat[jumlah].rwt, "Admin Melihat Menu");
	}

	printf("\n\t\t==================================================================================");
    printf("\n\n\t\tTekan Enter Untuk Kembali");
	getch();
    main_menu();
}

void urut(){
    system("cls");
    system("Color DB");
    int i,j;
    char temp2[100];
    jumlah++;

    if (menuu <= 0) {
    	printf("\n\t\tMenu Belum Ada!\n");
    }
    else {
    	printf("\t\t==================================================================================\n");
		printf("\t\t========================== Daftar Urut Restoran Spaneng ==========================\n");
		printf("\t\t==================================================================================\n\n");
		printf("\t\tNo\tID Menu\t\tNama Menu\tHarga\t\tStok Menu\tJenis Menu\n\n");
		for (i = 0 ; i < tot - 1; i++){
			for (j = 0 ; j < tot - i - 1; j++){
	      		if (dat[j].stok > dat[j+1].stok){
	      			//swap id
	        		strcpy(temps, dat[j].id);
	        		strcpy(dat[j].id, dat[j+1].id);
			        strcpy(dat[j+1].id, temps);
					//swap nama
			        strcpy(temps, dat[j].menu);
			        strcpy(dat[j].menu, dat[j+1].menu);
			        strcpy(dat[j+1].menu, temps);
					//swap harga
			        strcpy(temps, dat[j].harga);
			        strcpy(dat[j].harga, dat[j+1].harga);
			        strcpy(dat[j+1].harga, temps);
					//swap stok
			        temp = dat[j].stok;
			        dat[j].stok = dat[j+1].stok;
			        dat[j+1].stok = temp;
					//swap jenis
			        strcpy(temps, dat[j].jenis);
			        strcpy(dat[j].jenis, dat[j+1].jenis);
			        strcpy(dat[j+1].jenis, temps);
	      		}
	    	}
		}
	}

  	for(i = 0 ; i < tot ; i++){
  		printf("\t\t%i.\t%s\t\t%s\t%s\t\t%d\t\t%s\n", i+1, dat[i].id, dat[i].menu, dat[i].harga, dat[i].stok, dat[i].jenis);
		strcpy(dat[jumlah].rwt, "Admin Melihat Urutan Menu");
	}

	printf("\n\t\t==================================================================================");
    printf("\n\t\tTekan Enter Untuk Kembali");
    getch();
    main_menu();
}

void cari(){
    system("cls");
    system("Color EA");
    printf("\n\n\n\t\t\t\t=====================================================\n");
    printf("\t\t\t\t========== Pencarian Menu Restoran Spaneng ==========\n");
    printf("\t\t\t\t=====================================================\n");
    printf("\n\t\t\t\tMasukkan Nama Menu yang Ingin Dicari : "); scanf(" %[^\n]", &cri);
    bool temu = false;
    int i = 0;
    while (i <= tot && temu == false){
        if(strcmp(cri,dat[i].menu) == 0){
            temu = true;
        }
        else {
        	i++;
		}
    }
    if(temu == true ){
            printf("\n\t\t\t\tID Menu\t\t: %s\n", dat[i].id);
            printf("\t\t\t\tNama Menu\t: %s\n", dat[i].menu);
            printf("\t\t\t\tHarga Menu\t: %s\n", dat[i].harga);
            printf("\t\t\t\tStok Menu\t: %d\n", dat[i].stok);
            printf("\t\t\t\tJenis Menu\t: %s\n", dat[i].jenis);
            jumlah++;
            strcpy(dat[jumlah].rwt, "Admin Mencari Menu ");
            strcat(dat[jumlah].rwt, dat[i].menu);

    }
    else {
        printf("\n\t\t\t\tMenu Tidak Ditemukan\n");
    }

	printf("\n\t\t\t\t=====================================================");
    printf("\n\n\t\t\t\tTekan Enter Untuk Kembali\n");
    getch();
    main_menu();
}
void hapus () {
	system("cls");
	printf("\n\n\n\t\t\t\t=================================================\n");
    printf("\t\t\t\t========== Hapus Menu Restoran Spaneng ==========\n");
    printf("\t\t\t\t=================================================\n");
    printf("\n\t\t\t\tMasukkan Nama Menu yang ingin Dihapus : "); scanf(" %[^\n]", &cri);
    bool temu = false;
    int j,i = 0;
    char pilihan;
    while (i <= tot && temu == false){
        if(strcmp(cri,dat[i].menu) == 0){
            temu = true;
            tmp = i;
        }
        else {
        	i++;
        }
    }
    if(temu == true ){
        printf("\n\t\t\t\tID Menu\t\t: %s\n", dat[i].id);
        printf("\t\t\t\tNama Menu\t: %s\n", dat[i].menu);
        printf("\t\t\t\tHarga Menu\t: %s\n", dat[i].harga);
        printf("\t\t\t\tStok Menu\t: %d\n", dat[i].stok);
    	printf("\t\t\t\tJenis Menu\t: %s\n", dat[i].jenis);
        printf("\n\t\t\t\tApakah Ingin Menghapus Data ini (y/t): ");
    	scanf("%s", &pilihan);
    	if (pilihan == 'y') {
    		jumlah++;
			strcpy(dat[jumlah].rwt, "Admin Menghapus Menu ");
			//strcat(dat[jumlah].rwt, dat[i].menu);
    		for (j = tmp; j < tot; j++) {
    			strcpy(dat[j].id, dat[j+1].id);
    			strcpy(dat[j].menu, dat[j+1].menu);
    			strcpy(dat[j].harga, dat[j+1].harga);
    			dat[j].stok = dat[j+1].stok;
    			strcpy(dat[j].jenis, dat[j+1].jenis);
			}
    		printf("\t\t\t\tSuksess Hapus Menu!");
    		tot -= 1;
    	}
    	else if (pilihan == 't') {
    		printf("\t\t\t\tData Tidak Berhasil Di Hapus");
		}
    }
    else {
        printf("\n\t\t\t\tMenu Tidak Ditemukan\n");
    }
    printf("\n\t\t\t\t=================================================\n");
    printf("\n\n\t\t\t\tTekan Enter Untuk Kembali");
	getch();
    main_menu();
}

void edit () {
	system("cls");
	system("Color D9");
	printf("\n\n\n\t\t\t\t======================================================\n");
    printf("\t\t\t\t========== Pengeditan Menu Restoran Spaneng ==========\n");
    printf("\t\t\t\t======================================================\n");
    printf("\n\t\t\t\tMasukkan Nama Menu yang Ingin Diedit : "); scanf(" %[^\n]", &cri);
    bool temu = false;
    int i = 0;
    int pilihan, inputt;
    char input[100], menu2[100];
    while (i <= tot && temu == false){
        if(strcmp(cri,dat[i].menu) == 0){
            temu = true;
        }
        else {
        	i++;
		}
    }
    if(temu == true ){
    		printf("\n");
            printf("\t\t\t\t1. ID Menu\t: %s\n", dat[i].id);
            printf("\t\t\t\t2. Nama Menu\t: %s\n", dat[i].menu);
            printf("\t\t\t\t3. Harga Menu\t: %s\n", dat[i].harga);
            printf("\t\t\t\t4. Stok Menu\t: %d\n", dat[i].stok);
            printf("\t\t\t\t5. Jenis Menu\t: %s\n", dat[i].jenis);

        do {
            printf("\n\t\t\t\tIngin Mengganti Data Nomor Berapa (1/2/3/4/5) : ");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
            	printf("\n\t\t\t\tData Semula : %s", dat[i].id);
            	printf("\n\t\t\t\tData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(dat[i].id, input);
            	printf("\t\t\t\tData Berhasil diubah!");
            	jumlah++;
            	strcpy(dat[jumlah].rwt, "Admin Mengedit ID Menu ");
            	strcat(dat[jumlah].rwt, dat[i].menu);

			}
			else if (pilihan == 2) {
				printf("\n\t\t\t\tData Semula : %s", dat[i].menu);
				strcpy(menu2, dat[i].menu);
            	printf("\n\t\t\t\tData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(dat[i].menu, input);
            	printf("\t\t\t\tData Berhasil diubah!");
            	jumlah++;
            	strcpy(dat[jumlah].rwt, "Admin Mengedit Nama Menu ");
            	strcat(dat[jumlah].rwt, menu2);
            	strcat(dat[jumlah].rwt, " Menjadi ");
            	strcat(dat[jumlah].rwt, dat[i].menu);

			}
			else if (pilihan == 3) {
				printf("\n\t\t\t\tData Semula : %s", dat[i].harga);
				printf("\n\t\t\t\tData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(dat[i].harga, input);
            	printf("\t\t\t\tData Berhasil diubah!");
            	jumlah++;
            	strcpy(dat[jumlah].rwt, "Admin Mengedit Harga Menu ");
            	strcat(dat[jumlah].rwt, dat[i].menu);

			}
			else if (pilihan == 4) {
				printf("\n\t\t\t\tData Semula : %d", dat[i].stok);
            	printf("\n\t\t\t\tData diubah : ");
            	scanf("%i", &inputt);
            	dat[i].stok = inputt;
            	printf("\t\t\t\tData Berhasil diubah!");
            	jumlah++;
            	strcpy(dat[jumlah].rwt, "Admin Mengedit Stok Menu ");
            	strcat(dat[jumlah].rwt, dat[i].menu);

			}
			else if (pilihan == 5) {
				printf("\n\t\t\t\tData Semula : %s", dat[i].jenis);
				printf("\n\t\t\t\tData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(dat[i].jenis, input);
            	printf("\t\t\t\tData Berhasil diubah!");
            	jumlah++;
            	strcpy(dat[jumlah].rwt, "Admin Mengedit Jenis Menu ");
            	strcat(dat[jumlah].rwt, dat[i].menu);

			}
			else {
				printf("\t\t\t\tPilihan Tidak Tersedia!");

			}
		}while (pilihan < 1 || pilihan > 5);
    }
    else {
        printf("\n\t\t\t\tMenu Tidak Ditemukan\n");
    }

    printf("\n\t\t\t\t======================================================");
    printf("\n\n\t\t\t\tTekan Enter Untuk Kembali");
	getch();
    main_menu();

}

void history ()
{
	system("cls");
	system("Color F2");
	int i;
	printf("\n\n\n\t\t\t\t========================================================\n");
	printf("\t\t\t\t========== Riwayat Aktivitas Restoran Spaneng ==========\n");
	printf("\t\t\t\t========================================================\n");
	if (jumlah == 0) {
		printf("\n\t\t\t\tTidak Ada Riwayat Aktivitas!\n");
	}
	else {
		for (i = 1; i <= jumlah; i++) {
			printf("\t\t\t\t%i. %s\n", i, dat[i].rwt);
		}
	}
	printf("\n\t\t\t\t========================================================");
	printf("\n\n\t\t\t\tTekan Enter Untuk Kembali");
	getch();
    main_menu();

}

void exit_program()
{
	int i;
	system("cls");
    system("color 3f");
    Sleep(500);
    printf("\n\n\t\t\t\t\t\t");
    printf("K");Sleep(100);
    printf("E");Sleep(100);
    printf("L");Sleep(100);
    printf("O");Sleep(100);
    printf("M");Sleep(100);
    printf("P");Sleep(100);
    printf("O");Sleep(100);
    printf("K");Sleep(100);
    printf(" ");Sleep(100);
    printf("S");Sleep(100);
    printf("P");Sleep(100);
    printf("A");Sleep(100);
    printf("N");Sleep(100);
    printf("E");Sleep(100);
    printf("N");Sleep(100);
    printf("G \n\n");Sleep(2000);
    printf("\t\t\t\t===================================================\n");
    printf("\t\t\t\t1. MUHAMMAD YUS ADITIYA TRISNAWAN \t 672019033 \n");
    Sleep(1000);
    printf("\t\t\t\t2. DIKKY WAHYUDI \t\t\t 672019097 \n");
    Sleep(1000);
    printf("\t\t\t\t3. DANANG MAULANA IKHSAN \t\t 672019098 \n");
    Sleep(1000);
    printf("\t\t\t\t===================================================\n");
    Sleep(500);
    Sleep(500);

    Sleep(2000);

    for(i = 3; i >= 0; i--)
    {
        system("cls");
        printf("\n\n\t\t\t\t\t====================================\n");
        printf("\t\t\t\t\t====Program akan keluar dalam %d=====\n", i);
        printf("\t\t\t\t\t====================================\n");
        Sleep(1000);
    }
    printf("\t\t\t\t\t\t    Terimakasih!\n");
    Sleep(1000);
    exit(0);
}

void main_menu(){

    int i,pil;
    system("cls");
    system("Color B8");

	printf("\n\n\n\t\t\t\t===================================================\n");
	printf("\t\t\t\t=========== Menu Utama Restoran Spaneng============\n");
    //printf("\t\t=================== Menu Utama ====================\n");
    printf("\t\t\t\t===================================================\n\n");
    printf("\t\t\t\tTekan 1. Tambah Menu \n");
    printf("\t\t\t\tTekan 2. Lihat Menu\n");
    printf("\t\t\t\tTekan 3. Hapus Menu\n");
    printf("\t\t\t\tTekan 4. Edit Menu\n");
    printf("\t\t\t\tTekan 5. Pencarian Menu\n");
    printf("\t\t\t\tTekan 6. Urutkan Menu\n");
    printf("\t\t\t\tTekan 7. Riwayat Aktivitas\n");
    printf("\t\t\t\tTekan 8. Keluar dari Program\n");
    printf("\n\t\t\t\tMasukkan Pilihan Anda : "); scanf("%d", &pil);

	if (pil <= 0 || pil > 8 ) {
		printf("\n\t\t\t\tPilihan Tidak Tersedia!\n");
		printf("\t\t\t\t===================================================");
		getch();
		main_menu();
	}
	else if (pil == 1) {
		tambah();
	}
	else if (pil == 2) {
		lihat();
	}
	else if (pil == 3) {
		hapus();
	}
	else if (pil == 4) {
		edit();
	}
	else if (pil == 5) {
		cari();
	}
	else if (pil == 6) {
		urut();
	}
	else if (pil == 7) {
		history();
	}
	else if (pil == 8) {
		exit_program();
	}

}

void main () {
	login();
}
