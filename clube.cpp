
#include <cstdio>
// #include <cstdio> cabeçalho padrão de entrada/saída no C++
// Se fosse no C seria #include <stdio.h>
#include <cstring>
// "#include <cstring>" manipulação de cadeias de caracteres e regiões de memória no C++
// Se fosse no C seria "#include <string.h>"
#include <vector>
// A classe vector é uma alternativa à representação de array primitivo
// Em C é #include <vector.h>
#include <set>
//Sets são contêineres que armazenam elementos exclusivos seguindo uma ordem específica.
// Em C #include <set.h>
using namespace std;
// "using namespace std;" é uma forma de evitar nomes iguais fazendo coisas diferentes colidirem.
// Um namespace permite a definição de estruturas, classes, funções, constantes, etc, que estarão vinculadas a ele.
// Isso evita duplicidade como, por exemplo, outras implementações com nomes semelhantes.
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define INF 0x3f3f3f3f
// "#define INF 0x3f3f3f3f" é uma variável constante representando o infinito.
// 0x3f3f3f3f é grande o suficiente para a maioria dos casos.
// 0x3f3f3f3f + 0x3f3f3f3f não vai dar overflow.
// Nós podemos facilmente usar memset: memset(a, 0x3f, sizeof (a)).
// Para "-INF(menos infinito)", we can use 0xcfcfcfcf.
#define mst(a, b) memset(a, b, sizeof a)
// mst(Minimum Spanning Tree - Arvore Geradora Mínima) Árvore geradora cuja soma dos pesos das arestas é a menor possível.
// memset() foi definido no #include <cstring>
#define fr(i,a,b) for(int i=a; i < b; i++)
// "#define" Permite ao programador dar um nome a um valor constante antes de o programa ser compilado.
typedef set<int> si;

int l, k, w, n, m;
int arr[10005];
int arr_[10005];
si ns;
si::reverse_iterator it;

int check(int k, int sum, bool b) {

    it = ns.rbegin();
    int d, n, cnt = 0, i = ns.size()-1;

    while(k && it != ns.rend()) {
        n = *it;
        d = sum-n;
       
        if(b) {
            if(arr[n] <= 0 || d < 0 || (d==n ? (arr[d]-1) <= 0 : arr[d] <= 0)) {
                it++; continue;
            }
        }
        if(!b) {
            if(arr_[n] <= 0 || d < 0 || (d==n ?  (arr_[d]-1) <= 0 : arr_[d] <= 0)) {
                it++; continue;
            }
        }

        if(b) {
            arr[d]--, arr[n]--;
        }else {
            arr_[d]--, arr_[n]--;
        }

        cnt+= (d ? 2 : 1);
        k--;
    }

    if(k) return INF;
    return cnt;
}

int main (int argc, char const* argv[]) {

    while(sc2(n,m) && (n || m)) {
        mst(arr, 0); mst(arr_, 0);
        arr[0] = arr_[0] = INF;
        ns.clear();
        sc2(l,k);

        fr(i,0,k) {
            sc1(w);
            ns.insert(w);
            arr[w]++, arr_[w]++;
        }

        int r = INF;

        if((n*100)%l == 0){
            r = min(r, check((n*100)/l, m, 1));
        }

        if((m*100)%l == 0){
            r = min(r, check((m*100)/l, n, 0));
        }

        if(r >= INF || r < 0) puts("impossivel");
        else printf("%d\n", r);
    }

    return 0;
}