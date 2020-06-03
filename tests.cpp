#include <iostream>
#include "list.cpp"

using namespace std;

int main(void)
{
    List<int> *list = NULL;

    try
    {
        list->destroy();
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
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
        list = list->insert(1, 7);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
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
        list = list->delete_item(1);
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
        list = list->delete_first();
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
        list = list->delete_last();
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
        list->get(0);
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

    try
    {
        list->set(0, 4);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_7\t->\tPASSED" << endl;
        else
            cout << "Test_7\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_7\t->\tFAILED" << endl;
    }

    try
    {
        list->find(97);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EEMPTY)
            cout << "Test_8\t->\tPASSED" << endl;
        else
            cout << "Test_8\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_8\t->\tFAILED" << endl;
    }

    try
    {
        list = list->append(5);
    }
    catch (...)
    {
        cout << "Test_9\t->\tFAILED" << endl;
    }
    cout << "Test_9\t->\tPASSED" << endl;

    try
    {
        list = list->append(6);
    }
    catch (...)
    {
        cout << "Test_10\t->\tFAILED" << endl;
    }
    cout << "Test_10\t->\tPASSED" << endl;

    try
    {
        list = list->append(19);
    }
    catch (...)
    {
        cout << "Test_11\t->\tFAILED" << endl;
    }
    cout << "Test_11\t->\tPASSED" << endl;

    try
    {
        list = list->append(17);
    }
    catch (...)
    {
        cout << "Test_12\t->\tFAILED" << endl;
    }
    cout << "Test_12\t->\tPASSED" << endl;

    try
    {
        list = list->append(8);
    }
    catch (...)
    {
        cout << "Test_13\t->\tFAILED" << endl;
    }
    cout << "Test_13\t->\tPASSED" << endl;

    try
    {
        list = list->add(25);
    }
    catch (...)
    {
        cout << "Test_14\t->\tFAILED" << endl;
    }
    cout << "Test_14\t->\tPASSED" << endl;

    try
    {
        list = list->delete_item(100);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_15\t->\tPASSED" << endl;
        else
            cout << "Test_15\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_15\t->\tFAILED" << endl;
    }

    try
    {
        list->reverse_print();
    }
    catch (...)
    {
        cout << "Test_16\t->\tFAILED" << endl;
    }
    cout << "Test_16\t->\tPASSED" << endl;

    try
    {
        list->print();
    }
    catch (...)
    {
        cout << "Test_17\t->\tFAILED" << endl;
    }
    cout << "Test_17\t->\tPASSED" << endl;

    try
    {
        list = list->delete_item(100);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_18\t->\tPASSED" << endl;
        else
            cout << "Test_18\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_18\t->\tFAILED" << endl;
    }

    try
    {
        list = list->delete_item(2);
    }
    catch (...)
    {
        cout << "Test_19\t->\tFAILED" << endl;
    }
    cout << "Test_19\t->\tPASSED" << endl;

    try
    {
        list = list->delete_first();
    }
    catch (...)
    {
        cout << "Test_20\t->\tFAILED" << endl;
    }
    cout << "Test_20\t->\tPASSED" << endl;

    try
    {
        list = list->delete_last();
    }
    catch (...)
    {
        cout << "Test_21\t->\tFAILED" << endl;
    }
    cout << "Test_21\t->\tPASSED" << endl;

    try
    {
        list = list->insert(100, 7);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_22\t->\tPASSED" << endl;
        else
            cout << "Test_22\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_22\t->\tFAILED" << endl;
    }

    try
    {
        list = list->insert(2, 9);
    }
    catch (...)
    {
        cout << "Test_23\t->\tFAILED" << endl;
    }
    cout << "Test_23\t->\tPASSED" << endl;

    try
    {
        list->get(0);
    }
    catch (...)
    {
        cout << "Test_24\t->\tFAILED" << endl;
    }
    cout << "Test_24\t->\tPASSED" << endl;

    try
    {
        list->get(100);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_25\t->\tPASSED" << endl;
        else
            cout << "Test_25\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_25\t->\tFAILED" << endl;
    }

    try
    {
        list->get(2);
    }
    catch (...)
    {
        cout << "Test_26\t->\tFAILED" << endl;
    }
    cout << "Test_26\t->\tPASSED" << endl;

    try
    {
        list->set(100, 4);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::ESIZE)
            cout << "Test_27\t->\tPASSED" << endl;
        else
            cout << "Test_27\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_27\t->\tFAILED" << endl;
    }

    try
    {
        list->set(1, 99);
    }
    catch (...)
    {
        cout << "Test_28\t->\tFAILED" << endl;
    }
    cout << "Test_28\t->\tPASSED" << endl;

    try
    {
        list->find(97);
    }
    catch (const List<int>::LIST_ERR &ex)
    {
        if (ex == List<int>::EFOUND)
            cout << "Test_29\t->\tPASSED" << endl;
        else
            cout << "Test_29\t->\tFAILED" << endl;
    }
    catch (...)
    {
        cout << "Test_29\t->\tFAILED" << endl;
    }

    try
    {
        list->find(99);
    }
    catch (...)
    {
        cout << "Test_30\t->\tFAILED" << endl;
    }
    cout << "Test_30\t->\tPASSED" << endl;

    try
    {
        list->size();
    }
    catch (...)
    {
        cout << "Test_31\t->\tFAILED" << endl;
    }
    cout << "Test_31\t->\tPASSED" << endl;

    try
    {
        list->destroy();
    }
    catch (...)
    {
        cout << "Test_32\t->\tFAILED" << endl;
    }
    cout << "Test_32\t->\tPASSED" << endl;

    return 0;
}
