#include<stdio.h>
#include<string.h>
#include<math.h>
int checkPowerOfTwo(int num){
	int flag=0;
	int newnum=num;
	while(num>0){
		num=(num) & (num-1);
		flag+=1;
	}
	if(flag==1 || newnum==0)
	    return 1;
	else 
	    return 0;
}
int main(){
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
	char word[100];
	char reverseWord[100];
	int shiftedword[100];
	printf("\n Enter The Actual DataWord MSB----LSB-->  ");
	gets(word);
	int wordLength=strlen(word);
	int parity=1;
	int pows=2;
	while(pows<(wordLength+parity+1)){
			parity=parity+1;
			pows=pows*2;
		
	}
	int len=wordLength+parity;
	int hammingCode[len];
	int i;
	int tempParity=parity;
	int p=0;
	int q=0;
	for(i=wordLength-1;i>=0;i--){
		reverseWord[q++]=word[i];
	}
	for(i=0;i<len;i++){
		double x=pow(2.0,(double)i);
		int y=(int)x;
		if(parity>=1 && checkPowerOfTwo(i+1)){
			
			hammingCode[i]=2;
			parity=parity-1;
		}
		else{
			hammingCode[i]=(int)(reverseWord[p++])-48;
		}
	}
//	for(int i=0;i<len;i++)printf(" %d ",hammingCode[i]);
	shiftedword[0]=3;
	for(i=1;i<=len;i++){
		shiftedword[i]=hammingCode[i-1];
	}
	
    for(int i=1;i<=(len);i++){
    	if(shiftedword[i]==2){
    		int j=i;
    		int flag=0;
    		int repeat=0;
    		while(j<=len){
    			if(j==i){
    			
				j++;
				repeat=1;
				
				}
				else{
					if(repeat==i){
						
						j=j+i+1;
						
						repeat=0;
						
						
					}
					else{
					    if(shiftedword[j]%2==1){
						flag++;
						
					}
						repeat=repeat+1;
						if(repeat==i){
						
							j=j+i+1;
							
							repeat=0;
						
						}
						else{
							j++;
						}
						
					}
					
				}
				
			}
			if(flag%2==0){
				shiftedword[i]=0;
			}
			else shiftedword[i]=1;
		}
	}
	for(int i=len;i>=1;i--)printf("%d ",shiftedword[i]);

}
