#include <bits/stdc++.h>

using namespace std;

vector <int> v;
vector <int> rozlozone[207];

bool comp(int a, int b)
{
    return a > b;
}

int gcd(int a, int b)
{
    while (a > 0)
    {
        int x = a;
        a = b % a;
        b = x;
    }
    return b;
}

int policz()
{
    //sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j && gcd(v[i], v[j]) != 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            return v[i];
    }
}

vector <int> rozloz_liczbe(int a)
{
    vector <int> ans;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            ans.push_back(i);
    }
    return ans;
}

int policz2()
{
    for (int i = 0; i < v.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < v.size(); j++)
        {
            for (int a = 0; a < rozlozone[i].size(); a++)
            {
                for (int b = 0; b < rozlozone[j].size(); b++)
                {
                    if (i != j && rozlozone[i][a] == rozlozone[j][b])
                    {
                        ok = false;
                    }
                }
            }
        }
        if (ok)
            return v[i];
    }
}

int main()
{
    ifstream in("liczby.txt");
    int a;
    while (in >> a) {
        v.push_back(a);
    }
    sort(v.begin(), v.end(), comp);
	cout << "Policz: " << policz() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        rozlozone[i] = rozloz_liczbe(v[i]);
    }
    cout << "Policz2: " << policz2();

    return 0;
}
