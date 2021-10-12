struct TraSach
{
	char mdg[100];
	char ISBN[100];
	char TenS[100];
	int GiaS;
	int ngaymuon;
	int thangmuon;
	int nammuon;
	int ngaytra;
	int thangtra;
	int namtra;

};
void LayThongTinSachTra(TraSach ts[100], MangMuon &dgm);
void CapNhatThongTinSachMuonTra(TraSach ts[100], MangMuon &dgm);
void TraSach123(TraSach ts[100], MangMuon &dgm);
int TruNgayThangNam(int &ngay, int &thang, int &nam, int &ngay1, int &thang1, int &nam1);
void HamGiupXoaSach(TraSach ts[100], MangMuon &dgm, int n);