#ifndef _MY_H_
#define _MY_H_
struct customer {
	int ID;
	char name[50];
	unsigned int type:1;
	double x_coord;
	double y_coord;
	struct customer *nextCusPtr;
};
typedef struct customer Customer;
struct product {
	int ID;
	char name[50];
	int type;
	double price;
	struct product *nextProPtr;
};
typedef struct product Product;

struct purchased {
	int ID;//satýlan parça numarasý
	int invoice_ID;//fatura no
	int customer_ID;//müþteri no
	int product_ID;//ürün no
	double cost;//maliyet
	struct purchased *nextPurchasedPtr;
};
typedef struct purchased Purchased;
void instructions( void );
Customer *insertCustomer(Customer *cptr);
Customer *tekmusteri(Customer *z,int ID);
void displaycustomer(Customer *head);
void musteritip(Customer *cptr,int secim);
void displayurun(Product *head);
Product *tekurun(Product *y,int idd);
void uruntip(Product *cptr,int secim);
Purchased *sonfaturano(Purchased* head,int prevcostumerid,int lastinvoice);
void addpurchased(Purchased* purchased_head, Customer* customer_head, Product* product_head);
void satis_urun(Purchased *head,Product *pro);
void satis_tutar(Purchased *head,Product *pro);
void toplam_tutar(Purchased *head,Product *pro);
void kargo(Purchased *head,Customer *cptr);
void uruntutar(Purchased *head);

#endif
