#include <iostream>
using namespace std;
// github

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t)
{
    t = NULL; //cây rỗng
}

//Hàm thêm phần tử vào cây nhị phân
void ThemPhanTu(TREE &t , int x)
{
    if ( t == NULL)
    {
        NODE *p = new NODE;
        p ->data = x;
        p ->pLeft = NULL;
        p ->pRight = NULL;
        t = p ; // Phần tử gốc sẽ là phần tử đầu tiên
    }
    else
    {
        // Nếu phần tử tiếp theo lớn hơn phần tử gốc
        if (t ->data < x)
        {
            ThemPhanTu(t -> pRight , x);
        }
        // Nếu phần tử tiếp theo bé hơn phần tử gốc
        else if ( t -> data > x)
        {
            ThemPhanTu(t ->pLeft , x);
        }
    }
}

void Duyet_NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t ->data <<" ";
        Duyet_NLR(t ->pLeft);
        Duyet_NLR(t ->pRight);

    }
}

void Duyet_NRL(TREE t)
{
    if (t != NULL)
    {
        cout << t ->data <<" ";
        Duyet_NRL(t -> pRight);
        Duyet_NRL(t -> pLeft);

    }
}

void Duyet_LNR(TREE t)
{
    if ( t != NULL)
    {
        Duyet_LNR(t ->pLeft);
        cout << t ->data << " ";
        Duyet_LNR(t ->pRight);
    }
}

void Duyet_RNL(TREE t)
{
    if ( t != NULL)
    {
        Duyet_LNR(t ->pRight);
        cout << t ->data << " ";
        Duyet_LNR(t ->pLeft);
    }
}

void Duyet_LRN(TREE t)
{
    if ( t != NULL)
    {
        Duyet_LNR(t ->pLeft);
        Duyet_LNR(t ->pRight);
        cout << t ->data << " ";
    }
}

void Duyet_RLN(TREE t)
{
    if ( t != NULL)
    {
        Duyet_LNR(t ->pRight);
        Duyet_LNR(t ->pLeft);
        cout << t ->data << " ";
    }
}

//Hàm kiểm tra SNT
bool KTSNT(int x)
{
    if (x < 2)
        return false;
    else
    {
        if (x == 2)
            return true;
        else
        {
            if ( x % 2 == 0)
                return false;
            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                        return false;
                }
            }
        }    
    }
    return true;
}

//Hàm đếm số lượng SNT

void SoLuongSNT(TREE t, int &dem)
{
    if (t != NULL)
    {
        if (KTSNT( t -> data) == true)
            dem++;
        SoLuongSNT(t ->pLeft, dem);
        SoLuongSNT(t ->pRight,dem); 
    }
}

NODE *TimKiem(TREE t, int x)
{
    //nếu cây rỗng
    if (t == NULL) 
        return NULL;
    else
    {
        if ( x > t->data)
            TimKiem(t->pRight , x);
        else if ( x < t->data)
            TimKiem(t ->pLeft, x);
        else // t-> data == x
            return t;
    }

}

void Node_Co_2_con(TREE t)
{
    if (t != NULL)
    {
        if (t ->pLeft != NULL && t->pRight != NULL)
            cout  << t->data << " ";
    }
    Node_Co_2_con(t ->pLeft);
    Node_Co_2_con(t ->pRight);
}

void Node_Co_1_con(TREE t)
{
    if (t != NULL)
    {
        if (t ->pLeft != NULL && t->pRight == NULL || t ->pLeft == NULL && t->pRight != NULL)
            cout  << t->data << " ";
    }
    Node_Co_1_con(t ->pLeft);
    Node_Co_1_con(t ->pRight);
}

void Node_Co_0_con(TREE t)
{
    if (t != NULL)
    {
        if (t ->pLeft == NULL && t->pRight == NULL )
            cout  << t->data << " ";
    }
    Node_Co_0_con(t ->pLeft);
    Node_Co_0_con(t ->pRight);
}



void Menu(TREE &t)
{
    while(true)
    {
        system("cls");
        cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
        cout << "\n3. Dem so luong so nguyen to";
        cout << "\n4. Tim kiem phan tu";
        cout << "\n5. Node co 0 con ";
        cout << "\n6. Node co 1 con ";
        cout << "\n7. Node co 2 con ";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =======";


        int luachon;
        cout << "Nhap lua chon : ";
        cin >> luachon;

        if(luachon < 0 || luachon > 7)
        {
           cout << "Lua chon khong hop le !";
           system("pause");
        }

        if ( luachon == 1) // Nhập dữ liệu
        {
            int x;
            cout <<"Nhap so nguyen : ";
            cin >> x;
            ThemPhanTu(t , x);
        }
        else if ( luachon == 2)
        {
            cout <<"Duyet cay theo NLR : ";
            Duyet_NLR(t);

            cout << endl;
            cout <<"Duyet cay theo NRL : ";
            Duyet_NRL(t);

            cout << endl;
            cout <<"Duyet cay theo LNR : ";
            Duyet_LNR(t);

            cout << endl;
            cout <<"Duyet cay theo RNL : ";
            Duyet_RNL(t);

            cout << endl;
            cout <<"Duyet cay theo LRN : ";
            Duyet_LRN(t);

            cout << endl;
            cout <<"Duyet cay theo RLN : ";
            Duyet_RLN(t);

            
            system("pause");
        }
        else if ( luachon == 3)
        {
            int dem = 0;
            SoLuongSNT(t, dem);
            cout <<"So luong So nguyen to : " << dem;
            system("pause");
        }
        else if ( luachon == 4)
        {
            int x;
            cout <<"Nhap phan tu can tim kiem : ";
            cin >> x;
            NODE *p = TimKiem(t,x); 
            if ( p == NULL)
                cout <<"Phan tu "<<x<<" khong ton tai !";
            else   
                cout <<"Phan tu "<<x<<" co ton tai trong cay !";

            system("pause");
        }
        else if ( luachon == 5)
        {
            cout <<endl;
            cout <<"\tNode co 0 con la : ";
            Node_Co_0_con(t);
            system("pause");
        }
        else if ( luachon == 6)
        {
            cout <<endl;
            cout <<"\tNode co 1 con la : ";
            Node_Co_1_con(t);
            system("pause");
        }
        else if ( luachon == 7)
        {
            cout <<endl;
            cout <<"\tNode co 2 con la : ";
            Node_Co_2_con(t);
            system("pause");
        }
        else
        {
            break;
        }
    }
}




int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);

    return 0;
}