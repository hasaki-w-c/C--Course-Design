#include"stdio.h"     
#include"stdlib.h"    //其他说明
#include"string.h"    //字符串函数
#include"conio.h"     //getch从界面读入
#define LEN 100       //房间号和宿舍长最大字符数
#define N 10          //最大宿舍人数
void menu();          //声明函数
void help();          //说明
void shuaxin();       //输入信息
void seek();          //查找
void xiugai();        //修改
void paixu();         //排序
void del();           //删除
void xianshi();       //显示信息
void tongji();        //统计
void save();          //保存信息
void read1();         //读取文件 
void denglu();
int n=5;             //宿舍个数 
struct apartment
{
	char room[LEN];                  //房间号
	char dormitoryleader[LEN];       //宿舍长
	int dormitory;                   //楼号
	char member[500];                //宿舍成员
	char tel[20];                    //舍长电话号
	int livenumber;                  //居住人数
}stu[N];

int main()
{
	int x=1; 
	denglu();
	while(x!=0)
		menu();
	system("pause");
	return 0;
}


void denglu()
{
	char key[15];    //正确密码 
	char password[15];  //输入的密码 
	FILE *fp; 
  // fp=fopen("key.txt","rt");
  fp=fopen("key.txt","rt");
	fscanf(fp,"%s",key);
	printf("                                       用户登录\n\n");
	printf("                                       密  码：");
	while(1)
	{ 
		scanf("%s",password);
		if(strcmp(key,password)!=0)
		     printf("\n密码错误，请重新输入！\n"); 
		if(strcmp(key,password)==0)
		     break; 
	}
}

void menu()           //菜单
{
	char a;
	printf("               ##################宿舍系统功能菜单##################\n");
	printf("                       *#--------------------------------#*\n");
	printf("                        #      *0.系统帮助和说明*        #\n");
	printf("                        #      *1.刷新宿舍系统*          #\n");
	printf("                        #      *2.查询宿舍信息*          #\n");
	printf("                        #      *3.修改宿舍信息*          #\n");
	printf("                        #      *4.依据人数排序*          #\n");
	printf("                        #      *5.按房间号删除信息*      #\n");
	printf("                        #      *6.显示当前信息*          #\n");
	printf("                        #      *7.统计宿舍居住人数       #\n");
	printf("                        #         超过3的宿舍个数*       #\n");
	printf("                        #      *8.保存当前宿舍信息*      #\n");
	printf("                        #      *9.退出系统*              #\n");
	printf("                       *#--------------------------------#*\n");
	printf("                        (友情提示:查询前请先刷新菜单)\n    ");
	printf("                              请选择菜单编号:\n           ");
	a=getchar();
	fflush(stdin);
	switch(a)
	{
		case '0':
			help();
			break;
        case '1':
			shuaxin();
			break;
        case '2':
			seek();
			break;
		case '3':
			xiugai();
			break;
		case '4':
			paixu();
			break;
		case '5':
			del();
			break;
		case '6':
			xianshi();
			break;
		case '7':
			tongji();
			break;
		case '8':
			save();
			break;
		case '9':
			break;
		default:system("cls");
	}
}


void help()            //帮助
{
	printf("                              欢迎使用宿舍系统帮助!\n");
	printf("                         1.进入系统后,先刷新宿舍信息,再查询.\n");
	printf("                         2.按照菜单提示键输入序号.\n");
	printf("                         3.改变宿舍信息后记得保存信息.\n");
	printf("                         4.谢谢使用.\n\n\n\n");
}


void shuaxin()         //存入信息
{
	int i;
	FILE *fp;
	if(fp=NULL)
	{
		printf("cannot open!");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		printf("room:");
		scanf("%s",stu[i].room);
		printf("dormitoryleader:");
		scanf("%s",stu[i].dormitoryleader);
		printf("dormitory:");
		scanf("%d",&stu[i].dormitory);
		printf("member:");
		scanf("%s",stu[i].member);
		printf("tel:");
		scanf("%s",stu[i].tel);
		printf("livenumber:");
		scanf("%d",&stu[i].livenumber);
		printf("**********************\n");
	}
	for(i=0;i<n;i++)
	{
	if(i==0)
		fp=fopen("dormintory.txt","wt");
	else
		fp=fopen("dormintory.txt","at");
	fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory,stu[i].member,stu[i].tel,stu[i].livenumber);
	fclose(fp);
	}
	printf("录入完毕!\n");
}


void seek()         //信息查找
{
	int i,b,flag;
	char j[20];         //宿舍长和房间号最长长度 
	printf("                       --------------------\n");
	printf("                     $  1.按房间号查询 $\n   ");
	printf("                  $  2.按宿舍长查询 $\n   ");
	printf("                  $  3.退出本页     $\n    ");
	printf("                       --------------------\n");
	read1();
	while(1)
	{
		printf("请选择子菜单编号:\n");
		scanf("%d",&b);
		flag=0;
		switch(b)
		{
		case 1:
			printf("请输入要查询的房间号:\n");
			scanf("%s",j);
			for(i=0;i<n;i++)
				if(strcmp(stu[i].room,j)==0)
				{
					flag=1;
					printf("房间号  宿舍长   楼号 \n");
					printf("--------------------------------\n");
					printf("%0s%10s%10d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory);
					printf("*****************************************************\n");
					printf("宿舍成员            舍长电话号            居住人数\n");
					printf("--------------------------------\n");
					printf("%0s%30s%20d\n",stu[i].member,stu[i].tel,stu[i].livenumber);
				}
				if(flag==0)
					printf("该房间号不存在!\n");break;
        case 2:
			printf("请输入要查询的宿舍长:\n");
				scanf("%s",j);
			for(i=0;i<n;i++)
				if(strcmp(stu[i].dormitoryleader,j)==0)
				{
					flag=1;
					printf("房间号  宿舍长   楼号 \n");
					printf("--------------------------------\n");
					printf("%0s%10s%10d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory);
					printf("*****************************************************\n");
					printf("宿舍成员            舍长电话号            居住人数\n");
					printf("--------------------------------\n");
					printf("%0s%20s%20d\n",stu[i].member,stu[i].tel,stu[i].livenumber);
				}
				if(flag==0)
					printf("该宿舍长不存在!\n");break;
		case 3:return;
		default:printf("请在1到3中选择\n");
		}
	}
}


void xiugai()     //修改信息
{
	int i,a;
	char j[20],k[20];
	FILE *fp;
    read1();
	printf("请输入需要修改的宿舍的房间号");
	scanf("%s",j);
	for(i=0;(strcmp(stu[i].room,j)!=0);i++);
	if(strcmp(stu[i].room,j)==0);               /*比较字符串是否相等*/
	printf("               ------------------\n");
	printf("               1.修改宿舍长\n");
	printf("               2.修改楼号\n");
	printf("               3.修改宿舍成员\n");
	printf("               4.修改舍长手机号号码\n");
	printf("               5.修改居住人数\n");
	printf("               6.退出本菜单\n");
	printf("               ------------------\n");
	while(1)
	{
	printf("请选择子菜单编号:");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
	printf("请输入新的宿舍长:\n");
	scanf("%s",k);
	strcpy(stu[i].dormitoryleader,k); break;
	case 2:
	printf("请输入新的楼号：");
	scanf("%d",&stu[i].dormitory);break;
	case 3:
	printf("请输入新的宿舍成员：");
	scanf("%s",k);
	strcpy(stu[i].member,k); break;
	case 4:
	printf("请输入新的舍长手机号号码:\n");
	scanf("%s",k);
	strcpy(stu[i].tel,k); break;
	case 5:
	printf("请输入新的居住人数:\n");
	scanf("%d",&stu[i].livenumber); break;
	case 6:return;
	default:printf("请在1-6之间选择\n");
	}
    }
	fp=fopen("dormintory.txt","w");
	for(i=0;i<n;i++)
	fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory,stu[i].member,stu[i].tel,stu[i].livenumber);
	fclose(fp);
}


void paixu()        //按照居住人数排序
{
	int i,j,a;
	struct apartment t;
	read1();
	printf("                        *******************\n");
	printf("                        请选择排序方式\n");
	printf("                        1.从小到大排序\n");
	printf("                        2.从大到小排序\n");
	printf("                        3.退出本菜单\n");
	printf("                        *******************\n");
	while(1)
	{
		printf("请输入子菜单编号\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			for(i=0;i<n-1;i++)
			{

				for(j=0;j<n-i-1;j++)

				{
					if(stu[j].livenumber>stu[j+1].livenumber)
					{
						t=stu[j+1];
			            stu[j+1]=stu[j];
			            stu[j]=t;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				printf("房间号  宿舍长   楼号 \n");
		        printf("--------------------------------\n");
		        printf("%0s%10s%10d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory);
		        printf("*****************************************************\n");
		        printf("宿舍成员            电话号            居住人数\n");
		        printf("--------------------------------\n");
		        printf("%0s%20s%20d\n",stu[i].member,stu[i].tel,stu[i].livenumber);
			}
		break;
		case 2:
			for(i=0;i<n-1;i++)
			{

				for(j=0;j<n-i-1;j++)

				{
					if(stu[j].livenumber<stu[j+1].livenumber)
					{
						t=stu[j+1];
			            stu[j+1]=stu[j];
			            stu[j]=t;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				printf("房间号  宿舍长   楼号 \n");
		        printf("--------------------------------\n");
		        printf("%0s%10s%10d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory);
		        printf("*****************************************************\n");
		        printf("宿舍成员            电话号            居住人数\n");
		        printf("--------------------------------\n");
		        printf("%0s%20s%20d\n",stu[i].member,stu[i].tel,stu[i].livenumber);
			}
		break;
			case 3:return;
    	default:printf("请在1-3之间选择\n");
		}
	}
}


void del()        //删除部分信息 
{
	int i,j,flag=0;
	char s[10];
	read1();
	printf("请输入要删除的房间号:\n");
	scanf("%s",s);
	for(i=0;i<n;i++)
	if(strcmp(stu[i].room,s)==0)
	{
		flag=1;
		for(j=i;j<n-1;j++)
		stu[j]=stu[j+1];
	}
	if(flag==0)
		printf("该房间号不存在!\n");
	if(flag==1)
	{
		printf("删除成功,显示结果选择菜单6\n");
		n--;
		getch();
	}
}


void xianshi()        //显示当前信息 
{
	int i;
	read1();
	printf("所有宿舍的信息为:\n");
	printf("房间号  宿舍长   楼号 \n");
    printf("--------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%0s%10s%10d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory);
	}
	printf("*****************************************************\n");
	printf("宿舍成员            舍长电话号            居住人数\n");
	printf("--------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%0s%20s%20d\n",stu[i].member,stu[i].tel,stu[i].livenumber);
	}
}


void tongji()           //按条件进行统计 
{
	int i,p=0;	
	for(i=0;i<n;i++)
	{
		if(stu[i].livenumber>3)
		{
			p++;
		}
	}
	printf("符合条件的宿舍个数:%d\n",p);
}


void save()        //保存信息 
{
	int i;
	FILE *fp;
	fp=fopen("dormintory.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%s\t%s\t%d\t%s\t%s\t%d\n",stu[i].room,stu[i].dormitoryleader,stu[i].dormitory,stu[i].member,stu[i].tel,stu[i].livenumber);
	}
	fclose(fp);
	printf("保存成功!\n");
}

void read1()         //直接从文件中提取信息 
{
	int i;
	FILE *fp;
	if((fp=fopen("dormintory.txt","r")) == NULL) 
		puts("Open fail");
	if(fp!=NULL) 
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s\t%s\t%d\t%s\t%s\t%d\n",stu[i].room,stu[i].dormitoryleader,&stu[i].dormitory,stu[i].member,stu[i].tel,&stu[i].livenumber);
	} 
}  















	
