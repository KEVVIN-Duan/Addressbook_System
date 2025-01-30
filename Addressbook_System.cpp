// 这是一次尝试
#include <iostream>
#include <string>
#define MAX 1000//通讯录上限1000人
using namespace std;
//展示菜单，即选项
void showmenu(void)
{
    cout<<"1.Add contact person"<<endl;
    cout<<"2.Show contact person"<<endl;
    cout<<"3.Delete contact person"<<endl;
    cout<<"4.Search for contact person"<<endl;
    cout<<"5.Modify contact person"<<endl;
    cout<<"6.Eliminate contact person"<<endl;
    cout<<"0.Exit address book"<<endl;
    return;
}

struct contact//联系人结构体
{
    string name;
    string sex;//1male 2female
    int age;
    long long unsigned int phone;
    string address;
};

struct addressbook//通讯录结构体
{
    //结构体内部可以包含结构体数组！！
    contact array[MAX];//联系人序号数组
    int size;//通讯录人数
};


void inputcontact(addressbook*p)//添加联系人
{
    //先判断通讯录是否已满
    if(p->size>=MAX)
    {
        cout<<"The addressbook is already full"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"Please add new contact person"<<endl;
        cout<<"Please add name:";
        cin>>name;
        p->array[p->size].name=name;//是指通讯录本来有size个人，第size+1个人的姓名是用户输入的

        cout<<"Please add sex"<<endl;
        cout<<"1--male"<<endl;
        cout<<"2--female"<<endl;
        while(1)
        {
            int sex=0;
            cin>>sex;
            if(sex==1)
            {
                p->array[p->size].sex="male";
                break;
            }
            else if(sex==2)
            {
                p->array[p->size].sex="female";
                break;
            }
            else
            {
                cout<<"Wrong input!Please try again"<<endl;
            }
        }

        cout<<"Please add age:"<<endl;
        while(1)
        {
            int age=0;
            cin>>age;
            if(age<=0 || age>=100)
            {
                cout<<"Wrong input! Please try again"<<endl;
            }
            else
            {
                p->array[p->size].age=age;
                break;
            }
        }

        cout<<"Please add phone number:"<<endl;
        long long unsigned int phone=0;
        cin>>phone;
        p->array[p->size].phone=phone;

        cout<<"Please add address:"<<endl;
        string address="";
        cin>>address;
        p->array[p->size].address=address;

        p->size++;//!!!!注意通讯录人数得刷新一次

        cout<<"Successful addition!"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"The number of contact people is:"<<p->size<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    return;
}

//显示联系人
void showcontact(addressbook*p)
{
    if(p->size==0)//要注意没有联系人的情况！！
    {
        cout<<endl;
        cout<<"The addressbook is empty"<<endl;
        cout<<endl;
        cout<<endl;
    }
    else//显示所有联系人信息
    {
        cout<<endl;
        cout<<endl;
        for(int i=0; i<p->size; i++)
        {
            cout<<"Name:";
            cout<<p->array[i].name<<endl;
            cout<<"Sex:";
            cout<<p->array[i].sex<<endl;
            cout<<"Age:";
            cout<<p->array[i].age<<endl;
            cout<<"Phone number:";
            cout<<p->array[i].phone<<endl;
            cout<<"Address:";
            cout<<p->array[i].address<<endl;
            cout<<endl;
            cout<<endl;
        }
    }
    return;
}


//检查联系人是否存在，为后续删除做准备
int checkcontact(addressbook*p, string name)//!!注意要有name作为参数，从而使得删除时输入name就可以查找到联系人
{
    for(int i=0; i<p->size; i++)
    {
        if(p->array[i].name==name)
        {
            return i;
        }
    }
    return -1;
}

void deletecontact(addressbook*p)//删除逻辑：将后面的所有人均往前移动一位，最后将总人数减一
{
    cout<<"Please input the name:"<<endl;
    while(1)
    {
        string name="";
        cin>>name;
        if(checkcontact(p, name)==-1)
        {
            cout<<"The contact person doesn't exist, please try again"<<endl;
        }
        else
        {
            cout<<"Find that person:"<<name<<endl;
            for(int i=checkcontact(p, name); i<p->size; i++)
            {
                struct contact temp=p->array[i+1];
                p->array[i+1]=p->array[i];
                p->array[i]=temp;
            }
            p->size--;
            cout<<endl;
            cout<<endl;
            cout<<"Successful deletion!"<<endl;
            cout<<endl;
            cout<<endl;
            return;
        }
    }
}

void searchcontact(addressbook*p)
{
    cout<<"Please input the name:"<<endl;
    while(1)
    {
        string name="";
        cin>>name;
        if(checkcontact(p,name)==-1)
        {
            cout<<"The contact person doesn't exist. Please try again."<<endl;
        }
        else
        {
            cout<<"Find that person:"<<endl;
            cout<<endl;
            cout<<"Name:"<<p->array[checkcontact(p,name)].name<<"\t";
            cout<<"Age:"<<p->array[checkcontact(p,name)].age<<"\t";
            cout<<"Sex:"<<p->array[checkcontact(p,name)].sex<<"\t";
            cout<<"Phone number:"<<p->array[checkcontact(p,name)].phone<<"\t";
            cout<<"Address:"<<p->array[checkcontact(p,name)].address<<"\t";
            cout<<endl;
            cout<<endl;
            cout<<endl;
            return;
        }
    }
}

void modifycontact(addressbook*p)
{
    cout<<"Please input the name:"<<endl;
    while(1)
    {
        string name="";
        cin>>name;
        int index=checkcontact(p,name);
        if(index==-1)
        {
            cout<<"The contact person doesn't exist. Please try again"<<endl;
        }
        else
        {
            cout<<"Find that person:"<<endl;
            cout<<"Please input new name:";
            string name="";
            cin>>name;
            p->array[index].name=name;

            cout<<"Please input new sex:";
            cout<<"1--male"<<endl;
            cout<<"2--female"<<endl;
            string sex="";
            while(1)
            {
                int option=0;
                cin>>option;
                if(option==1)
                {
                    p->array[index].sex="male";
                    break;
                }
                else if(option==2)
                {
                    p->array[index].sex="female";
                    break;
                }
                else
                {
                    cout<<"Wrong input!Please try again"<<endl;
                }
            }

            cout<<"Please input age:";
            while(1)
            {
                int age=0;
                cin>>age;
                if(age<=0 || age>100)
                {
                    cout<<"Wrong input! Please try again"<<endl;
                }
                else
                {
                    p->array[index].age=age;
                    break;
                }
            }

            cout<<"Please input phone number:";
            long long unsigned int phone=0;
            cin>>phone;
            p->array[index].phone=phone;


            cout<<"Please input address:";
            string address="";
            cin>>address;
            p->array[index].address=address;

            cout<<endl;
            cout<<endl;
            cout<<"Successful modification!"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            break;
        }
    }
}



void cleancontact(addressbook*p)
{
    p->size=0;
    cout<<"Successful elimination!"<<endl;
    cout<<endl;
    cout<<endl;
}

int main(void)
{
    addressbook mine;//我的通讯录
    mine.size=0;
    int option=0;
    while(1)//运用死循环可以实现无限次输入，除非敲0
    {
        showmenu();
        cin>>option;
        switch(option)
        {
            case 1://添加 使用结构体
            inputcontact(&mine);//通过函数接收通讯录！！使用地址，因为地址才能改变实参
            break;

            case 2://显示
            showcontact(&mine);
            break;

            case 3://删除
            deletecontact(&mine);
            break;

            case 4://查询
            searchcontact(&mine);
            break;

            case 5://修改
            modifycontact(&mine);
            break;

            case 6://清空
            cleancontact(&mine);
            break;

            case 0://退出通讯录功能
            cout<<endl;
            cout<<endl;
            cout<<"Welcome to use next time!"<<endl;
            cout<<"Press any key to exit"<<endl;
            cout<<endl;
            system("pause");
            return 0;//可以从这里直接退出主函数！！！
            break;

            default:
            cout<<"Wrong input. Please try again"<<endl;
            break;
        }
    }
    //system("pause");
    return 0;
}

// 提交到远程仓库