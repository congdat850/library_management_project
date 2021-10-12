#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiSach.h"
#include"QuanLiDocGia.h"
#include"MuonSach.h"
#include"TraSach.h"
void LayThongTinSachTra(TraSach ts[100],MangMuon &dgm)
{
   
	FILE *DG123;
	DG123 = fopen("sachmuon.txt", "a+t");
	for (int i = 0; i < dgm.sl; i++)
	{

		//   \n%[^\t]\t%
		fscanf(DG123, "\n%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &ts[i].mdg, &ts[i].ISBN, &ts[i].TenS, &ts[i].GiaS, &ts[i].ngaymuon, &ts[i].thangmuon, &ts[i].nammuon, &ts[i].ngaytra, &ts[i].thangtra, &ts[i].namtra);

	}
	fclose(DG123);


}
void CapNhatThongTinSachMuonTra(TraSach ts[100],MangMuon &dgm)
{
	FILE *DG123;

DG123 = fopen("sachmuon.txt", "w+t");

for (int i = 0; i < dgm.sl-1; i++)
{
	//===============================
	fprintf(DG123, "\n%s\t", ts[i].mdg);


	fprintf(DG123, "%s\t", ts[i].ISBN);


	fprintf(DG123, "%s\t", ts[i].TenS);


	fprintf(DG123, "%d\t", ts[i].GiaS);


	fprintf(DG123, "%d\t", ts[i].ngaymuon);


	fprintf(DG123, "%d\t", ts[i].thangmuon);


	fprintf(DG123, "%d\t", ts[i].nammuon);


	fprintf(DG123, "%d\t", ts[i].ngaytra);


	fprintf(DG123, "%d\t", ts[i].thangtra);


	fprintf(DG123, "%d", ts[i].namtra);

}
fclose(DG123);
dgm.sl--;
FILE*slsachmuon123;
slsachmuon123 = fopen("solanmuonsach.txt", "w+t");
fprintf(slsachmuon123, "%d", dgm.sl);
fclose(slsachmuon123);

}

void TraSach123(TraSach ts[100], MangMuon &dgm)
{
	LaySoLanMuonSach(dgm);
	LayThongTinSachTra(ts, dgm);
	int can;
	int chon = 1;
	int them = 0;
	char bientam[30];
	int cn;
	int dung;
	int a = 0;
	int dung1;
	int dung2;
	int dung22;
	int HAY = -1;
	int HAY1 = -1;
	int ktms = 0;
	char CMND[30];
	char CMND1[30];
	int QUAHAY = -1;
	int VTDG = -1;
	int tienno = 0;
	int ngaytra, thangtra, namtra;
	int tongsachtrehen = 0;
	int tongsachlammat = 0;
	dgm.x++;// tang the thoi gian
	while (chon == 1)
	{
		if (a != 1)
		{
			printf(" Nhap ma doc gia muon muon sach :");
			gets_s(CMND);
			gets_s(CMND);
		}
		printf("Nhap ISBN muon tra:");
		gets_s(CMND1);
		for (int i = 0; i < dgm.sl; i++)
		{
			dung = 0;
			dung1 = -1;
			dung2 = 0;
			dung22 = -1;
			for (int i1 = 0; i1 < strlen(ts[i].mdg); i1++)
			{
				if (CMND[i1] == ts[i].mdg[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon muon
				{
					dung++;
					dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
				}
			}
			if (dung == strlen(ts[i].mdg))// khi da tim ra thi luu vi tri do vao HAY
			{
				HAY = dung1;
			}
			//=====================
			for (int i12 = 0; i12 < strlen(ts[i].ISBN); i12++)
			{
				if (CMND1[i12] == ts[i].ISBN[i12])//So sanh ISBN de tim ra vi tri sach muon muon.
				{
					dung2++;
					dung22 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
				}

				if (dung2 == strlen(ts[i].ISBN))// khi da tim ra thi luu vi tri do vao HAY
				{
					HAY1 = dung22;
				}
				if (HAY1 == HAY)
				{
					QUAHAY = HAY;
				}
			}
		}
		while (QUAHAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
		{
			printf("Ma doc gia hoac ma ISBN khong co trong danh sach muon.\nVui long nhap lai:\n");
			printf(" Nhap ma doc gia muon muon sach :");
			gets_s(CMND);
			printf("Nhap sai vui long. Nhap ISBN muon muon:");
			gets_s(CMND1);
			for (int j = 0; j < dgm.sl; j++)
			{
				dung = 0;
				dung1 = -1;
				dung2 = 0;
				dung22 = -1;
				for (int j1 = 0; j1 < strlen(ts[j].mdg); j1++)
				{
					if (CMND[j1] == ts[j].mdg[j1])// lay vi tri cua doc gia muon muon.
					{
						dung++;
						dung1 = j;
					}
				}
				if (dung == strlen(ts[j].mdg))
				{
					HAY = dung1;
				}

				//==============

				for (int j12 = 0; j12 < strlen(ts[j].ISBN); j12++)
				{
					if (CMND1[j12] == ts[j].ISBN[j12])// lay vi tri cua doc gia muon chinh sua.
					{
						dung2++;
						dung22 = j;
					}
				}
				if (dung2 == strlen(ts[j].ISBN))
				{
					HAY1 = dung22;
				}
				if (HAY == HAY1)
				{
					QUAHAY = HAY;
				}
			}

		}

		if (QUAHAY != -1)
		{
			VTDG = QUAHAY;

			//======================================
			printf("=================================================\n");
			printf("Nhap ngay tra sach:");
			scanf("%d", &ngaytra);
			printf("Nhap thang tra sach");
			scanf("%d", &thangtra);
			printf("Nhap nam tra sach");
			scanf("%d", &namtra);
			while (kt_ngay_thang_nam(ngaytra, thangtra, namtra) == 0)// giup nhap ngay thang nao cho den khi dung.
			{
				printf("Ngay Thang nam khong hop le vui long nhap lai\n");
				printf("Nhap ngay muon sach:");
				scanf("%d", &ngaytra);
				printf("Nhap thang muon sach");
				scanf("%d", &thangtra);
				printf("Nhap nam muon sach");
				scanf("%d", &namtra);
			}
			printf("================================================\n");
			printf("Han cua ban la tu ngay%d/%d/%d den %d/%d/%d\n", ts[HAY1].ngaymuon, ts[HAY1].thangmuon, ts[HAY1].nammuon, ts[HAY1].ngaytra, ts[HAY1].thangtra, ts[HAY1].namtra);
			if (TruNgayThangNam(ts[HAY1].ngaytra, ts[HAY1].thangtra, ts[HAY1].namtra, ngaytra, thangtra, namtra) > 0)// kiem tra xem doc gia co tra tre han khong
			{//Nhap tre han
				printf("================================================\n");
				tienno = TruNgayThangNam(ts[HAY1].ngaytra, ts[HAY1].thangtra, ts[HAY1].namtra, ngaytra, thangtra, namtra) * 5000 + tienno;// giup tnh tien phai boi thuong ngay luc muoi tra.
				printf("Ban da tre %d ngay(tien phat 5000/ngay)\n", TruNgayThangNam(ts[HAY1].ngaytra, ts[HAY1].thangtra, ts[HAY1].namtra, ngaytra, thangtra, namtra));
				printf("Tien phat hien tai  cua ban la:%d\n", tienno);
				tongsachtrehen++;
			}
			else// khong nhap tre han.
			{
				tienno = tienno;
				printf("Tien phat hien tai  cua ban la:%d\n", tienno);
			}


			chon = 0;
			if (chon == 0)
			{
				HamGiupXoaSach(ts,dgm, HAY1);
				CapNhatThongTinSachMuonTra(ts,dgm);
				printf("\n");
				printf("**********************************************************\n");
				printf("*    Ban co muon tra  nua hay khong ? Co:1    Khong:0    *\n");
				printf("**********************************************************\n");
				scanf("%d", &chon);
				a = chon;
			}
			gets_s(CMND1);
			//============================ranh gioi
			printf("\n");
			printf("******************************************************************\n");
			printf("*   Ban co lam mat cuon sach nao hay khong ?   Co:1     Khong:0  *\n");
			printf("******************************************************************\n");
			scanf("%d", &ktms);
			if (ktms == 1)
			{
				int chon1 = 1;
				while (chon1 == 1)
				{
					char bientam1[30];
					int cn1;
					int dung26;
					int dung226;
					int HAY26 = -1;
					int HAY5 = -1;
					int QUAHAY2 = -1;
					char CMND1[30];
					printf("Nhap ISBN sach ban da lam mat :");
					gets_s(CMND1);
					gets_s(CMND1);
					for (int i2 = 0; i2 < dgm.sl; i2++)
					{
						dung26 = 0;
						dung226 = -1;
						for (int i12 = 0; i12 < strlen(ts[i2].ISBN); i12++)
						{
							if (CMND1[i12] == ts[i2].ISBN[i12])//So sanh giup tim ra  cuon sach da lam mat de phat tien
							{
								dung26++;
								dung226 = i2;// luu vi tri sach tam thoi .khi nao dung thi luu vao buoc duoi
							}
						}


						if (dung26 == strlen(ts[i2].ISBN))// khi da tim ra thi luu vi tri do vao HAY
						{
							HAY26 = dung226;
						}
						//==========================
						dung = 0;
						dung1 = -1;
						for (int i1 = 0; i1 < strlen(ts[i2].mdg); i1++)
						{
							if (CMND[i1] == ts[i2].mdg[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon muon
							{
								dung++;
								dung1 = i2;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
							}
						}
						if (dung == strlen(ts[i2].mdg))// khi da tim ra thi luu vi tri do vao HAY
						{
							HAY5 = dung1;
						}

						if (HAY26 == HAY5)
						{
							QUAHAY2 = HAY26;

						}
					}
					while (HAY26 == -1)// Giup nhap ISBN cho den khi tim ra ISBN co trong danh sach dang muon.
					{
						printf("Nhap sai vui long. Nhap ISBN sach ban da lam mat:");
						gets_s(CMND1);
						for (int j2 = 0; j2 < dgm.sl; j2++)
						{
							dung26 = 0;
							dung226 = -1;
							for (int j12 = 0; j12 < strlen(ts[j2].ISBN); j12++)
							{
								if (CMND1[j12] == ts[j2].ISBN[j12])
								{
									dung26++;
									dung226 = j2;
								}
							}
							if (dung26 == strlen(ts[j2].ISBN))
							{
								HAY26 = dung226;
							}
							dung = 0;
							dung1 = -1;
							for (int i1 = 0; i1 < strlen(ts[j2].mdg); i1++)
							{
								if (CMND[i1] == ts[j2].mdg[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon muon
								{
									dung++;
									dung1 = j2;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
								}
							}
							if (dung == strlen(ts[j2].mdg))// khi da tim ra thi luu vi tri do vao HAY
							{
								HAY5 = dung1;
							}

							if (HAY26 == HAY5)
							{
								QUAHAY2 = HAY26;

							}

						}
					}
					if (QUAHAY2 == -1)
					{
						printf("Doc gia %s ko co muon sach %s ", CMND, CMND1);
						

					}
					else
					{
						tienno = ts[QUAHAY2].GiaS * 2 + tienno;
						printf("===================================================\n");
						printf("Ban da lam mat cuon sach %s gia %d(mat sach phai bio thuong 200 phan tram )\n", ts[QUAHAY2].TenS,ts[QUAHAY2].GiaS);
						printf("Tong tien phat hien gio la %d\n", tienno);
						tongsachlammat++;
						HamGiupXoaSach(ts, dgm, HAY1);
						CapNhatThongTinSachMuonTra(ts, dgm);
					}



					chon1 = 0;
					if (chon1 == 0)
					{
						printf("Ban co lam mat cuon sach nao nua hay khong ? Co:1    Khong:0 ");
						scanf("%d", &chon1);
					}



				}

			}//===================xong phan tinh toan==========================
			int vtdg = HAY;//========================Phan in phieu tra sach================
			printf("***************************************************************************\n");
			printf("                             PHIEU TRA SACH\n");
			printf("   +)Thong tin doc gia tra sach :\n");
			printf("1)Ma doc gia:");
			printf("%s\n", CMND);
			printf("\n");
			printf("Tong so sach tre hen :la %d\n", tongsachtrehen);
			printf("Tong sach lam mat la: %d\n", tongsachlammat);
			printf("Tong so tien phat la: %d\n", tienno);

			}
		}


		}
	




int TruNgayThangNam(int &ngay, int &thang, int &nam, int &ngay1, int &thang1, int &nam1)
{
	int sum1, sum, hieu;
	if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0)))
	{
		if (thang == 1)
			sum1 = ngay;
		if (thang == 2)
			sum1 = 31 + ngay;
		if (thang == 3)
			sum1 = 60 + ngay;
		if (thang == 4)
			sum1 = 91 + ngay;
		if (thang == 5)
			sum1 = 121 + ngay;
		if (thang == 6)
			sum1 = 152 + ngay;
		if (thang == 7)
			sum1 = 182 + ngay;
		if (thang == 8)
			sum1 = 213 + ngay;
		if (thang == 9)
			sum1 = 244 + ngay;
		if (thang == 10)
			sum1 = 274 + ngay;
		if (thang == 11)
			sum1 = 305 + ngay;
		if (thang == 12)
			sum1 = 335 + ngay;
	}
	else
	{

		if (thang == 1)
			sum1 = ngay;
		if (thang == 2)
			sum1 = 31 + ngay;
		if (thang == 3)
			sum1 = 59 + ngay;
		if (thang == 4)
			sum1 = 90 + ngay;
		if (thang == 5)
			sum1 = 120 + ngay;
		if (thang == 6)
			sum1 = 151 + ngay;
		if (thang == 7)
			sum1 = 181 + ngay;
		if (thang == 8)
			sum1 = 212 + ngay;
		if (thang == 9)
			sum1 = 243 + ngay;
		if (thang == 10)
			sum1 = 273 + ngay;
		if (thang == 11)
			sum1 = 304 + ngay;
		if (thang == 12)
			sum1 = 334 + ngay;
	}
	if ((nam1 % 400 == 0) || ((nam1 % 4 == 0) && (nam1 % 100 != 0)))
	{
		if (thang1 == 1)
			sum = ngay1;
		if (thang1 == 2)
			sum = 31 + ngay1;
		if (thang1 == 3)
			sum = 60 + ngay1;
		if (thang1 == 4)
			sum = 91 + ngay1;
		if (thang1 == 5)
			sum = 121 + ngay1;
		if (thang1 == 6)
			sum = 152 + ngay1;
		if (thang1 == 7)
			sum = 182 + ngay1;
		if (thang1 == 8)
			sum = 213 + ngay1;
		if (thang1 == 9)
			sum = 244 + ngay1;
		if (thang1 == 10)
			sum = 274 + ngay1;
		if (thang1 == 11)
			sum = 305 + ngay1;
		if (thang1 == 12)
			sum = 335 + ngay1;
	}
	else
	{

		if (thang1 == 1)
			sum = ngay1;
		if (thang1 == 2)
			sum = 31 + ngay1;
		if (thang1 == 3)
			sum = 59 + ngay1;
		if (thang1 == 4)
			sum = 90 + ngay1;
		if (thang1 == 5)
			sum = 120 + ngay1;
		if (thang1 == 6)
			sum = 151 + ngay1;
		if (thang1 == 7)
			sum = 181 + ngay1;
		if (thang1 == 8)
			sum = 212 + ngay1;
		if (thang1 == 9)
			sum = 243 + ngay1;
		if (thang1 == 10)
			sum = 273 + ngay1;
		if (thang1 == 11)
			sum = 304 + ngay1;
		if (thang1 == 12)
			sum = 334 + ngay1;
	}
	if (nam1 > nam)
	{
		if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0)))
		{
			sum = sum + 365;
		}
		else
			sum = sum + 364;
	}
	hieu = sum - sum1;
	return hieu;
}
void HamGiupXoaSach(TraSach ts[100], MangMuon &dgm, int n)
{
	for (int i = n; i < dgm.sl-1; i++)
	{
		
		if (strlen(ts[i].mdg) <= strlen(ts[i + 1].mdg))

			for (int i1 = 0; i1 <= strlen(ts[i + 1].mdg); i1++)
			{
				ts[i].mdg[i1] = ts[i+1].mdg[i1];
			}
		else
			for (int i11 = 0; i11 < strlen(ts[i].mdg); i11++)
			{
				ts[i].mdg[i11] = ts[i+1].mdg[i11];
			}


		//ts[i].ISBN);
		if (strlen(ts[i].ISBN) <= strlen(ts[i + 1].ISBN))

			for (int i1 = 0; i1 <= strlen(ts[i + 1].ISBN); i1++)
			{
				ts[i].ISBN[i1] = ts[i + 1].ISBN[i1];
			}
		else
			for (int i11 = 0; i11 < strlen(ts[i].ISBN); i11++)
			{
				ts[i].ISBN[i11] = ts[i + 1].ISBN[i11];
			}

		


		//ts[i].TenS);
		int hay;
		if (strlen(ts[i].TenS) <= strlen(ts[i + 1].TenS))

		{
			for (int i1 = 0; i1 <= strlen(ts[i + 1].TenS); i1++)
			{
				ts[i].TenS[i1] = ts[i + 1].TenS[i1];
				hay = i1;
			}
		}
		else
			for (int i11 = 0; i11 < strlen(ts[i].TenS); i11++)
			{
				ts[i].TenS[i11] = ts[i + 1].TenS[i11];
			}



		ts[i].GiaS = ts[i+1].GiaS;


		ts[i].ngaymuon = ts[i+1].ngaymuon;


		ts[i].thangmuon = ts[i + 1].thangmuon;


		ts[i].nammuon = ts[i + 1].nammuon;


		ts[i].ngaytra = ts[i + 1].ngaytra;


		ts[i].thangtra = ts[i + 1].thangtra;


		ts[i].namtra = ts[i + 1].namtra;
	}
}
