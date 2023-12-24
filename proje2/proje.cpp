#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
class eczn
{
	int eczn_id;
	char eczn_isim[30];
	char eczn_adres[30];
	public:
		eczn(){//Default Constructor
			eczn_id=0;
			strcpy(eczn_isim,"no name");
			strcpy(eczn_adres,"no name");
		}
		eczn(int id,char isim[30],char adres[30]){//Constructor with arg
			eczn_id=id;
			strcpy(eczn_isim,isim);
			strcpy(eczn_adres,adres);
		}
		eczn(const eczn &other){//Copy Constructor
			eczn_id=other.eczn_id;
			strcpy(eczn_isim,other.eczn_isim);
			strcpy(eczn_adres,other.eczn_adres);
		}
		eczn& operator=(const eczn &other){//Assignment operator
			eczn_id=other.eczn_id;
			strcpy(eczn_isim,other.eczn_isim);
			strcpy(eczn_adres,other.eczn_adres);
			return *this;
		}
		//get ve set fonksiyonlarý
		void set_eczn_id(int id){
			eczn_id=id;
		}
		void set_eczn_isim(char isim[30]){
			strcpy(eczn_isim,isim);
		}
		void set_eczn_adres(char adres[30]){
			strcpy(eczn_adres,adres);
		}
		
		int get_eczn_id(){
			return eczn_id;
		}
		string get_eczn_isim(){
			return eczn_isim;
		}
		string get_eczn_adres(){
			return eczn_adres;
		}
		
		void eczn_olustur();//Yöneticiye eczane bilgilerini sorarak eczn objesi oluþturmak için kullanýlacak fonksiyon.
		void eczn_goster();//Ýstenilen eczn objesinin bilgilerini ekrana yazdýrmak için oluþturulacak fonksiyon.
		void eczn_ilac_sayfasi();/*eczaneler ve ilaçlarýn tanýmlandýðý,eczaneye ait ilac listesinin oluþturulmasý için “eczaneismi_ialac.dat” isminde 
		dosya açýlýp ilaç bilgilerinin bu dosyaya yazýlmasý için kullanýlacak fonksiyon.*/
		void eczn_ekle();//dosyaya yazma
		void eczaneleri_goster();//hepsini dosyadan okuma
		eczn eczane_goster(string ad);/*dosyadan okuma Ýstenilen herhangi bir eczanenin bilgilerini ekranda göstermek için kullanýlýcak fonksiyon. 
		eczanenin eczn_isim bilgisi kullanýlarak arama yapýlýcaktýr.*/
};
class ilac
{
	int ilac_id;
	int ilac_sayisi;
	double ilac_fiyati;
	char ilac_isim[30];
	public:
		ilac(){//Default Constructor
			ilac_id=0;
			ilac_sayisi=0;
			ilac_fiyati=0.0;
			strcpy(ilac_isim,"no name");
		}
		ilac(int id,int sayi,double fiyat,char isim[30]){//Constructor with arg
			ilac_id=id;
			ilac_sayisi=sayi;
			ilac_fiyati=fiyat;
			strcpy(ilac_isim,isim);
		}
		ilac(const ilac& other){//Copy Constructor
			ilac_id=other.ilac_id;
			ilac_sayisi=other.ilac_sayisi;
			ilac_fiyati=other.ilac_fiyati;
			strcpy(ilac_isim,other.ilac_isim);
		}
		ilac& operator=(const ilac& other){//Assignment operator
			ilac_id=other.ilac_id;
			ilac_sayisi=other.ilac_sayisi;
			ilac_fiyati=other.ilac_fiyati;
			strcpy(ilac_isim,other.ilac_isim);
			return *this;
		}
		//get ve set fonksiyonlarý
		void set_ilac(int id,int sayi,double fiyat,char isim[30]){
			ilac_id=id;
			ilac_sayisi=sayi;
			ilac_fiyati=fiyat;
			strcpy(ilac_isim,isim);
		}
		int get_ilac_id(){
			return ilac_id;
		}
		int get_ilac_sayisi(){
			return ilac_sayisi;
		}
		double get_ilac_fiyati(){
			return ilac_fiyati;
		}
		string get_ilac_isim(){
			return ilac_isim;
		}
	
		void ilac_olustur();//Kullanýcýya ilac bilgilerini sorarak ilac objesi oluþturmak için kullanýlacak fonksiyon.
		void ilac_goster();//Ýstenilen ilac objesinin bilgilerini ekrana yazdýrmak için oluþturulacak fonksiyon.
		void ilac_duzenle();/*Düzenlenmek istenilen ilac objesinin ilac_isim kullanýlarak diðer bilgilerin deðiþtirilmesinde kullanýlacak fonksiyon.*/
		
		void ilac_ekle(char eczane[30]);/*dosyaya yazma-Ýstenilen eczanenin ilaç listesine yeni bir ilaç eklemek için kullanýlýcak fonksiyon.
		Eczanenin eczn_isim bilgisi kullanýlarak arama yapýlýcaktýr.*/
		void ilac_listele(char isim[30]);/*dosyadan okuma-Ýstenilen herhangi bir eczanenin ilaç listesini dosyadan okuyup ekrana yazdýrmak için kullanýlan fonksiyon.
		 Ýstenilen eczanenin eczn_isim bilgisi kullanýlarak arama yapýlýcaktýr.*/
		void ilac_ara();/*dosyadan okuma-Girilen ilac_isim bilgisinden yararlanýlarak istenilen ilacýn hangi eczanelerde oldugunu,
		 bulunan eczanenin bilgilerini ve ilaç bilgilerini ekranda göstermek için kullanýlacak fonksiyon*/
};
void ilac::ilac_goster(){
	cout<<"id: "<<this->ilac_id<<"\tisim: "<<this->ilac_isim<<"\tsayisi: "<<this->ilac_sayisi<<"\tfiyat: "<<this->ilac_fiyati<<endl;
}
void ilac::ilac_duzenle(){
	char ecz_isim[30];
	char ilac_isim[30];
	eczn e;
	cout<<"hangi eczanedeki ilacin bilgilerini degistirmek istiyorsunuz: ";
	cin>>ecz_isim;
	fstream ec_file;
    ec_file.open("eczane_listesi.dat",ios::in|ios::binary);
   
    if(!ec_file.is_open())
	{
		cout<<"dosya acilamadi!";
		exit(0);
	}
	else{
		while(ec_file.read((char*)&e, sizeof(eczn))!=NULL)
		{
			ec_file.read((char*)&e, sizeof(eczn));
			if(e.get_eczn_isim()== ecz_isim)
			{
				strcat(ecz_isim,"_ilac.dat");
				fstream ilac;
				ilac.open(ecz_isim,ios::out|ios::in|ios::app|ios::binary);
				
				cout<<"hangi ilaci degistirmek istiyorsunuz: ";
				cin>>ilac_isim;
				
				fstream copy;
				copy.open("kopya.dat",ios::out|ios::in|ios::app|ios::binary);
				
				int choice=0,id,sayi;
				double fiyat;
				while(ilac.read((char*)this, sizeof(*this))!=NULL){
					
					if(this->get_ilac_isim()==ilac_isim){
						int flag=1;
						while(flag == 1)
						{	
							cout <<endl<<"bu ilac icin"<<endl<<" 1. id degistir"<< endl<< " 2. sayisini degistir"<<endl
							<< " 3. fiyatini degistir "<<endl;
							cin >> choice;
							switch (choice)
							{
								case 1 :
									cout<<"id girin: ";
									cin>>id;
									this->ilac_id=id;
									copy.write((char*)this, sizeof(ilac));
									break;
								case 2 :
									cout<<"sayi girin: ";
									cin>>sayi;
									this->ilac_sayisi=sayi;
									copy.write((char*)this, sizeof(ilac));
									break;
								case 3 :
									cout<<"fiyat girin: ";
									cin>>fiyat;
									this->ilac_fiyati=fiyat;
									copy.write((char*)this, sizeof(ilac));
									break;
								default :
									cout<<"gecersiz giris yaptiniz"<< endl 
									<<"menuye devam etmek icin 1" <<endl;
									cin >> flag;
							}
							this->ilac_goster();
							cout<<endl;
							flag=0;
						}	
					}
					else{
						copy.write((char*)this, sizeof(ilac));
					}	
				}
				copy.close();
				ilac.close();
			}
		}
		remove(ecz_isim);//dosyayý kaldýr
		rename("kopya.dat",ecz_isim);
	}
	
}
void ilac::ilac_listele(char isim[30]){
	eczn ec;
	fstream ilac;
    strcat(isim,"_ilac.dat");
	ilac.open(isim,ios::in|ios::binary);
	if(!ilac.is_open())
	{
		cout<<"dosya acilamadi!\n";
		exit(0);
	}
	else{
		while(ilac.read((char*)this, sizeof(*this))!=NULL){
			this->ilac_goster();
		}
	}
	ilac.close();
}
void ilac::ilac_ara(){
	char isim[30];
	int i=0,count=0;
	string ecznler[50];
	string ecz_ad;
	cout<<"hangi ilaci aramak istiyorsunuz: ";
	cin>>isim;
	eczn e;
	fstream ara;
	ara.open("eczane_listesi.dat",ios::in|ios::binary);
	if(!ara.is_open())
	{
		cout<<"dosya acilamadi!\n";
		exit(0);
	}
	while(ara.read((char*)&e, sizeof(eczn))!=NULL){
	
		ecz_ad=e.get_eczn_isim();
		char *name=&ecz_ad[0];
		
		strcat(name,"_ilac.dat");
        ecznler[i]=name;
    
        i++;
        count++;
	}
	for(i=0;i<count;i++)
    {
        fstream dosya;
        dosya.open(ecznler[i].c_str(),ios::app|ios::in|ios::binary);//c_str()  string den char* yapmak için
        string eczane_ad;
        eczane_ad=ecznler[i].erase(ecznler[i].size()-9);//erase string ten karakter silmek için
        cout<<"eczane:"<<eczane_ad<<endl;
        if(!dosya.is_open())
		{
			cout<<"dosya acilamadi!\n";
			exit(0);
		}
		else{
			while(dosya.read((char*)this, sizeof(ilac))!=NULL){
				if ( this->get_ilac_isim() == isim)
				{
					this->ilac_goster();
					cout<<endl;
					dosya.close();
				}
			}
		}   
    }
}
void ilac::ilac_ekle(char eczane[30]){
	strcat(eczane,"_ilac.dat");
	fstream ecz;
	ecz.open(eczane,ios::app|ios::out|ios::binary);
	ecz.write((char*)this,sizeof(*this));
	
	ecz.close();
	this->ilac_goster();
	cout<<"ilac eklendi.."<<endl;
	ecz.close();
}
void ilac::ilac_olustur(){
	ilac i1;
	int id,sayi;
	double fiyat;
	char isim[30];
	char eczn[30];
	cout<<"ilac eklemek istediginiz eczane adini girin: ";
	cin>>eczn;
	cout<<"eklemek istediginiz ilac icin"<<endl<<"ilac id girin: ";
	cin>>id;
	cout<<"ilac adi girin: ";
	cin>>isim;
	cout<<"ilac sayisi girin: ";
	cin>>sayi;
	cout<<"ilac fiyati girin: ";
	cin>>fiyat;
	i1.set_ilac(id,sayi,fiyat,isim);
	i1.get_ilac_id();
	i1.get_ilac_isim();
	i1.get_ilac_sayisi();
	i1.get_ilac_fiyati();
	i1.ilac_ekle(eczn);
}
//eczaneler ve ilaçlarýn tanýmlandýðý fonksiyon
void eczn::eczn_ilac_sayfasi(){
	eczn e1(1,"zeynep","emek mah");
	eczn e2(2,"suna","yenimahalle");
	eczn e3(3,"esra","cemalcaymaz mah");
	
	e1.eczn_ekle();
	e2.eczn_ekle();
	e3.eczn_ekle();
	
	fstream filac;
	filac.open("zeynep_ilac.dat",ios::app|ios::out|ios::binary);
	ilac i1(1,5,7.5,"calpol");
	ilac i2(2,5,12.5,"majezik");
	ilac i3(3,5,8.0,"minoset");
	ilac i4(4,5,2.5,"aferin");
	ilac i5(5,5,15.5,"arveles");
	ilac i6(6,5,3.8,"aspirin");
	filac.write((char*)&i1,sizeof(i1));
	filac.write((char*)&i2,sizeof(i2));
	filac.write((char*)&i3,sizeof(i3));
	filac.write((char*)&i4,sizeof(i4));
	filac.write((char*)&i5,sizeof(i5));
	filac.write((char*)&i6,sizeof(i6));
	filac.close();
	
	fstream il;
	il.open("suna_ilac.dat",ios::app|ios::out|ios::binary);
	ilac a1(1,6,7.0,"calpol");
	ilac a2(2,6,11.5,"majezik");
	ilac a3(3,6,9.0,"minoset");
	ilac a4(4,6,6.5,"aferin");
	ilac a5(5,6,12.5,"arveles");
	ilac a6(6,6,3.5,"aspirin");
	il.write((char*)&a1,sizeof(a1));
	il.write((char*)&a2,sizeof(a2));
	il.write((char*)&a3,sizeof(a3));
	il.write((char*)&a4,sizeof(a4));
	il.write((char*)&a5,sizeof(a5));
	il.write((char*)&a6,sizeof(a6));
	il.close();
	
	fstream ff;
	ff.open("esra_ilac.dat",ios::app|ios::out|ios::binary);
	ilac b1(1,7,8.5,"calpol");
	ilac b2(2,7,14.0,"majezik");
	ilac b3(3,7,8.5,"minoset");
	ilac b4(4,7,4.5,"aferin");
	ilac b5(5,7,16.6,"arveles");
	ilac b6(6,7,5.4,"aspirin");
	ff.write((char*)&b1,sizeof(b1));
	ff.write((char*)&b2,sizeof(b2));
	ff.write((char*)&b3,sizeof(b3));
	ff.write((char*)&b4,sizeof(b4));
	ff.write((char*)&b5,sizeof(b5));
	ff.write((char*)&b6,sizeof(b6));
	ff.close();

}
void eczn::eczn_olustur(){
	
	eczn z1;
	int idd;
	char isimm[30];
	char adress[30];
	
	cout<<"eczane id girin: ";
	cin>>idd;
	cout<<"eczane ismi girin: ";
	cin>>isimm;
	cout<<"eczane adresi girin: ";
	scanf(" %[^\n]",adress);
	
	
	z1.set_eczn_id(idd);
	z1.get_eczn_id();
	z1.set_eczn_isim(isimm);
	z1.get_eczn_isim();
	z1.set_eczn_adres(adress);
	z1.get_eczn_adres();
	z1.eczn_ekle();
	cout<<"eczane olusturuldu"<<endl;
	
}
void eczn::eczn_goster(){
	cout<<"id: "<<this->eczn_id<<endl<<"isim: "<<this->eczn_isim<<endl<<"adres: "<<this->eczn_adres<<endl<<endl;
}
void eczn::eczn_ekle(){
	
	fstream file;
	file.open("eczane_listesi.dat",ios::app|ios::out|ios::binary);
	file.write((char*)this,sizeof(*this));
	
	file.close();
	this->eczn_goster();
}

void eczn::eczaneleri_goster(){
	
	fstream file;
	
	file.open("eczane_listesi.dat",ios::in|ios::binary);
	file.seekg(0,ios_base::beg);
	if(!file.is_open())
	{
		cout<<"dosya acilamadi!\n";
		exit(0);
	}
	
	while(file.read((char*)this, sizeof(*this))!=NULL){
		
		this->eczn_goster();
	}
	file.close();
}
eczn eczn::eczane_goster(string ad){
	fstream file;
	file.open("eczane_listesi.dat",ios::in|ios::binary);
	file.clear();
	file.seekg(0,ios_base::beg);
	file.seekp(0,ios_base::beg);
	if(!file.is_open())
	{
		cout<<"dosya acilamadi!\n";
		exit(0);
	}
	else{
		while(!file.eof()){
			file.read((char*)this, sizeof(*this));
				if (  this->get_eczn_isim() == ad)
				{
					return *this;
				}
		}
	}
}
int main()
{
	
	string ad;
	eczn e;
	char isim[30];
	ilac i;
	int choice,password,flag = 0;
	int Key=1234;
	while( flag== 0)
	{
		system("cls");
		cout <<"Hosgeldiniz lutfen secim yapin"<<endl<< "1.Eczane girisi "<<endl<<"2.Musteri girisi "<< endl <<"10.Cikis icin "<< endl;
		cin >> choice;
		if ( choice == 1){
			cout<<"devam etmek icin sifreyi giriniz:";
			cin>>password;//Kullanicinin yetkili olup olmadigini anlamak amacýyla istenen þifre
			
			while(password!=Key){
			cout<<"Yanlis sifre girildi lutfen yeniden deneyin \n";
			cin>>password;//anahtar dogru girilene kadar kullanicinin anahtari tekrar girmesi istenir
			}
			if(password==Key){
				system("cls");
				cout<<"Eczane girisine hosgeldiniz\n";
				flag = 1;
				while(flag == 1)
				{	
					cout << endl<< "Eczane Girisi" <<endl<<" 1. Eczane Listesi Olustur"<< endl<< " 2. Eczane Ekle"<<endl
					<< " 3. Ilac Ekle "<<endl<< " 4. Ilac Duzenle "<<endl<<" 5. Ust menu"<<endl;
					cin >> choice;
					switch (choice)
					{
						case 1 :
							system("cls");
							e.eczn_ilac_sayfasi();//eczane listesi olusturmak
							cout<<"tanimli eczaneler ve ilaclar olusturuldu"<<endl;
							break;
						case 2 :
							system("cls");
							e.eczn_olustur();//Eczane ekleme 
							break;
						case 3 :
							system("cls");
							i.ilac_olustur();// ilac ekleme
							break;
						case 4 :
							system("cls");
							i.ilac_duzenle();//ilac duzenle 
							break;
						case 5 :
							flag=0;
							break;
						default :
							cout<<"gecersiz giris yaptiniz"<< endl 
							<<"menuye devam etmek icin 1" << endl<<"ust menuye donmek icin 0 girin"<<endl;
							cin >> flag;
					}
				}
			}
		} 
		else if ( choice == 2)
		{	
			flag = 1 ;
			while(flag == 1)
			{
				
				
				cout << endl << "Musteri Girisi "<< endl <<" 1. Ilac Ara"<< endl<< " 2. Eczane Listele"<<endl
				<< " 3. Herhangi bir Eczaneyi Goster "<<endl<< " 4. Herhangi bir Eczaneye ait Ilac Listesi "<< endl <<" 5. Ust menu"<<endl;
				cin >> choice;
				switch (choice)
				{
					case 1 :
						system("cls");
						i.ilac_ara();//ilaç ara
						break;
					case 2 :
						system("cls");
						e.eczaneleri_goster();//Eczane Listele
						break;
					case 3 :
						system("cls");
						cout<<"eczane ismi girin: ";// Herhangi bir Eczaneyi Goster
						cin>>ad;
						e=e.eczane_goster(ad);
						e.eczn_goster();
						break;
					case 4 :
						system("cls");
						cout<<"eczane ismi girin: ";
						cin>>isim;
						i.ilac_listele(isim);// Herhangi bir Eczaneye ait Ilac Listesi
						break;
					case 5 :
						flag=0;
						break;
					default :
						cout<<"gecersiz giris yaptiniz"<< endl 
						<<"menuye devam etmek icin 1"<<endl<<"ust menuye donmek icin 0 girin"<<endl;
						cin >> flag;
				}
			}
		}
		else if ( choice == 10)
		{
			flag = 1;
			cout<<"cikis yapildi";
		}
	}
	return 0 ;
}
