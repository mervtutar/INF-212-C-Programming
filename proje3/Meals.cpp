#include <iostream>
#include <string>
using namespace std;
#include "Meals.h"

ostream& operator<<(ostream &os,const Breakfast &obj){
	os<<"small:"<<obj.small<<endl<<"medium:"<<obj.medium<<endl<<"large:"<<obj.large<<endl;
	return os;
}
Breakfast::Breakfast(){
	small=200;
	medium=400;
	large=600;
	calorie=0;
}
Breakfast::Breakfast(const Breakfast& other){
	small=other.small;
	medium=other.medium;
	large=other.large;
}
Breakfast& Breakfast::operator=(const Breakfast& other){
	if(this!=&other){
		small=other.small;
		medium=other.medium;
		large=other.large;
	}
	return *this;
}
Breakfast Breakfast::operator+(Breakfast &obj){
	Breakfast temp;
	temp.small=small+obj.small;
	temp.medium=medium+obj.medium;
	temp.large=large+obj.large;
	return temp;
}
int Breakfast::sec(){
	
	int a;
	cout<<"secim yapin\n1.small\n2.medium\n3.large"<<endl;
	cin>>a;
	if(a==1){
		calorie=small;
	}
	else if(a==2){
		calorie=medium;
	}
	else if(a==3){
		calorie=large;	
	}
	else{
		cout<<"yanlis secim yaptiniz."<<endl;
	}
			
	cout<<"calori degeri:"<<calorie<<endl;	
	return calorie;	
}
ostream& operator<<(ostream &os,const Lunch &obj){
	os<<"small:"<<obj.small<<endl<<"medium:"<<obj.medium<<endl<<"large:"<<obj.large<<endl;
	return os;
}
Lunch::Lunch(){
	small=400;
	medium=600;
	large=800;
}
Lunch::Lunch(const Lunch& other){
	small=other.small;
	medium=other.medium;
	large=other.large;
}
Lunch& Lunch::operator=(const Lunch& other){
	if(this!=&other){
		small=other.small;
		medium=other.medium;
		large=other.large;
	}
	return *this;
}
Lunch Lunch::operator+(Lunch &obj){
	Lunch temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}
int Lunch::sec(){
	int a;
	cout<<"secim yapin\n1.small\n2.medium\n3.large"<<endl;
	cin>>a;
	if(a==1){
		calorie=small;
		
	}
	else if(a==2){
		calorie=medium;
		
	}
	else if(a==3){
		calorie=large;
		
	}
	else{
		cout<<"yanlis secim yaptiniz."<<endl;
	}
			
	cout<<"calori degeri:"<<calorie<<endl;	
	return calorie;
}
ostream& operator<<(ostream &os,const Dinner &obj){
	os<<"small:"<<obj.small<<endl<<"medium:"<<obj.medium<<endl<<"large:"<<obj.large<<endl;
	return os;
}

Dinner::Dinner(){
	small=400;
	medium=600;
	large=800;
}
Dinner::Dinner(const Dinner& other){
	small=other.small;
	medium=other.medium;
	large=other.large;
}
Dinner& Dinner::operator=(const Dinner& other){
	if(this!=&other){
		small=other.small;
		medium=other.medium;
		large=other.large;
	}
	return *this;
}
Dinner Dinner::operator+(Dinner &obj){
	Dinner temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}
int Dinner::sec(){
	int a;
	cout<<"secim yapin\n1.small\n2.medium\n3.large"<<endl;
	cin>>a;
	if(a==1){
		calorie=small;
		
	}
	else if(a==2){
		calorie=medium;
		
	}
	else if(a==3){
		calorie=large;
		
	}
	else{
		cout<<"yanlis secim yaptiniz."<<endl;
	}
			
	cout<<"calori degeri:"<<calorie<<endl;
	
	return calorie;	
}




