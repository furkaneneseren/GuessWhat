#include <iostream>
#include <random>                   
#include <string>
#include <vector>                   
#include <set>                      
#include <fstream>                  
#include <ctime>
using namespace std;

int kontrolBloklari = 0;            

class Kelimeler{
    private:
        string gizliKelime;         
        int tahminSayisi;
        bool hileKodu;

    
    int eslesenHarfSayisi(string kelime){
        int eslesenHarf = 0;
        kontrolBloklari++;
        //cout << kontrolBloklari;
        for(int i=0;i<gizliKelime.length();i++){
            for(int j=0;j<kelime.length();j++){
                if(gizliKelime[i] == kelime[j]){
                    eslesenHarf++;
                    break;          
                }
            }
        }
        //cout << kontrolBloklari;
        return eslesenHarf;
    }

    int yeridogruHarfSayisi(string kelime){
        int eslesen = 0;
        kontrolBloklari++;

        for(int i=0; i<kelime.length(); i++){
            char kelimeHarf = kelime[i];
            kontrolBloklari++;
            char gizliKelimeHarf = gizliKelime[i];

            if(gizliKelimeHarf == kelimeHarf)
                eslesen++;
        }
        kontrolBloklari++;
        return eslesen;
    }

public:
    Kelimeler(){
    gizliKelime = "";
    kontrolBloklari++;
    tahminSayisi = 0;
    hileKodu = false;
    //cout << kontrolBloklari;
    };

    void oyunBasla(){
        kontrolBloklari++;
        cout<<"BilBakalim'a hosgeldiniz"<<endl;
        Sozluk sozluk("words.txt");
        cout<<"Bes harften olusan kelime tuttum"<<endl;
        string tahmin;
        cout<<"Klavyeden tahmininizi giriniz ve enter'a basiniz: ";
        cin>>tahmin;
        kontrolBloklari++;
        gizliKelime = sozluk.dogruKelimeSec();
        //cout << kontrolBloklari;
        
        while(eslesenHarfSayisi(tahmin) != gizliKelime.length()){
            bool dogruInput=true;
            for(int i=0; i<tahmin.length()-1; i++){
                kontrolBloklari++;
                for(int j = i + 1; j<tahmin.length(); j++){
                    if(tahmin[i]==tahmin[j])
                        dogruInput = false;
                }
            } 
            //cout << kontrolBloklari;
            if(dogruInput == false && tahmin != "xxxxx"){
                if(tahmin.length() != 5){
                    kontrolBloklari++;
                    cout<<"Tahmininiz bes karakter olmalidir"<<endl;
                    tahminSayisi++;
                }
                else if(sozluk.kelimeler.find(tahmin) == sozluk.kelimeler.end()){
                    kontrolBloklari++;
                    cout<<"Sozlukte boyle bir kelime yok"<<endl;
                    tahminSayisi += 1;
                }
                else{
                    tahminSayisi++;
                    int eslesenHarf = 0;
                    set<char> letters;
                    kontrolBloklari++;
                    for(int i=0;i<gizliKelime.length();i++){
                        for(int j=0;j<tahmin.length();j++){
                            if(gizliKelime[j] == tahmin[i]){
                                if(!(letters.find(tahmin[i]) != letters.end())){
                                    eslesenHarf += 1;
                                }
                            letters.insert(tahmin[i]);
                            break; 
                            }
                        }
                    
                    }
                    cout<<"Tahmin ile eslesen harf sayisi: "<<eslesenHarf<<endl;
                    //cout << kontrolBloklari;
                    cout<<"Tahmin ile eslesen harflerin dogru konumu: "<<yeridogruHarfSayisi(tahmin)<<endl;
                }
                cout<<"Klavyeden tahmininizi giriniz ve enter'a basiniz: ";
                kontrolBloklari++;
                cin>>tahmin;
                //cout << kontrolBloklari;
            }

            else{
                if(tahmin.length() != 5){
                    kontrolBloklari++;
                    //cout << kontrolBloklari;
                    cout<<"Tahmininiz bes karakter olmalidir"<<endl;
                }
                else{
                    if(tahmin == "xxxxx"){
                        cout << "Ipucu, tuttugum gizli kelime: " << gizliKelime << endl;
                        kontrolBloklari++;
                        tahminSayisi++;
                        hileKodu = true;
                    }
                    else if(sozluk.kelimeler.find(tahmin) == sozluk.kelimeler.end()){
                        kontrolBloklari++;
                        cout<<"Sozlukte boyle bir kelime yok"<<endl;
                        tahminSayisi++;
                    }
                    else{
                        int eslesenHarfler = eslesenHarfSayisi(tahmin);
                        cout<<"Tahmin ile eslesen harf sayisi: "<<eslesenHarfler<<endl;
                        if(eslesenHarfler > 0){
                            kontrolBloklari++;
                            cout<<"Tahmin ile eslesen harflerin dogru konumu: "<<yeridogruHarfSayisi(tahmin)<<endl;
                        }
                        kontrolBloklari++;
                        tahminSayisi++;
                    }
                }
                //cout << kontrolBloklari;
                cout<<"Klavyeden tahmininizi giriniz ve enter'a basiniz: ";
                kontrolBloklari++;
                cin>>tahmin;
            }
        }
        kontrolBloklari++;
        //cout << kontrolBloklari;
        tahminSayisi++;
        if(hileKodu == true)
            cout<<"Tebrikler! "<<tahminSayisi<<" tahminde ipucu kullanarak kelimeyi buldunuz!"<<endl;
        else
            cout<<"Tebrikler! "<<tahminSayisi<<" tahminde kelimeyi buldunuz!"<<endl;
    }

    class Sozluk{
    public:
        set<string> kelimeler;
        vector<string> gizliKelimeler;
        Sozluk(){};

        Sozluk(string dosyaAdi){
            ifstream dosya;
            kontrolBloklari++;
            dosya.open(dosyaAdi);
            string satir;
            kontrolBloklari++;
            while(getline(dosya , satir)){
                kelimeler.insert(satir);
                kontrolBloklari++;
            }
            set<string>::iterator i;
            kontrolBloklari++;
            for(i=kelimeler.begin();i!=kelimeler.end();i++){
                kontrolBloklari++;
                string kelime = *i;
                //cout << kontrolBloklari;
                if(kelime.length() == 5){
                    kontrolBloklari++;
                    gizliKelimeler.push_back(kelime);
                }
            }
        }

        string dogruKelimeSec(){
            kontrolBloklari++;
            int rastgeleSayi = (rand() % (gizliKelimeler.size() - 0 + 1));
            kontrolBloklari++;
            string kelime = gizliKelimeler[rastgeleSayi];
            //cout << kontrolBloklari;
            while(!kelimeUygunlugu(kelime)){
                rastgeleSayi = (rand() % ((gizliKelimeler.size()-1) + 1)) + 0;
                kontrolBloklari++;
                kelime = gizliKelimeler[rastgeleSayi];
                //cout << kontrolBloklari;
            }
            kontrolBloklari++;
            //cout << kontrolBloklari;
            return kelime;
        }

        bool kelimeUygunlugu(string kelime){
            kontrolBloklari++;
            for(int i=0; i<kelime.length()-1; i++){
                kontrolBloklari++;
                //cout << kontrolBloklari;
                for(int j = i + 1; j<kelime.length(); j++){
                    //cout << kontrolBloklari;
                    if(kelime[i]==kelime[j])
                        return false;
                }
            }
            return true;
        }
        ~Sozluk(){};
    };
    ~Kelimeler(){};
};

int main(){
    Kelimeler oyun;
    srand ( time(NULL) );
    oyun.oyunBasla();
    kontrolBloklari++;
    //cout << kontrolBloklari;
}