#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my.h"
int main(){
	//m��teri
	Customer *root;
	root=(Customer*)malloc(sizeof(Customer));
	root->ID=1; strcpy(root->name,"abc def");
	root->type=0; 
	root->x_coord=3.0; 
	root->y_coord=4.0;
	root->nextCusPtr= NULL;
	
	//�r�n
	Product *node;
	node=(Product*)malloc(sizeof(Product));
	strcpy(node->name,"elma");
	node->ID=1; 
	node->type=1;//meyve
	node->price=5.5;
	node->nextProPtr=NULL;

	node->nextProPtr=(Product*)malloc(sizeof(Product));
	node->nextProPtr->ID=2;;
	node->nextProPtr->price=4.5; 
	node->nextProPtr->type=2;//sebze 
	strcpy(node->nextProPtr->name,"lahana");
	node->nextProPtr->nextProPtr=NULL ; 
	
	node->nextProPtr->nextProPtr=(Product*)malloc(sizeof(Product));
	node->nextProPtr->nextProPtr->ID=3;
	node->nextProPtr->nextProPtr->price=3.5;
	node->nextProPtr->nextProPtr->type=1;//meyve
	strcpy(node->nextProPtr->nextProPtr->name,"armut");
	node->nextProPtr->nextProPtr->nextProPtr=NULL;
	
	//sat��	
	Purchased *pur;
	pur=(Purchased*)malloc(sizeof(Purchased));
	pur->nextPurchasedPtr=NULL;
	pur->invoice_ID=0;
	
	int id,secim;
	unsigned int choice,sec;
	instructions();
 	scanf( "%u", &choice );
	while ( choice !=5) {

	switch ( choice ) {
	case 1:
		system("cls");
		printf("musteri eklemek icin 1\nsatis yapmak icin 2\nseciniz:\n");
		scanf("%u",&sec);
		switch (sec){
			case 1:
				root=insertCustomer(root);
				break;
			case 2:
				addpurchased(pur,root,node);
				break;
			default:
				puts( "Verilen se�eneklerden birini girmediniz!\n" );
				break;
			}
		break;
	case 2: // m��teri bilgisi
		printf("islem secin\n");
		printf("1. tum musteriler\n2.musteri tipine gore musteriler\n3.tek musteri bulma\n");
		scanf("%u",&sec);
		switch (sec){
			
			case 1:
				displaycustomer(root);
				break;
			case 2:
				printf("Bireysel Musterileri yazdirmak icin 0\nTicari Musterileri yazdirmak icin 1 i girin:");
				scanf("%d",&secim);
				musteritip(root,secim);
				break;
			case 3:
				printf("musteri id girin:");//2.3 Bir m�steri
				scanf("%d",&id);
				tekmusteri(root,id);
				break;
			default:
				puts( "Verilen se�eneklerden birini girmediniz!\n" );
				break;
			}
		
		break;
	case 3://�r�n bilgisi
		printf("islem secin\n");
		printf("1. tum urunler\n2.urun tipine gore urunler\n3.tek urun bulma\n");
		scanf("%u",&sec);
		switch (sec){
			case 1:
				displayurun(node);//T�m �r�nler 
				break;
			case 2:
				secim=0;
				printf("Meyveleri yazdirmak icin 1\nSebzeleri yazdirmak icin 2 i girin:");
				scanf("%d",&secim);
				uruntip(node,secim);//�r�n tipine g�re
				break;
			case 3:
				printf("urun id girin:");
				scanf("%d",&id);
				tekurun(node,id);//Bir �r�n
				break;
			default:
				puts( "Verilen se�eneklerden birini girmediniz!\n" );
				break;
			}
		break;
	case 4:	//m��teri analizleri
		printf("islem secin\n");
		printf("1.Bir musterinin satin aldigi urunler\n2.Bir musterinin satin aldigi toplam tutar \n3.Tum musterinin satin aldigi urunlerin toplam tutari\n4.Musterilerin kargo ucreti\n");
		scanf("%u",&sec);
		switch (sec){
			case 1:
				satis_urun(pur,node);//Bir m��terinin sat�n ald��� �r�nler 
				break;
				
			case 2:
				satis_tutar(pur,node);//Bir m��terinin sat�n ald��� toplam tutar
				break;
			case 3:
				toplam_tutar(pur,node);//T�m m��terinin sat�n ald��� �r�nlerin toplam tutar� 
				break;
			case 4:
				kargo(pur,root);// M��terilerin kargo �creti
				break;
			default:
				puts( "Verilen se�eneklerden birini girmediniz!\n" );
				break;
			}
		break;
	case 5://�r�n analizi
		uruntutar(pur);	
		break;
		
	default:
		puts( "Invalid choice.\n" );
		break;
	} // end switch
	instructions();
	scanf( "%u", &choice );
	} // end while
	
	return 0;
}
