#include "struct7.h"
#include <malloc.h>
char level[5][20] = {" ","����ҽʦ", "������ҽʦ", "����ҽʦ", "סԺҽʦ"};
char department[11][20] = {" ", "�ڿ�", "���", "����", "����", "�ۿ�", "���Ǻ��", "��ǻ��", "Ƥ����", "��ҽ��", "������ѯ��"};
struct Check check[70];
struct DocInf doctor[31];
struct Drug drug[31];
void add(MedRecord *head,int n, int num, int weekday)
{                         //�����Ϣ
	MedRecord *p;
	int i=0;
	while(i<n)
	{
		p=(struct MedRecord *)malloc(sizeof(MedRecord));
		printf("������Ҫ��ӵ����Ƽ�¼:\n");
		printf("������Ҫ��ӵĻ�������:\n");
		scanf("%s",p->patinf.name);
		printf("��ĹҺ���%d", num+1);
		num++;
		printf("��ѡ����Ҫ�ҺŵĿ��ҵı�ţ�")
		for(int j = 1; j <= 10; j++){
			printf("%d. %s\n", j, department[j]);
		}
		int depart;
		scanf("%d", &depart);
		printf("��ѡ����Ҫ�Һŵ�ҽ����")
		for(int j = 1; j <= 30; j++){
			if(doctor[j].depart == depart && doctor[j].on[weekday] == 1){
				printf("%d. %s", j, doctor[j].name);
			}yao 
		}
		scanf("%d", &p->doctorid);
		printf("�����ǿ��Խ��еļ�飺\n");
		for(int j = 1; j <= 69; j+=3){
			printf("%d. %s    %d. %s   %d. %s\n", j, check[j].name, j+1, check[j+1].name, j+2, check[j+2], j+3, check[j+3]);
		} 
		printf("��������Ҫ����������\n");
		scanf("%d", &p->medinf.checknum);
		printf("������ÿ��ı�ţ��м���ӿո�:\n");
		for(int j = 0; j < &p->medinf.checknum; j++)
			scanf("%d", &p->medinf.check[j]);
		printf("�����ǿ��Թ����ҩ��\n");
		for(int j = 1; j <= 30; j+=3){
			printf("%d. %s    %d. %s   %d. %s\n", j, drug[j].name, j+1, drug[j+1].name, j+2, drug[j+2], j+3, drug[j+3]);
		} 
		printf("����������ҪҩƷ������")
		head->next=p;
		i++;
	}
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
}
void askdepart(MedRecord *head,int n)
{            //���տ��ҺŲ�ѯ
	MedRecord *p;
	for(p=head->next;p;p=p->next)
	{
		if(doctor[p->doctorid].depart==n)
		{
		    printf("%s",p->patinf.name);//������
		}
	}
}
void askdoc(MedRecord *head,int n)
{            //����ҽ�����Ų�ѯ
	MedRecord *p;
	for(p=head->next;p;p=p->next)
	{
		if(doctor[p->doctorid].number==n)
		{
		    printf("%s",p->patinf.name);//������
		}
	}
}
void askpat(MedRecord *head,int n)
{      //���ղ��˹ҺŲ�ѯ
	MedRecord *p;
	for(p=head->next;p;p=p->next)
	{
		if(p->patinf.number==n)
		{
		    printf("%s",p->patinf.name);//������
		}
	}
}

void count(MedRecord *top)
{
	int n=0;//�����������ڼ�¼ҽ��������
	top->doctorid=0;//��ͷ�ڵ�ҽ������һ���ʼ��Ϊһ�����Ϸ������ݣ���֤��һ��������䲻��
	MedRecord *p=top->next;
	MedRecord *p0=top;
	while(p)
	{
		if(doctor[p0->doctorid].number!=doctor[p->doctorid].number)
		{   //ҽ����ͬʱ��ͳ����λҽ���ķ�æ�̶Ȳ���ӡ����λҽ�����б�
			//ͳ����λҽ���ķ�æ�̶ȣ��ų�ͷ�ڵ㣩
			if(p0!=top)
			{
			    printf("��%d�����Ƽ�¼����æ�̶�Ϊ:",n);
			    if(n<=3) printf("����\n");
			    else if(n<=15) printf("����\n");
			    else printf("��æ\n");
			}
			//��ӡ����λҽ������Ϣ�б�
		 	printf("����");//����
		    printf("������Ϣ�б�\n");
		    printf("��������\t��������\t���߹Һ�\t�������\n");
		    n=0; //���㣬��ʼͳ����λҽ���Ļ�����
		}
		//��ӡ������Ϣ��ҽ���ﲡ����
		printf("%d",doctor[p->doctorid].number);//����
		n++;     //��¼ҽ��������
		p0=p;
		p=p->next;
	}
	//����:ͳ�����һλҽ����æ�̶�
	printf("��%d�����Ƽ�¼����æ�̶�Ϊ:",n);
	    if(n<=3) printf("����\n");
	    else if(n<=15) printf("����\n");
	    else printf("��æ\n");
}
void statis(MedRecord *head)
{
	MedRecord *p,*q0,*q,*p0;
	MedRecord *top;//������topΪͷ�ڵ������Ϊ�˽�ҽ�����չ���˳�򴢴棬��ͬһ��ҽ�����ӵ�һ��
	top=(struct MedRecord *)malloc(sizeof(struct MedRecord));
	top->next=NULL;
	for(p=head->next;p;p=p->next)
	{
		q=top->next; q0=top;
		while(q)
		{
			if(doctor[p->doctorid].number==doctor[q->doctorid].number)
			break;     //�ҵ���ͬ��ҽ��������ѭ�������뵽����ǰ��
			q0=q; q=q->next;
		}
		p0=(struct MedRecord *)malloc(sizeof(struct MedRecord));
		*p0=*p;
		p0->next=q;
		q0->next=p0;
	}
	count(top);
}
int main(){
	//printf("%s", level[1]);
	//printf("%s", department[7]);

	/*¼������Ϣ*/
	FILE *incheck;
	incheck = fopen("check2.txt", "r");
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
	indoctor = fopen("doctor2.txt", "r");
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

	/*¼��������Ϣ*/
	FILE *inmedrecord;
	inmedrecord = fopen("medrecord6.txt", "r");
	MedRecord* head;
	MedRecord* p1;
	MedRecord* p2;
	char temp5[5], temp6[5], temp7[10], temp8[50],temp9[150],temp10[20];
	int drugcat;
	int checkcat;
	head = (MedRecord*)malloc(sizeof(MedRecord));
	p2 = head;
	for(int j = 1; j <= 20; j++){
		p1 = (MedRecord*)malloc(sizeof(MedRecord));
		p2->next = p1;
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

	/*���¼���Ƿ���ȷ*/
	/*p1 = head->next;
	for(int i = 1; i <= 20; i++){
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
	}*/



	return 0;
}
