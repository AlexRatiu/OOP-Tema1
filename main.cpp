#include <iostream>
using namespace  std;
class Matrice
{
private:
    int nrLinii,nrColoane,el;
    int **m = new int*[20];

public:
    Matrice(int nrLinii, int nrColoane,int x)
    {
        this->nrLinii = nrLinii;
        this->nrColoane = nrColoane;
        el=x;
        for (int i = 0; i < nrLinii; ++i)
            m[i] = new int[nrColoane];
        for(int i = 0; i<nrLinii; i++)
            for(int j = 0; j<nrColoane; j++)
                m[i][j] = x;
    }

    Matrice()
    {
        this->nrLinii = 1;
        this->nrColoane = 1;
        this->el = 1;
        for (int i = 0; i < nrLinii; ++i)
            m[i] = new int[nrColoane];
        for(int i = 0; i<nrLinii; i++)
            for(int j = 0; j<nrColoane; j++)
                m[i][j] = 1;
    }

    Matrice(const Matrice &rhs)
    {
        nrLinii = rhs.nrLinii;
        nrColoane = rhs.nrColoane;
        el=rhs.el;
        for(int i= 0; i<nrLinii; i++)
            for(int j= 0; j<nrColoane; j++)
                m[i][j] = rhs.m[i][j];
    }


     [[maybe_unused]] int getNrlinii() const
    {
        return  nrLinii;
    }

    [[maybe_unused]] void setNrLinii(int _nrLinii)
    {
        if(nrLinii>=1 && nrLinii<=20)
            nrLinii = _nrLinii;
        else
        {
            cout<<"Datele nu au fost introduse corect. Numarul de linii trebuie sa fie cuprins intre 1 si 20";
            return;
        }
    }

    [[maybe_unused]] int getNrColoane() const
    {
        return  nrColoane;
    }

    [[maybe_unused]] void setNrColoane(int _nrColoane)
    {
        if(nrColoane>=1 && nrColoane<=20)
            nrColoane = _nrColoane;
        else
        {
            cout<<"Datele nu au fost introduse corect. Numarul de coloane trebuie sa fie cuprins intre 1 si 20";
            return;
        }
    }

    Matrice& operator=(const Matrice& rhs)
    {
        nrLinii = rhs.nrLinii;
        nrColoane = rhs.nrColoane;
        el = rhs.el;
        for(int i= 0; i<nrLinii; i++)
            for(int j= 0; j<nrColoane; j++)
                m[i][j] = rhs.m[i][j];
        return *this;
    }

    friend ostream & operator<<(ostream &oStream, const Matrice &rhs)
    {
        oStream <<"Matricea rezultata este: "<<endl;
        rhs.Afisare();
        return oStream;
    }

    friend istream &operator>>(istream& iStream, Matrice& mat)
    {
        cout<<"Numarul de linii: ";
        iStream>>mat.nrLinii;
        cout<<endl;

        cout<<"Numarul de coloane: ";
        iStream>>mat.nrColoane;
        cout<<endl;

        cout<<"Citeste elementul matricei: ";
        iStream>>mat.el;
        cout<<endl;

        for(int i = 0; i<mat.nrLinii; i++)
            for (int j = 0; j < mat.nrColoane; j++)
            {
                mat.m[i][j]=mat.el;
            }
        return iStream;
    }

    Matrice operator+(const Matrice &rhs)
    {
        int S= this->m[0][0]+ rhs.m[0][0];
        return  Matrice(nrLinii,nrColoane,S);
    }

    Matrice operator-(const Matrice &rhs)
    {
        int D= this->m[0][0]- rhs.m[0][0];
        return  Matrice(nrLinii,nrColoane,D);
    }

    void Afisare() const
    {
        for(int i = 0; i<nrLinii; i++)
        {
            for(int j = 0; j<nrColoane; j++)
                cout<<m[i][j]<<" ";
            cout<<endl;
        }

    }

    ~Matrice()
    {
        for(int i = 0; i<nrLinii; i++)
            delete [] m[i];
        delete []m;
    }

};
int main()
{
    char a = '*';
    cout<<"Ce operatie doriti sa efectuati?(+/-): ";
    cin>>a;
    cout<<endl;

    Matrice m1 =  Matrice(20,20,3);
    Matrice m2 =  Matrice(20,20,3);
    cin>>m1;
    cin>>m2;
    Matrice m3 =  Matrice(20,20,3);
    m3.setNrLinii(3);
    m3.setNrColoane(3);
    switch(a)
    {
    case '+' :
    {
        Matrice m3 = m1 + m2;
        cout<<m3;
        break;
    }
    case '-' :
    {
        Matrice m4 = m1 - m2;
        cout<<m4;
        break;
    }
    default:
        cout<<"EXIT";
    }


    return 0;
}
