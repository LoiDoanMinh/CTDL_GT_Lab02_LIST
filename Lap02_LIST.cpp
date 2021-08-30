#include <iostream>
#include <string>
using namespace std;
struct SV
{
    string name;
	int MSSV;
	int NS;
	float DTB;
};
typedef struct SV SV;
struct node
{
	struct SV data;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
node* KhoiTaoNode(SV x);
void KhoiTaoList(list& l);
void Input(SV& x);
void Output(SV x);
void ThemVaoDau(list& l, node* p);
void ThemVaoCuoi(list& l, node* p);
void NhapDSSV_head(list& l);
void NhapDSSV_Tail(list& l);
void Xuat(list l);
void XuatLonHon_5(list l);
int XoaDau(list& l);
int XoaCuoi(list& l);
void XoaSV(list& l);
void SapXepDTB(list& l);
void XoaIn(list& l);
void menu(list& l);
int main()
{
	list l;
	KhoiTaoList(l);
	menu(l);
	
}
node* KhoiTaoNode(SV x)
{
	node* p = new node();
	if (p == NULL)
		return NULL;
	else
	{
		p->data = x;
		p->pNext = NULL;
		return p;
	}
}
void KhoiTaoList(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void Input(SV& x)
{
	cout << "\nNhap ho ten : ";
	cin.ignore();
	getline(cin, x.name);
	cout << "Nhap mssv : ";
	cin >> x.MSSV;
	cout << "Nhap nam sinh : ";
	cin >> x.NS;
	cout << "Nhap DTB : ";
	cin >> x.DTB;
}
void Output(SV x)
{
	cout << "\n" << x.name << endl;
	cout << x.MSSV << endl;
	cout << x.NS << endl;
	cout << x.DTB << endl;
}
void ThemVaoDau(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ThemVaoCuoi(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void NhapDSSV_head(list& l)
{
	int n;
	cout << "\nNhap so luong sinh vien can nhap : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SV x;
		Input(x);
		node* p = KhoiTaoNode(x);
		ThemVaoDau(l, p);
	}
}
void NhapDSSV_Tail(list& l)
{
	int n;
	cout << "\nNhap so luong sinh vien can nhap : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SV x;
		Input(x);
		node* p = KhoiTaoNode(x);
		ThemVaoCuoi(l, p);
	}
}
void Xuat(list l)
{
	for (node* p = l.pHead; p != NULL; p = p->pNext)
	{
		Output(p->data);
	}
}
void XuatLonHon_5(list l)
{
	if (l.pHead == NULL)
	{
		cout << " chua co DSSV ";
	}
	else
	{
		cout << "\n\tDanh Sach sv co DTB nho hon 5 :";
		for (node* p = l.pHead; p != NULL; p = p->pNext)
		{
			if ((p->data).DTB < 5)
			{
				Output(p->data);
			}
		}
	}
}
int XoaDau(list& l)
{
	if (l.pHead == NULL)
	{
		return 0;
	}
	else
	{
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
}
int XoaCuoi(list& l)
{
	if (l.pHead == NULL)
		return 0;
	else
	{
		for (node* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == l.pTail)
			{
				node* p = l.pTail;
				l.pTail = k;
				delete(p);
				k->pNext = NULL;
				return 1;
			}
		}
	}
}
void XoaSV(list& l)
{
	node* q = new node;
	node* p = l.pHead;
	while (p != NULL)
	{
		if (p->data.NS < 2000)
		{
			if (p == l.pHead)
			{
				XoaDau(l);
				p = l.pHead;
				continue;
			}
			else
				if (p == l.pTail)
				{
					XoaCuoi(l);
					p = l.pTail;
				}
				else
				{
					node* k = p;
					q->pNext = p->pNext;
					p = q;
					delete k;
				}
		}
		q = p;
		p = p->pNext;
	}
}
void SapXepDTB(list& l)
{
	for (node* k = l.pHead; k != NULL; k = k->pNext)
	{
		for (node* q = k->pNext; q != NULL; q = q->pNext)
		{
			if (q->data.DTB < k->data.DTB)
			{
				swap(q->data, k->data);
			}
		}
	}
}
void XoaIn(list& l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		Output(p->data);
		l.pHead = l.pHead->pNext;
		delete(p);
		p = l.pHead;
	}
}
void menu(list& l)
{
	int luachon;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t===========MENU===========";
		cout << "\n\t1.Nhap n sinh vien(them vao dau) va Xuat.";
		cout << "\n\t2.Nhap n sinh vien(them vao cuoi) va Xuat.";
		cout << "\n\t3.Xuat DSSV co DTB nho hon 5.";
		cout << "\n\t4.Xoa SV truoc 2000.";
		cout << "\n\t5.Sap xep DTB tang dan.";
		cout << "\n\t6.Xoa list va in thong tin Xoa.";

		cout << "\n\n\t\t===========END===========";
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			NhapDSSV_head(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 2)
		{
			NhapDSSV_Tail(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			XuatLonHon_5(l);
			system("pause");
		}
		else if (luachon == 4)
		{

			XoaSV(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 5)
		{
			SapXepDTB(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\nCac SV bi xoa ";
			XoaIn(l);
			system("pause");
		}
		else
			break;
	}
}