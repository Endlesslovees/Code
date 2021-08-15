#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//khai báo một struc sinh viên gồm id: mã sinh viên, name họ tên sinh viên, và năm sinh
typedef struct sinhvien
{
    char ID[50];
    char NAME[50];
    int namsinh;
}SV;
//hàm ghi file
void writefile(FILE *f,SV sv)
{
    int n;//khai báo một biến: số lượng sinh viên nhập vào
    printf("nhap vao so luong sinh vien\n");
    scanf("%d",&n);
    //mở file
    f=fopen("DS_SV.C","wb");
    //duyệt vòng for để nhập vào n sinh viên
    for(int i=0;i<n;i++)
    {
        fflush(stdin);
        printf("nhap vao ma sinh vien\n");
        gets(sv.ID);
        printf("nhap vao ho ten sinh vien\n");
        gets(sv.NAME);
        printf("nhap vao nam sinh sinh vien \n");
        scanf("%d",&sv.namsinh);
        // ghi sinh viên vừa nhập vào file
        fwrite(&sv,sizeof(SV),1,f);
    }
    fclose(f);// khi mở file thì phải đóng file
}
//hàm đọc file
void readfile(FILE *f,SV sv)
{
    f=fopen("DS_SV.C","rb");// mở file nhị phân để đọc file
    rewind(f);// con trỏ đến fike
    int i=1;
    printf("\n\t\t\tDANH SACH SINH VIEN\n");
    printf("%16s%16s%16s%16s\n","STT","MA SV","HO TEN","NAM SINH");
     while( fread(&sv,sizeof(SV),1,f)!=NULL)//https://quantrimang.com/ham-fread-trong-c-157837 em đọc cái hàm này trong trang này nha
     {
        printf("%16d%16s%16s%16d\n",i++,sv.ID,sv.NAME,sv.namsinh);//in ra từng sinh viên trong file
     }
     fclose(f);//đóng file
}

//hàm sửa danh sách sinh viên
void suadanhsach(FILE *f,SV sv)
{
    f=fopen("DS_SV.C","rb"); // mở file
    printf("\n\t\t\tDANH SACH SINH VIEN\n");

    int i=0;
    char HT[50];// biến lưu tên sửa lại
    char ht[50];// biến lưu tên cần sửa
    printf("\nBAN MUON SUA HO TEN VA NAMSINH cua sinh vien nao \n");
    fflush(stdin);
    gets(ht);
    printf("\nnhap ho ten muon sua \n");
    fflush(stdin);
    gets(HT);
    int year;// biến lưu năm sửa lại
    printf("\n nhap vao nam sinh muon sua \n");
    scanf("%d",&year);
    while(fread(&sv,sizeof(SV),1,f)!=NULL)// như trên em đọc ở link kia nha
    {
        if(strcmp(sv.NAME,ht)==0)// so sánh tên trong danh sách sinh viên với biến tên cần sửa
        {
            strcpy(sv.NAME,HT);// viết lại tên
            sv.namsinh=year;//viết lại năm
        }
         printf("%16d%16s%16s%16d\n",i++,sv.ID,sv.NAME,sv.namsinh);// in ra màn hình consol
    }
    fclose(f);// đóng file
}
void menu()
{
    printf("\n 1. tao danh sach\n");
    printf("2.hien danh sach\n");
    printf("3.sua thong tin sinh vien\n");
    printf("4.ket thuc\n");
}
int main(int argc, char const *argv[])
{
    //khai báo
    FILE *f;
    SV sv;
    int choose;
    while(1)
    {
        menu();
        printf("\nnhap lua chon cua ban\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                writefile(f,sv);
                break;
            case 2:
                readfile(f,sv);
                break;
            case 3:
                suadanhsach(f,sv);
                break;
            case 4:
                exit(0);
            default :
                printf("\nban chon khong dung moi chon lai\n");
                break;
        }
    }
    return 0;
}
