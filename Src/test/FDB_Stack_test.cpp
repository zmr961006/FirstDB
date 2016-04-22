/*************************************************************************
	> File Name: FDB_Stack_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月18日 星期一 09时03分37秒
 ************************************************************************/

#include<iostream>
#include"./FDB_Stack.h"
#include"./FDB_Queue.h"
using namespace std;

int main()
{
    FDB_Queue<int> Q;

    if (Q.FDB_Queue_empty() == true)
    {
        cout << "empty" << endl;
    }

    Q.FDB_Queue_pop();
    cout << Q.FDB_Queue_front() << endl;
    //cout << Q.FDB_Queue_back() << endl;
//cout << "wrx" << endl;
    cout << Q.FDB_Queue_size() << endl;
    Q.FDB_Queue_push(1);
    Q.FDB_Queue_push(2);
    Q.FDB_Queue_push(3);
    Q.FDB_Queue_pop();
    cout << Q.FDB_Queue_front() << endl;
    cout << Q.FDB_Queue_back() << endl;
    cout << Q.FDB_Queue_size() << endl;

FDB_Stack<int> S;

    if (S.FDB_Stack_empty() == true)
    {
        cout << "empty" << endl;
    }

    S.FDB_Stack_pop();
//cout << "wrx" << endl;
    //cout << S.FDB_Stack_top() << endl;

    cout << S.FDB_Stack_size() << endl;
    S.FDB_Stack_push(1);
    S.FDB_Stack_push(2);
    S.FDB_Stack_push(3);
    S.FDB_Stack_pop();
    cout << S.FDB_Stack_top() << endl;
    cout << S.FDB_Stack_size() << endl;
}
