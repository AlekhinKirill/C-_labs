#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Введите номер упражнения" << endl;
    int num;
    cin >> num;
    if (num == 1)
    {
        cout << "Введите катеты" << endl;
        float a, b, c;
        cin >> a;
        cin >> b;
        c = pow(pow(a, 2) + pow(b, 2), 0.5);
        cout << "Гипотенуза = " << c << endl;
    }
    else
    {
        int N, i, j;
        cout << "Введите N" << endl;
        cin >> N;
        for (j = 1; j <= N; j++)
        {
            if (num == 2)
            {
                for (j = 1; j <= N; j++)
                {
                    for (i = 1; i <= N; i++)
                    {
                        cout << "*";
                    }
                    cout << endl;
                }
            }
            if (num == 3)
                for (j = 1; j <= N; j++)
                {
                    {
                        for (i = 1; i <= N; i++)
                            if (i <= j)
                            {
                                cout << "*";
                            }
                        cout << endl;
                    }
                }
            if (num == 4)
                for (j = 1; j <= N; j++)
                {
                    {
                        for (i = 1; i <= N; i++)
                            if (i >= j)
                            {
                                cout << "*";
                            }
                        cout << endl;
                    }
                }
            if (num == 5)
                for (j = 1; j <= N; j++)
                {
                    {
                        for (i = 1; i <= N - j + 1; i++)
                            if (i < j)
                            {
                                cout << " ";
                            }
                            else
                            {
                                cout << "*";
                            }
                        cout << endl;
                    }
                }
        }
    }
}
