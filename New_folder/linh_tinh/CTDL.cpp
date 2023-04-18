#include<iostream>
#include<string>
using namespace std;
struct Sv
{
	Sv (std::string ht, int t, int l, int h)
	{
		ho_ten = ht;
		toan = t;
		ly = l;
		hoa = h;
	}
	Sv( )
	{
	
	} 
	std::string ho_ten;
	int toan;
	int ly;
	int hoa;
}; 
int main(){
	Sv a[3]; 
	a[0] = Sv("Phan Van Tuoi",8,9,7);
	a[1] = Sv("Nguyen Minh Quan",9,9,9);
	a[2] = Sv("Duong Van Gioi",10,10,10);
	a[3] = Sv("Phan Anh Vu",5,5,5);cout<<"hehehe";
	for(int i=0; i<=3;i++){
			
        cout<< a[i].ho_ten<< ":"<<a[i].toan<<","<<a[i].ly<<","<<a[i].hoa<<"\n";
        ;
}
	return 0;
	
}
