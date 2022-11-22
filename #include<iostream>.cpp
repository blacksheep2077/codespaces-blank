#include<iostream>
#include<string.h> 
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
using namespace std;
typedef struct SinhVien {
    char MaSV[30];
    char HoTen[30];
    int NamSinh;
    char Lop[30];
    float DTB,GiaiTich1, TrietHoc, VatLy, TiengAnhA1;
};
typedef struct Node {
    SinhVien Data;
    Node* Next;
};
 
typedef struct Node* Stack;
void Textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
 
void NhapTT(SinhVien &sv) {
    fflush(stdin);
    cout << "Ma SV: ";
    cin.getline(sv.MaSV, 30);
    cout << "Ho ten: ";
    cin.getline(sv.HoTen, 30);
    cout << "Nam sinh: ";
    cin >> sv.NamSinh;
    fflush(stdin);
    cout << "Lop: ";
    cin.getline(sv.Lop, 30);
    do{
    cout<<"\nNhap diem GiaiTich1: ";
    cin>>sv.GiaiTich1;}while(sv.GiaiTich1<0&&cout<<"Loi(diem>0).Xin nhap lai :");
    do{
    cout<<"\nNhap diem TrietHoc: ";
    cin>>sv.TrietHoc;}while(sv.TrietHoc<0&&cout<<"Loi(diem>0).Xin nhap lai :");
    do{
    cout<<"\nNhap diem VatLy: ";
    cin>>sv.VatLy;}while(sv.VatLy<0&&cout<<"Loi(diem>0).Xin nhap lai :");
    do{
    cout<<"\nNhap diem TiengAnhA1: ";
    cin>>sv.TiengAnhA1;
    }while(sv.TiengAnhA1<0&&cout<<"Loi(diem>0).Xin nhap lai :");
	sv.DTB=(sv.GiaiTich1+sv.TrietHoc+sv.VatLy+sv.TiengAnhA1)/4.0;
  //  cout << "DTB: ";
 //   cin >> sv.DTB;
}
 
void XuatTT(SinhVien sv) {
	int w=20;
    cout << "Ma SV: " << sv.MaSV << endl;
    cout << "Ho ten:" << sv.HoTen << endl;
    cout << "Nam sinh: " << sv.NamSinh << endl;
    cout << "Lop: " << sv.Lop << endl;
    cout<<"----------Diem so----------------" << endl;
    cout<<setw(w)<<"Giai tich 1"<<setw(w)<<"Triet hoc"<<setw(w)<<"Vat ly"<<setw(w)<<"Tieng Anh A1"<< endl;
    cout<<setw(w)<<sv.GiaiTich1<<setw(w)<<sv.TrietHoc<<setw(w)<<sv.VatLy<<setw(w)<<sv.TiengAnhA1<<endl;
    cout << "DTB: " << sv.DTB << endl;
}
 
//1. Khoi tao
 
void InIt(Stack &S) {
    S == NULL;
}
 
//2. Kiem tra rong
bool IsEmpty(Stack S) {
    return (S == NULL);
}
 
//3. Tao Node
Node*AddNode(Node* P, SinhVien x) {
    P = (Node*)malloc(sizeof(Node));
    P->Data = x;
    P->Next = NULL;
    return P;
}
 
//4.Dem so luong
int DemSoLuong(Stack S) {
    int dem = 0;
    for (Node* M = S; M != NULL; M = M->Next) {
        dem++;
    }
    return dem;
}
void Pop(Stack& S, SinhVien x) {
    Node* P = AddNode(P, x);
    P->Next = S;
    S = P;
}
 
void Push(Stack& S) {
    S = S->Next;
}
 
void InPut(Stack& S, int n) {
    InIt(S);
    SinhVien x;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << endl;
        NhapTT(x);
        Pop(S, x);
    }
}
 
void OutPut(Stack S) {
    for (Node* M = S; M != NULL; M = M->Next) {
        XuatTT(M->Data);
        cout << "------------------------------------" << endl;
    }
}
 
void AddAny(Stack& S, Stack &S2, int k, SinhVien x) {
    InIt(S2);
    SinhVien sv;
    for (int i = 0; i < k - 1; i++) {
        sv = S->Data;
        Push(S);
        Pop(S2, sv);
    }
    Pop(S, x);
    for (int i = 0; i < k - 1; i++) {
        sv = S2->Data;
        Push(S2);
        Pop(S, sv);
    }
}
 
void DeleteAny(Stack& S, Stack &S2, int k) {
    InIt(S2);
    SinhVien sv;
    for (int i = 0; i < k - 1; i++) {
        sv = S->Data;
        Push(S);
        Pop(S2, sv);
    }
    Push(S);
    for (int i = 0; i < k - 1; i++) {
        sv = S2->Data;
        Push(S2);
        Pop(S, sv);
    }
}
 
void Tach(Stack& S, Stack& S2, Stack& S3) {
    InIt(S3);
    InIt(S2);
    int temp = 0;
    SinhVien sv;
    for (Node*M = S; M != NULL; M = M->Next) {
        temp++;
        if ((M->Data).DTB > 5.0) {
            for (int i = 0; i < temp - 1; i++) {
                sv = S->Data;
                Push(S);
                Pop(S2, sv);
 
            }
            sv = S->Data;
            Push(S);
            Pop(S3, sv);
            for (int i = 0; i < temp - 1; i++) {
                sv = S2->Data;
                Push(S2);
                Pop(S, sv);
            }
            temp--;
        }
    }
}
int main() {
    SinhVien x;
    int chon;
    Stack S, S2, S3;
    int n;
    Textcolor(14);
    cout << "So luong sinh vien: ";
    cin >> n;
    InPut(S, n);
    do
    {
    	Textcolor(11);
        system("cls");
        cout << "1. Them sinh vien. " << endl;
        cout << "2. Xuat sinh vien." << endl;
        cout << "3. Xoa sinh vien vua them. " << endl;
        cout << "4. Them bat ky. " << endl;
        cout << "5. Xoa bat ky. " << endl;
        cout << "6. Tach diem trung binh. " << endl;
        Textcolor(12);
        cin >> chon;
        switch (chon) {
        case 1: {
        	Textcolor(14);
            NhapTT(x);
            Pop(S, x);
            break;
        }
        case 2: {
        	Textcolor(252);
            OutPut(S);
            Textcolor(15);
            system("pause");
            break;
        }
        case 3: {
            Push(S);
            break;
        }
        case 4: {
        	Textcolor(14);
            int k;
            cout << "Them vao vi tri: ";
            cin >> k;
            if (k < 1 || k > DemSoLuong(S)) cout << "Vi tri khong hop le.";
            else {
 
                SinhVien x;
                NhapTT(x);
                AddAny(S, S2, k, x);
            }
            Textcolor(15);
            system("pause");
            break;
        }
        case 5: {
        	Textcolor(14);
            int k;
            cout << "xoa vi tri: ";
            cin >> k;
            if (k < 1 || k > DemSoLuong(S)) cout << "Vi tri khong hop le.";
            else {
                DeleteAny(S, S2, k);
            }
            Textcolor(15);
            system("pause");
            break;
        }
        case 6:
        {
        	Textcolor(252);
            Tach(S, S2, S3);
            cout << "stack 1" << endl;
            OutPut(S);
 
            cout << "stack 2 " << endl;
            Textcolor(15);
            OutPut(S3);
           // Textcolor(15);
            system("pause");
            break;
        }
        }
    } while (chon != 0);
    return 0;
}