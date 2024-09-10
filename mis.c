#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mis.h"

/*
* @rec creat custumor_list
*/
cuslink cre_cus(){
	cuslink l;
	l = (cuslink)malloc(sizeof(cuslist));

	if (l == NULL){
		printf("allocation fail");
		return NULL;
	}
	
	//initialaion
	memset(l, 0, sizeof(culist));
	l->last = -1;

	return l;
}



/*
* @rec add custumor
*/
int add_cus(cuslink p, culink q, int pos){
	//full
	if (p->last == N-1){
		printf("full\n");
		return -1;			//full
	}

	//chek pos
	if (pos < 0 || pos > p->last + 1){
		printf("Pos is invalid\n");
		return -2;			//pos is invalid
	}

	//move
	for(int i = p->last; i > pos; i--){
		p->customer[i+1] = p->customer[i];
	}

	//update
	p->customer[pos] = *q;
	p->last++;

	return 0;
}



/*
* @rec show custumor_list
*/
int list_cus(cuslink p){
	if(p == NULL){
		return -1;			//fail
	}

	char *a = (char *)malloc(sizeof(culist) + 20);
	
	if(a == NULL){
		return -2;			//fail
	}

	culink q = (culink)malloc(sizeof(culist));
	
	if(q == NULL){
		return -1;			//fail
	}


	memset(a,0,sizeof(culist) + 20);
	memset(q,0,sizeof(culist));

	if(p->last == -1){
		printf("It is empty\n"); //empty
		return 1;
	}

	for (int i =0; i <= p->last; i++){
		q = &(p->customer[i]);
		sprintf(a,"nu = %d, name = %s, gender = %c, age = %d, tel = %s, mail = %s", q->nu, q->name, q->gender, q->age, q->tel, q->mail);

		printf("%s\n", a);
	}

	return 0;
}



/*
* @rec clear custumor_list
*/
int clear_cus(cuslink p){
	if(p == NULL){
		return -1;
	}

	free(p);
	p = NULL;

	return 0;
}




/*
* @rec modify custumor
*/
int modi_cus(cuslink p, int pos){
	
	culink q = (culink)malloc(sizeof(culist));
	
	if(q == NULL){
		printf("fail");
		return -1;
	}

	memset(q,0,sizeof(culist));


	if(pos > p->last || pos < 0){
		printf("invaid\n");
		return -2;
	}

	q->name = (char *)malloc(sizeof(50));

	if (q->name == NULL ){
		printf("fail\n");
		free(q);
		return -1;
	}

	q->tel = (char *)malloc(sizeof(50));
	if (q->tel == NULL ){
		printf("fail\n");
		free(q->name);
		free(q);
		return -1;
	}

	q->mail = (char *)malloc(sizeof(50));
	if (q->mail == NULL ){
		printf("fail\n");
		free(q->tel);
		free(q->name);
		free(q);
		return -1;
	}
	
	printf("please input information:\n");
	scanf("%s %c %d %s %s", q->name, &(q->gender), &(q->age), q->tel, q->mail);
	
	q->nu = pos;
	p->customer[pos] = *q;
	
	//free(q->name);
	//free(q->tel);
	//free(q->mail);
	//free(q);

	//q->name = NULL;
	//q->tel = NULL;
	//q->mail = NULL;
	q = NULL;

	return 0;
}


/*
 * @rec del customer
 */

int del_cus(cuslink p, int pos){
	if(pos < 0 || pos > p->last){
		printf("invalid\n");
		return -1;
	}
	

	for(int i = pos; i < p->last; i++){
		p->customer[i-1] = p->customer[i];
		p->customer[i-1].nu = p->customer[i-1].nu - 1;
	}

	p->last--;

	return 0;
}



/*
 * @rec main menu
 


	char a;
	printf("sure?(y or n)");
	scanf("%c", &a);
	if(a != y || a !=n){
		printf("\n please enter current number")
	}

   void main_menu(){
	do{
		printf("------客户管理软件-------\n");
		printf("       1、添加客户       \n");
		printf("       2、修改客户       \n");
		printf("       3、删除客户       \n");
		printf("       4、客户列表       \n");
		printf("       5、退出           \n ");
		
		printf("please enter the operation you need to perform:");
		int key;
		int loop = 1;
		scanf("%d", &key);
		
		switch(key){
			case 1:
				add_cus(cuslink p, culink q, int pos);
				break;

			case 2:
				modi_cus(cuslink p, int pos);
				break;

			case 3:
				del_cus(cuslink p, int pos);
				break;

			case 4:
				list_cus(culink p);
				break;

			case 5:
				loop = 0;
				break;

			default:
				printf("please enter anagin\n");
		}
	}while(loop);

	printf("1");
}

 */
