#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>   
#include <cstdlib> 
#include <vector>

using namespace std;

class Hesap{
	protected:
		double id;
		string name;
		string password;
	public:
		Hesap(string name1,string password1)
		{	
			double randomId;
			srand (time(NULL));
			randomId=rand() % 1000;
			
			id=randomId;
			name=name1;
			password=password1;
		}
		
		string getName(){
			return name;
		}
		string getPassword(){
			return password;
		}
		double getId(){
			return id;
		}
		
		string setName(string name2){
			name=name2;
		}
		
		string setPw(string password2){
			password=password2;
		}
		
		friend ostream &operator << (ostream &output,Hesap yonetici)
		{
		    output<<"Yonetici Giris Ismi:"<<yonetici.name<<endl<<"Yonetici Sifresi:"<<yonetici.password<<endl;
		    return output;
	    }
		
		
		virtual	void setHesapBakiye(int bakiye1){
		}
		
		
		
};

class Akbil: public Hesap{ 

	private:
		
		static double bakiye;
	
	public:
		Akbil(string name,string password)
		:Hesap(name,password)
		{	
		
		}
		
		void setHesapBakiye(int bakiye1){
			
			cout<<"Akbile yatirmak istediginiz miktar nedir?:"<<endl;
			cin>>bakiye1; 
			
			bakiye+=bakiye1;
		}
		
		
		int getAkbilInfo(){
			
			cout<<"Hesap Id'niz:"<<id<<"	Bakiyeniz: "<<bakiye<<endl;
			
		}
	
		
		
		
		
};double Akbil::bakiye=0;

class yemekKarti: public Hesap{
	
	private:
		
		static double bakiye;
		
	public:
		yemekKarti(string name,string password)
		:Hesap( name, password)
		{
			
		}
		
		void setHesapBakiye(int bakiye1){
			
			cout<<"Yemek kartiniza yatirmak istediginiz miktar nedir?:"<<endl;
			cin>>bakiye1;
		
			bakiye+=bakiye1;
		}
		
		int getYemekKartiInfo(){
			
			cout<<"Hesap Id'niz:"<<id<<"	Bakiyeniz:"<<bakiye<<endl;
			
		}
		
};double yemekKarti::bakiye=0;


void hesapOlustur(vector<Hesap>&);

void hesapListesi(vector<Hesap>&);

bool hesapLogin(vector<Hesap>& newcreateAccObj);

int hesapIndexCheckForGetName(vector<Hesap>& newcreateAccObj);


int main(){
	int whileCondition=-1;
	string girisSecim;

		

	vector<Hesap>  createAccObj;
	
	while(whileCondition==-1){
		system("CLS");
		cout<<"--------------------------------------------------------"<<endl;
		cout<<"Genel Kart Programina Hosgeldiniz, ne yapmak istersiniz?"<<endl;
		cout<<"1-Hesap Olusturma				2-Hesaba Giris"<<endl;     
		cout<<"3-Yonetici Girisi				4-Cikis						"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		
		
		cin>>girisSecim;
		
		
				
			if(girisSecim=="1"){
				
				hesapOlustur(createAccObj);
			 
			} //girisSecim 1 finish
					
			else if(girisSecim=="2"){
				
				string secim;
				string name,password;
				
				
				
				if(hesapLogin(createAccObj)==true){
				
				//system("CLS");
    			cout<<"-----------------------"<<endl;
    			cout<<endl<<"You have logged in!"<<endl;
				}
				
				else{
						system("CLS");
    					cout<<"-----------------------"<<endl;
    					cout<<endl<<"Wrong password or name.Program closing for the security reason!"<<endl;
    					return 0;
				}
				
kartSecim:		cout<<endl<<"Hangi hesabinizla devam etmek istersiniz?"<<endl;
				cout<<"1-Akbil		2-Yemek Karti"<<endl;
				cin>>secim;
				
					if(secim=="1"){
						string akbilsecim;
						system("CLS");
						cout<<"------------------------------"<<endl;
						cout<<"Akbil hesabiniza gecis yapildi."<<endl;
						
						Akbil createAkbilObj(name,password);
					
akbilSecim:						cout<<"------------------------------"<<endl;
								cout<<"Seciminiz nedir?"<<endl;
								cout<<"1-Bakiye yukle  2-Bilgi Goruntuleme"<<endl; 
								cout<<"---------------------------------------"<<endl;
								cin>>akbilsecim;
						
							if(akbilsecim=="1"){
							
								int miktar;
								createAkbilObj.setHesapBakiye(miktar);	
													
								}
							
							
							else if(akbilsecim=="2"){
								
    							int i=hesapIndexCheckForGetName(createAccObj);
    							createAkbilObj.getAkbilInfo(); 
    							cout<<"Hesap Isminiz:  "<<createAccObj[i].getName()<<endl;
								
								
							}
							
							else{
								cout<<"Hatali islem yaptiniz, geri yonlendiriliyorsunuz"<<endl;
								goto akbilSecim;
							}
						
						
					}
							 	
					else if(secim=="2"){
						
						string yemekkartisecim;
						system("CLS");
						cout<<"Yemek karti hesabiniza gecis yapildi."<<endl;
						
						yemekKarti createyemekKartiObj(name,password);
						
yemekKartiSecim:				cout<<"------------------------------"<<endl;
								cout<<"Seciminiz nedir?"<<endl;
								cout<<"1-Bakiye yukle  2-Bilgi Goruntuleme"<<endl; 
								cout<<"---------------------------------------"<<endl;
								cin>>yemekkartisecim;
						
							if(yemekkartisecim=="1"){
								
			
								int miktar;
								createyemekKartiObj.setHesapBakiye(miktar);	
													
								}
							
							
							else if(yemekkartisecim=="2"){
								
								int i=hesapIndexCheckForGetName(createAccObj);
    							cout<<"Hesap Isminiz:  "<<createAccObj[i].getName()<<endl;
								createyemekKartiObj.getYemekKartiInfo();
							}
							
							else{
								cout<<"Hatali islem yaptiniz, geri yonlendiriliyorsunuz"<<endl;
								goto yemekKartiSecim;
							}
						
					}
					
								
					else{
						cout<<"Hatali islem yaptiniz, geri yonlendiriliyorsunuz"<<endl;
						goto kartSecim;
					}
					
							
					}//girisSecim 2 finish
					
			else if(girisSecim=="3"){
				
				
							string name;
							string password;
							Hesap yonetici("admin","adminpw");
							cout<<"-------------------"<<endl;
							cout<<"Enter admin name:"<<endl;
							cin>>name;
							cout<<"-------------------"<<endl;
							cout<<"Enter admin password:"<<endl;
							
							cin>>password;
								
							if(name=="admin"&&password=="adminpw"){
								
								string yoneticiSecim;
								
yoneticiSecimEkrani:			cout<<"------------------------------"<<endl;
								cout<<"Seciminiz nedir?"<<endl;
								cout<<"1-Kayitli Hesaplari Goruntule "<<endl; 
								cout<<"2-Yonetici Bilgilerini Goruntule"<<endl;
								cout<<"---------------------------------------"<<endl;
								cin>>yoneticiSecim;
								
									if(yoneticiSecim=="1"){
										hesapListesi(createAccObj);
										}
										
									else if(yoneticiSecim=="2"){
										cout<<yonetici;
									}
								
									else{
									
										cout<<"Hatali islem yaptiniz, geri yonlendiriliyorsunuz"<<endl;
										goto yoneticiSecimEkrani;
					
										}
								
								
								
								
								}	

							else {
							
								system("CLS");
    							cout<<"-----------------------"<<endl;
    							cout<<endl<<"Wrong password or name.Program closing for the security reason!"<<endl;
    							return 0;
								
							}
								
							
					
								}//girisSecim 3 finish
				
					
			else if(girisSecim=="4"){
				return 0;
				
			} //girisSecim 4 finish
			
			else{
				cout<<"Hatali tuslama."<<endl; 
			}
			

			whileCondition=0;
				
			cout<<"Programa devam etmek icin -1'i, cikmak icin herhangi bir seyi tuslayiniz."<<endl;
			cin>>whileCondition;
			
	} //while finish

	
} //main finish

void hesapOlustur(vector<Hesap>& newcreateAccObj){ 
		
		string name;
		string password;
		cout<<"-------------------"<<endl;
		cout<<"Enter your surname:"<<endl;
		cin>>name;
		cout<<"-------------------"<<endl;
		cout<<"Enter your password:"<<endl;
		
		cin>>password;
		
		Hesap newAcc(name,password);
		newcreateAccObj.push_back(newAcc);
		cout<<endl;
		
		
}


void hesapListesi(vector<Hesap>& newcreateAccObj){
	
	unsigned int size=newcreateAccObj.size();
	
	for(unsigned int i=0;i<size;i++){
		
		cout<<"Hesap "<<i+1<<endl;
		cout<<"-----------"<<endl;
		cout<<newcreateAccObj[i].getId()<<endl;
        cout<<newcreateAccObj[i].getName()<<endl;
		cout<<endl;
		
	}
	
}
			
bool hesapLogin(vector<Hesap>& newcreateAccObj){ 


    
    
	bool k=false;
	string name,password;
	cout<<"-----------------------"<<endl;
    cout<<"Please enter your surname: "<<endl;
    cin>>name;
    cout<<"-----------------------"<<endl;
    cout<<"Please enter your password"<<endl;
    cin>>password;
    
    
    unsigned int size=newcreateAccObj.size();
    
    for(unsigned int i=0;i<size;i++){
    	
    		string checkpw=newcreateAccObj[i].getPassword();
    		string checkname=newcreateAccObj[i].getName();
    	
    		
    		if(checkname==name && checkpw==password ){
    			k=true;
    			cout<<"--------------------------------------------------------------"<<endl;
    			cout<<"Please remind this security pin for security reasons: "<<i<<endl;
    			return k;
    			
			}
			
		} 
		
		return k;
		
}

int hesapIndexCheckForGetName(vector<Hesap>& newcreateAccObj){
			
			int number;
			cout<<"-----------------------"<<endl;
    		cout<<"Please enter the security pin "<<endl;
    		cin>>number;
    		return number;

		
}



	



