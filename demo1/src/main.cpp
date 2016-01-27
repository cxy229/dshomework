#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
#include<cassert>
#include<climits>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define INF (2139062143)
#define MAXN (600000+10)
typedef long long ll;
ll Fp[10]={1002347903,1000000411,1000000033,1000000087,1000000009};int p_size=5;
ll F=(1002347903);
int T,sp=0,opt[1000]={0},n;
ll val[1000]={0};
char buf[MAXN],st[MAXN];
ll num[MAXN];
ll pow2(ll a,ll b)
{
	if (b==0) return 1;
	if (b==1) return a%F;
	ll c=pow2(a,b/2);
	c=c*c%F;
	if (b&1) c=c*a%F;
	return c;
}
ll mulinv(ll a)
{
	return pow2(a,F-2);
}
ll revF=mulinv(10);
ll getint(int &i)
{
	if (st[sp]=='^') F--;//revF=mulinv(10);

	if (isalpha(buf[i])) return val[buf[i]];
	ll xm=0,xr=1;
	for(;isdigit(buf[i])&&i<=n;i++)
	{
		xm=(xm*10+(buf[i]-48))%F;
	}
	if (buf[i]=='.')
	{
		i++;
		for(;isdigit(buf[i])&&i<=n;i++)
		{
			xm=(xm*10+(buf[i]-48))%F;xr=xr*revF%F;
		}
	}
	i--;

	if (st[sp]=='^') F++;//revF=mulinv(10);

	return xm*xr%F;
}
void calc()
{
	if (st[sp]=='+') num[sp]=(num[sp]+num[sp+1])%F;
	else if (st[sp]=='-') num[sp]=(num[sp]-num[sp+1]+F)%F;
	else if (st[sp]=='*') num[sp]=(num[sp]*num[sp+1])%F;
	else if (st[sp]=='/') num[sp]=(num[sp]*mulinv(num[sp+1]))%F;
	else if (st[sp]=='^') num[sp]=(pow2(num[sp],num[sp+1]))%F;
	sp--;
}
void print()
{
	if (T>=0) return;
	//#ifdef DEBUG
	For(j,sp+1) cout<<num[j]<<' ';cout<<endl;
	For(j,sp) cout<<st[j]<<' ';cout<<endl;
	cout<<"sp="<<sp<<endl;
	//#endif
}
long long work()
{
	n=strlen(buf+1);sp=0;
	For(i,n)
	{
	//	cout<<i<<':'<<endl;
		int t=opt[buf[i]];
		if (t>0)
		{
			while (opt[st[sp]]>=t) calc();
			st[++sp]=buf[i];
		}
		else if (buf[i]=='(') st[++sp]=buf[i];
		else if (buf[i]==')')
		{
			while (st[sp]!='(') calc();
			num[sp]=num[sp+1];sp--;
		}
		else num[sp+1]=getint(i);
		///-0000
		print();
	}
	while (sp) calc(),print();
//	cout<<"=================================================\n";
	return num[1];
}
ll ans[10][2];
int main()
{
//	freopen("expression.in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&T);
//	cout<<pow2(10,4);
//	For(i,1000) cout<<pow2(10,i)<<' ';
	/*
	srand(32987);val['a']=1000000007;val['a']=1023492132;
	For(i,25) val[i+'a']=(rand()*+rand()*10003+val[i+'a'-1])%F;
	*/

	srand('o'+'r'+'z');
	For(i,26) val[i+'a'-1]=F-rand()%(F/100)-F/100*(i-1);


//	val['a']=1;val['b']=7;
	opt['+']=opt['-']=1,opt['*']=opt['/']=2,opt['^']=3,opt['(']=opt[')']=-1;
	while (T--)
	{
		Rep(j,2)
		{
			scanf("%s",buf+1);
			Rep(i,5)
			{
				F=Fp[i];revF=mulinv(10);
				ans[i][j]=work();
			}
		}
		//cout<<ans[0][0]<<' '<<ans[0][1]<<endl;
		bool bo=1;
		Rep(i,5) if (ans[i][0]^ans[i][1]) {puts("NO");bo=0;break;}
		if (bo) puts("YES");
	}
	return 0;
}
