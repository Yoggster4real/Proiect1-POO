#ifndef COMPLEXE_H
#define COMPLEXE_H
#include <iostream>

using namespace std;

class complexe
{
    double re, im;
public:
    ////////CONSTRUCTORI//////////
    complexe ();
    complexe (double x);
    complexe (double x, double y);
    complexe (const complexe &x);

    ///////GETTER SI SETTER///////
    int get_re ();
    int get_im ();
    void set_re (double x);
    void set_im (double x);

    ///////////CITIRE/////////////
    void citire ();

    ///////////OPERATII///////////
    complexe operator + (complexe y);
    complexe operator - (complexe y);
    complexe operator * (complexe y);
    complexe operator / (complexe y);
    complexe operator = (complexe y);
    complexe conjugatul ();
    int modulul ();
    friend ostream& operator << (ostream &, complexe &);
    friend istream& operator >> (istream &, complexe &);

    ///////////PROGRAM DE AFISARE A OPERATIILOR///////////
    void interfata ();

    ///////////DESTRUCTOR///////////
    virtual ~complexe ();
};

class Management
{
    int n;
    complexe obs[100];

public :

    Management (const Management &x);
    Management operator = (Management y);
    friend ostream& operator << (ostream &, Management &);
    friend istream& operator >> (istream &, Management &);

};


#endif // COMPLEXE_H
