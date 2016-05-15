/*************************************************************************
	> File Name: FDB_skiplist.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月14日 星期六 23时29分04秒
 ************************************************************************/

#include "FDB_skiplist.h"
using namespace std;
/*构造函数
*large 表示结点所允许的最大值
* */
template<class E>
list_skip<E>::list_skip(E large, int MaxE, float p)
{
    Eval = p*RAND_MAX;
    Tail_key = large;
    maxlevel = ceil(log(MaxE)/log(1/p))-1;

    levels = 0;                               /*对级号进行初始化*/

    /*创建头结点、尾结点以及指针数组last*/
    head = new SkipNode<E>(maxlevel+1);
    tail = new SkipNode<E>(maxlevel+1);
    last = new SkipNode<E>*[maxlevel+1];

    /*让头结点的每个指针都先指在tail这块地方*/
    tail->set_data(large);
    for(int i = 0; i <= maxlevel; i++){
        head->link[i] = tail;
    }

}


/*析构函数*/
template<class E>
list_skip<E>::~list_skip()
{
    SkipNode<E> *next;
     
    /*通过删除0级链来删除所有结点，因为不敢保证其他级链存在*/
    while(head != tail){
        next = head->link[0];
        delete head;
        head = next;
    }

    delete tail;
    delete []last;
}

/*产生一个随机级号 <= maxlevel*/
template<class E>
int list_skip<E>::level()
{
    int lev = 0;
    while(rand() <= Eval){
        lev++;
    }
    return (lev <= maxlevel)?lev:maxlevel;
}

/*向跳跃表插入结点函数*/
template<class E>
int list_skip<E>::Insert(E e)
{
    /*值太大或者已经存在*/
    if(e >= Tail_key || this->Search_my(e)){
        return 0;
    }
    
    /*创建一个新结点，并将其初始化*/
    SkipNode<E>* y = new SkipNode<E>(maxlevel+1);
    y->set_data(e);
    for(int i = 0; i <= maxlevel; i++){
        y->link[i] = tail;
    }

    /*在不重复的情况下为新结点创建级号*/
    int lev = level();
    std::cout << "lev = " << lev << "   levels = " << levels << std::endl;

    /*如果随机出来的层数大于已存的在非空层，则增加一层*/ 
    int key_lev = ( (lev >= levels) ? levels : lev);
    if(lev > levels) {
        ++levels;
    }

    /*建立一个指针数组保存每层要插入数据的位置*/
    SkipNode<E>** updata = new SkipNode<E>*[maxlevel];
    SkipNode<E>* p = head;                                     /*一个指向结点的临时指针变量*/
    SkipNode<E>* q = NULL;                             


    /*从高往低查找处合适的位置然后插入*/
    for(int i = key_lev; i >= 0; i--){
        while( (q=p->link[i]) != tail && q->get_data() < e){
            p = q;
        }
        updata[i] = p;
    }

    for(int i = key_lev; i >= 0; i-- ){

        y->link[i] = updata[i]->link[i];
        updata[i]->link[i] = y;
    }

    delete []updata;                                          /*删除临时数组防止内存泄漏*/
}

/*从跳跃表中删除指定的值*/
template<class E>
bool list_skip<E>::Delete_my(E e)
{

    SkipNode<E>* p = head;                              
    SkipNode<E>* q = NULL;                             
 
    
    for(int i = levels; i >= 0; i--){
        while( (q=p->link[i]) != tail && q->get_data() <= e){
            
            if(q->get_data() == e){
                for(int j = 0; j <= levels; j++){
                    p->link[j] = q->link[j];
                }

                delete q;
                return true;
            }
            p = q;
        }
    }

    return false;
}
//在跳跃表中查找指定的值
template<class E>
E list_skip<E>::Search_my(E e)
{

    SkipNode<E>* p = head;                                     /*一个指向结点的临时指针变量*/
    SkipNode<E>* q = NULL;                             

     for(int i = levels; i >= 0; i--){
        while( (q=p->link[i]) != tail && q->get_data() <= e){

            if(q->get_data() == e){
                return e;
            }
            p = q;
        }
    }

    return 0;
}

//输出跳跃表的内容
template<class E>
void list_skip<E>::out_my()
{
    
    SkipNode<E>* y = NULL;

    for(int i = 0; i <= levels; i++){
        y = head->link[i];

        while( y != tail){

            std::cout << y->get_data() << " ";
            y = y->link[0];
        }

        std::cout << std::endl;
    }

}
 
