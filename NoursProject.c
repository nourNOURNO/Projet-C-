#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100

void menu ( ) {
	printf("*************************************************************\n");
	printf("1  .  Add the products.\n");
	printf("2  .  Show a product.\n");
	printf("3  .  Delete a product.\n");
	printf("4  .  Show all products.\n");
	printf("5  .  Exit.\n");
	printf("*************************************************************\n");
	printf("Please choose a corresponding key . \n") ;	
}

typedef struct {
	unsigned int id, quantity;
	char name[100], brand[20];
	float price;
	int *size ;
} product ;


void add_product (product tabG [], product p, int * n){
  *(tabG+*n)=p;
}
    
unsigned int IdLocation( unsigned int x , product tabG [] , int size ) {
	int i = 0 ;
	while ( i<size && tabG[i].id !=x ) i++;
	if ( i <= size-1 ) return i;
	else return -1 ;
	
}

void show_all_products( product tabG [], int size) {
	int i = 0 ; 
	for  (i = 0 ; i< size ; i++){
		printf("Product num%d : \nID: %u -- Brand : %s  -- Name : %s -- Quantity: %u -- Price: %.2f$ \n\n\n",i,tabG[i].id,tabG[i].brand,tabG[i].name,tabG[i].quantity,tabG[i].price);
	}
}

void delete_product_pos (product tabG[] ,int pos , int *size) {
	int i ;
	for(i=pos; i<*size-1 ; i++) tabG[i]=tabG[i+1] ;
	*(size)--;	
}

	
int main(int argc, char *argv[]) {
	product tabG[max];
	int choice=-1 ;
	while (choice!=7) {
		menu();
		scanf("%d",&choice);
		system("cls");
		switch(choice) {
			case 1 :
				system("cls");
				int n ;
				product NewProduct;
				printf("how many products you want to add ?\n");
				scanf("%d",&n);
				int i = 0 ; 
				for ( i = 0 ; i < n ; i++ ) {
					printf("Enter product ID: ");
					scanf("%u", &NewProduct.id);
					fflush(stdin);
					printf("Enter product quantity: ");
					scanf("%u", &NewProduct.quantity);
					fflush(stdin);
					printf("Enter product name: ");
					scanf("%[^\n]s", &NewProduct.name);
					fflush(stdin);
					printf("Enter product brand: ");
					scanf("%[^\n]s", &NewProduct.brand);
					fflush(stdin);
					printf("Enter product price: ");
					scanf("%f", &NewProduct.price);
					fflush(stdin);
					add_product(tabG,NewProduct,&i);
				}
				
				puts("Product added.");
				break;
			case 2 :
				system("cls");
				int c;
				unsigned int x;
				printf("Enter product ID to show: ");
				scanf("%u", &x);
				fflush(stdin);
				int y = IdLocation(x, tabG , n);
				if (y == -1) printf("Product not found.\n");
				else {
					printf("Product num%d : \nID: %u -- Brand : %s  -- Name : %s -- Quantity: %u -- Price: %.2f$ \n",i,tabG[y].id, tabG[y].brand, tabG[y].name, tabG[y].quantity,tabG[y].price);
				puts("Press any key to continue...");
				}
				getch();
				break;
			case 3 :
				system("cls");
				int z ;
				printf("Enter a product position to delete: ");
				scanf("%d",&z);
				fflush(stdin);
				delete_product_pos (tabG,z,&n) ;
				printf("Product deleted.\n");
				sleep(3);
				break ;
			case 4 :
				system("cls");
				show_all_products(tabG,n);
				puts("Press any key to continue...");
				getch();
				break;
			case 5 :
				exit(0);
				break;
			default:
				printf("Invalid option.");
				sleep(1);
				break;
		}
	}
	return 0;
}
