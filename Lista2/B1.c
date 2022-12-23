int faz_conta_direito(int parcelas, char op){
    int values[parcelas], temp;
    for(int i = 0; i < parcelas; i++){
        scanf("%d", &temp);
        values[i] = temp;
    }
    if(op == '+'){
        int soma = 0;
        for(int i = 0; i < parcelas; i++){
            soma += values[i];
        }
        return soma;
    } else if(op == '-'){
        int total = values[0];
        for(int i = 1; i < parcelas; i++){
            total -= values[i];
        }
        return total;
    }
}