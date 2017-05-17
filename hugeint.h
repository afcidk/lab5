#ifndef HUGEINT_H
#define HUGEINT_H
#include <string>
#include <iostream>
using namespace std;

class HugeInt{

	friend istream &operator>> (istream &, HugeInt &);
	friend ostream &operator<< (ostream &, HugeInt &);

	public:
		HugeInt();
		HugeInt(int n);
		HugeInt(string s);
		
		HugeInt operator+ (const HugeInt &a) const;
		HugeInt operator- (const HugeInt &a) const;
		const HugeInt& operator= (const HugeInt &a);

	private:
		string value;
		int len;
};

#endif
