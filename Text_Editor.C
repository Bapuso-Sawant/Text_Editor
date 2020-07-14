// DEVELOPER :: BAPUSO SAWANT
// PROJECT :: TEXT-EDITOR

#include<stdio.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SAWANT B A 3031

int cntr=0;        // This counter for direct add file Or first take input from new then add file
int cntr1=0;	   // For save file directly OR after adding data from new
int cntr2=0;	   // For save as

int start_with_password();
void loading();
void save();
void saveas();
void add();
void open();
void exit();
void help();
void demo();

void block();
void block1();
void block2_for_help();
void blck1();
void blck2();
void blck3();
void blck4();
void blck5();
void block1_saveas2();
void block2_saveas2();
trial(int,int);
void nos(int);
void first_msg();
void second_msg();
void main()
{
	int n,i=0,j=0,k,f=0,n1,f1=0,t=1,v=0,m=0,c=1,flg=0,l=0,i2=0,j2=0,m1=7,nline=0;
	int k1=0,line=0,no=15,i1=0,j1=0,bc1=1,t1=0;
	char str1[200], ch, s[20], setname[20], s1[20], nm[20], st[100], choice, st1[100];
	char flname[20], takename[20], str_for_delete[400], small_str_for_delete[10];
	char nm_for_saveas[20], saveas[20], copied_data[400], saveas1[20],str_in_saveas[400];
	char file_name[20],fl_name_for_replace[20],str_for_replace[1000],seperated_str[1000][50],replace_by[30],for_replace[30];
	char str_for_scr[300][200],ch1,new_str[200][200];

	FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8,*fp9,*fp10,*fp11,*fp12,*fp13;
	clrscr();
	loading();
	t=start_with_password();
	if(t!=0)
	{
		goto end;
	}

	label1:
	clrscr();

	demo();
	label2:
	textcolor(13);
	gotoxy(5,5);
	cprintf("First enter your choice from above [Take help (Ctrl + H)]:");
	textcolor(14);
	for(i=2;i<=78;i++)
	{
		gotoxy(i,6);
		cprintf("%c",196);
	}
	gotoxy(5,8);
	fflush(stdin);
	n=getch();

	if(n==19)                 // it is only for new & save
	{
		lbl:
		clrscr();
		demo();
		gotoxy(18,9);
		printf("Enter file name:");
		block();
		gotoxy(22,11);
		fflush(stdin);
		fp1=fopen(gets(setname),"w");
		if(cntr1==0)
		{
			fclose(fp1);	//If file directly saved
			cntr1=0;
		}
		else if(cntr==1)
		{
			clrscr();
			demo();
			for(i=0;i<i2;i++)  //i2 is no of rows
			{
				for(j=0;new_str[i][j]!=0;j++)
					fputc(new_str[i][j],fp1);
			}
			fclose(fp1); 	//If file saved after new
			cntr1=0;	//It is necessary
			cntr=0;     //new kk
		}
		block();

		gotoxy(18,9);		// TO just print msg of file saved
		printf("Enter file name:");
		block();
		gotoxy(22,11);
		puts(setname);


		gotoxy(22,13);
		printf("File saved succesfully...");
		gotoxy(22,14);
		printf("Enter any key to exit :");
		getch();
		clrscr();
		demo();
		cntr=0;		 // Must do it for every condition
		cntr2=0;
		goto label2;
	}
	else if(n==14)
	{
		while(1)
		{
			//textcolor(15);
			gotoxy(5,m1);
			ch1=getchar();
			if(ch1=='\n')
			{
				new_str[i2][j2]='\0';
				i2++;     //  No of rows
				m1++;
				j2=0;
				nline++;
			}
			if(ch1==19)
			{
				new_str[i2][j2]='\0';
				cntr=1;	//new kk
				cntr1=1;
				goto lbl;
			}
			if(ch1==27)
			{
				break;
			}
			else
			{
				new_str[i2][j2]=ch1;
				j2++;
			}
			if(nline==18)
			{
				clrscr();
				demo();
				first_msg();
				m1=7;
				nline=0;
			}
		}
	       //	cntr=1;          // It must be here
		cntr1=1;
		cntr2=0;
		goto label2;
	}
	else if(n==24)
	{
		if(cntr2==0)	// Direct saveas
		{
			clrscr();
			demo();
			block1_saveas2();

			gotoxy(20,6);
			printf("Enter file name:");

			gotoxy(22,8);
			fflush(stdin);
			gets(nm_for_saveas);
			fp7=fopen(nm_for_saveas,"r");

			if(fp7==NULL)
			{
				gotoxy(22,10);
				printf("File does not exist..!!");
			}
			else
			{
				block2_saveas2();
				gotoxy(20,13);
				printf("Save as:");
				gotoxy(22,15);
				fflush(stdin);
				gets(saveas);

				//  Working of saveas
				while(fgets(copied_data,500,fp7));
				fp8=fopen(saveas,"w");	//  Copy data of previous file into new

				for(i=0;copied_data[i];i++)
				{
					fprintf(fp8,"%c",copied_data[i]);
				}
				gotoxy(22,17);
				printf("File saved as %s",saveas);
				fclose(fp8);
				remove(nm_for_saveas);	//  Delete previous file
			}

			fclose(fp7);

			getch();
		}
		cntr=0;
		cntr1=0;
		cntr2=0;
		clrscr();
		demo();
		goto label2;
	}
	else if(n==1)
	{
		clrscr();
		demo();
		gotoxy(18,9);
		printf("Enter file name:");
		block();
		fflush(stdin);

		fp2=fopen(gets(nm),"a");
		clrscr();
		demo();

		//conditions for direct add Or first take input from new then add
		if(cntr==0)
		{
			gotoxy(6,7);          // for direct add
			gets(st);

			for(i=0;st[i];i++)
			{
				fputc(st[i],fp2);
			}
		}
		else if(cntr==1)             // for new then add
		{
			for(i=0;str1[i];i++)
			{
				fputc(str1[i],fp2);
			}
		}

		fclose(fp2);

		// To show the message of file added succesfully
		clrscr();
		demo();
		gotoxy(18,9);
		printf("Enter file name:");
		block();
		puts(nm);
		gotoxy(22,13);
		printf("File added succesfully...\n");
		gotoxy(22,14);
		printf("Enter any key to exit :");
		getch();

		clrscr();
		demo();
		cntr=0;		 // It is necessary
		cntr1=0;
		cntr2=0;
		goto label2;
	}
	else if(n==15) //To open file
	{
		clrscr();
		demo();
		gotoxy(18,9);

		printf("Enter file name:");
		block();
		fflush(stdin);

		fp=fopen(gets(s),"r");
		if(fp==NULL)
		{
			gotoxy(20,13);
			printf("File does not exist !!");
			f1=0;
			getch();
		}
		else
		{
			clrscr();
			demo();
			while(!feof(fp))
			{
				ch=fgetc(fp);
				if(ch=='\n')
				{
					bc1++;
				}
			}
			fclose(fp);
			fp=fopen(s,"r");
			if(fp==NULL)
			{
				gotoxy(20,13);
				printf("File does not exist !!");
				f1=0;
			}
			else
			{
				i1=0,j1=0,line=0;
				while(!feof(fp))
				{
					ch=fgetc(fp);
					str_for_scr[i1][j1]=ch;
					if(ch=='\n')
					{
						str_for_scr[i1][j1+1]='\0';
						i1++;
						line++;
						j1=0;
					}
					else
					{
						j1++;
					}
				}
				str_for_scr[i1][j1]='\n';	//Imp conds of end
				str_for_scr[i1][j1+1]='\0';
			}
			demo();
			gotoxy(8,8);
//			while(k1!=line)
			while(ch!=27)
			{
				demo();
				second_msg();
				//trial(bc1);
				gotoxy(6,8);
				if(bc1>=15)
				{
					for(k1=t1;k1<t1+15;k1++)
					{
						for(l=0;str_for_scr[k1][l]!='\n';l++)
						{
							printf("%c",str_for_scr[k1][l]);
						}
						printf("\n%c    ",179);
					}
					nos(no);         // No of lines

					ch=getch();
					//
					if(ch==1)// && f1==1)   //Adding file after opening file
					{
						fp6=fopen(s,"a");
						gotoxy(6,23);
						gets(st1);//
						for(i=0;st1[i];i++)
						{
							fputc(st1[i],fp6);
						}

						// To show the message of file added succesfully
						clrscr();
						demo();
						gotoxy(18,9);
						printf("Enter file name:");
						block();
						puts(s);
						gotoxy(22,13);
						printf("File added succesfully...\n");
						gotoxy(22,14);
						printf("Enter any key to exit :");
						f1=0;
						getch();
					}

					// Working of saveas after opening file
					if(ch==24)// && f1==1)
					{
						clrscr();
						demo();
						gotoxy(20,9);
						printf("Save as:");
						block();
						gotoxy(22,11);
						fflush(stdin);
						gets(saveas1);

						//  Working of saveas
						fp=fopen(s,"r");
						while(fgets(str_in_saveas,400,fp));
						fp9=fopen(saveas1,"w");

						for(i=0;str_in_saveas[i];i++)
						{
							fprintf(fp9,"%c",str_in_saveas[i]);
						}
						fclose(fp9);
						fclose(fp);
						remove(s);

						gotoxy(22,13);
						printf("File saved as %s",saveas1);
						gotoxy(22,14);
						printf("Enter any key to exit...");
						f1=0;
						getch();
					}                         //


					if(ch==27 && k1<=line)
					{
						 break;
					}
					if(ch==80 && k1<=line) //Imp condionss
					{
						t1+=1;
						no++;
					}
					else if(ch==72 && t1>=1)
					{
						t1-=1;
						no--;
					}
					else if(ch==73 && t1>=15) //corrected imp conds
					{
						t1-=15;
						no-=15;
					}
					else if(ch==81 && t1<=(line-30)) //..||..
					{
						t1+=15;
						no+=15;
					}
				}
				else if(bc1<15 && bc1>=0)
				{
					for(k1=0;k1<bc1;k1++)
					{
						for(l=0;str_for_scr[k1][l]!='\n';l++)
						{
							printf("%c",str_for_scr[k1][l]);
						}
						printf("\n%c    ",179);
					}
					nos(no);
					ch=getch();
					if(ch==27)
					{
						 break;
					}
				}
				demo();
			}
			i1=0,j1=0,bc1=1,t1=0,k1=0,line=1,no=15,nline=0; //Initialization as it is
			fclose(fp);
		}
		//

		f1=1;	// To  saveas OR add file iff file is exist
		///
	      /*	fflush(stdin);
		n1=getch();  // Take input from user to add or not OR saveas or not

		// Working of adding file after opening
		if(n1==1 && f1==1)
		{
			fp6=fopen(s,"a");
			gets(st1);
			for(i=0;st1[i];i++)
			{
				fputc(st1[i],fp6);
			}
			fclose(fp6);

			// To show the message of file added succesfully
			clrscr();
			demo();
			gotoxy(18,9);
			printf("Enter file name:");
			block();
			puts(s);
			gotoxy(22,13);
			printf("File added succesfully...\n");
			gotoxy(22,14);
			printf("Enter any key to exit :");
			f1=0;
			getch();
		}

		// Working of saveas after opening file
		if(n1==24 && f1==1)
		{
			clrscr();
			demo();
			gotoxy(20,9);
			printf("Save as:");
			block();
			gotoxy(22,11);
			fflush(stdin);
			gets(saveas1);

			//  Working of saveas
			fp=fopen(s,"r");
			while(fgets(str_in_saveas,400,fp));
			fp9=fopen(saveas1,"w");

			for(i=0;str_in_saveas[i];i++)
			{
				fprintf(fp9,"%c",str_in_saveas[i]);
			}
			fclose(fp9);
			fclose(fp);
			remove(s);

			gotoxy(22,13);
			printf("File saved as %s",saveas1);
			gotoxy(22,14);
			printf("Enter any key to exit...");
			f1=0;
			getch();
		}*/
		clrscr();
		demo();
		cntr=0;
		cntr1=0;
		cntr2=0;
		goto label2;
	}
	else if(n==8)
	{
		help();
		getch();
		clrscr();
		demo();
		cntr=0;
		cntr1=0;
		cntr2=0;
		goto label2;
	}
	else if(n==5 || n==27)
	{
		cntr=0;
		cntr1=0;
		cntr2=0;
		clrscr();
		gotoxy(30,15);
		printf("Please wait");
	//	for(i=50;i<=53;i++)
		{
	  //		delay(500);
			gotoxy(i,30);
			printf(".");
		}
		delay(50);
		exit(1);
	}
	else if(n==4)
	{
		label3:

		clrscr();
		demo();
		blck1();
		blck2();
		blck3();
		blck4();
		blck5();
		gotoxy(18,6);
		printf("Select your choice:");
		fflush(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
		       case '1':
				clrscr();
				demo();
				block();
				gotoxy(20,9);
				printf("Enter file name:");
				gotoxy(21,11);
				fflush(stdin);
				gets(flname);
				fp3=fopen(flname,"r");
				if(fp3==NULL)
				{
						gotoxy(20,13);
					printf("File does not exist");
				}
				else
				{
					remove((flname));
					gotoxy(20,13);
					printf("File removed succesfully...");
				}
				fclose(fp3);
				getch();
				goto label3;
				break;

		       case '2':
				clrscr();
				demo();
				gotoxy(18,9);
				printf("Enter file name:");
				block();
				gotoxy(22,11);

				fflush(stdin);		// imp for taking input
				gets(file_name);
				fp10=fopen(file_name,"r");
				if(fp10==NULL)
				{
					gotoxy(20,13);
					printf("File does not exist");
				}
				else
				{
					remove(file_name);		//Delete 1st file & create another file of same name
					fp11=fopen(file_name,"w");
					fclose(fp11);
					gotoxy(20,13);
					printf("All records are removed succesfully...");
				}
				fclose(fp10);
				getch();
				goto label3;
				break;

		       case '3':
				clrscr();
				demo();
				gotoxy(18,9);
				printf("Enter file name:");
				block();
				gotoxy(22,11);

				fflush(stdin);		// imp for taking input
				gets(takename);
				fp4=fopen(takename,"r");
				if(fp4==NULL)
				{
					gotoxy(20,13);
					printf("File does not exist");
				}
				else
				{
					while(fgets(str_for_delete,400,fp4));

					//working of delete string
					clrscr();
					demo();
					gotoxy(18,9);
					printf("Which string u want to delete");
					block();
					gotoxy(22,11);

					fflush(stdin);
					gets(small_str_for_delete);
					for(i=0;str_for_delete[i];i++)
					{
						if(str_for_delete[i]==small_str_for_delete[j])
						{
							j++;
						}
						else
						{
							j=0;
						}
						if(small_str_for_delete[j]=='\0')
						{
							i=i+1-j;
							for(k=i;str_for_delete[k];k++)
							{
								str_for_delete[k]=str_for_delete[k+j];
							}
							j=0;
							f=1;
						}
					}
					if(f!=1)
					{
						gotoxy(22,13);
						printf("Given string is not present in the file...");
					}
					else
					{
						gotoxy(22,13);
						printf("Word removed sucessfully...");
						f=0;	//imp to know whether string is present or not again
					}
					fp5=fopen(takename,"w+");
					fprintf(fp5,"%s",str_for_delete);
					fclose(fp5);
				}
				fclose(fp4);
				getch();
				goto label3;
				break;

		       case '4':
				clrscr();
				demo();
				block();
				gotoxy(18,9);
				printf("Enter file name:");
				gotoxy(22,11);

				fflush(stdin);		// imp for taking input
				gets(fl_name_for_replace);
				fp12=fopen(fl_name_for_replace,"r");
				if(fp12==NULL)
				{
					gotoxy(20,13);
					printf("File does not exist");
				}
				else
				{
					//  Working of replacement
					clrscr();
					demo();
					block1_saveas2();
					gotoxy(20,6);
					printf("Which string u want to replace");
					gotoxy(22,8);

					fflush(stdin);
					gets(for_replace);	//for_replace is string which is taken from user which is to be replaced

					// To take the big string str_for_replace from file here...
					while(fgets(str_for_replace,1000,fp12)); //1000 is imp value update when it is updated in datatype

					// Seperate in 2 dimensional string
					for(i=0;str_for_replace[i]!='\0';i++)
					{
						seperated_str[m][v]=str_for_replace[i];
						v++;
						if(str_for_replace[i]==' ')
						{
							seperated_str[m][--v]='\0';
							m++;
							v=0;
							c++;
						}
					}
					seperated_str[m][v]='\0';

					// It only check whether string is present or not in file
					for(i=0;i<c;i++)
					{
						if(!strcmp(for_replace,seperated_str[i]))
						{
							flg=1;  // To check given word is present or not in file which is to be replaced
						}
					}

					if(flg!=1)
					{
						gotoxy(22,10);
						printf("Given string is not present in the file...");
						flg=0;
					}
					else
					{
						// Acutal working of replacement
						block2_saveas2();
						gotoxy(20,13);
						printf("By which string u want to replace\n");
						gotoxy(22,15);
						gets(replace_by);

						for(i=0;i<c;i++)
						{
							if(!strcmp(for_replace,seperated_str[i]))
							{
								for(v=0;replace_by[v];v++)
								{
									seperated_str[i][v]=replace_by[v];
								}
								seperated_str[i][v]='\0';
							}
						}
						gotoxy(22,17);
						printf("String replaced succesfully...");
						flg=0; //It is imp for to check again whether string is present or not

						// This is actual working of writing new big string in file which also contain replaced string ..big file is 2 dimensional ..ie seperated_str
						remove(fl_name_for_replace);
						fclose(fp12);
						fp13=fopen(fl_name_for_replace,"w");
						for(i=0;i<c;i++)
						{
							fprintf(fp12,"%s ",seperated_str[i]);
						}
						fclose(fp13);
					}

				}
				getch();
				goto label3;
				break;

		       case '5':
				break;

		       default:
				gotoxy(20,22);
				printf("Enter valid choice...");
				gotoxy(20,23);
				printf("Enter any key to continue...");
				getch();
				goto label3;
				break;
		}

		clrscr();
		demo();
		cntr=0;		 // it is necessary
		cntr1=0;
		cntr2=0;
		goto label2;

	}
	else
	{
		clrscr();
		demo();
		block1();
		textcolor(4);
		gotoxy(27,11);
		cprintf("Please enter valid input");
		gotoxy(21,13);
		cprintf("Plese take the help to know [CTRL + H]");
		gotoxy(27,15);
		cprintf("Enter any key to continue...");
		getch();
		clrscr();
		demo();
		goto label2;
	}
	end:
	getch();
}

trial(int c1,int no)
{

	int r;
	static int i=7,cnt=0;
	char ch;

	demo();
	r=c1/15;

	if(i<=24)
	{
		gotoxy(78,i);
		printf("%c",219);
	}

	cnt++;
	if(cnt==r)
	{
		i++;
		cnt=0;
	}
	return(1);
}


void nos(int x)
{
	gotoxy(72,24);
	printf("|%d|",x);
}
void dem()
{
	printf("hii");
}
void demo()
{
	int i;
	clrscr();
	textcolor(14);
	cprintf("%c",218);
	for(i=0;i<77;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	for(i=2; i<=24; i++)
	{
		gotoxy(1,i);
		cprintf("%c",179);
	}
	gotoxy(1,25);
	cprintf("%c",192);

	for(i=2;i<=79;i++)
	{
		gotoxy(i,25);
		cprintf("%c",196);
	}
	gotoxy(79,25);
	cprintf("%c",217);
	for(i=2; i<=24; i++)
	{
		gotoxy(79,i);
		cprintf("%c",179);
	}
	gotoxy(2,4);
	for(i=0;i<77;i++)
	{
		cprintf("%c",196);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(10,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(20,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(30,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(40,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(50,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(60,i);
		cprintf("%c",179);
	}
	for(i=2;i<4;i++)
	{
		gotoxy(70,i);
		cprintf("%c",179);
	}
	gotoxy(4,2);
	cprintf("New");
	gotoxy(13,2);
	cprintf("Save");
	gotoxy(22,2);
	cprintf("Save As");
	gotoxy(34,2);
	cprintf("Add");
	gotoxy(43,2);
	cprintf("Open");
	gotoxy(53,2);
	cprintf("Delete");
	gotoxy(63,2);
	cprintf("Help");
	gotoxy(73,2);
	cprintf("Exit");
}

void first_msg()
{
	int i;
	textcolor(13);
	gotoxy(5,5);
	cprintf("First enter your choice from above:");
	textcolor(14);
	for(i=2;i<=78;i++)
	{
		gotoxy(i,6);
		cprintf("%c",196);
	}

}
void second_msg()
{
	int i;
	gotoxy(10,5);
	textcolor(11);
	cprintf("Enter 'ESC' to exit...");
	for(i=2;i<=78;i++)
	{
		gotoxy(i,6);
		printf("-");
	}
}
void help()
{
	clrscr();
	demo();
	block2_for_help();
	gotoxy(6,5);
	textcolor(6);
	cprintf("HELP:-");
	gotoxy(20,7);
	cprintf("1. New    [CTRL + N]");
	gotoxy(20,8);
	cprintf("2. Save   [CTRL + S]");
	gotoxy(20,9);
	cprintf("3. SaveAs [CTRL + X]");
	gotoxy(20,10);
	cprintf("4. Add    [CTRL + A]");
	gotoxy(20,11);
	cprintf("5. Open   [CTRL + O]");
	gotoxy(20,12);
	cprintf("6. Delete [CTRL + D]");
	gotoxy(20,13);
	cprintf("7. Help   [CTRL + H]");
	gotoxy(20,14);
	cprintf("8. Exit   [CTRL + E] OR ESC");
	gotoxy(20,15);
	cprintf("9. Press the ENTER button to");
	gotoxy(20,16);
	cprintf("   change the line");
	gotoxy(15,20);
	cprintf("Enter any key...");
}

void block()
{
	int i;
	gotoxy(20,10);
	textcolor(15);
	cprintf("%c",218);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(59,11);
	cprintf("%c",179);
	gotoxy(20,12);
	cprintf("%c",192);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,11);
	cprintf("%c",179);
}

void block1()
{
	int i;
	gotoxy(20,10);
	textcolor(10);
	cprintf("%c",218);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(59,11);
	cprintf("%c",179);
	gotoxy(59,12);
	cprintf("%c",179);
	gotoxy(59,13);
	cprintf("%c",179);
	gotoxy(59,14);
	cprintf("%c",179);
	gotoxy(59,15);
	cprintf("%c",179);
	gotoxy(59,16);
	cprintf("%c",179);

	gotoxy(20,17);
	cprintf("%c",192);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,11);
	cprintf("%c",179);
	gotoxy(20,12);
	cprintf("%c",179);
	gotoxy(20,13);
	cprintf("%c",179);
	gotoxy(20,14);
	cprintf("%c",179);
	gotoxy(20,15);
	cprintf("%c",179);
	gotoxy(20,16);
	cprintf("%c",179);
}

void block2_for_help()
{
	int i;
	gotoxy(15,6);
	textcolor(10);
	cprintf("%c",218);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(54,7);
	cprintf("%c",179);
	gotoxy(54,8);
	cprintf("%c",179);
	gotoxy(54,9);
	cprintf("%c",179);
	gotoxy(54,10);
	cprintf("%c",179);
	gotoxy(54,11);
	cprintf("%c",179);
	gotoxy(54,12);
	cprintf("%c",179);
	gotoxy(54,13);
	cprintf("%c",179);
	gotoxy(54,14);
	cprintf("%c",179);
	gotoxy(54,15);
	cprintf("%c",179);
	gotoxy(54,16);
	cprintf("%c",179);

	gotoxy(15,17);
	cprintf("%c",192);
	for(i=1;i<=38;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(15,7);
	cprintf("%c",179);

	gotoxy(15,8);
	cprintf("%c",179);
	gotoxy(15,9);
	cprintf("%c",179);
	gotoxy(15,10);
	cprintf("%c",179);
	gotoxy(15,11);
	cprintf("%c",179);
	gotoxy(15,12);
	cprintf("%c",179);
	gotoxy(15,13);
	cprintf("%c",179);
	gotoxy(15,14);
	cprintf("%c",179);
	gotoxy(15,15);
	cprintf("%c",179);
	gotoxy(15,16);
	cprintf("%c",179);
}

void loading()
{
	int i,j;
	clrscr();
	gotoxy(1,9);
	gotoxy(36,12);
	printf("LOADING...");
	textcolor(14);
	gotoxy(3,13);
	cprintf("%c",218);
	for(i=1;i<=75;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(3,14);
	for(i=2;i<=77;i++)
	{
		cprintf("%c",196);
	}
	gotoxy(3,14);
	cprintf("%c",192);
	gotoxy(79,14);
	cprintf("%c",217);
	for(i=3,j=10;i<=79;i++,j++)
	{
		textcolor(12);
		delay(i);
		gotoxy(38,15);
		if(i==79)
			printf("100%");
		else
		printf("%d%",j);
		gotoxy(i,13);
		cprintf("%c",220);
		gotoxy(i,14);
		cprintf("%c",223);
	}
	delay(200);
	clrscr();
}

// blck1, blck2, blck3, blck4, blck5 are the blocks for delete choices
void blck1()
{
	int i;
	gotoxy(22,8);
	textcolor(12);
	cprintf("1. Delete file");
	gotoxy(20,7);
	cprintf("%c",218);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(53,8);
	cprintf("%c",179);
	gotoxy(20,9);
	cprintf("%c",192);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,8);
	cprintf("%c",179);
}

void blck2()
{
	int i;
	gotoxy(22,11);
	textcolor(12);
	cprintf("2. Delete all records from file");
	gotoxy(20,10);
	cprintf("%c",218);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(53,11);
	cprintf("%c",179);
	gotoxy(20,12);
	cprintf("%c",192);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,11);
	cprintf("%c",179);
}

void blck3()
{
	int i;
	gotoxy(22,14);
	textcolor(12);
	cprintf("3. Delete word");
	gotoxy(20,13);
	cprintf("%c",218);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(53,14);
	cprintf("%c",179);
	gotoxy(20,15);
	cprintf("%c",192);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,14);
	cprintf("%c",179);
}

void blck4()
{
	int i;
	gotoxy(22,17);
	textcolor(12);
	cprintf("4. Replace word");
	gotoxy(20,16);
	cprintf("%c",218);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(53,17);
	cprintf("%c",179);
	gotoxy(20,18);
	cprintf("%c",192);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,17);
	cprintf("%c",179);
}

void blck5()
{
	int i;
	gotoxy(22,20);
	textcolor(12);
	cprintf("5. Exit");
	gotoxy(20,19);
	cprintf("%c",218);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",191);
	gotoxy(53,20);
	cprintf("%c",179);
	gotoxy(20,21);
	cprintf("%c",192);
	for(i=1;i<=32;i++)
	{
		cprintf("%c",196);
	}
	cprintf("%c",217);
	gotoxy(20,20);
	cprintf("%c",179);
}

void block1_saveas2()
{
	int i;
	gotoxy(20,7);
	printf("%c",218);
	for(i=1;i<=38;i++)
	{
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(59,8);
	printf("%c",179);
	gotoxy(20,9);
	printf("%c",192);
	for(i=1;i<=38;i++)
	{
		printf("%c",196);
	}
	printf("%c",217);
	gotoxy(20,8);
	printf("%c",179);
}
void block2_saveas2()                     	
{
	int i;
	gotoxy(20,14);
	printf("%c",218);
	for(i=1;i<=38;i++)
	{
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(59,15);
	printf("%c",179);
	gotoxy(20,16);
	printf("%c",192);
	for(i=1;i<=38;i++)
	{
		printf("%c",196);
	}
	printf("%c",217);
	gotoxy(20,15);
	printf("%c",179);
}

int start_with_password()
{
	int k=0,i=0;
	char password[]="sawant",get_password[30],ch;
	gotoxy(20,9);
	textcolor(6);
	cprintf("Enter password:");
	block();
	gotoxy(22,11);
	while(1)
	{
		ch=getch();
		if(ch==ENTER)
		{
			get_password[i]='\0';
			break;
		}
		else if(ch==TAB)
		{
			get_password[i]='\t';
			cprintf("*");
			i++;
		}
		else if(ch==BKSP)
		{
			get_password[i]='\b';
			cprintf("*");
			i++;
		}
		else
		{
			get_password[i]=ch;
			cprintf("*");
			i++;
		}
	}

	k=strcmp(get_password,password);
	if(k==0)
	{
		return 0;
	}
	else
	{
		gotoxy(22,13);
		cprintf("Wrong password..!!");
		return 1;
	}
}


