#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiSach.h"
#include"QuanLiDocGia.h"
#include"MuonSach.h"
#include"TraSach.h"
#include"ThongKe.h"
void ThongKeSoSachTrongThuVien(MangSach &sa)
{
	int TongSachTrongThuVien = 0;
	LayDanhSachSach(sa);
	for (int i = 0; i < sa.d; i++)
	{
		TongSachTrongThuVien = TongSachTrongThuVien + sa.Sa[i].SoS;
	}
	printf("Tong so sach trong thu vien la : %d cuon sach \n ", TongSachTrongThuVien);
}
void ThongKeSoLuongDocGia(MangDocGia DG)
{
	int TongSoDG = 0;
	LayDanhSachDocGia(DG);
	printf("So Luong doc gia trong thu vien la : %d \n", DG.n);
}
void ThongKeSachDangMuon(MangMuon dgm)
{
	LaySoLanMuonSach(dgm);
	printf("So sach dang muon cua thu vien la : %d \n", dgm.sl);
}
void ThongKeSoLuongDocGiaTheoGioiTinh(MangDocGia DG)
{
	int nam = 0, nu = 0;
	LayDanhSachDocGia(DG);
	for (int i = 0; i < DG.n; i++)
	{
		if (strlen(DG.dg[i].GT) == 3)
			nam++;
		else
			nu++;
	}
	printf("So doc gia Nam la :%d \nSo doc gia Nu la :%d\n", nam, nu);
}
void ThongKeTheLoaiSachTrongThuVien(MangSach sa)
{
	LayDanhSachSach(sa);
	int j;
	int sum = 0;
	int hay = 0;
	int dung;

	if(sa.d!=0)
	{
		sum++;
	}
	while(sa.d!=0)
	{
		dung = 0;
		for (int i = 1; i < sa.d; i++)
	{
		j = 0;
		
		if (strlen(sa.Sa[0].THELOAISACH) != strlen(sa.Sa[i + 1].THELOAISACH))
		{
			dung++;
		}
		else
		{
			for (j; j < strlen(sa.Sa[0].THELOAISACH); j++)
			{
				if (sa.Sa[0].THELOAISACH[j] == sa.Sa[i].THELOAISACH[j])
				{
					hay++;
				}

			}
			if (strlen(sa.Sa[0].THELOAISACH) != hay)
			{
				dung++;
			}
			else
			{
				HamGiupXoaThongTinTheLoai(sa, i);
			}
		}

	}
	if (dung != 0)
	{
		sum++;
	}
	HamGiupXoaThongTinTheLoai(sa, 0);
}
	printf("So the loai trong thu vien la %d the loai \n", sum);
}
void HamGiupXoaThongTinTheLoai(MangSach &sa, int n)
{
	for (int i = n; i < sa.d - 1; i++)
	{

		if (strlen(sa.Sa[i].THELOAISACH) <= strlen(sa.Sa[i + 1].THELOAISACH))

			for (int i1 = 0; i1 <= strlen(sa.Sa[i + 1].THELOAISACH); i1++)
			{
				sa.Sa[i].THELOAISACH[i1] = sa.Sa[i + 1].THELOAISACH[i1];
			}
		else
			for (int i11 = 0; i11 < strlen(sa.Sa[i].THELOAISACH); i11++)
			{
				sa.Sa[i].THELOAISACH[i11] = sa.Sa[i + 1].THELOAISACH[i11];
			}
		
	}
	sa.d--;
}
void ThongKeDanhSachDocGiaBiTre()
{

}
void CapNhatThongTinDocGiaBiTreHen(int n)
{
	FILE *DG123;

	DG123 = fopen("sachmuon.txt", "a+t");
	fprintf(DG123, "%d",n);
	fclose(DG123);
}
void LayThongTinDocGiaTreHen(int n)
{

}
