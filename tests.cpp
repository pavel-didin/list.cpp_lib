#include <iostream>
#include "list.cpp"

using namespace std;

int main()
{
    List<int>* L = new List<int>;

    try
    {
        L->Insert(1, 7);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_1\t->\tPASSED" << endl;
        else
            cout << "Test_1\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_1\t->\tFAILED" << endl;
    }

    try
    {
        L->Delete(1);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_2\t->\tPASSED" << endl;
        else
            cout << "Test_2\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_2\t->\tFAILED" << endl;
    }

    try
    {
        L->DeleteFirst();
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_3\t->\tPASSED" << endl;
        else
            cout << "Test_3\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_3\t->\tFAILED" << endl;
    }

    try
    {
        L->DeleteLast();
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_4\t->\tPASSED" << endl;
        else
            cout << "Test_4\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_4\t->\tFAILED" << endl;
    }

    try
    {
        L->GetNode(0);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_5\t->\tPASSED" << endl;
        else
            cout << "Test_5\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_5\t->\tFAILED" << endl;
    }

    try
    {
        L->SetNode(0, 4);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_6\t->\tPASSED" << endl;
        else
            cout << "Test_6\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_6\t->\tFAILED" << endl;
    }

    const int n = 10;
    int a[n] = {0,1,2,3,4,5,6,7,8,9};

    for(unsigned i = 0; i < n; i++)
        if(i % 2 == 0)
        {
            try
            {
                L->AddHead(a[i]);
            }
            catch (...)
            {
                cout << "Test_" << 7+i << "\t->\tFAILED" << endl;
            }
            cout << "Test_" << 7+i << "\t->\tPASSED" << endl;
        }
        else
        {
            try
            {
                L->AddTail(a[i]);
            }
            catch (...)
            {
                cout << "Test_" << 7+i << "\t->\tFAILED" << endl;
            }
            cout << "Test_" << 7+i << "\t->\tPASSED" << endl;
        }

    try
    {
        L->Delete(100);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_17\t->\tPASSED" << endl;
        else
            cout << "Test_17\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_17\t->\tFAILED" << endl;
    }

    try
    {
        L->Delete(2);
    }
    catch (...)
    {
        cout << "Test_18\t->\tFAILED" << endl;
    }
    cout << "Test_18\t->\tPASSED" << endl;

    try
    {
        L->DeleteFirst();
    }
    catch (...)
    {
        cout << "Test_19\t->\tFAILED" << endl;
    }
    cout << "Test_19\t->\tPASSED" << endl;

    try
    {
        L->DeleteLast();
    }
    catch (...)
    {
        cout << "Test_20\t->\tFAILED" << endl;
    }
    cout << "Test_20\t->\tPASSED" << endl;

    try
    {
        L->Insert(2, 9);
    }
    catch (...)
    {
        cout << "Test_21\t->\tFAILED" << endl;
    }
    cout << "Test_21\t->\tPASSED" << endl;

    try
    {
        L->GetNode(0);
    }
    catch (...)
    {
        cout << "Test_22\t->\tFAILED" << endl;
    }
    cout << "Test_22\t->\tPASSED" << endl;

    try
    {
        L->GetNode(100);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_23\t->\tPASSED" << endl;
        else
            cout << "Test_23\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_23\t->\tFAILED" << endl;
    }

    try
    {
        L->SetNode(100, 4);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_24\t->\tPASSED" << endl;
        else
            cout << "Test_24\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_24\t->\tFAILED" << endl;
    }

    try
    {
        L->SetNode(1, 99);
    }
    catch (...)
    {
        cout << "Test_25\t->\tFAILED" << endl;
    }
    cout << "Test_25\t->\tPASSED" << endl;

    try
    {
        L->GetCount();
    }
    catch (...)
    {
        cout << "Test_26\t->\tFAILED" << endl;
    }
    cout << "Test_26\t->\tPASSED" << endl;

    List<int>* T = new List<int>;

    *T = *L;
    *T = *T;

    if(*T >= *L)
        cout << "Test_27\t->\tPASSED" << endl;
    else
        cout << "Test_27\t->\tFAILED" << endl;

    if(*T <= *L)
        cout << "Test_28\t->\tPASSED" << endl;
    else
        cout << "Test_28\t->\tFAILED" << endl;

    T->SetNode(7, -5);
    if(*T != *L)
        cout << "Test_29\t->\tPASSED" << endl;
    else
        cout << "Test_29\t->\tFAILED" << endl;

    T->DeleteLast();
    if(*T != *L)
        cout << "Test_30\t->\tPASSED" << endl;
    else
        cout << "Test_30\t->\tFAILED" << endl;

    if(*L <= *T)
        cout << "Test_31\t->\tFAILED" << endl;
    else
        cout << "Test_31\t->\tPASSED" << endl;

    if(*L >= *T)
        cout << "Test_32\t->\tPASSED" << endl;
    else
        cout << "Test_32\t->\tFAILED" << endl;

    cout << "List L:" << endl;
    cout << *L;

    cout << "List T:" << endl;
    cout << *T;

    List<int> Sum(*L);

    Sum = -*L + *T;

    cout << "List Sum:" << endl;
    cout << Sum;

    delete L;
    delete T;
    delete &Sum;

    return 0;
}
