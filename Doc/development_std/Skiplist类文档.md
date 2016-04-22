
##类的名称（编号）
Skiplist.h、Skiplist.cpp
##类的声明与作用
  两个类模板：结点类模板、跳跃表类模板
###类开发的必要性，唯一性
没有发现对项目实际可用的跳跃表模板，充分利用c++封装等特手动实现跳跃表类，可使项目性能及效率提高。
###类中各函数的复杂度，可能瓶颈
  跳跃链表是一种随机化数据结构，基于并联的链表，其效率可比拟于二叉查找树(对于大多数操作需要O(log n)平均时间)，并且对并发算法友好。
  跳跃表的期望空间需求为O(n)。跳跃表在中Redis实现有序键集合以及在集群结点中用作内部数据结构，用处较单一且必不可少。
  
##类的声明与定义

```
//结点类
template<class E, class K>
class SkipNode
{
public: 
    SkipNode(int size)
    {
        link = new SkipNode<E,K>*[size];
    }
    ~SkipNode()
    {
        delete []link;
    }

SkipNode<E,K>** link;    //一维指针数组
E data;
};

//跳跃表类
template<class E, class K>
class SkipList{
public:
     /*
     *成员函数接口
     */
    //MaxE 是表最大的容量large 是表中最大的值，即尾结点的值
    SkipList(K large, int MaxE = 10000, float p =0.5);
    ~SkipList();                               //析构函数删除所有结点及数组

    bool Search(const K& k, E& e)const;        //从跳跃表查找与k相匹配的元素并放入e中
    SkipList<E, K>& Insert(const E& e);       //插入e
    SkipList<E, K>& Delete(const K& k, E& e); //从跳跃表删除与k相匹配的元素并放入e中
    void Output(ostream& out)const;           //输出跳跃表
    int level();                              //产生一个随机级号
    SkipNode<E, K> *SaveSearch(const K& k);  //搜索k并保存最终得到的位置
    
    /*
    *待实现成员函数接口及功能说明
    *
    */
    get_skinode();                 //返回跳跃表在给定排位上的结点
    num_rank();                    //判断值是否在一个值范围
    first_ranknode();              //给定一个值范围，返回跳跃表中第一个符合这个范围的结点
    last_ranknode();              //给定一个值范围，返回跳跃表中最后一个符合这个范围的结点
    del_rank();                   //给定一个值范围，删除跳跃表中所有在这个范围之内的结点
    
    //变量
    int maxlevel;                          //所允许的最大级数
    int levels;                            //当前非空链的个数
    int Cutoff;                            //用于确定级号
    K Tailkey;                             //一个很大的key值
    SkipNode<E, K>* head;                  //头结点指针
    SkipNode<E, K>* tail;                  //尾结点指针
    SkipNode<E, K>** last;                 //指针数组

};

```
###类成员函数接口说明
 成员函数说明待补充
###审阅人批覆
