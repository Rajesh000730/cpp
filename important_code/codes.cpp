//power of 2 using modulo
int s = 1;
for(int i = 0; i < n;i++){
  s = 2*s%((int)(1e9 + 7));
}

//given n. divide the n nos into two sets such their sum is equal

//no of trailing zeroes for a given factorial
int n;
int ans = 0;
for(int i = 5; i <= n;i=i*5){
  ans+=i/n;
}


