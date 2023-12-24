#include <iostream>
#include <string>
using namespace std;
#include "Sports.h"

ostream& operator<<(ostream &os,const Basketball &obj){
	os<<"calorie:"<<obj.calorie<<endl;
	return os;
}

Basketball::Basketball(){
	calorie=6;
}
int Basketball::kalori(){
	int cal=0;
	cal=calorie;
	int a;
	cout<<"kac dakika basketbol oynadiniz?:";
	cin>>a;
	cal*=a;
	cout<<"harcanan calori:"<<cal<<endl;;
	return cal;
}
Basketball::Basketball(const Basketball& other){
	calorie=other.calorie;
}
Basketball& Basketball::operator=(const Basketball& other){
	if(this!=&other){
		calorie=other.calorie;
	}
	return *this;
}
Basketball Basketball::operator+(Basketball &obj){
	Basketball temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}
ostream& operator<<(ostream &os,const Football &obj){
	os<<"calorie:"<<obj.calorie<<endl;
	return os;
}

Football::Football(){
	calorie=5;
}
int Football::kalori(){
	int cal=0;
	cal=calorie;
	int a;
	cout<<"kac dakika futbol oynadiniz?:";
	cin>>a;
	cal*=a;
	cout<<"harcanan calori:"<<cal<<endl;;
	return cal;
}
Football::Football(const Football& other){
	calorie=other.calorie;
}
Football& Football::operator=(const Football& other){
	if(this!=&other){
		calorie=other.calorie;
	}
	return *this;
}
Football Football::operator+(Football &obj){
	Football temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}

ostream& operator<<(ostream &os,const Tennis &obj){
	os<<"calorie:"<<obj.calorie<<endl;
	return os;
}

Tennis::Tennis(){
	calorie=5;
}
int Tennis::kalori(){
	int cal=0;
	cal=calorie;
	int a;
	cout<<"kac dakika tenis oynadiniz?:";
	cin>>a;
	cal*=a;
	cout<<"harcanan calori:"<<cal<<endl;;
	return cal;
}
Tennis::Tennis(const Tennis& other){
	calorie=other.calorie;
}
Tennis& Tennis::operator=(const Tennis& other){
	if(this!=&other){
		calorie=other.calorie;
	}
	return *this;
}
Tennis Tennis::operator+(Tennis &obj){
	Tennis temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}


ostream& operator<<(ostream &os,const Swimming &obj){
	os<<"calorie:"<<obj.calorie<<endl;
	return os;
}

Swimming::Swimming(){
	calorie=7;
}
int Swimming::kalori(){
	int cal=0;
	cal=calorie;
	int a;
	cout<<"kac dakika yuzdunuz?:";
	cin>>a;
	cal*=a;
	cout<<"harcanan calori:"<<cal<<endl;;
	return cal;
}
Swimming::Swimming(const Swimming& other){
	calorie=other.calorie;
}
Swimming& Swimming::operator=(const Swimming& other){
	if(this!=&other){
		calorie=other.calorie;
	}
	return *this;
}
Swimming Swimming::operator+(Swimming &obj){
	Swimming temp;
	temp.calorie=calorie+obj.calorie;
	return temp;
}


