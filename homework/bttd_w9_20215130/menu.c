// Chuong trinh tao menu
#include <stdio.h>

int printMenu(){
    printf("==============MENU==============\n");
    printf("1. Nhap 2 so nguyen (a,b)\n");
    printf("2. Tinh tong 2 so\n");
    printf("3. Tinh tich 2 so\n");
    printf("4. Thoat chuong trinh\n");
    return 1;
}

int check(int flag){ //kiem tra xem da nhap hai so tu ban phim chua
    if(flag ==0 ){
        printf("Vui long nhap 2 so tu ban phim (thuc hien buoc 1 truoc).\n");
        return 0;
    }
    return 1;
}

int main(){
    int selection;
    int a,b;
    int flag = 0;
    while(printMenu()){
        printf("-->Nhap lua chon: ");
        scanf("%d",&selection);
        switch (selection){
            case 1:
                printf("---->Nhap 2 so nguyen (a,b)\n");
                scanf("%d %d",&a,&b);
                flag = 1;
                break;
            case 2:
                if(check(flag))  
                    printf("---->Tong hai so %d va %d la: %ld\n",a,b,a+b);
                break;
            case 3:
                if(check(flag))
                    printf("---->Tich hai so %d va %d la: %ld\n",a,b,a*b);
                break;
            case 4:
                printf("---->end process!\n");
                return 0;
            default:
                printf("Lua chon chuc nang tu 1 --> 4: \n");
            break; 
        }
    }
}