#include "struct9.h"
#include <malloc.h>
#include <time.h>
#include <string.h>
char level[5][20] = {" ","主任医师", "副主任医师", "主治医师", "住院医师"};
char department[11][20] = {" ", "内科", "外科", "儿科", "妇科", "眼科", "耳鼻喉科", "口腔科", "皮肤科", "中医科", "心理咨询室"};
struct Check check[70];
struct DocInf doctor[31];
struct Drug drug[31];
int total_day(int month,int day)//计算这一年已经过的天数
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
        printf("输入的月份有错误\n");
        break;
    }
    return sum;
}

MedRecord* add(MedRecord *tail,int n, int* num, int weekday)//num 是挂号
{                         //添加信息
	MedRecord *p;
	int i=0;
	while(i<n)
	{
		p=(struct MedRecord *)malloc(sizeof(MedRecord));
		//printf("输入需要添加的诊疗记录:\n");
		printf("输入需要添加的患者名字:\n");
		scanf("%s",p->patinf.name);
		printf("你的挂号是%d\n", *num+1);
		(*num)++;
		printf("请选择你要挂号的科室的编号：\n");
		for(int j = 1; j <= 10; j++){
			printf("%2d. %s\n", j, department[j]);
		}
		int depart;
		scanf("%d", &depart);
		printf("请选择你要挂号的医生：\n");
		for(int j = 1; j <= 30; j++){
			if(doctor[j].depart == depart && doctor[j].on[weekday] == 1){
				printf("%2d. %s", j, doctor[j].name);
			}
		}
		printf("\n");
		scanf("%d", &p->doctorid);
		printf("如下是可以进行的检查：\n");
		for(int j = 1; j <= 30; j+=3){
			printf("%2d. %32s  %2d. %32s  %2d. %32s\n", j, check[j].name, j+1, check[j+1].name, j+2, check[j+2].name, j+3, check[j+3].name);
		}
		printf("请输入你要检查的项数；\n");
		scanf("%d", &p->medinf.checknum);
		printf("请输入每项的编号（中间请加空格）:\n");
		for(int j = 0; j < p->medinf.checknum; j++)
			scanf("%d", &p->medinf.check[j]);
		printf("如下是可以购买的药：\n");
		for(int j = 1; j <= 30; j+=3){
			printf("%2d. %32s  %2d. %32s %2d. %32s\n", j, drug[j].name, j+1, drug[j+1].name, j+2, drug[j+2].name, j+3, drug[j+3].name);
		}
		printf("请输入你需要药品的总数：\n");
		scanf("%d", &p->medinf.drugnum);
		printf("请输入每项的编号与数量（中间请加空格）：\n");
		for(int j = 0; j < p->medinf.drugnum; j++){
			scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
		}
		printf("请问你要住院吗？（需要请输1, 不需要请输入0）");
		int judge;
		scanf("%d", &judge);
		if(judge == 1){
			p->medinf.hospital.yes == 1;
			printf("你要多久开始住院？\n");
			printf("几月啊？");
			scanf("%d", &p->medinf.hospital.intime.month);
			printf("几号啊？");
			scanf("%d", &p->medinf.hospital.intime.data);
			printf("几点啊？");
			scanf("%d", &p->medinf.hospital.intime.hour);
			printf("几分啊？");
			scanf("%d", &p->medinf.hospital.intime.minute);
			printf("你要多久离开医院啊？\n");
			printf("几月啊？");
			scanf("%d",&p->medinf.hospital.outime.month);
			printf("几号啊？");
			scanf("%d", &p->medinf.hospital.outime.data);
			printf("几点啊？");
			scanf("%d", &p->medinf.hospital.outime.hour);
			printf("几分啊？");
			scanf("%d", &p->medinf.hospital.outime.minute);
		}
		tail->next=p;
		tail = p;
		i++;
	}
	return tail;
}

void change(MedRecord *head,int m)
{                  //修改信息
	MedRecord *p;
	for(p=head->next;p;p=p->next)
	    if(p->patinf.number==m)
	        break;
//撤销操作----讨论
	printf("输入修改后的诊疗记录:\n");
		scanf("%s",p->patinf.name);//代补充
}
void re(MedRecord *head,int m)
{                  //删除信息
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
    printf("删除成功");
}
int statis2(MedRecord *head,int n)
{
    int D1,M1,D2,M2;
    int m=0;
    printf("请输入开始的月:");
    scanf("%d",&M1);
    printf("请输入开始的日:");
    scanf("%d",&D1);
    printf("请结束开始的月:");
    scanf("%d",&M2);
    printf("请结束开始的日:");
    scanf("%d",&D2);
	MedRecord *p;
	printf("    姓名                  身份证号               挂号    医生编号   医生姓名   \n");
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
{      //按照时间查询
    int D1,M1,D2,M2;
    printf("请输入开始的月:");
    scanf("%d",&M1);
    printf("请输入开始的日:");
    scanf("%d",&D1);
    printf("请结束开始的月:");
    scanf("%d",&M2);
    printf("请结束开始的日:");
    scanf("%d",&D2);
	MedRecord *p;
	printf("    姓名                  身份证号               挂号    医生编号   医生姓名   \n");
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
	printf("是否需要对其中病例项目进行详细查询（是输1，不是输2）");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("请输入你要查询的病例的挂号");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("检查项数总共%d个, 如下：\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("是否还要查询其他病例？（不是输1，是输2）");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}

}
void askdepart(MedRecord *head,MedRecord *tail,int n)
{            //按照科室号查询
	MedRecord *p;
	p=head->next;
	printf("    姓名                  身份证号               挂号    医生编号   医生姓名   \n");
	for(p=head->next;p;p=p->next)
	{

		if(doctor[p->doctorid].depart==n)
		{
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("是否需要对其中病例项目进行详细查询（是输1，不是输2）");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("请输入你要查询的病例的挂号");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("检查项数总共%d个, 如下：\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("是否还要查询其他病例？（不是输1，是输2）");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}
}
void askdoc(MedRecord *head,MedRecord *tail,int n)
{            //按照医生工号查询
	MedRecord *p;
	printf("    姓名                  身份证号               挂号    医生编号   医生姓名   \n");
	for(p=head->next;p;p=p->next)
	{
		if(p->doctorid==n)
		{
		  printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("是否需要对其中病例项目进行详细查询（是输1，不是输2）");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("请输入你要查询的病例的挂号");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("检查项数总共%d个, 如下：\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("是否还要查询其他病例？（不是输1，是输2）");
    int option5;
    scanf("%d", &option5);
    if(option5 == 1)
            break;
					}
				}
}
void askpat(MedRecord *head,MedRecord *tail, int n)
{      //按照病人挂号查询

	MedRecord *p;
	printf("    姓名                  身份证号               挂号    医生编号   医生姓名   \n");
	for(p=head->next;p;p=p->next)
	{
		if(p->patinf.number==n)
		{
		    printf("%8s   %30s        %2d       %2d     %10s\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name);
		}
	}
	printf("是否需要对其中病例项目进行详细查询（是输1，不是输2）");
    int option4;
    scanf("%d", &option4);
    if(option4 == 1){
    while(1){
    printf("请输入你要查询的病例的挂号");
    int num;
    scanf("%d", &num);
    p = tail;
    while(1){
    if(p->patinf.number == num)
                break;
            p = p->last;
        }
    if(p->medinf.checknum != 0) {
    printf("检查项数总共%d个, 如下：\n", p->medinf.checknum);
    for(int i = 1; i <= p->medinf.checknum; i++){
            printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
        }
    }

    if(p->medinf.drugnum != 0){
    printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
    for(int i = 1; i <= p->medinf.drugnum; i++){
        printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
        }
    }
    if(p->medinf.hospital.yes == 1){
        printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
        printf("出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
    }
    printf("是否还要查询其他病例？（不是输1，是输2）");
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
	/*录入检查信息*/
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

	/*录入医生信息*/
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

	/*录入药品信息*/
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
	
	/*录入诊疗信息*/
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
	int prenum = 29;//已然读入的值；
	
	/*录入30以后的信息*/
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
	/*检查录入是否正确*/
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
	 
	int num = prenum;//挂号
	int D,M;//当前的日期和月份
    time_t timep;
    struct tm *p4;
    time (&timep);
    p4=gmtime(&timep);
    D=p4->tm_mday;/*获取当前月份日数,范围是1-31*/
    M=1+p4->tm_mon;/*获取当前月份,范围是0-11,所以要加1*/
    int iWeek = 1+(D+2*M+3*(M+1)/5+2020+2020/4-2020/100+2020/400)%7;
    int hour = 8+p4->tm_hour;
    int min = p4->tm_min;
    while(1){
	printf("\n\n\n\n\n");
	printf("\t\t|-----------------------欢迎来到和协医院----------------------|\n") ;
	printf("\t\t|-------当前时间：星期 %d --- %d 月 %d 日 %d 点 %d 分--------- |", iWeek, M, D, hour, min);
	printf("\n\n\n\n\n");
	printf("请问你是什么身份？\n");
	printf("1. 患者\n2. 医生\n3.管理员\n4.退出\n");
	int option;
	scanf("%d", &option);
	printf("\n");
	if(option == 1){
		printf("是要重新挂一个号呢，还是查询一下诊疗信息呢（挂号输1，查询输2）");
		int option2;
		scanf("%d", &option2);
		if(option2 == 1) {
			MedRecord* p = (struct MedRecord *)malloc(sizeof(MedRecord));
			printf("你的名字是：");
			scanf("%s",p->patinf.name);
			printf("请输入一下你的身份证号：\n");
			scanf("%s", p->patinf.id);
			p->patinf.age = 2020-((int)(p->patinf.id[6]-'0')*1000 + (int)(p->patinf.id[7]-'0')*100 + (int)(p->patinf.id[8]-'0')*10 + (int)(p->patinf.id[9]-'0'));
			printf("\n记住你的挂号是%d\n", num+1);
			num++;
			p->patinf.number = num;
			p->medinf.time.month=M;
			p->medinf.time.data=D;
			p->medinf.time.hour=hour;
			p->medinf.time.minute=min;
			printf("你是哪里不舒服呢？下面是你能够挂的科室\n");
			for(int j = 1; j <= 10; j++){
				printf("%2d. %s\n", j, department[j]);
			}
			printf("请输入对应科室的编号：");
			int depart;
			scanf("%d", &depart);
			while(depart>10||depart<1)
            {
                printf("科室编号错误，请重新输入\n");
                scanf("%d", &depart);
            }
			printf("下面这些医生是现在有空的：\n");
			for(int j = 1; j <= 30; j++){
				if(doctor[j].depart == depart && doctor[j].on[iWeek] == 1){
					printf("%2d. %s", j, doctor[j].name);
				}
			}
			printf("\n请输入你想要找的医生编号:");
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
                printf("医生工号错误，请重新输入\n");
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
			printf("\n你已经挂好号了，请耐心等待，还有%d人就到你了",doctor[p->doctorid].patnum-1);
		}


		else if (option2 == 2){
			printf("下列是您能够进行的功能；\n1. 查询病例\n2. 查询当前诊疗进度\n3. 住院时间\n");
			int option3;
			printf("请输入您需要进行的功能编号：");
			scanf("%d", &option3);
			if(option3 == 1){
				printf("\n请问你的身份证号是多少？");
				char id[30];
				scanf("%s", id);
				MedRecord *p;
				printf("    姓名                  身份证号               挂号    医生编号   医生姓名     时间\n");
				for(p=head->next;p;p=p->next)
				{
					if(!strcmp(p->patinf.id,id))
					{
		  				  printf("%8s   %30s        %2d       %2d     %10s  %d月%d日%d时%d分\n", p->patinf.name, p->patinf.id, p->patinf.number, p->doctorid, doctor[p->doctorid].name,p->medinf.time.month,p->medinf.time.data,p->medinf.time.hour,p->medinf.time.minute);
					}
				}
				printf("是否需要对其中病例项目进行详细查询（是输1，不是输2）");
				int option4;
				scanf("%d", &option4);
				if(option4 == 1){
					while(1){
						printf("请输入你要查询的病例的挂号");
						int num;
						scanf("%d", &num);
						p = tail;
						while(1){
							if(p->patinf.number == num)
								break;
							p = p->last;
						}
						if(p->medinf.checknum != 0) {
							printf("检查项数总共%d个, 如下：\n", p->medinf.checknum);
							for(int i = 1; i <= p->medinf.checknum; i++){
								printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
							}
						}

						if(p->medinf.drugnum != 0){
							printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
							for(int i = 1; i <= p->medinf.drugnum; i++){
								printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
							}
						}
						if(p->medinf.hospital.yes == 1){
							printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
							printf("出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
						}
						printf("是否还要查询其他病例？（不是输1，是输2）");
						int option5;
						scanf("%d", &option5);
						if(option5 == 1)
							break;
					}
				}
			}
		else if(option3 == 2){
			printf("请输入您的挂号：");
			int num;
			scanf("%d", &num); 
			MedRecord* p = tail;
			while(1){
				if(p->patinf.number == num)
					break;
				p = p->last;
			}
			printf("您所挂的科室是%s\n", department[doctor[p->doctorid].depart]);
			printf("您预定的医生是%s\n", doctor[p->doctorid].name);
			if(p->medinf.checknum != 0) {
					printf("现在你应该进行的检查如下：\n");
					printf("检查项数总共%d个\n", p->medinf.checknum);
					for(int i = 1; i <= p->medinf.checknum; i++){
						printf("%d. %s\n", i, check[p->medinf.check[i-1]].name);
					}
			}
					printf("检查完后请回车\n");
					getchar();
					getchar(); 
					if(p->medinf.drugnum != 0){
							printf("这些是医生为你开的药：\n"); 
							printf("开药种类总共%d种, 如下：\n", p->medinf.drugnum);
							for(int i = 1; i <= p->medinf.drugnum; i++){
								printf("%d. %25s %2d盒\n", i, drug[p->medinf.drug[i-1]].name, p->medinf.drugqua[i-1]);
							}
						}
					if(p->medinf.hospital.yes == 1){
							printf("医生根据你的诊疗情况，判断你应该需要住院，希望你能早日康复。\n");
						//	printf("入院时间为%d月%d日%d点%d分\n",p->medinf.hospital.intime.month,p->medinf.hospital.intime.data,p->medinf.hospital.intime.hour,p->medinf.hospital.intime.minute);
							printf("医生给你的预估出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
					}
					printf("请您或您的家人前往柜台缴纳挂号费，检查费用，药品费用，和住院的押金，谢谢\n");
					printf("已经前往请回车");
					getchar();
					for(int i = 1; i <= p->medinf.checknum; i++){
						p->medinf.allcheckfee += check[p->medinf.check[i-1]].price;
					}
					for(int i = 1; i <= p->medinf.drugnum; i++){
						p->medinf.alldrugfee += drug[p->medinf.drug[i-1]].price*(float)p->medinf.drugqua[i-1];
					}
					printf("\n挂号费： 20 元\n检查总费用：%.2f 元\n药品总费用：%.2f 元\n住院押金: %.2f 元\n总计：%.2f 元", p->medinf.allcheckfee,p->medinf.alldrugfee,p->medinf.hospital.pledge,p->medinf.allcheckfee+p->medinf.alldrugfee+p->medinf.hospital.pledge);	
					money += (p->medinf.allcheckfee + p->medinf.alldrugfee);
					printf("\n回到主菜单请回车");
					getchar();
					 
		}
		else if(option3 = 3){
			printf("请输入您的挂号：");
			int num;
			scanf("%d", &num); 
			MedRecord* p = tail;
			while(1){
				if(p->patinf.number == num)
					break;
				p = p->last;
			}
			printf("医生给你的预估出院时间为%d月%d日%d点%d分\n",p->medinf.hospital.outime.month,p->medinf.hospital.outime.data,p->medinf.hospital.outime.hour,p->medinf.hospital.outime.minute);
			printf("你今天要出院吗？（是输1，不是输2）");
			int option4;
			scanf("%d", &option4);
			if(option4 == 1){
				int sum =total_day(M,D)-total_day(p->medinf.hospital.intime.month,p->medinf.hospital.intime.data);
				float summ;
		    if(hour<8){
		    	summ = (float)(sum-1)*200;
		    	printf("你需要缴纳%.2f元的住院费\n", summ);
			}   
            else{
            	summ = (float)(sum)*200;
            	printf("你需要缴纳%.2f元的住院费\n",summ);
		}
                printf("医院向您退回%f的押金", p->medinf.hospital.pledge-summ);
				p->medinf.hospital.pledge = summ;
				money += summ;
			}
			else if (option4 == 2){
				printf("请输入你要出院的时间：\n");
				printf("月份") ;
				scanf("%d",&p->medinf.hospital.outime.month);
				printf("\n日期") ;
				scanf("%d", &p->medinf.hospital.outime.data);
				int sum =total_day(p->medinf.hospital.outime.month,p->medinf.hospital.outime.data)-total_day(p->medinf.hospital.intime.month,p->medinf.hospital.intime.data);
				float summ;
				summ = (float)(sum)*200;
				if(summ > p->medinf.hospital.pledge){
					printf("请补交%.2f元押金\n", summ-p->medinf.hospital.pledge);
					p->medinf.hospital.pledge = summ;
			}
			printf("回主页面请回车");
			getchar();
			getchar(); 
		}	 
		}
	}
	}
	else if(option == 2){
		printf("请输入你的工号：");
		int number;
		scanf("%d", &number);
		while(number<1||number>30)
        {
            printf("工号错误，请重新输入\n");
            scanf("%d", &number);
        }
		if(doctor[number].patnum){
			printf("你还有%d位病人需要治疗", doctor[number].patnum);
			printf("以下是你需要诊疗的病人；\n");
			for(int i = 1; i <= doctor[number].patnum; i++){
				MedRecord* p;
				p = tail;
				while(1) {
				//	printf("%d\n",p->patinf.number);
					if(p->patinf.number == doctor[number].pat[i-1])
						break;
					p = p->last;
					}
				printf("第%d位病人信息如下\n", i);
				printf("姓名： %s\n", p->patinf.name);
				printf("身份证号：%s\n", p->patinf.id);
				printf("年龄：%d\n", p->patinf.age);
				printf("请大夫开始检查....");
				printf("请问初步检查完毕没有？（完毕回车）");
				getchar();
				getchar();
				printf("是否需要进一步检查？（是输1，不是2)");
				int option;
				scanf("%d", &option);
				if(option == 1){
					printf("如下是可以进行的检查：\n");
					for(int j = 1; j <= 30; j+=3){
						printf("%2d. %32s  %2d. %32s  %2d. %32s\n", j, check[j].name, j+1, check[j+1].name, j+2, check[j+2].name, j+3, check[j+3].name);
					}
					printf("请输入当前病人需要检查的项数；\n");
					scanf("%d", &p->medinf.checknum);
					while(p->medinf.checknum>30||p->medinf.checknum<1)
                    {
                          printf("检查的项数错误，请重新输入\n");
                          scanf("%d", &p->medinf.checknum);
                    }
					printf("请输入每项的编号（中间请加空格）:\n");
					for(int j = 0; j < p->medinf.checknum; j++)
                    {
						scanf("%d", &p->medinf.check[j]);
						while(p->medinf.check[j]>30||p->medinf.check[j]<1)
                        {
                            printf("检查号错误，请重新输入\n");
                            scanf("%d", &p->medinf.check[j]);
                        }
                    }
					printf("正在检查中....(检查完毕请输入回车)");
				}

				getchar();
				getchar();
				printf("是否需要进行开药？（是输1，不是输2）\n");
				int option2;
				scanf("%d", &option2);
				if(option2 == 1){
					printf("如下是能够开的药：\n");
				for(int j = 1; j <= 30; j+=3){
					printf("%2d. %32s  %2d. %32s %2d. %32s\n", j, drug[j].name, j+1, drug[j+1].name, j+2, drug[j+2].name, j+3, drug[j+3].name);
				}
				printf("请输入当前患者需要药品的种类数：\n");
				scanf("%d", &p->medinf.drugnum);
				while(p->medinf.drugnum>30||p->medinf.drugnum<1)
                {
                    printf("需要药品的种类总数错误，请重新输入\n");
                    scanf("%d", &p->medinf.drugnum);
                }
				printf("请输入每项的编号与数量（中间请加空格）：\n");
				for(int j = 0; j < p->medinf.drugnum; j++)
                {
					scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
					while(p->medinf.drug[j]>30||p->medinf.drug[j]<1)
                    {
                        printf("第%d种药品号错误，请重新输入\n",j+1);
                        scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
                    }
                    while(p->medinf.drugqua[j]>100||p->medinf.drugqua[j]<1)
                    {
                        printf("第%d种药品数量错误，请重新输入\n",j+1);
                        scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
                    }
                }
				}
				printf("是否需要住院？（是输1，不是输2）");
				int option3;
				scanf("%d", &option3);
				if(option3 == 1){
				    p->medinf.hospital.intime.minute = min;
					p->medinf.hospital.intime.hour = hour;
					p->medinf.hospital.intime.month = M;
					p->medinf.hospital.intime.data = D;
					printf("预估几月几日出院？\n");
					printf("月份");
			scanf("%d",&p->medinf.hospital.outime.month);
            int jv=0;
            while(jv==0)
            {
                jv=1;
                if(p->medinf.hospital.outime.month<p->medinf.hospital.intime.month)
                {
                    jv=0;
                    printf("出院日期应该大于住院日期，请重新输入\n");
                    scanf("%d", &p->medinf.hospital.outime.month);
                }
                if(p->medinf.hospital.outime.month>12||p->medinf.hospital.outime.month<1)
                {
                    jv=0;
                    printf("月份错误,请重新输入\n");
                    scanf("%d", &p->medinf.hospital.outime.month);
                }
            }

			printf("日期");
			scanf("%d", &p->medinf.hospital.outime.data);
			int xv,zv=0;
			while(xv==0||zv==0)
            {
                xv=1;zv=1;
                if(p->medinf.hospital.outime.month==p->medinf.hospital.intime.month)
                {
                    if(p->medinf.hospital.outime.data<p->medinf.hospital.intime.data)
                    {
                        printf("出院日期应该大于住院日期，请重新输入\n");
                        scanf("%d", &p->medinf.hospital.outime.data);
                        xv=0;
                    }
                }
                if(p->medinf.hospital.outime.month==1||p->medinf.hospital.outime.month==3||p->medinf.hospital.outime.month==5||p->medinf.hospital.outime.month==7||p->medinf.hospital.outime.month==8||p->medinf.hospital.outime.month==10||p->medinf.hospital.outime.month==12)
			        {
			            if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>31)
                        {
                            printf("日期错误,请重新输入\n");
                            scanf("%d", &p->medinf.hospital.outime.data);
                            zv=0;
                        }
			        }
			        else if(p->medinf.hospital.outime.month==2)
                    {
                        if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>29)
                        {
                            printf("日期错误,请重新输入\n");
                            scanf("%d", &p->medinf.hospital.outime.data);
                            zv=0;
                        }
                    }
                    else
                    {
                        if(p->medinf.hospital.outime.data<1||p->medinf.hospital.outime.data>30)
                        {
                            printf("日期错误,请重新输入\n");
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
                printf("该患者需要至少交纳%d的住院押金\n",(sum)*200);
                p->medinf.hospital.pledge=(sum)*200;
				doctor[number].pat[i-1] = 0;
				printf("第%d位患者已诊疗结束，医生幸苦了...(下一个请回车，如果没有则回到主界面)", i);
				getchar();
				getchar();
			}
			doctor[number].patnum = 0;
		}
		else{
			printf("现在没有人挂你的号，可以休息片刻哦(回车回到主页面)");
			getchar();
			getchar();
		}

	}
	else if(option == 3){
            int mm,n;
            printf("请输入5位密码\n");
            scanf("%d",&mm);
            while(mm!=12345)
            {
                printf("密码错误，请重新输入");
                scanf("%d",&mm);
            }
            if(mm==12345)
                printf("欢迎进入管理员界面\n");
                while(1){
            printf("请问您要进行什么操作\n");
            printf("1.查询操作\n");
            printf("2.删除诊疗记录\n");
            printf("3.统计医生工作繁忙程度\n");
            printf("4.打印某段时间范围内的所有诊疗信息\n");
            printf("5.保存当前的诊疗记录\n");
            printf("6.退出管理员系统\n");
            scanf("%d",&n);
            if(n==1)
		    {
			   int m,u;
			   printf("1.按照科室的诊疗信息\n");
			   printf("2.按照医生工号的诊疗信息\n");
			   printf("3.按照患者挂号的诊疗信息\n");
			   printf("请选择查询方式:");
			   scanf("%d",&m);
			   if(m==1) {
				   for(int j = 1; j <= 10; j++)
				    	printf("%2d. %s\n", j, department[j]);
                   printf("请输入科室号:");
			  	   scanf("%d",&u); askdepart(head,tail,u);
               }
               if(m==2) { printf("请输入医生工号:"); scanf("%d",&u); askdoc(head,tail,u); }
               if(m==3) { printf("请输入患者挂号:"); scanf("%d",&u); askpat(head,tail,u); }

		    }
		    if(n==2)
		    {
		        int m;
			    printf("请输入想删除的记录的挂号:");
			    scanf("%d",&m);
			    re(head,m);
		    }
		    if(n==3)
		    {
		        int u,m;
		        printf("请输入医生工号:"); scanf("%d",&u);
			    m=statis2(head,u);
			    printf("%s医生在该时间段里共%d个病例\n",doctor[u].name,m);
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
				printf("已经保存完毕(结束请回车)");
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
