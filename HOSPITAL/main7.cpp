#include "struct8.h"
#include <malloc.h>
#include <time.h>

char level[5][20] = {" ","主任医师", "副主任医师", "主治医师", "住院医师"};
char department[11][20] = {" ", "内科", "外科", "儿科", "妇科", "眼科", "耳鼻喉科", "口腔科", "皮肤科", "中医科", "心理咨询室"};
struct Check check[70];
struct DocInf doctor[31];
struct Drug drug[31];
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
}
void askdepart(MedRecord *head,int n)
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
}
void askdoc(MedRecord *head,int n)
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
}
void askpat(MedRecord *head, int n)
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
}

void count(MedRecord *top)
{
	int n=0;//计数器，用于记录医生病例数
	top->doctorid=0;//将头节点医生工号一项初始化为一个不合法的数据，保证第一个结点与其不等
	MedRecord *p=top->next;
	MedRecord *p0=top;
	while(p)
	{
		if(doctor[p0->doctorid].number!=doctor[p->doctorid].number)
		{   //医生不同时，统计上位医生的繁忙程度并打印出下位医生的列表
			//统计上位医生的繁忙程度（排除头节点）
			if(p0!=top)
			{
			    printf("共%d例诊疗记录，繁忙程度为:",n);
			    if(n<=3) printf("空闲\n");
			    else if(n<=15) printf("正常\n");
			    else printf("繁忙\n");
			}
			//打印出下位医生的信息列表
		 	printf("补充");//补充
		    printf("出诊信息列表：\n");
		    printf("患者姓名\t患者年龄\t患者挂号\t就诊科室\n");
		    n=0; //归零，开始统计下位医生的患者数
		}
		//打印诊疗信息及医生诊病科室
		printf("%d",doctor[p->doctorid].number);//补充
		n++;     //记录医生病例数
		p0=p;
		p=p->next;
	}
	//特殊:统计最后一位医生繁忙程度
	printf("共%d例诊疗记录，繁忙程度为:",n);
	    if(n<=3) printf("空闲\n");
	    else if(n<=15) printf("正常\n");
	    else printf("繁忙\n");
}
void statis(MedRecord *head)
{
	MedRecord *p,*q0,*q,*p0;
	MedRecord *top;//建立以top为头节点的链表，为了将医生按照工号顺序储存，即同一名医生连接到一起
	top=(struct MedRecord *)malloc(sizeof(struct MedRecord));
	top->next=NULL;
	for(p=head->next;p;p=p->next)
	{
		q=top->next; q0=top;
		while(q)
		{
			if(doctor[p->doctorid].number==doctor[q->doctorid].number)
			break;     //找到相同的医生，跳出循环，插入到它的前面
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
	int num = 30;//挂号 
	
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
	printf("1. 患者\n2. 医生\n3.管理员\n");
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
			printf("你是哪里不舒服呢？下面是你能够挂的科室\n");
			for(int j = 1; j <= 10; j++){
				printf("%2d. %s\n", j, department[j]);
			}
			printf("请输入对应科室的编号：");
			int depart;
			scanf("%d", &depart);
			printf("下面这些医生是现在有空的：\n");
			for(int j = 1; j <= 30; j++){
				if(doctor[j].depart == depart && doctor[j].on[iWeek] == 1){
					printf("%2d. %s", j, doctor[j].name);
				}
			}
			printf("\n请输入你想要找的医生编号:");
			scanf("%d", &p->doctorid);
			doctor[p->doctorid].pat[doctor[p->doctorid].patnum] = num;
			doctor[p->doctorid].patnum++;
			tail->next = p;
			p->last = tail;
			tail = p;
			p->next = NULL;
			printf("\n你已经挂好号了，请耐心等待，还有%d人就到你了",doctor[p->doctorid].patnum-1);
		}
		
	}
	else if(option == 2){
		printf("请输入你的工号：");
		int number;
		scanf("%d", &number);
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
					printf("请输入每项的编号（中间请加空格）:\n");
					for(int j = 0; j < p->medinf.checknum; j++)
						scanf("%d", &p->medinf.check[j]);
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
				printf("请输入每项的编号与数量（中间请加空格）：\n");
				for(int j = 0; j < p->medinf.drugnum; j++){
					scanf("%d %d", &p->medinf.drug[j], &p->medinf.drugqua[j]);
				}
				}
				printf("是否需要住院？（是输1，不是输2）");
				int option3;
				scanf("%d", &option3);
				if(option3 == 1){
					printf("预估几月几日出院？(月和日之间加空格)");
					scanf("%d%d",&p->medinf.hospital.outime.month,&p->medinf.hospital.outime.data);
					p->medinf.hospital.outime.hour = 12;
					p->medinf.hospital.outime.minute = 0;
					p->medinf.hospital.intime.minute = min;
					p->medinf.hospital.intime.hour = hour;
					p->medinf.hospital.intime.month = M;
					p->medinf.hospital.intime.data = D;	
				}
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
		
	}
}
	
	
	
    printf("*****诊疗管理系统*****\n");
    printf("1.增加诊疗记录\n");
	printf("2.修改诊疗记录\n");
	printf("3.删除诊疗记录\n");
	printf("4.查询操作\n");
	printf("5.统计操作\n");
	printf("6.结束操作\n");
	printf("请选择您的操作，输入操作序号：\n");
	int n;// 选项 
    //计算周几
	/*switch(iWeek){
		case 1: printf("星期一\n"); break;
     	case 2: printf("星期二\n"); break;
     	case 3: printf("星期三\n"); break;
     	case 4: printf("星期四\n"); break;
     	case 5: printf("星期五\n"); break;
     	case 6: printf("星期六\n"); break;
     	case 7: printf("星期日\n"); break;
	}*/
	while(scanf("%d",&n) && n!=6)
	{
		
		if(n==1)
		{
			int m,nu;
			printf("请输入想增加的记录条数:");
		    scanf("%d",&m);
		    tail = add(tail, m, &num, iWeek);
		    //printf("结束请输入6"); 
		}
		if(n==2)
		{
			int m;
			printf("请输入想修改的纪录的挂号:");
			scanf("%d",&m);
			printf("2");
		}
		if(n==3)
		{
			int m;
			printf("请输入想删除的记录的挂号:");
			scanf("%d",&m);
			re(head,m);
		}
		if(n==4)
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
			  	scanf("%d",&u); askdepart(head,u); 
			}
			if(m==2) { printf("请输入医生工号:"); scanf("%d",&u); askdoc(head,u); }
			if(m==3) { printf("请输入患者挂号:"); scanf("%d",&u); askpat(head,u); }

		}
		if(n==5)
		{
			statis(head);
		}
		printf("*****诊疗管理系统*****\n");
    	printf("1.增加诊疗记录\n");
		printf("2.修改诊疗记录\n");
		printf("3.删除诊疗记录\n");
		printf("4.查询操作\n");
		printf("5.统计操作\n");
		printf("6.结束操作\n");
		printf("请选择您的操作，输入操作序号：\n");
	}
	//tail = add(tail, 3, 101, 4);
    return 0;
}
