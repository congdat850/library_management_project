#pragma once
#pragma once
struct DocGia
{
	char MDG[256];//1
	char TEN[256];//2
	char CMND[256];//3
	char NTNS[256];//4
	char GT[256];//5
	char EMAIL[256];//6
	char DC[256];//7
	int ND;//8
	int TD;//9
	int NaD;//10
	int NH;//11
	int TH;//12
	int NaH;//13
	int SoSachDangMuon;//14
	int MS;//1
		   //ngay thang muon tra sach;
	int NM;//2
	int TM;//3
	int NaM;//4
			// ngay thang tra sach;
	int NT;//5
	int TT;//6
	int NaT;//7
};
struct MangDocGia
{
	int n;
	DocGia dg[100];
};
void CapNhatThongTin(MangDocGia &DG);
void LayDanhSachDocGia(MangDocGia &DG);
void XuatDanhSachDocGia(MangDocGia &DG);
void ThemDocGia(MangDocGia &DG);
void TimTheoHoTen(MangDocGia DG);
void XuatDocGia(MangDocGia DG, int j);
void TimDocGiaTheoCMND(MangDocGia DG);
void XoaDocGia(MangDocGia &DG);
void ChinhSuaDocGia(MangDocGia &DG);
