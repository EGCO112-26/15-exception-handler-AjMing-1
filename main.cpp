#include<iostream>
#include<exception>
using namespace std;
void check0(int);

class div0:public exception{ // Class จัดการ ตัวหารเป็น 0
	public:
	virtual const char* what() const throw() { 
		    
			return "Divided by zero"; 
 } 

};


/* เปิดไมค์/ พิมพ์ถามได้ค่ะ  */

class fail:public exception{ // Class จัดการ cinfail()
	public:
	virtual const char* what() const throw() { 
		    cin.clear();
			cin.ignore(50,'\n');
			return " "; 
 } 

};


int main(){
    int x,y;
	double d;	
	int a=1;
 do{

    try{
		
		cout<<"Enter 2 numbers: ";
		cin>>x>>y;

		/* Curated Exception Handling */
		if(cin.fail()) throw 101 ; 
		if(abs(x)>1000 ||abs(y)>1000) throw "Value out of range"; 
		check0(y);
		a=0;
		/* Normal Code*/
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
		
		int i;
		double * myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory .... "<<i<<endl;
			myarray= new double[50000000000];

		}
		
		
   }
   catch(const char *error){
	 cerr<< error<<endl;

	
   }
  catch(const int e ){
		switch(e){
			case 101: cerr<<"Incorrect numbers "<<endl; break;
			case 0: cerr<<"Divided by zero"<<endl; break;
		}
		
		cin.clear();
        cin.ignore(50,'\n');
  }
  catch(exception &e){
  	cout<<e.what()<<endl;
	a=0;

  }


 }while(a);
	return 0;
}



void check0(int x){
     div0 e;
	if(x==0) throw e;
}