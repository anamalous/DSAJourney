//maximum number
int maximum69Number (int num) {
    int digs[5]={0,0,0,0,0};
    int i=0;
    while(num>=0){
        digs[i]=num%10;
        num=(int)num/10;
        i++;
    }
    for(int i=4;i>=0;i--){
        if(digs[i]==6){
            digs[i]=9;
            break;
        }
    }
    for(int i=4;i>=0;i--){
        num+=digs[i]*(10^i);
    }
    return num;
}