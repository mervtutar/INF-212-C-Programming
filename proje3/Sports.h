#ifndef sports_h_
#define sports_h_
#include <iostream>
#include <string>
using namespace std;

class Basketball{
	friend ostream& operator<<(ostream &os,const Basketball &obj);
	public:
		Basketball();
		Basketball(const Basketball& other);
		Basketball& operator=(const Basketball& other);
		Basketball operator+(Basketball &obj);
		int kalori();//spor kaç dk yapýldýysa ona göre yakýlan kaloriyi hesaplayacak fonk
	private:
		int calorie;
};

class Football{
	friend ostream& operator<<(ostream &os,const Football &obj);
	public:
		Football();
		Football(const Football& other);
		Football& operator=(const Football& other);
		Football operator+(Football &obj);
		int kalori();
	private:
		int calorie;
};

class Tennis{
	friend ostream& operator<<(ostream &os,const Tennis &obj);
	public:
		Tennis();
		Tennis(const Tennis& other);
		Tennis& operator=(const Tennis& other);
		Tennis operator+(Tennis &obj);
		int kalori();
	private:
		int calorie;
};

class Swimming{
	friend ostream& operator<<(ostream &os,const Swimming &obj);
	public:
		Swimming();
		Swimming(const Swimming& other);
		Swimming& operator=(const Swimming& other);
		Swimming operator+(Swimming &obj);
		int kalori();
	private:
		int calorie;
};
#endif







