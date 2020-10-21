#include<stdio.h>
int draw(int h);



int main(){

    draw(5);

    return 0;
}

int draw(int h){

if(h==0){
return;
}
    
draw(h-1);
for(int i=0; i<h; i++){
    printf("#");
}
printf("\n");

}