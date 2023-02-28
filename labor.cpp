#include "Header.h"

struct student{
    string name, sname;
    double mark;
    double markmed;
};

void input(student &temp){

    
    int x = 0, egz = 0, kiek;//k-kiek pazymiu is viso, x-pazymio vieta
    double sum = 0;
    int *a=new int [1];
    char NewMark = 't', ap = 't';
    cout<<"Iveskite studento varda: "; cin>>temp.name;
    cout<<"Iveskite studento pavarde: "; cin>>temp.sname;

    cout<<"Ar norite atsitiktiniu pazymiu? t/n";cin>>ap;
    if(ap == 't'){
        cout<<"Kiek pazymiu generuoti?";cin>>kiek;
        for(int i=0; i<kiek; i++){
         a[i]= rand()%10;
         sum+=a[i];
         x++;  
        }
    }
   
    else while(NewMark == 't'){
        cout<<"Iveskite pazymi: "; cin>>a[x];
        sum+=a[x];
        x++;
        cout<<"Ar vesite dar viena pazymi? t/n: "; cin>>NewMark;
        if(NewMark == 'n') break;
    }
    cout<<"Iveskite egzamino pazymi: "; cin>>egz;
    
    temp.mark = (sum/x) * 0.4 + 0.6 * egz;
    
    if (x % 2 != 0)                        //galutinis med
        temp.markmed = ((a[x / 2 + 1]) * 0.4) + (0.6 * egz);
    else
        temp.markmed =  ((a[x / 2 - 1] + a[x / 2]) / 2) * 0.4 + 0.6 * egz;
    
    delete[] a;

};

int main(){
    
    char NewStudent = 't';
    int nr = 0;
    char vm;
    student *arr;
    arr=new student [nr];
    
    while(NewStudent == 't'){
        cout<<"Ar ivesite studenta? t/n: "; cin>>NewStudent;
        if(NewStudent == 'n') break;
        input(arr[nr]);
        nr++;
    };
    
    cout << "vidurkis ar mediana? v/m "; cin>>vm;
    
        if (vm == 'v'){
            cout<< "Vardas        Pavarde           Galutinis (Vid.)" <<endl;
            cout << "________________________________________________" << endl;
            for(int i=0; i<=nr;i++)
                cout<<fixed<<left<<setw(12)<<arr[i].name<<setw(12)<<arr[i].sname<<setprecision(2)<<arr[i].mark<<endl;
        }
        else {
            cout<< "Vardas        Pavarde           Galutinis (Med.)" <<endl;
            cout << "________________________________________________" << endl;
            for(int i=0; i<=nr;i++)
                cout<<fixed<<left<<setw(12)<<arr[i].name<<setw(12)<<arr[i].sname<<setprecision(2)<<arr[i].markmed<<endl;
    
    };
delete[] arr;
   
}

