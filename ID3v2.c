#include<stdio.h>
#include<math.h>
#include<string.h>

int jumlah_kolom,jumlah_isi,i,j,k,l,plus[10],minus[10],p[10],m[10],jenis_variabel[10],hasil;
char nama_kolom[20][10],isi_kolom[20][10][100],nama_variabel[20][10][10],checker[1][10][100];
float x,y,entropy_awal,s[10],gain[10],stotal,gain_catcher;

main(){
	printf("Aplikasi ID3\n");
	printf("------------\n\n");
	printf("Jumlah Kolom Tabel = ");
	scanf("%i",&jumlah_kolom);
	printf("Jumlah isi kolom  = ");
	scanf("%i",&jumlah_isi);
	
	printf("\nMasukkan nama-nama kolom dan isi kolom\n\n");

	for(i=0;i<jumlah_kolom;i++){
		printf("Kolom %i = ",i+1);
		scanf("%s",&nama_kolom[i]);
		printf("\nMasukkan isi kolom %s\n",nama_kolom[i]);
		for(j=0;j<jumlah_isi;j++){
			printf("Baris %i = ",j+1);
			scanf("%s",&isi_kolom[i][j]);
			printf("Jenis Entropy (p/n) ");
			scanf("%s",&checker[i][j]);
		}
		printf("\nJumlah jenis variabel kolom %s = ",nama_kolom[i]);
		scanf("%i",&jenis_variabel[i]);
		for(j=0;j<jenis_variabel[i];j++){
			printf("Variabel %i = ",j+1);
			scanf("%s",&nama_variabel[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nTabel\n\n");
	for(i=0;i<jumlah_kolom;i++){
		printf("%s\t\t",nama_kolom[i]);
	}
	printf("\n");
	for(i=0;i<jumlah_kolom;i++){	
		for(j=0;j<jumlah_isi;j++){
			printf("%s\t\t",isi_kolom[j][i]);
		}
		printf("\n");
	}
	
	for(i=0;i<jumlah_kolom;i++){	
		for(j=0;j<jumlah_isi;j++){
			if(strcmp(checker[i][j],"p")==0){
				plus[i]++;
			}else if(strcmp(checker[i][j],"n")==0){
				minus[i]++;
			}
		}
	}
	
	printf("\nMenghitung entropy awal\n");
	printf("Entropy[%i+,%i-] = ",plus[jumlah_kolom-1],minus[jumlah_kolom-1]);
	x=(float)plus[jumlah_kolom-1];
	y=(float)minus[jumlah_kolom-1];
	if(x==0||y==0){
		entropy_awal=0;
	}else{
		entropy_awal=-(x/(x+y))*(log10(x/(x+y))/log10(2))+(-(y/(x+y))*(log10(y/(x+y))/log10(2)));
	}
	printf("%1.5f\n",entropy_awal);
	
	for(k=0;k<jumlah_kolom-1;k++){
		printf("Menghitung Value %s\n",nama_kolom[i]);
		for(l=0;l<jenis_variabel[k];l++){
			stotal=0;
			printf("S%s\n",nama_variabel[k][l]);
			for(i=0;i<jumlah_kolom;i++){
				for(j=0;j<jumlah_isi;j++){
					if((strcmp(isi_kolom[i][j],nama_variabel[k][l])==0)&&(strcmp(checker[i][j],"p")==0)){
						p[l]++;
					}else{
						m[l]++;
					}
				}
				printf("S%s[%.0f+,%.0f-]: ",nama_variabel[k][l],p[l],m[l]);
				if(p[l]==0||m[l]==0){
					s[l]=0;
					printf("%1.5f",s[l]);
				}else{
					s[l]=-(p[l]/(p[l]+m[l]))*(log10(p[l]/(p[l]+m[l]))/log10(l))+(-(m[l]/(p[l]+m[l]))*(log10(m[l]/(p[l]+m[l]))/log10(l)));
					printf("%1.5f",s[l]);
				}
				stotal=stotal+s[l];
				printf("\n");
				gain[k]=entropy_awal-stotal;
			}
		}
	}
	
	
	for(i=0;i<jumlah_kolom-1;i++){
		if(gain[i]<gain[i+1]){
			gain_catcher=gain[i+1];
			hasil=i+1;
		}
	}
	
	printf("\n\nKesimpulan : Gain tertinggi adalah %1.5f dan atribut %s",gain_catcher,nama_kolom[hasil]);
	
	getch();
}
