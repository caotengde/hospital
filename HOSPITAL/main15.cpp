#include "struct9.h"
#include <malloc.h>
#include <time.h>
#include <string.h>
char level[5][20] = {" ","����ҽʦ", "������ҽʦ", "����ҽʦ", "סԺҽʦ"};
char department[11][20] = {" ", "�ڿ�", "���", "����", "����", "�ۿ�", "���Ǻ��", "��ǻ��", "Ƥ����", "��ҽ��", "������ѯ��"};
struct Check check[70];
struct DocInf doctor[31];
struct Drug drug[31];
int total_day(int month,int day)//������һ���Ѿ���������
{
    int sum = 0;
    switch(month)
    {
        case 1:sum = day;
                break;
        case 2:sum = 31 + day;
                break;
        case 3:sum = 60 + day;
                break;
        case 4:sum = 91 + day;
                break;
        case 5:sum = 121 + day;
                break;
        case 6:sum = 152 + day;
                break;
        case 7:sum = 183 + day;
                break;
        case 8:sum = 213 + day;
                break;
        case 9:sum = 244 + day;
                break;
        case 10:sum = 274 + day;
                break;
        case 11:sum = 305 + day;
                break;
        case 12:sum = 335 + day;
                break;
        default :
        printf("������·��д���\n");
        break;
    }
    return sum;
}

MedRecord* add(MedRecord *tail,int n, int* num, int weekday)//num �ǹҺ�
{                         //�����Ϣ
	MedRecord *p;
	int i=0;
	while(i<n)
	{
		p=(struct MedRecord *)malloc(sizeof(MedRecord));
		//printf("������Ҫ��ӵ����Ƽ�¼:\n");
		printf("������Ҫ��ӵĻ�������:\n");
		scanf("%s",p->patinf.name);
		printf("��ĹҺ���%d\n", *num+1);
		(*num)++;
		printf("��ѡ����Ҫ�ҺŵĿ��ҵı�ţ�\n");
		for(int j = 1; j <= 10; j++){
			printf("%2d. %s\n", j, department[j]);
		}
		int depart;
		scanf("%d", &depart);
		printf("��ѡ����Ҫ�Һŵ�ҽ����\n");
		for(int j = 1; j <= 30; j++){
			if(doctor[j].depart == depart && doctor[j].on[weekday] == 1){
				printf("%2d. %s", j, doctor[j].name);
			}
		}
		printf("\n");
		scanf("%d", &p->doctorid);
		printf("�����ǿ��Խ��еļ�飺\n");
		for(int j = 1; j <= 30; j+=3){
			printf("%2d. %32s  %2d. %32s  %2d. %32s\n", j, check[j].name, j+1, check[j+1].name, j+2, check[j+2].name, j+3, check[j+3].name);
		}
		printf("��������Ҫ����������\n");
		scanf("%d", &p->medinf.checknum);
		printf("������ÿ��ı�ţ��м���ӿո�:\n");
		for(int j = 0; j < p->medinf.checknum; j++)
			scanf("%d", &p->medinf.check[j]);
		printf("�����ǿ��Թ����ҩ��\n");
		for(int j = 1; j <= 30; j+=3){
			printf("%2d. %32s  %2d. %32s %2d. %32s\n", j, drug[j].name, j+1, drug[j+1].name, j+2, drug[j+2].name, j+3, drug[j+3].name);
		}
		printf("����������ҪҩƷ��������\n");
		scanf("%d", &p->medinf.drugnum);
		printf("������ÿ��ı�����������м���ӿո񣩣�\n");
		for(int j = 0; j < p->medinf.drugnum; j++){
			scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
		}
		printf("������ҪסԺ�𣿣���Ҫ����1, ����Ҫ������0��");
		int judge;
		scanf("%d", &judge);
		if(judge == 1){
			p->medinf.hospital.yes == 1;
			printf("��Ҫ��ÿ�ʼסԺ��\n");
			printf("���°���");
			scanf("%d", &p->medinf.hospital.intime.month);
			printf("���Ű���");
			scanf("%d", &p->medinf.hospital.intime.data);
			printf("���㰡��");
			scanf("%d", &p->medinf.hospital.intime.hour);
			printf("���ְ���");
			scanf("%d", &p->medinf.hospital.intime.minute);
			printf("��Ҫ����뿪ҽԺ����\n");
			printf("���°���");
			scanf("%d",&p->medinf.hospital.outime.month);
			printf("���Ű���");
			scanf("%d", &p->medinf.hospital.outime.data);
			printf("���㰡��");
			scanf("%d", &p->medinf.hospital.outime.hour);
			printf("���ְ���");
			scanf("%d", &p->medinf.hospital.outime.minute);
		}
		tail->next=p;
		tail = p;
		i++;
	}
	return tail;
}

void change(MedRecord *head,int m)
{                  //�޸���Ϣ
	MedRecord *p;
	for(p=head->next;p;p=p->next)
	    if(p->patinf.number==m)
	        break;
//��������----����
	printf("�����޸ĺ�����Ƽ�¼:\n");
		scanf("%s",p->patinf.name);//������
}
void re(MedRecord *head,int m)
{                  //ɾ����Ϣ
	MedRecord *p,*p0,*q;
	for(p=head->next,p0=head;p;)
	    if(p->patinf.number==m)
	    {
	    	q=p->next;
	    	p0->next=q;
	    	free(p);  p=q;
	    	break;
	    }
	    else
	    {
	    	p0=p;
			p=p->next;
		}
    printf("ɾ���ɹ�");
}
int statis2(MedRecord *head,int n)
{
    int D1,M1,D2,M2;
    int m=0;
    printf("�����뿪ʼ����:");
    scanf("%d",&M1);
    printf("�����뿪ʼ����:");
    scanf("%d",&D1);
    printf("�������ʼ����:");
    scanf("%d",&M2);
    printf("�������ʼ����:");
    scanf("%d",&D2);
	MedRecord *p;
	printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������   \n");
	for(p=head->next;p;p=p->next)
	{
		if(M1<p->medinf.time.month&&p->medinf.time.month<M2&&p->doctorid==n)
		{
		    m++;
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
		if((M1==p->medinf.time.month||p->medinf.time.month==M2)&&p->doctorid==n)
        {
            m++;
            if(D1<=p->medinf.time.data||p->medinf.time.data<=D2)
              printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
        }
	}
	return m;
}
void askday(MedRecord *head,MedRecord *tail)
{      //����ʱ���ѯ
    int D1,M1,D2,M2;
    printf("�����뿪ʼ����:");
    scanf("%d",&M1);
    printf("�����뿪ʼ����:");
    scanf("%d",&D1);
    printf("�������ʼ����:");
    scanf("%d",&M2);
    printf("�������ʼ����:");
    scanf("%d",&D2);
	MedRecord *p;
	printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������   \n");
	for(p=head->next;p;p=p->next)
	{
		if(M1<p->medinf.time.month&&p->medinf.time.month<M2)
		{
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
		if(M1==p->medinf.time.month||p->medinf.time.month==M2)
        {
            if(D1<=p->medinf.time.data||p->medinf.time.data<=D2)
              printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
        }
	}
	printf("�Ƿ���Ҫ�����в�����Ŀ������ϸ��ѯ������1��������2��");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("��������Ҫ��ѯ�Ĳ����ĹҺ�");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("��������ܹ�%d��, ���£�\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("�Ƿ�Ҫ��ѯ������������������1������2��");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}

}
void askdepart(MedRecord *head,MedRecord *tail,int n)
{            //���տ��ҺŲ�ѯ
	MedRecord *p;
	p=head->next;
	printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������   \n");
	for(p=head->next;p;p=p->next)
	{

		if(doctor[p->doctorid].depart==n)
		{
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("�Ƿ���Ҫ�����в�����Ŀ������ϸ��ѯ������1��������2��");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("��������Ҫ��ѯ�Ĳ����ĹҺ�");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("��������ܹ�%d��, ���£�\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("�Ƿ�Ҫ��ѯ������������������1������2��");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}
}
void askdoc(MedRecord *head,MedRecord *tail,int n)
{            //����ҽ�����Ų�ѯ
	MedRecord *p;
	printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������   \n");
	for(p=head->next;p;p=p->next)
	{
		if(p->doctorid==n)
		{
		  printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("�Ƿ���Ҫ�����в�����Ŀ������ϸ��ѯ������1��������2��");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("��������Ҫ��ѯ�Ĳ����ĹҺ�");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("��������ܹ�%d��, ���£�\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("�Ƿ�Ҫ��ѯ������������������1������2��");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}
}
void askpat(MedRecord *head,MedRecord *tail, int n)
{      //���ղ��˹ҺŲ�ѯ

	MedRecord *p;
	printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������   \n");
	for(p=head->next;p;p=p->next)
	{
		if(p->patinf.number==n)
		{
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("�Ƿ���Ҫ�����в�����Ŀ������ϸ��ѯ������1��������2��");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("��������Ҫ��ѯ�Ĳ����ĹҺ�");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("��������ܹ�%d��, ���£�\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("�Ƿ�Ҫ��ѯ������������������1������2��");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}
}


int main(){
	//printf("%s", level[1]);
	//printf("%s", department[7]);


	//freopen("in.txt", "r", stdin);
	/*¼������Ϣ*/
	FILE *incheck;
	incheck = fopen("check3.txt", "r");
	char temp[10];
	for(int i = 1; i <= 69; i++){
		fscanf(incheck, "%s%s%f", temp, check[i].name, &(check[i].price));
	}
	fclose(incheck);

	/*for(int i = 1; i <= 69; i++){
		printf("%d %s %f\n", i, check[i].name, check[i].price);
	}*/

	/*¼��ҽ����Ϣ*/
	FILE *indoctor;
	indoctor = fopen("doctor3.txt", "r");
	char temp2[10];
	char temp3[10];
	for(int i = 1; i <= 30; i++){
		fscanf(indoctor, "%s%s%s", doctor[i].name, temp2, temp3);
		doctor[i].level = (int)temp2[1] - (int)'0';
		doctor[i].depart = 10*((int)temp2[2]-(int)'0') + (int)temp2[3]-(int)'0';
		doctor[i].number = i;
		for(int j = 0; j < 3; j++)
			doctor[i].on[(int)(temp3[j]-'0')] = 1;
	}
	fclose(indoctor);

	/*for(int i = 1; i <= 30; i++){
		printf("%s %d %d %d ", doctor[i].name, doctor[i].level, doctor[i].depart, doctor[i].number);
		for(int j = 1; j <= 7; j++)
			printf("%d", doctor[i].on[j]);
		printf("\n");
	}*/

	/*¼��ҩƷ��Ϣ*/
	FILE *indrug;
	indrug = fopen("drug2.txt", "r");
	char temp4[10];
	for(int i = 1; i <= 30; i++){
		fscanf(indrug, "%s%s%f", temp4, drug[i].name, &drug[i].price);
	}
	fclose(indrug);

	/*for(int i = 1; i <= 30; i++){
		printf("%d %s %f\n", i, drug[i].name, drug[i].price);
	}*/

	float money = 0;
	
	/*¼��������Ϣ*/
	FILE *inmedrecord;
	inmedrecord = fopen("medrecord8.txt", "r");
	MedRecord* head;
	MedRecord* p1;
	MedRecord* p2;
	char temp5[5], temp6[5], temp7[10], temp8[50],temp9[150],temp10[20];
	int drugcat;
	int checkcat;
	head = (MedRecord*)malloc(sizeof(MedRecord));
	p2 = head;
	head->last = NULL;
	for(int j = 1; j <= 30; j++){
		p1 = (MedRecord*)malloc(sizeof(MedRecord));
		p2->next = p1;
		p1->last = p2;
		fscanf(inmedrecord, "%s%s%s%s%s%s%s%s%f", p1->patinf.name, p1->patinf.id, temp5, temp6, temp7, temp8, temp9, temp10, &p1->medinf.hospital.pledge);
		//printf("%s %s %s %s %s %s %s %s %f\n", p1->patinf.name, p1->patinf.id, temp5, temp6, temp7, temp8, temp9, temp10, p1->medinf.hospital.pledge);
		p1->patinf.number = (int)(temp5[0]-'0')*100 + (int)(temp5[1]- '0')*10 + (int)(temp5[2]-'0');
		p1->doctorid = (int)(temp6[0]-'0')*10 + (int)(temp6[1]- '0');
		p1->medinf.time.month = (int)(temp7[0]-'0')*10 + (int)(temp7[1]-'0');
		p1->medinf.time.data = (int)(temp7[2]-'0')*10 + (int)(temp7[3] - '0');
		p1->medinf.time.hour = (int)(temp7[4] - '0')*10 + (int)(temp7[5]-'0');
		p1->medinf.time.minute = (int)(temp7[6] - '0')*10 + (int)(temp7[7] - '0');
		p1->patinf.age = 2020-((int)(p1->patinf.id[6]-'0')*1000 + (int)(p1->patinf.id[7]-'0')*100 + (int)(p1->patinf.id[8]-'0')*10 + (int)(p1->patinf.id[9]-'0'));
		checkcat = (int)(temp8[0]-'0');
		p1->medinf.checknum = checkcat;
		for(int i = 0; i < checkcat; i++){
			p1->medinf.check[i] = (int)(temp8[2*i+1]-'0')*10 + (int)(temp8[2*i+2]-'0');
		}
		drugcat = (int)(temp9[0]-'0')*10 + (int)(temp9[1] - '0');
		p1->medinf.drugnum = drugcat;
		for(int i = 0; i < drugcat; i++){
			p1->medinf.drug[i] = (int)(temp9[4*i+2]-'0')*10 + (int)(temp9[4*i+3]- '0');
			p1->medinf.drugqua[i] = (int)(temp9[4*i+4]-'0')*10 + (int)(temp9[4*i+5]- '0');
		}
		for(int i = 1; i <= p1->medinf.checknum; i++){
				p1->medinf.allcheckfee += check[p1->medinf.check[i-1]].price;
			}
			for(int i = 1; i <= p1->medinf.drugnum; i++){
				p1->medinf.alldrugfee += drug[p1->medinf.drug[i-1]].price*(float)p1->medinf.drugqua[i-1];
			}
		money+=(p1->medinf.allcheckfee+p1->medinf.alldrugfee);
		p1->medinf.hospital.yes = 1;
		p1->medinf.hospital.intime.month = (int)(temp10[0]-'0')*10 + (int)(temp10[1]-'0');
		p1->medinf.hospital.intime.data = (int)(temp10[2]-'0')*10 + (int)(temp10[3]-'0');
		p1->medinf.hospital.intime.hour = (int)(temp10[4]-'0')*10 + (int)(temp10[5]-'0');
		p1->medinf.hospital.intime.minute = (int)(temp10[6]-'0')*10 + (int)(temp10[7]-'0');
		p1->medinf.hospital.outime.month = (int)(temp10[8]-'0')*10 + (int)(temp10[9]-'0');
		p1->medinf.hospital.outime.data = (int)(temp10[10]-'0')*10 + (int)(temp10[11]-'0');
		p1->medinf.hospital.outime.hour = (int)(temp10[12]-'0')*10 + (int)(temp10[13]-'0');
		p1->medinf.hospital.outime.minute = (int)(temp10[14]-'0')*10 + (int)(temp10[15]-'0');
		p2 = p1;
		//printf("%d\n", j);
	}
	p1->next = NULL;
	MedRecord* tail = p1;
	fclose(inmedrecord);
	int prenum = 29;//��Ȼ�����ֵ��
	
	/*¼��30�Ժ����Ϣ*/
	FILE* inmedadd = fopen("add.txt", "rb+");
	//fwrite(p1, sizeof(MedRecord), 1, inmedadd);
	while(!feof(inmedadd)){
		MedRecord *p = (MedRecord*)malloc(sizeof(MedRecord));
		fread(p, sizeof(MedRecord), 1, inmedadd);
		p1->next = p;
		p->last = p1;
		p1 = p1->next;
		prenum++;
	}
	p1->next = NULL;
	tail = p1;
	
	
	//tail->patinf.number = 31;
	/*���¼���Ƿ���ȷ*/
	/*p1 = head->next;
	for(int i = 1; i <= 30; i++){
		printf("%s %s %d %d\n", p1->patinf.name, p1->patinf.id, p1->patinf.number, p1->doctorid);
		printf("%d %d %d %d\n", p1->medinf.time.month,p1->medinf.time.data,p1->medinf.time.hour,p1->medinf.time.minute);
		for(int j = 0; j < p1->medinf.checknum; j++){
				printf("%d ", p1->medinf.check[j]);
			}
		printf("\n");
		printf("%d\n", p1->medinf.drugnum);
		for(int j = 0; j < p1->medinf.drugnum; j++){
				printf("%d %d\n", p1->medinf.drug[j], p1->medinf.drugqua[j]);
		}
		printf("\n");
		printf("%d %d %d\n",p1->medinf.hospital.intime.month, p1->medinf.hospital.intime.data, p1->medinf.hospital.intime.hour, p1->medinf.hospital.intime.minute);
		printf("%d %d %d\n",p1->medinf.hospital.outime.month, p1->medinf.hospital.outime.data, p1->medinf.hospital.outime.hour, p1->medinf.hospital.outime.minute);
		printf("%f\n", p1->medinf.hospital.pledge);
		printf("\n");
		p1 = p1->next;
	}
	*/
	 
	int num = prenum;//�Һ�
	int D,M;//��ǰ�����ں��·�
    time_t timep;
    struct tm *p4;
    time (&timep);
    p4=gmtime(&timep);
    D=p4->tm_mday;/*��ȡ��ǰ�·�����,��Χ��1-31*/
    M=1+p4->tm_mon;/*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/
    int iWeek = 1+(D+2*M+3*(M+1)/5+2020+2020/4-2020/100+2020/400)%7;
    int hour = 8+p4->tm_hour;
    int min = p4->tm_min;
    while(1){
	printf("\n\n\n\n\n");
	printf("\t\t|-----------------------��ӭ������ЭҽԺ----------------------|\n") ;
	printf("\t\t|-------��ǰʱ�䣺���� %d --- %d �� %d �� %d �� %d ��--------- |", iWeek, M, D, hour, min);
	printf("\n\n\n\n\n");
	printf("��������ʲô��ݣ�\n");
	printf("1. ����\n2. ҽ��\n3.����Ա\n4.�˳�\n");
	int option;
	scanf("%d", &option);
	printf("\n");
	if(option == 1){
		printf("��Ҫ���¹�һ�����أ����ǲ�ѯһ��������Ϣ�أ��Һ���1����ѯ��2��");
		int option2;
		scanf("%d", &option2);
		if(option2 == 1) {
			MedRecord* p = (struct MedRecord *)malloc(sizeof(MedRecord));
			printf("��������ǣ�");
			scanf("%s",p->patinf.name);
			printf("������һ��������֤�ţ�\n");
			scanf("%s", p->patinf.id);
			p->patinf.age = 2020-((int)(p->patinf.id[6]-'0')*1000 + (int)(p->patinf.id[7]-'0')*100 + (int)(p->patinf.id[8]-'0')*10 + (int)(p->patinf.id[9]-'0'));
			printf("\n��ס��ĹҺ���%d\n", num+1);
			num++;
			p->patinf.number = num;
			p->medinf.time.month=M;
			p->medinf.time.data=D;
			p->medinf.time.hour=hour;
			p->medinf.time.minute=min;
			printf("�������ﲻ����أ����������ܹ��ҵĿ���\n");
			for(int j = 1; j <= 10; j++){
				printf("%2d. %s\n", j, department[j]);
			}
			printf("�������Ӧ���ҵı�ţ�");
			int depart;
			scanf("%d", &depart);
			while(depart>10||depart<1)
            {
                printf("���ұ�Ŵ�������������\n");
                scanf("%d", &depart);
            }
			printf("������Щҽ���������пյģ�\n");
			for(int j = 1; j <= 30; j++){
				if(doctor[j].depart == depart && doctor[j].on[iWeek] == 1){
					printf("%2d. %s", j, doctor[j].name);
				}
			}
			printf("\n����������Ҫ�ҵ�ҽ�����:");
			scanf("%d", &p->doctorid);
			int bv=0;
            for(int j = 1; j <= 30; j++)
		    {
			    if(doctor[j].depart == depart && doctor[j].on[iWeek] == 1)
                {
				    if(j==p->doctorid)
                        bv++;
			    }
		    }
			while(bv==0)
            {
                printf("ҽ�����Ŵ�������������\n");
                scanf("%d", &p->doctorid);
                for(int j = 1; j <= 30; j++)
		        {
			        if(doctor[j].depart == depart && doctor[j].on[iWeek] == 1)
                    {
			    	    if(j==p->doctorid)
                            bv++;
			        }
		        }
            }
			doctor[p->doctorid].pat[doctor[p->doctorid].patnum] = num;
			doctor[p->doctorid].patnum++;
			tail->next = p;
			p->last = tail;
			tail = p;
			p->next = NULL;
			printf("\n���Ѿ��Һú��ˣ������ĵȴ�������%d�˾͵�����",doctor[p->doctorid].patnum-1);
		}


		else if (option2 == 2){
			printf("���������ܹ����еĹ��ܣ�\n1. ��ѯ����\n2. ��ѯ��ǰ���ƽ���\n3. סԺʱ��\n");
			int option3;
			printf("����������Ҫ���еĹ��ܱ�ţ�");
			scanf("%d", &option3);
			if(option3 == 1){
				printf("\n����������֤���Ƕ��٣�");
				char id[30];
				scanf("%s", id);
				MedRecord *p;
				printf("    ����                  ���֤��               �Һ�    ҽ�����   ҽ������     ʱ��\n");
				for(p=head->next;p;p=p->next)
				{
					if(!strcmp(p->patinf.id,id))
					{
		  				  printf("%8s   %30s        %2d       %2d     %10s  %d��%d��%dʱ%d��\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name,p->medinf.time.month,p->medinf.time.data,p->medinf.time.hour,p->medinf.time.minute);
					}
				}
				printf("�Ƿ���Ҫ�����в�����Ŀ������ϸ��ѯ������1��������2��");
				int option4;
				scanf("%d", &option4);
				if(option4 == 1){
					while(1){
						printf("��������Ҫ��ѯ�Ĳ����ĹҺ�");
						int num;
						scanf("%d", &num);
						p = tail;
						while(1){
							if(p->patinf.number == num)
								break;
							p = p->last;
						}
						if(p->medinf.checknum != 0) {
							printf("��������ܹ�%d��, ���£�\n", p->medinf.checknum);
							for(int i = 1; i <= p->medinf.checknum; i++){
								printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
							}
						}

						if(p->medinf.drugnum != 0){
							printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
							for(int i = 1; i <= p->medinf.drugnum; i++){
								printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
							}
						}
						if(p->medinf.hospital.yes == 1){
							printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
							printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
						}
						printf("�Ƿ�Ҫ��ѯ������������������1������2��");
						int option5;
						scanf("%d", &option5);
						if(option5 == 1)
							break;
					}
				}
			}
		else if(option3 == 2){
			printf("���������ĹҺţ�");
			int num;
			scanf("%d", &num); 
			MedRecord* p = tail;
			while(1){
				if(p->patinf.number == num)
					break;
				p = p->last;
			}
			printf("�����ҵĿ�����%s\n", department[doctor[p->doctorid].depart]);
			printf("��Ԥ����ҽ����%s\n", doctor[p->doctorid].name);
			if(p->medinf.checknum != 0) {
					printf("������Ӧ�ý��еļ�����£�\n");
					printf("��������ܹ�%d��\n", p->medinf.checknum);
					for(int i = 1; i <= p->medinf.checknum; i++){
						printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
					}
			}
					printf("��������س�\n");
					getchar();
					getchar(); 
					if(p->medinf.drugnum != 0){
							printf("��Щ��ҽ��Ϊ�㿪��ҩ��\n"); 
							printf("��ҩ�����ܹ�%d��, ���£�\n", p->medinf.drugnum);
							for(int i = 1; i <= p->medinf.drugnum; i++){
								printf("%d. %25s %2d��\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
							}
						}
					if(p->medinf.hospital.yes == 1){
							printf("ҽ�������������������ж���Ӧ����ҪסԺ��ϣ���������տ�����\n");
						//	printf("��Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
							printf("ҽ�������Ԥ����Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
					}
					printf("���������ļ���ǰ����̨���ɹҺŷѣ������ã�ҩƷ���ã���סԺ��Ѻ��лл\n");
					printf("�Ѿ�ǰ����س�");
					getchar();
					for(int i = 1; i <= p->medinf.checknum; i++){
						p->medinf.allcheckfee += check[p->medinf.check[i-1]].price;
					}
					for(int i = 1; i <= p->medinf.drugnum; i++){
						p->medinf.alldrugfee += drug[p->medinf.drug[i-1]].price*(float)p->medinf.drugqua[i-1];
					}
					printf("\n�Һŷѣ� 20 Ԫ\n����ܷ��ã�%.2f Ԫ\nҩƷ�ܷ��ã�%.2f Ԫ\nסԺѺ��: %.2f Ԫ\n�ܼƣ�%.2f Ԫ", p->medinf.allcheckfee,p->medinf.alldrugfee,p->medinf.hospital.pledge,p->medinf.allcheckfee+p->medinf.alldrugfee+p->medinf.hospital.pledge);	
					money += (p->medinf.allcheckfee + p->medinf.alldrugfee);
					printf("\n�ص����˵���س�");
					getchar();
					 
		}
		else if(option3 = 3){
			printf("���������ĹҺţ�");
			int num;
			scanf("%d", &num); 
			MedRecord* p = tail;
			while(1){
				if(p->patinf.number == num)
					break;
				p = p->last;
			}
			printf("ҽ�������Ԥ����Ժʱ��Ϊ%d��%d��%d��%d��\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
			printf("�����Ҫ��Ժ�𣿣�����1��������2��");
			int option4;
			scanf("%d", &option4);
			if(option4 == 1){
				int sum =total_day(M,D)-total_day(p->medinf.hospital.intime.month,p->medinf.hospital.intime.data);
				float summ;
		    if(hour<8){
		    	summ = (float)(sum-1)*200;
		    	printf("����Ҫ����%.2fԪ��סԺ��\n", summ);
			}   
            else{
            	summ = (float)(sum)*200;
            	printf("����Ҫ����%.2fԪ��סԺ��\n",summ);
		}
                printf("ҽԺ�����˻�%f��Ѻ��", p->medinf.hospital.pledge-summ);
				p->medinf.hospital.pledge = summ;
				money += summ;
			}
			else if (option4 == 2){
				printf("��������Ҫ��Ժ��ʱ�䣺\n");
				printf("�·�") ;
				scanf("%d",&p->medinf.hospital.outime.month);
				printf("\n����") ;
				scanf("%d", &p->medinf.hospital.outime.data);
				int sum =total_day(p->medinf.hospital.outime.month,p->medinf.hospital.outime.data)-total_day(p->medinf.hospital.intime.month,p->medinf.hospital.intime.data);
				float summ;
				summ = (float)(sum)*200;
				if(summ > p->medinf.hospital.pledge){
					printf("�벹��%.2fԪѺ��\n", summ-p->medinf.hospital.pledge);
					p->medinf.hospital.pledge = summ;
			}
			printf("����ҳ����س�");
			getchar();
			getchar(); 
		}	 
		}
	}
	}
	else if(option == 2){
		printf("��������Ĺ��ţ�");
		int number;
		scanf("%d", &number);
		while(number<1||number>30)
        {
            printf("���Ŵ�������������\n");
            scanf("%d", &number);
        }
		if(doctor[number].patnum){
			printf("�㻹��%dλ������Ҫ����", doctor[number].patnum);
			printf("����������Ҫ���ƵĲ��ˣ�\n");
			for(int i = 1; i <= doctor[number].patnum; i++){
				MedRecord* p;
				p = tail;
				while(1) {
				//	printf("%d\n",p->patinf.number);
					if(p->patinf.number == doctor[number].pat[i-1])
						break;
					p = p->last;
					}
				printf("��%dλ������Ϣ����\n", i);
				printf("������ %s\n", p->patinf.name);
				printf("���֤�ţ�%s\n", p->patinf.id);
				printf("���䣺%d\n", p->patinf.age);
				printf("����ʼ���....");
				printf("���ʳ���������û�У�����ϻس���");
				getchar();
				getchar();
				printf("�Ƿ���Ҫ��һ����飿������1������2)");
				int option;
				scanf("%d", &option);
				if(option == 1){
					printf("�����ǿ��Խ��еļ�飺\n");
					for(int j = 1; j <= 30; j+=3){
						printf("%2d. %32s  %2d. %32s  %2d. %32s\n", j, check[j].name, j+1, check[j+1].name, j+2, check[j+2].name, j+3, check[j+3].name);
					}
					printf("�����뵱ǰ������Ҫ����������\n");
					scanf("%d", &p->medinf.checknum);
					while(p->medinf.checknum>30||p->medinf.checknum<1)
                    {
                          printf("����������������������\n");
                          scanf("%d", &p->medinf.checknum);
                    }
					printf("������ÿ��ı�ţ��м���ӿո�:\n");
					for(int j = 0; j < p->medinf.checknum; j++)
                    {
						scanf("%d", &p->medinf.check[j]);
						while(p->medinf.check[j]>30||p->medinf.check[j]<1)
                        {
                            printf("���Ŵ�������������\n");
                            scanf("%d", &p->medinf.check[j]);
                        }
                    }
					printf("���ڼ����....(������������س�)");
				}

				getchar();
				getchar();
				printf("�Ƿ���Ҫ���п�ҩ��������1��������2��\n");
				int option2;
				scanf("%d", &option2);
				if(option2 == 1){
					printf("�������ܹ�����ҩ��\n");
				for(int j = 1; j <= 30; j+=3){
					printf("%2d. %32s  %2d. %32s %2d. %32s\n", j, drug[j].name, j+1, drug[j+1].name, j+2, drug[j+2].name, j+3, drug[j+3].name);
				}
				printf("�����뵱ǰ������ҪҩƷ����������\n");
				scanf("%d", &p->medinf.drugnum);
				while(p->medinf.drugnum>30||p->medinf.drugnum<1)
                {
                    printf("��ҪҩƷ������������������������\n");
                    scanf("%d", &p->medinf.drugnum);
                }
				printf("������ÿ��ı�����������м���ӿո񣩣�\n");
				for(int j = 0; j < p->medinf.drugnum; j++)
                {
					scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
					while(p->medinf.drug[j]>30||p->medinf.drug[j]<1)
                    {
                        printf("��%d��ҩƷ�Ŵ�������������\n",j+1);
                        scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
                    }
                    while(p->medinf.drugqua[j]>100||p->medinf.drugqua[j]<1)
                    {
                        printf("��%d��ҩƷ������������������\n",j+1);
                        scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
                    }
                }
				}
				printf("�Ƿ���ҪסԺ��������1��������2��");
				int option3;
				scanf("%d", &option3);
				if(option3 == 1){
				    p->medinf.hospital.intime.minute = min;
					p->medinf.hospital.intime.hour = hour;
					p->medinf.hospital.intime.month = M;
					p->medinf.hospital.intime.data = D;
					printf("Ԥ�����¼��ճ�Ժ��\n");
					printf("�·�");
			scanf("%d",&p->medinf.hospital.outime.month);
            int jv=0;
            while(jv==0)
            {
                jv=1;
                if(p->medinf.hospital.outime.month<p->medinf.hospital.intime.month)
                {
                    jv=0;
                    printf("��Ժ����Ӧ�ô���סԺ���ڣ�����������\n");
                    scanf("%d", &p->medinf.hospital.outime.month);
                }
                if(p->medinf.hospital.outime.month>12||p->medinf.hospital.outime.month<1)
                {
                    jv=0;
                    printf("�·ݴ���,����������\n");
                    scanf("%d", &p->medinf.hospital.outime.month);
                }
            }

			printf("����");
			scanf("%d", &p->medinf.hospital.outime.data);
			int xv,zv=0;
			while(xv==0||zv==0)
            {
                xv=1;zv=1;
                if(p->medinf.hospital.outime.month==p->medinf.hospital.intime.month)
                {
                    if(p->medinf.hospital.outime.data<p->medinf.hospital.intime.data)
                    {
                        printf("��Ժ����Ӧ�ô���סԺ���ڣ�����������\n");
                        scanf("%d", &p->medinf.hospital.outime.data);
                        xv=0;
                    }
                }
                if(p->medinf.hospital.outime.month==1||p->medinf.hospital.outime.month==3||p->medinf.hospital.outime.month==5||p->medinf.hospital.outime.month==7||p->medinf.hospital.outime.month==8||p->medinf.hospital.outime.month==10||p->medinf.hospital.outime.month==12)
			        {
			            if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>31)
                        {
                            printf("���ڴ���,����������\n");
                            scanf("%d", &p->medinf.hospital.outime.data);
                            zv=0;
                        }
			        }
			        else if(p->medinf.hospital.outime.month==2)
                    {
                        if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>29)
                        {
                            printf("���ڴ���,����������\n");
                            scanf("%d", &p->medinf.hospital.outime.data);
                            zv=0;
                        }
                    }
                    else
                    {
                        if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>30)
                        {
                            printf("���ڴ���,����������\n");
                            scanf("%d", &p->medinf.hospital.outime.data);
                            zv=0;
                        }
                    }
            }
					p->medinf.hospital.outime.hour = 23;
					p->medinf.hospital.outime.minute = 59;

				}
				int sum;
				sum =total_day(p->medinf.hospital.outime.month,p->medinf.hospital.outime.data)-total_day(p->medinf.hospital.intime.month,p->medinf.hospital.intime.data);
                printf("�û�����Ҫ���ٽ���%d��סԺѺ��\n",(sum)*200);
                p->medinf.hospital.pledge=(sum)*200;
				doctor[number].pat[i-1] = 0;
				printf("��%dλ���������ƽ�����ҽ���ҿ���...(��һ����س������û����ص�������)", i);
				getchar();
				getchar();
			}
			doctor[number].patnum = 0;
		}
		else{
			printf("����û���˹���ĺţ�������ϢƬ��Ŷ(�س��ص���ҳ��)");
			getchar();
			getchar();
		}

	}
	else if(option == 3){
            int mm,n;
            printf("������5λ����\n");
            scanf("%d",&mm);
            while(mm!=12345)
            {
                printf("�����������������");
                scanf("%d",&mm);
            }
            if(mm==12345)
                printf("��ӭ�������Ա����\n");
                while(1){
            printf("������Ҫ����ʲô����\n");
            printf("1.��ѯ����\n");
            printf("2.ɾ�����Ƽ�¼\n");
            printf("3.ͳ��ҽ��������æ�̶�\n");
            printf("4.��ӡĳ��ʱ�䷶Χ�ڵ�����������Ϣ\n");
            printf("5.���浱ǰ�����Ƽ�¼\n");
            printf("6.�˳�����Աϵͳ\n");
            scanf("%d",&n);
            if(n==1)
		    {
			   int m,u;
			   printf("1.���տ��ҵ�������Ϣ\n");
			   printf("2.����ҽ�����ŵ�������Ϣ\n");
			   printf("3.���ջ��߹Һŵ�������Ϣ\n");
			   printf("��ѡ���ѯ��ʽ:");
			   scanf("%d",&m);
			   if(m==1) {
				   for(int j = 1; j <= 10; j++)
				    	printf("%2d. %s\n", j, department[j]);
                   printf("��������Һ�:");
			  	   scanf("%d",&u); askdepart(head,tail,u);
               }
               if(m==2) { printf("������ҽ������:"); scanf("%d",&u); askdoc(head,tail,u); }
               if(m==3) { printf("�����뻼�߹Һ�:"); scanf("%d",&u); askpat(head,tail,u); }

		    }
		    if(n==2)
		    {
		        int m;
			    printf("��������ɾ���ļ�¼�ĹҺ�:");
			    scanf("%d",&m);
			    re(head,m);
		    }
		    if(n==3)
		    {
		        int u,m;
		        printf("������ҽ������:"); scanf("%d",&u);
			    m=statis2(head,u);
			    printf("%sҽ���ڸ�ʱ����ﹲ%d������\n",doctor[u].name,m);
		    }
		    if(n==4)
            {
                askday(head,tail);
            }
			if(n == 5){
				MedRecord* p = tail;
				while(1){
					if(p->patinf.number == prenum+1)
						break;
					p = p->last;
				}
				//fseek(inmedadd,0,SEEK_END); 
				while(1){
					fwrite(p, sizeof(MedRecord),1, inmedadd);
					if(p->next == NULL) break;
					p = p-> next;
				}
				printf("�Ѿ��������(������س�)");
				getchar(); 
			}
			if(n == 6) break; 
		}


	}
	else if(option == 4) {
		fclose(inmedadd);
		break;
	}
    }
    
    return 0;
}
