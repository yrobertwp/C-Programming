#include<stdio.h>
//#include<conio.h>
#include<math.h>
#include<string.h>
//# include <stdlib.h>
//# include <unistd.h>

char tenis[][100]={"tidak","tidak","ya","ya","ya","tidak","ya","tidak","ya","ya","ya","ya","ya","tidak"};
char angin[][100]={"lemah","kuat","lemah","lemah","lemah","kuat","kuat","lemah","lemah","lemah","kuat","kuat","lemah","kuat"};
char lembab[][100]={"tinggi","tinggi","tinggi","tinggi","normal","normal","normal","tinggi","normal","normal","normal","tinggi","normal","tinggi"};
char suhu[][100]={"panas","panas","panas","sejuk","dingin","dingin","dingin","sejuk","dingin","sejuk","sejuk","sejuk","panas","sejuk"};
char cuaca[][100]={"cerah","cerah","mendung","hujan","hujan","hujan","mendung","cerah","cerah","hujan","cerah","mendung","mendung","hujan"};
float entropi,lemah,kuat,tinggi,normal,panas,sejuk,dingin,cerah,mendung,hujan,temp;
float x,y;
float p[10],m[10];
float gain [4];
char z[][100]={"Angin","Kelembaban","Suhu","Ramalan Cuaca"};

main()
{
	for (int h=0;h<14;h++)
	{
		printf("|%s|%s|%s|%s|%s|\n",cuaca[h],suhu[h],lembab[h],angin[h],tenis[h]);
	}printf("\n");
	printf("Menghitung Entropi awal :\n");
	for (int i=0;i<14;i++)
	{
		if (strcmp(tenis[i],"ya")==0)
		{
			x++;	
		}
		else if (strcmp(tenis[i],"tidak")==0)
		{
			y++;
		}
	}
	printf("[%.0f+,%.0f-]\n",x,y);
	entropi=-(x/(x+y))*(log10(x/(x+y))/log10(2))+(-(y/(x+y))*(log10(y/(x+y))/log10(2)));
	printf("%.5f\n\n",entropi);
	printf("Menghitung Value Angin: \n");
	printf("SLemah: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(angin[i],"lemah")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[0]++;	
		}
		else if (strcmp(angin[i],"lemah")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[0]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[0],m[0]);
	if(p[0]==m[0])
	{
		lemah=1;
	}
	else if(p[0]==0||m[0]==0)
	{
		lemah=0;
	}
	else
	{
		lemah=-(p[0]/(p[0]+m[0]))*(log10(p[0]/(p[0]+m[0]))/log10(2))+(-(m[0]/(p[0]+m[0]))*(log10(m[0]/(p[0]+m[0]))/log10(2)));
	}
	printf("%.5f\n",lemah);
	printf("SKuat: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(angin[i],"kuat")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[1]++;	
		}
		else if (strcmp(angin[i],"kuat")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[1]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[1],m[1]);
	if(p[1]==m[1])
	{
		kuat=1;
	}
	else if(p[1]==0||m[1]==0)
	{
		kuat=0;
	}
	else
	{
		kuat=-(p[0]/(p[0]+m[0]))*(log10(p[0]/(p[0]+m[0]))/log10(2))+(-(m[0]/(p[0]+m[0]))*(log10(m[0]/(p[0]+m[0]))/log10(2)));
	}
	printf("%.5f\n",kuat);
	gain[0]=entropi-((p[0]+m[0])/(x+y))*lemah-((p[1]+m[1])/(x+y))*kuat;
	printf("Gain(S,Angin) = %.5f\n\n",gain[0]);
	printf("Menghitung Value Kelembaban: \n");
	printf("STinggi: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(lembab[i],"tinggi")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[2]++;	
		}
		else if (strcmp(lembab[i],"tinggi")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[2]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[2],m[2]);
	if(p[2]==m[2])
	{
		tinggi=1;
	}
	else if(p[2]==0||m[2]==0)
	{
		tinggi=0;
	}
	else
	{
		tinggi=-(p[2]/(p[2]+m[2]))*(log10(p[2]/(p[2]+m[2]))/log10(2))+(-(m[2]/(p[2]+m[2]))*(log10(m[2]/(p[2]+m[2]))/log10(2)));
	}
	printf("%.5f\n",tinggi);
	printf("SNormal: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(lembab[i],"normal")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[3]++;	
		}
		else if (strcmp(lembab[i],"normal")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[3]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[3],m[3]);
	if(p[3]==m[3])
	{
		normal=1;
	}
	else if(p[3]==0||m[3]==0)
	{
		normal=0;
	}
	else
	{
		normal=-(p[3]/(p[3]+m[3]))*(log10(p[3]/(p[3]+m[3]))/log10(2))+(-(m[3]/(p[3]+m[3]))*(log10(m[3]/(p[3]+m[3]))/log10(2)));
	}
	printf("%.5f\n",normal);
	gain[1]=entropi-((p[2]+m[2])/(x+y))*tinggi-((p[3]+m[3])/(x+y))*normal;
	printf("Gain(S,Kelembaban) = %.5f\n\n",gain[1]);
	printf("Menghitung Value Suhu: \n");
	printf("SPanas: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(suhu[i],"panas")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[4]++;	
		}
		else if (strcmp(suhu[i],"panas")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[4]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[4],m[4]);
	if(p[4]==m[4])
	{
		panas=1;
	}
	else if(p[4]==0||m[4]==0)
	{
		panas=0;
	}
	else
	{
		panas=-(p[4]/(p[4]+m[4]))*(log10(p[4]/(p[4]+m[4]))/log10(2))+(-(m[4]/(p[4]+m[4]))*(log10(m[4]/(p[4]+m[4]))/log10(2)));
	}
	printf("%.5f\n",panas);
	printf("SSejuk: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(suhu[i],"sejuk")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[5]++;	
		}
		else if (strcmp(suhu[i],"sejuk")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[5]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[5],m[5]);
	if(p[5]==m[5])
	{
		sejuk=1;
	}
	else if(p[5]==0||m[5]==0)
	{
		sejuk=0;
	}
	else
	{
		sejuk=-(p[5]/(p[5]+m[5]))*(log10(p[5]/(p[5]+m[5]))/log10(2))+(-(m[5]/(p[5]+m[5]))*(log10(m[5]/(p[5]+m[5]))/log10(2)));
	}
	printf("%.5f\n",sejuk);
	printf("SDingin: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(suhu[i],"dingin")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[6]++;	
		}
		else if (strcmp(suhu[i],"dingin")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[6]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[6],m[6]);
	if(p[6]==m[6])
	{
		dingin=1;
	}
	else if(p[6]==0||m[6]==0)
	{
		dingin=0;
	}
	else
	{
		dingin=-(p[6]/(p[6]+m[6]))*(log10(p[6]/(p[6]+m[6]))/log10(2))+(-(m[6]/(p[6]+m[6]))*(log10(m[6]/(p[6]+m[6]))/log10(2)));
	}
	printf("%.5f\n",dingin);
	gain[2]=entropi-((p[4]+m[4])/(x+y))*panas-((p[5]+m[5])/(x+y))*sejuk-((p[6]+m[6])/(x+y))*dingin;
	printf("Gain(S,Suhu) = %.5f\n\n",gain[2]);
	printf("Menghitung Value Ramalan Cuaca: \n");
	printf("SCerah: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(cuaca[i],"cerah")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[7]++;	
		}
		else if (strcmp(cuaca[i],"cerah")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[7]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[7],m[7]);
	if(p[7]==m[7])
	{
		cerah=1;
	}
	else if(p[7]==0||m[7]==0)
	{
		cerah=0;
	}
	else
	{
		cerah=-(p[7]/(p[7]+m[7]))*(log10(p[7]/(p[7]+m[7]))/log10(2))+(-(m[7]/(p[7]+m[7]))*(log10(m[7]/(p[7]+m[7]))/log10(2)));
	}
	printf("%.5f\n",cerah);
	printf("SMendung: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(cuaca[i],"mendung")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[8]++;	
		}
		else if (strcmp(cuaca[i],"mendung")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[8]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[8],m[8]);
	if(p[8]==m[8])
	{
		mendung=1;
	}
	else if(p[8]==0||m[8]==0)
	{
		mendung=0;
	}
	else
	{
		mendung=-(p[8]/(p[8]+m[8]))*(log10(p[8]/(p[8]+m[8]))/log10(2))+(-(m[8]/(p[8]+m[8]))*(log10(m[8]/(p[8]+m[8]))/log10(2)));
	}
	printf("%.5f\n",mendung);
	printf("SHujan: ");
	for (int i=0;i<14;i++)
	{
		if (strcmp(cuaca[i],"hujan")==0&&strcmp(tenis[i],"ya")==0)
		{
			p[9]++;	
		}
		else if (strcmp(cuaca[i],"hujan")==0&&strcmp(tenis[i],"tidak")==0)
		{
			m[9]++;
		}
	}
	printf("[%.0f+,%.0f-]: ",p[9],m[9]);
	if(p[9]==m[9])
	{
		hujan=1;
	}
	else if(p[9]==0||m[9]==0)
	{
		hujan=0;
	}
	else
	{
		hujan=-(p[9]/(p[9]+m[9]))*(log10(p[9]/(p[9]+m[9]))/log10(2))+(-(m[9]/(p[9]+m[9]))*(log10(m[9]/(p[9]+m[9]))/log10(2)));
	}
	printf("%.5f\n",hujan);
	gain[3]=entropi-((p[7]+m[7])/(x+y))*cerah-((p[8]+m[8])/(x+y))*mendung-((p[9]+m[9])/(x+y))*hujan;
	printf("Gain(S,Ramalan Cuaca) = %.5f\n\n",gain[3]);
	for(int i=0;i<4;i++)
	{
		printf("Gain(S,%s): %.5f\n",z[i],gain[i]);
	}
	for(int i=0;i<=3;i++)
	{
		for(int k=3-i;k>0;k--)
		{
			if(gain[k]>gain[k-1])
			temp=gain[k];
			gain[k]=gain[k-1];
			gain[k-1]=temp;
		}
	}
	printf("\nGain Tertinggi %.5f\n",gain[0]);
	printf("Attribute Ramalan_Cuaca akan menyediakan prediksi terbaik untuk target attribute Bermain_Tenis");
}
