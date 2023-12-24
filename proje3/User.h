#ifndef user_h_
#define user_h_
#include <iostream>
#include <string>
#include "Meals.h"
#include "Sports.h"
using namespace std;

class User{
	friend ostream& operator<<(ostream& os,User& obj);
	public:
		User();
		User(const User &other);
		User& operator=(const User &other);
		User operator+(User &obj);
		int get_alinan(){ return alinan_cal;}
		int get_verilen(){ return verilen_cal;}
		int get_total(){ return (alinan_cal-verilen_cal);}
		User& set_alinan(int a);
		User& set_verilen(int b);
		int kac_spor(int secim);
		void spor_bilgi();
		int kac_yemek(int secim);
		void yemek_bilgi();
		Breakfast b;
		Lunch l;
		Dinner d;
		
		Basketball basket;
		Football futbol;
		Tennis t;
		Swimming s;
		int kahvalti,ogle,aksam;//hangi öðünden ne kadar yediðini tutmak için oluþturulan deðiþkenler, mainde 7 ile sýnýrlandýrýldý
	private:
		int id;
		int yas;
		int kilo;
		string ad;
		string soyad;
		int alinan_cal;
		int verilen_cal;
		int total_cal;
		int hafta_no;
		int basketbol,futboll,tenis,yuzme;//hangi sporu kaç kere yaptýðýný bulmak için oluþturulan deðiþkenler
		
};
#endif






