#ifndef MIS_H
#define N 128

typedef struct{
	int nu;
	char *name;
	char gender;
	int age;
	char *tel;
	char *mail;
}culist, *culink;

typedef struct{
	culist customer[N];
	int last;
} cuslist,*cuslink;

cuslink cre_cus();
int add_cus(cuslink p, culink q, int pos);
int modi_cus(cuslink p, int pos);
int list_cus(cuslink p);
int del_cus(cuslink p, int pos);
int clear_cus(cuslink p);
void main_menu();
#endif
