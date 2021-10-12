#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiDocGia.h"

void LayDanhSachDocGia(MangDocGia &DG)
{
	FILE*DG123;
	FILE*SoDG;
	SoDG = fopen("SoDG.txt", "a+t");
	fscanf(SoDG, "%d", &DG.n);
	fclose(SoDG);
	DG123 = fopen("DG1.txt", "a+t");
	for (int i = 0; i < DG.n; i++)
	{
		fscanf(DG123, "\n%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d\t%d\t%d]", &DG.dg[i].MDG, &DG.dg[i].TEN, &DG.dg[i].CMND, &DG.dg[i].NTNS, &DG.dg[i].GT, &DG.dg[i].EMAIL, &DG.dg[i].DC, &DG.dg[i].ND, &DG.dg[i].TD, &DG.dg[i].NaD, &DG.dg[i].SoSachDangMuon);
		if (DG.dg[i].SoSachDangMuon != 0)
		{
			fscanf(DG123, "%d\t%d\t%d\t%d\t%d\t%d\t%d", &DG.dg[i].MS, &DG.dg[i].NM, &DG.dg[i].TM, &DG.dg[i].NaM, &DG.dg[i].NT, &DG.dg[i].TT, &DG.dg[i].NaT);
		}
	}
	fclose(DG123);
}

void CapNhatThongTin(MangDocGia &DG)
{
	FILE *DG123;

	DG123 = fopen("DG1.txt", "w+t");

	for (int i = 0; i < DG.n; i++)
	{
		//===============================
		fprintf(DG123, "\n%s\t", DG.dg[i].MDG);


		fprintf(DG123, "%s\t", DG.dg[i].TEN);


		fprintf(DG123, "%s\t", DG.dg[i].CMND);


		fprintf(DG123, "%s\t", DG.dg[i].NTNS);


		fprintf(DG123, "%s\t", DG.dg[i].GT);


		fprintf(DG123, "%s\t", DG.dg[i].EMAIL);


		fprintf(DG123, "%s\t", DG.dg[i].DC);


		fprintf(DG123, "%d\t%d\t%d\t", DG.dg[i].ND, DG.dg[i].TD, DG.dg[i].NaD);

		fprintf(DG123, "%d", DG.dg[i].SoSachDangMuon);
	}
	fclose(DG123);
}
void XuatDanhSachDocGia(MangDocGia &DG)
{

	for (int j = 0; j < DG.n; j++)
	{
		printf("\n=======================================================================\n");
		printf("\n1)STT :");
		printf("%d",j+1);
		printf("\n2)Ma Doc Gia:");
		printf("%s", DG.dg[j].MDG);
		printf("\n3)Ho Va Ten:");
		printf("%s", DG.dg[j].TEN);
		printf("\n4)Chung Minh Nhan Dan: ");
		printf("%s", DG.dg[j].CMND);
		printf("\n5)Ngay/Thang/Nam Sinh: ");
		printf("%s", DG.dg[j].NTNS);
		printf("\n6)Gioi Tinh: ");
		printf("%s", DG.dg[j].GT);
		printf("\n7)Email: ");
		printf("%s", DG.dg[j].EMAIL);
		printf("\n8)Dia Chi: ");
		printf("%s", DG.dg[j].DC);
		printf("\n9)Ngay Thanh Lap The-Ngay Het Han The: ");
			printf("%d/%d/%d", DG.dg[j].ND,DG.dg[j].TD,DG.dg[j].NaD);
	}
}
void ThemDocGia(MangDocGia &DG)
{

	FILE *DG123;
	FILE *SoDG;

	DG.n++;

	DG123 = fopen("DG1.txt", "a+t");
	SoDG = fopen("SoDG.txt", "w+t");
	fprintf(SoDG, "%d", DG.n);


	printf("Nhap ma doc gia:");
	
	gets_s(DG.dg[DG.n - 1].MDG);
	gets_s(DG.dg[DG.n-1].MDG);
	fprintf(DG123, "\n%s\t", DG.dg[DG.n - 1].MDG);

	printf("Nhap ten doc gia:");
	gets_s(DG.dg[DG.n - 1].TEN);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].TEN);
	
	printf("Nhap so chung minh nhan dan");
	gets_s(DG.dg[DG.n - 1].CMND);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].CMND);

	printf("Nhap ngay thang nam sinh doc gia duoi dang XX/YY/ZZZZ");
	gets_s(DG.dg[DG.n - 1].NTNS);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].NTNS);

	printf("Nhap gioi tinh doc gia (Nam/Nu):");
	gets_s(DG.dg[DG.n - 1].GT);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].GT);

	printf("Nhap Email doc gia:");
	gets_s(DG.dg[DG.n - 1].EMAIL);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].EMAIL);

	printf("Nhap dia chi doc gia :");
	gets_s(DG.dg[DG.n - 1].DC);
	fprintf(DG123, "%s\t", DG.dg[DG.n - 1].DC);

	printf("Nhap ngay thanh lap the va ngay het han the duoi dang XX/YY/ZZZZ - XX/YY/ZZZZ :");
	scanf("%d%d%d", &DG.dg[DG.n - 1].ND, &DG.dg[DG.n - 1].TD, &DG.dg[DG.n - 1].NaD);
	fprintf(DG123, "%d\t%d\t%d", DG.dg[DG.n - 1].ND, DG.dg[DG.n - 1].TD, DG.dg[DG.n - 1].NaD);

	DG.dg[DG.n - 1].SoSachDangMuon = 0;
	fprintf(DG123, "\t%d", DG.dg[DG.n - 1].SoSachDangMuon);

	fcloseall();

	printf("*************************************************************************\n");
	printf("* Doc gia da duoc them vao.Ban co the vao danh sach doc gia de kiem tra *\n");
	printf("*************************************************************************\n");
}
void TimTheoHoTen(MangDocGia DG)
{
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char TEN[30];
	//=============================
	printf("Nhap ho va ten doc gia muon tim :");
	gets_s(TEN);
	gets_s(TEN);
	strlwr(TEN);
	//==============================
	char TENTAM[30];
	for (int i = 0; i < DG.n; i++)
	{
		for (int j2 = 0; j2 < strlen(DG.dg[i].TEN); j2++)
		{
			TENTAM[j2] = DG.dg[i].TEN[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(DG.dg[i].TEN); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(DG.dg[i].TEN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	//===============================
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("Ma so ban nhap khong co trong danh sach doc gia.\nVui long nhap lai:");
		gets_s(TEN);
		strlwr(TEN);
		for (int j = 0; j < DG.n; j++)
		{
			for (int j2 = 0; j2 < strlen(DG.dg[j].TEN); j2++)
			{
				TENTAM[j2] = DG.dg[j].TEN[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(DG.dg[j].TEN); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(DG.dg[dung1].TEN))
			{
				HAY = dung1;
			}
		}
	}
	//======================
	if (HAY != -1)
	{
		XuatDocGia(DG, HAY);
	}
}
void XuatDocGia(MangDocGia DG,int j)
{
	printf("\n1)STT :");
	printf("%d",j  + 1);
	printf("\n2)Ma Doc Gia:");
	printf("%s", DG.dg[j].MDG);
	printf("\n3)Ho Va Ten:");
	printf("%s", DG.dg[j].TEN);
	printf("\n4)Chung Minh Nhan Dan: ");
	printf("%s", DG.dg[j].CMND);
	printf("\n5)Ngay/Thang/Nam Sinh: ");
	printf("%s", DG.dg[j].NTNS);
	printf("\n6)Gioi Tinh: ");
	printf("%s", DG.dg[j].GT);
	printf("\n7)Email: ");
	printf("%s", DG.dg[j].EMAIL);
	printf("\n8)Dia Chi: ");
	printf("%s", DG.dg[j].DC);
	printf("\n9)Ngay Thanh Lap The-Ngay Het Han The: ");
	printf("%d/%d/%d", DG.dg[j].ND, DG.dg[j].TD, DG.dg[j].NaD);
	printf("\n");
}
void TimDocGiaTheoCMND(MangDocGia DG)
{

	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char TEN[30];
	//=============================
	printf("Nhap CMND doc gia muon tim :");
	gets_s(TEN);
	gets_s(TEN);
	strlwr(TEN);
	//==============================
	char TENTAM[30];
	for (int i = 0; i < DG.n; i++)
	{
		
		for (int j2 = 0; j2 < strlen(DG.dg[i].CMND); j2++)
		{
			TENTAM[j2] = DG.dg[i].CMND[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(DG.dg[i].CMND); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(DG.dg[i].CMND))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	//===============================
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("So CMND khong co trong danh sach.\nVui long nhap lai:");
		gets_s(TEN);
		strlwr(TEN);
		for (int j = 0; j < DG.n; j++)
		{
			for (int j2 = 0; j2 < strlen(DG.dg[j].CMND); j2++)
			{
				TENTAM[j2] = DG.dg[j].CMND[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(DG.dg[j].CMND); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(DG.dg[dung1].CMND))
			{
				HAY = dung1;
			}
		}
	}
	//======================
	if (HAY != -1)
	{
		XuatDocGia(DG, HAY);
	}
}
void XoaDocGia(MangDocGia &DG)
{
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char TEN[30];
	//=============================
	printf("Nhap ho va ten doc gia muon xoa :");
	gets_s(TEN);
	gets_s(TEN);
	strlwr(TEN);
	//==============================
	char TENTAM[30];
	for (int i = 0; i < DG.n; i++)
	{
		for (int j2 = 0; j2 < strlen(DG.dg[i].TEN); j2++)
		{
			TENTAM[j2] = DG.dg[i].TEN[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(DG.dg[i].TEN); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(DG.dg[i].TEN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	//===============================
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("Ma so ban nhap khong co trong danh sach doc gia.\nVui long nhap lai:");
		gets_s(TEN);
		strlwr(TEN);
		for (int j = 0; j < DG.n; j++)
		{
			for (int j2 = 0; j2 < strlen(DG.dg[j].TEN); j2++)
			{
				TENTAM[j2] = DG.dg[j].TEN[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(DG.dg[j].TEN); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(DG.dg[dung1].TEN))
			{
				HAY = dung1;
			}
		}
	}
	
	//======================
	if (HAY != -1)
	{
		while (HAY < DG.n-1)
		{

			if (strlen(DG.dg[HAY].MDG) <= strlen(DG.dg[HAY + 1].MDG))
			{
				for (int i2 = 0; i2 <= strlen(DG.dg[HAY + 1].MDG); i2++)
				{
					DG.dg[HAY].MDG[i2] = DG.dg[HAY + 1].MDG[i2];
				}

			}
			else
			{
				for (int i22 = 0; i22 < strlen(DG.dg[HAY].MDG); i22++)
				{
					DG.dg[HAY].MDG[i22] = DG.dg[HAY + 1].MDG[i22];
				}
			}


			if (strlen(DG.dg[HAY].TEN) <= strlen(DG.dg[HAY + 1].TEN))
			{

				for (int i3 = 0; i3 <= strlen(DG.dg[HAY + 1].TEN); i3++)
				{
					DG.dg[HAY].TEN[i3] = DG.dg[HAY + 1].TEN[i3];
				}
			}
			else
			{
				for (int i32 = 0; i32 < strlen(DG.dg[HAY].TEN); i32++)
				{
					DG.dg[HAY].TEN[i32] = DG.dg[HAY + 1].TEN[i32];
				}
			}


			if (strlen(DG.dg[HAY].CMND) <= strlen(DG.dg[HAY + 1].CMND))
			{

				for (int i4 = 0; i4 <= strlen(DG.dg[HAY + 1].CMND); i4++)
				{
					DG.dg[HAY].CMND[i4] = DG.dg[HAY + 1].CMND[i4];
				}
			}
			else
			{
				for (int i42 = 0; i42 < strlen(DG.dg[HAY].CMND); i42++)
				{
					DG.dg[HAY].CMND[i42] = DG.dg[HAY + 1].CMND[i42];
				}
			}


			if (strlen(DG.dg[HAY].NTNS) <= strlen(DG.dg[HAY + 1].NTNS))
			{

				for (int i5 = 0; i5 <= strlen(DG.dg[HAY + 1].NTNS); i5++)
				{
					DG.dg[HAY].NTNS[i5] = DG.dg[HAY + 1].NTNS[i5];
				}
			}
			else
			{
				for (int i52 = 0; i52 < strlen(DG.dg[HAY].NTNS); i52++)
				{
					DG.dg[HAY].NTNS[i52] = DG.dg[HAY + 1].NTNS[i52];
				}
			}


			if (strlen(DG.dg[HAY].GT) <= strlen(DG.dg[HAY + 1].GT))
			{

				for (int i6 = 0; i6 <= strlen(DG.dg[HAY + 1].GT); i6++)
				{
					DG.dg[HAY].GT[i6] = DG.dg[HAY + 1].GT[i6];
				}
			}
			else
			{
				for (int i62 = 0; i62 < strlen(DG.dg[HAY].GT); i62++)
				{
					DG.dg[HAY].GT[i62] = DG.dg[HAY + 1].GT[i62];
				}
			}


			if (strlen(DG.dg[HAY].EMAIL) <= strlen(DG.dg[HAY + 1].EMAIL))
			{

				for (int i7 = 0; i7 <= strlen(DG.dg[HAY + 1].EMAIL); i7++)
				{
					DG.dg[HAY].EMAIL[i7] = DG.dg[HAY + 1].EMAIL[i7];
				}
			}
			else
			{
				for (int i72 = 0; i72 < strlen(DG.dg[HAY].EMAIL); i72++)
				{
					DG.dg[HAY].EMAIL[i72] = DG.dg[HAY + 1].EMAIL[i72];
				}
			}


			if (strlen(DG.dg[HAY].DC) <= strlen(DG.dg[HAY + 1].DC))
			{

				for (int i8 = 0; i8 <= strlen(DG.dg[HAY + 1].DC); i8++)
				{
					DG.dg[HAY].DC[i8] = DG.dg[HAY + 1].DC[i8];
				}
			}
			else
			{
				for (int i82 = 0; i82 < strlen(DG.dg[HAY].DC); i82++)
				{
					DG.dg[HAY].DC[i82] = DG.dg[HAY + 1].DC[i82];
				}
			}
			DG.dg[HAY].ND = DG.dg[HAY + 1].ND;
			DG.dg[HAY].TD = DG.dg[HAY + 1].TD;
			DG.dg[HAY].NaD = DG.dg[HAY + 1].NaD;
			DG.dg[HAY].SoSachDangMuon = DG.dg[HAY + 1].SoSachDangMuon;
			HAY++;
		}//====== chuyen sau thanh truoc

			FILE *SoDG;
			DG.n--;
			SoDG = fopen("SoDG.txt", "w+t");
			fprintf(SoDG, "%d", DG.n);
			fclose(SoDG);
			fscanf(SoDG, "%d", DG.n);
			CapNhatThongTin(DG);

		
	}
	printf("****************************************************************\n");
	printf("* Doc gia da bi xoa .Ban co the vao danh sach de kiem tra      *\n");
	printf("****************************************************************\n");

	}


void ChinhSuaDocGia(MangDocGia &DG)
{
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char TEN[30];
	//=============================
	printf("Nhap ho va ten doc gia muon chinh sua :");
	gets_s(TEN);
	gets_s(TEN);
	strlwr(TEN);
	//==============================
	char TENTAM[30];
	for (int i = 0; i < DG.n; i++)
	{
		for (int j2 = 0; j2 < strlen(DG.dg[i].TEN); j2++)
		{
			TENTAM[j2] = DG.dg[i].TEN[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(DG.dg[i].TEN); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(DG.dg[i].TEN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	//===============================
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("Ma so ban nhap khong co trong danh sach doc gia.\nVui long nhap lai:");
		gets_s(TEN);
		strlwr(TEN);
		for (int j = 0; j < DG.n; j++)
		{
			for (int j2 = 0; j2 < strlen(DG.dg[j].TEN); j2++)
			{
				TENTAM[j2] = DG.dg[j].TEN[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(DG.dg[j].TEN); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}


			}
			if (dung == strlen(DG.dg[j].TEN))// khi da tim ra thi luu vi tri do vao HAY
			{
				HAY = dung1;
			}
		}
	}

			if (HAY != -1)
			{
				printf("\n");
				printf("Ban muon thay doi gi cua doc gia co ma so doc gia  %s ?\n", DG.dg[HAY].MDG);
				printf("1.Ma So Doc gia \n2.Ten\n3.Chung  minh nhan dan\n4.Ngay/Thang/Nam sinh.\n5.Gioi tinh\n6.Dia chi email.\n7.Dia Chi\n8.Ngay thanh lap the-Ngay het han the.");
				scanf("%d", &cn);
				printf("\n");
				switch (cn)
				{
				case 1:// sua ma doc gia
				{
					printf("Ma doc gia cu :%s\n", DG.dg[HAY].MDG);
					printf("Vui long nhap ma doc gia muon sua");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].MDG))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay1 = 0; thay1 < strlen(bientam); thay1++)
						{
							DG.dg[HAY].MDG[thay1] = bientam[thay1];
						}
					}
					else
					{
						for (int thay12 = 0; thay12 < strlen(DG.dg[HAY].MDG); thay12++)
						{
							DG.dg[HAY].MDG[thay12] = bientam[thay12];
						}
					}
					break;
				}
				case 2:
				{
					printf("Ho va ten doc gia cu: %s\n", DG.dg[HAY].TEN);
					printf("Vui long nhap ho va ten muon sua");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].TEN))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay2 = 0; thay2 < strlen(bientam); thay2++)
						{
							DG.dg[HAY].TEN[thay2] = bientam[thay2];
						}
					}
					else
					{
						for (int thay22 = 0; thay22 < strlen(DG.dg[HAY].TEN); thay22++)
						{
							DG.dg[HAY].TEN[thay22] = bientam[thay22];
						}
					}
					break;
				}
				case 3:
				{
					printf("So chung minh nhan dan doc gia cu: %s\n", DG.dg[HAY].CMND);
					printf("Vui long nhap so chung minh nhan dan muon sua: ");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].CMND))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay3 = 0; thay3 < strlen(bientam); thay3++)
						{
							DG.dg[HAY].CMND[thay3] = bientam[thay3];
						}
					}
					else
					{
						for (int thay32 = 0; thay32 < strlen(DG.dg[HAY].CMND); thay32++)
						{
							DG.dg[HAY].CMND[thay32] = bientam[thay32];
						}
					}
					break;

				}
				case 4:
				{
					printf("Ngay/Thang/Nam Sinh doc gia cu: %s\n", DG.dg[HAY].NTNS);
					printf("Vui long nhap Ngay/Thang/Nam Sinh muon sua(Ngay/Thang/Nam Sinh co dang XX/YY/ZZZZ): ");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].NTNS))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay4 = 0; thay4 < strlen(bientam); thay4++)
						{
							DG.dg[HAY].NTNS[thay4] = bientam[thay4];
						}
					}
					else
					{
						for (int thay42 = 0; thay42 < strlen(DG.dg[HAY].NTNS); thay42++)
						{
							DG.dg[HAY].NTNS[thay42] = bientam[thay42];
						}
					}
					break;
				}
				case 5:
				{
					printf("Gioi tinh doc gia cu: %s\n", DG.dg[HAY].GT);
					printf("Vui long nhap gioi tinh muon sua: ");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].GT))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay5 = 0; thay5 < strlen(bientam); thay5++)
						{
							DG.dg[HAY].GT[thay5] = bientam[thay5];
						}
					}
					else
					{
						for (int thay52 = 0; thay52 < strlen(DG.dg[HAY].GT); thay52++)
						{
							DG.dg[HAY].GT[thay52] = bientam[thay52];
						}
					}
					break;
				}
				case 6:
				{
					printf("Email doc gia cu: %s\n", DG.dg[HAY].EMAIL);
					printf("Vui long nhap email muon sua: ");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].EMAIL))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay6 = 0; thay6 < strlen(bientam); thay6++)
						{
							DG.dg[HAY].EMAIL[thay6] = bientam[thay6];
						}
					}
					else
					{
						for (int thay62 = 0; thay62 < strlen(DG.dg[HAY].EMAIL); thay62++)
						{
							DG.dg[HAY].EMAIL[thay62] = bientam[thay62];
						}
					}
					break;
				}
				case 7:
				{
					printf("Dia chi doc gia cu: %s\n", DG.dg[HAY].DC);
					printf("Vui long nhap dia chi muon sua: ");
					gets_s(bientam);
					gets_s(bientam);
					if (strlen(bientam) >= strlen(DG.dg[HAY].DC))// so sanh de ra su lua chon cho khi chen vao.
					{
						for (int thay7 = 0; thay7 < strlen(bientam); thay7++)
						{
							DG.dg[HAY].DC[thay7] = bientam[thay7];
						}
					}
					else
					{
						for (int thay72 = 0; thay72 < strlen(DG.dg[HAY].DC); thay72++)
						{
							DG.dg[HAY].DC[thay72] = bientam[thay72];
						}
					}
					break;
				}
				case 8:
				{
					printf("Ngay lap the-Ngay het han doc gia cu: %d/%d/%d\n", DG.dg[HAY].ND, DG.dg[HAY].TD, DG.dg[HAY].NaD);
					printf("Vui long nhap Ngay lap the-Ngay het han muon sua: ");
					scanf("%d%d%d", &DG.dg[HAY].ND, &DG.dg[HAY].TD, &DG.dg[HAY].NaD);
					break;
				}
				
				}
				CapNhatThongTin(DG);
			}
			printf("***************************************************************************\n");
			printf("* Doc gia da bi chinh sua. Ban co the vao danh sach doc gia de kiem tra   *\n");
			printf("***************************************************************************\n");
		}