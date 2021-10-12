#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiDocGia.h"
#include"QuanLiSach.h"
#include"MuonSach.h"
#include"TraSach.h"
#include"ThongKe.h"
void main()
{
	
	int kt = 1;
	int n;
	int cn;
	int n2;
	int n3;
	int n4;
	int n5;
	MangDocGia DG;
	MangSach sa;
	MangDocGia mdg;
	MangMuon dgm;
	TraSach ts[100];
while (kt == 1)
{
	system("cls");
	printf("===================================================================\n");
	printf("======================== QUAN LI THU VIEN =========================\n");
	printf("===================================================================\n");
	printf("\n\n\n");
	printf("===========================================================================\n");
	printf("===============================   MENU CHINH   ============================\n");
	printf("===========================================================================\n");
	printf("==============       1.Quan li doc gia.                     ===============\n");
	printf("==============       2.Quan li sach.                        ===============\n");
	printf("==============       3.Lap phieu muon sach.                 ===============\n");
	printf("==============       4.Lap phieu tra sach.                  ===============\n");
	printf("==============       5.Cac thong ke co ban                  ===============\n");
	printf("==============       6.Thoat khoi truong trinh thu vien     ===============\n");
	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("Vui Long Chon Chuc Nang:");
	scanf("%d", &cn);

	//=======================================================
	switch (cn)//Giup chon chuc nang lon trong thu vien.
	{
	case 1://============================CHUC NANG 1====================================
	{   int kt1 = 1;
	while (kt1 == 1)
	{
		system("cls");
		printf("================================================================\n");
		printf("======================   I.Quan li doc gia.    =================\n");
		printf("================================================================\n");
		printf("========       1.Xem danh sach do gia.                 =========\n");
		printf("========       2.Them doc gia.                         =========\n");
		printf("========       3.Chinh sua thong tin doc gia.          =========\n");
		printf("========       4.Xoa thong tin doc gia.                =========\n");
		printf("========       5.Tim kiem doc gia theo CMND.           =========\n");
		printf("========       6.Tim kiem danh sach theo ho ten.       =========\n");
		printf("========       7.Thoat khoi Quan li doc gia.           =========\n");
		printf("================================================================\n");
		printf("================================================================\n");
		LayDanhSachDocGia(DG);
		printf("Vui Long Chon Chuc Nang:");
		scanf("%d", &n);
		switch (n)
		{
		case 1://================================THONG TIN DOC GIA===================================
		{
			system("cls");
			printf("================1.Thong Tin Doc Gia==============\n");
			LayDanhSachDocGia(DG);
			XuatDanhSachDocGia(DG);
			kt1 = 0;
			if (kt1 == 0)
			{
				printf("\n");
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt1);
			}
			break;
		}
		case 2://===============THEM DOC GIA==============
		{system("cls");
		ThemDocGia(DG);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt1);
		break;
		}
		case 3://==============================CHINH SUA THONG TIN DOC GIA=============================
		{system("cls");
		ChinhSuaDocGia(DG);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt1);
		break;
		}
		case 4://Xoa Doc gia.
		{system("cls");
		XoaDocGia(DG);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt1);
		break;
		}
		case 5://Tim doc gia theo CMND
		{system("cls");
		TimDocGiaTheoCMND(DG);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt1);
		break;
		}
		case 6:// Tim Doc gia theo ho va ten
		{system("cls");
		TimTheoHoTen(DG);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt1);
		break;
		}
		case 7:
		{
			kt1 = 0;
			break;
		}
		}
	}
	kt = 0;
	if (kt == 0)// dung de dung truong trinh
	{
		system("cls");
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt);
	}
	break;

	}
	case 2://========================CHUC NANG 2================================================
	{
		int kt2 = 1;
		while (kt2 == 1)
		{
			system("cls");
			printf("================================================================\n");
			printf("======================   I.Quan li sach.       =================\n");
			printf("================================================================\n");
			printf("========       1.Xem danh sach sach trong thu vien.    =========\n");
			printf("========       2.Them sach.                            =========\n");
			printf("========       3.Chinh sua thong tin mot quyen sach.   =========\n");
			printf("========       4.Xoa thong tin sach.                   =========\n");
			printf("========       5.Tim kiem doc gia theo ISBN.           =========\n");
			printf("========       6.Tim kiem danh sach theo ten sach.     =========\n");
			printf("========       7.Thoat ra khoi quan li sach.           =========\n");
			printf("================================================================\n");
			printf("================================================================\n");
			printf("Vui Long Chon Chuc Nang:");
			LayDanhSachSach(sa);
			scanf("%d", &n2);
			switch (n2)
			{
			case 1:
			{  system("cls");
				LayDanhSachSach(sa);
			    XuatDanhSachSach(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;
			}
			case 2:
			{
				system("cls");
				ThemSach(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;
			}
			case 3:
			{
				system("cls");
				ChinhSuaThonhTinSach(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;
			}
			case 4:
			{
				system("cls");
				XoaThongTinSach(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;
			case 5:
			{
				system("cls");
				TimSachTheoISBN(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;

			}
			case 6:
			{
				system("cls");
				TimSachTheoTen(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt2);
				break;
			}
			case 7:
			{
				kt2 = 0;
				break;
			}

			}

			}

		}
		kt = 0;
		if (kt == 0)// dung de dung truong trinh
		{
			system("cls");
			printf("*******************************************************************\n");
			printf("*                                                                 *\n");
			printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
			printf("*                                                                 *\n");
			printf("*******************************************************************\n");
			scanf("%d", &kt);
		}
		break;
	}
	case 3://================================CHUC NANG 3===================================
	{int kt3 = 1;
	while (kt3 == 1)
	{
		LayDanhSachDocGia(DG);
		LayDanhSachSach(sa);
		MuonSach(DG,sa,dgm);
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt3);
		break;

	}
	kt = 0;
	if (kt == 0)// dung de dung truong trinh
	{
		system("cls");
		printf("*******************************************************************\n");
		printf("*                                                                 *\n");
		printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
		printf("*                                                                 *\n");
		printf("*******************************************************************\n");
		scanf("%d", &kt);
	}

	break;

	}
	case 4://==============================CHUC NANG 4=======================================
	{
		int kt4 = 1;
		while (kt4 == 1)
		{
			LaySoLanMuonSach(dgm);
			TraSach123(ts,dgm);
			printf("*******************************************************************\n");
			printf("*                                                                 *\n");
			printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
			printf("*                                                                 *\n");
			printf("*******************************************************************\n");
			scanf("%d", &kt4);
			break;

		}
		kt = 0;
		if (kt == 0)// dung de dung truong trinh
		{
			system("cls");
			printf("*******************************************************************\n");
			printf("*                                                                 *\n");
			printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
			printf("*                                                                 *\n");
			printf("*******************************************************************\n");
			scanf("%d", &kt);
		}

		break;
	}
	//==============
	case 5://==========================CHUC NANG 5=============================================
	{
		int kt5 = 1;
		while (kt5 == 1)
		{
			system("cls");
			printf("================================================================\n");
			printf("======================   I.Quan li sach.       =================\n");
			printf("================================================================\n");
			printf("========    1.Thong ke so luong sach trong thu vien.   =========\n");
			printf("========    2.Thong ke so luong sach theo the loai.    =========\n");
			printf("========    3.Thong ke so luon doc gia.                =========\n");
			printf("========    4.Thong ke so luong doc gia theo gioi tinh.=========\n");
			printf("========    5.Thong ke so sach dang muon.              =========\n");
			printf("========    6.Thong ke danh sach doc gia bi tre han.   =========\n");
			printf("========    7.Thoat ra khoi quan li sach.              =========\n");
			printf("================================================================\n");
			printf("================================================================\n");
			printf("Vui Long Chon Chuc Nang:");
			scanf("%d", &n2);
			switch (n2)
			{
			case 1:
			{
				ThongKeSoSachTrongThuVien(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;
			}
			case 2:
			{
				ThongKeTheLoaiSachTrongThuVien(sa);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;
			}
			case 3:
			{
				ThongKeSoLuongDocGia(DG);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;
			}
			case 4:
			{
				ThongKeSoLuongDocGiaTheoGioiTinh(DG);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;
			}
			case 5:
			{
				ThongKeSachDangMuon(dgm);
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;

			}
			case 6:
			{
				
				printf("*******************************************************************\n");
				printf("*                                                                 *\n");
				printf("*     ban co muon quay lai menu truoc khong ? CO:1  KHONG:0       *\n");
				printf("*                                                                 *\n");
				printf("*******************************************************************\n");
				scanf("%d", &kt5);
				break;
			}
			case 7:
			{
				kt5 = 0;
				break;
			}

			}
		}
		kt = 0;
		if (kt == 0)// dung de dung truong trinh
		{
			system("cls");
			printf("*******************************************************************\n");
			printf("*                                                                 *\n");
			printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
			printf("*                                                                 *\n");
			printf("*******************************************************************\n");
			scanf("%d", &kt);
		}

		break;
	}
	case 6:
	{
		kt = 0;
		if (kt == 0)// dung de dung truong trinh
		{
			system("cls");
			printf("*******************************************************************\n");
			printf("*                                                                 *\n");
			printf("*       Ban co muon quay lai MENU chinh khong CO:1  KHONG:0       *\n");
			printf("*                                                                 *\n");
			printf("*******************************************************************\n");
			scanf("%d", &kt);
		}

		break;
	}
	}
}
_getch();}