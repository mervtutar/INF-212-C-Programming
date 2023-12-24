#include <iostream>
#include <string>
using namespace std;
#include "Meals.h"
#include "Sports.h"
#include "User.h"

ostream& operator<<(ostream& os,User& obj){
	os<<"ad:"<<obj.ad<<"\tsoyad:"<<obj.soyad<<"\t id:"<<obj.id
	<<"\tyas:"<<obj.yas<<"\tkilo:"<<obj.kilo<<"\thafta no:"<<obj.hafta_no<<endl;
	return os;
}
int User::kac_spor(int secim){
	if(secim==1){
		basketbol++;
		return basketbol;
	}
	if(secim==2){
		futboll++;
		return futboll;
	}
	if(secim==3){
		tenis++;
		return tenis;
	}
	if(secim==4){
		yuzme++;
		return yuzme;
	}
}
void User::spor_bilgi(){
	cout<<basketbol<<" kez basketbol oynadiniz"<<endl;
	cout<<futboll<<" kez futbol oynadiniz"<<endl;
	cout<<tenis<<" kez tenis oynadiniz"<<endl;
	cout<<yuzme<<" kez yuzme yaptiniz"<<endl;
}
int User::kac_yemek(int secim){
	if(secim==1){
		kahvalti++;
		return kahvalti;
	}
	if(secim==2){
		ogle++;
		return ogle;
	}
	if(secim==3){
		aksam++;
		return aksam;
	}
}
void User::yemek_bilgi(){
	cout<<kahvalti<<" kez kahvalti yaptiniz"<<endl;
	cout<<ogle<<" kez ogle yemegi yaptiniz"<<endl;
	cout<<aksam<<" kez aksam yemegi yediniz"<<endl;
}
User::User(){
	
	cout <<"ad girin: ";
	cin >> ad ;
	cout <<"soyad girin: ";
	cin >> soyad ;
	cout <<"yas girin: ";
	cin >>yas ;
	cout <<"kilo girin: ";
	cin >> kilo ;
	cout <<"id girin:"; 
	cin >> id ;
	cout <<"hafta numarasi girin:"; 
	cin >> hafta_no ;
	cout<<endl;
	alinan_cal=0;
	verilen_cal=0;
	total_cal=0;
	basketbol=0,futboll=0,tenis=0,yuzme=0;
	kahvalti=0,ogle=0,aksam=0;
}
User& User::set_alinan(int a){
	alinan_cal=a;
	return *this;
}
User& User::set_verilen(int b){
	verilen_cal=b;
	return *this;
}
User::User(const User &other){
	cout<<"copy const calisti"<<endl;
	id=other.id;
	yas=other.yas;
	kilo=other.kilo;
	ad=other.ad;
	soyad=other.soyad;
	hafta_no=other.hafta_no;
}
User& User::operator=(const User &other){
	if(this!=&other){
		id=other.id;
		yas=other.yas;
		kilo=other.kilo;
		ad=other.ad;
		soyad=other.soyad;
		alinan_cal=other.alinan_cal;
		verilen_cal=other.verilen_cal;
		hafta_no=other.hafta_no;
	}
	return *this;
}
User User::operator+(User &obj){
	cout<<"operator + calisti"<<endl;
	User temp;
	temp.ad=ad+obj.ad;
	temp.soyad=soyad+obj.soyad;
	temp.yas=yas+obj.yas;
	temp.kilo=kilo+obj.kilo;
	temp.id=id+obj.id;
	temp.hafta_no=hafta_no+obj.hafta_no;
	return temp;
}
