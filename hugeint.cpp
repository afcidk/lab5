#include "hugeint.h"

HugeInt::HugeInt(){
	this->value = "";
	this->len = 0;
}

HugeInt::HugeInt(int x){
	
	this->value = "";
	while(x>0){

		char now = x%10+'0';
		x/=10;
		this->value = now + this->value;
	}
	this->len = this->value.length();
}

HugeInt::HugeInt(string s){
	this->value = s;
	this->len = this->value.length();
}

HugeInt HugeInt::operator+(const HugeInt &s) const{

	int lena = this->len;
	int lenb = s.len;
	string x=s.value;
	string tmp = value;
	HugeInt now;

	int i, j;
	for(i=lena-1, j=lenb-1; i>=0 && j>=0; --i, --j)	tmp.at(i)+=x.at(j)-'0';
	if(lenb > lena)	tmp = x.substr(0, lenb-lena) + tmp;

	for(i=max(lena, lenb)-1; i>0; --i){

		if(tmp.at(i)>'9'){
			tmp.at(i)-=10;
			++tmp.at(i-1);
		}
	}

	if(tmp.at(0)>'9'){
		tmp.at(0)-=10;
		tmp = "1" + tmp;
	}

	now.value = tmp;
	now.len = tmp.length();
	return now;
}

HugeInt HugeInt::operator- (const HugeInt &s) const{

	int lena = this->len;
	int lenb = s.len;
	int neg=0;
	string x = s.value, tmp = this->value;
	HugeInt now;

	std::cout<<x<<" "<<tmp<<std::endl;
	if(lena<lenb || (lena==lenb && tmp<x)){
		x=this->value;
		tmp = s.value;
		int t=lenb;
		lenb=lena;
		lena=t;
		neg=1;
	}

	int i, j;
	for(i=lena-1, j=lenb-1; i>=0 && j>=0; --i, --j)	tmp.at(i)-=x.at(j)-'0';
	if(lenb > lena)	tmp = x.substr(0, lenb-lena) + tmp;

	for(i=max(lena, lenb)-1; i>0; --i){

		if(tmp.at(i)<'0'){
			tmp.at(i)+=10;
			--tmp.at(i-1);
		}
	}
	
	while(tmp.at(0)=='0' && tmp.length()>1) tmp.erase(0,1);

	if(neg) tmp = "-"+tmp;
	now.value = tmp;
	now.len = tmp.length();
	return now;
}

const HugeInt& HugeInt::operator=(const HugeInt &x){

	(*this).value = x.value;
	(*this).len = x.len;
	return *this;
}

ostream &operator<< (ostream &out, HugeInt &x) {

	out<<x.value;
	return out;
}

istream &operator>> (istream &in, HugeInt &x){
	
	in>>x.value;
	x.len = x.value.length();
	return in;
}
