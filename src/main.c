/*Laboratorio com objetivo de utilizar pipes e "ferramentas do linux" para
  ordenar de forma decrescente numeros nao primos
  Hugo Ralf Pereira RA:155742*/
#include <stdio.h>
#include <stdlib.h>
int calc_prime_numbers(int x);
int main() {

	int x;
	FILE *fp;
	fp = popen("sort -n -r","w");//criar um fork e aplica o metodo sort
	if(fp == NULL){
		printf("erro\n");
		exit(EXIT_FAILURE);
	}	
		for(;;){
			scanf("%d",&x);
			if(x == -1)
				break;
			if(calc_prime_numbers(x))
				fprintf(fp, "%d\n", x);
		}
	pclose(fp);
	return 0;
}
/*funcao que calcula numero primos e nao primos*/
int calc_prime_numbers(int x){
	int aux = 0;
	int i;
	if(x == 2)
		return 0;
	if(x == 1 || x % 2 ==0)		//caso o numero for par(exceto) ja sabemos que nao e primo
		return 1;
	for(i = 3; i<= (x/2); i=i+2){//verifica o caso de numeros primos percorrendo numeros impares
		if((x % i) == 0)
			aux ++;
		if (aux)
			return 1;		
	}
	return 0;
}
