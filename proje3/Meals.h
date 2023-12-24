#ifndef meals_h_
#define meals_h_
#include <iostream>
#include <string>
using namespace std;

class Breakfast{
	friend ostream& operator<<(ostream &os,const Breakfast &obj);
	public:
		Breakfast();
		Breakfast(const Breakfast& other);
		Breakfast& operator=(const Breakfast& other);
		Breakfast operator+(Breakfast &obj);
		int sec();//kahvaltinin boyutunu belirlemek için kullanýlacak fonk
	private:
		int small;
		int medium;
		int large;
		int calorie;
};
class Lunch{
	friend ostream& operator<<(ostream &os,const Lunch &obj);
	public:
		Lunch();
		Lunch(const Lunch& other);
		Lunch& operator=(const Lunch& other);
		Lunch operator+(Lunch &obj);
		int sec();
	private:
		int small;
		int medium;
		int large;
		int calorie;
};
class Dinner{
	friend ostream& operator<<(ostream &os,const Dinner &obj);
	public:
		Dinner();
		Dinner(const Dinner& other);
		Dinner& operator=(const Dinner& other);
		Dinner operator+(Dinner &obj);
		int sec();
	private:
		int small;
		int medium;
		int large;
		int calorie;
};
#endif
