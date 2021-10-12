#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiSach.h"
#include"QuanLiDocGia.h"
#include"MuonSach.h"
int kt_ngay_thang_nam(int &ngay, int &thang, int &nam)
{
	int s = 1;
	if (nam >= 0)
	{
		s = s;
		if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0)))
		{
			if ((thang > 0 && thang <= 12))
			{
				if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
				{
					s = s;
					if (ngay > 0 && ngay <= 31)
						s = s;
					else
					{
						s = 0;
					}
				}
				else
				{
					s = s;
					if (ngay > 0 && ngay <= 30 && (thang != 2))
					{
						s = s;
					}
					else
					{
						if (thang == 2 && ngay > 0 && ngay <= 29)
						{
							s = s;
						}
						else
							s = 0;
					}

				}

			}
			else
				s = 0;
		}
		else
		{
			if (thang > 0 && thang <= 12)
			{
				if (thang > 0 && thang <= 12 && (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12))
				{
					s = s;
					if (ngay > 0 && ngay <= 31)
						s = s;
					else
						s = 0;
				}
				else
				{
					if (thang != 2 && ngay > 0 && ngay <= 30)
						s = s;
					else
					{
						if (thang == 2 && ngay > 0 && ngay <= 28)
							s = s;
						else
							s = 0;
					}
				}
			}
			else
				s = 0;
		}

	}
	return s;
}
//=============================
void tim_7_ngay_sau(int ngay, int thang, int nam, int &ngay1, int &thang1, int &nam1)
{
	int d = ngay, m = thang, y = nam;
	for (int i = 1; i <= 7; i++)
	{
		switch (m)
		{
		case 1:case 3: case 5: case 7: case 8: case 10:
			if (d >0 && d <31)
			{
				d = d + 1;
				m = m;
				y = y; break;
			}
			if (d == 31)
			{
				d = 1;
				m = m + 1;
				y = y; break;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (d >0 && d <30)
			{
				d = d + 1;
				m = m;
				y = y; break;
			}
			if (d == 30)
			{
				d = 1;
				m = m + 1;
				y = y; break;
			}
			break;
		case 2:
			if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0)))
			{
				if (d >0 && d <29)
				{
					d = d + 1;
					m = m;
					y = y; break;
				}
				if (d == 29)
				{
					d = 1;
					m = m + 1;
					y = y; break;
				}
			}
			else
			{
				if (d >0 && d <28)
				{
					d = d + 1;
					m = m;
					y = y; break;
				}
				if (d == 28)
				{
					d = 1;
					m = m + 1;
					y = y; break;
				}
			}
			break;
		case 12:
			if (d >0 && d <31)
			{
				d = d + 1;
				m = m;
				y = y;
				break;
			}
			if (d == 31)
			{
				d = 1;
				m = 1;
				y = y + 1; break;
			}
		}
	}
	ngay1 = d;
	thang1 = m;
	nam1 = y;
}
void MuonSach(MangDocGia &mdg, MangSach &sa, MangMuon &dgm)
{
	LaySoDocGiaMuonSach(dgm);
	LaySoLanMuonSach(dgm);
	int can;
	int chon = 1;
	int them = 0;
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	int HAY1[100];
	char CMND[30];
	int VTDG = -1;
	dgm.x++;// tang the thoi gian
	dgm.docgiam[dgm.x].ssmuon = 0;
	printf(" Nhap ma doc gia muon muon sach :");
	gets_s(CMND);
	
	gets_s(CMND);
	for (int i = 0; i < mdg.n; i++)
	{
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(mdg.dg[i].MDG); i1++)
		{
			if (CMND[i1] == mdg.dg[i].MDG[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon muon
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(mdg.dg[i].MDG))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("Ma doc gia khong co trong thu vien.\nVui long nhap lai:");
		gets_s(CMND);
		for (int j = 0; j < mdg.n; j++)
		{
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(mdg.dg[j].MDG); j1++)
			{
				if (CMND[j1] == mdg.dg[j].MDG[j1])// lay vi tri cua doc gia muon muon.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(mdg.dg[j].MDG))
			{
				HAY = dung1;
			}
		}
	}
	if (HAY != -1)
	{
	VTDG = HAY;
	}//=========================== lay vi tri cua doc gia muon muon========================

	while (chon == 1)
	{
		dgm.docgiam[dgm.x].ssmuon = dgm.docgiam[dgm.x].ssmuon + 1;//them: la luu vitri dgm
		dgm.sl = dgm.sl + 1;
		char bientam1[30];
		int cn1;
		int dung2;
		int dung22; 
		HAY = -1;
		HAY1[dgm.docgiam[dgm.x].ssmuon] = -1;
		char CMND1[30];
		printf("Nhap ISBN sach muon muon sach :");
		gets_s(CMND1);
		for (int i2 = 0; i2 < sa.d; i2++)
		{
			dung2 = 0;
			dung22 = -1;
			for (int i12 = 0; i12 < strlen(sa.Sa[i2].ISBN); i12++)
			{
				if (CMND1[i12] == sa.Sa[i2].ISBN[i12])//So sanh ISBN de tim ra vi tri sach muon muon.
				{
					dung2++;
					dung22 = i2;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
				}
			}
			if (dung2 == strlen(sa.Sa[i2].ISBN))// khi da tim ra thi luu vi tri do vao HAY
			{
				HAY1[dgm.docgiam[dgm.x].ssmuon] = dung22;
			}
		}
		while (HAY1[dgm.docgiam[dgm.x].ssmuon] == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
		{
			printf("Nhap sai vui long. Nhap ISBN muon muon:");
			gets_s(CMND1);
			for (int j2 = 0; j2 < sa.d; j2++)
			{
				dung2 = 0;
				dung22 = -1;
				for (int j12 = 0; j12 < strlen(sa.Sa[j2].ISBN); j12++)
				{
					if (CMND1[j12] == sa.Sa[j2].ISBN[j12])// lay vi tri cua doc gia muon chinh sua.
					{
						dung2++;
						dung22 = j2;
					}
				}
				if (dung2 == strlen(sa.Sa[j2].ISBN))
				{
					HAY1[dgm.docgiam[dgm.x].ssmuon] = dung22;
				}
			}
		}
		printf("Nhap ngay muon sach:");
		scanf("%d", &dgm.sm[dgm.docgiam[dgm.x].ssmuon].ngaymuon);
		printf("Nhap thang muon sach");
		scanf("%d", &dgm.sm[dgm.docgiam[dgm.x].ssmuon].thangmuon);
		printf("Nhap nam muon sach");
		scanf("%d", &dgm.sm[dgm.docgiam[dgm.x].ssmuon].nammuon);
		while (kt_ngay_thang_nam(dgm.sm[dgm.docgiam[dgm.x].ssmuon].ngaymuon, dgm.sm[dgm.docgiam[dgm.x].ssmuon].thangmuon, dgm.sm[dgm.docgiam[dgm.x].ssmuon].nammuon) == 0)//=============giup nhap ngay thang nam cho den khi dung.
		{
			printf("Ngay Thang nam khong hop le vui long nhap lai\n");
			printf("Nhap ngay muon sach:");
			scanf("%d", &dgm.sm[dgm.docgiam[dgm.x ].ssmuon].ngaymuon);
			printf("Nhap thang muon sach");
			scanf("%d", &dgm.sm[dgm.docgiam[dgm.x].ssmuon].thangmuon);
			printf("Nhap nam muon sach");
			scanf("%d", &dgm.sm[dgm.docgiam[dgm.x ].ssmuon].nammuon);
		}
		tim_7_ngay_sau(dgm.sm[dgm.docgiam[dgm.x].ssmuon].ngaymuon, dgm.sm[dgm.docgiam[dgm.x].ssmuon].thangmuon, dgm.sm[dgm.docgiam[dgm.x].ssmuon].nammuon, dgm.sm[dgm.docgiam[dgm.x].ssmuon].ngayhan, dgm.sm[dgm.docgiam[dgm.x].ssmuon].thanghan, dgm.sm[dgm.docgiam[dgm.x].ssmuon].namhan);// tinh han cho cuon sach duoc muon

		//============================================================
		chon = 0;
		if (chon == 0)
		{
			printf("Ban co muon muon nua hay khong ? Co:1    Khong:0 ");
			scanf("%d", &chon);
		}
		gets_s(CMND1);//===================================


	}
	printf("***************************************************************************\n");
	printf("                             PHIEU MUON SACH\n");
	printf("   +)Thong tin doc gia muon sach :\n");
	printf("1)Ma doc gia:");

	printf("%s", mdg.dg[VTDG].MDG);
	printf("\n");
	printf("2)Ten doc gia:");

	printf("%s", mdg.dg[VTDG].TEN);

	printf("\n");
	printf("    +)Thong tin sach muon\n");
	for (int j = 1; j <= dgm.docgiam[dgm.x].ssmuon; j++)
	{
		printf("1)ISBN:");

		printf("%s", sa.Sa[HAY1[j]].ISBN);

		printf("\n");
		printf("2)Ten sach:");

		printf("%s", sa.Sa[HAY1[j]].TENSACH);

		printf("\n");
		printf("3)Ngay/thang/nam muon:%d/%d/%d\n", dgm.sm[j].ngaymuon, dgm.sm[j].thangmuon, dgm.sm[j].nammuon);
		printf("4)Ngay/thang/nam phai tra sach:%d/%d/%d\n", dgm.sm[j].ngayhan, dgm.sm[j].thanghan, dgm.sm[j].namhan);
	}
	CapNhatSoDocGiaMuonSach(dgm);
	CapNhatSoLanMuonSach(dgm);
	
	CapNhatSachMuon(dgm, mdg, sa, VTDG, HAY1);
}
void CapNhatSachMuon(MangMuon dgm,MangDocGia mdg,MangSach sa,int hay,int hay1[100])
{///////////////////


	FILE *DG123;

	DG123 = fopen("sachmuon.txt", "a+t");

	for (int i = 0; i < dgm.docgiam[dgm.x].ssmuon; i++)
	{
		// nen luu them ma doc gia.
		//===============================
		fprintf(DG123, "\n%s\t", mdg.dg[hay].MDG);


		fprintf(DG123, "%s\t", sa.Sa[hay1[i+1]].ISBN);//hay1 la 1 mang


		fprintf(DG123, "%s\t", sa.Sa[hay1[i+1]].TENSACH);


		fprintf(DG123, "%d\t", sa.Sa[hay1[i+1]].GIASACH);


		fprintf(DG123, "%d\t", dgm.sm[i+1].ngaymuon);


		fprintf(DG123, "%d\t", dgm.sm[i+1].thangmuon);


		fprintf(DG123, "%d\t", dgm.sm[i+1].nammuon);


		fprintf(DG123, "%d\t", dgm.sm[i+1].ngayhan);


		fprintf(DG123, "%d\t", dgm.sm[i+1].thanghan);


		fprintf(DG123, "%d\t", dgm.sm[i+1].namhan);

	}
	fclose(DG123);
}
void CapNhatSoDocGiaMuonSach(MangMuon &dgm)
{
	FILE *DG123;

	DG123 = fopen("sodgmuonsach.txt", "w+t");
	fprintf(DG123, "%d", dgm.x);
	fclose(DG123);
}
void LaySoDocGiaMuonSach(MangMuon &dgm)
{
	FILE *DG123;

	DG123 = fopen("sodgmuonsach.txt", "a+t");
	fscanf(DG123, "%d", &dgm.x);
	fclose(DG123);
}
void CapNhatSoLanMuonSach(MangMuon &dgm)
{
	FILE *DG123;

	DG123 = fopen("solanmuonsach.txt", "w+t");
	fprintf(DG123, "%d", dgm.sl);
	fclose(DG123);
}
void LaySoLanMuonSach(MangMuon &dgm)
{
	FILE *DG123;

	DG123 = fopen("solanmuonsach.txt", "a+t");
	fscanf(DG123, "%d", &dgm.sl);
	fclose(DG123);
}
