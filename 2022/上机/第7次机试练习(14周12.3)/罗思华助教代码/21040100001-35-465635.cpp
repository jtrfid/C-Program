#include<stdio.h>
int main(){
	int n,su,a[100],b=0,num,i,j,k=0;
	scanf("%d",&n);
	for(i=2;i<n;i++){
		k=0;
		for(j=2;j<=i;j++){
			if(i%j==0){
				k++;
			}
		}
		if(k==1){
			a[b]=i;
				b++;
		}
}
	for(i=0;i<b;i++){
		for(j=b;j>0;j--){
			if(a[j]==n-a[i]){
				printf("%d %d",a[i],a[j]);
				return 0;
			}
		}
	}
}
