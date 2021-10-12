struct Sach
{
	char ISBN[100];//1
	char TENSACH[100];//2
	char TACGIA[100];//3
	char NXB[100];//4
	char NaXB[100];//5
	char THELOAISACH[100];//6
	int GIASACH;//7
	int SoS;//8


};
struct MangSach
{
	int d;
	Sach Sa[100];
};
void XuatDanhSachSach(MangSach &sa);
void LayDanhSachSach(MangSach &sa);
void CapNhatSach(MangSach &sa);
void ThemSach(MangSach &sa);
void ChinhSuaThonhTinSach(MangSach &sa);
void XoaThongTinSach(MangSach &sa);
void XuatSach(MangSach sa, int j);
void TimSachTheoISBN(MangSach sa);
void TimSachTheoTen(MangSach sa);
