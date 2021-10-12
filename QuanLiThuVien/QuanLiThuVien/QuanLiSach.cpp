#include<stdio.h>
#include<conio.h>
#include<string>
#include"QuanLiSach.h"
void LayDanhSachSach(MangSach &sa)
{
	FILE*Sa;
	FILE*Sos;
	Sos = fopen("SoS.txt", "a+t");
	fscanf(Sos, "%d", &sa.d);
	fclose(Sos);
	Sa = fopen("S.txt", "a+t");
	for (int i = 0; i < sa.d; i++)
	{
		fscanf(Sa, "\n%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d\t%d]", &sa.Sa[i].ISBN, &sa.Sa[i].TENSACH, &sa.Sa[i].TACGIA, &sa.Sa[i].NXB, &sa.Sa[i].NaXB, &sa.Sa[i].THELOAISACH, &sa.Sa[i].GIASACH, &sa.Sa[i].SoS);
	}
	fclose(Sa);
}
void XuatDanhSachSach(MangSach &sa)
{
	for (int j = 0; j < sa.d; j++)
	{
		printf("=======================================================================\n");
		printf("\n1)STT ");
		
			printf("%d", j+1);
		
		printf("\n1)ISBN:");
		
			printf("%s", sa.Sa[j].ISBN);
		
		
		printf("\n2)Ten Sach:");
		
			printf("%s", sa.Sa[j].TENSACH);
		
		
		printf("\n3)Tac Gia:");
		
			printf("%s", sa.Sa[j].TACGIA);
		
		
		printf("\n4)Nha Xuat ban: ");
		
			printf("%s", sa.Sa[j].NXB);
		
		
		printf("\n5)Nam Xuat Ban: ");
		
			printf("%s", sa.Sa[j].NaXB);
		
		
		printf("\n6)The Loai: ");
		
			printf("%s", sa.Sa[j].THELOAISACH);
		
		
		printf("\n7)Gia Sach: ");

		printf("%d", sa.Sa[j].GIASACH);
		printf(" Dong");

		printf("\n8)So luong Sach: ");

		printf("%d", sa.Sa[j].SoS);
		printf("\n");

	}
}
void CapNhatSach(MangSach &sa)

	{
		FILE *Sach;

		Sach = fopen("S.txt", "w+t");

		for (int i = 0; i < sa.d; i++)
		{
			//===============================
			fprintf(Sach, "\n%s\t", sa.Sa[i].ISBN);


			fprintf(Sach, "%s\t", sa.Sa[i].TENSACH);


			fprintf(Sach, "%s\t", sa.Sa[i].TACGIA);


			fprintf(Sach, "%s\t", sa.Sa[i].NXB);


			fprintf(Sach, "%s\t", sa.Sa[i].NaXB);


			fprintf(Sach, "%s\t", sa.Sa[i].THELOAISACH);


			fprintf(Sach, "%d\t", sa.Sa[i].GIASACH);


			fprintf(Sach, "%d", sa.Sa[i].SoS);
		}
		fclose(Sach);
	}
void ThemSach(MangSach &sa)
{
	FILE *Sa;
	FILE *SS;
	sa.d++;
	Sa = fopen("S.txt", "a+t");
	SS = fopen("SoS.txt", "w+t");
	fprintf(SS, "%d", sa.d);
	printf("Nhap ma ISBN:");

	gets_s(sa.Sa[sa.d - 1].ISBN);
	gets_s(sa.Sa[sa.d - 1].ISBN);
	fprintf(Sa, "\n%s\t", sa.Sa[sa.d - 1].ISBN);

	printf("Nhap ten sach :");
	gets_s(sa.Sa[sa.d - 1].TENSACH);
	fprintf(Sa, "%s\t", sa.Sa[sa.d - 1].TENSACH);

	printf("Nhap tac gia :");
	gets_s(sa.Sa[sa.d - 1].TACGIA);
	fprintf(Sa, "%s\t", sa.Sa[sa.d - 1].TACGIA);

	printf("Nhap nha xuat ban :");
	gets_s(sa.Sa[sa.d - 1].NXB);
	fprintf(Sa, "%s\t", sa.Sa[sa.d - 1].NXB);

	printf("Nhap nam xuat ban :");
	gets_s(sa.Sa[sa.d - 1].NaXB);
	fprintf(Sa, "%s\t", sa.Sa[sa.d - 1].NaXB);

	printf("Nhap  the loai sach :");
	gets_s(sa.Sa[sa.d - 1].THELOAISACH);
	fprintf(Sa, "%s\t", sa.Sa[sa.d - 1].THELOAISACH);

	printf("Nhap gia sach :");
	scanf("%d",&sa.Sa[sa.d - 1].GIASACH);
	fprintf(Sa, "%d\t", sa.Sa[sa.d - 1].GIASACH);

	printf("Nhap so cuon sach:");
	scanf("%d", &sa.Sa[sa.d - 1].SoS);
	fprintf(Sa, "%d", sa.Sa[sa.d - 1].SoS);


	fcloseall();

	printf("*************************************************************************\n");
	printf("*    Sach da duoc them vao.Ban co the vao danh sach doc gia de kiem tra *\n");
	printf("*************************************************************************\n");
}
void ChinhSuaThonhTinSach(MangSach &sa)
{
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char MDG[30];
	printf("Nhap ma so sach muon chinh sua :");
	gets_s(MDG);
	gets_s(MDG);
	for (int i = 0; i < sa.d; i++)
	{
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(sa.Sa[i].ISBN); i1++)
		{
			if (MDG[i1] == sa.Sa[i].ISBN[i1])//So sanh ma doc gia de tim ra vi tri sach muon sua
			{
				dung++;
				dung1 = i;// luu vi tri sach tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(sa.Sa[dung1].ISBN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	while (HAY == -1)// ========= giup nhap lai ISBN khi nhap sai
	{
		printf("Ma so sach sai vui long nhap lai.\nVui long nhap lai:");
		gets_s(MDG);
		for (int j = 0; j < sa.d; j++)
		{
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(sa.Sa[j].ISBN); j1++)
			{
				if (MDG[j1] == sa.Sa[j].ISBN[j1])// lay vi tri cua sach muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(sa.Sa[dung1].ISBN))
			{
				HAY = dung1;
			}
		}
	}
	if (HAY != -1)
	{
		printf("Ban muon thay doi gi cua cuon sach %s ?\n", sa.Sa[HAY].TENSACH);
		printf("1.Ma so sach \n2.Ten sach\n3.Tac gia.\n4.Ngay Xuat ban.\n5.Nam xuat ban.\n6.The loai sach.\n7.Gia sach.\n8.So cuon sach.");
		scanf("%d", &cn);
		switch (cn)
		{
		case 1:// sua ma doc gia
		{
			printf("Ma so sach luc truoc :%s\n", sa.Sa[HAY].ISBN);
			printf("Vui long nhap ma so sach moi:");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].ISBN))// so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay1 = 0; thay1 < strlen(bientam); thay1++)
				{
					sa.Sa[HAY].ISBN[thay1] = bientam[thay1];
				}
			}
			else
			{
				for (int thay12 = 0; thay12 < strlen(sa.Sa[HAY].ISBN); thay12++)
				{
					sa.Sa[HAY].ISBN[thay12] = bientam[thay12];
				}
			}
			break;
		}
		case 2:
		{
			printf("Ten sach luc truoc : %s\n", sa.Sa[HAY].TENSACH);
			printf("Vui long nhap ho va ten muon sua");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].TENSACH))//  so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay2 = 0; thay2 < strlen(bientam); thay2++)
				{
					sa.Sa[HAY].TENSACH[thay2] = bientam[thay2];
				}
			}
			else
			{
				for (int thay22 = 0; thay22 < strlen(sa.Sa[HAY].TENSACH); thay22++)
				{
					sa.Sa[HAY].TENSACH[thay22] = bientam[thay22];
				}
			}
			break;
		}
		case 3:
		{
			printf("Ten tac gia luc truoc : %s\n", sa.Sa[HAY].TACGIA);
			printf("Vui long nhap ten tac gia moi: ");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].TACGIA))//  so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay3 = 0; thay3 < strlen(bientam); thay3++)
				{
					sa.Sa[HAY].TACGIA[thay3] = bientam[thay3];
				}
			}
			else
			{
				for (int thay32 = 0; thay32 < strlen(sa.Sa[HAY].TACGIA); thay32++)
				{
					sa.Sa[HAY].TACGIA[thay32] = bientam[thay32];
				}
			}
			break;

		}
		case 4:
		{
			printf("Ngay xuat ban luc truoc : %s\n", sa.Sa[HAY].NXB);
			printf("Vui long nhap Ngay xuat ban moi : ");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].NXB))//  so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay4 = 0; thay4 < strlen(bientam); thay4++)
				{
					sa.Sa[HAY].NXB[thay4] = bientam[thay4];
				}
			}
			else
			{
				for (int thay42 = 0; thay42 < strlen(sa.Sa[HAY].NXB); thay42++)
				{
					sa.Sa[HAY].NXB[thay42] = bientam[thay42];
				}
			}
			break;
		}
		case 5:
		{
			printf("Nam xuat ban luc truoc: %s\n", sa.Sa[HAY].NaXB);
			printf("Vui long nhap ngay xuat ban moi: ");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].NaXB))//  so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay5 = 0; thay5 < strlen(bientam); thay5++)
				{
					sa.Sa[HAY].NaXB[thay5] = bientam[thay5];
				}
			}
			else
			{
				for (int thay52 = 0; thay52 < strlen(sa.Sa[HAY].NaXB); thay52++)
				{
					sa.Sa[HAY].NaXB[thay52] = bientam[thay52];
				}
			}
			break;
		}
		case 6:
		{
			printf("The loai sach luc truoc : %s\n", sa.Sa[HAY].THELOAISACH);
			printf("Vui long nhap the loai sach muon sua: ");
			gets_s(bientam);
			gets_s(bientam);
			if (strlen(bientam) >= strlen(sa.Sa[HAY].THELOAISACH))//  so sanh xem cai nao dai hon de co phuong an chen
			{
				for (int thay6 = 0; thay6 < strlen(bientam); thay6++)
				{
					sa.Sa[HAY].THELOAISACH[thay6] = bientam[thay6];
				}
			}
			else
			{
				for (int thay62 = 0; thay62 < strlen(sa.Sa[HAY].THELOAISACH); thay62++)
				{
					sa.Sa[HAY].THELOAISACH[thay62] = bientam[thay62];
				}
			}
			break;
		}
		case 7:
		{
			printf("Gia sach luc truoc: %d\n", sa.Sa[HAY].GIASACH);
			printf("Vui long nhap dia chi muon sua: ");
			scanf("%d", &sa.Sa[HAY].GIASACH);
			break;
		}
		case 8:
		{
			printf("Ngay lap the-Ngay het han doc gia cu: %d\n", sa.Sa[HAY].SoS);
			printf("Vui long nhap Ngay lap the-Ngay het han muon sua: ");
			scanf("%d", &sa.Sa[HAY].SoS);
			break;
		}
		}
		CapNhatSach(sa);
	}
	printf("***********************************************************\n");
	printf("*   Ban da chinh sua thong tinh sach thanh cong .         *\n");
	printf("*   Ban co the vao danh sach sach de kiem tra.            *\n");
	printf("***********************************************************\n");
}
void XoaThongTinSach(MangSach &sa)
{

	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char MDG[30];
	printf("Nhap ma so sach muon xoa :");
	gets_s(MDG);
	gets_s(MDG);
	for (int i = 0; i < sa.d; i++)
	{
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(sa.Sa[i].ISBN); i1++)
		{
			if (MDG[i1] == sa.Sa[i].ISBN[i1])//So sanh ma doc gia de tim ra vi tri sach muon sua
			{
				dung++;
				dung1 = i;// luu vi tri sach tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(sa.Sa[dung1].ISBN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	while (HAY == -1)// ========= giup nhap lai ISBN khi nhap sai
	{
		printf("Ma so sach sai vui long nhap lai.\nVui long nhap lai:");
		gets_s(MDG);
		for (int j = 0; j < sa.d; j++)
		{
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(sa.Sa[j].ISBN); j1++)
			{
				if (MDG[j1] == sa.Sa[j].ISBN[j1])// lay vi tri cua sach muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(sa.Sa[dung1].ISBN))
			{
				HAY = dung1;
			}
		}
	}
	if (HAY != -1)
	{
	        //==========giup cho phan 5
		while (HAY < sa.d-1)//======Giup lap day nhung cho khuyet sau khi da xoa
		{

			if (strlen(sa.Sa[HAY].ISBN) <= strlen(sa.Sa[HAY+1].ISBN))//==============chuyen ISBN tu n++ den n
			{

				for (int i2 = 0; i2 <= strlen(sa.Sa[HAY + 1].ISBN); i2++)
				{
					sa.Sa[HAY].ISBN[i2] = sa.Sa[HAY + 1].ISBN[i2];
				}
			}
			else
			{
				for (int i22 = 0; i22 < strlen(sa.Sa[HAY].ISBN); i22++)
				{
					sa.Sa[HAY].ISBN[i22] = sa.Sa[HAY + 1].ISBN[i22];
				}
			}


			if (strlen(sa.Sa[HAY].TENSACH) <= strlen(sa.Sa[HAY + 1].TENSACH))//==============chuyen ten sach tu n++ den n
			{

				for (int i3 = 0; i3 <= strlen(sa.Sa[HAY + 1].TENSACH); i3++)
				{
					sa.Sa[HAY].TENSACH[i3] = sa.Sa[HAY + 1].TENSACH[i3];
				}
			}
			else
			{
				for (int i32 = 0; i32 < strlen(sa.Sa[HAY].TENSACH); i32++)
				{
					sa.Sa[HAY].TENSACH[i32] = sa.Sa[HAY + 1].TENSACH[i32];
				}
			}


			if (strlen(sa.Sa[HAY].TACGIA) <= strlen(sa.Sa[HAY + 1].TACGIA))//==============chuyen tac gia tu n++ den n
			{

				for (int i4 = 0; i4 <= strlen(sa.Sa[HAY + 1].TACGIA); i4++)
				{
					sa.Sa[HAY].TACGIA[i4] = sa.Sa[HAY + 1].TACGIA[i4];
				}
			}
			else
			{
				for (int i42 = 0; i42 < strlen(sa.Sa[HAY].TACGIA); i42++)
				{
					sa.Sa[HAY].TACGIA[i42] = sa.Sa[HAY + 1].TACGIA[i42];
				}
			}


			if (strlen(sa.Sa[HAY].NXB) <= strlen(sa.Sa[HAY + 1].NXB))//==============chuyen nha xuat ban tu n++ den n
			{

				for (int i5 = 0; i5 <= strlen(sa.Sa[HAY + 1].NXB); i5++)
				{
					sa.Sa[HAY].NXB[i5] = sa.Sa[HAY + 1].NXB[i5];
				}
			}
			else
			{
				for (int i52 = 0; i52 < strlen(sa.Sa[HAY].NXB); i52++)
				{
					sa.Sa[HAY].NXB[i52] = sa.Sa[HAY + 1].NXB[i52];
				}
			}


			if (strlen(sa.Sa[HAY].NaXB) <= strlen(sa.Sa[HAY + 1].NaXB))//==============chuyen nam  xuat ban tu sau toi
			{

				for (int i6 = 0; i6 <= strlen(sa.Sa[HAY + 1].NaXB); i6++)
				{
					sa.Sa[HAY].NaXB[i6] = sa.Sa[HAY + 1].NaXB[i6];
				}
			}
			else
			{
				for (int i62 = 0; i62 < strlen(sa.Sa[HAY].NaXB); i62++)
				{
					sa.Sa[HAY].NaXB[i62] = sa.Sa[HAY + 1].NaXB[i62];
				}
			}


			if (strlen(sa.Sa[HAY].THELOAISACH) <= strlen(sa.Sa[HAY + 1].THELOAISACH))//==============chuyen the loai tu N++ tu sau toi
			{

				for (int i7 = 0; i7 <= strlen(sa.Sa[HAY + 1].THELOAISACH); i7++)
				{
					sa.Sa[HAY].THELOAISACH[i7] = sa.Sa[HAY + 1].THELOAISACH[i7];
				}
			}
			else
			{
				for (int i72 = 0; i72 < strlen(sa.Sa[HAY].THELOAISACH); i72++)
				{
					sa.Sa[HAY].THELOAISACH[i72] = sa.Sa[HAY + 1].THELOAISACH[i72];
				}
			}
			sa.Sa[HAY].GIASACH = sa.Sa[HAY + 1].GIASACH;

			sa.Sa[HAY].SoS = sa.Sa[HAY + 1].SoS;

			HAY++;
		}

		FILE *SoS;
		sa.d--;
		SoS = fopen("SoS.txt", "w+t");
		fprintf(SoS, "%d", sa.d);
		fclose(SoS);
		CapNhatSach(sa);

	}
	printf("****************************************************************************\n");
	printf("*   Ban da xoa sach thang cong. Ban co the vao danh sach sach de kiem tra  *\n");
	printf("****************************************************************************\n");
}
void TimSachTheoISBN(MangSach sa)
{
	char bientam[30];
	int cn;
	int dung;
	int dung1;
	int HAY = -1;
	char TEN[30];
	//=============================
	printf("Nhap ma ISBN muon tim :");
	gets_s(TEN);
	gets_s(TEN);
	strlwr(TEN);
	//==============================
	char TENTAM[30];
	for (int i = 0; i < sa.d; i++)
	{
		
		for (int j2 = 0; j2 < strlen(sa.Sa[i].ISBN); j2++)
		{
			TENTAM[j2] = sa.Sa[i].ISBN[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(sa.Sa[i].ISBN); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(sa.Sa[i].ISBN))// khi da tim ra thi luu vi tri do vao HAY
		{
			HAY = dung1;
		}
	}
	//===============================
	while (HAY == -1)// giup cho vong nay chay cho den khi tim ra duoc ma doc gia co trong danh sach
	{
		printf("Ma ISBN khong co trong danh sach.\nVui long nhap lai:");
		gets_s(TEN);
		strlwr(TEN);
		for (int j = 0; j < sa.d; j++)
		{
			for (int j2 = 0; j2 < strlen(sa.Sa[j].ISBN); j2++)
			{
				TENTAM[j2] = sa.Sa[j].ISBN[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(sa.Sa[j].ISBN); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(sa.Sa[dung1].ISBN))
			{
				HAY = dung1;
			}
		}
	}
	//======================
	if (HAY != -1)
	{
		XuatSach(sa, HAY);
	}
}
void XuatSach(MangSach sa, int j)
{
	printf("\n1)STT ");

	printf("%d", j + 1);

	printf("\n1)ISBN:");

	printf("%s", sa.Sa[j].ISBN);


	printf("\n2)Ten Sach:");

	printf("%s", sa.Sa[j].TENSACH);


	printf("\n3)Tac Gia:");

	printf("%s", sa.Sa[j].TACGIA);


	printf("\n4)Nha Xuat ban: ");

	printf("%s", sa.Sa[j].NXB);


	printf("\n5)Nam Xuat Ban: ");

	printf("%s", sa.Sa[j].NaXB);


	printf("\n6)The Loai: ");

	printf("%s", sa.Sa[j].THELOAISACH);


	printf("\n7)Gia Sach: ");

	printf("%d", sa.Sa[j].GIASACH);
	printf(" Dong");

	printf("\n8)So luong Sach: ");

	printf("%d", sa.Sa[j].SoS);
	printf("\n");
}
void TimSachTheoTen(MangSach sa)
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
	for (int i = 0; i < sa.d; i++)
	{
		for (int j2 = 0; j2 < strlen(sa.Sa[i].TENSACH); j2++)
		{
			TENTAM[j2] = sa.Sa[i].TENSACH[j2];
		}
		strlwr(TENTAM);
		//==============================
		dung = 0;
		dung1 = -1;
		for (int i1 = 0; i1 < strlen(sa.Sa[i].TENSACH); i1++)
		{
			if (TEN[i1] == TENTAM[i1])//So sanh ma doc gia de tim ra vi tri doc gia muon  sua
			{
				dung++;
				dung1 = i;// luu vi tri doc gia tam thoi .khi nao dung thi luu vao buoc duoi
			}
		}
		if (dung == strlen(sa.Sa[i].TENSACH))// khi da tim ra thi luu vi tri do vao HAY
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
		for (int j = 0; j < sa.d; j++)
		{
			for (int j2 = 0; j2 < strlen(sa.Sa[j].TENSACH); j2++)
			{
				TENTAM[j2] = sa.Sa[j].TENSACH[j2];
			}
			strlwr(TENTAM);
			//====================
			dung = 0;
			dung1 = -1;
			for (int j1 = 0; j1 < strlen(sa.Sa[j].TENSACH); j1++)
			{
				if (TEN[j1] == TENTAM[j1])// lay vi tri cua doc gia muon chinh sua.
				{
					dung++;
					dung1 = j;
				}
			}
			if (dung == strlen(sa.Sa[dung1].TENSACH))
			{
				HAY = dung1;
			}
		}
	}
	//======================
	if (HAY != -1)
	{
		XuatSach(sa,HAY);
	}
}