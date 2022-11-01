#include <iostream>
using namespace  std;
class Matrice
{
private:
    int nrLinii,nrColoane;
    int **m = new int*[20];

public:
    Matrice(int _nrLinii, int _nrColoane,int x)
    {
        nrLinii = _nrLinii;
        nrColoane = _nrColoane;
        for (int i = 0; i < _nrLinii; ++i)
            m[i] = new int[_nrColoane];
        for(int i = 0; i<_nrLinii; i++)
            for(int j = 0; j<_nrColoane; j++)
                m[i][j] = x;
    }

    Matrice()
    {
        this->nrLinii = 1;
        this->nrColoane = 1;
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
        for(int i = 0; i<nrLinii; i++)
            delete [] m[i];
        delete []m;

        int **k = new int*[20];
        for (int i = 0; i < nrLinii; ++i)
            k[i] = new int[nrColoane];
        for(int i= 0; i<nrLinii; i++)
            for(int j= 0; j<nrColoane; j++)
                k[i][j] = rhs.m[i][j];
    }

    int getNrlinii() const
    {
        return  nrLinii;
    }

    void setNrLinii(int _nrLinii)
    {
        if(nrLinii>=1 && nrLinii<=20)
            nrLinii = _nrLinii;
        else
        {
            cout<<"Datele nu au fost introduse corect. Numarul de linii trebuie sa fie cuprins intre 1 si 20";
            return;
        }
    }

    int getNrColoane() const
    {
        return  nrColoane;
    }

    void setNrColoane(int nrColoane)
    {
        if(nrColoane>=1 && nrColoane<=20)
            this->nrColoane = nrColoane;
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

    friend istream &operator>>(istream& iStream, Matrice& m)
    {
        cout<<"Numarul de linii: ";
        iStream>>m.nrLinii;
        cout<<endl;

        cout<<"Numarul de coloane: ";
        iStream>>m.nrColoane;
        cout<<endl;

        for(int i = 0; i<m.nrLinii; i++)
            for (int j = 0; j < m.nrColoane; j++)
            {
                iStream >> m.m[i][j];
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
        cout<<"D:"<<endl;
    }

};
int main()
{
    int n,m,x,y;
    cout<<"Introduceti numarul de linii: ";
    cin>>n;
    cout<<endl;
    cout<<"Introduceti numarul de coloane: ";
    cin>>m;
    cout<<endl;
    cout<<"Introduceti valoarea din prima matrice: ";
    cin>>x;
    cout<<endl;
    cout<<"Introduceti valoarea din a doua matrice: ";
    cin>>y;
    cout<<endl;

    char a;

    Matrice m1 =  Matrice(n,m,x);
    Matrice m2 =  Matrice(n,m,y);
    cout<<"Ce operatie doriti sa efectuati?(+/-): ";
    cin>>a;
    cout<<endl;
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
    }


    return 0;
}
