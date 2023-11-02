#include<iostream>
#include<cmath>
float pi = 3.14159;
using namespace std;
class Fiberoptics {
    float n1, n2;
    int flag = 1;

public:
    void get() {
        while (flag) {
            try {
                cout << "\nEnter value of refractive index of core:";
                cin >> n1;
                if (n1 <= 0) {
                    throw 0;
                }
                cout << "\nEnter value of refractive index of cladding:";
                cin >> n2;
                if (n2 <= 0) {
                    throw 0;
                }
                if (n1 < n2) {
                    throw 0;
                }
                else {
                    flag = 0;
                }
            }
            catch (int) {
                cout << "\nWrong input!\n";
                fflush(stdin);
                cin.clear();
                reset();
            }
        }
    }

    void reset() {
        flag = 1;
    }



     //To calculate numerical aperture , i.e.; light gathering capacity of fiber.
    void NA(){
        cout<<"\nLet the outside ambient medium be air";
        float na=sqrt(n1*n1-n2*n2);
        cout<<"\nThe numerical aperture of the given fiber is :"<<na;
    }
    //To calculate relative refractive index and percentage relative refractive index of fiber. 
    void RRI(){
            float rr=(n1-n2)/n1;
            cout<<"\nThe relative refractive index of the given medium is:"<<rr;
            cout<<"\nThe percentage relative refractive index of the given fiber is:"<<rr*100<<"%";
    }
//To calculate the angle of acceptance of an optical fiber cable
    void AA(){
        if((n1*n1-n2*n2)>1){
            cout<<"\nThis configuration is not possible";
        }
        cout<<"\nLet the outside ambient medium be air";
        float a=asin(sqrt(n1*n1-n2*n2));
        cout<<"\nThe acceptance of given fiber is "<<a*180/pi<<" degrees";
    }

    //To calculate the V number and possible number of modes of optical fiber.
    void VM(){
        cout<<"\nLet the outside ambient medium be air and the given fiber is step index fiber";
        float d,w;
        flag=1;
        while(flag){
            cout<<"\nEnter diameter of fiber and wavelength of incident light in same units:";
            try{
                cin>>d>>w;
                if(d<=0||w<=0){
                    throw 0;
                    }
                else{
                    flag=0;
                }
                float v=(pi*d*sqrt(n1*n1-n2*n2))/w;
                cout<<"\nThe V number of the given fiber is:"<<v;
                if(v>2.405){
                    cout<<"\nAs V number is greater than 2.405 so, the given fiber is multimode fiber";
                }
                else{
                    cout<<"\nAs V number is <= 2.405 so, the given fiber is stepindex fiber";
                }
                cout<<"\nNumber of modes possible by the given fiber is:"<<floor(v*v/2);
            }
            catch(int){
                cout<<"\nWrong input!\n";
                cin.clear();
                fflush(stdin);
            }

        }

    }
    //To calculate the attenuation losses (attenuation coeficient in dB/Km)
    void ACa(){
    float po,pi,l;
    float a;
    int flag=1;
    while(flag){
        try{
            cout<<"\nFor Attenuation Coefficient"<<endl;
            cout<<"\nEnter the output power(in W):";
            cin>>po;
            if(po<0){
                throw 0;
            }
            cout<<"\nEnter the input power(in W):";
            cin>>pi;
            if(pi<0){
                throw 0;
            }
            if(pi<po){
                throw 0;
            }
            cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
            cin>>l;
            if(l<0){
                throw 0;
            }
            else{
                flag=0;
            }
            float k=po/pi;
            a=-(10/l)*(log10(k));
            cout<<"\nThe attenuation coefficient of fiber (in dB/km) is: "<<a<<"dB/km";
        }
        catch(int){
            cout<<"\nWrong input!"<<endl;
            fflush(stdin);
            cin.clear();
        }
    }
}
//To calculate the output power of an optical fiber after reduction of losses in inputted power in optical fiber
void ACpo(){
    float po,pi,l;
    float a;
    int flag=1;
    while(flag){
        try{
            cout<<"\nFor Output Power:-"<<endl;
            cout<<"\nEnter the value of attenuation coefficient (dB/km):";
            cin>>a;
            if(a<0){
                throw 0;
            }
            cout<<"\nEnter the input power(in W):";
            cin>>pi;
            if(pi<0){
                throw 0;
            }
            cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
            cin>>l;
            if(l<0){
                throw 0;
            }
            else{
                flag=0;
            }
            float k=-(a*l)/10;
            float x=pow(10,k);
            po=pi*x;
            cout<<"\nThe output power here is: "<<po<<" W";
        }
        catch(int){
            cout<<"\nWrong input!\n";
            fflush(stdin);
            cin.clear();
        }
    }
    
}
//To calculate the inputted  power of an optical fiber if attenuation losses and output power is known to us.
void ACpi(){
    float po,pi,l;
    float a;
    int flag=1;
    while(flag){
        try{
            cout<<"\nFor Input Power:-"<<endl;
            cout<<"\nEnter the value of attenuation (dB/km):";
            cin>>a;
            if(a<0){
                throw 0;
            }
            cout<<"\nEnter the output power(in W):";
            cin>>po;
            if(po<0){
                throw 0;
            }
            cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
            cin>>l;
            if(l<0){
                throw 0;
            }
            else{
                flag=0;
            }
            float k=-(a*l)/10;
            float x=pow(10,k);
            pi=po/x;
            cout<<"\nThe input power here is: "<<pi<<" W";
        }
        catch(int){
            cout<<"\nWrong input!\n";
            cin.clear();
            fflush(stdin);
        }
    }
}
//To calculate the length of optical fiber if output , input power and attenuation losses are known to us.
void ACl(){
    float po,pi,l;
    float a;
    int flag=1;
    while(flag){
        try{
            cout<<"\nFor Length of Fiber"<<endl;
            cout<<"\nEnter the output power(in W):";
            cin>>po;
            if(po<0){
                throw 0;
            }
            cout<<"\nEnter the input power(in W):";
            cin>>pi;
            if(pi<0){
                throw 0;
            }
            cout<<"\nEnter the attenuation coefficient(in dB/km):";
            cin>>a;
            if(a<0){
                throw 0;
            }
            else{
                flag=0;
            }
            float k=po/pi;
            l=-(10/a)*(log10(k));
            cout<<"\nThe length of fiber is: "<<l<<"km";
        }
        catch(int){
            cout<<"\nWrong input!\n";
            cin.clear();
            fflush(stdin);
        }
    }

}
//To calculate the numerical aperture of graded index fiber.
void GRIN(){
    float a,r;
    flag=1;
    while(flag){
        try{
            cout<<"\nEnter the value of core radius:";
            cin>>a;
            if(a<0){
                throw 0;
            }
            cout<<"\nEnter the value of position across core:";
            cin>>r;
            if(r>2*a||r<0){
                throw 0;
            }
            else{
                flag=0;
            }
            float rr=(n1-n2)/n1;
            //cout<<"\nIn the graded index fiber , the numerical aperture is a function of position across the core(r)";
            if(r<a){
                float var=r/a;
                if((2*rr*pow(var,2)>1)){
                    throw 0;
                }
                else{
                    flag=0;
                }
                float g1=n1*sqrt(1-2*rr*pow(var,2));
                cout<<"\nThe numerical aperture of the graded index fibre will be: "<<g1<<endl;
            }
            else{
                if((2*rr)>1){
                throw 0;
                }
                else{
                    flag=0;
                }
            float g=n1*sqrt(1-2*rr);
            cout<<"\nThe numerical aperture of the graded index fibre will be: "<<g<<endl;
            }
        }
        catch(int){
            cout<<"\nWrong input!\n";
            cin.clear();
            fflush(stdin);     
        }
    }

}
//To calculate the critical radius of a given optical fiber cable on particular operating wavelength.
void CR(){
    int mode;
    float critical_radius,g,l,lc,d;
    int flag=1;
    while(flag){
        try{
            cout<<"Enter the value for diameter index of core in centi-meters:"<<endl;
            cin>>d;//d:diameter of core
            if(d<0){
                throw;
            }
            cout<<"\nEnter the value for operating wavelength:"<<endl;
            cin>>l;
            if(l<0){
                throw 0;
            }
            cout<<"\nEnter 0 for single-mode optical fibre and 1 for multi-mode optical fiber"<<endl;
            cin>>mode;
            if(mode!=0 && mode!=1){
                throw 0;
            }
            else{
                flag=0;
            }
            if(mode==1){
                g=pow(n1,2)-pow(n2,2);
                critical_radius=(3*pow(n1,2)*l)/(4*3.14*pow(g,1.5));//----------->l:operating wavelength
                cout<<"\ncritical radius of your multimode fiber is:"<<critical_radius<<" "<<"centi-meters"<<endl;
                }
            else{   
                g=pow(n1,2)-pow(n2,2);
                lc=3.14*d*pow(g,0.5)/2.405;//lc:cut-off wavelength
                critical_radius=((20*l)/g)*pow((((2.748)*lc-0.996*g)/lc),-3);
                cout<<"critical radius of your singlemode fiber is:"<<critical_radius<<" "<<"centi-meters"<<endl;
            }
        }
        catch(int){
            cout<<"\nWrong input!\n";
            cin.clear();
            fflush(stdin);       
        }
    }
}
};
int main(){ 
Fiberoptics F;
int x;
int choice;
int flag=1;
while(flag){
    try{
        cout<<"\n\n1:For Fiberoptics calculation\n2:Exit\n\nEnter choice:";
        cin>>x;
        cout<<"\n__________________________________________________________________________________________________________________\n";
        if(x==1){
            cout<<"\n\n1:For Numerical Aperture \n2: For Relative refractive index:\n3:For acceptance angle \n4:For V number and Number of modes \n5:For Attenuation Coefficient \n6:For Output Power\n7:For Input Power\n8:For Length of Fiber\n9:For Numerical Aperture of graded index fiber\n10:For Critical radius\n\nEnter choice:";
            cin>>choice;
            switch(choice){
                case 1:
                    F.get();
                    F.NA();
                    F.reset();
                    break;
                case 2:
                    F.get();
                    F.RRI();
                    F.reset();                    
                    break;
                case 3:
                    F.get();
                    F.AA();
                    F.reset();                    
                    break;
                case 4:
                    F.get();
                    F.VM();
                    F.reset();
                    break;
                case 5:
                    F.ACa();
                    break;
                case 6:
                    F.ACpo();
                    break;
                case 7:
                    F.ACpi();
                    break;
                case 8:
                    F.ACl();
                    break;
                case 9:
                    F.get();
                    F.GRIN();
                    break;
                case 10:
                    F.get();
                    F.CR();
                    break;
                default:
                    throw 0;
                    break; 
                }
        }
                
        else if(x==2){
            cout<<"*************************Program exit successfully**************************";
            cout<<"\n__________________________________________________________________________________________________________________\n";
            break;
        }
        else{
            throw 0;
        }
        }
        catch(int){
        }
    }
return 0;
}