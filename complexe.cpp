#include "complexe.h"
#include <iostream>
#include <math.h>
using namespace std;

///////////INITIALIZARE///////////
complexe::complexe()
{
    re = 0;
    im = 0;
}


///////////MODIFICARE DOAR PARTE REALA///////////
complexe::complexe(double x)
{
    re = x;
    im = 0;
}


///////////MODIFICARE AMBELE PARTI///////////
complexe::complexe(double x, double y)
{
    re = x;
    im = y;
}

///////////COPIERE///////////
complexe::complexe(const complexe &x)
{
    re = x.re;
    im = x.im;
}

///////////FURNIZARE NUMAR REAL///////////
int complexe::get_re()
{
    return re;
}

///////////FURNIZARE NUMAR IMAGINAR///////////
int complexe::get_im()
{
    return im;
}

///////////SETEAZA NUMARUL REAL///////////
void complexe::set_re(double x)
{
    re = x;
}

///////////SETEAZA NUMARUL IMAGINAR///////////
void complexe::set_im(double x)
{
    im = x;
}

///////////AICI E CITIREA IN FUNCTIE DE NUMARUL IMAGINAR PENTRU O AFISARE MAI FRUMOASA///////////
void complexe::citire()
{
    if(im<0)
        cout << get_re() << "" << get_im() << "i" << endl;
    else if(im==0)
        cout << get_re() << endl;
    else
        cout << get_re() << "+" << get_im() << "i" << endl;
}

///////////OPERATIA DE ADUNARE PRIN SUPRAINCARCARE///////////
complexe complexe::operator +(complexe y)
{
    complexe R;
    R.re = re + y.re;
    R.im = im + y.im;

    return R;
}

///////////OPERATIA DE SCADERE PRIN SUPRAINCARCARE///////////
complexe complexe::operator -(complexe y)
{
    complexe R;
    R.re = re - y.re;
    R.im = im - y.im;

    return R;
}

///////////OPERATIA DE INMULTIRE PRIN SUPRAINCARCARE///////////
complexe complexe::operator *(complexe y)
{
    complexe R;
    R.re = re * y.re - im * y.im;
    R.im = re * y.im + y.re * im;

    return R;
}

///////////OPERATIA DE IMPARTIRE PRIN SUPRAINCARCARE + CAZUL SPECIAL DE IMPARTIRE LA 0///////////
complexe complexe::operator /(complexe y)
{
    complexe R;
    if(y.re==0 && y.im==0)
    {
        cout << "Ai impartit numarul la 0. ";
    }
    else
    {
        R.re = (re * y.re + im + y.im) / (y.re * y.re + y.im * y.im);
        R.im = (y.re * im - re * y.im) / (y.re * y.re + y.im * y.im);
    }

    return R;
}

///////////CONJUGATUL UNUI NUMAR///////////
complexe complexe::conjugatul()
{
    complexe R;
    R.im = im;
    R.re = re;
    R.im *= -1;

    return R;
}

///////////MODULUL UNUI NUMAR///////////
int complexe::modulul()
{
    return sqrt(re * re + im * im);
}


///////////AICI E AFISAREA///////////
ostream & operator << (ostream &out, complexe &Z)
{
    if (Z.get_re() != 0)
        out << Z.re << "*a ";
    if (Z.get_im() != 0)
        out << Z.im << "*b";
    out << endl;
    return out;
}

///////////AICI E CITIREA///////////
istream & operator >> (istream &in, complexe &Z)
{
    double a, b;
    in >> a;
    in >> b;

    Z.set_re(a);
    Z.set_im(b);
    return in;
}

///////////INTERFATA///////////
void complexe::interfata()
{
    complexe X, Y, Z;
    cout << "Scrieti datele primului numar complex: ";
    cin >> X;
    cout << endl;

    cout << "Scrieti datele pentru al doilea numar complex: ";
    cin >> Y;
    cout << endl;

    //adunare
    cout << "Adunarea numerelor este: ";
    Z = X + Y;
    Z.citire();
    //scadere
    cout << "Scaderea numerelor este: ";
    Z = X - Y;
    Z.citire();
    //inmultire
    cout << "Inmultirea numerelor este: ";
    Z = X * Y;
    Z.citire();
    //impartire
    cout << "Impartirea numerelor este: ";
    Z = X / Y;
    Z.citire();
    //conjugatul
    cout << "Primul conjugat: ";
    Z = X.conjugatul();
    Z.citire();
    cout << "Al doilea conjugat: ";
    Z = Y.conjugatul();
    Z.citire();
    //modulul
    cout << "Primul modul: ";
    Z = X.modulul();
    Z.citire();
    cout << "Al doilea modul: ";
    Z = Y.modulul();
    Z.citire();

}

complexe::~complexe()
{
    //destructor
}
