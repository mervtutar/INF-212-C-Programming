#include <iostream>
#include <string>
#include "Meals.h"
#include "Sports.h"
#include "User.h"
using namespace std;

int main(){

	int choice,flag = 0;
	while( flag== 0)
	{
		system("cls");
		cout <<"Hosgeldiniz lutfen secim yapin"<<endl<< "1.Developer mode "<<endl<<"2.User mode "<< endl <<"10.Cikis icin "<< endl;
		cin >> choice;
		if ( choice == 1){
			User b;
				cout<<"Developer mode"<<endl;
				flag = 1;
				while(flag == 1)
				{	
					cout<<"seciniz\n"<<" 1. User class testi icin"<< endl<< " 2. Meals.h classlari testi icin"<<endl
					<< " 3. Sports.h classlari testi icin "<<endl<<" 4. Ust menu icin"<<endl;
					cin >> choice;
					if(choice==1)
					{
						cout<<"operator << testi"<<endl;
						cout<<b<<endl;
						cout<<"copy const test ediliyor"<<endl;
						User d=b;
						cout<<d<<endl;
						cout<<"assignment op test ediliyor"<<endl;
						d=b;
						cout<<d<<endl;
						cout<<"operator + test ediliyor"<<endl;
						d=d+b;
						cout<<d<<endl;
						cout<<"set get fonksiyonlari test ediliyor"<<endl;
						b.set_alinan(5);b.set_verilen(4);
						cout<<"alinan:"<<b.get_alinan()<<" verilen:"<<b.get_verilen()<<" total:"<<b.get_total()<<endl<<endl;
						cout<<"int kac_spor(int secim); ve void spor_bilgi(); test ediliyor"<<endl;
						b.kac_spor(1);b.spor_bilgi();
						cout<<endl;
						cout<<"int kac_yemek(int secim); ve void yemek_bilgi(); test ediliyor"<<endl;
						b.kac_yemek(1);b.yemek_bilgi();
						cout<<endl;
					}
					else if(choice==2){
						Breakfast b1;Breakfast b2;
						Lunch l1;Lunch l2;
						Dinner d1;Dinner d2;
						
						cout<<"Breakfast class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Breakfast b3;
						b3=b1+b2;
						cout<<b3;
						cout<<"assignment op test ediliyor"<<endl;
						b1=b3;cout<<b1;
						cout<<"copy const test ediliyor"<<endl;
						Breakfast b4=b3;cout<<b4;
						cout<<"int sec(); test ediliyor"<<endl;
						b1.sec();
						
						
						cout<<endl<<"Lunch class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Lunch l3;
						l3=l1+l2;cout<<l3;
						cout<<"assignment op test ediliyor"<<endl;
						l1=l3;cout<<l1;
						cout<<"copy const test ediliyor"<<endl;
						Lunch l4=l3;cout<<l4;
						cout<<"int sec(); test ediliyor"<<endl;
						l1.sec();
						
						
						cout<<endl<<"Dinner class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Dinner d3;
						d3=d1+d2;cout<<d3;
						cout<<"assignment op test ediliyor"<<endl;
						d1=d3;cout<<d1;
						cout<<"copy const test ediliyor"<<endl;
						Dinner d4=d3;cout<<d4;
						cout<<"int sec(); test ediliyor"<<endl;
						d1.sec();
					
					}
					else if(choice==3){
						Basketball bas1;
						Basketball bas2;
						cout<<endl<<"Basketball class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Basketball bas3;
						bas3=bas1+bas2;cout<<bas3;
						cout<<"assignment op test ediliyor"<<endl;
						bas1=bas3;cout<<bas1;
						cout<<"copy const test ediliyor"<<endl;
						Basketball bas4=bas3;cout<<bas4;
						cout<<"int kalori(); test ediliyor"<<endl;
						bas1.kalori();
						
						Football f1;
						Football f2;
						cout<<endl<<"Football class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Football f3;
						f3=f1+f2;cout<<f3;
						cout<<"assignment op test ediliyor"<<endl;
						f1=f3;cout<<f1;
						cout<<"copy const test ediliyor"<<endl;
						Football f4=f3;cout<<f4;
						cout<<"int kalori(); test ediliyor"<<endl;
						f1.kalori();
						
						
						Tennis t1;
						Tennis t2;
						cout<<endl<<"Tennis class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Tennis t3;
						t3=t1+t2;cout<<t3;
						cout<<"assignment op test ediliyor"<<endl;
						t1=t3;cout<<t1;
						cout<<"copy const test ediliyor"<<endl;
						Tennis t4=t3;cout<<t4;
						cout<<"int kalori(); test ediliyor"<<endl;
						t1.kalori();
						
						
						Swimming s1;
						Swimming s2;
						cout<<endl<<"Swimming class test ediliyor"<<endl;
						cout<<"operator + ve << test ediliyor"<<endl;
						Swimming s3;
						s3=s1+s2;cout<<s3;
						cout<<"assignment op test ediliyor"<<endl;
						s1=s3;cout<<s1;
						cout<<"copy const test ediliyor"<<endl;
						Swimming s4=s3;cout<<s4;
						cout<<"int kalori(); test ediliyor"<<endl;
						s1.kalori();
					}
					else if(choice==4){
						flag=0;
						break;
					}
					else{
						cout<<"gecersiz giris yaptiniz"<< endl 
						<<"menuye devam etmek icin 1" << endl<<"ust menuye donmek icin 0 girin"<<endl;
						cin >> flag;
					}
							
					
				}
		} 
		else if ( choice == 2)
		{	
			User a;
			int x=0;
			int y=0,counter=0;
			flag = 1 ;
			while(flag == 1)
			{	
				
				cout <<"secim yapin"<<endl <<" 1. Spor girisi"<< endl<< " 2. Ogun girisi"<<endl<<" 3. Spor ve Ogun bilgileri"<<endl<<" 4. Ust menu"<<endl;
				cin >> choice;
				switch (choice)
				{
					case 1 :
						cout <<"seciniz"<< endl <<" 1. Basketbol"<< endl<< " 2. Futbol"<<endl<<" 3. Tenis"<<endl<<" 4. Yuzme"<<endl<<" 5. Ust menu"<<endl;
						cin >> choice;
						a.kac_spor(choice);
						switch (choice)
						{
							case 1 :
								x+=a.basket.kalori();
								a.set_verilen(x);
								break;
							case 2 :
								x+=a.futbol.kalori();
								a.set_verilen(x);
								break;
							case 3 :
								x+=a.t.kalori();
								a.set_verilen(x);
								break;
							case 4 :
								x+=a.s.kalori();
								a.set_verilen(x);
								break;
							case 5 :
								flag=0;
								break;
							default :
								cout<<"gecersiz giris yaptiniz"<< endl 
								<<"menuye devam etmek icin 1"<<endl<<"ust menuye donmek icin 0 girin"<<endl;
								cin >> flag;
						}
						break;
					case 2 :
						cout <<"seciniz"<< endl <<" 1. Kahvalti"<< endl<< " 2. Ogle yemegi "<<endl<<" 3. Aksam yemegi"<<endl<<" 4. Ust menu"<<endl;
						cin >> choice;
						a.kac_yemek(choice);
						switch (choice)
						{
							case 1 :
								if(a.kahvalti<8){
									y+=a.b.sec();
									a.set_alinan(y);
								}
								else{
									cout<<"bu hafta 7 kere kahvalti yaptiniz baska bir ogun secin!"<<endl;
								}
								break;
							case 2 :
								if(a.ogle<8){
									y+=a.l.sec();
									a.set_alinan(y);
								}
								else{
									cout<<"bu hafta 7 kere ogle yemegi yediniz baska bir ogun secin!"<<endl;
								}
								break;
							case 3 :
								if(a.aksam<8){
									y+=a.d.sec();
									a.set_alinan(y);
								}
								else{
									cout<<"bu hafta 7 kere aksam yemegi yediniz baska bir ogun secin!"<<endl;
								}
								break;
							case 4 :
								flag=0;
								break;
							default :
								cout<<"gecersiz giris yaptiniz"<< endl 
								<<"menuye devam etmek icin 1"<<endl<<"ust menuye donmek icin 0 girin"<<endl;
								cin >> flag;
						}
						break;
					case 3 :
						cout<<a<<endl;
						a.spor_bilgi();
						cout<<"harcanan toplam kalori:"<<a.get_verilen()<<endl<<endl;
						a.yemek_bilgi();
						cout<<"alinan toplam kalori:"<<a.get_alinan()<<endl<<endl;
						cout<<"total kalori:"<<a.get_total()<<endl;
						
						break;
					case 4 :						
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

	return 0;
}



