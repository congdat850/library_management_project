struct dgmuon
{
	char madgmuon[100];
	char tendgmuon[100];
	int ssmuon;


};
struct smuon
{
	char ISBNm[100];
	char tsm[100];
	int ngaymuon;
	int thangmuon;
	int nammuon;
	int ngayhan;
	int thanghan;
	int namhan;
};
struct MangMuon
{
	int x;//so doc giam muon sach;
	int sl;//so lan muon sach
	dgmuon docgiam[100];
	smuon sm[100];
};

int kt_ngay_thang_nam(int &ngay, int &thang, int &nam);
void tim_7_ngay_sau(int ngay, int thang, int nam, int &ngay1, int &thang1, int &nam1);
void MuonSach(MangDocGia &mdg, MangSach &sa, MangMuon &dgm);
void CapNhatSachMuon(MangMuon dgm, MangDocGia mdg, MangSach sa, int hay, int hay1[100]);
void CapNhatSoDocGiaMuonSach(MangMuon &dgm);
void LaySoDocGiaMuonSach(MangMuon &dgm);
void CapNhatSoLanMuonSach(MangMuon &dgm);
void LaySoLanMuonSach(MangMuon &dgm);
