#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my.h"

void instructions( void )
{
	puts( "\nsecim yapiniz\n"
	"1. Satis \n2. Musteri Bilgisi \n3. Urun Bilgisi \n4. Musteri Analizleri \n5. Urun Analizleri" );
}
Customer *insertCustomer(Customer *cptr){
	Customer* iter;
	iter = cptr;
	int idx;
	char name[50];
	unsigned int tip;
	double x,y;
	printf("Musteri Numarasi Giriniz\n") ;
	scanf("%d",&idx) ;
	printf("musteri adi girin:");
	scanf(" %[^\n]",name); 
	printf("musteri tipi secin ticari ise 1, bireysel ise 0:");
	scanf("%d",&tip);
	printf("x koordinatini girin:");
	scanf("%lf",&x);
	printf("y koordinatini girin:");
	scanf("%lf",&y);
	if( iter->ID == 0){
		iter = (Customer*)malloc(sizeof(Customer));
		iter->ID = idx;
		strcpy(cptr->name,name);
		iter->type = tip;
		iter->x_coord = x;
		iter->y_coord = y;
		iter->nextCusPtr = NULL ;
		printf("%d %s %lf %lf %u\n bilgileri girilmistir..\n\n",iter->ID, iter->name, 
		iter->x_coord, iter->y_coord, iter->type );
		cptr = iter ;
		return cptr ;
	}
	else{
		while(iter->nextCusPtr != NULL){
			iter = iter -> nextCusPtr ;
		}
		iter->nextCusPtr = (Customer*)malloc(sizeof(Customer));
		iter = iter->nextCusPtr;
		iter->nextCusPtr = NULL ;	
		strcpy(iter -> name, name) ;
		iter -> ID = idx ;
		iter -> type = tip ;
		iter -> x_coord = x ;
		iter -> y_coord = y ;
		printf("%d %s %.2lf %.2lf %u\n bilgileri girilmistir..\n\n",iter->ID, iter->name, iter->x_coord, iter->y_coord, iter->type );
		return cptr ;
	}
}
Customer *tekmusteri(Customer *z,int ID){
	system("cls");
	if(z==NULL){
		printf("musteri listesi bos!!");
	}
	else{
		while(z->nextCusPtr!=NULL){
			if(ID==z->ID){
				printf("\nmusteri numarasi :%d\n",z->ID);
				printf("musteri adi :%s\n",z->name);
				printf("musteri tipi :%d\n",z->type);
				printf("x koordinati :%.2lf\n",z->x_coord);
				printf("y koordinati :%.2lf\n",z->y_coord);	
			}
			z=z->nextCusPtr;
		}	
		if(ID==z->ID){
				printf("\nmusteri numarasi :%d\n",z->ID);
				printf("musteri adi :%s\n",z->name);
				printf("musteri tipi :%d\n",z->type);
				printf("x koordinati :%.2lf\n",z->x_coord);
				printf("y koordinati :%.2lf\n",z->y_coord);	
		}	
		printf("\n");
	}
	return z;
}
void displaycustomer(Customer *head){
	system("cls");
	if(head==NULL){
		printf("musteri listesi bos!!");
	}
	else{
		Customer *p=head;
		while(head->nextCusPtr!= NULL){
			printf("musteri no:%d adi:%s koordinatlari:%.2lf,%.2lf  tipi:%u \n",head->ID, head->name, head->x_coord, head->y_coord, head->type );
			head=head->nextCusPtr;
		}
		printf("------------\n");
		printf("musteri no:%d adi:%s koordinatlari:%.2lf,%.2lf  tipi:%u \n\n",head->ID, head->name, head->x_coord, head->y_coord, head->type );
	}
	
}
void musteritip(Customer *cptr,int secim){
	system("cls");
	Customer *iter=cptr;
	while(iter->nextCusPtr != NULL )
	{
		if(iter->type == secim){
			printf("musteri no : %d\nmusteri adý : %s\nmusteri tipi : %u\n", iter->ID, iter->name, iter->type);
		}
		iter = iter->nextCusPtr;
	}
	
	if(iter->type == secim){
				printf("musteri no : %d\nmusteri adý : %s\nmusteri tipi : %u\n", iter->ID, iter->name, iter->type);
	}
}
void displayurun(Product *head){
	system("cls");
	printf("\ntum urunler:\n\n");
	while(head!= NULL){
		printf("%d %s %.2lf %u \n",head->ID, head->name, head->price, head->type );
		head=head->nextProPtr;
	}
	printf("\n\n");
}
Product *tekurun(Product *y,int idd){
	system("cls");
	if(y==NULL){
		printf("urun listesi bos!!");
	}
	else{
		Product *p=y;
		while(p!=NULL){
			if(p->ID==idd){
				printf("\nurun numarasi :%d\n",p->ID);
				printf("urun adi :%s\n",p->name);
				printf("urun tipi :%d\n",p->type);
				printf("urun ucreti :%.2lf\n",p->price);	
			}
			p=p->nextProPtr;
		}
		printf("\n");
	}
	return y;
}
void uruntip(Product *cptr,int secim){
	system("cls");
	Product *iter=cptr;
	while(iter->nextProPtr != NULL )
	{
		if(iter->type == secim){
			printf("urun no : %d\nurun adi : %s\nurun tipi : %u\nurun ucreti : %.2lf", iter->ID, iter->name, iter->type,iter->price);
		}
		iter = iter->nextProPtr;
	}
	
	if(iter->type == secim){
			printf("urun no : %d\nurun adi : %s\nurun tipi : %u\nurun ucreti : %.2lf", iter->ID, iter->name, iter->type,iter->price);
	}
}
Purchased *sonfaturano(Purchased* head,int prevcostumerid,int lastinvoice){
	lastinvoice = head->invoice_ID ;
	Purchased* iter = head;
	if(iter->nextPurchasedPtr == NULL)
	{
		iter->invoice_ID++;
		return iter;
	}
	while(iter->nextPurchasedPtr != NULL)
	{	prevcostumerid=iter->customer_ID ;
		if(iter->customer_ID == prevcostumerid )
		{
			iter->invoice_ID = lastinvoice;
		}
		else
		{
			iter->invoice_ID++;
			lastinvoice = iter->invoice_ID ;
		}
		iter = iter->nextPurchasedPtr ;
		return iter;
	}
}
void addpurchased(Purchased* purchased_head, Customer* customer_head, Product* product_head)
{
	system("cls");
	int prevcustomerid, prevdinvoiceid ;
	Purchased* purchasedx = purchased_head ;
	Customer* customerx = customer_head ;
	Product* productx = product_head ;
	int idx, adet=0,flag=0;
	double sumcost=0;
	while( flag == 0 )
	{
		printf("satis icin musteri Numarasi Giriniz\n") ;
		scanf("%d",&idx) ;
		customerx = tekmusteri(customer_head, idx) ;
		if(customerx == NULL)
		{
			printf("\nDevam etmek icin 0\n Cýkmak icin 99 girin") ;
			scanf("%d",&flag) ;
		}
		else{
			flag = 1; 
		}
		while( flag == 1 )
		{
			purchasedx = sonfaturano(purchased_head,prevcustomerid,prevdinvoiceid);

			if(prevcustomerid == purchasedx->customer_ID)
			{
				purchasedx->invoice_ID = prevdinvoiceid ;
			}
			else
			{
				purchasedx->invoice_ID++ ;
				prevcustomerid = purchasedx->customer_ID ;
			}

			printf("Sepete Urun eklemek icin urun no giriniz\n") ;
			scanf("%d",&idx) ;

			productx = tekurun(product_head,idx) ;
			if( productx == NULL )
			{	
				printf("Urun bulunamadý!!!! Satis devam icin 1 cikmak icin 99 giriniz\n");
				scanf("%d",&flag);
				continue ;	
			}
			printf("Urun Adedi giriniz\n") ;
			scanf("%d",&adet) ;
			if( adet == 0 )
			{	
				printf("Urun adet 0 olarak girildi!!\n") ;
				printf("Satisa devam icin 1 cikmak icin 99 giriniz\n");
				scanf("%d",&flag);
				continue ;
			}
			else
			{
				purchasedx->cost = (adet)*(productx->price);//sepet tutarý
				sumcost+= (adet)*(productx->price) ;//toplam maliyet
			}
			purchasedx->ID++ ;
			purchasedx->product_ID = productx->ID ;
			purchasedx->customer_ID = customerx->ID ;
			printf("Tekrar urun eklemek icin 1 giriniz, \nToplam maliyet icin 2,\nUst menu icin 0, \n") ;
			scanf("%d",&flag) ;
			if( flag == 2 )
			{
				printf("Sepet Tutari : %.2lf TL'dir\n",purchasedx->cost ) ;
				if( sumcost == 0 )
				{	
					printf("Urun adeti girilmedi devam etmek icin 0 girin\n") ;
					scanf("%d",&flag) ;
					break ;
				}
				else
				{
					sumcost += 2*(sqrt(pow(customerx->x_coord,2)+pow(customerx->y_coord,2)));
					printf("Odenecek Tutar : %.2lf TL'dir \n",sumcost ) ;
				}
			}	
		}
	}
	return;
}
void satis_urun(Purchased *head,Product *pro){
	int idd;
	Product *xx=pro;
	printf("musteri no giriniz:\n");
	scanf("%d",&idd);
	if(head==NULL){
	 	printf("satis yok");
	}
	else{
	 	Purchased *sat = head;
	 	while(sat!=NULL){
	 		if(idd==sat->customer_ID){
	 			xx=tekurun(pro,sat->product_ID);
			}
			sat=sat->nextPurchasedPtr;
		}
	}
	return;
}
void satis_tutar(Purchased *head,Product *pro){
	int idd;
	Product *xx=pro;
	printf("musteri no giriniz:\n");
	scanf("%d",&idd);
	if(head==NULL){
	 	printf("satis yok");
	}
	else{
	 	Purchased *sat = head;
	 	while(sat!=NULL){
	 		if(idd==sat->customer_ID){
	 			printf("musterinin satin aldigi urunlerin toplam tutari:%.2lf TL\n",sat->cost);
			}
			sat=sat->nextPurchasedPtr;
		}
	}
	return;
}
void toplam_tutar(Purchased *head,Product *pro){
	double counter=0;
	Product *xx=pro;
	if(head==NULL){
	 	printf("satis yok");
	}
	else{
	 	Purchased *sat = head;
	 	while(sat->nextPurchasedPtr!=NULL){
	 		counter+=sat->cost;
			sat=sat->nextPurchasedPtr;
		}	
		counter+=sat->cost;
		printf("tum musterilerin satin aldigi urunlerin toplam tutari:%.2lf TL\n",counter);
	}
	return;
}
void kargo(Purchased *head,Customer *cptr){
	double sumcost;
	if(head==NULL){
	 	printf("satis yok");
	}
	else{
		Customer *cus=cptr;
	 	Purchased *sat = head;
	 	while(sat->nextPurchasedPtr!=NULL){
	 		sumcost += 2*(sqrt(pow(cus->x_coord,2)+pow(cus->y_coord,2)));
	 		sat=sat->nextPurchasedPtr;
		}
		sumcost += 2*(sqrt(pow(cus->x_coord,2)+pow(cus->y_coord,2)));
		printf("Odenecek Tutar : %.2lf TL'dir \n",sumcost ) ;
	}
	return;
}
void uruntutar(Purchased *head){
	int idd;
	printf("urun no girin:\n");
	scanf("%d",&idd);
	if(head==NULL){
	 	printf("satis yok");
	}
	else{
	 	Purchased *sat = head;
	 	while(sat!=NULL){
	 		if(idd==sat->product_ID){
	 			printf("musterinin satin aldigi toplam urun tutari:%.2lf TL\n",sat->cost);
			}
			sat=sat->nextPurchasedPtr;
		}
	}
	return;	
}

