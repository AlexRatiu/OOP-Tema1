#include <iostream>
using namespace  std;
class Matrice
{
private:
    int nrLinii,nrColoane;
    int **m = new int*[20];

public:
    Matrice(int nrLinii, int nrColoane,int x)
    {
        this->nrLinii = nrLinii;
        this->nrColoane = nrColoane;
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

    Matrice& operator=( Matrice const &rhs)
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

    Matrice operator+( Matrice const &rhs)
    {
        int S= m[0][0]+ rhs.m[0][0];
        return  Matrice(nrLinii,nrColoane,S);
    }

    Matrice operator-( Matrice const &rhs)
    {
        int D= m[0][0]- rhs.m[0][0];
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
    int n,m,x,y,a;
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
    cout<<"Ce operatie doriti sa efectuati?(+/-): ";
    cin>>a;
    cout<<endl;

    Matrice m1 =  Matrice(n,m,x);
    Matrice m2 =  Matrice(n,m,y);
    switch(a)
    {
    case 1 :
    {
        Matrice m3 = Matrice(n,m,0);
        m3 = m1 + m2;
        cout<<m3;
        break;
    }
    case 0 :
    {
        Matrice m3 = Matrice(n,m,0);
        m3 = m1 - m2;
        cout<<m3;
        break;
    }
    }


    return 0;
}
