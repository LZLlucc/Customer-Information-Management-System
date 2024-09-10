#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mis.h"
int main(){

	cuslink L = cre_cus();
	void main_menu();
	printf("%d\n",L->last);
	
	culist cu1 = {0,"wang", 'm', 2, "123456", "44201@q.com"};
	culist cu2 = {1,"wang", 'm', 3, "124896","44301@q.com"};
	culist cu3 = {2,"huang", 'f', 2, "123456","44201@q.com"};
	culink q1 = &cu1;
	culink q2 = &cu2;
	culink q3 = &cu3;

	add_cus(L,q1,0);
	add_cus(L,q2,1);
	add_cus(L,q3,2);

	list_cus(L);
		
	modi_cus(L,2);
	
	list_cus(L);
	
	return 0;
}
